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
#include <QtGui>
#include <QTranslator>
#include "globals.h"
#include "patterns.h"
#include "allWidgets.h"
#include "draw.h"
#include "xprotos.h"
#include "undo_module.h"

extern int replacement_main(int argc,char **argv);

char BI_VERSION[128];
char BI_SYSTEM[256];

DrawProps draw_props =
{{1, 1}, 0, TRUE, 1, 0.0, LINECAP_BUTT, LINEJOIN_MITER, 1.0, 0, FILLRULE_WINDING};
int maxgraph;
QFont stdFont;
QFontMetrics stdFontMetrics(stdFont);
bool useQPrinter=false;
QPrinter * stdPrinter;
int stdOutputFormat=1;
frmEllipseProps * EllipseProps;
frmEllipseProps * EditEllipseProps;
frmEllipseProps * BoxProps;
frmEllipseProps * EditBoxProps;
frmTextProps * TextProps;
frmTextProps * EditTextProps;
frmLineProps * LineProps;
frmLineProps * EditLineProps;
frmDrawObjects * FormDrawObjects;
frmConsole * FormConsole;
frmEvalExpr * FormEvalExpr;
frmSetAppearance * FormSetAppearance;
frmGraphApp * FormGraphAppearance;
frmPlotAppearance * FormPlotAppearance;
frmLocatorProps * FormLocatorProps;
frmAxisProp * FormAxisProperties;
frmPointExplorer * FormPointExplorer;
frmNonlinCurveFit * FormNonlinCurveFit;
//frmEditColumnProp * EditColumn;
frmInterpolation * FormInterpolation;
frmSetOp * FormSetOperations;
frmCommands * FormCommands;
frmDeviceSetup * FormDeviceSetup;
frmPreferences * FormPreferences;
frmArrangeGraphs * FormArrangeGraphs;
frmOverlayGraphs * FormOverlayGraphs;
frmAutoscaleGraphs * FormAutoScaleGraphs;
frmDataSetProperties * FormDataSetProperties;
frmSetOperations * FormSetOPS;
frmFeatureExtract * FormFeatureExtraction;
frmInterpolation * FormHistograms;
frmFourier * FormFourier;
frmFourier2 * FormFourier2;
frmLoadEval * FormLoadAndEvaluate;
frmSmallCalc * FormIntegration;
frmSmallCalc * FormSeasonDiff;
frmSmallCalc * FormDifferences;
frmSmallCalc * FormAverages;
frmSmallCalc * FormRegression;
frmCorrelation * FormCorrelation;
frmCorrelation * FormConvolution;
frmCorrelation * FormDigitalFilter;
frmTransform * FormPruneData;
frmTransform * FormSamplePoints;
frmTransform * FormGeometricTransform;
frmHotLinks * FormHotLinks;
frmRegionStatus * FormRegionStatus;
frmRegions * FormReportRegion;
frmRegions * FormClearRegion;
frmRegions * FormDefineRegion;

frmNetCDF * FormNetCDF;
frmIOForm * FormReadSets;
frmIOForm * FormReadNetCDF;
frmIOForm * FormWriteSets;
frmIOForm * FormOpenProject;
frmIOForm * FormSaveProject;
frmIOForm * FormSelectHotLink;
frmIOForm * FormReadParameters;
frmIOForm * FormWriteParameters;
frmIOForm * FormSelectOutputFile;
frmIOForm * FormReadBinary;
frmIOForm * FormWriteBinary;

frmBinaryFormatInput * FormBinaryImportFilter;

frmEditBlockData * FormEditBlockData;

frmFontTool * FormFontTool;
frmAbout * FormAbout;
frmSetEditor * FormSetEditor;
frmUndoList * FormUndoList;

frmExtraPreferences * ExtraPreferences;
QSettings * allPrefs;
bool display_help_externally=false;
bool showhideworkaround=false;

int number_of_opened_spreadsheets=0;
frmSpreadSheet ** FormSpreadSheets=new frmSpreadSheet*[2];

//Undo-Stuff
bool undo_active=true;
int NodeNr,used_Nodes,akt_Node;
int max_node_nr;
class undo_node * Node;

extern double * old_ddata[16];//to store some data temporarely
extern int * old_idata[16];//to store some data temporarely
extern int old_data[16];

