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
#ifndef FUNDAMENTALS_H
#define FUNDAMENTALS_H

#include <iostream>
#include <QtGui>
#include <fstream>
#include <cstring>
#include <QListWidget>
#include <QMouseEvent>
#include <QMenu>
#include <QMenuBar>
#include <QMenu>
#include <QMenuBar>

#include "noxprotos.h"
#include "t1fonts.h"
#include "parser.h"
#include "graphs.h"

#define DIRLIST 0
#define FILELIST 1

#define GRAPHLIST 0
#define SETLIST 1
#define TEXTLIST 2
#define SETCHOICE 3

#define DO_NOT_PRESERVE_SELECTION 0
#define DO_PRESERVE_SELECTION 1

using namespace std;

struct komplex
{
double real;
double imag;
};
struct komplex add_komplex(struct komplex a,struct komplex b);
struct komplex sub_komplex(struct komplex a,struct komplex b);
struct komplex mult_komplex(struct komplex a,struct komplex b);
struct komplex div_komplex(struct komplex a,struct komplex b);
struct komplex pow_komplex(struct komplex a,double n);

class uniList;

class GraphPopup:public QMenu
{
Q_OBJECT
public:
int selected_no;
int number_of_selected_graphs;
int * selected_graphs;

uniList * par;

GraphPopup(uniList *parent=0);
~GraphPopup();

QAction *actLabel,*actFocusTo,*actShow,*actHide,*actDuplicate,*actKill,*actSwap,*actCreateNew;
QAction *actCopy12,*actCopy21,*actMove12,*actMove21;

public slots:
void CreateActions(void);
void doNothing(void);
void doFocusTo(void);
void doShow(void);
void doHide(void);
void doDuplicate(void);
void doKill(void);
void doSwap(void);
void doCreateNew(void);
void doMove12(void);
void doMove21(void);
void doCopy12(void);
void doCopy21(void);
void update(void);
void update_menu_content(void);
};

class SetPopup:public QMenu
{
Q_OBJECT
public:
int selected_graph;//graph the selected sets belong to
int number_of_selected_sets;
int * selected_sets;

uniList * par;
SetPopup(uniList *parent=0);
~SetPopup();

QMenu * mnuEdit;
QMenu * mnuCreateNew;
QMenu * mnuSelectorOperations;
QAction * actLabel;
QAction * actHide,*actBringToFront,*actSendToBack,*actPackAllSets;
QAction * actShow,*actDuplicate,*actKill,*actKillData,*actSwap;
QAction * actCreateByFormula,* actCreateInSpreadsheet,* actCreateInTextEditor,* actCreateFromBlockData;
QAction * actEditInSpreadsheet,* actEditInTextEditor;
QAction * actViewSetComments,*actShowDataLess,*actShowHidden,*actSelectAll,*actUnselectAll,*actInvertSelection,*actUpdate;
QAction * actCopy12,*actCopy21,*actMove12,*actMove21;

public slots:
void prepareForAction(void);
void finishAction(int preserveSelection);
void CreateActions(void);
void doNothing(void);
void doHide(void);
void doShow(void);
void doSendToBack(void);
void doBringToFront(void);
void doDuplicate(void);
void doKill(void);
void doKillData(void);
void doSwap(void);
void doPackAllSets(void);
void doEditInSpreadSheet(void);
void doEditInTextEditor(void);
void doCreateByFormula(void);
void doCreateInSpreadsheet(void);
void doCreateInTextEditor(void);
void doCreateFromBlockData(void);
void doSelectAll(void);
void doUnSelectAll(void);
void doUpdate(void);
void doInvertSelection(void);
void doShowHidden(void);
void doShowDataLess(void);
void doViewSetComments(void);
void doMove12(void);
void doMove21(void);
void doCopy12(void);
void doCopy21(void);
void update_menu_content(void);
};

class uniList:public QListWidget
{
Q_OBJECT
public:
int datType;
int number_of_entries;
int gr_no;
int * entries;//set or graph numbers (because hidden numbers are not displayed --> item-number != set-number)
QString * text_entries;//only used in TEXTLIST
bool show_hidden;
bool show_data_less;
bool show_comments;

bool deselect_possible;
bool show_all_sets_marker;

class uniList * partner;

SetPopup * popupMenu1;
GraphPopup * popupMenu2;

uniList(int type,QWidget *parent=0);
~uniList();

public slots:
void update_number_of_entries(void);//reread and display entries - selection is cleared
void update_number_of_entries_preserve_selection(void);//same as above, selection is not cleared
void get_selection(int * number,int ** selection);
void get_selection(int * number,QString ** selection);//only useful for TEXTLIST
void add_Item(QString item);
void set_graph_number(int gno,bool keep_selection);
void new_selection(void);
void set_new_selection(int number,int * selection);
void entryDoubleClicked(QListWidgetItem * item);
virtual void mousePressEvent(QMouseEvent * e);
virtual void mouseReleaseEvent(QMouseEvent * e );
virtual void keyReleaseEvent(QKeyEvent * e);
void setBehavior(bool deselect,bool multi,bool all_sets);
signals:
void new_selection(int a);
};

