/***************************************************************************
 *   Copyright (C) 2008-2011 by Andreas Winter   *
 *   andreas.f.winter@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "fundamentals.h"
#include "MainWindow.h"
#include "allWidgets.h"
#include "undo_module.h"

extern MainWindow * mainWin;
extern frmTextProps * TextProps;
extern frmTextProps * EditTextProps;
extern frmLineProps * LineProps;
extern frmLineProps * EditLineProps;
extern frmEllipseProps * BoxProps;
extern frmEllipseProps * EditBoxProps;
extern frmEllipseProps * EllipseProps;
extern frmEllipseProps * EditEllipseProps;
extern frmSetEditor * FormSetEditor;
extern frmEditBlockData * FormEditBlockData;
//extern frmEditColumnProp * EditColumn;
extern QPixmap * GraceIcon;
extern QIcon * ColorIcons[16];
extern QPixmap * ColorPixmaps[16];
extern QString * ColorNames[16];
extern QIcon * LineIcons[MAXLINESTYLES];
extern QPixmap * LinePixmaps[MAXLINESTYLES];
extern QBitmap * patterns[MAXPATTERNS];
extern QPixmap * PatternPixmaps[MAXPATTERNS];
extern QPixmap * Qt_justifications[12];
extern QPixmap * Qt_matrixOrder[8];

extern QFont stdFont;
extern QFontMetrics stdFontMetrics;

extern graph * g;
extern int maxgraph;
extern int new_set_no;

extern void strToUpper(char * tar,char * ch);
extern void add_ColorSelector(ColorSelector * colSel);
extern void showSetInSpreadSheet(int gno,int setno);
void close_ss_editor(int gno,int setno);
extern frmLoadEval * FormLoadAndEvaluate;

extern void add_SetSelector(uniList * setSel);
extern void add_GraphSelector(uniList * grSel);
extern void add_SetChoiceItem(uniList * setSel);
extern void HelpCB(char *data);

using namespace std;

/* lookup table to determine if character is a floating point digit
 * only allowable char's [0-9.eE]
 */
unsigned char fpdigit[256] = {
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void sort(int number,int * items)//bubble-sort (I know that I am stupid - but it works)
{
int dummy;
    for (int i=0;i<number;i++)
    {
	for (int j=i+1;j<number;j++)
	{
            if (items[j]<items[i])
            {
            dummy=items[j];
            items[j]=items[i];
            items[i]=dummy;
            }
	}
    }
}

struct komplex add_komplex(struct komplex a,struct komplex b)
{
struct komplex c={a.real+b.real,a.imag+b.imag};
return c;
}

struct komplex sub_komplex(struct komplex a,struct komplex b)
{
struct komplex c={a.real-b.real,a.imag-b.imag};
return c;
}

struct komplex mult_komplex(struct komplex a,struct komplex b)
{
//(ar+i*ai)*(br+i*bi)=(ar*br-ai*bi)+i*(ai*br+bi*ar)
struct komplex c={a.real*b.real-a.imag*b.imag,a.imag*b.real+b.imag*a.real};
return c;
}

struct komplex div_komplex(struct komplex a,struct komplex b)
{
//(ar+i*ai)/(br+i*bi)=(ar+i*ai)/(br+i*bi)*(br-i*bi)/(br-i*bi)=((ar*br+ai*bi)+i*(ai*br-bi*ar))/(br*br+bi*bi)
double betr=b.real*b.real+b.imag*b.imag;
struct komplex c={(a.real*b.real+a.imag*b.imag)/betr,(a.imag*b.real-b.imag*a.real)/betr};
return c;
}

struct komplex pow_komplex(struct komplex a,double n)
{
static double pi=2.0*asin(1.0);
double absval=pow(hypot(a.real,a.imag),n);
double phase=atan2(a.imag,a.real)*n;
/*if (a.real==0.0)
{
if (a.imag>=0.0) phase=0.5*pi;
else phase=1.5*pi;
}*/
struct komplex c={absval*cos(phase),absval*sin(phase)};
return c;
}

Panel::Panel(QPixmap * pix,QWidget * parent):QLabel(parent)
{
p=pix;
inpaint=false;
setMouseTracking(TRUE);
}

void Panel::paintEvent(QPaintEvent *event)
{
if (inpaint==false)
inpaint=true;
else
return;
QPainter paint(this);
paint.drawPixmap(0,0,*p);
paint.end();
QLabel::paintEvent(event);
inpaint=false;
}

void Panel::mouseMoveEvent( QMouseEvent * event )
{
emit(mouseMoving());
}

void Panel::mouseReleaseEvent(QMouseEvent *event)
{
emit(mouseClicked());
}

panelWindow::panelWindow(int rows,int cols,QPixmap ** pix,QWidget * parent):QDialog(parent)
{
frm=new QFrame(this);
layout0=new QHBoxLayout(this);
layout0->setMargin(0);
layout0->setSpacing(0);
frm->setFrameStyle(QFrame::Raised | QFrame::WinPanel);
signalMapper1=new QSignalMapper;
signalMapper2=new QSignalMapper;
pixmaps=pix;
row_count=rows;
col_count=cols;
number_of_elements=row_count*col_count;
elementWidth=pix[0]->width();
elementHeight=pix[0]->height();
marked=highlighted=-1;//-1 means nothing ist marked or highlighted
layout=new QGridLayout;
layout->setMargin(0);
layout->setSpacing(0);
int r=0,c=0;
lblPanel=new class Panel*[number_of_elements];
	for (int i=0;i<number_of_elements;i++)
	{
	lblPanel[i]=new class Panel(pixmaps[i],this);
	lblPanel[i]->setMinimumSize(elementWidth,elementHeight);

connect(lblPanel[i], SIGNAL(mouseMoving()), signalMapper1, SLOT(map()));
connect(lblPanel[i], SIGNAL(mouseClicked()), signalMapper2, SLOT(map()));
signalMapper1->setMapping(lblPanel[i],i);
signalMapper2->setMapping(lblPanel[i],i);

	layout->addWidget(lblPanel[i],r,c);
	r++;
		if (r>=row_count)
		{
		r=0;
		c++;
		}
	}
connect(signalMapper1, SIGNAL(mapped(int)),this, SLOT(mouseMovedIn(int)));
connect(signalMapper2, SIGNAL(mapped(int)),this, SLOT(mouseClickedIn(int)));
clickTime=new QTime();
clickTime->start();
frm->setLayout(layout);
setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
setMouseTracking(TRUE);
layout0->addWidget(frm);
setLayout(layout0);
}

void panelWindow::setMarked(int i)
{
if (marked==i) return;
if (marked!=-1)
{
lblPanel[marked]->setFrameShape(QFrame::NoFrame);
lblPanel[marked]->repaint();
}
marked=i;
lblPanel[marked]->setFrameShape(QFrame::Panel);
lblPanel[marked]->setFrameStyle(QFrame::Raised | QFrame::WinPanel);
lblPanel[marked]->repaint();
}

void panelWindow::mouseMovedIn(int i)
{
if (i==highlighted) return;
//a new one is to be highlighted
if (highlighted!=-1)
{
	if (highlighted==marked)
	{
	lblPanel[highlighted]->setFrameShape(QFrame::Panel);
	lblPanel[highlighted]->setFrameStyle(QFrame::Raised | QFrame::WinPanel);
	lblPanel[highlighted]->repaint();
	}
	else
	{
	lblPanel[highlighted]->setFrameShape(QFrame::NoFrame);
	lblPanel[highlighted]->repaint();
	}
}
if (i!=-1)
{
lblPanel[i]->setFrameShape(QFrame::Panel);
lblPanel[i]->setFrameStyle(QFrame::Sunken | QFrame::WinPanel);
lblPanel[i]->repaint();
}
highlighted=i;
}

void panelWindow::leaveEvent( QEvent * event )
{
if (highlighted!=-1)
{
	if (highlighted==marked)
	{
	lblPanel[highlighted]->setFrameShape(QFrame::Panel);
	lblPanel[highlighted]->setFrameStyle(QFrame::Raised | QFrame::WinPanel);
	lblPanel[highlighted]->repaint();
	}
	else
	{
	lblPanel[highlighted]->setFrameShape(QFrame::NoFrame);
	lblPanel[highlighted]->repaint();
	}
}
highlighted=-1;
}

void panelWindow::mouseClickedIn(int i)
{
hide();
emit(newSelection(i));
}

void panelWindow::mousePressEvent(QMouseEvent *event)
{
pressed=true;
}

void panelWindow::mouseReleaseEvent(QMouseEvent *event)
{
int curTime;
if (pressed==false) return;
curTime=clickTime->restart();
if (curTime<300)
{
pressed=false;
return;
}
int x=event->x();
int y=event->y();
int r=y/elementHeight;
int c=x/elementWidth;
int element=r+c*row_count;
if (x<0 || y<0 || x>col_count*elementWidth || y>row_count*elementHeight) 
{
element=-1;
if (marked>=0)
lblPanel[marked]->mouseReleaseEvent(event);
}
releaseMouse();
if (element>=0 && element<number_of_elements)
{
lblPanel[element]->mouseReleaseEvent(event);
}
hide();
}

void panelWindow::mouseMoveEvent(QMouseEvent * event)
{
int x=event->x();
int y=event->y();
int r=y/elementHeight;
int c=x/elementWidth;
int element=r+c*row_count;
if (x<0 || y<0) element=-1;
if (x>col_count*elementWidth || y>row_count*elementHeight) element=-1;
if (element<0 || element>=number_of_elements)
{
leaveEvent(event);
}
else
{
	if (element!=highlighted)
	{
	lblPanel[element]->mouseMoveEvent(event);
	}
}
}

newCombo::newCombo(int rows,int cols,QPixmap ** pix,QString ** titles,bool showTextOnly,QWidget * parent):QComboBox(parent)
{
text_only=showTextOnly;
if (text_only==false)
setIconSize(QSize(pix[0]->width(),pix[0]->height()));
panels=new panelWindow(rows,cols,pix,this);
panels->hide();
connect(panels,SIGNAL(newSelection(int)),SLOT(wrapperSetCurrentIndex(int)));
title_strings=new QString[panels->number_of_elements];
for (int i=0;i<panels->number_of_elements;i++)
title_strings[i]=*(titles[i]);
setCurrentIndex(0);
}

void newCombo::wrapperSetCurrentIndex(int index)
{
setCurrentIndex(index);
emit(currentIndexChanged(index));
}

void newCombo::setCurrentIndex(int index)
{
if (index<0 || index>=panels->number_of_elements)
{
cout << "Selection Index out of range!" << endl;
return;
}
panels->setMarked(index);
selection=index;
clear();
if (text_only==true)
addItem(title_strings[index]);
else
addItem(QIcon(*panels->pixmaps[index]),"");
QMouseEvent * a=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(0,0),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
QComboBox::mouseReleaseEvent(a);
}

int newCombo::currentIndex(void)
{
return selection;
}

void newCombo::showPopup()
{
int row_number=0;
int col_number=0;
for (int i=0;i<selection;i++)
{
row_number++;
if (row_number>=panels->row_count)
{
row_number=0;
col_number++;
}
}
panels->setMarked(selection);
panels->move(mapToGlobal(QPoint(-col_number*panels->elementWidth,-row_number*panels->elementHeight)));
panels->show();
//panels->pressed=false;
panels->clickTime->restart();
panels->pressed=true;
qApp->processEvents();
panels->repaint();
panels->grabMouse();
}

fitLine::fitLine(QWidget * parent,int nr):QWidget(parent)
{
char dummy[128];
sprintf(dummy,"A%d:",nr);
lblA=new QLabel(QString(dummy),this);
sprintf(dummy,"< A%d <",nr);
lblABounds=new QLabel(QString(dummy),this);
chkBonds=new QCheckBox(tr("Bounds:"),this);
connect(chkBonds,SIGNAL(stateChanged(int)),this,SLOT(constr_check(int)));
ledValue=new QLineEdit(QString("1"),this);
ledLowerBound=new QLineEdit(QString("1"),this);
ledHighterBound=new QLineEdit(QString("1"),this);
layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblA);
layout->addWidget(ledValue);
layout->addWidget(chkBonds);
layout->addWidget(ledLowerBound);
layout->addWidget(lblABounds);
layout->addWidget(ledHighterBound);
setLayout(layout);
}

void fitLine::constr_check(int t)
{
if (t==0)
{
ledLowerBound->setEnabled(false);
ledHighterBound->setEnabled(false);
lblABounds->setEnabled(false);
}
else
{
ledLowerBound->setEnabled(true);
ledHighterBound->setEnabled(true);
lblABounds->setEnabled(true);
}
}

void fitLine::getValues(double & value,bool & active,double & lowerBound,double & upperBound)
{
value=atof(ledValue->text().toAscii());
active=chkBonds->isChecked()==TRUE?true:false;
lowerBound=atof(ledLowerBound->text().toAscii());
upperBound=atof(ledHighterBound->text().toAscii());
}

axisLine::axisLine(QWidget * parent,int nr):QWidget(parent)
{
char dummy[128];
sprintf(dummy,"%d",nr);
lblNr=new QLabel(QString(dummy),this);
ledLocation=new QLineEdit(QString(""),this);
ledLabel=new QLineEdit(QString(""),this);
layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblNr);
layout->addWidget(ledLocation);
layout->addWidget(ledLabel);
setLayout(layout);
}

