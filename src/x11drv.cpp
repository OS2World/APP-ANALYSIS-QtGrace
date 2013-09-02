/*
 * Grace - GRaphing, Advanced Computation and Exploration of data
 * 
 * Home page: http://plasma-gate.weizmann.ac.il/Grace/
 * 
 * Copyright (c) 1991-1995 Paul J Turner, Portland, OR
 * Copyright (c) 1996-2003 Grace Development Team
 * 
 * Maintained by Evgeny Stambulchik
 * 
 * Modified by Andreas Winter 2008-2011
 * 
 *                           All Rights Reserved
 * 
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 * 
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 * 
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* 
 *
 * driver for X11 for Grace
 * modified for Qt-Library by Andreas Winter 2008
 *
 */

///#include <config.h>
#include <cmath>
#include "defines.h"

#include <stdlib.h>

///#include <X11/Xlib.h>
#include <QtGui>

#include "globals.h"
#include "utils.h"
#include "device.h"
#include "devlist.h"
#include "draw.h"
#include "graphs.h"
#include "patterns.h"

#include "x11drv.h"

#include "noxprotos.h"
#include "MainWindow.h"

extern bool useQPrinter;
extern QPrinter * stdPrinter;
extern QImage * MainPixmap;
extern QPainter * GeneralPainter;
extern MainWindow * mainWin;
extern QVector<qreal> * PenDashPattern[MAXLINESTYLES];
extern QBitmap * patterns[MAXPATTERNS];

extern DrawProps draw_props;

/*extern Display *disp;
extern Window xwin;*/

///Window root;
int screennumber;
///GC gc, gcxor;
int depth;

///static Visual *visual;
static int pixel_size;

int install_cmap = CMAP_INSTALL_AUTO;

static int private_cmap = FALSE;

unsigned long xvlibcolors[MAXCOLORS];
///Colormap cmap;

static QPixmap * curtile;
static QPixmap * displaybuff;// = (Pixmap) NULL;

static int xlibcolor;
static int xlibbgcolor;
static int xlibpatno;
static int xliblinewidth;
static int xliblinestyle;
static int xlibfillrule;
static int xlibarcfillmode;
static int xliblinecap;
static int xliblinejoin;

extern void generate_Pixmap_from_Bits(unsigned char * bits,int length,int rows,int cols,QPixmap * target);

unsigned int win_h = 0, win_w = 0;
#define win_scale ((win_h < win_w) ? win_h:win_w)

QPixmap resize_bufpixmap(unsigned int w, unsigned int h);

///original Grace: 'X11' instead of 'Screen'

static Device_entry dev_x11 = {DEVICE_TERM,
          "Screen",
          xlibinitgraphics,
          NULL,
          NULL,
          "",
          FALSE,
          TRUE,
          {DEFAULT_PAGE_WIDTH, DEFAULT_PAGE_HEIGHT, 72.0},
          NULL
         };

int register_x11_drv(void)
{
    /*long mrsize;
    int max_path_limit;
    
     XExtendedMaxRequestSize() appeared in X11R6 */
/*#if XlibSpecificationRelease > 5
    mrsize = XExtendedMaxRequestSize(disp);
#else
    mrsize = 0;
#endif
    if (mrsize <= 0) {
        mrsize = XMaxRequestSize(disp);
    }
    max_path_limit = (mrsize - 3)/2;
    if (max_path_limit < get_max_path_limit()) {
        char buf[128];
        sprintf(buf,
            "Setting max drawing path length to %d (limited by the X server)",
            max_path_limit);
        errmsg(buf);
        set_max_path_limit(max_path_limit);
    }
    
    dev_x11.pg.dpi = rint(MM_PER_INCH*DisplayWidth(disp, screennumber)/
        DisplayWidthMM(disp, screennumber));
    */
dev_x11.pg.dpi=QApplication::desktop()->logicalDpiX();
pixel_size=1;
curtile=new QPixmap(10,10);
displaybuff=new QPixmap(10,10);
    return register_device(dev_x11);
}

int xlibinit(void)
{
//cout << "xlibinit" << endl;
pixel_size=1;
    return RETURN_SUCCESS;
}


int xconvxlib(double x)
{
    return ((int) rint(win_scale * x));
}

int yconvxlib(double y)
{
    return ((int) rint(win_h - win_scale * y));
}