//OptionItem *graph_select_items = NULL;
int ngraph_select_items = 0;
uniList ** graph_selectors=NULL;
int ngraph_selectors = 0,n_gr_sel_alloc=0;
//OptionItem *color_option_items = NULL;
int ncolor_option_items = 0;
ColorSelector **color_selectors = NULL;
int ncolor_selectors = 0,n_col_sel_alloc=0;
uniList ** set_selectors=NULL;
int nset_selectors = 0,n_set_sel_alloc=0;
uniList ** plist = NULL;
int nplist = 0,n_plist_alloc=0;

struct ColumnFormat binaryImportFormat[NUMBER_OF_COLUMN_FORMATS];
char binaryImportFormatName[NUMBER_OF_COLUMN_FORMATS][32];
int ImportDestination[NUMBER_OF_IMPORT_DESTINATIONS];
char ImportDestinationName[NUMBER_OF_IMPORT_DESTINATIONS][32];
signed char ImportDestinationType[NUMBER_OF_IMPORT_DESTINATIONS];

MainWindow * mainWin=NULL;
QImage * MainPixmap;
QPainter * GeneralPainter;
QPixmap * Qt_justifications[12];
QPixmap * Qt_matrixOrder[8];
QBitmap * patterns[MAXPATTERNS];//Fill_Paterns for drawing
QPixmap * PatternPixmaps[MAXPATTERNS];
QBitmap * autoBitMap;
QBitmap * downBitMap;
QBitmap * expandBitMap;
QBitmap * leftBitMap;
QBitmap * rightBitMap;
QBitmap * shrinkBitMap;
QBitmap * upBitMap;
QBitmap * zoomBitMap;
QPixmap * GraceIcon;
QPixmap * Qt_j_lm_o_bits;
QPixmap * Qt_j_cm_o_bits;
QPixmap * Qt_j_rm_o_bits;
QPixmap * Qt_j_lb_b_bits;
QPixmap * Qt_j_lm_b_bits;
QPixmap * Qt_j_lt_b_bits;
QPixmap * Qt_j_ct_b_bits;
QPixmap * Qt_j_rt_b_bits;
QPixmap * Qt_j_rm_b_bits;
QPixmap * Qt_j_rb_b_bits;
QPixmap * Qt_j_cb_b_bits;
QPixmap * Qt_j_cm_b_bits;
QPixmap * Qt_m_hv_lr_bt_bits;
QPixmap * Qt_m_hv_lr_tb_bits;
QPixmap * Qt_m_hv_rl_bt_bits;
QPixmap * Qt_m_hv_rl_tb_bits;
QPixmap * Qt_m_vh_lr_bt_bits;
QPixmap * Qt_m_vh_lr_tb_bits;
QPixmap * Qt_m_vh_rl_bt_bits;
QPixmap * Qt_m_vh_rl_tb_bits;
QIcon * ColorIcons[16];
QPixmap * ColorPixmaps[16];
QString * ColorNames[16];
QIcon * LineIcons[MAXLINESTYLES];
QPixmap * LinePixmaps[MAXLINESTYLES];
QVector<qreal> * PenDashPattern[MAXLINESTYLES];
CMap_entry *cmap_table;

QCursor * wait_cursor;
QCursor * line_cursor;
QCursor * find_cursor;
QCursor * move_cursor;
QCursor * text_cursor;
QCursor * kill_cursor;
QCursor * what_cursor;
int cur_cursor = -1;

int action_flag = 0;
int region_def_under_way;

QColor * stdColors[16];//Colors for Drawing
QBrush * stdBrush;//standard Brush for Drawing
QPen * stdPen;//standard Pen for Drawing

char user_home_dir[1024];
char qt_grace_exe_dir[1024];
//extern QTime lastc;

int max_history=10;//maximum number of recently opend files to be stored
int current_history=0;//content of history
QString history[MAX_HISTORY];//actual history

//index=0 is reserved for english, which is the default
QTranslator translator[nr_of_translations];
char translator_files[nr_of_translations][64];
char translator_languages[nr_of_translations][64];
int current_language=0;

void init_color_icons(void);
void read_settings(void);