headLine::headLine(QWidget * parent,int columns):QWidget(parent)
{
QString dummy;
char dummy2[128];
cols=columns;

empty=new QWidget(this);
signalMapper=new QSignalMapper(this);

layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(empty);

for (int i=0;i<6;i++)
{
	switch (i)
	{
	case 0:
	dummy=QString("X");
	break;
	case 1:
	dummy=QString("Y");
	break;
	default:
	sprintf(dummy2,"Y%d",i-1);
	dummy=QString(dummy2);
	break;
	}
cmdColHead[i]=new QPushButton(dummy,this);
connect(cmdColHead[i],SIGNAL(clicked()),signalMapper,SLOT(map()));
signalMapper->setMapping(cmdColHead[i],i);
if (i<cols)
{
cmdColHead[i]->setVisible(TRUE);
layout->addWidget(cmdColHead[i]);
}
else
cmdColHead[i]->setVisible(FALSE);
}
setLayout(layout);
connect(signalMapper,SIGNAL(mapped(int)),SLOT(pressed(int)));
}

void headLine::resize(int columns)
{
if (columns<cols)//the new one has lesser columns than the old one
{
	for (int i=columns;i<cols;i++)
	{
	cmdColHead[i]->setVisible(FALSE);
	layout->removeWidget(cmdColHead[i]);
	}
}
else//more columns
{
	for (int i=cols;i<columns;i++)
	{
	cmdColHead[i]->setVisible(TRUE);
	layout->addWidget(cmdColHead[i]);
	}
}
update();
parentWidget()->updateGeometry();
cols=columns;
}

void headLine::pressed(int i)
{
emit(col_pressed(i));
}

spreadLine::spreadLine(QWidget * parent,int row_nr,int columns):QWidget(parent)
{
char dummy[128];
marked=false;
row=row_nr;
cols=columns;
sprintf(dummy,"%d",row);
cmdSelect=new QPushButton(QString(dummy),this);
connect(cmdSelect,SIGNAL(clicked()),SLOT(clickSelect()));
layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(cmdSelect);
for (int i=0;i<6;i++)
{
ledInput[i]=new QLineEdit(QString(""),this);
	if (i<cols)
	{
	ledInput[i]->setVisible(TRUE);
	layout->addWidget(ledInput[i]);
	}
	else
	ledInput[i]->setVisible(FALSE);

}
setLayout(layout);
}

spreadLine::~spreadLine()
{
	for (int i=0;i<6;i++)
	{
		if (i<cols)
		layout->removeWidget(ledInput[i]);
	ledInput[i]->disconnect();
	delete ledInput[i];
	}
}

void spreadLine::resize(int columns)
{
if (cols>columns)//new are fewer columns
{
	for (int i=columns;i<cols;i++)
	{
	layout->removeWidget(ledInput[i]);
	ledInput[i]->setVisible(FALSE);
	}
}
else
{
	for (int i=cols;i<columns;i++)
	{
	layout->addWidget(ledInput[i]);
	ledInput[i]->setVisible(TRUE);
	}
}
cols=columns;
}

void spreadLine::clickSelect(void)
{
marked=!marked;
QPalette pal;
QBrush t1,t2;
	for (int i=0;i<6;i++)
	{
	pal=ledInput[i]->palette();
	t1=pal.text();
	t2=pal.base();
	//exchange forground and background to show selection
	pal.setBrush(QPalette::Active,QPalette::Base,t1);
	pal.setBrush(QPalette::Active,QPalette::Text,t2);
	ledInput[i]->setPalette(pal);
	}
}

spreadSheet::spreadSheet(QWidget * parent,int type,int row_count,int col_count):QWidget(parent)
{
sheet_type=type;
rows=row_count;//rows with actual inputs
cols=col_count;

layout=new QVBoxLayout;
layout->setMargin(0);
layout->setSpacing(0);
generate_layout();

setLayout(layout);

/*stdWidth=ledInput[0][0]->width();
stdHeight=ledInput[0][0]->height();*/

}

void spreadSheet::generate_layout(void)
{
char dummy[120];
signalMapper=new QSignalMapper(this);

switch (sheet_type)
{
case 0:
headline=new headLine(this,cols);
layout->addWidget(headline);
spreadlines=new spreadLine*[rows];
	for (int i=0;i<rows;i++)
	{
	spreadlines[i]=new spreadLine(this,i,cols);
	layout->addWidget(spreadlines[i]);
	}
	/*if (rows>0)
	{
	headline->empty->setMaximumWidth(spreadlines[0]->cmdSelect->width());
	}*/
break;
case 1:
fitlines=new fitLine*[11];
	for (int i=0;i<11;i++)
	{
	fitlines[i]=new fitLine(this,i);
		if (i<rows)
		{
		fitlines[i]->setVisible(TRUE);
		layout->addWidget(fitlines[i]);
		}
		else
		{
		fitlines[i]->setVisible(FALSE);
		}
	}
break;
case 2:
axislines=new axisLine*[rows];
	for (int i=0;i<rows;i++)
	{
	axislines[i]=new axisLine(this,i);
	layout->addWidget(axislines[i]);
	}
break;
}

for (int i=0;i<rows;i++)
{
;
//layout->addWidget();
//connect(VHeads[i],SIGNAL(clicked()),signalMapper1,SLOT(map()));
//signalMapper1->setMapping(VHeads[i],i);
}
//connect(signalMapper,SIGNAL(mapped(int)),SLOT(clickHHeader(int)));
}

spreadSheet::~spreadSheet()
{

}

void spreadSheet::clickHHeader(int nr)
{
/*EditColumn->selColumn->setCurrentIndex(nr);
EditColumn->show();
EditColumn->raise();*/
}

void spreadSheet::clickVHeader(int nr)
{
/*marked[nr]=!marked[nr];
QPalette pal;
QBrush t1,t2;
	for (int i=0;i<cols;i++)
	{
	pal=ledInput[nr][i]->palette();
	t1=pal.text();
	t2=pal.base();
	//exchange forground and background to show selection
	pal.setBrush(QPalette::Active,QPalette::Base,t1);
	pal.setBrush(QPalette::Active,QPalette::Text,t2);
	ledInput[nr][i]->setPalette(pal);
	}*/
}

void spreadSheet::entryChanged(void)
{
emit(changed());
}

void spreadSheet::resize(int row,int col)
{

/*if (rows>0 && !sheet_type)
{
for (int i=0;i<6;i++)
headline->cmdColHead[i]->setMinimumSize(spreadlines[0]->ledInput[i]->width(),spreadlines[0]->ledInput[i]->height());
}*/

switch (sheet_type)
{
case 0:

setGeometry(0,0,width(),(row+1)*25);

headline->resize(col);

for (int i=0;i<rows;i++)
{
layout->removeWidget(spreadlines[i]);
delete spreadlines[i];
}
delete[] spreadlines;

spreadlines=new spreadLine*[row];
for (int i=0;i<row;i++)
{
spreadlines[i]=new spreadLine(this,i,col);
layout->addWidget(spreadlines[i]);
}
rows=row;
cols=col;

break;
case 1:
	if (row>rows)
	{
		for (int i=rows;i<row;i++)
		{
		layout->addWidget(fitlines[i]);
		fitlines[i]->setVisible(TRUE);
		}
	}
	else
	{
		for (int i=row;i<rows;i++)
		{
		fitlines[i]->setVisible(FALSE);
		layout->removeWidget(fitlines[i]);
		}
	}
	rows=row;
	cols=col;
break;
case 2:

break;
}

/*
setGeometry(0,0,(col+1)*stdWidth,(row+1)*stdHeight);
///delete current Elements
layout->removeWidget(empty);
delete empty;
delete[] marked;
for (int i=0;i<rows;i++)
{
layout->removeWidget(VHeads[i]);
VHeads[i]->disconnect();
delete VHeads[i];
	for (int j=0;j<cols;j++)
	{
	layout->removeWidget(ledInput[i][j]);
	ledInput[i][j]->disconnect();
	delete ledInput[i][j];
	}
delete[] ledInput[i];
}
delete[] ledInput;
delete[] VHeads;
for (int i=0;i<6;i++)
{
layout->removeWidget(HHeads[i]);
HHeads[i]->disconnect();
delete HHeads[i];
}
delete[] HHeads;

signalMapper1->disconnect();
signalMapper2->disconnect();

rows=row;
cols=col;

generate_layout();
*/
update();
parentWidget()->updateGeometry();
}

stdSlider::stdSlider(QWidget * parent,QString label,int min,int max):QWidget(parent)
{
QRect rec=stdFontMetrics.boundingRect(QString("100"));
textHeight=rec.height();
if (textHeight<16) textHeight=16;
setMinimumSize(QSize(180,textHeight*3));
Indicator=new QLabel("0",this);
Indicator->setGeometry(0,0,32,textHeight);//20
sldSlider=new QSlider(Qt::Horizontal,this);
sldSlider->setRange(min,max);
sldSlider->setGeometry(Indicator->x(),Indicator->y()+Indicator->height(),200,textHeight);//20
connect(sldSlider,SIGNAL(valueChanged(int)),SLOT(changed(int)));
lblText=new QLabel(label,this);
lblText->move(Indicator->x(),sldSlider->y()+sldSlider->height());//,150,20);
lblText->setGeometry(Indicator->x(),sldSlider->y()+sldSlider->height(),sldSlider->width(),textHeight);//20
setMinimumSize(60,3*textHeight);
setSizePolicy(QSizePolicy::Expanding,QSizePolicy::MinimumExpanding);
}

QSize stdSlider::sizeHint(void)
{
return QSize(60,textHeight*3);//60
}

QSize stdSlider::minimumSizeHint(void)
{
return QSize(60,textHeight*3);//60
}

void stdSlider::resizeEvent( QResizeEvent * e)
{
e->accept();
int width=e->size().width();
int height=e->size().height();
QFont fo=font();
if (height<3*textHeight)
{
fo.setPixelSize(fo.pixelSize()-2);
textHeight-=2;
setFont(fo);
}
else if (height<3*textHeight && fo.pixelSize()<14)
{
fo.setPixelSize(14);
textHeight-=2;
setFont(fo);
}

Indicator->setGeometry(Indicator->x(),0,Indicator->width(),textHeight);
sldSlider->setGeometry(0,textHeight,width,height-2*textHeight);
lblText->setGeometry(0,height-textHeight,lblText->width(),textHeight);
changed(sldSlider->value());

/*sldSlider->setGeometry(0,textHeight,width,height/3);
Indicator->setGeometry(Indicator->x(),0,Indicator->width(),sldSlider->height());
lblText->setGeometry(sldSlider->x(),sldSlider->y()+sldSlider->height(),lblText->width(),sldSlider->height());
changed(sldSlider->value());*/
}

void stdSlider::changed(int i)
{
char dummy[50];
int pos;
pos=sldSlider->x()+(sldSlider->width()-Indicator->width())*i/sldSlider->maximum();
Indicator->move(pos,Indicator->y());
sprintf(dummy,"%d",i);
Indicator->setText(QString(dummy));
}

int stdSlider::value(void)
{
return sldSlider->value();
}

void stdSlider::setValue(int i)
{
sldSlider->setValue(i);
changed(i);
}

FontSelector::FontSelector(QWidget * parent):QWidget(parent)
{
lblText=new QLabel(tr("Font:"));
cmbFontSelect=new QComboBox();
for (int i=0;i<number_of_fonts();i++)
cmbFontSelect->addItem(get_fontalias(i));

layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(cmbFontSelect);
setLayout(layout);
}

int FontSelector::currentIndex(void)
{
return cmbFontSelect->currentIndex();
}

void FontSelector::setCurrentIndex(int i)
{
cmbFontSelect->setCurrentIndex(i);
}

PositionSelector::PositionSelector(QWidget * parent):QWidget(parent)
{
lblText=new QLabel(tr("Position in:"));
cmbPositionSelect=new QComboBox();
cmbPositionSelect->addItem(tr("World coordinates"));
cmbPositionSelect->addItem(tr("Viewport coordinates"));
layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(cmbPositionSelect);
setLayout(layout);
}

int PositionSelector::currentIndex(void)
{
return cmbPositionSelect->currentIndex();
}

int PositionSelector::currentValue(void)
{
return cmbPositionSelect->currentIndex()==0?COORD_WORLD:COORD_VIEW;
}

void PositionSelector::setCurrentIndex(int i)
{
cmbPositionSelect->setCurrentIndex(i);
}

JustificationSelector::JustificationSelector(QWidget * parent):QWidget(parent)
{
just_names=new QString*[12];

just_names[0]=new QString("lm");
just_names[1]=new QString("cm");
just_names[2]=new QString("rm");
just_names[3]=new QString("lb");
just_names[4]=new QString("cb");
just_names[5]=new QString("rb");
just_names[6]=new QString("lm");
just_names[7]=new QString("cm");
just_names[8]=new QString("rm");
just_names[9]=new QString("lt");
just_names[10]=new QString("ct");
just_names[11]=new QString("rt");

cmbJustSelect=new newCombo(3,4,Qt_justifications,just_names,false,this);
lblText=new QLabel(tr("Justification:"));
/*cmbJustSelect=new QComboBox();
for (int i=0;i<12;i++)
cmbJustSelect->addItem(QIcon(Qt_justifications[i]->copy(Qt_justifications[i]->rect())),"");*/

layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(cmbJustSelect);
setLayout(layout);
}

int JustificationSelector::currentIndex(void)
{
return cmbJustSelect->currentIndex();
}

void JustificationSelector::setCurrentIndex(int i)
{
cmbJustSelect->setCurrentIndex(i);
}

stdButtonGroup::stdButtonGroup(QWidget * parent,bool appl,bool acc,bool help):QWidget(parent)
{
showAccept=acc;
showApply=appl;
showHelp=help;

cmdAccept=new QPushButton(tr("Accept"));
cmdApply=new QPushButton(tr("Apply"));
cmdClose=new QPushButton(tr("Close"));
cmdHelp=new QPushButton(tr("Help"));

layout=new QHBoxLayout;
layout->setMargin(2);
if (showApply==true)
layout->addWidget(cmdApply);
else
cmdApply->hide();
if (showAccept==true)
layout->addWidget(cmdAccept);
else
cmdAccept->hide();

layout->addWidget(cmdClose);

if (showHelp==true)
layout->addWidget(cmdHelp);
else
cmdHelp->hide();
setLayout(layout);
}