void xlibVPoint2dev(VPoint vp, int *x, int *y)
{
    *x = xconvxlib(vp.x);
    *y = yconvxlib(vp.y);
}

QPoint VPoint2XPoint(VPoint vp)
{
    return QPoint(xconvxlib(vp.x),yconvxlib(vp.y));
}

/*
 * xlibdev2VPoint - given (x,y) in screen coordinates, return the 
 * viewport coordinates
 */
VPoint xlibdev2VPoint(int x, int y)
{
    VPoint vp;

    if (win_scale == 0) {
        vp.x = (double) 0.0;
        vp.y = (double) 0.0;
    } else {
        vp.x = (double) x / win_scale;
        vp.y = (double) (win_h - y) / win_scale;
    }

    return (vp);        
}


void xlibupdatecmap(void)
{
    /* TODO: replace!!! */
    //if (inwin) 
    {
        xlibinitcmap();
    }
}


void xlibinitcmap(void)
{
    /*int i;
    RGB *prgb;
    QColor xc[MAXCOLORS];*/
    
    /*for (i = 0; i < MAXCOLORS; i++) {
        xc[i].pixel = 0;
        xc[i].flags = DoRed | DoGreen | DoBlue;
    }*/
    
    /*
	for (i = 0; i < number_of_colors(); i++) {
        // even in mono, b&w must be allocated 
        if (monomode == FALSE || i < 2) { 
            prgb = get_rgb(i);
            if (prgb != NULL) {
                xc[i].red = prgb->red << (16 - GRACE_BPP);
                xc[i].green = prgb->green << (16 - GRACE_BPP);
                xc[i].blue = prgb->blue << (16 - GRACE_BPP);
                if (XAllocColor(disp, cmap, &xc[i])) {
                    xvlibcolors[i] = xc[i].pixel;
                } else {
                    if (install_cmap != CMAP_INSTALL_NEVER && 
                                        private_cmap == FALSE) {
                        cmap = XCopyColormapAndFree(disp, cmap);
                        private_cmap = TRUE;
                        // will try to allocate the same color 
                        // in the private colormap
                        i--; 
                    } else {
                        // really bad
                        xvlibcolors[i] = xvlibcolors[1];
 //
 //                         errmsg("Can't allocate color");
 //
                    }
                }
            }
        } else {
            xvlibcolors[i] = xvlibcolors[1];
        }
    }
    */
}

int xlibinitgraphics(void)
{
    int i, j;
    double step;
    QPoint xp;

    /*if (inwin == FALSE) {
        return RETURN_FAILURE;
    }*/

    xlibcolor = BAD_COLOR;
    xlibbgcolor = BAD_COLOR;
    xlibpatno = -1;
    xliblinewidth = -1;
    xliblinestyle = -1;
    xlibfillrule = -1;
    xlibarcfillmode = -1;
    xliblinecap   = -1;
    xliblinejoin  = -1;
    
    /* device-dependent routines */    
    devupdatecmap = xlibupdatecmap;
    
    devdrawpixel = xlibdrawpixel;
    devdrawpolyline = xlibdrawpolyline;
    devfillpolygon = xlibfillpolygon;
    devdrawarc = xlibdrawarc;
    devfillarc = xlibfillarc;
    devputpixmap = xlibputpixmap;
    
    devleavegraphics = xlibleavegraphics;

    /* init settings specific to X11 driver */    
    
    if (get_pagelayout() == PAGE_FIXED) {
        sync_canvas_size(&win_w, &win_h, FALSE);
    } else {
        sync_canvas_size(&win_w, &win_h, TRUE);
    }
    
    ///*displaybuff = resize_bufpixmap(win_w, win_h);
    
    xlibupdatecmap();
    
    /*XSetForeground(disp, gc, xvlibcolors[0]);
    XSetFillStyle(disp, gc, FillSolid);
    XFillRectangle(disp, displaybuff, gc, 0, 0, win_w, win_h);
    XSetForeground(disp, gc, xvlibcolors[1]);*/
    

/*Qt-plotting stuff*/
GeneralPainter->end();
//Setting new target for GeneralPainter
if (useQPrinter==false || stdPrinter==NULL)
{
*MainPixmap=QImage(win_w,win_h,QImage::Format_ARGB32_Premultiplied);
GeneralPainter->begin(MainPixmap);
}
else
{
GeneralPainter->begin(stdPrinter);
}
///GeneralPainter->setRenderHint(QPainter::Antialiasing);

GeneralPainter->setPen(Qt::white);
GeneralPainter->setBrush(Qt::white);
GeneralPainter->drawRect(0,0,win_w - 1,win_h - 1);
GeneralPainter->setPen(Qt::black);
GeneralPainter->setBrush(Qt::black);

    step = (double) win_scale/10;
    for (i = 0; i < win_w/step; i++) {
        for (j = 0; j < win_h/step; j++) {
            xp.setX(rint(i*step));
            xp.setY(win_h - rint(j*step));
            ///XDrawPoint(disp, displaybuff, gc, xp.x, xp.y);
	    GeneralPainter->drawPoint(xp.x(),xp.y());
        }
    }
    
   ///XSetLineAttributes(disp, gc, 1, LineSolid, CapButt, JoinMiter);
   ///XDrawRectangle(disp, displaybuff, gc, 0, 0, win_w - 1, win_h - 1);
GeneralPainter->setBrush(Qt::NoBrush);
GeneralPainter->drawRect(0,0,win_w - 1,win_h - 1);
    return RETURN_SUCCESS;
}


