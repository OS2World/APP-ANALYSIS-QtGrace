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
#include "MainWindow.h"
#include "bitmaps.h"
#include "jbitmaps.h"
#include "mbitmaps.h"
#include "patterns.h"
#include "events.h"
#include "graphutils.h"
#include "allWidgets.h"
#include "plotone.h"
#include "files.h"
#include "undo_module.h"

#include <QDesktopWidget>

using namespace std;

extern QFont stdFont;
extern graph *g;
extern bool useQPrinter;
extern QPrinter * stdPrinter;
extern int stdOutputFormat;
extern frmDrawObjects * FormDrawObjects;
extern frmConsole * FormConsole;
extern frmEvalExpr * FormEvalExpr;
extern frmSetAppearance * FormSetAppearance;
extern frmGraphApp * FormGraphAppearance;
extern frmPlotAppearance * FormPlotAppearance;
extern frmLocatorProps * FormLocatorProps;
extern frmAxisProp * FormAxisProperties;
extern frmPointExplorer * FormPointExplorer;
extern frmNonlinCurveFit * FormNonlinCurveFit;
extern frmInterpolation * FormInterpolation;
extern frmSetOp * FormSetOperations;
extern frmCommands * FormCommands;
extern frmDeviceSetup * FormDeviceSetup;
extern frmPreferences * FormPreferences;
extern frmArrangeGraphs * FormArrangeGraphs;
extern frmOverlayGraphs * FormOverlayGraphs;
extern frmAutoscaleGraphs * FormAutoScaleGraphs;
extern frmDataSetProperties * FormDataSetProperties;
extern frmSetOperations * FormSetOPS;
extern frmFeatureExtract * FormFeatureExtraction;
extern frmInterpolation * FormHistograms;
extern frmFourier * FormFourier;
extern frmFourier2 * FormFourier2;
extern frmSmallCalc * FormIntegration;
extern frmSmallCalc * FormSeasonDiff;
extern frmSmallCalc * FormDifferences;
extern frmSmallCalc * FormAverages;
extern frmSmallCalc * FormRegression;
extern frmCorrelation * FormCorrelation;
extern frmCorrelation * FormConvolution;
extern frmCorrelation * FormDigitalFilter;
extern frmTransform * FormPruneData;
extern frmTransform * FormSamplePoints;
extern frmTransform * FormGeometricTransform;
extern frmHotLinks * FormHotLinks;
extern frmRegionStatus * FormRegionStatus;
extern frmRegions * FormReportRegion;
extern frmRegions * FormClearRegion;
extern frmRegions * FormDefineRegion;

extern frmNetCDF * FormNetCDF;
extern frmIOForm * FormReadSets;
extern frmIOForm * FormReadNetCDF;
extern frmIOForm * FormWriteSets;
extern frmIOForm * FormOpenProject;
extern frmIOForm * FormSaveProject;
extern frmIOForm * FormReadParameters;
extern frmIOForm * FormWriteParameters;
extern frmIOForm * FormReadBinary;
extern frmIOForm * FormWriteBinary;

extern frmBinaryFormatInput * FormBinaryImportFilter;

extern frmFontTool * FormFontTool;
extern frmAbout * FormAbout;
extern frmUndoList * FormUndoList;

extern frmExtraPreferences * ExtraPreferences;
extern bool showhideworkaround;

extern char user_home_dir[1024];
extern char qt_grace_exe_dir[1024];
extern int inwin;
extern int monomode;
extern int cursortype;
extern int win_w;
extern int win_h;
extern int anchor_x;
extern int anchor_y;
extern QRect ShiftRect;
extern QPoint ShiftPoint;
extern MainWindow * mainWin;
extern QImage * MainPixmap;
extern QPainter * GeneralPainter;
extern QBitmap * patterns[MAXPATTERNS];
extern QPixmap * PatternPixmaps[MAXPATTERNS];
extern QBitmap * autoBitMap;
extern QBitmap * downBitMap;
extern QBitmap * expandBitMap;
extern QBitmap * leftBitMap;
extern QBitmap * rightBitMap;
extern QBitmap * shrinkBitMap;
extern QBitmap * upBitMap;
extern QBitmap * zoomBitMap;
extern QPixmap * GraceIcon;
extern QPixmap * Qt_j_lm_o_bits;
extern QPixmap * Qt_j_cm_o_bits;
extern QPixmap * Qt_j_rm_o_bits;
extern QPixmap * Qt_j_lb_b_bits;
extern QPixmap * Qt_j_lm_b_bits;
extern QPixmap * Qt_j_lt_b_bits;
extern QPixmap * Qt_j_ct_b_bits;
extern QPixmap * Qt_j_rt_b_bits;
extern QPixmap * Qt_j_rm_b_bits;
extern QPixmap * Qt_j_rb_b_bits;
extern QPixmap * Qt_j_cb_b_bits;
extern QPixmap * Qt_j_cm_b_bits;

extern QPixmap * Qt_m_hv_lr_bt_bits;
extern QPixmap * Qt_m_hv_lr_tb_bits;
extern QPixmap * Qt_m_hv_rl_bt_bits;
extern QPixmap * Qt_m_hv_rl_tb_bits;
extern QPixmap * Qt_m_vh_lr_bt_bits;
extern QPixmap * Qt_m_vh_lr_tb_bits;
extern QPixmap * Qt_m_vh_rl_bt_bits;
extern QPixmap * Qt_m_vh_rl_tb_bits;

extern QIcon * ColorIcons[16];
extern QPixmap * ColorPixmaps[16];
extern QString * ColorNames[16];
extern QIcon * LineIcons[MAXLINESTYLES];
extern QPixmap * LinePixmaps[MAXLINESTYLES];

extern QVector<qreal> * PenDashPattern[MAXLINESTYLES];

extern QCursor * wait_cursor;
extern QCursor * line_cursor;
extern QCursor * find_cursor;
extern QCursor * move_cursor;
extern QCursor * text_cursor;
extern QCursor * kill_cursor;
extern int cur_cursor;

extern int action_flag;

extern int max_history;
extern int current_history;
extern QString history[MAX_HISTORY];

extern QColor * stdColors[16];//Colors for Drawing
extern QBrush * stdBrush;//standard Brush for Drawing
extern QPen * stdPen;//standard Pen for Drawing

extern QBitmap generate_Bitmap_from_Bits(unsigned char * bits,int length,int rows,int cols);
extern void generate_Pixmap_from_Bits(unsigned char * bits,int length,int rows,int cols,QPixmap * target);
extern void convertBitmapToPixmap(QBitmap * source,QPixmap * dest);
extern int find_dev_nr(char * dev_name);
extern void HelpCB(char *data);
extern void get_tracking_props(int *setno, int *move_dir, int *add_at);

extern void read_settings(void);
extern void write_settings(void);

void init_Patterns(void)
{
QPixmap tempIcon(38,24);
QPixmap tempIcon2(38,24);
QPainter paint;
for (int i=0;i<MAXPATTERNS;i++)
{
patterns[i]=new QBitmap();
*(patterns[i])=generate_Bitmap_from_Bits(pat_bits[i],32,16,16);
tempIcon.fill(QApplication::palette().window().color());
paint.begin(&tempIcon);
paint.setPen(Qt::black);
paint.setBrush(Qt::black);
if (i==0)
paint.drawText(4,16,QString("None"));
else
{
convertBitmapToPixmap(patterns[i],&tempIcon2);
paint.drawPixmap(11,4,tempIcon2);
}
paint.end();
PatternPixmaps[i]=new QPixmap(tempIcon);
}
}