void init(void)
{
for (int i=0;i<MAX_HISTORY;i++)
history[i]=QString("");

region_def_under_way=-1;
Qt_justifications[0]=Qt_j_lm_o_bits;
Qt_justifications[1]=Qt_j_cm_o_bits;
Qt_justifications[2]=Qt_j_rm_o_bits;
Qt_justifications[3]=Qt_j_lb_b_bits;
Qt_justifications[4]=Qt_j_cb_b_bits;
Qt_justifications[5]=Qt_j_rb_b_bits;
Qt_justifications[6]=Qt_j_lm_b_bits;
Qt_justifications[7]=Qt_j_cm_b_bits;
Qt_justifications[8]=Qt_j_rm_b_bits;
Qt_justifications[9]=Qt_j_lt_b_bits;
Qt_justifications[10]=Qt_j_ct_b_bits;
Qt_justifications[11]=Qt_j_rt_b_bits;

Qt_matrixOrder[0]=Qt_m_hv_lr_tb_bits;
Qt_matrixOrder[1]=Qt_m_hv_lr_bt_bits;
Qt_matrixOrder[2]=Qt_m_hv_rl_bt_bits;
Qt_matrixOrder[3]=Qt_m_hv_rl_tb_bits;
Qt_matrixOrder[4]=Qt_m_vh_lr_tb_bits;
Qt_matrixOrder[5]=Qt_m_vh_lr_bt_bits;
Qt_matrixOrder[6]=Qt_m_vh_rl_tb_bits;
Qt_matrixOrder[7]=Qt_m_vh_rl_bt_bits;

#ifdef LINUX_SYSTEM
showhideworkaround=true;
#else
showhideworkaround=false;
#endif

binaryImportFormat[0].format=COLUMN_OFFSET;
binaryImportFormat[0].size=1;
strcpy(binaryImportFormatName[0],"Offset");
binaryImportFormat[1].format=COLUMN_SIG_CHAR;
binaryImportFormat[1].size=sizeof(signed char);
strcpy(binaryImportFormatName[1],"signed Char");
binaryImportFormat[2].format=COLUMN_USIG_CHAR;
binaryImportFormat[2].size=sizeof(unsigned char);
strcpy(binaryImportFormatName[2],"unsigned Char");
binaryImportFormat[3].format=COLUMN_SIG_SHORT;
binaryImportFormat[3].size=sizeof(signed short);
strcpy(binaryImportFormatName[3],"signed Short");
binaryImportFormat[4].format=COLUMN_USIG_SHORT;
binaryImportFormat[4].size=sizeof(unsigned short);
strcpy(binaryImportFormatName[4],"unsigned Short");
binaryImportFormat[5].format=COLUMN_SIG_INT;
binaryImportFormat[5].size=sizeof(signed int);
strcpy(binaryImportFormatName[5],"signed Int");
binaryImportFormat[6].format=COLUMN_USIG_INT;
binaryImportFormat[6].size=sizeof(unsigned int);
strcpy(binaryImportFormatName[6],"unsigned Int");
binaryImportFormat[7].format=COLUMN_SIG_LONG;
binaryImportFormat[7].size=sizeof(signed long);
strcpy(binaryImportFormatName[7],"signed Long");
binaryImportFormat[8].format=COLUMN_USIG_LONG;
binaryImportFormat[8].size=sizeof(unsigned long);
strcpy(binaryImportFormatName[8],"unsigned Long");
binaryImportFormat[9].format=COLUMN_FLOAT;
binaryImportFormat[9].size=sizeof(float);
strcpy(binaryImportFormatName[9],"Float");
binaryImportFormat[10].format=COLUMN_DOUBLE;
binaryImportFormat[10].size=sizeof(double);
strcpy(binaryImportFormatName[10],"Double");
binaryImportFormat[11].format=COLUMN_LONG_DOUBLE;
binaryImportFormat[11].size=sizeof(long double);
strcpy(binaryImportFormatName[11],"long Double");
binaryImportFormat[12].format=COLUMN_STRING;
binaryImportFormat[12].size=0;
strcpy(binaryImportFormatName[12],"String");

ImportDestination[0]=IMPORT_TO_NONE;
strcpy(ImportDestinationName[0],"None");
ImportDestinationType[0]=3;//every one
ImportDestination[1]=IMPORT_TO_TITLE;
strcpy(ImportDestinationName[1],"Title");
ImportDestinationType[1]=1;//only for header
ImportDestination[2]=IMPORT_TO_X;
strcpy(ImportDestinationName[2],"X");
ImportDestinationType[2]=2;//only for data
ImportDestination[3]=IMPORT_TO_Y;
strcpy(ImportDestinationName[3],"Y");
ImportDestinationType[3]=2;//only for data
ImportDestination[4]=IMPORT_TO_Y1;
strcpy(ImportDestinationName[4],"Y1");
ImportDestinationType[4]=2;//only for data
ImportDestination[5]=IMPORT_TO_Y2;
strcpy(ImportDestinationName[5],"Y2");
ImportDestinationType[5]=2;//only for data
ImportDestination[6]=IMPORT_TO_Y3;
strcpy(ImportDestinationName[6],"Y3");
ImportDestinationType[6]=2;//only for data
ImportDestination[7]=IMPORT_TO_Y4;
strcpy(ImportDestinationName[7],"Y4");
ImportDestinationType[7]=2;//only for data
ImportDestination[8]=IMPORT_TO_X0;
strcpy(ImportDestinationName[8],"X0");
ImportDestinationType[8]=1;//only for header
ImportDestination[9]=IMPORT_TO_DELTAX;
strcpy(ImportDestinationName[9],"delta X");
ImportDestinationType[9]=1;//only for header
ImportDestination[10]=IMPORT_TO_XTITLE;
strcpy(ImportDestinationName[10],"X-Title");
ImportDestinationType[10]=1;//only for header
ImportDestination[11]=IMPORT_TO_YTITLE;
strcpy(ImportDestinationName[11],"Y-Title");
ImportDestinationType[11]=1;//only for header
ImportDestination[12]=IMPORT_TO_XFACTOR;
strcpy(ImportDestinationName[12],"X-Factor");
ImportDestinationType[12]=1;//only for header
ImportDestination[13]=IMPORT_TO_YFACTOR;
strcpy(ImportDestinationName[13],"Y-Factor");
ImportDestinationType[13]=1;//only for header
ImportDestination[14]=IMPORT_TO_Y1FACTOR;
strcpy(ImportDestinationName[14],"Y1-Factor");
ImportDestinationType[14]=1;//only for header
ImportDestination[15]=IMPORT_TO_Y2FACTOR;
strcpy(ImportDestinationName[15],"Y2-Factor");
ImportDestinationType[15]=1;//only for header
ImportDestination[16]=IMPORT_TO_Y3FACTOR;
strcpy(ImportDestinationName[16],"Y3-Factor");
ImportDestinationType[16]=1;//only for header
ImportDestination[17]=IMPORT_TO_Y4FACTOR;
strcpy(ImportDestinationName[17],"Y4-Factor");
ImportDestinationType[17]=1;//only for header
ImportDestination[18]=IMPORT_TO_SUBTITLE;
strcpy(ImportDestinationName[18],"SubTitle");
ImportDestinationType[18]=1;//only for header
ImportDestination[19]=IMPORT_TO_NUMBER_OF_DATA;
strcpy(ImportDestinationName[19],"Sample Count");
ImportDestinationType[19]=1;//only for header
ImportDestination[20]=IMPORT_TO_NUMBER_OF_CHANNELS;
strcpy(ImportDestinationName[20],"Channel Count");
ImportDestinationType[20]=1;//only for header
ImportDestination[21]=IMPORT_TO_DATA_SIZE;
strcpy(ImportDestinationName[21],"Channel Size (Bytes)");
ImportDestinationType[21]=1;//only for header
ImportDestination[22]=IMPORT_TO_DATA_SIZE_BIT;
strcpy(ImportDestinationName[22],"Channel Size (Bits)");
ImportDestinationType[22]=1;//only for header
ImportDestination[23]=IMPORT_TO_DATA_SAMPLING_RATE;
strcpy(ImportDestinationName[23],"Sampling Rate");
ImportDestinationType[23]=1;//only for header
ImportDestination[24]=IMPORT_TO_WHOLE_DATA_BLOCK_SIZE;
strcpy(ImportDestinationName[24],"Whole data block (Bytes)");
ImportDestinationType[24]=1;//only for header
ImportDestination[25]=IMPORT_TO_SINGLE_DATA_BLOCK_SIZE;
strcpy(ImportDestinationName[25],"Single data point (Bytes)");
ImportDestinationType[25]=1;//only for header
ImportDestination[26]=IMPORT_TO_SET_LEGEND;
strcpy(ImportDestinationName[26],"Set Legend");
ImportDestinationType[26]=1;//only for header
}