void xlib_setpen(void)
{
QBrush brush(GeneralPainter->brush());
QPen pen(GeneralPainter->pen());
    int fg, bg, p;
    QPixmap ptmp;
    RGB * rgb_color;

    fg = getcolor();
    bg = getbgcolor();
    p = getpattern();


xlibcolor=fg;
xlibbgcolor=bg;
xlibpatno=p;
set_Brush_only(fg,bg,p);
return;

    if ((fg == xlibcolor) && (bg == xlibbgcolor) && (p == xlibpatno)) {
        return;
    }
        
    if (fg != xlibcolor) {
	rgb_color=get_rgb(fg);
        ///XSetForeground(disp, gc, xvlibcolors[fg]);
	pen.setColor(get_Color(fg));
	///GeneralPainter->setPen(QColor(rgb_color->red,rgb_color->green,rgb_color->blue));
	//GeneralPainter->setBrush(QColor(rgb_color->red,rgb_color->green,rgb_color->blue));
        xlibcolor = fg;
    }
    
    if (bg != xlibbgcolor) {
	rgb_color=get_rgb(bg);
        ///XSetBackground(disp, gc, xvlibcolors[bg]);
	//GeneralPainter->setPen(QColor(rgb_color->red,rgb_color->green,rgb_color->blue));
	///GeneralPainter->setBrush(QColor(rgb_color->red,rgb_color->green,rgb_color->blue));
        xlibbgcolor = bg;
    }

    if (p >= number_of_patterns() || p < 0) {
        p = 0;
    }
    xlibpatno = p;
    
    if (p == 0) { /* TODO: transparency !!!*/
	brush.setStyle(Qt::NoBrush);
	GeneralPainter->setBrush(brush);
	///GeneralPainter->setBrush(brush);
        return;
    } else if (p == 1) {
        /* To make X faster */
	brush.setStyle(Qt::SolidPattern);
	///GeneralPainter->setBrush(brush);
        ///XSetFillStyle(disp, gc, FillSolid);
    } else {
        /* TODO: implement cache ? */
        ///ptmp = XCreateBitmapFromData(disp, root, (char *) pat_bits[p], 16, 16);
        ///XCopyPlane(disp, ptmp, curtile, gc, 0, 0, 16, 16, 0, 0, 1);
        ///XFreePixmap(disp, ptmp);

brush.setColor(get_Color(fg));

QPixmap pic(16,16);
generate_Pixmap_from_Bits(pat_bits[p],32,16,16,&pic);
//brush.setTexture(patterns[p]->copy(0,0,16,16));
brush.setTexture(pic);
pic.fill(get_Color(bg));
QPainter paintr(&pic);
paintr.setBrush(brush);
paintr.setPen(Qt::NoPen);
paintr.drawRect(0,0,16,16);
paintr.end();
brush.setTexture(pic);
/*
 *      XSetFillStyle(disp, gc, FillStippled);
 *      XSetStipple(disp, gc, curstipple);
 */
        ///XSetFillStyle(disp, gc, FillTiled);
        ///XSetTile(disp, gc, curtile);

	///setDrawPropsOfPainter();
GeneralPainter->setBrush(brush);
        return;
    }
}