class Panel:public QLabel
{
Q_OBJECT
public:
Panel(QPixmap * pix,QWidget * parent=0);
QPixmap * p;
bool inpaint;
public slots:
void mouseMoveEvent( QMouseEvent * event );
void mouseReleaseEvent(QMouseEvent *event);
void paintEvent(QPaintEvent *event);
signals:
void mouseMoving(void);
void mouseClicked(void);
};

class panelWindow:public QDialog
{
Q_OBJECT
public:
panelWindow(int rows,int cols,QPixmap ** pix,QWidget * parent=0);

class Panel ** lblPanel;

QTime * clickTime;
QGridLayout * layout;
QHBoxLayout * layout0;
QFrame * frm;
QPixmap ** pixmaps;
QSignalMapper * signalMapper1;
QSignalMapper * signalMapper2;
int row_count,col_count,number_of_elements;
int marked;//the always-raised-element
int highlighted;//the sunken element while mouse is over it
int elementWidth,elementHeight;
int pressed;
public slots:
void setMarked(int i);//set the 
void mouseMovedIn(int i);//MouseMoved in one of the Panels
void mouseClickedIn(int i);//Users clicked on one of the Panels
virtual void leaveEvent( QEvent * event );
void mouseReleaseEvent(QMouseEvent *event);
void mousePressEvent(QMouseEvent *event);
void mouseMoveEvent(QMouseEvent * event);
signals:
void newSelection(int i);
};

class newCombo:public QComboBox
{
Q_OBJECT
public:
newCombo(int rows,int cols,QPixmap ** pix,QString ** titles,bool showTextOnly=true,QWidget * parent=0);

panelWindow * panels;
QString * title_strings;
int selection;
bool text_only;
public slots:
void setCurrentIndex(int index);
int currentIndex(void);
virtual void showPopup();
private slots:
void wrapperSetCurrentIndex(int index);
signals:
void currentIndexChanged( int index );
};

class fitLine:public QWidget
{
Q_OBJECT
public:
fitLine(QWidget * parent=0,int nr=0);

QLabel * lblA;
QLabel * lblABounds;
QCheckBox * chkBonds;
QLineEdit * ledValue;
QLineEdit * ledLowerBound;
QLineEdit * ledHighterBound;
QHBoxLayout * layout;
public slots:
void getValues(double & value,bool & active,double & lowerBound,double & upperBound);
void constr_check(int t);
};

class axisLine:public QWidget
{
Q_OBJECT
public:
axisLine(QWidget * parent=0,int nr=0);

QLabel * lblNr;
QLineEdit * ledLocation;
QLineEdit * ledLabel;
QHBoxLayout * layout;
public slots:
};

class headLine:public QWidget
{
Q_OBJECT
public:
headLine(QWidget * parent=0,int columns=0);
int cols;
QPushButton * cmdColHead[6];
QHBoxLayout * layout;
QWidget * empty;
QSignalMapper * signalMapper;
public slots:
void pressed(int i);
void resize(int columns);
signals:
void col_pressed(int i);
};

class spreadLine:public QWidget
{
Q_OBJECT
public:
spreadLine(QWidget * parent=0,int row_nr=0,int columns=0);
~spreadLine();
bool marked;
int row;
int cols;
QPushButton * cmdSelect;
QLineEdit * ledInput[6];
QHBoxLayout * layout;
public slots:
void clickSelect(void);
void resize(int columns);
};

class spreadSheet:public QWidget
{
Q_OBJECT
public:
spreadSheet(QWidget * parent,int type,int row_count,int col_count);
~spreadSheet();
int rows;//rows with actual inputs
int cols;
int sheet_type;//type=0-->spreadsheet, type=1-->fit-spreadsheet, type=3-->axis-properties
int stdWidth,stdHeight;

fitLine ** fitlines;
axisLine ** axislines;
headLine * headline;
spreadLine ** spreadlines;

QWidget * empty;
QSignalMapper * signalMapper;
QVBoxLayout * layout;
public slots:
void clickHHeader(int nr);
void clickVHeader(int nr);
void resize(int row,int col);
void generate_layout(void);
void entryChanged(void);
signals:
void changed(void);
};