MainWindow::MainWindow( QWidget *parent):QWidget( parent )
{
QPixmap HelpPixmap;

setFont(stdFont);

setWindowTitle(QString("qtGrace: untitled"));

windowWidth=872;
windowHeight=670;

helpMapper=new QSignalMapper();

CreateActions();
CreatePatterns();

setWindowIcon(QIcon(*GraceIcon));

    //setMinimumSize(windowWidth,windowHeight);
    //setMaximumSize(windowWidth,windowHeight);

//Main menu bar
menuBar=new QMenuBar(this);
menuBar->setGeometry(0,0,windowWidth,menuBar->height());

//The File-Menu and its entries
mnuFile	=new QMenu(tr("&File"), this );
mnuFile->setTearOffEnabled(TRUE);
mnuFile->addAction(actNew);
mnuFile->addAction(actOpen);
mnuFile->addAction(actSave);
mnuFile->addAction(actSaveAs);
mnuFile->addAction(actRevert);
mnuHistory=new QMenu(tr("Recently opened files"),this);
mnuHistory->setTearOffEnabled(TRUE);
for (int i=0;i<MAX_HISTORY;i++)
mnuHistory->addAction(actHistory[i]);
mnuHistory->addSeparator();
mnuHistory->addAction(actClearHistory);
mnuFile->addMenu(mnuHistory);
mnuFile->addSeparator();
mnuFile->addAction(actPrintSetup);
mnuFile->addAction(actPrint);
mnuFile->addSeparator();
mnuFile->addAction(actExit);

//The Edit-Menu and its entries
mnuEdit=new QMenu(tr("&Edit"),  this );
mnuEdit->setTearOffEnabled(TRUE);
mnuEdit->addAction(actUndo);
mnuEdit->addAction(actRedo);
mnuEdit->addAction(actUndoList);
mnuEdit->addSeparator();
mnuEdit->addAction(actDataSets);
mnuEdit->addAction(actSetOperations);
mnuEdit->addSeparator();
mnuEdit->addAction(actArrangeGraphs);
mnuEdit->addAction(actOverlayGraphs);
mnuEdit->addAction(actAutoscaleGraphs);
mnuEdit->addSeparator();
mnuRegions=new QMenu(tr("Reg&ions"),this);
mnuRegions->setTearOffEnabled(TRUE);
mnuRegions->addAction(actRegionsStatus);
mnuRegions->addAction(actRegionsDefine);
mnuRegions->addAction(actRegionsClear);
mnuRegions->addSeparator();
mnuRegions->addAction(actRegionsReportOn);
mnuEdit->addMenu(mnuRegions);
mnuEdit->addAction(actHotLinks);
mnuEdit->addSeparator();
mnuEdit->addAction(actSetLocFixPoint);
mnuEdit->addAction(actClearLocFixPoint);
mnuEdit->addAction(actLocProp);
mnuEdit->addSeparator();
mnuEdit->addAction(actPreferences);

//The Data-Menu and its entries
mnuData	=new QMenu(tr("&Data"), this );
mnuData->setTearOffEnabled(TRUE);

mnuTransform=new QMenu(tr("&Transformations"), this );
mnuTransform->setTearOffEnabled(TRUE);
mnuTransform->addAction(actEvaluateExpr);
mnuTransform->addAction(actHistograms);
mnuTransform->addAction(actFourier);
mnuTransform->addAction(actFourier2);
mnuTransform->addSeparator();
mnuTransform->addAction(actRunningAverages);
mnuTransform->addAction(actDifferences);
mnuTransform->addAction(actSeasonalDiff);
mnuTransform->addAction(actIntegration);
mnuTransform->addSeparator();
mnuTransform->addAction(actInterpolation);
mnuTransform->addAction(actRegression);
mnuTransform->addAction(actNonLinCurveFitting);
mnuTransform->addSeparator();
mnuTransform->addAction(actCorrelation);
mnuTransform->addAction(actDigitalFilter);
mnuTransform->addAction(actLinConvolution);
mnuTransform->addSeparator();
mnuTransform->addAction(actGeomTransform);
mnuTransform->addSeparator();
mnuTransform->addAction(actSamplePoints);
mnuTransform->addAction(actPruneData);

mnuImport=new QMenu(tr("&Import"), this );
mnuImport->setTearOffEnabled(TRUE);
mnuImport->addAction(actImportAscii);
mnuImport->addAction(actImportBinary);
mnuImport->addAction(actImportNetCDF);
mnuExport=new QMenu(tr("&Export"), this );
mnuExport->setTearOffEnabled(TRUE);
mnuExport->addAction(actExportAscii);
mnuExport->addAction(actExportBinary);

mnuData->addAction(actDataSetOperations);
mnuData->addMenu(mnuTransform);
mnuData->addAction(actFeatureExtraction);
mnuData->addSeparator();
mnuData->addMenu(mnuImport);
mnuData->addMenu(mnuExport);

//The Plo-Menu and its entries
mnuPlot	=new QMenu(tr("&Plot"), this );
mnuPlot->setTearOffEnabled(TRUE);
mnuPlot->addAction(actPlotAppearance);
mnuPlot->addAction(actGraphAppearance);
mnuPlot->addAction(actSetAppearance);
mnuPlot->addAction(actAxisProperties);
mnuPlot->addSeparator();
mnuPlot->addAction(actLoadParameters);
mnuPlot->addAction(actSaveParameters);

//The View-Menu and its entries
mnuView	=new QMenu(tr("&View"), this );
mnuView->setTearOffEnabled(TRUE);
mnuView->addAction(actShowLocBar);
mnuView->addAction(actShowStatusBar);
mnuView->addAction(actShowToolBar);
mnuView->addSeparator();
mnuView->addAction(actPageSetup);
mnuView->addSeparator();
mnuView->addAction(actRedraw);
mnuView->addSeparator();
mnuView->addAction(actUpdateAll);

//The Window-Menu and its entries
mnuWindow=new QMenu(tr("&Window"),  this );
mnuWindow->setTearOffEnabled(TRUE);
mnuWindow->addAction(actCommands);
mnuWindow->addAction(actPointExplorer);
mnuWindow->addAction(actDrawingObjects);
mnuWindow->addAction(actFontTool);
mnuWindow->addAction(actConsole);

//The Help-Menu and its entries
mnuHelp	=new QMenu(tr("&Help"),  this );
mnuHelp->setTearOffEnabled(TRUE);
mnuExample=new QMenu(tr("&Examples"), this );
mnuExample->setTearOffEnabled(TRUE);
for (int i=0;i<nr_of_Example_Menues;i++)
mnuExample->addMenu(example_menues[i]);
connect(helpMapper, SIGNAL(mapped(int)),this, SLOT(HelpOpenExample(int)));

mnuHelp->addAction(actHelpOnContext);
mnuHelp->addAction(actHelpUsersGuide);
mnuHelp->addAction(actHelpTutorial);
mnuHelp->addAction(actHelpFAQ);
mnuHelp->addAction(actHelpChanges);
mnuHelp->addSeparator();
mnuHelp->addMenu(mnuExample);
mnuHelp->addSeparator();
mnuHelp->addAction(actHelpComments);
mnuHelp->addSeparator();
mnuHelp->addAction(actHelpLicense);
mnuHelp->addAction(actHelpAbout);

menuBar->addMenu( mnuFile );
menuBar->addMenu( mnuEdit );
menuBar->addMenu( mnuData );
menuBar->addMenu( mnuPlot );
menuBar->addMenu( mnuView );
menuBar->addMenu( mnuWindow );
menuBar->addSeparator();
menuBar->addMenu( mnuHelp );

stdBarHeight=menuBar->height()-7;
stdRowHeight=148;
stdColWidth=68;
stdDistance1=5;
stdDistance2=6;
stdHeight1=25;
stdHeight2=23;
stdWidth2=23;

//The status locator bar
statLocBar=new QLabel(" ",this);
//statLocBar->setGeometry(0,stdBarHeight,windowWidth,stdBarHeight-8);
statLocBar->setText(QString("G0: X, Y = [-, -]"));
statLocBar->setFrameStyle(QFrame::Box | QFrame::Raised);

//The status bar 
statusBar=new QStatusBar(this);
//statusBar->setGeometry(0,windowHeight-stdBarHeight,windowWidth,stdBarHeight);
statusBar->showMessage( "-,-,Untitled" );

//The tool bar(s)
toolBar1=new QFrame(this);
//toolBar1->setGeometry(0,stdBarHeight+statLocBar->height(),70,130);
toolBar1->setFrameStyle(QFrame::Box | QFrame::Raised);
//toolBar1->setMinimumHeight(137);

cmdDraw=new QPushButton(tr("Draw"),toolBar1);
cmdDraw->setGeometry(2,4,64,stdHeight1);
connect(cmdDraw, SIGNAL(clicked()), this, SLOT(doDraw()));
convertBitmapToPixmap(zoomBitMap,&HelpPixmap);
cmdZoom=new QPushButton(HelpPixmap,"",toolBar1);
cmdZoom->setGeometry(cmdDraw->x()+stdDistance2,cmdDraw->y()+cmdDraw->height()+6,stdWidth2,stdHeight2);
connect(cmdZoom, SIGNAL(clicked()), this, SLOT(doZoom()));
convertBitmapToPixmap(autoBitMap,&HelpPixmap);
cmdAutoScale=new QPushButton(HelpPixmap,"",toolBar1);
cmdAutoScale->setGeometry(cmdDraw->x()+cmdZoom->width()+2*stdDistance2,cmdZoom->y(),stdWidth2,stdHeight2);
connect(cmdAutoScale, SIGNAL(clicked()), this, SLOT(doAutoScale()));
convertBitmapToPixmap(expandBitMap,&HelpPixmap);
cmdZz=new QPushButton(HelpPixmap,"",toolBar1);
cmdZz->setGeometry(cmdDraw->x()+stdDistance2,cmdZoom->y()+cmdZoom->height()+stdDistance1,stdWidth2,stdHeight2);
connect(cmdZz, SIGNAL(clicked()), this, SLOT(doZz()));
convertBitmapToPixmap(shrinkBitMap,&HelpPixmap);
cmdzz=new QPushButton(HelpPixmap,"",toolBar1);
cmdzz->setGeometry(cmdDraw->x()+cmdZoom->width()+2*stdDistance2,cmdZz->y(),stdWidth2,stdHeight2);
connect(cmdzz, SIGNAL(clicked()), this, SLOT(dozz()));
convertBitmapToPixmap(leftBitMap,&HelpPixmap);
cmdLeft=new QPushButton(HelpPixmap,"",toolBar1);
cmdLeft->setGeometry(cmdDraw->x()+stdDistance2,cmdZz->y()+cmdZz->height()+stdDistance1,stdWidth2,stdHeight2);
connect(cmdLeft, SIGNAL(clicked()), this, SLOT(doLeft()));
convertBitmapToPixmap(rightBitMap,&HelpPixmap);
cmdRight=new QPushButton(HelpPixmap,"",toolBar1);
cmdRight->setGeometry(cmdDraw->x()+cmdZoom->width()+2*stdDistance2,cmdLeft->y(),stdWidth2,stdHeight2);
connect(cmdRight, SIGNAL(clicked()), this, SLOT(doRight()));
convertBitmapToPixmap(upBitMap,&HelpPixmap);
cmdUp=new QPushButton(HelpPixmap,"",toolBar1);
cmdUp->setGeometry(cmdDraw->x()+stdDistance2,cmdLeft->y()+cmdLeft->height()+stdDistance1,stdWidth2,stdHeight2);
connect(cmdUp, SIGNAL(clicked()), this, SLOT(doUp()));
convertBitmapToPixmap(downBitMap,&HelpPixmap);
cmdDown=new QPushButton(HelpPixmap,"",toolBar1);
cmdDown->setGeometry(cmdDraw->x()+cmdZoom->width()+2*stdDistance2,cmdUp->y(),stdWidth2,stdHeight2);
connect(cmdDown, SIGNAL(clicked()), this, SLOT(doDown()));

tool1Grid=new QGridLayout();
tool1Grid->setMargin(2);
tool1Grid->setSpacing(2);

toolBar1->setLayout(tool1Grid);

toolBar2=new QFrame(this);
//toolBar2->setGeometry(0,toolBar1->y()+toolBar1->height(),toolBar1->width(),windowHeight-stdBarHeight*2-statLocBar->height()-toolBar1->height());
toolBar2->setFrameStyle(QFrame::Box | QFrame::Raised);

cmdAutoT=new QPushButton("AutoT",toolBar2);
cmdAutoT->setGeometry(2,2,64,stdHeight1);
connect(cmdAutoT, SIGNAL(clicked()), this, SLOT(doAutoT()));
cmdAutoO=new QPushButton("AutoO",toolBar2);
cmdAutoO->setGeometry(cmdAutoT->x(),cmdAutoT->y()+cmdAutoT->height()+2,cmdAutoT->width(),cmdAutoT->height());
connect(cmdAutoO, SIGNAL(clicked()), this, SLOT(doAutoO()));
cmdZX=new QPushButton("ZX",toolBar2);
cmdZX->setGeometry(cmdAutoO->x()+stdDistance2,cmdAutoO->y()+cmdAutoO->height()+4,stdWidth2,stdHeight2);
connect(cmdZX, SIGNAL(clicked()), this, SLOT(doZX()));
cmdZY=new QPushButton("ZY",toolBar2);
cmdZY->setGeometry(cmdZX->x()+cmdZX->width()+stdDistance2,cmdZX->y(),stdWidth2,stdHeight2);
connect(cmdZY, SIGNAL(clicked()), this, SLOT(doZY()));
cmdAX=new QPushButton("AX",toolBar2);
cmdAX->setGeometry(cmdZX->x(),cmdZX->y()+cmdZX->height()+stdDistance1,cmdZX->width(),cmdZX->height());
connect(cmdAX, SIGNAL(clicked()), this, SLOT(doAX()));
cmdAY=new QPushButton("AY",toolBar2);
cmdAY->setGeometry(cmdZY->x(),cmdAX->y(),cmdZX->width(),cmdZX->height());
connect(cmdAY, SIGNAL(clicked()), this, SLOT(doAY()));
cmdPZ=new QPushButton("PZ",toolBar2);
cmdPZ->setGeometry(cmdZX->x(),cmdAX->y()+cmdAX->height()+stdDistance1,cmdZX->width(),cmdZX->height());
connect(cmdPZ, SIGNAL(clicked()), this, SLOT(doPZ()));
cmdPu=new QPushButton("Pu",toolBar2);
cmdPu->setGeometry(cmdZY->x(),cmdPZ->y(),cmdZX->width(),cmdZX->height());
connect(cmdPu, SIGNAL(clicked()), this, SLOT(doPu()));
cmdPo=new QPushButton("Po",toolBar2);
cmdPo->setGeometry(cmdZX->x(),cmdPZ->y()+cmdPZ->height()+stdDistance1,cmdZX->width(),cmdZX->height());
connect(cmdPo, SIGNAL(clicked()), this, SLOT(doPo()));
cmdCy=new QPushButton("Cy",toolBar2);
cmdCy->setGeometry(cmdZY->x(),cmdPo->y(),cmdZX->width(),cmdZX->height());
connect(cmdCy, SIGNAL(clicked()), this, SLOT(doCy()));
lblSD=new QLabel(" SD:1",toolBar2);
lblSD->setGeometry(cmdDraw->x(),cmdCy->y()+cmdCy->height()+stdDistance1,cmdDraw->width(),cmdDraw->height()-6);
lblCW=new QLabel(" CW:0",toolBar2);
lblCW->setGeometry(lblSD->x(),lblSD->y()+lblSD->height(),lblSD->width(),lblSD->height());
cmdExit=new QPushButton(tr("Exit"),toolBar2);
cmdExit->setGeometry(cmdAutoO->x(),lblCW->y()+lblCW->height()+2,cmdAutoO->width(),cmdAutoO->height());
connect(cmdExit, SIGNAL(clicked()), this, SLOT(doExit()));

tool2Grid=new QGridLayout();
tool2Grid->setMargin(2);
tool2Grid->setSpacing(2);

toolBar2->setLayout(tool2Grid);

//The main drawing area
mainArea=new MainArea(this);
mainArea->setGeometry(toolBar1->width(),stdBarHeight+statLocBar->height(),windowWidth-toolBar1->width(),windowHeight-statusBar->height()-stdBarHeight-statLocBar->height());
mainArea->show();

mainGrid=new QGridLayout();
mainGrid->setMargin(2);
mainGrid->setSpacing(0);
mainGrid->addWidget(menuBar,0,0,1,2);
mainGrid->setRowMinimumHeight(0,stdBarHeight);
mainGrid->setRowStretch(0,0);
mainGrid->addWidget(statLocBar,1,0,1,2);
mainGrid->setRowMinimumHeight(1,stdBarHeight);
mainGrid->setRowStretch(1,0);
mainGrid->addWidget(toolBar1,2,0,1,1);
mainGrid->addWidget(toolBar2,3,0,1,1);
mainGrid->addWidget(mainArea,2,1,2,1);
mainGrid->setRowStretch(2,0);
mainGrid->setRowStretch(3,1);
mainGrid->addWidget(statusBar,4,0,1,2);
mainGrid->setRowMinimumHeight(4,stdBarHeight);
mainGrid->setRowStretch(4,0);
mainGrid->setColumnMinimumWidth(0,stdColWidth);
mainGrid->setColumnStretch(0,0);
mainGrid->setColumnStretch(1,1);
mainGrid->setRowMinimumHeight(2,stdRowHeight);

mainGrid->setRowStretch(0,0);
mainGrid->setRowStretch(1,0);
mainGrid->setRowStretch(2,0);
mainGrid->setRowStretch(3,1);
mainGrid->setRowStretch(4,0);
#ifdef MAC_SYSTEM
mainGrid->removeWidget(menuBar);
mainGrid->setRowMinimumHeight(0,0);
#endif
setLayout(mainGrid);
}