void xlib_setdrawbrush(void)
{
QPen pen(GeneralPainter->pen());
    unsigned int iw;
    int style;
    int lc, lj;
    int i, scale, darr_len;
    char *xdarr;

    xlib_setpen();
    
    iw = (unsigned int) rint(getlinewidth()*win_scale);
    if (iw == 1) {
        iw = 0;
    }
    style = getlinestyle();
    lc = getlinecap();
    lj = getlinejoin();
    

    /*switch (lc) {
    case LINECAP_BUTT:
	pen.setCapStyle(Qt::SquareCap);
        ///lc = CapButt;
        break;
    case LINECAP_ROUND:
	pen.setCapStyle(Qt::RoundCap);
        ///lc = CapRound;
        break;
    case LINECAP_PROJ:
	pen.setCapStyle(Qt::FlatCap);
        ///lc = CapProjecting;
        break;
    }

    switch (lj) {
    case LINEJOIN_MITER:
	pen.setJoinStyle(Qt::MiterJoin);
        ///lj = JoinMiter;
        break;
    case LINEJOIN_ROUND:
	pen.setJoinStyle(Qt::RoundJoin);
        ///lj = JoinRound;
        break;
    case LINEJOIN_BEVEL:
	pen.setJoinStyle(Qt::BevelJoin);
        ///lj = JoinBevel;
        break;
    }*/
    
    if (iw != xliblinewidth || style != xliblinestyle ||
        lc != xliblinecap   || lj    != xliblinejoin) {
        if (style > 1) {
            darr_len = dash_array_length[style];
            xdarr = (char*)xmalloc(darr_len*sizeof(char));
            if (xdarr == NULL) {
                return;
            }
            scale = MAX2(1, iw);
            for (i = 0; i < darr_len; i++) {
                xdarr[i] = scale*dash_array[style][i];
            }
	pen.setStyle(Qt::CustomDashLine);
	pen.setDashPattern(*PenDashPattern[style]);
            ///XSetLineAttributes(disp, gc, iw, LineOnOffDash, lc, lj);
            ///XSetDashes(disp, gc, 0, xdarr, darr_len);
            xfree(xdarr);
        } else if (style == 1) {
	pen.setStyle(Qt::SolidLine);
            ///XSetLineAttributes(disp, gc, iw, LineSolid, lc, lj);
        }
	else if (style == 0)
	{
	pen.setStyle(Qt::NoPen);
	}
	pen.setWidth(iw);

        xliblinestyle = style;
        xliblinewidth = iw;
        xliblinecap   = lc;
        xliblinejoin  = lj;
	GeneralPainter->setPen(pen);
    }
set_Pen_only();
    return;
}

void xlibdrawpixel(VPoint vp)
{
    QPoint xp;
    
    xp = VPoint2XPoint(vp);
    xlib_setpen();
set_Pen_only();
GeneralPainter->drawPoint(xp);
    ///XDrawPoint(disp, displaybuff, gc, xp.x, xp.y);
}

void xlibdrawpolyline(VPoint *vps, int n, int mode)
{
    int i, xn = n;
    QPoint *p;

    if (n <= 1 || getlinestyle() == 0 || getpattern() == 0) {
        return;
    }
    
    if (mode == POLYLINE_CLOSED) {
        xn++;
    }
    
    p = new QPoint[xn];//xmalloc(xn*sizeof(XPoint));
    if (p == NULL) {
        return;
    }
    
    for (i = 0; i < n; i++) {
        p[i] = VPoint2XPoint(vps[i]);
    }
    if (mode == POLYLINE_CLOSED) {
        p[n] = p[0];
    }
    
    ///xlib_setdrawbrush();
    set_Pen_only();
GeneralPainter->drawPolyline(p,xn);
    ///XDrawLines(disp, displaybuff, gc, p, xn, CoordModeOrigin);
    
    ///xfree(p);
delete[] p;
}