class stdSlider:public QWidget
{
Q_OBJECT
public:
stdSlider(QWidget * parent,QString label,int min,int max);
QLabel * Indicator;
QLabel * lblText;
QSlider * sldSlider;
int textHeight;
virtual void resizeEvent( QResizeEvent * e);
public slots:
virtual QSize sizeHint (void);
virtual QSize minimumSizeHint(void);
void changed(int i);
int value(void);
void setValue(int i);
};

class FontSelector:public QWidget
{
Q_OBJECT
public:
FontSelector(QWidget * parent=0);

QLabel * lblText;
QComboBox * cmbFontSelect;
QHBoxLayout * layout;

public slots:
int currentIndex(void);
void setCurrentIndex(int i);
};

class PositionSelector:public QWidget
{
Q_OBJECT
public:
PositionSelector(QWidget * parent=0);

QLabel * lblText;
QComboBox * cmbPositionSelect;
QHBoxLayout * layout;

public slots:
int currentIndex(void);
int currentValue(void);
void setCurrentIndex(int i);
};

class JustificationSelector:public QWidget
{
Q_OBJECT
public:
JustificationSelector(QWidget * parent=0);

QLabel * lblText;
//QComboBox * cmbJustSelect;
newCombo * cmbJustSelect;
QHBoxLayout * layout;
QString ** just_names;
public slots:
int currentIndex(void);
void setCurrentIndex(int i);
};

class ColorSelector:public QWidget
{
Q_OBJECT
public:
ColorSelector(QWidget * parent=0);

QLabel * lblText;
///QComboBox * cmbColorSelect;
newCombo * cmbColorSelect;
QHBoxLayout * layout;

public slots:
int currentIndex(void);
void setCurrentIndex(int i);
private slots:
void panelIndexChanged(int i);
signals:
void currentIndexChanged(int i);
};

class StdSelector:public QWidget
{
Q_OBJECT
public:
StdSelector(QWidget * parent=0);
StdSelector(QWidget * parent,QString label,int number,QString * entr);
~StdSelector();

int number_of_entries;
int * entryValues;
QString * entries;

QLabel * lblText;
QComboBox * cmbSelect;
QHBoxLayout * layout;

public slots:
void setValues(int * values);
void setNewEntries(int number,QString * entr);
void setNewEntries(int number,QString * entr,int * values);
int currentIndex(void);
int currentValue(void);
void setCurrentIndex(int i);
void setCurrentValue(int i);
};

class LineStyleSelector:public QWidget
{
Q_OBJECT
public:
LineStyleSelector(QWidget * parent=0);

QString ** LineNames;
QLabel * lblText;
//QComboBox * cmbStyleSelect;
newCombo * cmbStyleSelect;
QHBoxLayout * layout;

public slots:
int currentIndex(void);
void setCurrentIndex(int i);
};

class FillPatternSelector:public QWidget
{
Q_OBJECT
public:
FillPatternSelector(QWidget * parent=0);

QString ** PatternNames;
QLabel * lblText;
//QComboBox * cmbFillPattern;
newCombo * cmbFillPattern;
QHBoxLayout * layout;

public slots:
int currentIndex(void);
void setCurrentIndex(int i);
};

class OrderSelector:public QWidget
{
Q_OBJECT
public:
OrderSelector(QWidget * parent=0);

QString ** OrderNames;
QLabel * lblText;
newCombo * cmbOrderPattern;
QHBoxLayout * layout;
public slots:
int currentIndex(void);
void setCurrentIndex(int i);
};

class LineWidthSelector:public QWidget
{
Q_OBJECT
public:
LineWidthSelector(QWidget * parent=0);
QLabel * lblText;
QDoubleSpinBox * spnLineWidth;
QHBoxLayout * layout;
public slots:
double value(void);
void setValue(double i);
};

class stdIntSelector:public QWidget
{
Q_OBJECT
public:
stdIntSelector(QWidget * parent,QString label,int min,int max);
QLabel * lblText;
QSpinBox * spnInt;
QHBoxLayout * layout;
public slots:
int value(void);
void setValue(int i);
};

class stdLineEdit:public QWidget
{
Q_OBJECT
public:
stdLineEdit(QWidget * parent,QString label);

QLabel * lblText;
QLineEdit * lenText;
QHBoxLayout * layout;
public slots:
QString text(void);
void setText(QString text);
};