MainWindow::~MainWindow()
{
for (int i=0;i<MAXPATTERNS;i++)
delete patterns[i];

delete autoBitMap;
delete downBitMap;
delete expandBitMap;
delete leftBitMap;
delete rightBitMap;
delete shrinkBitMap;
delete upBitMap;
delete zoomBitMap;
delete GraceIcon;
delete Qt_j_lm_o_bits;
delete Qt_j_cm_o_bits;
delete Qt_j_rm_o_bits;
delete Qt_j_lb_b_bits;
delete Qt_j_lm_b_bits;
delete Qt_j_lt_b_bits;
delete Qt_j_ct_b_bits;
delete Qt_j_rt_b_bits;
delete Qt_j_rm_b_bits;
delete Qt_j_rb_b_bits;
delete Qt_j_cb_b_bits;
delete Qt_j_cm_b_bits;
delete Qt_m_hv_lr_bt_bits;
delete Qt_m_hv_lr_tb_bits;
delete Qt_m_hv_rl_bt_bits;
delete Qt_m_hv_rl_tb_bits;
delete Qt_m_vh_lr_bt_bits;
delete Qt_m_vh_lr_tb_bits;
delete Qt_m_vh_rl_bt_bits;
delete Qt_m_vh_rl_tb_bits;

for (int i=0;i<MAXLINESTYLES;i++)
{
delete PenDashPattern[i];
delete LineIcons[i];
delete LinePixmaps[i];
}
for (int i=0;i<16;i++)
{
delete ColorIcons[i];
delete ColorPixmaps[i];
delete ColorNames[i];
}

delete wait_cursor;
delete line_cursor;
delete find_cursor;
delete move_cursor;
delete text_cursor;
delete kill_cursor;
}

void MainWindow::CreatePatterns(void)
{
//generate Patterns for filling styles
for (int i=0;i<MAXPATTERNS;i++)
patterns[i]=new QBitmap(16,16);
init_Patterns();

autoBitMap=new QBitmap();
*autoBitMap=generate_Bitmap_from_Bits(auto_bits,auto_width*auto_height,auto_width,auto_height);
downBitMap=new QBitmap();
*downBitMap=generate_Bitmap_from_Bits(down_bits,down_width*down_height,down_width,down_height);
expandBitMap=new QBitmap();
*expandBitMap=generate_Bitmap_from_Bits(expand_bits,expand_width*expand_height,expand_width,expand_height);
leftBitMap=new QBitmap();
*leftBitMap=generate_Bitmap_from_Bits(left_bits,left_width*left_height,left_width,left_height);
rightBitMap=new QBitmap();
*rightBitMap=generate_Bitmap_from_Bits(right_bits,right_width*right_height,right_width,right_height);
shrinkBitMap=new QBitmap();
*shrinkBitMap=generate_Bitmap_from_Bits(shrink_bits,shrink_width*shrink_height,shrink_width,shrink_height);
upBitMap=new QBitmap();
*upBitMap=generate_Bitmap_from_Bits(up_bits,up_width*up_height,up_width,up_height);
zoomBitMap=new QBitmap();
*zoomBitMap=generate_Bitmap_from_Bits(zoom_bits,zoom_width*zoom_height,zoom_width,zoom_height);

//Read Grace-icon-image
GraceIcon=new QPixmap(16,16);
char dummy1[80],dummy2[80],dummy3[80];
int rr,gg,bb;
char dummy[800];
int c_width,c_height,nr_cols,bpc;
sscanf(grace_icon_xpm[0],"%d %d %d %d",&c_width,&c_height,&nr_cols,&bpc);
QImage img1(c_width,c_height,QImage::Format_ARGB32_Premultiplied);
QColor cols[nr_cols];
char ctrl_char[nr_cols];
for (int i=0;i<nr_cols;i++)
{
sscanf(grace_icon_xpm[1+i],"%c c #%s",ctrl_char+i,dummy);
dummy1[0]=dummy2[0]=dummy3[0]='0';
dummy1[1]=dummy2[1]=dummy3[1]='x';
	for (int j=0;j<4;j++)
	{
	dummy1[2+j]=dummy[j];
	dummy2[2+j]=dummy[j+4];
	dummy3[2+j]=dummy[j+8];
	}
dummy1[2+4]='\0';
dummy2[2+4]='\0';
dummy3[2+4]='\0';
sscanf(dummy1,"%x",&rr);
sscanf(dummy2,"%x",&gg);
sscanf(dummy3,"%x",&bb);
cols[i]=QColor(rr/256 ,gg/256 ,bb/256 );
}

for (int i=0;i<c_width;i++)
{
	for (int j=0;j<c_height;j++)
	{
		for (int k=0;k<nr_cols;k++)
		{
			if (ctrl_char[k]==grace_icon_xpm[1+nr_cols+j][i])
			{
			img1.setPixel(i,j,cols[k].rgb());
			break;
			}
		}
	}
}
*GraceIcon=QPixmap::fromImage(img1,Qt::AutoColor);

//GraceIcon->save(QString("GraceIcon.png"),"PNG",100);

//Read justification bits
Qt_j_lm_o_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_lm_o_bits=generate_Bitmap_from_Bits(j_lm_o_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_lm_o_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_lm_o_bits);
Qt_j_cm_o_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_cm_o_bits=generate_Bitmap_from_Bits(j_cm_o_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_cm_o_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_cm_o_bits);
Qt_j_rm_o_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_rm_o_bits=generate_Bitmap_from_Bits(j_rm_o_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_rm_o_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_rm_o_bits);
Qt_j_lb_b_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_lb_b_bits=generate_Bitmap_from_Bits(j_lb_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_lb_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_lb_b_bits);
Qt_j_lm_b_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_lm_b_bits=generate_Bitmap_from_Bits(j_lm_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_lm_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_lm_b_bits);
Qt_j_lt_b_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_lt_b_bits=generate_Bitmap_from_Bits(j_lt_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_lt_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_lt_b_bits);
Qt_j_ct_b_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_ct_b_bits=generate_Bitmap_from_Bits(j_ct_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_ct_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_ct_b_bits);
Qt_j_rt_b_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_rt_b_bits=generate_Bitmap_from_Bits(j_rt_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_rt_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_rt_b_bits);
Qt_j_rm_b_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_rm_b_bits=generate_Bitmap_from_Bits(j_rm_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_rm_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_rm_b_bits);
Qt_j_rb_b_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_rb_b_bits=generate_Bitmap_from_Bits(j_rb_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_rb_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_rb_b_bits);
Qt_j_cb_b_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_cb_b_bits=generate_Bitmap_from_Bits(j_cb_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_cb_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_cb_b_bits);
Qt_j_cm_b_bits=new QPixmap(JBITMAP_WIDTH,JBITMAP_HEIGHT);
//*Qt_j_cm_b_bits=generate_Bitmap_from_Bits(j_cm_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT);
generate_Pixmap_from_Bits(j_cm_b_bits,5*12+9,JBITMAP_WIDTH,JBITMAP_HEIGHT,Qt_j_cm_b_bits);

Qt_m_hv_lr_bt_bits=new QPixmap(MBITMAP_WIDTH,MBITMAP_HEIGHT);
generate_Pixmap_from_Bits(m_hv_lr_tb_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT,Qt_m_hv_lr_bt_bits);
Qt_m_hv_lr_tb_bits=new QPixmap(MBITMAP_WIDTH,MBITMAP_HEIGHT);
//*Qt_m_hv_lr_tb_bits=generate_Bitmap_from_Bits(m_hv_lr_tb_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT);
generate_Pixmap_from_Bits(m_hv_lr_tb_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT,Qt_m_hv_lr_tb_bits);
Qt_m_hv_rl_bt_bits=new QPixmap(MBITMAP_WIDTH,MBITMAP_HEIGHT);
//*Qt_m_hv_rl_bt_bits=generate_Bitmap_from_Bits(m_hv_rl_bt_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT);
generate_Pixmap_from_Bits(m_hv_rl_bt_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT,Qt_m_hv_rl_bt_bits);
Qt_m_hv_rl_tb_bits=new QPixmap(MBITMAP_WIDTH,MBITMAP_HEIGHT);
//*Qt_m_hv_rl_tb_bits=generate_Bitmap_from_Bits(m_hv_rl_tb_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT);
generate_Pixmap_from_Bits(m_hv_rl_tb_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT,Qt_m_hv_rl_tb_bits);
Qt_m_vh_lr_bt_bits=new QPixmap(MBITMAP_WIDTH,MBITMAP_HEIGHT);
//*Qt_m_vh_lr_bt_bits=generate_Bitmap_from_Bits(m_vh_lr_bt_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT);
generate_Pixmap_from_Bits(m_vh_lr_bt_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT,Qt_m_vh_lr_bt_bits);
Qt_m_vh_lr_tb_bits=new QPixmap(MBITMAP_WIDTH,MBITMAP_HEIGHT);
//*Qt_m_vh_lr_tb_bits=generate_Bitmap_from_Bits(m_vh_lr_tb_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT);
generate_Pixmap_from_Bits(m_vh_lr_tb_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT,Qt_m_vh_lr_tb_bits);
Qt_m_vh_rl_bt_bits=new QPixmap(MBITMAP_WIDTH,MBITMAP_HEIGHT);
//*Qt_m_vh_rl_bt_bits=generate_Bitmap_from_Bits(m_vh_rl_bt_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT);
generate_Pixmap_from_Bits(m_vh_rl_bt_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT,Qt_m_vh_rl_bt_bits);
Qt_m_vh_rl_tb_bits=new QPixmap(MBITMAP_WIDTH,MBITMAP_HEIGHT);
//*Qt_m_vh_rl_tb_bits=generate_Bitmap_from_Bits(m_vh_rl_tb_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT);
generate_Pixmap_from_Bits(m_vh_rl_tb_bits,5*12,MBITMAP_WIDTH,MBITMAP_HEIGHT,Qt_m_vh_rl_tb_bits);

QPixmap templIcon(82,22);
QPainter templPainter;
QPen pen1(Qt::black);
for (int i=0;i<MAXLINESTYLES;i++)
{
//templIcon.fill(Qt::white);
templIcon.fill(QApplication::palette().window().color());
templPainter.begin(&templIcon);

PenDashPattern[i]=new QVector<qreal>();
	for (int j=0;j<dash_array_length[i];j++)
	*PenDashPattern[i] << dash_array[i][j];
if (i==0)
{
templPainter.setPen(pen1);
templPainter.drawText(10,15,"None");
}
else
{
pen1.setColor(Qt::black);
pen1.setDashPattern(*PenDashPattern[i]);
pen1.setWidth(2);
templPainter.setPen(pen1);
templPainter.drawLine(0,11,82,11);
}
templPainter.end();
LineIcons[i]=new QIcon(templIcon);
LinePixmaps[i]=new QPixmap(templIcon);
}
}

void MainWindow::newFile(void)
{
new_project(NULL);
mainArea->completeRedraw();
}

void MainWindow::Open(void)
{
if (FormOpenProject==NULL)
{
FormOpenProject=new frmIOForm(READ_PROJECT_FORM,this);
connect(FormOpenProject,SIGNAL(newFileSelectedForIO(int,QString,bool,bool,bool)),SLOT(IOrequested(int,QString,bool,bool,bool)));
}
FormOpenProject->init();
FormOpenProject->show();
FormOpenProject->raise();
FormOpenProject->activateWindow();
}

void MainWindow::IOrequested(int type,QString file,bool exists,bool writeable,bool readable)
{
char dummy[file.length()+2];
strcpy(dummy,file.toAscii());
char dummy2[strlen(dummy)+35];
sprintf(dummy2,"Can't stat file %s",dummy);
/*cout << "Ursprung(type)=" << type << endl;
cout << "zu laden=" << dummy << endl;
cout << "Existiert=" << exists << endl;
cout << "Schreibbar=" << writeable << endl;
cout << "Lesbar=" << readable << endl;*/

if (
(readable==false && (type==READ_SET_FORM || type==READ_NETCDF_FORM || type==READ_PROJECT_FORM || type==READ_PARAMETERS) )
||
(writeable==false && exists==true)
)
{ 
    errwin(dummy2);
return;
}
switch (type)
{
case READ_SET_FORM:
;//done separately
break;
case READ_NETCDF_FORM:
;//done separately
break;
case READ_PROJECT_FORM:
if (readable==false)
{
errwin(dummy2);
return;
}
else
{
LoadProject(dummy);
if (FormOpenProject)
FormOpenProject->doCancel();
}
break;
case WRITE_SET_FORM:
;//done separately
break;
case WRITE_PROJECT_FORM:

if (exists==false || (exists==true && writeable==true))
{
save_project(dummy);
FormSaveProject->doCancel();
}

break;
case READ_PARAMETERS:

if (readable==false)
{
    getparms(dummy);
    update_all();
    mainArea->completeRedraw();
}

break;
case WRITE_PARAMETERS:
    int gno;
    FILE *pp;

    if (GetChoice(FormWriteParameters->selParamGraph) == 0) {
        gno = get_cg();
    } else {
        gno = ALL_GRAPHS;
    }

    pp = grace_openw(dummy);
    if (pp != NULL) {
        putparms(gno, pp, 0);
        grace_close(pp);
    }
break;
}
}