int main( int argc, char **argv )
{
/*#ifdef WINDOWS_SYSTEM
    cout << "Windows" << endl;
#endif
#ifdef MAC_SYSTEM
    cout << "Mac OS X" << endl;
#endif
#ifdef LINUX_SYSTEM
    cout << "Linux" << endl;
#endif*/

    QApplication a( argc, argv );

    Node=NULL;
for (int i=0;i<16;i++)
{
old_ddata[i]=NULL;
old_idata[i]=NULL;
old_data[i]=0;
}
    strcpy(user_home_dir,QDir::homePath().toAscii());
    strcpy(qt_grace_exe_dir,qApp->applicationDirPath().toAscii());

    //define the available languages
    strcpy(translator_files[0],"-");
    strcpy(translator_files[1],"qt_grace_ger");
    strcpy(translator_languages[0],"English");
    strcpy(translator_languages[1],"German");
    for (int i=1;i<nr_of_translations;i++)
    {
    translator[i].load(translator_files[i]);
    //a.installTranslator(&translator[i]);//-->install later
    }

    allPrefs=new QSettings(qt_grace_exe_dir+QString("/qtGrace_Settings.ini"),QSettings::IniFormat);
    allPrefs->sync();
    allPrefs->beginGroup(QString("ExtraPreferences"));
    int sellang=allPrefs->value(QString("language"),QVariant(0)).toInt();
    allPrefs->endGroup();
    delete allPrefs;
    if (sellang>0)
    {
    a.installTranslator(&translator[sellang]);
    current_language=sellang;
    }

init_cursors();
initNodes();//Undo-Stuff

MainPixmap=new QImage(10,10,QImage::Format_ARGB32_Premultiplied);
MainPixmap->fill(0);
GeneralPainter=new QPainter(MainPixmap);

stdFont=a.font();
stdFont.setPixelSize(14);
stdFontMetrics=QFontMetrics(stdFont);

mainWin=new MainWindow();
a.setWindowIcon(*GraceIcon);
replacement_main(argc,argv);//set up all internal Grace-things

    mainWin->setGeometry( 100, 100, 872, 670 );

init();

    useQPrinter=false;
    stdPrinter=NULL;
    FormAbout=NULL;
    FormEvalExpr=NULL;
    FormSetAppearance=NULL;
    FormGraphAppearance=NULL;
    FormPlotAppearance=NULL;
    FormAxisProperties=NULL;
    FormLocatorProps=NULL;
    FormConsole=new frmConsole(mainWin);//needed for error-Messages
    FormDrawObjects=NULL;
    FormPointExplorer=NULL;
    FormNonlinCurveFit=NULL;
    FormInterpolation=NULL;
    FormSetOperations=NULL;
    FormCommands=NULL;
    FormDeviceSetup=NULL;
    FormArrangeGraphs=NULL;
    FormOverlayGraphs=NULL;
    FormAutoScaleGraphs=NULL;
    FormLoadAndEvaluate=NULL;
    FormDataSetProperties=NULL;
    FormSetOPS=NULL;
    FormFeatureExtraction=NULL;
    FormInterpolation=NULL;
    FormHistograms=NULL;
    FormFourier=NULL;
    FormFourier2=NULL;
    FormIntegration=NULL;
    FormSeasonDiff=NULL;
    FormDifferences=NULL;
    FormAverages=NULL;
    FormRegression=NULL;
    FormCorrelation=NULL;
    FormConvolution=NULL;
    FormDigitalFilter=NULL;
    FormPruneData=NULL;
    FormSamplePoints=NULL;
    FormGeometricTransform=NULL;
    FormSelectHotLink=NULL;
    FormReadParameters=NULL;
    FormWriteParameters=NULL;
    FormHotLinks=NULL;
    FormRegionStatus=NULL;
    FormReportRegion=NULL;
    FormClearRegion=NULL;
    FormDefineRegion=NULL;
    FormSelectOutputFile=NULL;
    FormReadSets=NULL;
    FormWriteSets=NULL;
    FormNetCDF=NULL;
    FormReadNetCDF=NULL;
    FormOpenProject=NULL;
    FormSaveProject=NULL;
    FormBinaryImportFilter=NULL;
    FormSetEditor=NULL;
    FormEditBlockData=NULL;
    FormUndoList=NULL;

    FormPreferences=new frmPreferences(mainWin);
    FormPreferences->init();
    FormPreferences->hide();
    ExtraPreferences=new frmExtraPreferences(FormPreferences);
    ExtraPreferences->init();
    ExtraPreferences->hide();

EditTextProps=new frmTextProps(mainWin,true);
EditTextProps->hide();
EditLineProps=new frmLineProps(mainWin,true);
EditLineProps->hide();
EditBoxProps=new frmEllipseProps(mainWin,true,false);
EditBoxProps->hide();
EditEllipseProps=new frmEllipseProps(mainWin,true,true);
EditEllipseProps->hide();
/*EditColumn=new frmEditColumnProp(mainWin);
EditColumn->hide();*/

EllipseProps=NULL;
BoxProps=NULL;
LineProps=NULL;
TextProps=NULL;

FormFontTool=NULL;

read_settings();

mainWin->mainArea->completeRedraw();
mainWin->show();
clear_dirtystate();
CheckActive();

    return a.exec();
}