void xlibfillpolygon(VPoint *vps, int npoints)
{
    int i;
    QPoint *p;
    
    if (npoints < 3 || getpattern() == 0) {
        return;
    }
    
    p = new QPoint[npoints];//(XPoint *) xmalloc(npoints*sizeof(XPoint));
    if (p == NULL) {
        return;
    }
    
    for (i = 0; i < npoints; i++) {
        p[i] = VPoint2XPoint(vps[i]);
    }
    
    xlib_setpen();

    if (getfillrule() != xlibfillrule) {
        xlibfillrule = getfillrule();
        if (getfillrule() == FILLRULE_WINDING) {
            ///XSetFillRule(disp, gc, WindingRule);
        } else {
            ///XSetFillRule(disp, gc, EvenOddRule);
        }
    }

set_Pen_only();
GeneralPainter->setPen(Qt::NoPen);
set_Brush_only(getcolor(),getbgcolor(),getpattern());
if (getfillrule() == FILLRULE_WINDING)
GeneralPainter->drawPolygon(p,npoints,Qt::WindingFill);
else
GeneralPainter->drawPolygon(p,npoints,Qt::OddEvenFill);

    ///XFillPolygon(disp, displaybuff, gc, p, npoints, Complex, CoordModeOrigin);
    
    //xfree(p);
delete[] p;
}

/*
 *  xlibdrawarc
 */
void xlibdrawarc(VPoint vp1, VPoint vp2, int angle1, int angle2)
{
    int x1, y1, x2, y2;
    
    xlibVPoint2dev(vp1, &x1, &y2);
    xlibVPoint2dev(vp2, &x2, &y1);

    if (getlinestyle() == 0 || getpattern() == 0) {
        return;
    }
	
    xlib_setdrawbrush();///Brush sets only the outline
set_Pen_only();
GeneralPainter->setBrush(Qt::NoBrush);
    if (x1 != x2 || y1 != y2) {
//GeneralPainter->drawPie(MIN2(x1, x2), MIN2(y1, y2),abs(x2 - x1), abs(y2 - y1),16*angle1,16*(angle2-angle1));
GeneralPainter->drawArc(MIN2(x1, x2), MIN2(y1, y2),abs(x2 - x1), abs(y2 - y1),16*angle1,16*(angle2-angle1));
	//GeneralPainter->drawEllipse(MIN2(x1, x2), MIN2(y1, y2),abs(x2 - x1), abs(y2 - y1));
        ///XDrawArc(disp, displaybuff, gc, MIN2(x1, x2), MIN2(y1, y2),
        ///      abs(x2 - x1), abs(y2 - y1), 64 * angle1, 64 * (angle2 - angle1));
    } else { /* zero radius */
	GeneralPainter->drawPoint(x1,y1);
        ///XDrawPoint(disp, displaybuff, gc, x1, y1);
    }
}

/*
 *  xlibfillarc
 */
void xlibfillarc(VPoint vp1, VPoint vp2, int angle1, int angle2, int mode)
{
    int x1, y1, x2, y2;
    bool pie=true;
    xlibVPoint2dev(vp1, &x1, &y2);
    xlibVPoint2dev(vp2, &x2, &y1);
    
    if (getpattern() != 0) {
        xlib_setpen();///Pen sets outline and filling
        if (x1 != x2 || y1 != y2) {
            //if (xlibarcfillmode != mode) {
                xlibarcfillmode = mode;
                if (mode == ARCFILL_CHORD) {
			pie=false;
                    ///XSetArcMode(disp, gc, ArcChord);
                } else {
			pie=true;
                    ///XSetArcMode(disp, gc, ArcPieSlice);
                }
            //}
set_Pen_only();
GeneralPainter->setPen(Qt::NoPen);
set_Brush_only(getcolor(),getbgcolor(),getpattern());
if (pie)
GeneralPainter->drawPie(MIN2(x1, x2), MIN2(y1, y2),abs(x2 - x1), abs(y2 - y1),16*angle1,16*(angle2-angle1));
else
GeneralPainter->drawChord(MIN2(x1, x2), MIN2(y1, y2),abs(x2 - x1), abs(y2 - y1),16*angle1,16*(angle2-angle1));
	//GeneralPainter->drawEllipse(MIN2(x1, x2), MIN2(y1, y2),abs(x2 - x1), abs(y2 - y1));
            ///XFillArc(disp, displaybuff, gc, MIN2(x1, x2), MIN2(y1, y2),
            ///   abs(x2 - x1), abs(y2 - y1), 64 * angle1, 64 * (angle2 - angle1));
        } else { /* zero radius */
	GeneralPainter->drawPoint(x1,y1);
            ///XDrawPoint(disp, displaybuff, gc, x1, y1);
        }
    }
}