void MainWindow::Save(void)
{
    if (strcmp (get_docname(), NONAME) != 0)
    save_project(get_docname());
    else
    SaveAs();
}

void MainWindow::SaveAs(void)
{
if (FormSaveProject==NULL)
{
FormSaveProject=new frmIOForm(WRITE_PROJECT_FORM,this);
connect(FormSaveProject,SIGNAL(newFileSelectedForIO(int,QString,bool,bool,bool)),SLOT(IOrequested(int,QString,bool,bool,bool)));
}
FormSaveProject->init();
FormSaveProject->show();
FormSaveProject->raise();
FormSaveProject->activateWindow();
}

void MainWindow::RevertToSaved(void)
{
QString selectedFile(get_docname());
QFile fileTest(selectedFile);
QFileInfo fileInfo(fileTest);
bool FileExists,isWriteable,isReadable;
if (fileInfo.isFile()==false)
{
FileExists=false;
isWriteable=false;
isReadable=false;
}
else
{
FileExists=fileTest.exists();
isWriteable=fileInfo.isWritable();
isReadable=fileInfo.isReadable();
}
IOrequested(READ_PROJECT_FORM,selectedFile,FileExists,isWriteable,isReadable);
}

void MainWindow::Exit(void)
{
write_settings();
int ret=bailout();
    if (ret==1)
    {
    initNodes();//to clear all Contents of the undo-list
    qApp->exit(0);
    }
}

void MainWindow::PrintSetup(void)
{
if (FormDeviceSetup==NULL)
{
FormDeviceSetup=new frmDeviceSetup(this);
}
FormDeviceSetup->show();
//FormDeviceSetup->devices_item->setCurrentIndex(find_dev_nr("PS")-1);//'-1' because dummy-device not shown
FormDeviceSetup->devices_item->setCurrentIndex(stdOutputFormat);
FormDeviceSetup->raise();
FormDeviceSetup->activateWindow();
}

void MainWindow::Print(void)
{
    do_hardcopy();
}

void MainWindow::DataSets(void)
{
if (FormDataSetProperties==NULL)
{
FormDataSetProperties=new frmDataSetProperties(this);
}
FormDataSetProperties->init();
FormDataSetProperties->show();
FormDataSetProperties->raise();
FormDataSetProperties->activateWindow();
}

void MainWindow::SetOperations(void)
{
if (FormSetOPS==NULL)
{
FormSetOPS=new frmSetOperations(this);
}
FormSetOPS->init();
FormSetOPS->show();
FormSetOPS->raise();
FormSetOPS->activateWindow();
}

void MainWindow::ArrangeGraphs(void)
{
if (FormArrangeGraphs==NULL)
{
FormArrangeGraphs=new frmArrangeGraphs(this);
}
FormArrangeGraphs->init();
FormArrangeGraphs->show();
FormArrangeGraphs->raise();
FormArrangeGraphs->activateWindow();
}

void MainWindow::OverlayGraphs(void)
{
if (FormOverlayGraphs==NULL)
{
FormOverlayGraphs=new frmOverlayGraphs(this);
}
FormOverlayGraphs->init();
FormOverlayGraphs->show();
FormOverlayGraphs->raise();
FormOverlayGraphs->activateWindow();
}

void MainWindow::AutoscaleGraphs(void)
{
if (FormAutoScaleGraphs==NULL)
{
FormAutoScaleGraphs=new frmAutoscaleGraphs(this);
}
FormAutoScaleGraphs->init();
FormAutoScaleGraphs->show();
FormAutoScaleGraphs->raise();
FormAutoScaleGraphs->activateWindow();
}

void MainWindow::HotLinks(void)
{
if (FormHotLinks==NULL)
{
FormHotLinks=new frmHotLinks(this);
}
FormHotLinks->init();
FormHotLinks->show();
FormHotLinks->raise();
FormHotLinks->activateWindow();
}

void MainWindow::SetLocFixPoint(void)
{
set_action(SEL_POINT);
}

void MainWindow::ClearLocFixPoint(void)
{
    GLocator locator;

    get_graph_locator(get_cg(), &locator);
    locator.pointset = FALSE;
    SaveLocatorFixPoint(get_cg());
    set_graph_locator(get_cg(), &locator);
    LocatorFixPointModified(get_cg());
    mainArea->completeRedraw();
}

void MainWindow::LocProp(void)
{
if (FormLocatorProps==NULL)
{
FormLocatorProps=new frmLocatorProps(this);
}
FormLocatorProps->init();
FormLocatorProps->show();
FormLocatorProps->raise();
FormLocatorProps->activateWindow();
}

void MainWindow::Preferences(void)
{
if (FormPreferences==NULL)
{
FormPreferences=new frmPreferences(this);
}
FormPreferences->init();
FormPreferences->show();
FormPreferences->raise();
FormPreferences->activateWindow();
}

void MainWindow::RegionsStatus(void)
{
if (FormRegionStatus==NULL)
{
FormRegionStatus=new frmRegionStatus(this);
}
FormRegionStatus->init();
FormRegionStatus->show();
FormRegionStatus->raise();
FormRegionStatus->activateWindow();
}

void MainWindow::RegionsDefine(void)
{
if (FormDefineRegion==NULL)
{
FormDefineRegion=new frmRegions(DEFINEREGIONWINDOW,this);
}
FormDefineRegion->init();
FormDefineRegion->show();
FormDefineRegion->raise();
FormDefineRegion->activateWindow();
}

void MainWindow::RegionsClear(void)
{
if (FormClearRegion==NULL)
{
FormClearRegion=new frmRegions(CLEARREGIONWINDOW,this);
}
FormClearRegion->init();
FormClearRegion->show();
FormClearRegion->raise();
FormClearRegion->activateWindow();
}

void MainWindow::RegionsReportOn(void)
{
if (FormReportRegion==NULL)
{
FormReportRegion=new frmRegions(REPORTREGIONWINDOW,this);
}
FormReportRegion->init();
FormReportRegion->show();
FormReportRegion->raise();
FormReportRegion->activateWindow();
}

void MainWindow::DataSetOperations(void)
{
if (FormSetOperations==NULL)
{
FormSetOperations=new frmSetOp(this);
}
FormSetOperations->init();
FormSetOperations->show();
FormSetOperations->raise();
FormSetOperations->activateWindow();
}

void MainWindow::FeatureExtraction(void)
{
if (FormFeatureExtraction==NULL)
{
FormFeatureExtraction=new frmFeatureExtract(this);
}
FormFeatureExtraction->init();
FormFeatureExtraction->show();
FormFeatureExtraction->raise();
FormFeatureExtraction->activateWindow();
}

void MainWindow::ImportAscii(void)
{
if (FormReadSets==NULL)
{
FormReadSets=new frmIOForm(READ_SET_FORM,this);
}
FormReadSets->init();
FormReadSets->show();
FormReadSets->raise();
FormReadSets->activateWindow();
}

void MainWindow::ImportBinary(void)
{
if (FormBinaryImportFilter==NULL)
{
FormBinaryImportFilter=new frmBinaryFormatInput(this);
}
FormBinaryImportFilter->init();
FormBinaryImportFilter->show();
FormBinaryImportFilter->raise();
FormBinaryImportFilter->activateWindow();
/*if (FormReadBinary==NULL)
{
FormReadBinary=new frmIOForm(READ_BINARY_FILE,this);
}
FormReadBinary->init();
FormReadBinary->show();
FormReadBinary->raise();
FormReadBinary->activateWindow();*/
}

void MainWindow::ImportNetCDF(void)
{
///anything missing!!!
if (FormNetCDF==NULL)
{
FormNetCDF=new frmNetCDF(this);
}
FormNetCDF->init();
FormNetCDF->show();
FormNetCDF->raise();
FormNetCDF->activateWindow();
}

void MainWindow::ExportAscii(void)
{
if (FormWriteSets==NULL)
{
FormWriteSets=new frmIOForm(WRITE_SET_FORM,this);
}
FormWriteSets->init();
FormWriteSets->show();
FormWriteSets->raise();
FormWriteSets->activateWindow();
}

void MainWindow::ExportBinary(void)
{
if (FormWriteBinary==NULL)
{
FormWriteBinary=new frmIOForm(WRITE_BINARY_FILE,this);
}
FormWriteBinary->init();
FormWriteBinary->show();
FormWriteBinary->raise();
FormWriteBinary->activateWindow();
}

void MainWindow::EvaluateExpr(void)
{
if (FormEvalExpr==NULL)
{
FormEvalExpr=new frmEvalExpr(this,this);
}
FormEvalExpr->init();
FormEvalExpr->show();
FormEvalExpr->raise();
FormEvalExpr->activateWindow();
}

void MainWindow::Histograms(void)
{
if (FormHistograms==NULL)
{
FormHistograms=new frmInterpolation(HISTOGRAMSWINDOW,this);
}
FormHistograms->init();
FormHistograms->show();
FormHistograms->raise();
FormHistograms->activateWindow();
}

void MainWindow::Fourier(void)
{
if (FormFourier==NULL)
{
FormFourier=new frmFourier(this);
}

FormFourier->init();
FormFourier->show();
FormFourier->raise();
FormFourier->activateWindow();
}

void MainWindow::Fourier2(void)
{
    if (FormFourier2==NULL)
    {
    FormFourier2=new frmFourier2(this);
    }

    FormFourier2->init();
    FormFourier2->show();
    FormFourier2->raise();
    FormFourier2->activateWindow();
}

void MainWindow::RunningAverages(void)
{
if (FormAverages==NULL)
{
FormAverages=new frmSmallCalc(AVERAGESWINDOW,this);
}
FormAverages->init();
FormAverages->show();
FormAverages->raise();
FormAverages->activateWindow();
}

void MainWindow::Differences(void)
{
if (FormDifferences==NULL)
{
FormDifferences=new frmSmallCalc(DIFFERENCESWINDOW,this);
}
FormDifferences->init();
FormDifferences->show();
FormDifferences->raise();
FormDifferences->activateWindow();
}

void MainWindow::SeasonalDiff(void)
{
if (FormSeasonDiff==NULL)
{
FormSeasonDiff=new frmSmallCalc(SEASONALWINDOW,this);
}
FormSeasonDiff->init();
FormSeasonDiff->show();
FormSeasonDiff->raise();
FormSeasonDiff->activateWindow();
}

void MainWindow::Integration(void)
{
if (FormIntegration==NULL)
{
FormIntegration=new frmSmallCalc(INTEGRATIONWINDOW,this);
}
FormIntegration->init();
FormIntegration->show();
FormIntegration->raise();
FormIntegration->activateWindow();
}

void MainWindow::Interpolation(void)
{
if (FormInterpolation==NULL)
{
FormInterpolation=new frmInterpolation(INTERPOLATIONWINDOW,this);
}
FormInterpolation->init();
FormInterpolation->show();
FormInterpolation->raise();
FormInterpolation->activateWindow();
}

void MainWindow::Regression(void)
{
if (FormRegression==NULL)
{
FormRegression=new frmSmallCalc(REGRESSIONWINDOW,this);
}
FormRegression->init();
FormRegression->show();
FormRegression->raise();
FormRegression->activateWindow();
}

void MainWindow::NonLinCurveFitting(void)
{
if (FormNonlinCurveFit==NULL)
{
FormNonlinCurveFit=new frmNonlinCurveFit(this);
}
FormNonlinCurveFit->init();
FormNonlinCurveFit->show();
FormNonlinCurveFit->raise();
FormNonlinCurveFit->activateWindow();
}

void MainWindow::Correlation(void)
{
if(FormCorrelation==NULL)
{
FormCorrelation=new frmCorrelation(CORRELATIONWINDOW,this);
}
FormCorrelation->init();
FormCorrelation->show();
FormCorrelation->raise();
FormCorrelation->activateWindow();
}

void MainWindow::DigitalFilter(void)
{
if (FormDigitalFilter==NULL)
{
FormDigitalFilter=new frmCorrelation(FILTERWINDOW,this);
}
FormDigitalFilter->init();
FormDigitalFilter->show();
FormDigitalFilter->raise();
FormDigitalFilter->activateWindow();
}

void MainWindow::LinConvolution(void)
{
if (FormConvolution==NULL)
{
FormConvolution=new frmCorrelation(CONVOLUTIONWINDOW,this);
}
FormConvolution->init();
FormConvolution->show();
FormConvolution->raise();
FormConvolution->activateWindow();
}