int object_edit_popup(int type, int id)
{
    switch (type) {
    case OBJECT_BOX:
        if (EditBoxProps==NULL)
        {
        EditBoxProps=new frmEllipseProps(mainWin,true,false);
        }
        EditBoxProps->init(id);
        EditBoxProps->show();
        EditBoxProps->raise();
        break;
    case OBJECT_ELLIPSE:
        if (EditEllipseProps==NULL)
        {
        EditEllipseProps=new frmEllipseProps(mainWin,true,false);
        }
        EditEllipseProps->init(id);
        EditEllipseProps->show();
        EditEllipseProps->raise();
        break;
    case OBJECT_LINE:
        if (EditLineProps==NULL)
        {
        EditLineProps=new frmLineProps(mainWin,true);
        }
        EditLineProps->init(id);
        EditLineProps->show();
        EditLineProps->raise();
        break;
    case OBJECT_STRING:
        if (EditTextProps==NULL)
        {
        EditTextProps=new frmTextProps(mainWin,true);
        }
        EditTextProps->init(id);
        EditTextProps->show();
        EditTextProps->raise();
        EditTextProps->activateWindow();
        EditTextProps->string_item->lenText->setFocus();
        break;
    default:
        return RETURN_FAILURE;
        break;
    }
    return RETURN_SUCCESS;
}