ColorSelector::ColorSelector(QWidget * parent):QWidget(parent)
{
lblText=new QLabel(tr("Color:"));

/*cmbColorSelect=new QComboBox();
for (int i=0;i<16;i++)
cmbColorSelect->addItem(*ColorIcons[i],"");
cmbColorSelect->setIconSize(QSize(82,16));
*/

cmbColorSelect=new newCombo(4,4,ColorPixmaps,ColorNames,true,this);
connect(cmbColorSelect,SIGNAL(currentIndexChanged(int)),SLOT(panelIndexChanged(int)));

layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(cmbColorSelect);
setLayout(layout);

add_ColorSelector(this);
}

void ColorSelector::panelIndexChanged(int i)
{
emit(currentIndexChanged(i));
}

int ColorSelector::currentIndex(void)
{
return cmbColorSelect->currentIndex();
}

void ColorSelector::setCurrentIndex(int i)
{
cmbColorSelect->setCurrentIndex(i);
}

StdSelector::StdSelector(QWidget * parent)
{
int number=2;
QString * entr=new QString[2];
entr[0]=QString("");
entr[1]=QString("");
QString label("");
StdSelector(parent,label,number,entr);
}

StdSelector::StdSelector(QWidget * parent,QString label,int number,QString * entr):QWidget(parent)
{
lblText=new QLabel(label);
cmbSelect=new QComboBox();
number_of_entries=number;
entries=new QString[number];
entryValues=new int[number];
for (int i=0;i<number;i++)
{
entries[i]=entr[i];
entryValues[i]=i;
cmbSelect->addItem(entr[i]);
}

layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(cmbSelect);
setLayout(layout);
}

StdSelector::~StdSelector()
{
delete[] entries;
delete[] entryValues;
}

void StdSelector::setValues(int * values)
{
for (int i=0;i<number_of_entries;i++)
{
entryValues[i]=values[i];
}
}

void StdSelector::setNewEntries(int number,QString * entr)
{
int * values=new int[number];
for (int i=0;i<number;i++)
values[i]=i;

setNewEntries(number,entr,values);
delete[] values;
}

void StdSelector::setNewEntries(int number,QString * entr,int * values)
{
cmbSelect->clear();
delete[] entries;
delete[] entryValues;
number_of_entries=number;
entries=new QString[number];
entryValues=new int[number];
for (int i=0;i<number;i++)
{
entries[i]=entr[i];
entryValues[i]=values[i];
cmbSelect->addItem(entr[i]);
}
}

int StdSelector::currentIndex(void)
{
return cmbSelect->currentIndex();
}

int StdSelector::currentValue(void)
{
return entryValues[cmbSelect->currentIndex()];
}

void StdSelector::setCurrentIndex(int i)
{
if (i>=0 && i<cmbSelect->count())
cmbSelect->setCurrentIndex(i);
else
cmbSelect->setCurrentIndex(0);
}

void StdSelector::setCurrentValue(int i)
{
int index=0;
for (int j=0;j<number_of_entries;j++)
{
	if (i==entryValues[j])
	{
	index=j;
	break;
	}
}
cmbSelect->setCurrentIndex(index);
}

LineStyleSelector::LineStyleSelector(QWidget * parent):QWidget(parent)
{
lblText=new QLabel(tr("Line style:"));
/*cmbStyleSelect=new QComboBox();
for (int i=0;i<MAXLINESTYLES;i++)
cmbStyleSelect->addItem(*LineIcons[i],"");
cmbStyleSelect->setIconSize(QSize(82,22));*/
LineNames=new QString*[MAXLINESTYLES];
char dummy[48];
for (int i=0;i<MAXLINESTYLES;i++)
{
sprintf(dummy,"%d",i);
LineNames[i]=new QString(dummy);
}

cmbStyleSelect=new newCombo(MAXLINESTYLES,1,LinePixmaps,LineNames,false,this);

layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(cmbStyleSelect);
setLayout(layout);
}

int LineStyleSelector::currentIndex(void)
{
return cmbStyleSelect->currentIndex();
}

void LineStyleSelector::setCurrentIndex(int i)
{
cmbStyleSelect->setCurrentIndex(i);
}

FillPatternSelector::FillPatternSelector(QWidget * parent):QWidget(parent)
{
lblText=new QLabel(tr("Fill pattern:"),this);

/*
cmbFillPattern=new QComboBox(this);
cmbFillPattern->addItem(tr("None"));
for (int i=1;i<MAXPATTERNS;i++)
cmbFillPattern->addItem(QIcon(patterns[i]->copy(patterns[i]->rect())),"");
*/

char dummy[48];
PatternNames=new QString*[MAXPATTERNS];
sprintf(dummy,"None");
PatternNames[0]=new QString(dummy);
for (int i=1;i<MAXPATTERNS;i++)
{
sprintf(dummy,"%d",i);
PatternNames[i]=new QString(dummy);
}

cmbFillPattern=new newCombo(8,4,PatternPixmaps,PatternNames,false,this);

layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(cmbFillPattern);
setLayout(layout);
}

int FillPatternSelector::currentIndex(void)
{
return cmbFillPattern->currentIndex();
}

void FillPatternSelector::setCurrentIndex(int i)
{
cmbFillPattern->setCurrentIndex(i);
}

OrderSelector::OrderSelector(QWidget * parent):QWidget(parent)
{
OrderNames=new QString*[4*2];
OrderNames[0]=new QString("hv_lr");
OrderNames[1]=new QString("hv_lr");
OrderNames[2]=new QString("hv_rl");
OrderNames[3]=new QString("hv_rl");
OrderNames[4]=new QString("vh_lr");
OrderNames[5]=new QString("vh_lr");
OrderNames[6]=new QString("vh_rl");
OrderNames[7]=new QString("vh_rl");
lblText=new QLabel(tr("Order:"),this);

cmbOrderPattern=new newCombo(4,2,Qt_matrixOrder,OrderNames,false,this);

layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(cmbOrderPattern);
setLayout(layout);
}

int OrderSelector::currentIndex(void)
{
return cmbOrderPattern->currentIndex();
}

void OrderSelector::setCurrentIndex(int i)
{
cmbOrderPattern->setCurrentIndex(i);
}


LineWidthSelector::LineWidthSelector(QWidget * parent):QWidget(parent)
{
lblText=new QLabel(tr("Line width:"));
spnLineWidth=new QDoubleSpinBox(this);
spnLineWidth->setRange(0.0,MAX_LINEWIDTH);
spnLineWidth->setDecimals(1);
spnLineWidth->setSingleStep(0.5);
layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(spnLineWidth);
setLayout(layout);
}

double LineWidthSelector::value(void)
{
return spnLineWidth->value();
}

void LineWidthSelector::setValue(double i)
{
spnLineWidth->setValue(i);
}

stdIntSelector::stdIntSelector(QWidget * parent,QString label,int min,int max):QWidget(parent)
{
lblText=new QLabel(label,this);
spnInt=new QSpinBox(this);
spnInt->setRange(min,max);
layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(spnInt);
setLayout(layout);
}

int stdIntSelector::value(void)
{
return spnInt->value();
}

void stdIntSelector::setValue(int i)
{
spnInt->setValue(i);
}

stdLineEdit::stdLineEdit(QWidget * parent,QString label):QWidget(parent)
{
lblText=new QLabel(label,this);
lenText=new QLineEdit("0",this);
layout=new QHBoxLayout();
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(lenText);
setLayout(layout);
}

QString stdLineEdit::text(void)
{
return lenText->text();
}

void stdLineEdit::setText(QString text)
{
lenText->setText(text);
}

dirList::dirList(QWidget * parent,int type):QTreeView(parent)
{
listtype=type;

model = new QDirModel();

if (listtype==DIRLIST)
model->setFilter(QDir::AllDirs);
else
model->setFilter(QDir::Files | QDir::NoDotAndDotDot);

setModel(model);
setRootIndex(model->index(QDir::currentPath()));
}

FileSelector::FileSelector(QWidget * parent):QWidget(parent)
{
int number=3;
QString entr[3];
entr[0]=tr("Cwd");
entr[1]=tr("Home");
#ifdef MAC_SYSTEM
entr[2]=tr("/");
#endif
#ifdef LINUX_SYSTEM
entr[2]=tr("/");
#endif
#ifdef WINDOWS_SYSTEM
entr[2]=tr("C:\\");
onHighestLevel=false;
#endif
grpChDir=new QGroupBox(QString(""),this);
selChdir=new StdSelector(grpChDir,tr("Chdir to:"),number,entr);
cmdSetCwd=new QPushButton(tr("Set as cwd"),grpChDir);
chkShowHiddenFiles=new QCheckBox(tr("Show hidden files"),this);

lblFilter=new QLabel(tr("Filter:"),this);
lblDirs=new QLabel(tr("Directories:"),this);
lblFiles=new QLabel(tr("Files:"),this);
ledFilter=new QLineEdit("",this);
DirList=new QListView(this);
FileList=new QListView(this);
modelDirs=new QDirModel();
modelDirs->setFilter(QDir::AllDirs);
modelFiles=new QDirModel();
modelFiles->setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::Drives);
DirList->setModel(modelDirs);
FileList->setModel(modelFiles);

currentDir=QDir::currentPath();//Just for initialization

DirList->setRootIndex(modelDirs->index(currentDir));
FileList->setRootIndex(modelFiles->index(currentDir));
//cmdGoUp=new QPushButton(tr("GoUp"),this);
cmdGoUp=new QPushButton(qApp->style()->standardPixmap(QStyle::SP_FileDialogToParent),QString(""),this);
//cmdStdDialog=new QPushButton(tr("StdDialog"),this);
cmdStdDialog=new QPushButton(qApp->style()->standardPixmap(QStyle::SP_DirOpenIcon),QString(""),this);

connect(cmdGoUp,SIGNAL(clicked()),SLOT(doGoUp()));
connect(cmdStdDialog,SIGNAL(clicked()),SLOT(doStdDialog()));

connect(selChdir->cmbSelect,SIGNAL(currentIndexChanged(int)),SLOT(currentDirChanged(int)));
connect(FileList,SIGNAL(clicked(const QModelIndex &)),SLOT(FileSelected(const QModelIndex &)));
connect(FileList,SIGNAL(doubleClicked(const QModelIndex &)),SLOT(FileDoubleClicked(const QModelIndex &)));
connect(DirList,SIGNAL(clicked(const QModelIndex &)),SLOT(DirSelected(const QModelIndex &)));
connect(DirList,SIGNAL(doubleClicked(const QModelIndex &)),SLOT(DirDoubleClicked(const QModelIndex &)));
connect(ledFilter,SIGNAL(returnPressed()),SLOT(newFilterEntered()));
connect(chkShowHiddenFiles,SIGNAL(stateChanged(int)),SLOT(toggleHiddenFile(int)));
connect(cmdSetCwd,SIGNAL(clicked()),SLOT(doSetCWD()));

layout0=new QHBoxLayout;
layout0->setMargin(2);
layout0->addWidget(selChdir);
layout0->addWidget(cmdSetCwd);
grpChDir->setLayout(layout0);

layout=new QGridLayout();
layout->setMargin(2);
layout->addWidget(lblFilter,0,0,1,4);
layout->addWidget(ledFilter,1,0,1,4);
layout->addWidget(lblDirs,2,0);
layout->addWidget(cmdGoUp,2,1);
layout->addWidget(lblFiles,2,2,1,2);
layout->addWidget(DirList,3,0,1,2);
layout->addWidget(FileList,3,2,1,2);
layout->addWidget(chkShowHiddenFiles,4,0,1,2);
layout->addWidget(cmdStdDialog,4,2,1,2);
layout->addWidget(grpChDir,5,0,1,4);
setLayout(layout);
doubleclickdir=false;
doubleclickfile=false;

separator=QDir::separator();//QString("/");

filterExtension=QString("*.dat");
filter=currentDir+separator+filterExtension;
ledFilter->setText(filter);
}

void FileSelector::FileSelected(const QModelIndex & index )
{
if (doubleclickfile==true)
{
doubleclickfile=false;
return;
}
selectedFile=index.data().toString();
QString toEmit=QDir::cleanPath(currentDir+separator+selectedFile);
toEmit=QDir::toNativeSeparators(toEmit);
emit(newSelection(toEmit));
}

void FileSelector::FileDoubleClicked( const QModelIndex & index )
{
doubleclickfile=true;
selectedFile=index.data().toString();
QString toEmit=QDir::cleanPath(currentDir+separator+selectedFile);
toEmit=QDir::toNativeSeparators(toEmit);
emit(newSelectionDoubleClick(toEmit));
}

void FileSelector::DirSelected(const QModelIndex & index )
{
if (doubleclickdir==true)
{
doubleclickdir=false;
return;
}
selectedDir=index.data().toString();
//filter=currentDir+separator+selectedDir+separator+filterExtension;
QDir curDir(currentDir+separator+selectedDir);
QString newFilter,newDir;
GeneratePathWithExtension(curDir,newFilter,newDir);
filter=newFilter;
//ledFilter->setText(QDir::toNativeSeparators(filter));
ledFilter->setText(filter);
}