void MainWindow::GeomTransform(void)
{
if (FormGeometricTransform==NULL)
{
FormGeometricTransform=new frmTransform(GEOMETRICWINDOW,this);
}
FormGeometricTransform->init();
FormGeometricTransform->show();
FormGeometricTransform->raise();
FormGeometricTransform->activateWindow();
}

void MainWindow::SamplePoints(void)
{
if (FormSamplePoints==NULL)
{
FormSamplePoints=new frmTransform(SAMPLEPOINTSWINDOW,this);
}
FormSamplePoints->init();
FormSamplePoints->show();
FormSamplePoints->raise();
FormSamplePoints->activateWindow();
}

void MainWindow::PruneData(void)
{
if (FormPruneData==NULL)
{
FormPruneData=new frmTransform(PRUNEWINDOW,this);
}
FormPruneData->init();
FormPruneData->show();
FormPruneData->raise();
FormPruneData->activateWindow();
}

void MainWindow::PlotAppearance(void)
{
if (FormPlotAppearance==NULL)
{
FormPlotAppearance=new frmPlotAppearance(this);
}
FormPlotAppearance->init();
FormPlotAppearance->show();
FormPlotAppearance->raise();
FormPlotAppearance->activateWindow();
}

void MainWindow::GraphAppearance(void)
{
if (FormGraphAppearance==NULL)
{
FormGraphAppearance=new frmGraphApp(this);
}
FormGraphAppearance->init();
FormGraphAppearance->show();
FormGraphAppearance->raise();
FormGraphAppearance->activateWindow();
}

void MainWindow::SetAppearance(void)
{
if (FormSetAppearance==NULL)
{
FormSetAppearance=new frmSetAppearance(this);
}
FormSetAppearance->init();
FormSetAppearance->show();
FormSetAppearance->raise();
FormSetAppearance->activateWindow();
}

void MainWindow::AxisProperties(void)
{
if (FormAxisProperties==NULL)
{
FormAxisProperties=new frmAxisProp(this);
}
FormAxisProperties->create_axes_dialog(0);
FormAxisProperties->show();
FormAxisProperties->raise();
FormAxisProperties->activateWindow();
}

void MainWindow::LoadParameters(void)
{
if (FormReadParameters==NULL)
{
FormReadParameters=new frmIOForm(READ_PARAMETERS,this);
connect(FormReadParameters,SIGNAL(newFileSelectedForIO(int,QString,bool,bool,bool)),SLOT(IOrequested(int,QString,bool,bool,bool)));
}
FormReadParameters->init();
FormReadParameters->show();
FormReadParameters->raise();
FormReadParameters->activateWindow();
}

void MainWindow::SaveParameters(void)
{
if (FormWriteParameters==NULL)
{
FormWriteParameters=new frmIOForm(WRITE_PARAMETERS,this);
connect(FormWriteParameters,SIGNAL(newFileSelectedForIO(int,QString,bool,bool,bool)),SLOT(IOrequested(int,QString,bool,bool,bool)));
}
FormWriteParameters->init();
FormWriteParameters->show();
FormWriteParameters->raise();
FormWriteParameters->activateWindow();
}

void MainWindow::ShowLocBar(void)
{
	if (actShowLocBar->isChecked()==FALSE)
	{
	statLocBar->hide();
	mainGrid->setRowMinimumHeight(1,0);
	}
	else
	{
	statLocBar->show();
	mainGrid->setRowMinimumHeight(1,stdBarHeight);
	}
}

void MainWindow::ShowStatusBar(void)
{
	if (actShowStatusBar->isChecked()==FALSE)
	{
	statusBar->hide();
	mainGrid->setRowMinimumHeight(4,0);
	}
	else
	{
	statusBar->show();
	mainGrid->setRowMinimumHeight(4,stdBarHeight);
	}
}

void MainWindow::ShowToolBar(void)
{
	if (actShowToolBar->isChecked()==FALSE)
	{
	toolBar1->hide();
	toolBar2->hide();
	mainGrid->setColumnMinimumWidth(0,0);
	}
	else
	{
	toolBar1->show();
	toolBar2->show();
	mainGrid->setColumnMinimumWidth(0,70);
	}
}

void MainWindow::PageSetup(void)
{
if (FormDeviceSetup==NULL)
{
FormDeviceSetup=new frmDeviceSetup(this);
}
FormDeviceSetup->show();
FormDeviceSetup->devices_item->setCurrentIndex(find_dev_nr("X11"));
FormDeviceSetup->raise();
FormDeviceSetup->activateWindow();
}

void MainWindow::Redraw(void)
{
mainArea->completeRedraw();
}

void MainWindow::UpdateAll(void)
{
update_all();
}

void MainWindow::Commands(void)
{
if (FormCommands==NULL)
{
FormCommands=new frmCommands(this);
}
FormCommands->show();
FormCommands->raise();
FormCommands->activateWindow();
}

void MainWindow::PointExplorer(void)
{
if (FormPointExplorer==NULL)
{
FormPointExplorer=new frmPointExplorer(this);
}
FormPointExplorer->init();
FormPointExplorer->show();
FormPointExplorer->resize(FormPointExplorer->width(),FormPointExplorer->width()/3);
FormPointExplorer->raise();
FormPointExplorer->activateWindow();
}

void MainWindow::DrawingObjects(void)
{
if (FormDrawObjects==NULL)
{
FormDrawObjects=new frmDrawObjects(this);
}
FormDrawObjects->show();
FormDrawObjects->raise();
FormDrawObjects->activateWindow();
}

void MainWindow::FontTool(void)
{
if (FormFontTool==NULL)
{
FormFontTool=new frmFontTool(this);
}
FormFontTool->show();
FormFontTool->raise();
FormFontTool->activateWindow();
}

void MainWindow::Console(void)
{
if (FormConsole==NULL)
{
FormConsole=new frmConsole(this);
}
FormConsole->show();
FormConsole->raise();
FormConsole->activateWindow();
}

void MainWindow::HelpOnContext(void)
{
setCursor(QCursor(Qt::WhatsThisCursor));
}

void MainWindow::HelpUsersGuide(void)
{
HelpCB("doc/UsersGuide.html");
}

void MainWindow::HelpTutorial(void)
{
HelpCB("doc/Tutorial.html");
}

void MainWindow::HelpFAQ(void)
{
HelpCB("doc/FAQ.html");
}

void MainWindow::HelpChanges(void)
{
HelpCB("doc/CHANGES.html");
}

void MainWindow::HelpComments(void)
{
char buf[256];
sprintf(buf,"http://plasma-gate.weizmann.ac.il/Grace/comments.phtml?version_id=%ld",bi_version_id());
HelpCB(buf);
}

void MainWindow::HelpLicense(void)
{
HelpCB("doc/GPL.html");
}

void MainWindow::HelpAbout(void)
{
if (FormAbout==NULL)
{
FormAbout=new frmAbout(this);
}
FormAbout->show();
FormAbout->raise();
FormAbout->activateWindow();
}

void MainWindow::HelpOpenExample(int i)
{
if (i<0 || i>nr_of_Examples) return;
char buf[2056];
char buf2[2056];
char ex_name[2056];
strcpy(ex_name,examplesFiles[i].toAscii());
sprintf(buf, "%s/../examples/%s",qt_grace_exe_dir, ex_name);
sprintf(buf2, "%s/../examples",qt_grace_exe_dir);
set_workingdir(buf2);
QFile file(buf);
if (!file.exists())
cout << "Example file " << buf <<  " does not exist!" << endl;
else
load_project_file(buf, FALSE);
initNodes();
mainArea->completeRedraw();
mainArea->setGeometry(mainArea->x(),mainArea->y(),mainArea->width(),mainArea->height());
//setGeometry(x(),y(),width(),height());
///xdrawgraph();
}

void MainWindow::doDraw(void)
{
mainArea->completeRedraw();
}

void MainWindow::doZoom(void)
{
set_action(ZOOM_1ST);
}

void MainWindow::doAutoScale(void)
{
autoscale_proc(AUTOSCALE_XY);
}

void MainWindow::doZz(void)
{
graph_zoom_proc(GZOOM_EXPAND);
}

void MainWindow::dozz(void)
{
graph_zoom_proc(GZOOM_SHRINK);
}

void MainWindow::doLeft(void)
{
graph_scroll_proc(GSCROLL_LEFT);
}

void MainWindow::doRight(void)
{
graph_scroll_proc(GSCROLL_RIGHT);
}

void MainWindow::doUp(void)
{
graph_scroll_proc(GSCROLL_UP);
}

void MainWindow::doDown(void)
{
graph_scroll_proc(GSCROLL_DOWN);
}

void MainWindow::doAutoT(void)
{
    char dummy[256];
    SaveTickmarksStatesPrevious(X_AXIS,Y_AXIS,get_cg(),get_cg());
        autotick_axis(get_cg(), ALL_AXES);
        if (FormAxisProperties!=NULL)
        FormAxisProperties->update_ticks(get_cg());
    TickmarksModified(X_AXIS,Y_AXIS,get_cg(),get_cg());
    sprintf(dummy,"Autotick axes [G%d]",get_cg());
    addAditionalDescriptionToLastNode(-1,QString(dummy),QString(),0);
        mainArea->completeRedraw();
}

void MainWindow::doAutoO(void)
{
    set_action(DO_NOTHING);
    set_action(AUTO_NEAREST);
}

void MainWindow::doZX(void)
{
set_action(ZOOMX_1ST);
}

void MainWindow::doZY(void)
{
set_action(ZOOMY_1ST);
}

void MainWindow::doAX(void)
{
autoscale_proc(AUTOSCALE_X);
}

void MainWindow::doAY(void)
{
autoscale_proc(AUTOSCALE_Y);
}

void MainWindow::doPZ(void)
{
world_stack_proc(WSTACK_PUSH_ZOOM);
}

void MainWindow::doPu(void)
{
world_stack_proc(WSTACK_PUSH);
}

void MainWindow::doPo(void)
{
world_stack_proc(WSTACK_POP);
}

void MainWindow::doCy(void)
{
world_stack_proc(WSTACK_CYCLE);
}

void MainWindow::doExit(void)
{
Exit();
}