void errwin(const char *s)
{
if (FormConsole==NULL)
{
FormConsole=new frmConsole(mainWin);
}
FormConsole->errwin(s);
}

void add_GraphSelector(uniList * grSel)
{
    if (ngraph_selectors==n_gr_sel_alloc)
    {
    uniList ** dummy=graph_selectors;
    n_gr_sel_alloc+=5;
    graph_selectors=new uniList*[n_gr_sel_alloc];
        for (int i=0;i<ngraph_selectors;i++)
        graph_selectors[i]=dummy[i];
    delete[] dummy;//delete original entries
    }
    graph_selectors[ngraph_selectors]=grSel;
    ngraph_selectors++;
}

void set_graph_selectors(int gno)
{
    int i;

    for (i = 0; i < ngraph_selectors; i++) {
        SelectListChoice(graph_selectors[i], gno);
    }
        for (i = 0; i < nset_selectors; i++)
        set_selectors[i]->set_graph_number(gno,true);
}

void add_SetSelector(uniList * setSel)
{
    if (nset_selectors==n_set_sel_alloc)
    {
    uniList ** dummy=set_selectors;
    n_set_sel_alloc+=5;
    set_selectors=new uniList*[n_set_sel_alloc];
        for (int i=0;i<nset_selectors;i++)
        set_selectors[i]=dummy[i];
    delete[] dummy;//delete original entries
    }
    set_selectors[nset_selectors]=setSel;
    nset_selectors++;
}

void add_SetChoiceItem(uniList * setSel)
{
    if (nplist==n_plist_alloc)
    {
    uniList ** dummy=plist;
    n_plist_alloc+=5;
    plist=new uniList*[n_plist_alloc];
        for (int i=0;i<nplist;i++)
        plist[i]=dummy[i];
    delete[] dummy;//delete original entries
    }
    plist[nplist]=setSel;
    nplist++;
}

void add_ColorSelector(ColorSelector * colSel)
{
    if (ncolor_selectors==n_col_sel_alloc)
    {
    ColorSelector ** dummy=color_selectors;
    n_col_sel_alloc+=5;
    color_selectors=new ColorSelector*[n_col_sel_alloc];
        for (int i=0;i<ncolor_selectors;i++)
        color_selectors[i]=dummy[i];
    delete[] dummy;//delete original entries
    }
    color_selectors[ncolor_selectors]=colSel;
    ncolor_selectors++;
}