void FileSelector::DirDoubleClicked( const QModelIndex & index )
{
doubleclickdir=true;
selectedDir=index.data().toString();

currentDir=currentDir+separator+selectedDir;//set a new directory
QString newFilter,newDir;
GeneratePathWithExtension(currentDir,newFilter,newDir);

QDir d1(currentDir);
d1.makeAbsolute();
currentDir=d1.path();
filter=newFilter;
ledFilter->setText(filter);
/*filter=currentDir+separator+filterExtension;
filter=QDir::cleanPath(filter);
ledFilter->setText(QDir::toNativeSeparators(filter));*/
showFilesLikeFilter();
/*QString toEmit=QDir::cleanPath(currentDir+separator);
toEmit=QDir::toNativeSeparators(toEmit);*/
emit(newSelection(newDir));
newFilterEntered();
}

void FileSelector::showFilesLikeFilter(void)
{
QStringList filters;
filters << filterExtension;
modelDirs->setNameFilters(filters);
modelFiles->setNameFilters(filters);
DirList->setRootIndex(modelDirs->index(currentDir));
FileList->setRootIndex(modelFiles->index(currentDir));
}

void FileSelector::newFilterEntered(void)
{
///test for "exists"???
QString entered=ledFilter->text();
QDir d1(entered);
QChar last_char=entered.at(entered.length()-1);
#ifdef WINDOWS_SYSTEM
onHighestLevel=false;
#endif
if ( !entered.contains(QString("*")) && !entered.contains(QString("?")) && last_char==separator.at(0))
{
filterExtension=QString("*");
ledFilter->setText(QDir::toNativeSeparators(entered + filterExtension));
}
else
{
filterExtension=d1.dirName();
}
filter=entered;

int pos=entered.lastIndexOf(separator);
QString p=entered;
p.chop(entered.length()-pos);

QDir d2(p);
d2.makeAbsolute();
currentDir=d2.path();

showFilesLikeFilter();
}

void FileSelector::setFilterFromExtern(QString & directory,QString & extension)
{
currentDir=directory;
filterExtension=extension;
showFilesLikeFilter();
}

void FileSelector::doSetCWD(void)
{
char dummy[currentDir.length()];
strcpy(dummy,currentDir.toAscii());
set_workingdir(dummy);
}

void FileSelector::toggleHiddenFile(int i)
{
if (i==Qt::Checked)
{
modelDirs->setFilter(QDir::AllDirs | QDir::Hidden);
modelFiles->setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden);
}
else
{
modelDirs->setFilter(QDir::AllDirs);
modelFiles->setFilter(QDir::Files | QDir::NoDotAndDotDot);
}
showFilesLikeFilter();
}

void FileSelector::currentDirChanged(int i)
{
switch (i)
{
case 0://CWD
currentDir=QString(get_workingdir());
currentDir.chop(1);
break;
case 1://HOME
currentDir=QString(get_userhome());
currentDir.chop(1);
#ifdef WINDOWS_SYSTEM
onHighestLevel=true;
#endif
break;
case 2://'/'
#ifdef WINDOWS_SYSTEM
currentDir=QString("C:\\");
#else
currentDir=QString("");
#endif
break;
}
filter=currentDir+separator+filterExtension;
ledFilter->setText(QDir::toNativeSeparators(filter));
showFilesLikeFilter();
}

void FileSelector::GeneratePathWithExtension(QDir dir,QString & PathAndExtension,QString & DirectoryOnly)
{
QString str=dir.cleanPath(dir.absolutePath()).toAscii();
QString current;
if (str.startsWith("/.."))
{
    while (str.startsWith("/.."))
    {
    current=str.right(str.length()-3);
    str=current;
    }
}
else
{
current=dir.absolutePath();
}
#ifdef WINDOWS_SYSTEM
while (current.count(QString(":"))>1)
{
str=current;
current=str.right(str.length()-3);
}
if (current.contains(QString(":")))
{
current=current.mid(current.indexOf(QString(":"))-1);
}
onHighestLevel=false;
#endif
PathAndExtension=current+separator+filterExtension;
PathAndExtension=QDir::cleanPath(PathAndExtension);
PathAndExtension=QDir::toNativeSeparators(PathAndExtension);
DirectoryOnly=current+separator;
DirectoryOnly=QDir::cleanPath(DirectoryOnly);
DirectoryOnly=QDir::toNativeSeparators(DirectoryOnly);
}

void FileSelector::doGoUp(void)
{
QDir cdir(currentDir);
QDir tdir(cdir);
/*QString str2=currentDir;
char strbuf[512];
strcpy(strbuf,str2.toAscii());
if (strncmp(strbuf,"/..",3)==0)
{
char buf2[512];
strcpy(buf2,strbuf+3);
cout << "oh oh" << endl;
strcpy(strbuf,cdir.cleanPath(tdir.absolutePath()).toAscii());
cout << "buf=" << strbuf << endl;
tdir=QDir(buf2);
}
cout << "currentdir=#" << strbuf << "#" << endl;
QString toEmit;
str2.chop(1+cdir.dirName().length());
//currentDir=str2;
strcpy(strbuf,str2.toAscii());
cout << "updir1=#" << strbuf << "#" << endl;
*/
bool up_possible=tdir.cdUp();
/*strcpy(strbuf,tdir.path().toAscii());
cout << "updir2=#" << strbuf << "# possible=" << up_possible << endl;*/
#ifdef WINDOWS_SYSTEM
if (up_possible==false || onHighestLevel==true)
#else
if (up_possible==false)
#endif
{
#ifdef WINDOWS_SYSTEM
    currentDirChanged(1);
#endif
    return;
}
currentDir=tdir.absolutePath();
currentDir=QDir::cleanPath(currentDir);
QString newFilter,newPath;
GeneratePathWithExtension(tdir,newFilter,newPath);
filter=newFilter;
ledFilter->setText(newFilter);
emit(newSelection(newPath));
/*currentDir=tdir.absolutePath();
filter=currentDir+separator+filterExtension;
toEmit=QDir::cleanPath(filter);
toEmit=QDir::toNativeSeparators(toEmit);
ledFilter->setText(toEmit);
toEmit=QDir::cleanPath(currentDir+separator);
toEmit=QDir::toNativeSeparators(toEmit);
emit(newSelection(toEmit));*/
showFilesLikeFilter();
}

void FileSelector::doStdDialog(void)
{
QString s;
if (forRead==true)
s=QFileDialog::getOpenFileName(this,currentDir);
else
s=QFileDialog::getSaveFileName(this,currentDir);
if (!s.isNull())
{
/*lazy method of finding filename and directory*/
ledFilter->setText(QDir::toNativeSeparators(s));
newFilterEntered();
//set and announce new selection and filters
selectedFile=filter;
filterExtension=QString("*");
filter=currentDir+separator+filterExtension;
emit(newSelection(selectedFile));
//show selection again
///modify to do this only for existing files!!!
ledFilter->setText(QDir::toNativeSeparators(filter));
newFilterEntered();
QModelIndex index=modelFiles->index(selectedFile);
FileList->setCurrentIndex(index);
}
}

stdStartStop::stdStartStop(QWidget * parent):QWidget(parent)
{
lblStart=new QLabel(tr("Start load at:"),this);
lblStop=new QLabel(tr("Stop load at:"),this);
lblLength=new QLabel(tr("# of points:"),this);
ledStart=new QLineEdit(QString(""),this);
///ledStart->setValidator(new QDoubleValidator(this));
ledStop=new QLineEdit(QString(""),this);
//ledStop->setValidator(new QDoubleValidator(this));
ledLength=new QLineEdit(QString(""),this);
QIntValidator * intval=new QIntValidator(this);
intval->setBottom(1);
ledLength->setValidator(intval);
//ledLength->setValidator(new QRegExpValidator(rx, this));
error=false;//state indicating conversion errors
layout=new QHBoxLayout();
layout->setMargin(2);
layout->addWidget(lblStart);
layout->addWidget(ledStart);
layout->addWidget(lblStop);
layout->addWidget(ledStop);
layout->addWidget(lblLength);
layout->addWidget(ledLength);
setLayout(layout);
}

double stdStartStop::start(void)
{
double val;
error=false;
xv_evalexpr(ledStart, &val);
/*int len=ledStart->text().length();
if (len<=0)
{
error=true;
return 0.0;
}
char dummy[ledStart->text().length()];
strcpy(dummy,ledStart->text().toAscii());
return atof(dummy);*/
return val;
}

double stdStartStop::stop(void)
{
double val;
error=false;
xv_evalexpr(ledStop, &val);
/*int len=ledStop->text().length();
if (len<=0)
{
error=true;
return 0.0;
}
char dummy[ledStop->text().length()];
strcpy(dummy,ledStop->text().toAscii());
return atof(dummy);*/
return val;
}

int stdStartStop::length(void)
{
int val;
error=false;
xv_evalexpri(ledLength,&val);
/*int len=ledLength->text().length();
if (len<=0)
{
error=true;
return 0.0;
}
char dummy[ledLength->text().length()];
strcpy(dummy,ledLength->text().toAscii());
return atoi(dummy);*/
return val;
}

stdSetTypeSelector::stdSetTypeSelector(QWidget * parent):StdSelector(parent)
{
lblText=new QLabel("Type:");
cmbSelect=new QComboBox();
number_of_entries=column_count=2;
entries=new QString[column_count];
entryValues=new int[column_count];
entries[1]=QString("");
entries[0]=QString("");
entryValues[0]=0;
entryValues[1]=1;
cmbSelect->addItem(entries[0]);
cmbSelect->addItem(entries[1]);

layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(lblText);
layout->addWidget(cmbSelect);
setLayout(layout);
showAll=false;
setColumnCount(column_count);
}

void stdSetTypeSelector::setColumnCount(int count)
{
if (showAll==false)
column_count=count;
char dummy[512];
///SET APPROPRIATE SET_TYPE_CHOICES ACCORDING TO NUMBER OF COLUMNS --> SHOW ONLY AVAILABLE CHOICES, I DON'T KNOW HOW TO DISABLE CHOICES
int number_of_Type_entries=0;
for (int i=0;i<NUMBER_OF_SETTYPES;i++)
if (settype_cols(i) == count || showAll==true) number_of_Type_entries++;
int * Type_entries=new int[number_of_Type_entries];
QString * entr=new QString[number_of_Type_entries];
number_of_Type_entries=0;
for (int i=0;i<NUMBER_OF_SETTYPES;i++)
{
	if (settype_cols(i) == count || showAll==true)
	{
	strToUpper(dummy,set_types(i));
	entr[number_of_Type_entries]=QString(dummy);
	Type_entries[number_of_Type_entries]=i;
	number_of_Type_entries++;
	}
}
setNewEntries(number_of_Type_entries,entr,Type_entries);
}

void stdSetTypeSelector::setShowAll(bool sa)
{
showAll=sa;
setColumnCount(column_count);
}

int stdSetTypeSelector::getColumnCount(void)
{
return settype_cols(currentValue());
}

/* Wrappers */

int GetSpinChoice(stdIntSelector * s)
{
return s->value();
}
    
double GetSpinChoice(LineWidthSelector * s)
{
return s->value();
}

double GetSpinChoice(QDoubleSpinBox * s)	
{
return s->value();
}
	
bool GetToggleButtonState(QCheckBox * c)
{
return c->isChecked();
}

int GetChoice(StdSelector * s)
{
return s->currentValue();
}

int GetChoice(PositionSelector * s)
{
return s->currentIndex();
}

int GetOptionChoice(ColorSelector * s)
{
return s->currentIndex();
}

int GetOptionChoice(LineStyleSelector * s)
{
return s->currentIndex();
}

int GetOptionChoice(FillPatternSelector * s)
{
return s->currentIndex();
}

int GetOptionChoice(JustificationSelector * s)
{
return s->currentIndex();
}

int GetOptionChoice(FontSelector * s)
{
return s->currentIndex();
}

int GetOptionChoice(QComboBox * c)
{
return c->currentIndex();
}

int GetOptionChoice(StdSelector * sel)
{
return sel->currentValue();
}

double GetCharSizeChoice(stdSlider * sel)
{
return sel->value();
}

double GetAngleChoice(stdSlider * sel)
{
return sel->value();
}

char * GetTextString(stdLineEdit * led)
{
static char dummy[256];
strcpy(dummy,led->lenText->text().toAscii());
return dummy;
}

void SetToggleButtonState(QCheckBox * cb, int v)
{
cb->setChecked(bool(v));
}

bool GetToggleButtonState(QAction * c)
{
return c->isChecked();
}

void SetChoice(StdSelector * sel,int v)
{
sel->setCurrentValue(v);
}

void SetOptionChoice(ColorSelector * sel,int v)
{
sel->setCurrentIndex(v);
}

void SetOptionChoice(LineStyleSelector * sel,int v)
{
sel->setCurrentIndex(v);
}

void SetOptionChoice(FillPatternSelector * sel,int v)
{
sel->setCurrentIndex(v);
}

void SetOptionChoice(FontSelector * sel,int v)
{
sel->setCurrentIndex(v);
}

void SetOptionChoice(JustificationSelector * sel,int v)
{
sel->setCurrentIndex(v);
}

void SetOptionChoice(StdSelector * sel,int v)
{
sel->setCurrentValue(v);
}

void SetSpinChoice(stdIntSelector * sel, double v)
{
sel->setValue((int)v);
}

void SetSpinChoice(LineWidthSelector * sel, double v)
{
sel->setValue((int)v);
}

void SetChoice(PositionSelector * sel,int v)
{
sel->setCurrentIndex(v);
}

void SetScaleValue(stdSlider * sel, int v)
{
sel->setValue(v);
}

void SetCharSizeChoice(stdSlider * sel,double v)
{
sel->setValue(int(v));
}

void SetAngleChoice(stdSlider * sel,double v)
{
sel->setValue((int)v);
}

void SetTextString(stdLineEdit * led,char * st)
{
led->setText(st);
}

void SetLabel(QLabel * lab,char * st)
{
lab->setText(QString(st));
}