void MainWindow::CreateActions(void)
{
//Actions for File menu
actNew = new QAction(tr("&New"), this);
actNew->setShortcut(tr("Ctrl+N"));
actNew->setStatusTip(tr("Create a new file"));
connect(actNew, SIGNAL(triggered()), this, SLOT(newFile()));
actOpen= new QAction(tr("&Open"), this);
actOpen->setShortcut(tr("Ctrl+O"));
actOpen->setStatusTip(tr("Open an existing file"));
connect(actOpen, SIGNAL(triggered()), this, SLOT(Open()));
actSave= new QAction(tr("&Save"), this);
actSave->setShortcut(tr("Ctrl+S"));
actSave->setStatusTip(tr("Save current data"));
connect(actSave, SIGNAL(triggered()), this, SLOT(Save()));
actSaveAs= new QAction(tr("S&ave As..."), this);
actSaveAs->setStatusTip(tr("Save to file new file"));
connect(actSaveAs, SIGNAL(triggered()), this, SLOT(SaveAs()));
actRevert= new QAction(tr("Re&vert to Saved"), this);
actRevert->setStatusTip(tr("Revert to version last saved"));
connect(actRevert, SIGNAL(triggered()), this, SLOT(RevertToSaved()));
actPrint= new QAction(tr("&Print"), this);
actPrint->setShortcut(tr("Ctrl+P"));
actPrint->setStatusTip(tr("Print"));
connect(actPrint, SIGNAL(triggered()), this, SLOT(Print()));
actPrintSetup= new QAction(tr("Prin&t Setup..."), this);
actPrintSetup->setStatusTip(tr("Adjust print properties"));
connect(actPrintSetup, SIGNAL(triggered()), this, SLOT(PrintSetup()));
actExit= new QAction(tr("E&xit"), this);
actExit->setShortcut(tr("Ctrl+Q"));
actExit->setStatusTip(tr("Exit program"));
connect(actExit, SIGNAL(triggered()), this, SLOT(Exit()));

//Actions for Edit menu
actDataSets= new QAction(tr( "&Data sets..."), this);
//->setStatusTip(tr());
connect(actDataSets, SIGNAL(triggered()), this, SLOT(DataSets()));
actSetOperations= new QAction(tr("Set &operations..." ), this);
connect(actSetOperations, SIGNAL(triggered()), this, SLOT(SetOperations()));
actArrangeGraphs= new QAction(tr( "A&rrange graphs..."), this);
connect(actArrangeGraphs, SIGNAL(triggered()), this, SLOT(ArrangeGraphs()));
actOverlayGraphs= new QAction(tr("&Overlay graphs..." ), this);
connect(actOverlayGraphs, SIGNAL(triggered()), this, SLOT(OverlayGraphs()));
actAutoscaleGraphs= new QAction(tr("&Autoscale graphs..." ), this);
connect(actAutoscaleGraphs, SIGNAL(triggered()), this, SLOT(AutoscaleGraphs()));
actRegionsStatus= new QAction(tr("&Status..." ), this);
connect(actRegionsStatus, SIGNAL(triggered()), this, SLOT(RegionsStatus()));
actRegionsDefine= new QAction(tr("&Define..." ), this);
connect(actRegionsDefine, SIGNAL(triggered()), this, SLOT(RegionsDefine()));
actRegionsClear= new QAction(tr("&Clear..." ), this);
connect(actRegionsClear, SIGNAL(triggered()), this, SLOT(RegionsClear()));
actRegionsReportOn= new QAction(tr("&Report on..." ), this);
connect(actRegionsReportOn, SIGNAL(triggered()), this, SLOT(RegionsReportOn()));
actHotLinks= new QAction(tr( "Hot &links..."), this);
connect(actHotLinks, SIGNAL(triggered()), this, SLOT(HotLinks()));
actSetLocFixPoint= new QAction(tr("Set locator &fixed point" ), this);
connect(actSetLocFixPoint, SIGNAL(triggered()), this, SLOT(SetLocFixPoint()));
actClearLocFixPoint= new QAction(tr( "&Clear locator fixed point"), this);
connect(actClearLocFixPoint, SIGNAL(triggered()), this, SLOT(ClearLocFixPoint()));
actLocProp= new QAction(tr("Locator &props..." ), this);
connect(actLocProp, SIGNAL(triggered()), this, SLOT(LocProp()));
actPreferences= new QAction(tr("P&references..." ), this);
connect(actPreferences, SIGNAL(triggered()), this, SLOT(Preferences()));

//Actions for the Data menu
actDataSetOperations= new QAction(tr("Data set &operations..." ), this);
connect(actDataSetOperations, SIGNAL(triggered()), this, SLOT(DataSetOperations()));
actFeatureExtraction= new QAction(tr("Feature e&xtraction..." ), this);
connect(actFeatureExtraction, SIGNAL(triggered()), this, SLOT(FeatureExtraction()));
actExportAscii= new QAction(tr("&ASCII..." ), this);
connect(actExportAscii, SIGNAL(triggered()), this, SLOT(ExportAscii()));
actExportBinary= new QAction(tr("&Binary..." ), this);
connect(actExportBinary, SIGNAL(triggered()), this, SLOT(ExportBinary()));
actImportNetCDF= new QAction(tr("&NetCDF..." ), this);
connect(actImportNetCDF, SIGNAL(triggered()), this, SLOT(ImportNetCDF()));
actImportAscii= new QAction(tr("&ASCII..." ), this);
connect(actImportAscii, SIGNAL(triggered()), this, SLOT(ImportAscii()));
actImportBinary= new QAction(tr("&Binary..." ), this);
connect(actImportBinary, SIGNAL(triggered()), this, SLOT(ImportBinary()));
actEvaluateExpr= new QAction(tr("&Evaluate expression..." ), this);
connect(actEvaluateExpr, SIGNAL(triggered()), this, SLOT(EvaluateExpr()));
actHistograms= new QAction(tr("&Histograms..." ), this);
connect(actHistograms, SIGNAL(triggered()), this, SLOT(Histograms()));
actFourier= new QAction(tr("Fo&urier transforms..." ), this);
connect(actFourier, SIGNAL(triggered()), this, SLOT(Fourier()));
actFourier2= new QAction(tr("Filters..." ), this);
connect(actFourier2, SIGNAL(triggered()), this, SLOT(Fourier2()));

actRunningAverages= new QAction(tr("&Running &averages..." ), this);
connect(actRunningAverages, SIGNAL(triggered()), this, SLOT(RunningAverages()));
actDifferences= new QAction(tr("&Differences..." ), this);
connect(actDifferences, SIGNAL(triggered()), this, SLOT(Differences()));
actSeasonalDiff= new QAction(tr("Seas&onal differences..." ), this);
connect(actSeasonalDiff, SIGNAL(triggered()), this, SLOT(SeasonalDiff()));
actIntegration= new QAction(tr("&Integration..." ), this);
connect(actIntegration, SIGNAL(triggered()), this, SLOT(Integration()));
actInterpolation= new QAction(tr("In&terpolation/splines..." ), this);
connect(actInterpolation, SIGNAL(triggered()), this, SLOT(Interpolation()));
actRegression= new QAction(tr( "&Regression..."), this);
connect(actRegression, SIGNAL(triggered()), this, SLOT(Regression()));
actNonLinCurveFitting= new QAction(tr("&Non-linear curve fitting..." ), this);
connect(actNonLinCurveFitting, SIGNAL(triggered()), this, SLOT(NonLinCurveFitting()));
actCorrelation= new QAction(tr("&Correlation/covariance..." ), this);
connect(actCorrelation, SIGNAL(triggered()), this, SLOT(Correlation()));
actDigitalFilter= new QAction(tr("Digital &filter..." ), this);
connect(actDigitalFilter, SIGNAL(triggered()), this, SLOT(DigitalFilter()));
actLinConvolution= new QAction(tr( "Linear con&volution..."), this);
connect(actLinConvolution, SIGNAL(triggered()), this, SLOT(LinConvolution()));
actGeomTransform= new QAction(tr("&Geometric transforms..." ), this);
connect(actGeomTransform, SIGNAL(triggered()), this, SLOT(GeomTransform()));
actSamplePoints= new QAction(tr("Sa&mple points..." ), this);
connect(actSamplePoints, SIGNAL(triggered()), this, SLOT(SamplePoints()));
actPruneData= new QAction(tr("&Prune data..." ), this);
connect(actPruneData, SIGNAL(triggered()), this, SLOT(PruneData()));

//Actions for the Plot menu
actPlotAppearance= new QAction(tr("Plot a&ppearance..." ), this);
connect(actPlotAppearance, SIGNAL(triggered()), this, SLOT(PlotAppearance()));
actGraphAppearance= new QAction(tr("&Graph appearance..." ), this);
connect(actGraphAppearance, SIGNAL(triggered()), this, SLOT(GraphAppearance()));
actSetAppearance= new QAction(tr("&Set appearance..." ), this);
connect(actSetAppearance, SIGNAL(triggered()), this, SLOT(SetAppearance()));
actAxisProperties= new QAction(tr("A&xis properties..." ), this);
connect(actAxisProperties, SIGNAL(triggered()), this, SLOT(AxisProperties()));
actLoadParameters= new QAction(tr("&Load parameters..." ), this);
connect(actLoadParameters, SIGNAL(triggered()), this, SLOT(LoadParameters()));
actSaveParameters= new QAction(tr( "&Save parameters..."), this);
connect(actSaveParameters, SIGNAL(triggered()), this, SLOT(SaveParameters()));

//Actions for the View menu
actShowLocBar= new QAction(tr("Show locator bar" ), this);
actShowLocBar->setCheckable(TRUE);
actShowLocBar->setChecked(TRUE);
connect(actShowLocBar, SIGNAL(triggered()), this, SLOT(ShowLocBar()));
actShowStatusBar= new QAction(tr("Show status bar" ), this);
actShowStatusBar->setCheckable(true);
actShowStatusBar->setChecked(TRUE);
connect(actShowStatusBar, SIGNAL(triggered()), this, SLOT(ShowStatusBar()));
actShowToolBar= new QAction(tr("Show tool bar" ), this);
actShowToolBar->setCheckable(TRUE);
actShowToolBar->setChecked(TRUE);
connect(actShowToolBar, SIGNAL(triggered()), this, SLOT(ShowToolBar()));
actPageSetup= new QAction(tr("&PageSetup" ), this);
connect(actPageSetup, SIGNAL(triggered()), this, SLOT(PageSetup()));
actRedraw= new QAction(tr("&Redraw" ), this);
connect(actRedraw, SIGNAL(triggered()), this, SLOT(Redraw()));
actUpdateAll= new QAction(tr("&Update all" ), this);
connect(actUpdateAll, SIGNAL(triggered()), this, SLOT(UpdateAll()));

//Actions for the Window menu
actCommands= new QAction(tr("&Commands" ), this);
connect(actCommands, SIGNAL(triggered()), this, SLOT(Commands()));
actPointExplorer= new QAction(tr("&Point explorer" ), this);
connect(actPointExplorer, SIGNAL(triggered()), this, SLOT(PointExplorer()));
actDrawingObjects= new QAction(tr("&Drawing objects" ), this);
connect(actDrawingObjects, SIGNAL(triggered()), this, SLOT(DrawingObjects()));
actFontTool= new QAction(tr("&Font tool" ), this);
connect(actFontTool, SIGNAL(triggered()), this, SLOT(FontTool()));
actConsole= new QAction(tr("&Console" ), this);
connect(actConsole, SIGNAL(triggered()), this, SLOT(Console()));

//Undo-Actions
actUndo= new QAction(tr("&UnDo" ), this);
actUndo->setShortcut(tr("Ctrl+Z"));
connect(actUndo, SIGNAL(triggered()), this, SLOT(doUndo()));
actRedo= new QAction(tr("&ReDo" ), this);
actRedo->setShortcut(tr("Shift+Ctrl+Z"));
connect(actRedo, SIGNAL(triggered()), this, SLOT(doRedo()));
actUndoList= new QAction(tr("UndoList" ), this);
connect(actUndoList, SIGNAL(triggered()), this, SLOT(doUndoList()));

//Actions for the Help menu
actHelpOnContext= new QAction(tr("On conte&xt" ), this);
actHelpOnContext->setShortcut(tr("Shift+F1"));
connect(actHelpOnContext, SIGNAL(triggered()), this, SLOT(HelpOnContext()));
actHelpUsersGuide= new QAction(tr("User's &Guide" ), this);
connect(actHelpUsersGuide, SIGNAL(triggered()), this, SLOT(HelpUsersGuide()));
actHelpTutorial= new QAction(tr( "&Tutorial"), this);
connect(actHelpTutorial, SIGNAL(triggered()), this, SLOT(HelpTutorial()));
actHelpFAQ= new QAction(tr( "FA&Q"), this);
connect(actHelpFAQ, SIGNAL(triggered()), this, SLOT(HelpFAQ()));
actHelpChanges= new QAction(tr("&Changes" ), this);
connect(actHelpChanges, SIGNAL(triggered()), this, SLOT(HelpChanges()));
actHelpComments= new QAction(tr("Co&mments" ), this);
connect(actHelpComments, SIGNAL(triggered()), this, SLOT(HelpComments()));
actHelpLicense= new QAction(tr("License terms" ), this);
connect(actHelpLicense, SIGNAL(triggered()), this, SLOT(HelpLicense()));
actHelpAbout= new QAction(tr("&About..." ), this);
connect(actHelpAbout, SIGNAL(triggered()), this, SLOT(HelpAbout()));

//the Examples
nr_of_Example_Menues=8;
ExampleMenuNames[0]=tr("General &intro");
ExampleMenuNames[1]=tr("XY &graphs");
ExampleMenuNames[2]=tr("XY &charts");
ExampleMenuNames[3]=tr("&Polar graphs");
ExampleMenuNames[4]=tr("P&ie charts");
ExampleMenuNames[5]=tr("&Special set presentations");
ExampleMenuNames[6]=tr("&Type setting");
ExampleMenuNames[7]=tr("Calc&ulus");
nr_of_Example_Menu_Entries[0]=10;
ExampleMenuEntries[0][0]=tr("Explain");
ExampleMenuEntries[0][1]=tr("Properties");
ExampleMenuEntries[0][2]=tr("Axes");
ExampleMenuEntries[0][3]=tr("Fonts");
ExampleMenuEntries[0][4]=tr("Arrows");
ExampleMenuEntries[0][5]=tr("Symbols and lines");
ExampleMenuEntries[0][6]=tr("Fills");
ExampleMenuEntries[0][7]=tr("World stack");
ExampleMenuEntries[0][8]=tr("Insert graphs");
ExampleMenuEntries[0][9]=tr("Many graphs");
nr_of_Example_Menu_Entries[1]=11;
ExampleMenuEntries[1][0]=tr("Log scale");
ExampleMenuEntries[1][1]=tr("Log2 scale");
ExampleMenuEntries[1][2]=tr("Log2/Log scale");
ExampleMenuEntries[1][3]=tr("Logit scale");
ExampleMenuEntries[1][4]=tr("Reciprocal scale");
ExampleMenuEntries[1][5]=tr("Error bars");
ExampleMenuEntries[1][6]=tr("Data/time axis formats");
ExampleMenuEntries[1][7]=tr("Australia map");
ExampleMenuEntries[1][8]=tr("A CO2 analysis");
ExampleMenuEntries[1][9]=tr("Motif statistics");
ExampleMenuEntries[1][10]=tr("Spectrum");
nr_of_Example_Menu_Entries[2]=4;
ExampleMenuEntries[2][0]=tr("Bar chart");
ExampleMenuEntries[2][1]=tr("Stacked bar");
ExampleMenuEntries[2][2]=tr("Bar chart with error");
ExampleMenuEntries[2][3]=tr("Different charts");
nr_of_Example_Menu_Entries[3]=1;
ExampleMenuEntries[3][0]=tr("Polar graph");
nr_of_Example_Menu_Entries[4]=1;
ExampleMenuEntries[4][0]=tr("Pie chart");
nr_of_Example_Menu_Entries[5]=7;
ExampleMenuEntries[5][0]=tr("HILO");
ExampleMenuEntries[5][1]=tr("XY Radius");
ExampleMenuEntries[5][2]=tr("XYZ");
ExampleMenuEntries[5][3]=tr("Box plot");
ExampleMenuEntries[5][4]=tr("Vector map");
ExampleMenuEntries[5][5]=tr("XY size");
ExampleMenuEntries[5][6]=tr("XY color");
nr_of_Example_Menu_Entries[6]=3;
ExampleMenuEntries[6][0]=tr("Simple");
ExampleMenuEntries[6][1]=tr("Tex transforms");
ExampleMenuEntries[6][2]=tr("Advanced");
nr_of_Example_Menu_Entries[7]=1;
ExampleMenuEntries[7][0]=tr("Non-linear fit");

int numbers=0;//counts the different Examples

for (int i=0;i<nr_of_Example_Menues;i++)
{
example_menues[i]=new QMenu(ExampleMenuNames[i],this);
example_menues[i]->setTearOffEnabled(TRUE);
	for (int j=0;j<nr_of_Example_Menu_Entries[i];j++)
	{
	act_examples[i][j]=new QAction(ExampleMenuEntries[i][j], this);
	connect(act_examples[i][j], SIGNAL(triggered()), helpMapper, SLOT(map()));
	helpMapper->setMapping(act_examples[i][j],numbers);
	numbers++;
	example_menues[i]->addAction(act_examples[i][j]);
	}
}
nr_of_Examples=numbers;

examplesFiles[0]=QString("explain.agr");
examplesFiles[1]=QString("props.agr");
examplesFiles[2]=QString("axes.agr");
examplesFiles[3]=QString("tfonts.agr");
examplesFiles[4]=QString("arrows.agr");
examplesFiles[5]=QString("symslines.agr");
examplesFiles[6]=QString("fills.agr");
examplesFiles[7]=QString("tstack.agr");
examplesFiles[8]=QString("tinset.agr");
examplesFiles[9]=QString("manygraphs.agr");
examplesFiles[10]=QString("tlog.agr");
examplesFiles[11]=QString("log2.agr");
examplesFiles[12]=QString("log2log.agr");
examplesFiles[13]=QString("logit.agr");
examplesFiles[14]=QString("reciprocal.agr");
examplesFiles[15]=QString("terr.agr");
examplesFiles[16]=QString("times.agr");
examplesFiles[17]=QString("au.agr");
examplesFiles[18]=QString("co2.agr");
examplesFiles[19]=QString("motif.agr");
examplesFiles[20]=QString("spectrum.agr");
examplesFiles[21]=QString("bar.agr");
examplesFiles[22]=QString("stackedb.agr");
examplesFiles[23]=QString("chartebar.agr");
examplesFiles[24]=QString("charts.agr");
examplesFiles[25]=QString("polar.agr");
examplesFiles[26]=QString("pie.agr");
examplesFiles[27]=QString("hilo.agr");
examplesFiles[28]=QString("txyr.agr");
examplesFiles[29]=QString("xyz.agr");
examplesFiles[30]=QString("boxplot.agr");
examplesFiles[31]=QString("vmap.agr");
examplesFiles[32]=QString("xysize.agr");
examplesFiles[33]=QString("xycolor.agr");
examplesFiles[34]=QString("test2.agr");
examplesFiles[35]=QString("txttrans.agr");
examplesFiles[36]=QString("typeset.agr");
examplesFiles[37]=QString("logistic.agr");

//History-actions
char dummy[64];
historyMapper=new QSignalMapper();
actClearHistory= new QAction(tr("&Clear History" ), this);
connect(actClearHistory, SIGNAL(triggered()), this, SLOT(clearHistory()));
for (int i=0;i<MAX_HISTORY;i++)
{
sprintf(dummy,"item %d",i);
actHistory[i]=new QAction(QString(dummy), this);
connect(actHistory[i], SIGNAL(triggered()), historyMapper, SLOT(map()));
historyMapper->setMapping(actHistory[i],i);
}
connect(historyMapper, SIGNAL(mapped(int)),this, SLOT(HistoryClicked(int)));
}