void xlibputpixmap(VPoint vp, int width, int height, 
     char *databits, int pixmap_bpp, int bitmap_pad, int pixmap_type)
{
    int j, k, l;
    
    QPoint xp;

    ///static XImage *ximage;

QPen linePen;
RGB * rgbColor;
QPixmap clipmask(width,height);
clipmask.fill();
QPainter clp_painter(&clipmask);
int x1,y1;//real_world_coordinates
xlibVPoint2dev(vp, &x1, &y1);
//cout << "x1="<< x1 << " y1=" << y1 << endl;
    char *pixmap_ptr;
    char *clipmask_ptr = NULL;
    
    int line_off;

    int cindex, fg, bg;
    
    xp = VPoint2XPoint(vp);
      
    if (pixmap_bpp != 1) {
        if (monomode == TRUE) {
            /* TODO: dither pixmaps on mono displays */
            return;
        }
        pixmap_ptr = (char *)xcalloc(PAD(width, 8) * height, pixel_size);
        if (pixmap_ptr == NULL) {
            errmsg("xmalloc failed in xlibputpixmap()");
            return;
        }
 
        /* re-index pixmap */
        for (k = 0; k < height; k++) {
            for (j = 0; j < width; j++) {
                cindex = (unsigned char) (databits)[k*width+j];
                for (l = 0; l < pixel_size; l++) {
                    pixmap_ptr[pixel_size*(k*width+j) + l] =
                                        (char) (xvlibcolors[cindex] >> (8*l));
                }
            }
        }
/*cout << "pixel_size=" << pixel_size << endl;
		for (int i=0;i<height;i++)
		{
			for (int j=0;j<width;j++)
			{
				if (pixmap_ptr[i*width+j])
				clp_painter.drawPoint(j,i);
			}
		}

cout << "pixmap_bpp="<< pixmap_bpp << endl;*/
        ///ximage=XCreateImage(disp, visual,
        ///                   depth, ZPixmap, 0, pixmap_ptr, width, height,
        ///                   bitmap_pad,  /* lines padded to bytes */
        ///                   0 /* number of bytes per line */
        ///                   );

        if (pixmap_type == PIXMAP_TRANSPARENT) {
            clipmask_ptr =(char*) xcalloc((PAD(width, 8)>>3)* height, sizeof(char));
            if (clipmask_ptr == NULL) {
                errmsg("xmalloc failed in xlibputpixmap()");
                return;
            } else {
                /* Note: We pad the clipmask always to byte boundary */
                bg = getbgcolor();
                for (k = 0; k < height; k++) {
                    line_off = k*(PAD(width, 8) >> 3);
                    for (j = 0; j < width; j++) {
                        cindex = (unsigned char) (databits)[k*width+j];
                        if (cindex != bg) {
				//cout << "cindex=" << (int)cindex << endl;
	rgbColor=get_rgb((int)cindex);
	linePen=QPen(QColor(rgbColor->red,rgbColor->green,rgbColor->blue));
	GeneralPainter->setPen(linePen);
				clp_painter.drawPoint(j,k);
	GeneralPainter->drawPoint(j+x1,k+y1);
                            clipmask_ptr[line_off+(j>>3)] |= (0x01 << (j%8));
                        }
                    }
                }
        
                ///clipmask=XCreateBitmapFromData(disp, root, clipmask_ptr, 
                ///                                            width, height);
                xfree(clipmask_ptr);

            }
        }
    } else {
        pixmap_ptr = (char*)xcalloc((PAD(width, bitmap_pad)>>3) * height,sizeof(char));
        if (pixmap_ptr == NULL) {
            errmsg("xmalloc failed in xlibputpixmap()");
            return;
        }
        memcpy(pixmap_ptr, databits, ((PAD(width, bitmap_pad)>>3) * height));

        fg = getcolor();
        if (fg != xlibcolor) {
            ///XSetForeground(disp, gc, xvlibcolors[fg]);
            xlibcolor = fg;
        }
        ///ximage=XCreateImage(disp, visual,
        ///                    1, XYBitmap, 0, pixmap_ptr, width, height,
        ///                    bitmap_pad, /* lines padded to bytes */
        ///                    0 /* number of bytes per line */
        ///                    );
        if (pixmap_type == PIXMAP_TRANSPARENT) {
            ///clipmask=XCreateBitmapFromData(disp, root, pixmap_ptr, 
            ///                                  PAD(width, bitmap_pad), height);
        }
    }

    if (pixmap_type == PIXMAP_TRANSPARENT) {
        ///XSetClipMask(disp, gc, clipmask);
       /// XSetClipOrigin(disp, gc, xp.x, xp.y);
    }
        
        
    /* Force bit and byte order */
    ///ximage->bitmap_bit_order=LSBFirst;
    ///ximage->byte_order=LSBFirst;
    
    ///XPutImage(disp, displaybuff, gc, ximage, 0, 0, xp.x, xp.y, width, height);
    ///XDestroyImage(ximage);

clp_painter.end();
//GeneralPainter->drawPixmap(x1,y1,clipmask);

    if (pixmap_type == PIXMAP_TRANSPARENT) {
        ///XFreePixmap(disp, clipmask);
        ///clipmask = 0;
        ///XSetClipMask(disp, gc, None);
        ///XSetClipOrigin(disp, gc, 0, 0);
    }    
}