void xv_setstr(stdLineEdit * led, char * text)
{
led->setText(QString(text));
}

void xv_setstr(QLineEdit * led, char * text)
{
led->setText(QString(text));
}

void SetSensitive(stdLineEdit * led, bool e)
{
led->setEnabled(e);
}

void SetSensitive(QLineEdit * led, bool e)
{
led->setEnabled(e);
}

void SetSensitive(StdSelector * led, bool e)
{
led->setEnabled(e);
}

void SetSensitive(QPushButton * led, bool e)
{
led->setEnabled(e);
}

void SetSensitive(QCheckBox * led, bool e)
{
led->setEnabled(e);
}

int GetScaleValue(stdSlider * sel)
{
return sel->value();
}

char * xv_getstr(stdLineEdit * led)
{
    ///WARNING POSSIBLY UNSAVE PROCEDURE!!!
static char value[1024];
strcpy(value,led->lenText->text().toAscii());
return value;
}

char * xv_getstr(QLineEdit * led)
{
    ///WARNING POSSIBLY UNSAVE PROCEDURE!!!
static char value[1024];
strcpy(value,led->text().toAscii());
return value;
}

int xv_evalexpr(stdLineEdit * w, double * answer )
{
return xv_evalexpr(w->lenText,answer);
}

int xv_evalexpri(stdLineEdit * w,int * answer)
{
return xv_evalexpri(w->lenText,answer);
}

/*
 * xv_evalexpr - take a text field and pass it to the parser if it needs to
 * evaluated, else use atof().
 * place the double result in answer
 * if an error, return False, else True
 */
int xv_evalexpr(QLineEdit * w,double * answer)
{
    static char *buf = NULL;
    int i, len, ier = 0;
    double result;
    QString st=w->text();
    buf=new char[st.length()+1];
    strcpy(buf,st.toAscii());

    if (!(len = strlen( buf ) )) { /* check for zero length */
        *answer = 0;
        delete[] buf;
        return RETURN_FAILURE;
    }
    /* first character may be a sign */
    if (!fpdigit[(int) buf[0]] && buf[0] != '-' && buf[0] != '+') {
        i = len +1;
    } else {
        i = 1;
    }

    for (; i<len; i++) {
        if (!fpdigit[(int) buf[i]]) {
            break;
        }
    }

    if (i == len) {         /* only floating point digits */
        *answer = atof( buf );
        delete[] buf;
        return RETURN_SUCCESS;
    } else {                /* must evaluate an expression */
        ier = s_scanner(buf, &result);
        if( !ier ) {
            *answer = result;
            delete[] buf;
            return RETURN_SUCCESS;
        } else {
            *answer = 0;
            delete[] buf;
            return RETURN_FAILURE;
        }
    }
}

/*
 * xv_evalexpri - take a text field and pass it to the parser if it needs to
 * evaluated, else use atoi().
 * place the integer result in answer
 * if an error, return False, else True
 */
int xv_evalexpri(QLineEdit * w,int * answer)
{
    static char *buf = NULL;
    int i, len, ier = 0;
    double result;
    QString st=w->text();
    buf=new char[st.length()+1];
    strcpy(buf,st.toAscii());

    if (!(len = strlen( buf ) )) { /* check for zero length */
        *answer = 0;
        return RETURN_FAILURE;
    }
    /* first character may be a sign */
    if (!fpdigit[(int) buf[0]] && buf[0] != '-' && buf[0] != '+') {
        i = len +1;
    } else {
        i = 1;
    }

    for (; i<len; i++) {
        if (!fpdigit[(int) buf[i]]) {
            break;
        }
    }

    if (i == len) {             /* only floating point digits */
        *answer = atoi(buf);
        return RETURN_SUCCESS;
    } else {                    /* must evaluate an expression */
        ier = s_scanner(buf, &result);
        if( !ier ) {
            *answer = (int)result;
            return RETURN_SUCCESS;
        } else {
            *answer = 0;
            return RETURN_FAILURE;
        }
    }
}

void SelectListChoice(uniList * list,int nr)
{
int count=1;
int selection[2]={nr,1};
list->set_new_selection(count,selection);
}

void SelectListChoices(uniList * list,int count,int * nrs)
{
list->set_new_selection(count,nrs);
}

int GetListChoices(uniList * list, int ** sel)
{
int nr;
list->get_selection(&nr,sel);
return nr;
}

int GetSelectedSets(uniList * list, int ** sel)
{
int nr;
list->get_selection(&nr,sel);
return nr;
}

int GetSelectedSet(uniList * list)
{
    int nr,*sel=new int[3];
    list->get_selection(&nr,&sel);
    if (nr>0)
    nr=sel[0];
    else
    nr=SET_SELECT_ERROR;
    delete[] sel;
return nr;
}

int GetSingleListChoice(uniList * list, int * sel)
{
int nr;
int * selection=new int[5];
list->get_selection(&nr,&selection);
if (nr<=0)
{
delete[] selection;
return RETURN_FAILURE;
}
else
{
*sel=selection[0];
delete[] selection;
return RETURN_SUCCESS;
}
}

GraphPopup::GraphPopup(uniList *parent):QMenu(parent)
{
par=parent;
CreateActions();
setTearOffEnabled(FALSE);

//Create Menu itself
addAction(actLabel);
addSeparator();
addAction(actFocusTo);
addAction(actHide);
addAction(actShow);
addAction(actDuplicate);
addAction(actKill);
addSeparator();
addAction(actCopy12);
addAction(actCopy21);
addAction(actMove12);
addAction(actMove21);
addAction(actSwap);
addSeparator();
addAction(actCreateNew);

number_of_selected_graphs=0;
selected_graphs=new int[2];
}

GraphPopup::~GraphPopup()
{
delete[] selected_graphs;
}

void GraphPopup::CreateActions(void)
{
actLabel=new QAction(tr("G0"),this);
connect(actLabel,SIGNAL(triggered()), this, SLOT(doNothing()));
actFocusTo=new QAction(tr("&Focus to"),this);
connect(actFocusTo,SIGNAL(triggered()), this, SLOT(doFocusTo()));
actShow=new QAction(tr("&Show"),this);
connect(actShow,SIGNAL(triggered()), this, SLOT(doShow()));
actHide=new QAction(tr("&Hide"),this);
connect(actHide,SIGNAL(triggered()), this, SLOT(doHide()));
actDuplicate=new QAction(tr("&Duplicate"),this);
connect(actDuplicate,SIGNAL(triggered()), this, SLOT(doDuplicate()));
actKill=new QAction(tr("&Kill"),this);
connect(actKill,SIGNAL(triggered()), this, SLOT(doKill()));
actCopy12=new QAction(tr("Copy G0 to G1"),this);
connect(actCopy12,SIGNAL(triggered()), this, SLOT(doCopy12()));
actCopy21=new QAction(tr("Copy G1 to G0"),this);
connect(actCopy21,SIGNAL(triggered()), this, SLOT(doCopy21()));
actMove12=new QAction(tr("Move G0 to G1"),this);
connect(actMove12,SIGNAL(triggered()), this, SLOT(doMove12()));
actMove21=new QAction(tr("Move G1 to G0"),this);
connect(actMove21,SIGNAL(triggered()), this, SLOT(doMove21()));
actSwap=new QAction(tr("S&wap"),this);
connect(actSwap,SIGNAL(triggered()), this, SLOT(doSwap()));
actCreateNew=new QAction(tr("&Create new"),this);
connect(actCreateNew,SIGNAL(triggered()), this, SLOT(doCreateNew()));
}

void GraphPopup::doNothing(void)
{
;
}

void GraphPopup::doFocusTo(void)
{
switch_current_graph(selected_no);
update();
}

void GraphPopup::doShow(void)
{
ShowHideGraphs(number_of_selected_graphs,selected_graphs);
for (int i = 0; i < number_of_selected_graphs; i++)
set_graph_hidden(selected_graphs[i], FALSE);
update();
}

void GraphPopup::doHide(void)
{
ShowHideGraphs(number_of_selected_graphs,selected_graphs);
for (int i = 0; i < number_of_selected_graphs; i++)
set_graph_hidden(selected_graphs[i], TRUE);
update();
}

void GraphPopup::doDuplicate(void)
{
int * gnos=new int[number_of_selected_graphs+2];
int index=0;
for (int i = 0; i < number_of_selected_graphs; i++)
{
duplicate_graph(selected_graphs[i]);
    if (new_set_no!=-1)
    gnos[index++]=new_set_no;
}
GraphsCreated(index,gnos,UNDO_COMPLETE);
delete[] gnos;
update();
}

void GraphPopup::doKill(void)
{
if (yesno("Kill selected graph(s)?", NULL, NULL, NULL))
{
    int * graphs=new int[number_of_selected_graphs];
    for (int i = number_of_selected_graphs - 1; i >= 0; i--)
    graphs[(number_of_selected_graphs - 1)-i]=selected_graphs[i];
GraphsDeleted(number_of_selected_graphs,graphs,false);
    delete[] graphs;
    for (int i = number_of_selected_graphs - 1; i >= 0; i--)
    {
    kill_graph(selected_graphs[i]);
    }
}
update();
}

void GraphPopup::doSwap(void)
{
UndoSwapGraphs(selected_graphs[0], selected_graphs[1]);
swap_graph(selected_graphs[0], selected_graphs[1]);
}

void GraphPopup::doCreateNew(void)
{
int * gnos=new int[2];
gnos[1]=gnos[0]=number_of_graphs();
set_graph_active(number_of_graphs());
GraphsCreated(1,gnos,UNDO_COMPLETE);
delete[] gnos;
update();
}

void GraphPopup::update(void)
{
par->update_number_of_entries_preserve_selection();
mainWin->mainArea->completeRedraw();
}

void GraphPopup::doMove12(void)
{
char buf[32];
    if (number_of_selected_graphs==2)
    {
    sprintf(buf, "Replace G%d?", selected_graphs[1]);
        if (yesno(buf, NULL, NULL, NULL))
        {
            SaveGraphStatesPrevious(number_of_selected_graphs,selected_graphs,UNDO_COMPLETE);
        move_graph(selected_graphs[0], selected_graphs[1]);
            selected_graphs[0]=selected_graphs[1];
            GraphsModified(1,selected_graphs,UNDO_COMPLETE);
        }
    update();
    }
}

void GraphPopup::doMove21(void)
{
char buf[32];
    if (number_of_selected_graphs==2)
    {
    sprintf(buf, "Replace G%d?", selected_graphs[0]);
        if (yesno(buf, NULL, NULL, NULL))
        {
            SaveGraphStatesPrevious(number_of_selected_graphs,selected_graphs,UNDO_COMPLETE);
        move_graph(selected_graphs[1], selected_graphs[0]);
            GraphsModified(1,selected_graphs,UNDO_COMPLETE);
        }
    update();
    }
}

void GraphPopup::doCopy12(void)
{
char buf[32];
    if (number_of_selected_graphs == 2)
    {
    sprintf(buf, "Overwrite G%d?", selected_graphs[1]);
        if (yesno(buf, NULL, NULL, NULL))
        {
            SaveGraphStatesPrevious(number_of_selected_graphs,selected_graphs,UNDO_COMPLETE);
        copy_graph(selected_graphs[0], selected_graphs[1]);
            GraphsModified(number_of_selected_graphs,selected_graphs,UNDO_COMPLETE);
        }
    update();
    }
}

void GraphPopup::doCopy21(void)
{
char buf[32];
    if (number_of_selected_graphs == 2)
    {
    sprintf(buf, "Overwrite G%d?", selected_graphs[0]);
        if (yesno(buf, NULL, NULL, NULL))
        {
            SaveGraphStatesPrevious(number_of_selected_graphs,selected_graphs,UNDO_COMPLETE);
        copy_graph(selected_graphs[1], selected_graphs[0]);
            GraphsModified(number_of_selected_graphs,selected_graphs,UNDO_COMPLETE);
        }
    update();
    }
}

void GraphPopup::update_menu_content(void)
{
char dummy[64],dummy2[64];
sprintf(dummy,"G");
for (int i=0;i<number_of_selected_graphs;i++)
{
sprintf(dummy2,"%d",selected_graphs[i]);
strcat(dummy,dummy2);
        if (i>2 && i!=number_of_selected_graphs-1)
        {
        strcat(dummy,",...");
        break;
        }
        else
        {
        if (i!=number_of_selected_graphs-1)
        strcat(dummy,", G");
        }
}
actLabel->setText(QString(dummy));
    if (number_of_selected_graphs==1)
    {
    actCopy12->setVisible(false);
    actCopy21->setVisible(false);
    actMove12->setVisible(false);
    actMove21->setVisible(false);
    actSwap->setEnabled(false);
    actFocusTo->setEnabled(true);
    }
    else
    {
        if (number_of_selected_graphs==2)
        {
        sprintf(dummy,"Copy G%d to G%d",selected_graphs[0],selected_graphs[1]);
        actCopy12->setText(QString(dummy));
        actCopy12->setVisible(true);
        sprintf(dummy,"Copy G%d to G%d",selected_graphs[1],selected_graphs[0]);
        actCopy21->setText(QString(dummy));
        actCopy21->setVisible(true);
        sprintf(dummy,"Move G%d to G%d",selected_graphs[0],selected_graphs[1]);
        actMove12->setText(QString(dummy));
        actMove12->setVisible(true);
        sprintf(dummy,"Move G%d to G%d",selected_graphs[1],selected_graphs[0]);
        actMove21->setText(QString(dummy));
        actMove21->setVisible(true);
        actSwap->setEnabled(true);
        }
        else
        {
        actCopy12->setVisible(false);
        actCopy21->setVisible(false);
        actMove12->setVisible(false);
        actMove21->setVisible(false);
        actSwap->setEnabled(false);
        }
    actFocusTo->setEnabled(false);
    }
}