void change_language(int index)
{
if (index>=nr_of_translations) return;
if (current_language!=0)
{
qApp->removeTranslator(&translator[current_language]);
}
qApp->installTranslator(&translator[index]);
current_language=index;
}

void read_settings(void)
{
    /*allPrefs=new QSettings(QString("Grace"),QString("qtGrace"));
    allPrefs->setPath(QSettings::IniFormat,QSettings::UserScope,qt_grace_exe_dir);*/
    allPrefs=new QSettings(qt_grace_exe_dir+QString("/qtGrace_Settings.ini"),QSettings::IniFormat);
    allPrefs->sync();
    allPrefs->beginGroup(QString("Preferences"));
    FormPreferences->noask_item->setChecked(allPrefs->value(QString("dontaskquestions"),QVariant(false)).toBool());
    FormPreferences->dc_item->setChecked(allPrefs->value(QString("allowdoubleclickoncanvas"),QVariant(true)).toBool());
    FormPreferences->graph_focus_choice_item->setCurrentIndex(allPrefs->value(QString("graphfocusswitch"),QVariant(0)).toInt());
    FormPreferences->graph_drawfocus_choice_item->setChecked(allPrefs->value(QString("displayfocusmarker"),QVariant(true)).toBool());
    FormPreferences->autoredraw_type_item->setChecked(allPrefs->value(QString("autoredraw"),QVariant(true)).toBool());
    FormPreferences->cursor_type_item->setChecked(allPrefs->value(QString("crosshaircursor"),QVariant(false)).toBool());

    FormPreferences->max_path_item->setValue(allPrefs->value(QString("maxdrawpathlength"),QVariant(20000)).toInt());
    FormPreferences->safe_mode_item->setChecked(allPrefs->value(QString("runinsafemode"),QVariant(true)).toBool());

    FormPreferences->scrollper_item->setValue(allPrefs->value(QString("scrollpercent"),QVariant(5)).toInt());
    FormPreferences->shexper_item->setValue(allPrefs->value(QString("zoompercent"),QVariant(5)).toInt());
    FormPreferences->linkscroll_item->setChecked(allPrefs->value(QString("linkedscrolling"),QVariant(false)).toBool());

    FormPreferences->hint_item->setCurrentIndex(allPrefs->value(QString("datehint"),QVariant(3)).toInt());
    FormPreferences->date_item->setText(allPrefs->value(QString("referencedate"),QVariant("-4713-01-01 12:00:00")).toString());
    FormPreferences->two_digits_years_item->setChecked(allPrefs->value(QString("twodigityearspan"),QVariant(false)).toBool());
    FormPreferences->wrap_year_item->setText(allPrefs->value(QString("wrapyear"),QVariant(1950)).toString());
    allPrefs->endGroup();
    allPrefs->beginGroup(QString("ExtraPreferences"));
    ExtraPreferences->lenHome->setText(allPrefs->value(QString("gracehomedirectory"),QVariant(qt_grace_exe_dir)).toString());
    ExtraPreferences->chkExternalHelpViewer->setChecked(allPrefs->value(QString("showhelpexternally"),QVariant(false)).toBool());
    ExtraPreferences->lenHelpViewer->setText(allPrefs->value(QString("helpviewer"),QVariant("")).toString());
    ExtraPreferences->selLanguage->setCurrentIndex(allPrefs->value(QString("language"),QVariant(0)).toInt());
    ExtraPreferences->chkShowHideException->setChecked(allPrefs->value(QString("showhideworkaround"),QVariant(false)).toBool());
    allPrefs->endGroup();
    allPrefs->beginGroup(QString("History"));
    max_history=allPrefs->value(QString("maxhistory"),QVariant(MAX_HISTORY)).toInt();
    ExtraPreferences->histSize->setValue(max_history);
    current_history=allPrefs->value(QString("historysize"),QVariant(0)).toInt();
    char dummy[32];
    for (int i=0;i<MAX_HISTORY;i++)//always save MAX_HISTORY entries (possibly empty ones)
    {
    sprintf(dummy,"history%d",i);
    history[i]=allPrefs->value(QString(dummy),QVariant("")).toString();
    }
    allPrefs->endGroup();
    allPrefs->beginGroup(QString("General"));
    stdOutputFormat=allPrefs->value(QString("stdOutputFormat"),QVariant(1)).toInt();
    undo_active=allPrefs->value(QString("activateUndoRecords"),QVariant(false)).toBool();///undo deactivated as a default
    allPrefs->endGroup();
    allPrefs->sync();
    FormPreferences->doApply();
    ExtraPreferences->doApply();
    delete allPrefs;
    mainWin->recreateHistory();
}

