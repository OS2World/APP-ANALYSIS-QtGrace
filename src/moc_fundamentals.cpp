/****************************************************************************
** Meta object code from reading C++ file 'fundamentals.h'
**
** Created: Sun Apr 10 21:02:43 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fundamentals.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fundamentals.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GraphPopup[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      28,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      52,   11,   11,   11, 0x0a,
      61,   11,   11,   11, 0x0a,
      70,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      93,   11,   11,   11, 0x0a,
     102,   11,   11,   11, 0x0a,
     116,   11,   11,   11, 0x0a,
     127,   11,   11,   11, 0x0a,
     138,   11,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,
     160,   11,   11,   11, 0x0a,
     169,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GraphPopup[] = {
    "GraphPopup\0\0CreateActions()\0doNothing()\0"
    "doFocusTo()\0doShow()\0doHide()\0"
    "doDuplicate()\0doKill()\0doSwap()\0"
    "doCreateNew()\0doMove12()\0doMove21()\0"
    "doCopy12()\0doCopy21()\0update()\0"
    "update_menu_content()\0"
};

const QMetaObject GraphPopup::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_GraphPopup,
      qt_meta_data_GraphPopup, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GraphPopup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GraphPopup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GraphPopup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphPopup))
        return static_cast<void*>(const_cast< GraphPopup*>(this));
    return QMenu::qt_metacast(_clname);
}

int GraphPopup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CreateActions(); break;
        case 1: doNothing(); break;
        case 2: doFocusTo(); break;
        case 3: doShow(); break;
        case 4: doHide(); break;
        case 5: doDuplicate(); break;
        case 6: doKill(); break;
        case 7: doSwap(); break;
        case 8: doCreateNew(); break;
        case 9: doMove12(); break;
        case 10: doMove21(); break;
        case 11: doCopy12(); break;
        case 12: doCopy21(); break;
        case 13: update(); break;
        case 14: update_menu_content(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
static const uint qt_meta_data_SetPopup[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      47,   29,    9,    9, 0x0a,
      65,    9,    9,    9, 0x0a,
      81,    9,    9,    9, 0x0a,
      93,    9,    9,    9, 0x0a,
     102,    9,    9,    9, 0x0a,
     111,    9,    9,    9, 0x0a,
     126,    9,    9,    9, 0x0a,
     143,    9,    9,    9, 0x0a,
     157,    9,    9,    9, 0x0a,
     166,    9,    9,    9, 0x0a,
     179,    9,    9,    9, 0x0a,
     188,    9,    9,    9, 0x0a,
     204,    9,    9,    9, 0x0a,
     226,    9,    9,    9, 0x0a,
     247,    9,    9,    9, 0x0a,
     267,    9,    9,    9, 0x0a,
     291,    9,    9,    9, 0x0a,
     314,    9,    9,    9, 0x0a,
     338,    9,    9,    9, 0x0a,
     352,    9,    9,    9, 0x0a,
     368,    9,    9,    9, 0x0a,
     379,    9,    9,    9, 0x0a,
     399,    9,    9,    9, 0x0a,
     414,    9,    9,    9, 0x0a,
     431,    9,    9,    9, 0x0a,
     451,    9,    9,    9, 0x0a,
     462,    9,    9,    9, 0x0a,
     473,    9,    9,    9, 0x0a,
     484,    9,    9,    9, 0x0a,
     495,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SetPopup[] = {
    "SetPopup\0\0prepareForAction()\0"
    "preserveSelection\0finishAction(int)\0"
    "CreateActions()\0doNothing()\0doHide()\0"
    "doShow()\0doSendToBack()\0doBringToFront()\0"
    "doDuplicate()\0doKill()\0doKillData()\0"
    "doSwap()\0doPackAllSets()\0doEditInSpreadSheet()\0"
    "doEditInTextEditor()\0doCreateByFormula()\0"
    "doCreateInSpreadsheet()\0doCreateInTextEditor()\0"
    "doCreateFromBlockData()\0doSelectAll()\0"
    "doUnSelectAll()\0doUpdate()\0"
    "doInvertSelection()\0doShowHidden()\0"
    "doShowDataLess()\0doViewSetComments()\0"
    "doMove12()\0doMove21()\0doCopy12()\0"
    "doCopy21()\0update_menu_content()\0"
};

const QMetaObject SetPopup::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_SetPopup,
      qt_meta_data_SetPopup, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SetPopup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SetPopup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SetPopup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SetPopup))
        return static_cast<void*>(const_cast< SetPopup*>(this));
    return QMenu::qt_metacast(_clname);
}

int SetPopup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: prepareForAction(); break;
        case 1: finishAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: CreateActions(); break;
        case 3: doNothing(); break;
        case 4: doHide(); break;
        case 5: doShow(); break;
        case 6: doSendToBack(); break;
        case 7: doBringToFront(); break;
        case 8: doDuplicate(); break;
        case 9: doKill(); break;
        case 10: doKillData(); break;
        case 11: doSwap(); break;
        case 12: doPackAllSets(); break;
        case 13: doEditInSpreadSheet(); break;
        case 14: doEditInTextEditor(); break;
        case 15: doCreateByFormula(); break;
        case 16: doCreateInSpreadsheet(); break;
        case 17: doCreateInTextEditor(); break;
        case 18: doCreateFromBlockData(); break;
        case 19: doSelectAll(); break;
        case 20: doUnSelectAll(); break;
        case 21: doUpdate(); break;
        case 22: doInvertSelection(); break;
        case 23: doShowHidden(); break;
        case 24: doShowDataLess(); break;
        case 25: doViewSetComments(); break;
        case 26: doMove12(); break;
        case 27: doMove21(); break;
        case 28: doCopy12(); break;
        case 29: doCopy21(); break;
        case 30: update_menu_content(); break;
        default: ;
        }
        _id -= 31;
    }
    return _id;
}
static const uint qt_meta_data_uniList[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,    8,    8,    8, 0x0a,
      57,    8,    8,    8, 0x0a,
     120,  103,    8,    8, 0x0a,
     146,  103,    8,    8, 0x0a,
     181,  176,    8,    8, 0x0a,
     218,  199,    8,    8, 0x0a,
     245,    8,    8,    8, 0x0a,
     261,  103,    8,    8, 0x0a,
     289,  176,    8,    8, 0x0a,
     328,  326,    8,    8, 0x0a,
     358,  326,    8,    8, 0x0a,
     390,  326,    8,    8, 0x0a,
     442,  418,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_uniList[] = {
    "uniList\0\0a\0new_selection(int)\0"
    "update_number_of_entries()\0"
    "update_number_of_entries_preserve_selection()\0"
    "number,selection\0get_selection(int*,int**)\0"
    "get_selection(int*,QString**)\0item\0"
    "add_Item(QString)\0gno,keep_selection\0"
    "set_graph_number(int,bool)\0new_selection()\0"
    "set_new_selection(int,int*)\0"
    "entryDoubleClicked(QListWidgetItem*)\0"
    "e\0mousePressEvent(QMouseEvent*)\0"
    "mouseReleaseEvent(QMouseEvent*)\0"
    "keyReleaseEvent(QKeyEvent*)\0"
    "deselect,multi,all_sets\0"
    "setBehavior(bool,bool,bool)\0"
};

const QMetaObject uniList::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_uniList,
      qt_meta_data_uniList, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &uniList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *uniList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *uniList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uniList))
        return static_cast<void*>(const_cast< uniList*>(this));
    return QListWidget::qt_metacast(_clname);
}

int uniList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: new_selection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: update_number_of_entries(); break;
        case 2: update_number_of_entries_preserve_selection(); break;
        case 3: get_selection((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int**(*)>(_a[2]))); break;
        case 4: get_selection((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< QString**(*)>(_a[2]))); break;
        case 5: add_Item((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: set_graph_number((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: new_selection(); break;
        case 8: set_new_selection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2]))); break;
        case 9: entryDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 11: mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 12: keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 13: setBehavior((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void uniList::new_selection(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_Panel[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      21,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   36,    6,    6, 0x0a,
      71,   36,    6,    6, 0x0a,
     103,   36,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Panel[] = {
    "Panel\0\0mouseMoving()\0mouseClicked()\0"
    "event\0mouseMoveEvent(QMouseEvent*)\0"
    "mouseReleaseEvent(QMouseEvent*)\0"
    "paintEvent(QPaintEvent*)\0"
};

const QMetaObject Panel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_Panel,
      qt_meta_data_Panel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Panel))
        return static_cast<void*>(const_cast< Panel*>(this));
    return QLabel::qt_metacast(_clname);
}

int Panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mouseMoving(); break;
        case 1: mouseClicked(); break;
        case 2: mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Panel::mouseMoving()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Panel::mouseClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
static const uint qt_meta_data_panelWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   13,   12,   12, 0x0a,
      48,   13,   12,   12, 0x0a,
      66,   13,   12,   12, 0x0a,
      92,   86,   12,   12, 0x0a,
     112,   86,   12,   12, 0x0a,
     144,   86,   12,   12, 0x0a,
     174,   86,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_panelWindow[] = {
    "panelWindow\0\0i\0newSelection(int)\0"
    "setMarked(int)\0mouseMovedIn(int)\0"
    "mouseClickedIn(int)\0event\0leaveEvent(QEvent*)\0"
    "mouseReleaseEvent(QMouseEvent*)\0"
    "mousePressEvent(QMouseEvent*)\0"
    "mouseMoveEvent(QMouseEvent*)\0"
};

const QMetaObject panelWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_panelWindow,
      qt_meta_data_panelWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &panelWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *panelWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *panelWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_panelWindow))
        return static_cast<void*>(const_cast< panelWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int panelWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setMarked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: mouseMovedIn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: mouseClickedIn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: leaveEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 5: mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void panelWindow::newSelection(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_newCombo[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   10,    9,    9, 0x0a,
      66,    9,   62,    9, 0x0a,
      81,    9,    9,    9, 0x0a,
      93,   10,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_newCombo[] = {
    "newCombo\0\0index\0currentIndexChanged(int)\0"
    "setCurrentIndex(int)\0int\0currentIndex()\0"
    "showPopup()\0wrapperSetCurrentIndex(int)\0"
};

const QMetaObject newCombo::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_newCombo,
      qt_meta_data_newCombo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &newCombo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *newCombo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *newCombo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_newCombo))
        return static_cast<void*>(const_cast< newCombo*>(this));
    return QComboBox::qt_metacast(_clname);
}

int newCombo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = currentIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: showPopup(); break;
        case 4: wrapperSetCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void newCombo::currentIndexChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_fitLine[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      44,    9,    8,    8, 0x0a,
      87,   85,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_fitLine[] = {
    "fitLine\0\0value,active,lowerBound,upperBound\0"
    "getValues(double&,bool&,double&,double&)\0"
    "t\0constr_check(int)\0"
};

const QMetaObject fitLine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fitLine,
      qt_meta_data_fitLine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fitLine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fitLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fitLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fitLine))
        return static_cast<void*>(const_cast< fitLine*>(this));
    return QWidget::qt_metacast(_clname);
}

int fitLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: getValues((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: constr_check((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_axisLine[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_axisLine[] = {
    "axisLine\0"
};

const QMetaObject axisLine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_axisLine,
      qt_meta_data_axisLine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &axisLine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *axisLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *axisLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_axisLine))
        return static_cast<void*>(const_cast< axisLine*>(this));
    return QWidget::qt_metacast(_clname);
}

int axisLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_headLine[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   10,    9,    9, 0x0a,
      50,   42,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_headLine[] = {
    "headLine\0\0i\0col_pressed(int)\0pressed(int)\0"
    "columns\0resize(int)\0"
};

const QMetaObject headLine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_headLine,
      qt_meta_data_headLine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &headLine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *headLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *headLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_headLine))
        return static_cast<void*>(const_cast< headLine*>(this));
    return QWidget::qt_metacast(_clname);
}

int headLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: col_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: resize((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void headLine::col_pressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_spreadLine[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      34,   26,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_spreadLine[] = {
    "spreadLine\0\0clickSelect()\0columns\0"
    "resize(int)\0"
};

const QMetaObject spreadLine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_spreadLine,
      qt_meta_data_spreadLine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &spreadLine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *spreadLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *spreadLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_spreadLine))
        return static_cast<void*>(const_cast< spreadLine*>(this));
    return QWidget::qt_metacast(_clname);
}

int spreadLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clickSelect(); break;
        case 1: resize((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_spreadSheet[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   23,   12,   12, 0x0a,
      44,   23,   12,   12, 0x0a,
      70,   62,   12,   12, 0x0a,
      86,   12,   12,   12, 0x0a,
     104,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_spreadSheet[] = {
    "spreadSheet\0\0changed()\0nr\0clickHHeader(int)\0"
    "clickVHeader(int)\0row,col\0resize(int,int)\0"
    "generate_layout()\0entryChanged()\0"
};

const QMetaObject spreadSheet::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_spreadSheet,
      qt_meta_data_spreadSheet, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &spreadSheet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *spreadSheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *spreadSheet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_spreadSheet))
        return static_cast<void*>(const_cast< spreadSheet*>(this));
    return QWidget::qt_metacast(_clname);
}

int spreadSheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changed(); break;
        case 1: clickHHeader((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: clickVHeader((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: resize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: generate_layout(); break;
        case 5: entryChanged(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void spreadSheet::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_stdSlider[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   10,   11,   10, 0x0a,
      28,   10,   11,   10, 0x0a,
      48,   46,   10,   10, 0x0a,
      65,   10,   61,   10, 0x0a,
      73,   46,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_stdSlider[] = {
    "stdSlider\0\0QSize\0sizeHint()\0"
    "minimumSizeHint()\0i\0changed(int)\0int\0"
    "value()\0setValue(int)\0"
};

const QMetaObject stdSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_stdSlider,
      qt_meta_data_stdSlider, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &stdSlider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *stdSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *stdSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_stdSlider))
        return static_cast<void*>(const_cast< stdSlider*>(this));
    return QWidget::qt_metacast(_clname);
}

int stdSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QSize _r = sizeHint();
            if (_a[0]) *reinterpret_cast< QSize*>(_a[0]) = _r; }  break;
        case 1: { QSize _r = minimumSizeHint();
            if (_a[0]) *reinterpret_cast< QSize*>(_a[0]) = _r; }  break;
        case 2: changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { int _r = value();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_FontSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   13,   14,   13, 0x0a,
      35,   33,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FontSelector[] = {
    "FontSelector\0\0int\0currentIndex()\0i\0"
    "setCurrentIndex(int)\0"
};

const QMetaObject FontSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FontSelector,
      qt_meta_data_FontSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FontSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FontSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FontSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FontSelector))
        return static_cast<void*>(const_cast< FontSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int FontSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = currentIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_PositionSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   17,   18,   17, 0x0a,
      37,   17,   18,   17, 0x0a,
      54,   52,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PositionSelector[] = {
    "PositionSelector\0\0int\0currentIndex()\0"
    "currentValue()\0i\0setCurrentIndex(int)\0"
};

const QMetaObject PositionSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PositionSelector,
      qt_meta_data_PositionSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PositionSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PositionSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PositionSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PositionSelector))
        return static_cast<void*>(const_cast< PositionSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int PositionSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = currentIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = currentValue();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_JustificationSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   22,   23,   22, 0x0a,
      44,   42,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_JustificationSelector[] = {
    "JustificationSelector\0\0int\0currentIndex()\0"
    "i\0setCurrentIndex(int)\0"
};

const QMetaObject JustificationSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_JustificationSelector,
      qt_meta_data_JustificationSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &JustificationSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *JustificationSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *JustificationSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JustificationSelector))
        return static_cast<void*>(const_cast< JustificationSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int JustificationSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = currentIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_ColorSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   14,   42,   14, 0x0a,
      61,   15,   14,   14, 0x0a,
      82,   15,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ColorSelector[] = {
    "ColorSelector\0\0i\0currentIndexChanged(int)\0"
    "int\0currentIndex()\0setCurrentIndex(int)\0"
    "panelIndexChanged(int)\0"
};

const QMetaObject ColorSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ColorSelector,
      qt_meta_data_ColorSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ColorSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ColorSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ColorSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorSelector))
        return static_cast<void*>(const_cast< ColorSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int ColorSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { int _r = currentIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: panelIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ColorSelector::currentIndexChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_StdSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   13,   12,   12, 0x0a,
      48,   36,   12,   12, 0x0a,
      95,   76,   12,   12, 0x0a,
     132,   12,  128,   12, 0x0a,
     147,   12,  128,   12, 0x0a,
     164,  162,   12,   12, 0x0a,
     185,  162,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StdSelector[] = {
    "StdSelector\0\0values\0setValues(int*)\0"
    "number,entr\0setNewEntries(int,QString*)\0"
    "number,entr,values\0setNewEntries(int,QString*,int*)\0"
    "int\0currentIndex()\0currentValue()\0i\0"
    "setCurrentIndex(int)\0setCurrentValue(int)\0"
};

const QMetaObject StdSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StdSelector,
      qt_meta_data_StdSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StdSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StdSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StdSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StdSelector))
        return static_cast<void*>(const_cast< StdSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int StdSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setValues((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 1: setNewEntries((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString*(*)>(_a[2]))); break;
        case 2: setNewEntries((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString*(*)>(_a[2])),(*reinterpret_cast< int*(*)>(_a[3]))); break;
        case 3: { int _r = currentIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = currentValue();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: setCurrentValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
static const uint qt_meta_data_LineStyleSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   18,   19,   18, 0x0a,
      40,   38,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LineStyleSelector[] = {
    "LineStyleSelector\0\0int\0currentIndex()\0"
    "i\0setCurrentIndex(int)\0"
};

const QMetaObject LineStyleSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LineStyleSelector,
      qt_meta_data_LineStyleSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LineStyleSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LineStyleSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LineStyleSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LineStyleSelector))
        return static_cast<void*>(const_cast< LineStyleSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int LineStyleSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = currentIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_FillPatternSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   20,   21,   20, 0x0a,
      42,   40,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FillPatternSelector[] = {
    "FillPatternSelector\0\0int\0currentIndex()\0"
    "i\0setCurrentIndex(int)\0"
};

const QMetaObject FillPatternSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FillPatternSelector,
      qt_meta_data_FillPatternSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FillPatternSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FillPatternSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FillPatternSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FillPatternSelector))
        return static_cast<void*>(const_cast< FillPatternSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int FillPatternSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = currentIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_OrderSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   14,   15,   14, 0x0a,
      36,   34,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OrderSelector[] = {
    "OrderSelector\0\0int\0currentIndex()\0i\0"
    "setCurrentIndex(int)\0"
};

const QMetaObject OrderSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OrderSelector,
      qt_meta_data_OrderSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OrderSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OrderSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OrderSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrderSelector))
        return static_cast<void*>(const_cast< OrderSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int OrderSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = currentIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_LineWidthSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   18,   19,   18, 0x0a,
      36,   34,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LineWidthSelector[] = {
    "LineWidthSelector\0\0double\0value()\0i\0"
    "setValue(double)\0"
};

const QMetaObject LineWidthSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LineWidthSelector,
      qt_meta_data_LineWidthSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LineWidthSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LineWidthSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LineWidthSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LineWidthSelector))
        return static_cast<void*>(const_cast< LineWidthSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int LineWidthSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { double _r = value();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 1: setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_stdIntSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   15,   16,   15, 0x0a,
      30,   28,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_stdIntSelector[] = {
    "stdIntSelector\0\0int\0value()\0i\0"
    "setValue(int)\0"
};

const QMetaObject stdIntSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_stdIntSelector,
      qt_meta_data_stdIntSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &stdIntSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *stdIntSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *stdIntSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_stdIntSelector))
        return static_cast<void*>(const_cast< stdIntSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int stdIntSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = value();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_stdLineEdit[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   12,   13,   12, 0x0a,
      33,   28,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_stdLineEdit[] = {
    "stdLineEdit\0\0QString\0text()\0text\0"
    "setText(QString)\0"
};

const QMetaObject stdLineEdit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_stdLineEdit,
      qt_meta_data_stdLineEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &stdLineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *stdLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *stdLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_stdLineEdit))
        return static_cast<void*>(const_cast< stdLineEdit*>(this));
    return QWidget::qt_metacast(_clname);
}

int stdLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = text();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: setText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_stdButtonGroup[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_stdButtonGroup[] = {
    "stdButtonGroup\0"
};

const QMetaObject stdButtonGroup::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_stdButtonGroup,
      qt_meta_data_stdButtonGroup, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &stdButtonGroup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *stdButtonGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *stdButtonGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_stdButtonGroup))
        return static_cast<void*>(const_cast< stdButtonGroup*>(this));
    return QWidget::qt_metacast(_clname);
}

int stdButtonGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_dirList[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_dirList[] = {
    "dirList\0"
};

const QMetaObject dirList::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_dirList,
      qt_meta_data_dirList, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dirList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dirList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dirList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dirList))
        return static_cast<void*>(const_cast< dirList*>(this));
    return QTreeView::qt_metacast(_clname);
}

int dirList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_FileSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   14,   13,   13, 0x05,
      46,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     114,   79,   13,   13, 0x0a,
     164,   13,   13,   13, 0x0a,
     173,   13,   13,   13, 0x0a,
     193,  187,   13,   13, 0x0a,
     219,  187,   13,   13, 0x0a,
     250,  187,   13,   13, 0x0a,
     275,  187,   13,   13, 0x0a,
     305,   13,   13,   13, 0x0a,
     327,   13,   13,   13, 0x0a,
     346,   13,   13,   13, 0x0a,
     359,  357,   13,   13, 0x0a,
     401,  381,   13,   13, 0x0a,
     440,  357,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FileSelector[] = {
    "FileSelector\0\0selection\0newSelection(QString)\0"
    "newSelectionDoubleClick(QString)\0"
    "dir,PathAndExtension,DirectoryOnly\0"
    "GeneratePathWithExtension(QDir,QString&,QString&)\0"
    "doGoUp()\0doStdDialog()\0index\0"
    "FileSelected(QModelIndex)\0"
    "FileDoubleClicked(QModelIndex)\0"
    "DirSelected(QModelIndex)\0"
    "DirDoubleClicked(QModelIndex)\0"
    "showFilesLikeFilter()\0newFilterEntered()\0"
    "doSetCWD()\0i\0toggleHiddenFile(int)\0"
    "directory,extension\0"
    "setFilterFromExtern(QString&,QString&)\0"
    "currentDirChanged(int)\0"
};

const QMetaObject FileSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FileSelector,
      qt_meta_data_FileSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileSelector))
        return static_cast<void*>(const_cast< FileSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int FileSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newSelection((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: newSelectionDoubleClick((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: GeneratePathWithExtension((*reinterpret_cast< QDir(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: doGoUp(); break;
        case 4: doStdDialog(); break;
        case 5: FileSelected((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: FileDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: DirSelected((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: DirDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: showFilesLikeFilter(); break;
        case 10: newFilterEntered(); break;
        case 11: doSetCWD(); break;
        case 12: toggleHiddenFile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: setFilterFromExtern((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: currentDirChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void FileSelector::newSelection(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileSelector::newSelectionDoubleClick(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_stdStartStop[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   13,   14,   13, 0x0a,
      29,   13,   14,   13, 0x0a,
      40,   13,   36,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_stdStartStop[] = {
    "stdStartStop\0\0double\0start()\0stop()\0"
    "int\0length()\0"
};

const QMetaObject stdStartStop::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_stdStartStop,
      qt_meta_data_stdStartStop, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &stdStartStop::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *stdStartStop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *stdStartStop::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_stdStartStop))
        return static_cast<void*>(const_cast< stdStartStop*>(this));
    return QWidget::qt_metacast(_clname);
}

int stdStartStop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { double _r = start();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 1: { double _r = stop();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 2: { int _r = length();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_stdSetTypeSelector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   20,   19,   19, 0x0a,
      46,   40,   19,   19, 0x0a,
      70,   19,   66,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_stdSetTypeSelector[] = {
    "stdSetTypeSelector\0\0sa\0setShowAll(bool)\0"
    "count\0setColumnCount(int)\0int\0"
    "getColumnCount()\0"
};

const QMetaObject stdSetTypeSelector::staticMetaObject = {
    { &StdSelector::staticMetaObject, qt_meta_stringdata_stdSetTypeSelector,
      qt_meta_data_stdSetTypeSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &stdSetTypeSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *stdSetTypeSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *stdSetTypeSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_stdSetTypeSelector))
        return static_cast<void*>(const_cast< stdSetTypeSelector*>(this));
    return StdSelector::qt_metacast(_clname);
}

int stdSetTypeSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StdSelector::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setShowAll((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: setColumnCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = getColumnCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