class stdButtonGroup:public QWidget
{
Q_OBJECT
public:
stdButtonGroup(QWidget * parent=0,bool appl=true,bool acc=true,bool help=false);

bool showAccept;
bool showApply;
bool showHelp;

QPushButton * cmdAccept;
QPushButton * cmdApply;
QPushButton * cmdClose;
QPushButton * cmdHelp;
QHBoxLayout * layout;
public slots:

};

class dirList:public QTreeView
{
Q_OBJECT
public:
dirList(QWidget * parent=0,int type=DIRLIST);
int listtype;
QDirModel *model;

public slots:

};

class FileSelector:public QWidget
{
Q_OBJECT
public:
FileSelector(QWidget * parent=0);

QLabel * lblFilter;
QLabel * lblDirs;
QLabel * lblFiles;
QLineEdit * ledFilter;
QListView * DirList;
QListView * FileList;
QCheckBox * chkShowHiddenFiles;
QGroupBox * grpChDir;
QHBoxLayout * layout0;
StdSelector * selChdir;
QPushButton * cmdSetCwd;
QPushButton * cmdGoUp;
QPushButton * cmdStdDialog;

QDirModel *modelDirs;
QDirModel *modelFiles;

QString filter;
QString filterExtension;

bool forRead;//select only existing files
bool doubleclickfile;
bool doubleclickdir;
#ifdef WINDOWS_SYSTEM
bool onHighestLevel;//for non-Unix-Systems
#endif
QString separator;
QString currentDir;
QString selectedFile;
QString selectedDir;

QGridLayout * layout;
public slots:
void GeneratePathWithExtension(QDir dir,QString & PathAndExtension,QString & DirectoryOnly);
void doGoUp(void);//Go upwards one directory
void doStdDialog(void);//Open the OS standard dialog for file opening / saving
void FileSelected(const QModelIndex & index );
void FileDoubleClicked( const QModelIndex & index );
void DirSelected(const QModelIndex & index );
void DirDoubleClicked( const QModelIndex & index );
void showFilesLikeFilter(void);
void newFilterEntered(void);
void doSetCWD(void);
void toggleHiddenFile(int i);
void setFilterFromExtern(QString & directory,QString & extension);
void currentDirChanged(int i);
signals:
void newSelection(QString selection);
void newSelectionDoubleClick(QString selection);
};

class stdStartStop:public QWidget
{
Q_OBJECT
public:
stdStartStop(QWidget * parent=0);

QLabel * lblStart;
QLabel * lblStop;
QLabel * lblLength;
QLineEdit * ledStart;
QLineEdit * ledStop;
QLineEdit * ledLength;

QHBoxLayout * layout;

bool error;

public slots:
double start(void);
double stop(void);
int length(void);
};

class stdSetTypeSelector:public StdSelector
{
Q_OBJECT
public:
stdSetTypeSelector(QWidget * parent=0);
int column_count;
bool showAll;
public slots:
void setShowAll(bool sa);
void setColumnCount(int count);
int getColumnCount(void);
};

/*int GetSpinChoice(stdIntSelector * s);
double GetSpinChoice(LineWidthSelector * s);
double GetSpinChoice(QDoubleSpinBox * s);    
bool GetToggleButtonState(QCheckBox * c);*/

#define NUMBER_OF_COLUMN_FORMATS 13

#define COLUMN_OFFSET 0
#define COLUMN_SIG_CHAR 1
#define COLUMN_USIG_CHAR 2
#define COLUMN_SIG_SHORT 3
#define COLUMN_USIG_SHORT 4
#define COLUMN_SIG_INT 5
#define COLUMN_USIG_INT 6
#define COLUMN_SIG_LONG 7
#define COLUMN_USIG_LONG 8
#define COLUMN_FLOAT 9
#define COLUMN_DOUBLE 10
#define COLUMN_LONG_DOUBLE 11
#define COLUMN_STRING 12

#define NUMBER_OF_IMPORT_DESTINATIONS 27

#define IMPORT_TO_NONE 0
#define IMPORT_TO_TITLE 1
#define IMPORT_TO_X 2
#define IMPORT_TO_Y 3
#define IMPORT_TO_Y1 4
#define IMPORT_TO_Y2 5
#define IMPORT_TO_Y3 6
#define IMPORT_TO_Y4 7
#define IMPORT_TO_X0 8
#define IMPORT_TO_DELTAX 9
#define IMPORT_TO_XTITLE 10
#define IMPORT_TO_YTITLE 11
#define IMPORT_TO_XFACTOR 12
#define IMPORT_TO_YFACTOR 13
#define IMPORT_TO_Y1FACTOR 14
#define IMPORT_TO_Y2FACTOR 15
#define IMPORT_TO_Y3FACTOR 16
#define IMPORT_TO_Y4FACTOR 17
#define IMPORT_TO_SUBTITLE 18
#define IMPORT_TO_NUMBER_OF_DATA 19
#define IMPORT_TO_NUMBER_OF_CHANNELS 20
#define IMPORT_TO_DATA_SIZE 21
#define IMPORT_TO_DATA_SIZE_BIT 22
#define IMPORT_TO_DATA_SAMPLING_RATE 23
#define IMPORT_TO_WHOLE_DATA_BLOCK_SIZE 24
#define IMPORT_TO_SINGLE_DATA_BLOCK_SIZE 25
#define IMPORT_TO_SET_LEGEND 26
//#define IMPORT_TO_ 22