SetPopup::SetPopup(uniList *parent):QMenu(parent)
{
par=parent;
CreateActions();
setTearOffEnabled(FALSE);

//Create Menu itself
addAction(actLabel);
addSeparator();
addAction(actHide);
addAction(actShow);
addAction(actBringToFront);
addAction(actSendToBack);
addSeparator();
addAction(actDuplicate);
addAction(actKill);
addAction(actKillData);
addSeparator();
addAction(actCopy12);
addAction(actCopy21);
addAction(actMove12);
addAction(actMove21);
addAction(actSwap);
addSeparator();
mnuEdit=new QMenu(tr("&Edit"),this);
mnuEdit->setTearOffEnabled(FALSE);
mnuEdit->addAction(actEditInSpreadsheet);
mnuEdit->addAction(actEditInTextEditor);
mnuCreateNew=new QMenu(tr("Create new"),this);
mnuCreateNew->setTearOffEnabled(FALSE);
mnuCreateNew->addAction(actCreateByFormula);
mnuCreateNew->addAction(actCreateInSpreadsheet);
mnuCreateNew->addAction(actCreateInTextEditor);
mnuCreateNew->addAction(actCreateFromBlockData);
addMenu(mnuEdit);
addMenu(mnuCreateNew);
addSeparator();
addAction(actPackAllSets);
addSeparator();
mnuSelectorOperations=new QMenu(tr("Select&or operations"),this);
mnuSelectorOperations->setTearOffEnabled(FALSE);
mnuSelectorOperations->addAction(actViewSetComments);
actViewSetComments->setCheckable(true);
actViewSetComments->setChecked(FALSE);
mnuSelectorOperations->addAction(actShowDataLess);
actShowDataLess->setCheckable(true);
actShowDataLess->setChecked(FALSE);
mnuSelectorOperations->addAction(actShowHidden);
actShowHidden->setCheckable(true);
actShowHidden->setChecked(TRUE);
mnuSelectorOperations->addSeparator();
mnuSelectorOperations->addAction(actSelectAll);
mnuSelectorOperations->addAction(actUnselectAll);
mnuSelectorOperations->addAction(actInvertSelection);
mnuSelectorOperations->addSeparator();
mnuSelectorOperations->addAction(actUpdate);
addMenu(mnuSelectorOperations);

number_of_selected_sets=0;
selected_sets=new int[2];
}

SetPopup::~SetPopup()
{
delete[] selected_sets;
}

void SetPopup::CreateActions(void)
{
actLabel=new QAction(tr("S0"),this);
connect(actLabel,SIGNAL(triggered()), this, SLOT(doNothing()));
actHide=new QAction(tr("Hide"),this);
connect(actHide,SIGNAL(triggered()), this,SLOT(doHide()));
actBringToFront=new QAction(tr("BringToFront"),this);
connect(actBringToFront,SIGNAL(triggered()), this,SLOT(doBringToFront()));
actSendToBack=new QAction(tr("Send to back"),this);
connect(actSendToBack,SIGNAL(triggered()), this,SLOT(doSendToBack()));
actPackAllSets=new QAction(tr("Pack All sets"),this);
connect(actPackAllSets,SIGNAL(triggered()), this,SLOT(doPackAllSets()));
actShow=new QAction(tr("Show"),this);
connect(actShow,SIGNAL(triggered()), this,SLOT(doShow()));
actDuplicate=new QAction(tr("Duplicate"),this);
connect(actDuplicate,SIGNAL(triggered()), this,SLOT(doDuplicate()));
actKill=new QAction(tr("Kill"),this);
connect(actKill,SIGNAL(triggered()), this,SLOT(doKill()));
actKillData=new QAction(tr("Kill data"),this);
connect(actKillData,SIGNAL(triggered()), this,SLOT(doKillData()));
actCopy12=new QAction(tr("Copy S0 to S1"),this);
connect(actCopy12,SIGNAL(triggered()), this,SLOT(doCopy12()));
actCopy21=new QAction(tr("Copy S1 to S0"),this);
connect(actCopy21,SIGNAL(triggered()), this,SLOT(doCopy21()));
actMove12=new QAction(tr("Move S0 to S1"),this);
connect(actMove12,SIGNAL(triggered()), this,SLOT(doMove12()));
actMove21=new QAction(tr("Move S1 to S0"),this);
connect(actMove21,SIGNAL(triggered()), this,SLOT(doMove21()));
actSwap=new QAction(tr("Swap"),this);
connect(actSwap,SIGNAL(triggered()), this,SLOT(doSwap()));
actCreateByFormula=new QAction(tr("By formula"),this);
connect(actCreateByFormula,SIGNAL(triggered()), this,SLOT(doCreateByFormula()));
actCreateInSpreadsheet=new QAction(tr("In spreadsheet"),this);
connect(actCreateInSpreadsheet,SIGNAL(triggered()), this,SLOT(doCreateInSpreadsheet()));
actCreateInTextEditor=new QAction(tr("In text Editor"),this);
connect(actCreateInTextEditor,SIGNAL(triggered()), this,SLOT(doCreateInTextEditor()));
actCreateFromBlockData=new QAction(tr("From block data"),this);
connect(actCreateFromBlockData,SIGNAL(triggered()), this,SLOT(doCreateFromBlockData()));
actEditInSpreadsheet=new QAction(tr("In spreadsheet"),this);
connect(actEditInSpreadsheet,SIGNAL(triggered()), this,SLOT(doEditInSpreadSheet()));
actEditInTextEditor=new QAction(tr("In text editor"),this);
connect(actEditInTextEditor,SIGNAL(triggered()), this,SLOT(doEditInTextEditor()));
actViewSetComments=new QAction(tr("View set comments"),this);
connect(actViewSetComments,SIGNAL(triggered()), this,SLOT(doViewSetComments()));
actShowDataLess=new QAction(tr("Show data-less"),this);
connect(actShowDataLess,SIGNAL(triggered()), this,SLOT(doShowDataLess()));
actShowHidden=new QAction(tr("Show hidden"),this);
connect(actShowHidden,SIGNAL(triggered()), this,SLOT(doShowHidden()));
actSelectAll=new QAction(tr("Select all"),this);
connect(actSelectAll,SIGNAL(triggered()), this,SLOT(doSelectAll()));
actUnselectAll=new QAction(tr("Unselect all"),this);
connect(actUnselectAll,SIGNAL(triggered()), this,SLOT(doUnSelectAll()));
actInvertSelection=new QAction(tr("Invert selection"),this);
connect(actInvertSelection,SIGNAL(triggered()), this,SLOT(doInvertSelection()));
actUpdate=new QAction(tr("Update"),this);
connect(actUpdate,SIGNAL(triggered()), this,SLOT(doUpdate()));
}

void SetPopup::prepareForAction(void)
{
selected_graph=par->gr_no;
par->get_selection(&number_of_selected_sets,&selected_sets);
}

void SetPopup::finishAction(int preserveSelection)
{
par->update_number_of_entries();
mainWin->mainArea->completeRedraw();
if (preserveSelection==DO_PRESERVE_SELECTION)
par->set_new_selection(number_of_selected_sets,selected_sets);
}

void SetPopup::doNothing(void)
{
;
}

void SetPopup::doHide(void)
{
prepareForAction();
int * gnos=new int[number_of_selected_sets];
int * snos=new int[number_of_selected_sets];
for (int i=0;i<number_of_selected_sets;i++)
{
gnos[i]=selected_graph;
snos[i]=selected_sets[i];
set_set_hidden(selected_graph, selected_sets[i], TRUE);
}
///Undo-Stuff
ShowHideSets(number_of_selected_sets,gnos,snos);
delete[] gnos;
delete[] snos;
finishAction(DO_PRESERVE_SELECTION);
}

void SetPopup::doShow(void)
{
prepareForAction();
int * gnos=new int[number_of_selected_sets];
int * snos=new int[number_of_selected_sets];
for (int i=0;i<number_of_selected_sets;i++)
{
gnos[i]=selected_graph;
snos[i]=selected_sets[i];
set_set_hidden(selected_graph, selected_sets[i], FALSE);
}
///Undo-Stuff
ShowHideSets(number_of_selected_sets,gnos,snos);
delete[] gnos;
delete[] snos;
finishAction(DO_PRESERVE_SELECTION);
}

void SetPopup::doSendToBack(void)
{
int number;
int * selection=new int[2];
int gno=par->gr_no;
par->get_selection(&number,&selection);
if (number==1)
{
ChangeSetOrdering(gno,selection[0],PUSH_SET_TOBACK);
pushset(gno, selection[0], PUSH_SET_TOBACK);
}
delete[] selection;
par->update_number_of_entries();
mainWin->mainArea->completeRedraw();
}

void SetPopup::doBringToFront(void)
{
int number;
int * selection=new int[2];
int gno=par->gr_no;
par->get_selection(&number,&selection);
if (number==1)
{
ChangeSetOrdering(gno,selection[0],PUSH_SET_TOFRONT);
pushset(gno, selection[0], PUSH_SET_TOFRONT);
}
delete[] selection;
par->update_number_of_entries();
mainWin->mainArea->completeRedraw();
}

void SetPopup::doDuplicate(void)
{
int number;
int * selection=new int[2];
int gno=par->gr_no;
int setno;
int index=0;
par->get_selection(&number,&selection);
int * gnos=new int[number+2];
int * snos=new int[number+2];
    for (int i=0;i<number;i++)
    {
    setno = nextset(gno);
    do_copyset(gno, selection[i], gno, setno);
    gnos[index]=gno;
    snos[index++]=setno;
    }
SetsCreated(index,gnos,snos,UNDO_COMPLETE);
delete[] selection;
delete[] gnos;
delete[] snos;
par->update_number_of_entries_preserve_selection();
mainWin->mainArea->completeRedraw();
}

void SetPopup::doKill(void)
{
prepareForAction();
if (yesno("Kill selected set(s)?", NULL, NULL, NULL))
{
    int * gnos=new int[number_of_selected_sets];
    for (int i=0;i<number_of_selected_sets;i++)
    gnos[i]=selected_graph;
    SetsDeleted(number_of_selected_sets,gnos,selected_sets,UNDO_COMPLETE);//UndoStuff
    delete[] gnos;
	for (int i=0;i<number_of_selected_sets;i++)
	{
	killset(selected_graph, selected_sets[i]);
	}
finishAction(DO_NOT_PRESERVE_SELECTION);
}
else
finishAction(DO_PRESERVE_SELECTION);
}

void SetPopup::doKillData(void)
{
prepareForAction();
if (yesno("Kill data in selected set(s)?", NULL, NULL, NULL))
{
    int * gnos=new int[number_of_selected_sets];
    for (int i=0;i<number_of_selected_sets;i++)
    gnos[i]=selected_graph;
    SetsDeleted(number_of_selected_sets,gnos,selected_sets,UNDO_COMPLETE);//UndoStuff
    char dummy[128];
    sprintf(dummy,"[G%d.S%d]",gnos[0],selected_sets[0]);
    if (number_of_selected_sets>1)
    {
    addAditionalDescriptionToLastNode(-1,QObject::tr("Kill set data"),QString(),-1);
    }
    else
    {
    addAditionalDescriptionToLastNode(-1,QObject::tr("Kill set data")+QString(dummy),QString(),-1);
    }
    delete[] gnos;
	for (int i=0;i<number_of_selected_sets;i++)
	{
	killsetdata(selected_graph, selected_sets[i]);
	}
finishAction(DO_NOT_PRESERVE_SELECTION);
}
else
finishAction(DO_PRESERVE_SELECTION);
}

void SetPopup::doSwap(void)
{
int number;
int * selection=new int[2];
int gno=par->gr_no;
par->get_selection(&number,&selection);
if (number==2)
{
swapset(gno, selection[0], gno, selection[1]);
UndoSwapSets(gno, selection[0], gno, selection[1]);
}
delete[] selection;
par->update_number_of_entries();
mainWin->mainArea->completeRedraw();
}

void SetPopup::doPackAllSets(void)
{
int gno=par->gr_no;
SetsAboutToBePacked(gno);
packsets(gno);
par->update_number_of_entries();
mainWin->mainArea->completeRedraw();
}

void SetPopup::doEditInSpreadSheet(void)
{
int gno=par->gr_no;
int number;
int * selection=new int[5];
par->get_selection(&number,&selection);
for (int i=0;i<number;i++)
{
showSetInSpreadSheet(gno,selection[i]);
}
delete[] selection;
}

void SetPopup::doEditInTextEditor(void)
{
int gno=this->selected_graph;
int setno=-1;
if (this->number_of_selected_sets>0)
{
setno=this->selected_sets[0];
}
if (setno!= -1)
{
setcomment(gno, setno, "Editor");
set_set_hidden(gno, setno, FALSE);
if (FormSetEditor==NULL)
{
FormSetEditor=new frmSetEditor(0);
}
FormSetEditor->init(gno,setno);
FormSetEditor->show();
FormSetEditor->raise();
FormSetEditor->activateWindow();
///FormSetEditor->setModal(true);
}
}

void SetPopup::doCreateByFormula(void)
{
if (FormLoadAndEvaluate==NULL)
{
FormLoadAndEvaluate=new frmLoadEval(0);
}
FormLoadAndEvaluate->show();
FormLoadAndEvaluate->raise();
FormLoadAndEvaluate->activateWindow();
}

void SetPopup::doCreateInSpreadsheet(void)
{
    int setno,gno=selected_graph;
    if ((setno = nextset(gno)) != -1) {
    setcomment(gno, setno, "Editor");
    set_set_hidden(gno, setno, FALSE);
    //create_ss_frame(gno, setno);
    showSetInSpreadSheet(gno,setno);
    } else {
    ;///cout << "error" << endl;
    }
}