void write_settings(void)
{
/*allPrefs=new QSettings(QString("Grace"),QString("qtGrace"));
allPrefs->setPath(QSettings::IniFormat,QSettings::UserScope,qt_grace_exe_dir);*/
allPrefs=new QSettings(qt_grace_exe_dir+QString("/qtGrace_Settings.ini"),QSettings::IniFormat);
allPrefs->beginGroup(QString("Preferences"));
allPrefs->setValue(QString("dontaskquestions"),QVariant(FormPreferences->noask_item->isChecked()));
allPrefs->setValue(QString("allowdoubleclickoncanvas"),QVariant(FormPreferences->dc_item->isChecked()));
allPrefs->setValue(QString("graphfocusswitch"),QVariant(FormPreferences->graph_focus_choice_item->currentIndex()));
allPrefs->setValue(QString("displayfocusmarker"),QVariant(FormPreferences->graph_drawfocus_choice_item->isChecked()));
allPrefs->setValue(QString("autoredraw"),QVariant(FormPreferences->autoredraw_type_item->isChecked()));
allPrefs->setValue(QString("crosshaircursor"),QVariant(FormPreferences->cursor_type_item->isChecked()));

allPrefs->setValue(QString("maxdrawpathlength"),QVariant(FormPreferences->max_path_item->value()));
allPrefs->setValue(QString("runinsafemode"),QVariant(FormPreferences->safe_mode_item->isChecked()));

allPrefs->setValue(QString("scrollpercent"),QVariant(FormPreferences->scrollper_item->value()));
allPrefs->setValue(QString("zoompercent"),QVariant(FormPreferences->shexper_item->value()));
allPrefs->setValue(QString("linkedscrolling"),QVariant(FormPreferences->linkscroll_item->isChecked()));

allPrefs->setValue(QString("datehint"),QVariant(FormPreferences->hint_item->currentIndex()));
allPrefs->setValue(QString("referencedate"),QVariant(FormPreferences->date_item->text()));
allPrefs->setValue(QString("twodigityearspan"),QVariant(FormPreferences->two_digits_years_item->isChecked()));
allPrefs->setValue(QString("wrapyear"),QVariant(FormPreferences->wrap_year_item->text()));
allPrefs->endGroup();
allPrefs->beginGroup(QString("ExtraPreferences"));
allPrefs->setValue(QString("gracehomedirectory"),QVariant(ExtraPreferences->lenHome->text()));
allPrefs->setValue(QString("showhelpexternally"),QVariant(ExtraPreferences->chkExternalHelpViewer->isChecked()));
allPrefs->setValue(QString("helpviewer"),QVariant(ExtraPreferences->lenHelpViewer->text()));
allPrefs->setValue(QString("language"),QVariant(ExtraPreferences->selLanguage->currentIndex()));
allPrefs->setValue(QString("showhideworkaround"),QVariant(ExtraPreferences->chkShowHideException->isChecked()));
//allPrefs->setValue(QString(""),QVariant());
allPrefs->endGroup();
allPrefs->beginGroup(QString("History"));
allPrefs->setValue(QString("maxhistory"),QVariant(max_history));
allPrefs->setValue(QString("historysize"),QVariant(current_history));
char dummy[32];
for (int i=0;i<MAX_HISTORY;i++)//always save MAX_HISTORY entries (possibly empty ones)
{
sprintf(dummy,"history%d",i);
    if (current_history>i && max_history>i)
    allPrefs->setValue(QString(dummy),QVariant(history[i]));
    else
    allPrefs->setValue(QString(dummy),QVariant(""));
}
allPrefs->endGroup();
allPrefs->beginGroup(QString("General"));
allPrefs->setValue(QString("stdOutputFormat"),QVariant(stdOutputFormat));
allPrefs->setValue(QString("activateUndoRecords"),QVariant(undo_active));
allPrefs->endGroup();
allPrefs->sync();
delete allPrefs;
}