//#define IMPORT_TO_DELTAX 19

struct ColumnFormat
{
int format;
int size;
};

struct BinReadInstructions
{
unsigned int length_of_header;//number of bytes at the beginning of the file before reading starts
unsigned int column_count;//number of columns that are saved in the binary file
struct ColumnFormat * column_type;//tells us the number of bytes for the representation of a specific column and its format
unsigned int datasets_to_read;//max set-count to be read
bool read_until_end_is_reached;//read as much as possible
unsigned int n_columns_to_read;//number of columns to be saved
unsigned int * col_numbers_to_read;//which columns are to be read and where they are to be stored
};

void LoadBinaryData(int gno,int setno,int settype,char * filename,struct BinReadInstructions inst);

extern int GetSpinChoice(stdIntSelector * s);
extern double GetSpinChoice(LineWidthSelector * s);
extern double GetSpinChoice(QDoubleSpinBox * s);
extern bool GetToggleButtonState(QCheckBox * c);
extern bool GetToggleButtonState(QAction * c);
extern int GetChoice(StdSelector * s);
extern int GetChoice(PositionSelector * s);
extern int GetOptionChoice(ColorSelector * s);
extern int GetOptionChoice(LineStyleSelector * s);
extern int GetOptionChoice(FillPatternSelector * s);
extern int GetOptionChoice(JustificationSelector * s);
extern int GetOptionChoice(FontSelector * s);
extern int GetOptionChoice(QComboBox * c);
extern int GetOptionChoice(StdSelector * sel);
extern double GetCharSizeChoice(stdSlider * sel);
extern double GetAngleChoice(stdSlider * sel);
extern char * GetTextString(stdLineEdit * led);
extern void SetToggleButtonState(QCheckBox * cb, int v);
extern void SetChoice(StdSelector * sel,int v);
extern void SetChoice(PositionSelector * sel,int v);
extern void SetOptionChoice(ColorSelector * sel,int v);
extern void SetOptionChoice(LineStyleSelector * sel,int v);
extern void SetOptionChoice(FillPatternSelector * sel,int v);
extern void SetOptionChoice(FontSelector * sel,int v);
extern void SetOptionChoice(JustificationSelector * sel,int v);
extern void SetOptionChoice(StdSelector * sel,int v);
extern void SetSpinChoice(stdIntSelector * sel, double v);
extern void SetSpinChoice(LineWidthSelector * sel, double v);
extern void SetScaleValue(stdSlider * sel, int v);
extern void SetCharSizeChoice(stdSlider * sel,double v);
extern void SetAngleChoice(stdSlider * sel,double v);
extern void SetTextString(stdLineEdit * led,char * st);
extern void SetLabel(QLabel * lab,char * st);
extern void xv_setstr(stdLineEdit * led, char * text);
extern void xv_setstr(QLineEdit * led, char * text);
extern char * xv_getstr(stdLineEdit * led);
extern char * xv_getstr(QLineEdit * led);
extern void SetSensitive(stdLineEdit * led, bool e);
extern void SetSensitive(QLineEdit * led, bool e);
extern void SetSensitive(StdSelector * led, bool e);
extern void SetSensitive(QPushButton * led, bool e);
extern void SetSensitive(QCheckBox * led, bool e);
extern int GetScaleValue(stdSlider * sel);
extern int xv_evalexpr(stdLineEdit * led,double * val);
extern int xv_evalexpri(stdLineEdit * led,int * val);
extern int xv_evalexpr(QLineEdit * led,double * val);
extern int xv_evalexpri(QLineEdit * led,int * val);
extern void SelectListChoice(uniList * list,int nr);
extern void SelectListChoices(uniList * list,int count,int * nrs);
extern int GetListChoices(uniList * list, int ** sel);
extern int GetSelectedSets(uniList * list, int ** sel);
extern int GetSelectedSet(uniList * list);
extern int GetSingleListChoice(uniList * list, int * sel);

#endif