void SetPopup::doCreateInTextEditor(void)
{
int gno=this->selected_graph;
int setno;
if ((setno = nextset(gno)) != -1)
{
setcomment(gno, setno, "Editor");
set_set_hidden(gno, setno, FALSE);
    if (FormSetEditor==NULL)
    {
    FormSetEditor=new frmSetEditor(0);
    }
    FormSetEditor->init(gno,setno);
    FormSetEditor->show();
    FormSetEditor->raise();
    FormSetEditor->activateWindow();
///FormSetEditor->setModal(true);
}
}

void SetPopup::doCreateFromBlockData(void)
{
    if (FormEditBlockData==NULL)
    {
    FormEditBlockData=new frmEditBlockData(mainWin);
    }
    FormEditBlockData->init();
    int blockncols = get_blockncols();
    if (!blockncols)
    FormEditBlockData->hide();
    else
    {
    FormEditBlockData->show();
    FormEditBlockData->raise();
    FormEditBlockData->activateWindow();
    }
}

void SetPopup::doSelectAll(void)
{
par->selectAll();
}

void SetPopup::doUnSelectAll(void)
{
par->clearSelection();
}

void SetPopup::doUpdate(void)
{
par->update_number_of_entries_preserve_selection();
}

void SetPopup::doInvertSelection(void)
{
int number=par->count()-number_of_selected_sets;
int * n_selected_sets=new int[number];
int index=0;
bool in_list;
for (int i=0;i<par->count();i++)
{
in_list=false;
	for (int j=0;j<number_of_selected_sets;j++)
	if (selected_sets[j]==i)
	{
	in_list=true;
	break;
	}
		if (in_list==false)
		{
		n_selected_sets[index]=i;
		index++;
		}
}
par->set_new_selection(number,n_selected_sets);
delete[] n_selected_sets;
}

void SetPopup::doShowHidden(void)
{
par->show_hidden=!par->show_hidden;
par->update_number_of_entries_preserve_selection();
}

void SetPopup::doShowDataLess(void)
{
par->show_data_less=!par->show_data_less;
par->update_number_of_entries_preserve_selection();
}

void SetPopup::doViewSetComments(void)
{
par->show_comments=!par->show_comments;
par->update_number_of_entries_preserve_selection();
}

void SetPopup::doMove12(void)
{
if (number_of_selected_sets==2)
{
    int gno=par->gr_no;
    int * gnos=new int[2];
    gnos[0]=gnos[1]=gno;
    char dummy[64];
    sprintf(dummy, "Replace S%d?", selected_sets[1]);
    if (yesno(dummy, NULL, NULL, NULL))
    {
        SaveSetStatesPrevious(2,gnos,selected_sets,UNDO_COMPLETE);
    moveset(gno, selected_sets[0], gno, selected_sets[1]);
        SetsModified(1,gnos,selected_sets+1,UNDO_COMPLETE);
        sprintf(dummy,"Move [G%d.S%d]-->[G%d.S%d]",gno, selected_sets[0], gno, selected_sets[1]);
        addAditionalDescriptionToLastNode(-1,QString(dummy),QString(),0);
    }
    delete[] gnos;
    finishAction(DO_PRESERVE_SELECTION);
}
}

void SetPopup::doMove21(void)
{
if (number_of_selected_sets==2)
{
    int gno=par->gr_no;
    int * gnos=new int[2];
    gnos[0]=gnos[1]=gno;
    char dummy[64];
    sprintf(dummy, "Replace S%d?", selected_sets[0]);
    if (yesno(dummy, NULL, NULL, NULL))
    {
        SaveSetStatesPrevious(2,gnos,selected_sets,UNDO_COMPLETE);
    moveset(gno, selected_sets[1], gno, selected_sets[0]);
        //selected_sets[0]=selected_sets[1];
        SetsModified(1,gnos,selected_sets,UNDO_COMPLETE);
        sprintf(dummy,"Move [G%d.S%d]-->[G%d.S%d]",gno, selected_sets[1], gno, selected_sets[0]);
        addAditionalDescriptionToLastNode(-1,QString(dummy),QString(),0);
    }
    delete[] gnos;
    finishAction(DO_PRESERVE_SELECTION);
}
}

void SetPopup::doCopy12(void)
{
if (number_of_selected_sets==2)
{
    int gno=par->gr_no;
    int * gnos=new int[2];
    gnos[0]=gnos[1]=gno;
    char dummy[64];
    sprintf(dummy, "Overwrite S%d?", selected_sets[1]);
    if (yesno(dummy, NULL, NULL, NULL))
    {
        SaveSetStatesPrevious(2,gnos,selected_sets,UNDO_COMPLETE);
    do_copyset(gno, selected_sets[0], gno, selected_sets[1]);
        SetsModified(2,gnos,selected_sets,UNDO_COMPLETE);
        sprintf(dummy,"Copy [G%d.S%d]-->[G%d.S%d]",gno, selected_sets[0], gno, selected_sets[1]);
        addAditionalDescriptionToLastNode(-1,QString(dummy),QString(),0);
    }
    delete[] gnos;
    finishAction(DO_PRESERVE_SELECTION);
}
}

void SetPopup::doCopy21(void)
{
if (number_of_selected_sets==2)
{
    int gno=par->gr_no;
    int * gnos=new int[2];
    gnos[0]=gnos[1]=gno;
    char dummy[64];
    sprintf(dummy, "Overwrite S%d?", selected_sets[0]);
    if (yesno(dummy, NULL, NULL, NULL))
    {
        SaveSetStatesPrevious(2,gnos,selected_sets,UNDO_COMPLETE);
    do_copyset(gno, selected_sets[1], gno, selected_sets[0]);
        SetsModified(2,gnos,selected_sets,UNDO_COMPLETE);
        sprintf(dummy,"Copy [G%d.S%d]-->[G%d.S%d]",gno, selected_sets[1], gno, selected_sets[0]);
        addAditionalDescriptionToLastNode(-1,QString(dummy),QString(),0);
    }
    delete[] gnos;
    finishAction(DO_PRESERVE_SELECTION);
}
}

void SetPopup::update_menu_content(void)
{
    char dummy[128];
    char dummy2[128];
    actViewSetComments->setChecked(par->show_comments);
    actShowDataLess->setChecked(par->show_data_less);
    actShowHidden->setChecked(par->show_hidden);

    if (number_of_selected_sets==0)
    {
    actLabel->setText(tr("None"));
    actHide->setEnabled(false);
    actBringToFront->setEnabled(false);
    actSendToBack->setEnabled(false);
    actPackAllSets->setEnabled(false);
    actShow->setEnabled(false);
    actDuplicate->setEnabled(false);
    actKill->setEnabled(false);
    actKillData->setEnabled(false);
    actSwap->setEnabled(false);
    actEditInSpreadsheet->setEnabled(false);
    actEditInTextEditor->setEnabled(false);
    actCopy12->setVisible(false);
    actCopy21->setVisible(false);
    actMove12->setVisible(false);
    actMove21->setVisible(false);

    /*actions()[2]->setEnabled(FALSE);
    actions()[3]->setEnabled(FALSE);
    actions()[4]->setEnabled(FALSE);
    actions()[5]->setEnabled(FALSE);
    actions()[7]->setEnabled(FALSE);
    actions()[8]->setEnabled(FALSE);
    actions()[9]->setEnabled(FALSE);
    actions()[11]->setEnabled(FALSE);
    mnuEdit->actions()[0]->setEnabled(FALSE);
    mnuEdit->actions()[1]->setEnabled(FALSE);*/
    }
    else
    {
    actHide->setEnabled(true);
    actBringToFront->setEnabled(true);
    actSendToBack->setEnabled(true);
    actPackAllSets->setEnabled(true);
    actShow->setEnabled(true);
    actDuplicate->setEnabled(true);
    actKill->setEnabled(true);
    actKillData->setEnabled(true);
    actSwap->setEnabled(true);
    actEditInSpreadsheet->setEnabled(true);
    actEditInTextEditor->setEnabled(true);
    /*actions()[2]->setEnabled(TRUE);
    actions()[3]->setEnabled(TRUE);
    actions()[4]->setEnabled(TRUE);
    actions()[5]->setEnabled(TRUE);
    actions()[7]->setEnabled(TRUE);
    actions()[8]->setEnabled(TRUE);
    actions()[9]->setEnabled(TRUE);
    actions()[11]->setEnabled(TRUE);
    mnuEdit->actions()[0]->setEnabled(TRUE);
    mnuEdit->actions()[1]->setEnabled(TRUE);*/

    sprintf(dummy,"S");
    for (int i=0;i<number_of_selected_sets;i++)
    {
    sprintf(dummy2,"%d",selected_sets[i]);
    strcat(dummy,dummy2);
            if (i>2 && i!=number_of_selected_sets-1)
            {
            strcat(dummy,",...");
            break;
            }
            else
            {
            if (i!=number_of_selected_sets-1)
            strcat(dummy,", S");
            }
    }
    actLabel->setText(QString(dummy));

        if (number_of_selected_sets==1)
        {
        actCopy12->setVisible(false);
        actCopy21->setVisible(false);
        actMove12->setVisible(false);
        actMove21->setVisible(false);
        actSwap->setEnabled(false);
        actBringToFront->setEnabled(true);
        actSendToBack->setEnabled(true);
        actEditInSpreadsheet->setEnabled(true);
        actEditInTextEditor->setEnabled(true);
        }
        else
        {
            if (number_of_selected_sets==2)
            {
            sprintf(dummy,"Copy S%d to S%d",selected_sets[0],selected_sets[1]);
            actCopy12->setText(QString(dummy));
            actCopy12->setVisible(true);
            sprintf(dummy,"Copy S%d to S%d",selected_sets[1],selected_sets[0]);
            actCopy21->setText(QString(dummy));
            actCopy21->setVisible(true);
            sprintf(dummy,"Move S%d to S%d",selected_sets[0],selected_sets[1]);
            actMove12->setText(QString(dummy));
            actMove12->setVisible(true);
            sprintf(dummy,"Move S%d to S%d",selected_sets[1],selected_sets[0]);
            actMove21->setText(QString(dummy));
            actMove21->setVisible(true);
            actSwap->setEnabled(true);
            }
            else
            {
            actCopy12->setVisible(false);
            actCopy21->setVisible(false);
            actMove12->setVisible(false);
            actMove21->setVisible(false);
            actSwap->setEnabled(false);
            }
        actBringToFront->setEnabled(false);
        actSendToBack->setEnabled(false);
        actEditInSpreadsheet->setEnabled(false);
        actEditInTextEditor->setEnabled(false);
        }
    }
}

uniList::uniList(int type,QWidget *parent):QListWidget(parent)
{
datType=type;
partner=NULL;
show_all_sets_marker=false;
//set the standard-behavior (can be changed especially for some widgets)
if (type==GRAPHLIST)
{
setBehavior(true,false,false);
}
else if (type==SETCHOICE)
{
setBehavior(false,true,true);
}
else//SetList
{
setBehavior(false,true,false);
}
connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem *)),SLOT(entryDoubleClicked(QListWidgetItem *)));
connect(this,SIGNAL(itemSelectionChanged()),SLOT(new_selection()));

popupMenu1=new SetPopup(this);
popupMenu1->hide();
popupMenu2=new GraphPopup(this);
popupMenu2->hide();

number_of_entries=0;
gr_no=0;
entries=new int[2];
text_entries=new QString[2];
show_hidden=true;
show_data_less=false;
show_comments=false;

if (type==GRAPHLIST)//register this List so that it may be updated later (live)
{
add_GraphSelector(this);
}
else if (type==SETCHOICE)
{
add_SetChoiceItem(this);
}
else
{
add_SetSelector(this);
}
}

uniList::~uniList()
{
delete[] entries;
delete[] text_entries;
}

void uniList::update_number_of_entries(void)
{
char dummy[2048];
char hidden_char;
int cols;
int index=0;
disconnect(this,SIGNAL(itemSelectionChanged()),this,SLOT(new_selection()));
clear();
if (datType==GRAPHLIST)
{
delete[] entries;
entries=new int[number_of_graphs()>1?number_of_graphs()+1:2+1];
	if (show_all_sets_marker==true)
	{
	new QListWidgetItem(tr("All graphs"), this);
	entries[index]=-1;
	index++;
	}
	for (int i=0;i<number_of_graphs();i++)
	{
	if (g[i].hidden!=0 && show_hidden==false) continue;//don't show hidden graphs
        hidden_char=(!is_graph_hidden(i))?'+':'-';
        sprintf(dummy,"(%c) G%d (%d sets)",hidden_char,i,number_of_sets(i));
	new QListWidgetItem(dummy, this);
	entries[index]=i;
	index++;
	}
}
else if (datType==TEXTLIST)
{
index=number_of_entries;//This should by all that is needed.
}
else//SETLIST or SETCHOICE
{
if (gr_no<0 || gr_no>=number_of_graphs()) return;
delete[] entries;
entries=new int[g[gr_no].maxplot>1?g[gr_no].maxplot+1:2+1];
	if (show_all_sets_marker==true)
	{
	new QListWidgetItem(tr("All sets"), this);
	entries[index]=-1;
	index++;
	}
	for (int i=0;i<g[gr_no].maxplot;i++)
        {
        if (!((show_data_less == true || is_set_active(gr_no, i) == TRUE) && (show_hidden == true || is_set_hidden(gr_no, i) != TRUE ))) continue;
        ///if ((g[gr_no].p[i].hidden!=0 && show_hidden==false) || g[gr_no].p[i].data.len<=0) continue;//don't show hidden sets
	hidden_char=g[gr_no].p[i].hidden==0?'+':'-';
	cols=settype_cols(g[gr_no].p[i].type);
        if (datType==SETLIST)
        {
        sprintf(dummy,"(%c) G%d.S%d[%d][%d]",hidden_char,gr_no,i,cols,g[gr_no].p[i].data.len);
            if (show_comments)
            {
            strcat(dummy," \"");
            strcat(dummy,g[gr_no].p[i].comments);
            strcat(dummy,"\"");
            }
        }
        else
        sprintf(dummy, "S%d (N=%d, %s)", i, getsetlength(gr_no, i), getcomment(gr_no, i));
	new QListWidgetItem(dummy, this);
	entries[index]=i;
	index++;
	}
}
number_of_entries=index;
connect(this,SIGNAL(itemSelectionChanged()),this,SLOT(new_selection()));
}