void MainWindow::resizeEvent( QResizeEvent * e)
{
windowWidth=e->size().width();
windowHeight=e->size().height();
}

void MainWindow::LoadProject(char * filename)
{
inwin=1;
load_project(filename);
///Are the following two statements realy necessary?
/*inwin=1;
monomode=0;*/
//addToHistory(filename);
initNodes();//Undo-Stuff
mainArea->completeRedraw();
mainArea->setGeometry(mainArea->x(),mainArea->y(),mainArea->width(),mainArea->height());
}

void MainWindow::closeEvent( QCloseEvent * event )
{
    write_settings();
    int ret=bailout();
    if (ret==0)
    {
    event->ignore();
    }
}

/*
 * service the autoscale buttons on the main panel
 */
void MainWindow::autoscale_proc(int data)
{
    int cg = get_cg();
    char dummy[256];
    //Undo-Stuff
    SaveTickmarksStatesPrevious(X_AXIS,Y_AXIS,cg,cg);
    if (autoscale_graph(cg, (int) data) == RETURN_SUCCESS)
    {
        if (FormAxisProperties!=NULL)
        FormAxisProperties->update_ticks(cg);
    //Undo-Stuff
    TickmarksModified(X_AXIS,Y_AXIS,cg,cg);
        if (data==AUTOSCALE_XY)
        sprintf(dummy,"Autoscale graph [G%d]",cg);
        else if (data==AUTOSCALE_X)
        sprintf(dummy,"Autoscale X-axis [G%d]",cg);
        else
        sprintf(dummy,"Autoscale Y-axis [G%d]",cg);
    addAditionalDescriptionToLastNode(-1,QString(dummy),QString(),0);
        mainArea->completeRedraw();
    } else {
	errmsg("Can't autoscale (no active sets?)");
    }
}

void MainWindow::autoon_proc(int data)
{
    set_action(DO_NOTHING);
    set_action(AUTO_NEAREST);
}

/*
 * service the autoticks button on the main panel
 */
void MainWindow::autoticks_proc(int data)
{
    char dummy[256];
    SaveTickmarksStatesPrevious(X_AXIS,Y_AXIS,get_cg(),get_cg());
        autotick_axis(get_cg(), ALL_AXES);
        if (FormAxisProperties!=NULL)
        FormAxisProperties->update_ticks(get_cg());
    TickmarksModified(X_AXIS,Y_AXIS,get_cg(),get_cg());
    sprintf(dummy,"Autotick graph [G%d]",get_cg());
    addAditionalDescriptionToLastNode(-1,QString(dummy),QString(),0);
        mainArea->completeRedraw();
}

void MainWindow::graph_scroll_proc(int data)
{
    char dummy[256];
    SaveTickmarksStatesPrevious(X_AXIS,Y_AXIS,get_cg(),get_cg());
        graph_scroll(data);
    TickmarksModified(X_AXIS,Y_AXIS,get_cg(),get_cg());
    if (data==GSCROLL_LEFT)
    sprintf(dummy,"Scroll left graph [G%d]",get_cg());
    else if (data==GSCROLL_RIGHT)
    sprintf(dummy,"Scroll right graph [G%d]",get_cg());
    else if (data==GSCROLL_UP)
    sprintf(dummy,"Scroll up graph [G%d]",get_cg());
    else
    sprintf(dummy,"Scroll down graph [G%d]",get_cg());
    addAditionalDescriptionToLastNode(-1,QString(dummy),QString(),0);
        mainArea->completeRedraw();
}

void MainWindow::graph_zoom_proc(int data)
{
    char dummy[256];
    SaveTickmarksStatesPrevious(X_AXIS,Y_AXIS,get_cg(),get_cg());
        graph_zoom(data);
    TickmarksModified(X_AXIS,Y_AXIS,get_cg(),get_cg());
    if (data==GZOOM_EXPAND)
    sprintf(dummy,"Zoom out graph [G%d]",get_cg());
    else
    sprintf(dummy,"Zoom in graph [G%d]",get_cg());
    addAditionalDescriptionToLastNode(-1,QString(dummy),QString(),0);
        mainArea->completeRedraw();
}

void MainWindow::world_stack_proc(int data)
{
    switch (data) {
    case WSTACK_PUSH_ZOOM:
        push_and_zoom();
        break;
    case WSTACK_PUSH:
        push_world();
        break;
    case WSTACK_POP:
        pop_world();
        break;
    case WSTACK_CYCLE:
        cycle_world_stack();
        break;
    default:
        return;
    }
    update_all();
    mainArea->completeRedraw();//xdrawgraph();
}

void MainWindow::load_example(char *data)
{
    char *s, buf[128];
    
    set_wait_cursor();
    
    s = data;
    sprintf(buf, "examples/%s", s);
    load_project_file(buf, FALSE);

    mainArea->completeRedraw();//xdrawgraph();

    unset_wait_cursor();
}

void MainWindow::set_stack_message(void)
{
    char buf[16];
    //cout << "cg=" << get_cg() << " wss=" << graph_world_stack_size(get_cg()) << " wsc=" << get_world_stack_current(get_cg()) << endl;
        sprintf(buf, " SD:%1d ", graph_world_stack_size(get_cg()));
        lblSD->setText(QString(buf));
        sprintf(buf, " CW:%1d ", get_world_stack_current(get_cg()));
        lblCW->setText(QString(buf));
}

void MainWindow::mouseReleaseEvent ( QMouseEvent * event )
{
    event->accept();
    mainArea->completeRedraw();
}

void MainWindow::keyPressEvent( QKeyEvent * e )
{
QWidget::keyPressEvent(e);
}

void MainWindow::SpreadSheetClosed(int gno,int setno)
{
//cout << "Spreadsheet closed: G" << gno << ".S" << setno << endl;
}

void MainWindow::set_barebones(int onoff)
{
    if (onoff){
        actShowStatusBar->setChecked(false);
        actShowToolBar->setChecked(false);
        actShowLocBar->setChecked(false);
        //locbar_visible = 0;
        //toolbar_visible = 0;
        //statusbar_visible = 0;
    }
}

void MainWindow::addToHistory(char * entry)
{
int found=-1;
QString to_find=QString(entry);
for (int i=0;i<current_history;i++)
{
    if (history[i]==to_find)
    {
    found=i;
    break;
    }
}
    if (found>=0)
    {
        for (int i=found;i>0;i--)
        history[i]=history[i-1];
        history[0]=QString(entry);
    }
    else
    {
        for (int i=MAX_HISTORY-1;i>0;i--)
        history[i]=history[i-1];

        history[0]=QString(entry);
        current_history++;
        if (current_history>max_history) current_history=max_history;
    }
    recreateHistory();
}

void MainWindow::HistoryClicked(int i)
{
    if (current_history==0)
    return;//clicks are pointless
int FileExists,isWriteable,isReadable;
QFile fileTest(history[i]);//selectedFile);
QFileInfo fileInfo(fileTest);
if (fileInfo.isFile()==false)
{
FileExists=false;
isWriteable=false;
isReadable=false;
}
else
{
FileExists=fileTest.exists();
isWriteable=fileInfo.isWritable();
isReadable=fileInfo.isReadable();
}
IOrequested(READ_PROJECT_FORM,QString(history[i]),FileExists,isWriteable,isReadable);
}

void MainWindow::clearHistory(void)
{
    if (current_history==0)
    return;//clicks are pointless
current_history=0;
recreateHistory();
}

void MainWindow::recreateHistory(void)
{
for (int i=current_history;i<MAX_HISTORY;i++)
actHistory[i]->setVisible(false);
    for (int i=0;i<current_history;i++)
    {
    actHistory[i]->setText(history[i]);
    actHistory[i]->setVisible(true);
    }
if (current_history==0)
actClearHistory->setText(tr("No entries"));
else
actClearHistory->setText(tr("&Clear History"));
}

void MainWindow::doUndo(void)
{
Undo();
}

void MainWindow::doRedo(void)
{
Redo();
}