void xlibleavegraphics(void)
{
    int cg = get_cg();  
    if (is_graph_hidden(cg) == FALSE) {
        draw_focus(cg);
    }
    reset_crosshair();
    ///xlibredraw(xwin, 0, 0, win_w, win_h);
    ///XFlush(disp);
//GeneralPainter->end();
//mainWin->mainArea->repaint();
}

QColor get_Color(int i)
{
RGB * rgb_color=get_rgb(i);
return QColor(rgb_color->red,rgb_color->green,rgb_color->blue);
}

void set_Brush_only(int fg,int bg,int p)
{
QBrush brush=GeneralPainter->brush();
brush.setColor(get_Color(fg));
if (p==0)
{
GeneralPainter->setBrush(Qt::NoBrush);
return;
}
else if (p==1)
{
brush.setStyle(Qt::SolidPattern);
GeneralPainter->setBrush(brush);
return;
}
else
{
QPixmap pic(16,16);
brush.setTexture(*(patterns[p]));
pic.fill(get_Color(bg));
QPainter paintr(&pic);
paintr.setBrush(brush);
paintr.setPen(Qt::NoPen);
paintr.drawRect(0,0,16,16);
paintr.end();
brush.setTexture(pic);
GeneralPainter->setBrush(brush);
return;
}
}

void set_Pen_only(void)
{
QPen tmpPen(GeneralPainter->pen());

tmpPen.setColor(get_Color(draw_props.pen.color));
tmpPen.setWidthF(qreal(draw_props.linew));
switch (xliblinecap)
{
case LINECAP_BUTT:
tmpPen.setCapStyle(Qt::SquareCap);
break;
case LINECAP_ROUND:
tmpPen.setCapStyle(Qt::RoundCap);
break;
case LINECAP_PROJ:
tmpPen.setCapStyle(Qt::FlatCap);
break;
}
switch (xliblinejoin)
{
case LINEJOIN_MITER:
tmpPen.setJoinStyle(Qt::MiterJoin);
break;
case LINEJOIN_ROUND:
tmpPen.setJoinStyle(Qt::RoundJoin);
break;
case LINEJOIN_BEVEL:
tmpPen.setJoinStyle(Qt::BevelJoin);
break;
}
if (xliblinestyle==0)
tmpPen.setStyle(Qt::NoPen);
else if (draw_props.lines==1)
tmpPen.setStyle(Qt::SolidLine);
else
{
tmpPen.setStyle(Qt::CustomDashLine);
tmpPen.setDashPattern(*PenDashPattern[draw_props.lines]);
}

if (draw_props.pen.pattern>1)//0=none, 1=solid, >1 special filling pattern
{
QBrush tmpBrush;
tmpBrush.setTexture(patterns[draw_props.pen.pattern]->copy(0,0,16,16));
tmpBrush.setColor(tmpPen.color());
QPixmap pic(16,16);
pic.fill(get_Color(getbgcolor()));
QPainter paintr(&pic);
paintr.setBrush(tmpBrush);
paintr.setPen(Qt::NoPen);
paintr.drawRect(0,0,16,16);
paintr.end();
tmpBrush.setTexture(pic);
tmpPen.setBrush(tmpBrush);
}

GeneralPainter->setPen(tmpPen);
}