void uniList::update_number_of_entries_preserve_selection(void)
{
int ns,*sel=new int[2];
disconnect(this,SIGNAL(itemSelectionChanged()),this,SLOT(new_selection()));
get_selection(&ns,&sel);
if (0)//partner!=NULL)//this part did not work as desired --> I think this could be deleted
{
disconnect(partner,SIGNAL(itemSelectionChanged()),partner,SLOT(new_selection()));
    int nsp,*selp=new int[2];
    partner->get_selection(&nsp,&selp);
    cout << "selection:" << endl;
    for (int j=0;j<ns;j++)
    cout << j << ": " << sel[j] << endl;
    cout << "partner_selection:" << endl;
    for (int j=0;j<nsp;j++)
    cout << j << ": " << selp[j] << endl;
   if (datType==GRAPHLIST)//nothing to be done here, everything is done, when set is updated
   {//partner is a set-list
        cout << "t1" << endl;
        update_number_of_entries();
        cout << "t2" << endl;
        set_new_selection(ns,sel);
        cout << "t3" << endl;
        partner->update_number_of_entries();
        cout << "t4" << endl;
        partner->set_new_selection(nsp,selp);
        cout << "t5" << endl;
        //cout << "test Graphlist-update" << endl;//update_number_of_entries();
   }
   else
   {
   cout << "test Setlist-update -- doing nothing!" << endl;
   /* for (int j=0;j<nsp;j++)
    cout << j << ": " << selp[j] << endl;
   partner->update_number_of_entries();
   partner->set_new_selection(nsp,selp);

   update_number_of_entries();
   set_new_selection(ns,sel);*/
   }
   delete[] selp;
connect(partner,SIGNAL(itemSelectionChanged()),partner,SLOT(new_selection()));
}
else
{
    if (datType==TEXTLIST)
    {
    clear();
        for (int i=0;i<number_of_entries;i++)
        new QListWidgetItem(QString(text_entries[i]), this);
    }
    else
    {
    update_number_of_entries();
    }
    set_new_selection(ns,sel);
    new_selection();
}
delete[] sel;
connect(this,SIGNAL(itemSelectionChanged()),this,SLOT(new_selection()));
}

void uniList::set_graph_number(int gno,bool keep_selection)
{
gr_no=gno;
int s_nr,*sel=new int[2];
get_selection(&s_nr,&sel);
update_number_of_entries();
if (datType==GRAPHLIST)
item(gno)->setSelected(TRUE);
else if (keep_selection==true)
set_new_selection(s_nr,sel);
delete[] sel;
}

void uniList::get_selection(int * number,int ** selection)
{
QModelIndexList list=selectedIndexes();
*number=list.size();
if (*number<=0) return;//return without deleting anything
delete[] *selection;
if (entries[list.at(0).row()]<0)
{
*number=number_of_entries-1;
*selection=new int[*number];
for (int i=0;i<*number;i++)
*(*selection+i)=entries[i+1];
}
else
{
*selection=new int[*number];
for (int i=0;i<*number;i++)
*(*selection+i)=entries[list.at(i).row()];
}
sort(*number,*selection);
}

void uniList::set_new_selection(int number,int * selection)
{
disconnect(this,SIGNAL(itemSelectionChanged()),this,SLOT(new_selection()));
int scroll=-1;
if (number<0) goto end_set_new_selection;
clearSelection();
if (number==0) goto end_set_new_selection;
for (int i=0;i<number;i++)
{
if (selection[i]>count()) continue;
	for (int j=0;j<count();j++)
	{
	if (selection[i]==entries[j])
	{
	item(j)->setSelected(TRUE);
	if (scroll==-1) scroll=j;
	}
	}
}
if (scroll!=-1)
scrollToItem(item(scroll));
end_set_new_selection:
connect(this,SIGNAL(itemSelectionChanged()),this,SLOT(new_selection()));
}

void uniList::new_selection(void)
{
QModelIndexList list=selectedIndexes();
if (list.size()>0)
{
emit(new_selection(list.at(0).row()));
}
else
{
emit(new_selection(-1));
}
}

void uniList::mousePressEvent(QMouseEvent * e)
{
Qt::KeyboardModifiers modif=e->modifiers();
    QCursor curs=mainWin->cursor();
    QCursor curs2(Qt::WhatsThisCursor);
    QCursor curs3=cursor();
    QCursor curs4=parentWidget()->cursor();
    if (curs.shape()==curs2.shape() || curs3.shape()==curs2.shape() || curs4.shape()==curs2.shape())
    {
        if (datType==SETLIST)
        {
        HelpCB("doc/UsersGuide.html#set-selector");
        }
        else if (datType==GRAPHLIST)
        {
        HelpCB("doc/UsersGuide.html#graph-selector");
        }
        else
        {
        HelpCB("doc/UsersGuide.html#list-selector");
        }
        unsetCursor();
    return;
    }
QPoint p=e->pos();
QModelIndexList list=selectedIndexes();
int number_of_selected_entries=list.size();
QListWidgetItem * clickedItem=itemAt(p);
int selected_no=row(clickedItem);

bool already_selected=false;
if (clickedItem!=0)
already_selected=item(selected_no)->isSelected();

if (e->button() & Qt::RightButton)
{
	if (datType==SETLIST)
	{
	popupMenu1->selected_graph=gr_no;
	get_selection(&popupMenu1->number_of_selected_sets,&popupMenu1->selected_sets);
	sort(popupMenu1->number_of_selected_sets,popupMenu1->selected_sets);
        popupMenu1->update_menu_content();
	popupMenu1->exec(QCursor::pos());
	}
        else if (datType==GRAPHLIST)
	{
        get_selection(&popupMenu2->number_of_selected_graphs,&popupMenu2->selected_graphs);
        sort(popupMenu2->number_of_selected_graphs,popupMenu2->selected_graphs);
        popupMenu2->selected_no=selected_no;
        popupMenu2->update_menu_content();
        popupMenu2->exec(QCursor::pos());
	QListWidget::mousePressEvent(e);
	}
}
else//Left Button clicked
{
    if (clickedItem==0)
    {
        return;//nothing to do if someone clicked outside the entries
    }
    if (number_of_selected_entries>1 && ((int)(modif&Qt::ControlModifier))==0)
    {
        clearSelection();
        item(selected_no)->setSelected(true);
    }
    else if (deselect_possible==true && already_selected==true)
    {
       item(selected_no)->setSelected(false);
    }
    else
    {
        QListWidget::mousePressEvent(e);
    }
}
}

void uniList::mouseReleaseEvent(QMouseEvent * e )
{
QPoint p=e->pos();
QModelIndexList list=selectedIndexes();
int number_of_selected_entries=list.size();
QListWidgetItem * clickedItem=itemAt(p);
int selected_no=row(clickedItem);
if (clickedItem!=0)
QListWidget::mouseReleaseEvent(e);
}

void uniList::keyReleaseEvent(QKeyEvent * e)
{
if (datType==GRAPHLIST || datType==SETLIST)
{
int k=e->key();
Qt::KeyboardModifiers mod=e->modifiers();
if (mod==Qt::ControlModifier)
{
    if (k==Qt::Key_I)
    {
    popupMenu1->selected_graph=gr_no;
    get_selection(&popupMenu1->number_of_selected_sets,&popupMenu1->selected_sets);
    sort(popupMenu1->number_of_selected_sets,popupMenu1->selected_sets);
    popupMenu1->doInvertSelection();
    }
    else if(k==Qt::Key_U)
    clearSelection();
}
}
}

void uniList::entryDoubleClicked(QListWidgetItem * c_item)
{
if (datType==SETLIST)
{
int cl_index=-1;
for (int i=0;i<number_of_entries;i++)
{
	if (item(i)==c_item)
	{
	cl_index=i;
	break;
	}
}
if (cl_index>=0)
showSetInSpreadSheet(gr_no,entries[cl_index]);
}
else if (datType==GRAPHLIST)
{
    int nr_sel,*sel=new int[2];
    get_selection(&nr_sel,&sel);
    int cg = get_cg();
    if (sel[0] != cg) {
        switch_current_graph(sel[0]);
        mainWin->mainArea->completeRedraw();
    }
    delete[] sel;
}
}

void uniList::add_Item(QString item)
{
QString * str=new QString[number_of_entries+1];
int * tentr=new int[number_of_entries];
for (int i=0;i<number_of_entries;i++)
{
str[i]=text_entries[i];
tentr[i]=entries[i];
}
str[number_of_entries]=item;
tentr[number_of_entries]=number_of_entries;
delete[] text_entries;
delete[] entries;
text_entries=str;
entries=tentr;
number_of_entries++;
update_number_of_entries_preserve_selection();
}

void uniList::get_selection(int * number,QString ** selection)
{
QModelIndexList list=selectedIndexes();
*number=list.size();
if (*number<=0) return;
delete[] *selection;
*selection=new QString[*number];
for (int i=0;i<*number;i++)
*(*selection+i)=text_entries[list.at(i).row()];
//sort(*number,*selection);
}

void uniList::setBehavior(bool deselect,bool multi,bool all_sets)
{
deselect_possible=deselect;
show_all_sets_marker=all_sets;
    if (multi==true)
    {
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    }
    else
    {
    setSelectionMode(QAbstractItemView::SingleSelection);
    }
}

void LoadBinaryData(int gno,int setno,int settype,char * filename,struct BinReadInstructions inst)
{
plotarr * p;
char dummy[256];
int importcount=0;
int readbytes;
int allocated;
int startcount;
char * dest;
int * positions=new int[inst.n_columns_to_read];//positions, where the different colums are in one complete column set
int length_of_one_column_set=0;

for (int i=0;i<inst.column_count;i++)//all columns in a set (to be read or not)
length_of_one_column_set+=inst.column_type[i].size;

dest=new char[length_of_one_column_set+8];//prepare space to read one set

if (inst.read_until_end_is_reached==true)
{
startcount=-1;//we will count downwards --> 0 is never reached
}
else
{
startcount=inst.datasets_to_read;//we will count downwards until zero is reached
}
//prepare set for writing
int retval=activateset(gno,setno);
set_dataset_type(gno,setno,settype);
/*cout << "setlength=" << getsetlength(gno, setno) << endl;
cout << "number of cols=" << dataset_cols(gno, setno) << endl;
cout << "number of cols new settype=" << settype_cols(settype) << endl;
cout << "filename='" << filename << "'" << endl;*/
p = &g[gno].p[setno];
allocated=100;
//prepare some space for the data that is to be read an stored
p->data.len=0;
for (int i=0;i<inst.n_columns_to_read;i++)
{
p->data.ex[i] = (double *)xrealloc(p->data.ex[i], allocated*sizeof(double));
positions[i]=0;
    for (int j=0;j<i;j++)
    positions[i]+=inst.column_type[j].size;
//cout << "column_offset[" << i << "]=" << positions[i] << endl;
}
ifstream ifi;
ifi.open(filename);

if (inst.length_of_header>0)
{
ifi.seekg(inst.length_of_header);
}

while (startcount!=0)
{
ifi.read(dest,length_of_one_column_set);//read one set of columns in one go into dest
readbytes=(int)(ifi.gcount());
if (readbytes!=length_of_one_column_set)
{
//cout << "error reading datacolumn; " << importcount << " sets already read" << endl;
    sprintf(dummy,"[Information] Stopped reading after import of %d datasets.",importcount);
    stufftext(dummy);
break;
}
else//normal read operation
{
startcount--;
//convert columns into dataset
for (int i=0;i<inst.n_columns_to_read;i++)
{
    switch (inst.column_type[inst.col_numbers_to_read[i]].format)
    {//get format of colum that is to be read
    case COLUMN_SIG_CHAR:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (signed char*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    case COLUMN_USIG_CHAR:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (unsigned char*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    case COLUMN_SIG_SHORT:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (signed short*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    case COLUMN_USIG_SHORT:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (unsigned short*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    case COLUMN_SIG_INT:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (signed int*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    case COLUMN_USIG_INT:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (unsigned int*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    case COLUMN_SIG_LONG:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (signed long*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    case COLUMN_USIG_LONG:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (unsigned long*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    case COLUMN_FLOAT:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (float*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    case COLUMN_DOUBLE:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (double*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    case COLUMN_LONG_DOUBLE:
    p->data.ex[i][importcount]=(double)(
                 *(
                   (long double*)(
                                  (void*)(dest+positions[i])
                                 )
                  )
                  );
    break;
    }
}
//check for enough space for the next run
    importcount++;
    if (importcount==allocated)
    {
        allocated+=100;
        for (int i=0;i<inst.n_columns_to_read;i++)
        {
        p->data.ex[i] = (double *)xrealloc(p->data.ex[i], allocated*sizeof(double));
        if (!p->data.ex[i]) cout << "error in reallocation" << endl;
        }
    }
}
if (ifi.eof()) break;
}

for (int i=0;i<inst.n_columns_to_read;i++)
p->data.ex[i] = (double *)xrealloc(p->data.ex[i], importcount*sizeof(double));
p->data.len=importcount;

delete[] positions;
}