void MainWindow::doUndoList(void)
{
    if (FormUndoList==NULL)
    {
    FormUndoList=new frmUndoList(this);
    }
    FormUndoList->init();
    FormUndoList->show();
    FormUndoList->raise();
}

MainArea::MainArea(QWidget *parent):QWidget( parent )
{
//drawArea=new QFrame(this);
//drawArea->setGeometry(0,0,1,1);
//drawArea->setFrameStyle(QFrame::Box | QFrame::Raised);
//scrollH=new QScrollBar(Qt::Horizontal,this);

//connect(scrollH,SIGNAL(sliderMoved(int)),SLOT(scroll_h(int)));
//connect(scrollH,SIGNAL(valueChanged(int)),SLOT(change_h(int)));
//scrollV=new QScrollBar(Qt::Vertical,this);

//connect(scrollV,SIGNAL(sliderMoved(int)),SLOT(scroll_v(int)));
//connect(scrollV,SIGNAL(valueChanged(int)),SLOT(change_v(int)));
//useable_w=drawArea->width();
//useable_h=drawArea->height();
setMouseTracking(TRUE);
//drawArea->setMouseTracking(TRUE);

scroll=new QScrollArea(this);
//connect(scroll->verticalScrollBar(),SIGNAL(sliderMoved(int)),SLOT(scroll_v(int)));
//connect(scroll->horizontalScrollBar(),SIGNAL(sliderMoved(int)),SLOT(scroll_v(int)));
lblBackGr=new QLabel(QString(""),this);
lblBackGr->setGeometry(0,0,20,20);
lblBackGr->setMouseTracking(TRUE);

scroll->setMouseTracking(TRUE);
scroll->setWidget(lblBackGr);

/*hier*/
//scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
/*ende*/

rubber=new QRubberBand(QRubberBand::Rectangle, lblBackGr);
rubber->hide();
rubberLine=new QRubberBand(QRubberBand::Line, lblBackGr);
rubberLine->hide();

draw_box=false;
contentChanged=true;

layout=new QHBoxLayout;
layout->setMargin(2);
layout->addWidget(scroll);
setLayout(layout);
}

special_XEvent QMouseToXEvent( QMouseEvent * e )
{
int x=e->x(),real_x;
int y=e->y(),real_y;
mainWin->mainArea->transf_window_coords(x,y,real_x,real_y);
special_XEvent event;
event.delta=0;
event.xbutton.button=e->button();
event.xbutton.x=real_x;
event.xbutton.y=real_y;
event.xmotion.x=event.xbutton.x;
event.xmotion.y=event.xbutton.y;
Qt::KeyboardModifiers mod=e->modifiers();
if ((mod & Qt::AltModifier)==Qt::AltModifier)
event.alt=true;
else
event.alt=false;
if ((mod & Qt::ControlModifier)==Qt::ControlModifier)
event.ctrl=true;
else
event.ctrl=false;
return event;
}

special_XEvent QKeyToXEvent( QKeyEvent * e )
{
special_XEvent event;
event.type=QEvent::KeyPress;
event.delta=0;
event.key=e->key();
event.xbutton.x=mainWin->mainArea->cursor().pos().x();
event.xbutton.y=mainWin->mainArea->cursor().pos().y();
event.xmotion.x=event.xbutton.x;
event.xmotion.y=event.xbutton.y;
event.xbutton.button=Qt::NoButton;
Qt::KeyboardModifiers mod=e->modifiers();
if ((mod & Qt::AltModifier)==Qt::AltModifier)
event.alt=true;
else
event.alt=false;
if ((mod & Qt::ControlModifier)==Qt::ControlModifier)
event.ctrl=true;
else
event.ctrl=false;
return event;
}

special_XEvent QWheelToXEvent( QWheelEvent * e )
{
int x=e->x(),real_x;
int y=e->y(),real_y;
mainWin->mainArea->transf_window_coords(x,y,real_x,real_y);
special_XEvent event;
event.type=QEvent::Wheel;
event.xbutton.button=Qt::NoButton;
event.xbutton.x=real_x;
event.xbutton.y=real_y;
event.xmotion.x=event.xbutton.x;
event.xmotion.y=event.xbutton.y;
event.delta=e->delta();
Qt::KeyboardModifiers mod=e->modifiers();
if ((mod & Qt::AltModifier)==Qt::AltModifier)
event.alt=true;
else
event.alt=false;
if ((mod & Qt::ControlModifier)==Qt::ControlModifier)
event.ctrl=true;
else
event.ctrl=false;
return event;
}

void MainArea::mouseMoveEvent( QMouseEvent * e)
{
special_XEvent event=QMouseToXEvent(e);
if (event.xbutton.x<0 || event.xbutton.x>MainPixmap->width() || event.xbutton.y<0 || event.xbutton.y>MainPixmap->height()) return;
event.type=QEvent::MouseMove;
int setno,move_dir,add_at;
int dx,dy,posx,posy;
switch (action_flag)
{
case ZOOM_2ND:
case ZOOMX_2ND:
case ZOOMY_2ND:
case MAKE_ELLIP_2ND:
case MAKE_BOX_2ND:
box_end_x=event.xbutton.x;
box_end_y=event.xbutton.y;
rubber->setGeometry(QRect(origin, lblBackGr->mapFrom(this,e->pos())).normalized());
break;
case MOVE_OBJECT_2ND:
case COPY_OBJECT2ND:
case PLACE_LEGEND_2ND:
case PLACE_TIMESTAMP_2ND:
box_end_x=event.xbutton.x;
box_end_y=event.xbutton.y;
mainWin->mainArea->rubber->setGeometry(ShiftRect.translated(event.xbutton.x-ShiftPoint.x(),event.xbutton.y-ShiftPoint.y()));
//rubber->setGeometry(QRect(origin, lblBackGr->mapFrom(this,e->pos())).normalized());
break;
case VIEW_2ND:
box_end_x=event.xbutton.x;
box_end_y=event.xbutton.y;
    posx=anchor_x<box_end_x?anchor_x:box_end_x;
    posy=anchor_y<box_end_y?anchor_y:box_end_y;
    dx=abs(anchor_x-box_end_x);
    dy=abs(anchor_y-box_end_y);
mainWin->mainArea->rubber->setGeometry(posx,posy,dx,dy);
break;
case MAKE_LINE_2ND:

break;
case MOVE_POINT2ND:
get_tracking_props(&setno,&move_dir,&add_at);
            switch (move_dir) {
            case MOVE_POINT_XY:
                rubberLine->setGeometry(QRect(origin, lblBackGr->mapFrom(this,e->pos())).normalized());
                break;
            case MOVE_POINT_Y:
                rubberLine->setGeometry(QRect(origin, lblBackGr->mapFrom(this,QPoint(origin.x(),e->y()))).normalized());
                break;
            case MOVE_POINT_X:
                rubberLine->setGeometry(QRect(origin, lblBackGr->mapFrom(this,QPoint(e->x(),origin.y()))).normalized());
                break;
            }
break;
}
my_proc(&event);
}

void MainArea::mousePressEvent(QMouseEvent * e)
{
    e->accept();
    QCursor curs=cursor();
    QCursor curs2(Qt::WhatsThisCursor);
    if (curs.shape()==curs2.shape())
    {
    HelpCB("doc/UsersGuide.html#canvas");
    unsetCursor();
    return;
    }
special_XEvent event=QMouseToXEvent(e);
event.doubleClick=false;
event.type=QEvent::MouseButtonPress;
origin = lblBackGr->mapFrom(this,e->pos());
processClickCommand(event);
}

void MainArea::processClickCommand(special_XEvent & event)
{
    switch (action_flag)
    {
    case ZOOM_1ST:
    case ZOOMX_1ST:
    case ZOOMY_1ST:
    case MAKE_ELLIP_1ST:
    case MAKE_BOX_1ST:
    box_end_x=box_start_x=event.xbutton.x;
    box_end_y=box_start_y=event.xbutton.y;
    rubber->setGeometry(QRect(origin, QSize()));
    rubber->show();
    draw_box=true;
    break;
    case COPY_OBJECT1ST:
    case MOVE_OBJECT_1ST:
    case PLACE_LEGEND_1ST:
    box_end_x=box_start_x=event.xbutton.x;
    box_end_y=box_start_y=event.xbutton.y;
    draw_box=true;
    break;
    case ZOOM_2ND:
    case ZOOMX_2ND:
    case ZOOMY_2ND:
    case MAKE_ELLIP_2ND:
    case MAKE_BOX_2ND:
    draw_box=false;
    rubber->hide();
    parentWidget()->setCursor(Qt::ArrowCursor);
    break;
    case MOVE_POINT1ST:
    box_end_x=box_start_x=event.xbutton.x;
    box_end_y=box_start_y=event.xbutton.y;
    rubberLine->setGeometry(QRect(origin, QSize()));
    rubberLine->show();
    break;
    case MOVE_POINT2ND:
    rubberLine->hide();
    break;
    }
    my_proc(&event);
}

void MainArea::mouseDoubleClickEvent(QMouseEvent * e )
{
    special_XEvent event=QMouseToXEvent(e);
    event.doubleClick=true;
    event.type=QEvent::MouseButtonPress;
    processClickCommand(event);
}

void MainArea::mouseReleaseEvent(QMouseEvent * e )
{
special_XEvent event=QMouseToXEvent(e);
mainWin->mouseReleaseEvent(e);
}

void MainArea::keyPressEvent( QKeyEvent * e )
{
special_XEvent event=QKeyToXEvent(e);
my_proc(&event);
mainWin->keyPressEvent( e );
}

void MainArea::wheelEvent( QWheelEvent * e )
{
special_XEvent event=QWheelToXEvent(e);
my_proc(&event);
}

QImage paintXOR(QImage * canvas,QImage * toDraw)//draw "toDraw" at position in XOR on "canvas" (no check for sizes, to Draw has to be at least as big as canvas; the result will have the same size as canvas)
{
int c_width=canvas->width(),c_height=canvas->height();
//Invert image to be painted --> white areas in toDraw will leave canvas untouched
toDraw->invertPixels();
//generate an empty image for the result
QImage resultImage(c_width,c_height,QImage::Format_ARGB32_Premultiplied);
//buffers for every pixel
QRgb col;
QColor col2;
int cr[3],cg[3],cb[3],ca[3];
//go through every line
for (int i=0;i<c_width;i++)
{
	//go through every row
	for (int j=0;j<c_height;j++)
	{
	//get color of canvas
	col=canvas->pixel(i,j);
	col2.setRgb(col);
	col2.getRgb(cr,cg,cb,ca);
	//get color of toDraw
	col=toDraw->pixel(i,j);
	col2.setRgb(col);
	col2.getRgb(cr+1,cg+1,cb+1,ca+1);
	//bitwise XOR-operation
	cr[2]=cr[0]^cr[1];
	cg[2]=cg[0]^cg[1];
	cb[2]=cb[0]^cb[1];
	//generate an RGB-value
	col2.setRgb(cr[2],cg[2],cb[2]);
	//set the pixel in the resulting image
	resultImage.setPixel(i,j,col2.rgb());
	}
}
return resultImage;
}

void MainArea::completeRedraw(void)
{
//cout << "Complete redraw()" << endl;
update_all();
xdrawgraph();
contentChanged=true;
repaint();
}

void MainArea::paintEvent( QPaintEvent *e )
{
static QPixmap pm;
if (contentChanged==false)
{
//cout << "repaint" << endl;
///lblBackGr->repaint();
return;
}

if (cursortype!=0)
{
QPoint cpoint=mapFromGlobal(QCursor::pos());
GeneralPainter->setPen(Qt::black);
GeneralPainter->drawLine(-4,cpoint.y()-4,width()+4,cpoint.y()-4);
GeneralPainter->drawLine(cpoint.x()-4,0,cpoint.x()-4,height());
}

if (monomode == FALSE)
pm=QPixmap::fromImage(*MainPixmap,Qt::AutoColor);
else
pm=QPixmap::fromImage(*MainPixmap,Qt::MonoOnly);

lblBackGr->setPixmap(pm);

if (pm.width()!=lblBackGr->width() || pm.height()!=lblBackGr->height())
{
lblBackGr->setGeometry(0,0,pm.width(),pm.height());
/*lblBackGr->setPixmap(pm);*/
}
//else
//lblBackGr->setGeometry(0,0,20,20);

//lblBackGr->repaint();
if (showhideworkaround)//a strange thing which is necessary sometimes
{
lblBackGr->hide();
qApp->processEvents();
lblBackGr->show();
}
contentChanged=false;
}

void MainArea::transf_window_coords(int x,int y,int & real_x,int & real_y)
{
QPoint p=lblBackGr->mapFrom(this,QPoint(x,y));
real_x=p.x();
real_y=p.y();
}
