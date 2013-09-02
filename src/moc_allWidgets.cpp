/****************************************************************************
** Meta object code from reading C++ file 'allWidgets.h'
**
** Created: Sun Apr 10 21:02:30 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "allWidgets.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'allWidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_grpSelect[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      48,   38,   10,   10, 0x0a,
      90,   73,   10,   10, 0x0a,
     127,  123,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_grpSelect[] = {
    "grpSelect\0\0update_number_of_entries()\0"
    "gno,setno\0mark_single_set(int,int)\0"
    "gno,nsets,setnos\0mark_multiple_sets(int,int,int*)\0"
    "gno\0set_graph_nr(int)\0"
};

const QMetaObject grpSelect::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_grpSelect,
      qt_meta_data_grpSelect, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &grpSelect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *grpSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *grpSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_grpSelect))
        return static_cast<void*>(const_cast< grpSelect*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int grpSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: update_number_of_entries(); break;
        case 1: mark_single_set((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: mark_multiple_sets((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int*(*)>(_a[3]))); break;
        case 3: set_graph_nr((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmEditColumnProp[] = {

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
      40,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   18,   18,   18, 0x0a,
      79,   18,   18,   18, 0x0a,
      90,   18,   18,   18, 0x0a,
     102,  100,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmEditColumnProp[] = {
    "frmEditColumnProp\0\0col,format,precision\0"
    "newColumnFormat(int,int,int)\0doApply()\0"
    "doAccept()\0doClose()\0i\0initToColumn(int)\0"
};

const QMetaObject frmEditColumnProp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmEditColumnProp,
      qt_meta_data_frmEditColumnProp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmEditColumnProp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmEditColumnProp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmEditColumnProp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmEditColumnProp))
        return static_cast<void*>(const_cast< frmEditColumnProp*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmEditColumnProp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newColumnFormat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: doApply(); break;
        case 2: doAccept(); break;
        case 3: doClose(); break;
        case 4: initToColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void frmEditColumnProp::newColumnFormat(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_frmSpreadSheet[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   53,   15,   15, 0x0a,
     108,  103,   15,   15, 0x0a,
     127,   15,   15,   15, 0x0a,
     146,  144,   15,   15, 0x0a,
     178,  166,   15,   15, 0x0a,
     192,   15,   15,   15, 0x0a,
     208,   15,   15,   15, 0x0a,
     218,   15,   15,   15, 0x0a,
     229,   15,   15,   15, 0x0a,
     239,   15,   15,   15, 0x0a,
     250,   15,   15,   15, 0x0a,
     264,   15,   15,   15, 0x0a,
     281,   15,   15,   15, 0x0a,
     299,   15,   15,   15, 0x0a,
     323,   15,   15,   15, 0x0a,
     335,   15,   15,   15, 0x0a,
     365,  361,   15,   15, 0x0a,
     399,  386,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmSpreadSheet[] = {
    "frmSpreadSheet\0\0gno,setno\0"
    "spreadSheetClosed(int,int)\0"
    "col,format,precision\0setColumnFormat(int,int,int)\0"
    "type\0changeDataSet(int)\0update_entries()\0"
    "i\0HHeaderClicked(int)\0g_no,set_no\0"
    "init(int,int)\0CreateActions()\0doApply()\0"
    "doAccept()\0doClose()\0doAddRow()\0"
    "doDelSelRow()\0doColumnFormat()\0"
    "doHelpOnContext()\0doHelpOnDataSetEditor()\0"
    "write_set()\0spreadSheetEntryChanged()\0"
    "r,c\0itemChanged(int,int)\0n_of_sel,sel\0"
    "getSelection(int*,int**)\0"
};

const QMetaObject frmSpreadSheet::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmSpreadSheet,
      qt_meta_data_frmSpreadSheet, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmSpreadSheet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmSpreadSheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmSpreadSheet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmSpreadSheet))
        return static_cast<void*>(const_cast< frmSpreadSheet*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmSpreadSheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: spreadSheetClosed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: setColumnFormat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: changeDataSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: update_entries(); break;
        case 4: HHeaderClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: CreateActions(); break;
        case 7: doApply(); break;
        case 8: doAccept(); break;
        case 9: doClose(); break;
        case 10: doAddRow(); break;
        case 11: doDelSelRow(); break;
        case 12: doColumnFormat(); break;
        case 13: doHelpOnContext(); break;
        case 14: doHelpOnDataSetEditor(); break;
        case 15: write_set(); break;
        case 16: spreadSheetEntryChanged(); break;
        case 17: itemChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: getSelection((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int**(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void frmSpreadSheet::spreadSheetClosed(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_frmPointExplorer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   18,   17,   17, 0x0a,
      42,   17,   17,   17, 0x0a,
      49,   17,   17,   17, 0x0a,
      58,   17,   17,   17, 0x0a,
      82,   68,   17,   17, 0x0a,
     116,   17,   17,   17, 0x0a,
     125,   17,   17,   17, 0x0a,
     135,   17,   17,   17, 0x0a,
     145,   17,   17,   17, 0x0a,
     157,   17,   17,   17, 0x0a,
     168,   17,   17,   17, 0x0a,
     179,   17,   17,   17, 0x0a,
     190,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmPointExplorer[] = {
    "frmPointExplorer\0\0a\0selectionChanged(int)\0"
    "init()\0doGoTo()\0doTrack()\0gno,setno,loc\0"
    "update_point_locator(int,int,int)\0"
    "doMove()\0doMoveX()\0doMoveY()\0doPrepend()\0"
    "doAppend()\0doInsert()\0doDelete()\0"
    "doClose()\0"
};

const QMetaObject frmPointExplorer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmPointExplorer,
      qt_meta_data_frmPointExplorer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmPointExplorer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmPointExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmPointExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmPointExplorer))
        return static_cast<void*>(const_cast< frmPointExplorer*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmPointExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: selectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: init(); break;
        case 2: doGoTo(); break;
        case 3: doTrack(); break;
        case 4: update_point_locator((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: doMove(); break;
        case 6: doMoveX(); break;
        case 7: doMoveY(); break;
        case 8: doPrepend(); break;
        case 9: doAppend(); break;
        case 10: doInsert(); break;
        case 11: doDelete(); break;
        case 12: doClose(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
static const uint qt_meta_data_frmTextProps[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   14,   13,   13, 0x0a,
      29,   27,   13,   13, 0x0a,
      52,   13,   13,   13, 0x0a,
      63,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmTextProps[] = {
    "frmTextProps\0\0id\0init(int)\0i\0"
    "viewCoordsChanged(int)\0doAccept()\0"
    "doClose()\0"
};

const QMetaObject frmTextProps::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmTextProps,
      qt_meta_data_frmTextProps, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmTextProps::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmTextProps::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmTextProps::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmTextProps))
        return static_cast<void*>(const_cast< frmTextProps*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmTextProps::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: viewCoordsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: doAccept(); break;
        case 3: doClose(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmLineProps[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   14,   13,   13, 0x0a,
      29,   27,   13,   13, 0x0a,
      52,   13,   13,   13, 0x0a,
      63,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmLineProps[] = {
    "frmLineProps\0\0id\0init(int)\0i\0"
    "viewCoordsChanged(int)\0doAccept()\0"
    "doClose()\0"
};

const QMetaObject frmLineProps::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmLineProps,
      qt_meta_data_frmLineProps, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmLineProps::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmLineProps::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmLineProps::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmLineProps))
        return static_cast<void*>(const_cast< frmLineProps*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmLineProps::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: viewCoordsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: doAccept(); break;
        case 3: doClose(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmEllipseProps[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   17,   16,   16, 0x0a,
      32,   30,   16,   16, 0x0a,
      55,   16,   16,   16, 0x0a,
      66,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmEllipseProps[] = {
    "frmEllipseProps\0\0id\0init(int)\0i\0"
    "viewCoordsChanged(int)\0doAccept()\0"
    "doClose()\0"
};

const QMetaObject frmEllipseProps::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmEllipseProps,
      qt_meta_data_frmEllipseProps, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmEllipseProps::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmEllipseProps::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmEllipseProps::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmEllipseProps))
        return static_cast<void*>(const_cast< frmEllipseProps*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmEllipseProps::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: viewCoordsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: doAccept(); break;
        case 3: doClose(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmDrawObjects[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      25,   15,   15,   15, 0x0a,
      38,   15,   15,   15, 0x0a,
      47,   15,   15,   15, 0x0a,
      60,   15,   15,   15, 0x0a,
      68,   15,   15,   15, 0x0a,
      80,   15,   15,   15, 0x0a,
      92,   15,   15,   15, 0x0a,
     108,   15,   15,   15, 0x0a,
     120,   15,   15,   15, 0x0a,
     132,   15,   15,   15, 0x0a,
     144,   15,   15,   15, 0x0a,
     155,   15,   15,   15, 0x0a,
     172,   15,   15,   15, 0x0a,
     190,   15,   15,   15, 0x0a,
     208,   15,   15,   15, 0x0a,
     229,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmDrawObjects[] = {
    "frmDrawObjects\0\0doText()\0doTextProp()\0"
    "doLine()\0doLineProp()\0doBox()\0doBoxProp()\0"
    "doEllipse()\0doEllipseProp()\0doEditObj()\0"
    "doMoveObj()\0doCopyObj()\0doDelObj()\0"
    "doClearAllText()\0doClearAllLines()\0"
    "doClearAllBoxes()\0doClearAllEllipses()\0"
    "doClose()\0"
};

const QMetaObject frmDrawObjects::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmDrawObjects,
      qt_meta_data_frmDrawObjects, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmDrawObjects::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmDrawObjects::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmDrawObjects::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmDrawObjects))
        return static_cast<void*>(const_cast< frmDrawObjects*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmDrawObjects::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doText(); break;
        case 1: doTextProp(); break;
        case 2: doLine(); break;
        case 3: doLineProp(); break;
        case 4: doBox(); break;
        case 5: doBoxProp(); break;
        case 6: doEllipse(); break;
        case 7: doEllipseProp(); break;
        case 8: doEditObj(); break;
        case 9: doMoveObj(); break;
        case 10: doCopyObj(); break;
        case 11: doDelObj(); break;
        case 12: doClearAllText(); break;
        case 13: doClearAllLines(); break;
        case 14: doClearAllBoxes(); break;
        case 15: doClearAllEllipses(); break;
        case 16: doClose(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
static const uint qt_meta_data_frmPlotAppearance[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      29,   18,   18,   18, 0x0a,
      40,   18,   18,   18, 0x0a,
      50,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmPlotAppearance[] = {
    "frmPlotAppearance\0\0doApply()\0doAccept()\0"
    "doClose()\0init()\0"
};

const QMetaObject frmPlotAppearance::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmPlotAppearance,
      qt_meta_data_frmPlotAppearance, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmPlotAppearance::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmPlotAppearance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmPlotAppearance::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmPlotAppearance))
        return static_cast<void*>(const_cast< frmPlotAppearance*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmPlotAppearance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doApply(); break;
        case 1: doAccept(); break;
        case 2: doClose(); break;
        case 3: init(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmLocatorProps[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      27,   16,   16,   16, 0x0a,
      38,   16,   16,   16, 0x0a,
      48,   16,   16,   16, 0x0a,
      59,   16,   55,   16, 0x0a,
      92,   88,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmLocatorProps[] = {
    "frmLocatorProps\0\0doApply()\0doAccept()\0"
    "doClose()\0init()\0int\0locator_define_notify_proc()\0"
    "gno\0update_locator_items(int)\0"
};

const QMetaObject frmLocatorProps::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmLocatorProps,
      qt_meta_data_frmLocatorProps, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmLocatorProps::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmLocatorProps::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmLocatorProps::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmLocatorProps))
        return static_cast<void*>(const_cast< frmLocatorProps*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmLocatorProps::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doApply(); break;
        case 1: doAccept(); break;
        case 2: doClose(); break;
        case 3: init(); break;
        case 4: { int _r = locator_define_notify_proc();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: update_locator_items((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
static const uint qt_meta_data_frmConsole[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      28,   11,   11,   11, 0x0a,
      37,   11,   11,   11, 0x0a,
      47,   11,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      66,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
     102,   11,   11,   11, 0x0a,
     121,  117,   11,   11, 0x0a,
     141,  117,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmConsole[] = {
    "frmConsole\0\0CreateActions()\0doSave()\0"
    "doClose()\0doCopy()\0doClear()\0"
    "doHelpOnContext()\0doHelpOnConsole()\0"
    "doPopOnError()\0msg\0errwin(const char*)\0"
    "msgwin(const char*)\0"
};

const QMetaObject frmConsole::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmConsole,
      qt_meta_data_frmConsole, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmConsole::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmConsole::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmConsole::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmConsole))
        return static_cast<void*>(const_cast< frmConsole*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmConsole::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CreateActions(); break;
        case 1: doSave(); break;
        case 2: doClose(); break;
        case 3: doCopy(); break;
        case 4: doClear(); break;
        case 5: doHelpOnContext(); break;
        case 6: doHelpOnConsole(); break;
        case 7: doPopOnError(); break;
        case 8: errwin((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 9: msgwin((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
static const uint qt_meta_data_frmSetOp[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      19,   17,    9,    9, 0x0a,
      40,    9,    9,    9, 0x0a,
      56,    9,    9,    9, 0x0a,
      66,    9,    9,    9, 0x0a,
      77,    9,    9,    9, 0x0a,
      87,    9,    9,    9, 0x0a,
     105,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmSetOp[] = {
    "frmSetOp\0\0init()\0i\0changeSelection(int)\0"
    "CreateActions()\0doClose()\0doAccept()\0"
    "doApply()\0doHelpOnContext()\0doHelpOnSetOp()\0"
};

const QMetaObject frmSetOp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmSetOp,
      qt_meta_data_frmSetOp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmSetOp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmSetOp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmSetOp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmSetOp))
        return static_cast<void*>(const_cast< frmSetOp*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmSetOp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: changeSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: CreateActions(); break;
        case 3: doClose(); break;
        case 4: doAccept(); break;
        case 5: doApply(); break;
        case 6: doHelpOnContext(); break;
        case 7: doHelpOnSetOp(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
static const uint qt_meta_data_frmCommands[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      21,   12,   12,   12, 0x0a,
      32,   12,   12,   12, 0x0a,
      44,   12,   12,   12, 0x0a,
      51,   12,   12,   12, 0x0a,
      60,   12,   12,   12, 0x0a,
      69,   12,   12,   12, 0x0a,
      78,   12,   12,   12, 0x0a,
      88,   12,   12,   12, 0x0a,
      99,   12,   12,   12, 0x0a,
     109,   12,   12,   12, 0x0a,
     135,  118,   12,   12, 0x0a,
     200,  164,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmCommands[] = {
    "frmCommands\0\0doAdd()\0doDelete()\0"
    "doReplace()\0doUp()\0doDown()\0doRead()\0"
    "doSave()\0doClear()\0doReplay()\0doClose()\0"
    "doHelp()\0number,selection\0"
    "getListSelection(int*,int**)\0"
    "type,file,exists,writeable,readable\0"
    "IOrequested(int,QString,bool,bool,bool)\0"
};

const QMetaObject frmCommands::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmCommands,
      qt_meta_data_frmCommands, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmCommands::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmCommands::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmCommands::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmCommands))
        return static_cast<void*>(const_cast< frmCommands*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmCommands::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doAdd(); break;
        case 1: doDelete(); break;
        case 2: doReplace(); break;
        case 3: doUp(); break;
        case 4: doDown(); break;
        case 5: doRead(); break;
        case 6: doSave(); break;
        case 7: doClear(); break;
        case 8: doReplay(); break;
        case 9: doClose(); break;
        case 10: doHelp(); break;
        case 11: getListSelection((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int**(*)>(_a[2]))); break;
        case 12: IOrequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
static const uint qt_meta_data_frmDeviceOptions[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      25,   17,   17,   17, 0x0a,
      35,   17,   17,   17, 0x0a,
      46,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmDeviceOptions[] = {
    "frmDeviceOptions\0\0init()\0doApply()\0"
    "doAccept()\0doClose()\0"
};

const QMetaObject frmDeviceOptions::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmDeviceOptions,
      qt_meta_data_frmDeviceOptions, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmDeviceOptions::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmDeviceOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmDeviceOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmDeviceOptions))
        return static_cast<void*>(const_cast< frmDeviceOptions*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmDeviceOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doApply(); break;
        case 2: doAccept(); break;
        case 3: doClose(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmDeviceSetup[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   16,   15,   15, 0x0a,
      30,   15,   15,   15, 0x0a,
      48,   46,   15,   15, 0x0a,
      72,   46,   15,   15, 0x0a,
      91,   46,   15,   15, 0x0a,
     108,   46,   15,   15, 0x0a,
     132,   46,   15,   15, 0x0a,
     148,   15,   15,   15, 0x0a,
     158,   15,   15,   15, 0x0a,
     169,   15,   15,   15, 0x0a,
     179,   15,   15,   15, 0x0a,
     189,   15,   15,   15, 0x0a,
     202,   15,   15,   15, 0x0a,
     218,   15,   15,   15, 0x0a,
     236,   15,   15,   15, 0x0a,
     255,   15,   15,   15, 0x0a,
     266,   15,   15,   15, 0x0a,
     277,   15,   15,   15, 0x0a,
     337,  301,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmDeviceSetup[] = {
    "frmDeviceSetup\0\0dev\0init(int)\0"
    "CreateActions()\0i\0PrintToFileClicked(int)\0"
    "DeviceChanged(int)\0SizeChanged(int)\0"
    "OrientationChanged(int)\0DimChanged(int)\0"
    "doApply()\0doAccept()\0doClose()\0doPrint()\0"
    "doSyncPage()\0doRescalePlot()\0"
    "doHelpOnContext()\0doHelpOnDevSetup()\0"
    "doBrowse()\0doDevOpt()\0doNativePrinterDialog()\0"
    "type,file,exists,writeable,readable\0"
    "IOrequested(int,QString,bool,bool,bool)\0"
};

const QMetaObject frmDeviceSetup::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmDeviceSetup,
      qt_meta_data_frmDeviceSetup, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmDeviceSetup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmDeviceSetup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmDeviceSetup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmDeviceSetup))
        return static_cast<void*>(const_cast< frmDeviceSetup*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmDeviceSetup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: CreateActions(); break;
        case 2: PrintToFileClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: DeviceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: SizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: OrientationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: DimChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: doApply(); break;
        case 8: doAccept(); break;
        case 9: doClose(); break;
        case 10: doPrint(); break;
        case 11: doSyncPage(); break;
        case 12: doRescalePlot(); break;
        case 13: doHelpOnContext(); break;
        case 14: doHelpOnDevSetup(); break;
        case 15: doBrowse(); break;
        case 16: doDevOpt(); break;
        case 17: doNativePrinterDialog(); break;
        case 18: IOrequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}
static const uint qt_meta_data_frmPreferences[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      25,   23,   15,   15, 0x0a,
      45,   15,   15,   15, 0x0a,
      55,   15,   15,   15, 0x0a,
      66,   15,   15,   15, 0x0a,
      76,   15,   15,   15, 0x0a,
      97,   15,   15,   15, 0x0a,
     124,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmPreferences[] = {
    "frmPreferences\0\0init()\0i\0toggleWrapYear(int)\0"
    "doApply()\0doAccept()\0doClose()\0"
    "doExtraPreferences()\0props_define_notify_proc()\0"
    "update_props_items()\0"
};

const QMetaObject frmPreferences::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmPreferences,
      qt_meta_data_frmPreferences, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmPreferences::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmPreferences::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmPreferences::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmPreferences))
        return static_cast<void*>(const_cast< frmPreferences*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmPreferences::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: toggleWrapYear((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: doApply(); break;
        case 3: doAccept(); break;
        case 4: doClose(); break;
        case 5: doExtraPreferences(); break;
        case 6: props_define_notify_proc(); break;
        case 7: update_props_items(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
static const uint qt_meta_data_frmExtraPreferences[] = {

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
      21,   20,   20,   20, 0x0a,
      34,   28,   20,   20, 0x0a,
      56,   20,   20,   20, 0x0a,
      65,   20,   20,   20, 0x0a,
      74,   20,   20,   20, 0x0a,
      84,   20,   20,   20, 0x0a,
      95,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmExtraPreferences[] = {
    "frmExtraPreferences\0\0init()\0entry\0"
    "toggleHTMLviewer(int)\0doLoad()\0doSave()\0"
    "doApply()\0doAccept()\0doClose()\0"
};

const QMetaObject frmExtraPreferences::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmExtraPreferences,
      qt_meta_data_frmExtraPreferences, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmExtraPreferences::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmExtraPreferences::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmExtraPreferences::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmExtraPreferences))
        return static_cast<void*>(const_cast< frmExtraPreferences*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmExtraPreferences::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: toggleHTMLviewer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: doLoad(); break;
        case 3: doSave(); break;
        case 4: doApply(); break;
        case 5: doAccept(); break;
        case 6: doClose(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
static const uint qt_meta_data_frmArrangeGraphs[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      25,   17,   17,   17, 0x0a,
      35,   17,   17,   17, 0x0a,
      45,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmArrangeGraphs[] = {
    "frmArrangeGraphs\0\0init()\0doApply()\0"
    "doClose()\0doAccept()\0"
};

const QMetaObject frmArrangeGraphs::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmArrangeGraphs,
      qt_meta_data_frmArrangeGraphs, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmArrangeGraphs::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmArrangeGraphs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmArrangeGraphs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmArrangeGraphs))
        return static_cast<void*>(const_cast< frmArrangeGraphs*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmArrangeGraphs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doApply(); break;
        case 2: doClose(); break;
        case 3: doAccept(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmOverlayGraphs[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      25,   17,   17,   17, 0x0a,
      35,   17,   17,   17, 0x0a,
      45,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmOverlayGraphs[] = {
    "frmOverlayGraphs\0\0init()\0doApply()\0"
    "doClose()\0doAccept()\0"
};

const QMetaObject frmOverlayGraphs::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmOverlayGraphs,
      qt_meta_data_frmOverlayGraphs, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmOverlayGraphs::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmOverlayGraphs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmOverlayGraphs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmOverlayGraphs))
        return static_cast<void*>(const_cast< frmOverlayGraphs*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmOverlayGraphs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doApply(); break;
        case 2: doClose(); break;
        case 3: doAccept(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmAutoscaleGraphs[] = {

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
      20,   19,   19,   19, 0x0a,
      27,   19,   19,   19, 0x0a,
      37,   19,   19,   19, 0x0a,
      47,   19,   19,   19, 0x0a,
      68,   58,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmAutoscaleGraphs[] = {
    "frmAutoscaleGraphs\0\0init()\0doApply()\0"
    "doClose()\0doAccept()\0aon,au,ap\0"
    "define_autos(int,int,int)\0"
};

const QMetaObject frmAutoscaleGraphs::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmAutoscaleGraphs,
      qt_meta_data_frmAutoscaleGraphs, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmAutoscaleGraphs::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmAutoscaleGraphs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmAutoscaleGraphs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmAutoscaleGraphs))
        return static_cast<void*>(const_cast< frmAutoscaleGraphs*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmAutoscaleGraphs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doApply(); break;
        case 2: doClose(); break;
        case 3: doAccept(); break;
        case 4: define_autos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_frmDataSetProperties[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,
      38,   21,   21,   21, 0x0a,
      51,   21,   21,   21, 0x0a,
      65,   21,   21,   21, 0x0a,
      83,   21,   21,   21, 0x0a,
     101,   21,   21,   21, 0x0a,
     119,   21,   21,   21, 0x0a,
     137,   21,   21,   21, 0x0a,
     159,   21,   21,   21, 0x0a,
     180,   21,   21,   21, 0x0a,
     203,   21,   21,   21, 0x0a,
     230,   21,   21,   21, 0x0a,
     256,   21,   21,   21, 0x0a,
     286,  283,   21,   21, 0x0a,
     308,  302,   21,   21, 0x0a,
     332,   21,   21,   21, 0x0a,
     339,   21,   21,   21, 0x0a,
     349,   21,   21,   21, 0x0a,
     359,   21,   21,   21, 0x0a,
     369,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmDataSetProperties[] = {
    "frmDataSetProperties\0\0CreateActions()\0"
    "doKillData()\0doDuplicate()\0doSetAppearance()\0"
    "doSetOperations()\0doHelpOnContext()\0"
    "doHelpOnSetProp()\0doEditInSpreadsheet()\0"
    "doEditInTextEditor()\0doCreateNewByFormula()\0"
    "doCreateNewInSpreadsheet()\0"
    "doCreateNewInTextEditor()\0"
    "doCreateNewFromBlockData()\0nr\0"
    "setChanged(int)\0index\0setChanged(QModelIndex)\0"
    "init()\0doClear()\0doApply()\0doClose()\0"
    "doAccept()\0"
};

const QMetaObject frmDataSetProperties::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmDataSetProperties,
      qt_meta_data_frmDataSetProperties, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmDataSetProperties::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmDataSetProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmDataSetProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmDataSetProperties))
        return static_cast<void*>(const_cast< frmDataSetProperties*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmDataSetProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CreateActions(); break;
        case 1: doKillData(); break;
        case 2: doDuplicate(); break;
        case 3: doSetAppearance(); break;
        case 4: doSetOperations(); break;
        case 5: doHelpOnContext(); break;
        case 6: doHelpOnSetProp(); break;
        case 7: doEditInSpreadsheet(); break;
        case 8: doEditInTextEditor(); break;
        case 9: doCreateNewByFormula(); break;
        case 10: doCreateNewInSpreadsheet(); break;
        case 11: doCreateNewInTextEditor(); break;
        case 12: doCreateNewFromBlockData(); break;
        case 13: setChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: setChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 15: init(); break;
        case 16: doClear(); break;
        case 17: doApply(); break;
        case 18: doClose(); break;
        case 19: doAccept(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
static const uint qt_meta_data_frmSetOperations[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      25,   17,   17,   17, 0x0a,
      35,   17,   17,   17, 0x0a,
      45,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmSetOperations[] = {
    "frmSetOperations\0\0init()\0doApply()\0"
    "doClose()\0doAccept()\0"
};

const QMetaObject frmSetOperations::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmSetOperations,
      qt_meta_data_frmSetOperations, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmSetOperations::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmSetOperations::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmSetOperations::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmSetOperations))
        return static_cast<void*>(const_cast< frmSetOperations*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmSetOperations::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doApply(); break;
        case 2: doClose(); break;
        case 3: doAccept(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmAbout[] = {

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
      10,    9,    9,    9, 0x0a,
      27,    9,    9,    9, 0x0a,
      45,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmAbout[] = {
    "frmAbout\0\0doShowHomepage()\0doShowHomepage2()\0"
    "doClose()\0"
};

const QMetaObject frmAbout::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmAbout,
      qt_meta_data_frmAbout, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmAbout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmAbout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmAbout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmAbout))
        return static_cast<void*>(const_cast< frmAbout*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmAbout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doShowHomepage(); break;
        case 1: doShowHomepage2(); break;
        case 2: doClose(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_frmFeatureExtract[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      28,   26,   18,   18, 0x0a,
      47,   18,   18,   18, 0x0a,
      57,   18,   18,   18, 0x0a,
     106,   68,   18,   18, 0x0a,
     166,  144,  140,   18, 0x0a,
     251,  226,  140,   18, 0x0a,
     308,  226,  140,   18, 0x0a,
     385,  365,  140,   18, 0x0a,
     446,  432,  140,   18, 0x0a,
     515,  501,  494,   18, 0x0a,
     590,  565,  140,   18, 0x0a,
     638,  621,  140,   18, 0x0a,
     694,  682,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmFeatureExtract[] = {
    "frmFeatureExtract\0\0init()\0i\0"
    "XValueChanged(int)\0doClose()\0doAccept()\0"
    "gto,feature,abs_src,abs_set,abs_graph\0"
    "fext_routine(int,int,int,int,int)\0int\0"
    "n,x,y,slope,intercept\0"
    "mute_linear_regression(int,double*,double*,double*,double*)\0"
    "setl,xv,yv,min,max,width\0"
    "get_rise_time(int,double*,double*,double,double,double*)\0"
    "get_fall_time(int,double*,double*,double,double,double*)\0"
    "setl,xv,yv,crossing\0"
    "get_zero_crossing(int,double*,double*,double*)\0"
    "len,x,y,width\0"
    "get_half_max_width(int,double*,double*,double*)\0"
    "double\0x1,y1,x2,y2,x\0"
    "linear_interp(double,double,double,double,double)\0"
    "grno,setno,sorton,median\0"
    "getmedian(int,int,int,double*)\0"
    "n,x,y,barycenter\0"
    "get_barycenter(int,double*,double*,double*)\0"
    "a,b,n,max,d\0get_max_pos(double*,double*,int,double,double*)\0"
};

const QMetaObject frmFeatureExtract::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmFeatureExtract,
      qt_meta_data_frmFeatureExtract, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmFeatureExtract::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmFeatureExtract::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmFeatureExtract::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmFeatureExtract))
        return static_cast<void*>(const_cast< frmFeatureExtract*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmFeatureExtract::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: XValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: doClose(); break;
        case 3: doAccept(); break;
        case 4: fext_routine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 5: { int _r = mute_linear_regression((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double*(*)>(_a[4])),(*reinterpret_cast< double*(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { int _r = get_rise_time((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double*(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { int _r = get_fall_time((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double*(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { int _r = get_zero_crossing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: { int _r = get_half_max_width((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { double _r = linear_interp((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 11: { int _r = getmedian((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { int _r = get_barycenter((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: get_max_pos((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double*(*)>(_a[5]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
static const uint qt_meta_data_frmIOForm[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      47,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,   96,   10,   10, 0x0a,
     131,   96,   10,   10, 0x0a,
     167,   10,   10,   10, 0x0a,
     174,   10,   10,   10, 0x0a,
     181,   10,   10,   10, 0x0a,
     192,   10,   10,   10, 0x0a,
     203,   10,   10,   10, 0x0a,
     214,  212,   10,   10, 0x0a,
     233,  212,   10,   10, 0x0a,
     258,  212,   10,   10, 0x0a,
     278,  212,   10,   10, 0x0a,
     302,  212,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmIOForm[] = {
    "frmIOForm\0\0type,file,exists,writeable,readable\0"
    "newFileSelectedForIO(int,QString,bool,bool,bool)\0"
    "selection\0gotNewSelection(QString)\0"
    "gotNewSelectionDoubleClick(QString)\0"
    "init()\0doOK()\0doFilter()\0doCancel()\0"
    "doHelp()\0c\0headerChecked(int)\0"
    "readUntilEOFChecked(int)\0setTypeChanged(int)\0"
    "columnCountChanged(int)\0columnSizeChanged(int)\0"
};

const QMetaObject frmIOForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmIOForm,
      qt_meta_data_frmIOForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmIOForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmIOForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmIOForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmIOForm))
        return static_cast<void*>(const_cast< frmIOForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmIOForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newFileSelectedForIO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 1: gotNewSelection((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: gotNewSelectionDoubleClick((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: init(); break;
        case 4: doOK(); break;
        case 5: doFilter(); break;
        case 6: doCancel(); break;
        case 7: doHelp(); break;
        case 8: headerChecked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: readUntilEOFChecked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: setTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: columnCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: columnSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void frmIOForm::newFileSelectedForIO(int _t1, QString _t2, bool _t3, bool _t4, bool _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_GlyphPanel[] = {

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
      14,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   32,   11,   11, 0x0a,
      69,   53,   11,   11, 0x0a,
     101,   95,   11,   11, 0x0a,
     157,  139,  131,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GlyphPanel[] = {
    "GlyphPanel\0\0i\0panelClicked(int)\0mark\0"
    "setMarked(bool)\0font_nr,char_nr\0"
    "setCurrentPixmap(int,int)\0event\0"
    "mousePressEvent(QMouseEvent*)\0QPixmap\0"
    "c,FontID,val_char\0DrawCB(unsigned char,int,bool&)\0"
};

const QMetaObject GlyphPanel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_GlyphPanel,
      qt_meta_data_GlyphPanel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GlyphPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GlyphPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GlyphPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlyphPanel))
        return static_cast<void*>(const_cast< GlyphPanel*>(this));
    return QLabel::qt_metacast(_clname);
}

int GlyphPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: panelClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setMarked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: setCurrentPixmap((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: { QPixmap _r = DrawCB((*reinterpret_cast< unsigned char(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void GlyphPanel::panelClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_frmFontTool[] = {

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
      18,   13,   12,   12, 0x0a,
      47,   45,   12,   12, 0x0a,
      73,   71,   12,   12, 0x0a,
      90,   71,   12,   12, 0x0a,
     104,   12,   12,   12, 0x0a,
     114,   12,   12,   12, 0x0a,
     124,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmFontTool[] = {
    "frmFontTool\0\0text\0characterInserted(QString)\0"
    "c\0insertAtCursor(QString)\0i\0"
    "FontChanged(int)\0newClick(int)\0doApply()\0"
    "doClose()\0doAccept()\0"
};

const QMetaObject frmFontTool::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmFontTool,
      qt_meta_data_frmFontTool, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmFontTool::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmFontTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmFontTool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmFontTool))
        return static_cast<void*>(const_cast< frmFontTool*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmFontTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: characterInserted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: insertAtCursor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: FontChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: newClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: doApply(); break;
        case 5: doClose(); break;
        case 6: doAccept(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
static const uint qt_meta_data_frmFourier[] = {

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
      12,   11,   11,   11, 0x0a,
      19,   11,   11,   11, 0x0a,
      27,   11,   11,   11, 0x0a,
      35,   11,   11,   11, 0x0a,
      50,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmFourier[] = {
    "frmFourier\0\0init()\0doDFT()\0doFFT()\0"
    "doWindowOnly()\0doClose()\0"
};

const QMetaObject frmFourier::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmFourier,
      qt_meta_data_frmFourier, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmFourier::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmFourier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmFourier::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmFourier))
        return static_cast<void*>(const_cast< frmFourier*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmFourier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doDFT(); break;
        case 2: doFFT(); break;
        case 3: doWindowOnly(); break;
        case 4: doClose(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_frmFourier2[] = {

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
      13,   12,   12,   12, 0x0a,
      22,   20,   12,   12, 0x0a,
      45,   20,   12,   12, 0x0a,
      68,   20,   12,   12, 0x0a,
      90,   12,   12,   12, 0x0a,
     101,   12,   12,   12, 0x0a,
     112,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmFourier2[] = {
    "frmFourier2\0\0init()\0i\0filterTypeChanged(int)\0"
    "filterKindChanged(int)\0selPointsChanged(int)\0"
    "doFilter()\0doAccept()\0doClose()\0"
};

const QMetaObject frmFourier2::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmFourier2,
      qt_meta_data_frmFourier2, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmFourier2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmFourier2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmFourier2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmFourier2))
        return static_cast<void*>(const_cast< frmFourier2*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmFourier2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: filterTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: filterKindChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: selPointsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: doFilter(); break;
        case 5: doAccept(); break;
        case 6: doClose(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
static const uint qt_meta_data_frmHotLinks[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      20,   12,   12,   12, 0x0a,
      29,   12,   12,   12, 0x0a,
      39,   12,   12,   12, 0x0a,
      50,   12,   12,   12, 0x0a,
      68,   12,   12,   12, 0x0a,
      78,   12,   12,   12, 0x0a,
     134,   98,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmHotLinks[] = {
    "frmHotLinks\0\0init()\0doLink()\0doFiles()\0"
    "doUnlink()\0update_hotlinks()\0doClose()\0"
    "do_hotupdate_proc()\0"
    "type,file,exists,writeable,readable\0"
    "newLinkFileSelected(int,QString,bool,bool,bool)\0"
};

const QMetaObject frmHotLinks::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmHotLinks,
      qt_meta_data_frmHotLinks, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmHotLinks::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmHotLinks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmHotLinks::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmHotLinks))
        return static_cast<void*>(const_cast< frmHotLinks*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmHotLinks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doLink(); break;
        case 2: doFiles(); break;
        case 3: doUnlink(); break;
        case 4: update_hotlinks(); break;
        case 5: doClose(); break;
        case 6: do_hotupdate_proc(); break;
        case 7: newLinkFileSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
static const uint qt_meta_data_frmRegionStatus[] = {

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
      17,   16,   16,   16, 0x0a,
      24,   16,   16,   16, 0x0a,
      35,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmRegionStatus[] = {
    "frmRegionStatus\0\0init()\0doUpdate()\0"
    "doClose()\0"
};

const QMetaObject frmRegionStatus::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmRegionStatus,
      qt_meta_data_frmRegionStatus, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmRegionStatus::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmRegionStatus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmRegionStatus::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmRegionStatus))
        return static_cast<void*>(const_cast< frmRegionStatus*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmRegionStatus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doUpdate(); break;
        case 2: doClose(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_frmRegions[] = {

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
      12,   11,   11,   11, 0x0a,
      19,   11,   11,   11, 0x0a,
      30,   11,   11,   11, 0x0a,
      41,   11,   11,   11, 0x0a,
      60,   51,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmRegions[] = {
    "frmRegions\0\0init()\0doAccept()\0doDefine()\0"
    "doClose()\0nr,rtype\0define_region(int,int)\0"
};

const QMetaObject frmRegions::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmRegions,
      qt_meta_data_frmRegions, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmRegions::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmRegions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmRegions::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmRegions))
        return static_cast<void*>(const_cast< frmRegions*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmRegions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doAccept(); break;
        case 2: doDefine(); break;
        case 3: doClose(); break;
        case 4: define_region((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_frmEditBlockData[] = {

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
      33,   18,   17,   17, 0x0a,
      60,   58,   17,   17, 0x0a,
      80,   17,   17,   17, 0x0a,
      91,   87,   17,   17, 0x0a,
     110,   17,   17,   17, 0x0a,
     121,   17,   17,   17, 0x0a,
     131,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmEditBlockData[] = {
    "frmEditBlockData\0\0columns,length\0"
    "setCompleteData(int,int)\0i\0"
    "setTypeChanged(int)\0init()\0gno\0"
    "update_eblock(int)\0doAccept()\0doApply()\0"
    "doClose()\0"
};

const QMetaObject frmEditBlockData::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmEditBlockData,
      qt_meta_data_frmEditBlockData, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmEditBlockData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmEditBlockData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmEditBlockData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmEditBlockData))
        return static_cast<void*>(const_cast< frmEditBlockData*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmEditBlockData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setCompleteData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: setTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: init(); break;
        case 3: update_eblock((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: doAccept(); break;
        case 5: doApply(); break;
        case 6: doClose(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
static const uint qt_meta_data_frmLoadEval[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x0a,
      32,   12,   12,   12, 0x0a,
      43,   12,   12,   12, 0x0a,
      53,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmLoadEval[] = {
    "frmLoadEval\0\0i\0typeChanged(int)\0"
    "doAccept()\0doApply()\0doClose()\0"
};

const QMetaObject frmLoadEval::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmLoadEval,
      qt_meta_data_frmLoadEval, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmLoadEval::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmLoadEval::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmLoadEval::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmLoadEval))
        return static_cast<void*>(const_cast< frmLoadEval*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmLoadEval::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: typeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: doAccept(); break;
        case 2: doApply(); break;
        case 3: doClose(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmEvalExpr[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      23,   12,   12,   12, 0x0a,
      34,   12,   12,   12, 0x0a,
      44,   12,   12,   12, 0x0a,
      51,   12,   12,   12, 0x0a,
      60,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmEvalExpr[] = {
    "frmEvalExpr\0\0doApply()\0doAccept()\0"
    "doClose()\0init()\0update()\0compute_aac()\0"
};

const QMetaObject frmEvalExpr::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmEvalExpr,
      qt_meta_data_frmEvalExpr, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmEvalExpr::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmEvalExpr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmEvalExpr::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmEvalExpr))
        return static_cast<void*>(const_cast< frmEvalExpr*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmEvalExpr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doApply(); break;
        case 1: doAccept(); break;
        case 2: doClose(); break;
        case 3: init(); break;
        case 4: update(); break;
        case 5: compute_aac(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
static const uint qt_meta_data_nlcfTabMain[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_nlcfTabMain[] = {
    "nlcfTabMain\0\0i\0paraNumberChanged(int)\0"
};

const QMetaObject nlcfTabMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_nlcfTabMain,
      qt_meta_data_nlcfTabMain, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &nlcfTabMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *nlcfTabMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *nlcfTabMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_nlcfTabMain))
        return static_cast<void*>(const_cast< nlcfTabMain*>(this));
    return QWidget::qt_metacast(_clname);
}

int nlcfTabMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: paraNumberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_nlcfTabAdvanced[] = {

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
      19,   17,   16,   16, 0x0a,
      40,   17,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_nlcfTabAdvanced[] = {
    "nlcfTabAdvanced\0\0i\0weights_changed(int)\0"
    "load_changed(int)\0"
};

const QMetaObject nlcfTabAdvanced::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_nlcfTabAdvanced,
      qt_meta_data_nlcfTabAdvanced, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &nlcfTabAdvanced::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *nlcfTabAdvanced::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *nlcfTabAdvanced::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_nlcfTabAdvanced))
        return static_cast<void*>(const_cast< nlcfTabAdvanced*>(this));
    return QWidget::qt_metacast(_clname);
}

int nlcfTabAdvanced::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: weights_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: load_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_frmNonlinCurveFit[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      26,   18,   18,   18, 0x0a,
      46,   18,   18,   18, 0x0a,
      62,   18,   18,   18, 0x0a,
      72,   18,   18,   18, 0x0a,
      83,   18,   18,   18, 0x0a,
      93,   18,   18,   18, 0x0a,
     102,   18,   18,   18, 0x0a,
     111,   18,   18,   18, 0x0a,
     124,   18,   18,   18, 0x0a,
     136,   18,   18,   18, 0x0a,
     149,   18,   18,   18, 0x0a,
     160,   18,   18,   18, 0x0a,
     176,   18,   18,   18, 0x0a,
     212,  188,   18,   18, 0x0a,
     275,  239,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmNonlinCurveFit[] = {
    "frmNonlinCurveFit\0\0init()\0update_nonl_frame()\0"
    "CreateActions()\0doApply()\0doAccept()\0"
    "doClose()\0doOpen()\0doSave()\0doResetFit()\0"
    "doLoadFit()\0doAutoLoad()\0doUpdate()\0"
    "doHelpContext()\0doHelpFit()\0"
    "src_gno,src_setno,force\0"
    "load_nonl_fit(int,int,int)\0"
    "type,file,exists,writeable,readable\0"
    "IOrequested(int,QString,bool,bool,bool)\0"
};

const QMetaObject frmNonlinCurveFit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmNonlinCurveFit,
      qt_meta_data_frmNonlinCurveFit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmNonlinCurveFit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmNonlinCurveFit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmNonlinCurveFit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmNonlinCurveFit))
        return static_cast<void*>(const_cast< frmNonlinCurveFit*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmNonlinCurveFit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: update_nonl_frame(); break;
        case 2: CreateActions(); break;
        case 3: doApply(); break;
        case 4: doAccept(); break;
        case 5: doClose(); break;
        case 6: doOpen(); break;
        case 7: doSave(); break;
        case 8: doResetFit(); break;
        case 9: doLoadFit(); break;
        case 10: doAutoLoad(); break;
        case 11: doUpdate(); break;
        case 12: doHelpContext(); break;
        case 13: doHelpFit(); break;
        case 14: load_nonl_fit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: IOrequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
static const uint qt_meta_data_frmInterpolation[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      27,   25,   17,   17, 0x0a,
      51,   25,   17,   17, 0x0a,
      77,   17,   17,   17, 0x0a,
      88,   17,   17,   17, 0x0a,
      98,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmInterpolation[] = {
    "frmInterpolation\0\0init()\0i\0"
    "selSamplingChanged(int)\0"
    "selSamplGraphChanged(int)\0doAccept()\0"
    "doApply()\0doClose()\0"
};

const QMetaObject frmInterpolation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmInterpolation,
      qt_meta_data_frmInterpolation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmInterpolation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmInterpolation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmInterpolation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmInterpolation))
        return static_cast<void*>(const_cast< frmInterpolation*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmInterpolation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: selSamplingChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: selSamplGraphChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: doAccept(); break;
        case 4: doApply(); break;
        case 5: doClose(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
static const uint qt_meta_data_frmSmallCalc[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      23,   21,   13,   13, 0x0a,
      40,   13,   13,   13, 0x0a,
      51,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmSmallCalc[] = {
    "frmSmallCalc\0\0init()\0i\0loadChanged(int)\0"
    "doAccept()\0doClose()\0"
};

const QMetaObject frmSmallCalc::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmSmallCalc,
      qt_meta_data_frmSmallCalc, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmSmallCalc::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmSmallCalc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmSmallCalc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmSmallCalc))
        return static_cast<void*>(const_cast< frmSmallCalc*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmSmallCalc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: loadChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: doAccept(); break;
        case 3: doClose(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_frmCorrelation[] = {

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
      16,   15,   15,   15, 0x0a,
      23,   15,   15,   15, 0x0a,
      34,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmCorrelation[] = {
    "frmCorrelation\0\0init()\0doAccept()\0"
    "doClose()\0"
};

const QMetaObject frmCorrelation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmCorrelation,
      qt_meta_data_frmCorrelation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmCorrelation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmCorrelation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmCorrelation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmCorrelation))
        return static_cast<void*>(const_cast< frmCorrelation*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmCorrelation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doAccept(); break;
        case 2: doClose(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_frmTransform[] = {

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
      14,   13,   13,   13, 0x0a,
      23,   21,   13,   13, 0x0a,
      45,   21,   13,   13, 0x0a,
      64,   13,   13,   13, 0x0a,
      75,   13,   13,   13, 0x0a,
      85,   13,   13,   13, 0x0a,
      95,   21,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmTransform[] = {
    "frmTransform\0\0init()\0i\0PruneTypeChanged(int)\0"
    "CoordsChanged(int)\0doAccept()\0doReset()\0"
    "doClose()\0selectorChanged(int)\0"
};

const QMetaObject frmTransform::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmTransform,
      qt_meta_data_frmTransform, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmTransform::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmTransform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmTransform::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmTransform))
        return static_cast<void*>(const_cast< frmTransform*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmTransform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: PruneTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: CoordsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: doAccept(); break;
        case 4: doReset(); break;
        case 5: doClose(); break;
        case 6: selectorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
static const uint qt_meta_data_tabMain[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,    9,    8,    8, 0x05,
      31,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,    9,    8,    8, 0x0a,
      72,    9,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_tabMain[] = {
    "tabMain\0\0val\0colorChanged(int)\0"
    "colorChanged2(int)\0LineColorChanged(int)\0"
    "SymbColorChanged(int)\0"
};

const QMetaObject tabMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tabMain,
      qt_meta_data_tabMain, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &tabMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *tabMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *tabMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tabMain))
        return static_cast<void*>(const_cast< tabMain*>(this));
    return QWidget::qt_metacast(_clname);
}

int tabMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: colorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: colorChanged2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: LineColorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: SymbColorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void tabMain::colorChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tabMain::colorChanged2(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_tabSymbol[] = {

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

static const char qt_meta_stringdata_tabSymbol[] = {
    "tabSymbol\0"
};

const QMetaObject tabSymbol::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tabSymbol,
      qt_meta_data_tabSymbol, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &tabSymbol::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *tabSymbol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *tabSymbol::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tabSymbol))
        return static_cast<void*>(const_cast< tabSymbol*>(this));
    return QWidget::qt_metacast(_clname);
}

int tabSymbol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_tabLine[] = {

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

static const char qt_meta_stringdata_tabLine[] = {
    "tabLine\0"
};

const QMetaObject tabLine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tabLine,
      qt_meta_data_tabLine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &tabLine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *tabLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *tabLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tabLine))
        return static_cast<void*>(const_cast< tabLine*>(this));
    return QWidget::qt_metacast(_clname);
}

int tabLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_tabAnnVal[] = {

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

static const char qt_meta_stringdata_tabAnnVal[] = {
    "tabAnnVal\0"
};

const QMetaObject tabAnnVal::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tabAnnVal,
      qt_meta_data_tabAnnVal, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &tabAnnVal::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *tabAnnVal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *tabAnnVal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tabAnnVal))
        return static_cast<void*>(const_cast< tabAnnVal*>(this));
    return QWidget::qt_metacast(_clname);
}

int tabAnnVal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_tabErrorBars[] = {

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

static const char qt_meta_stringdata_tabErrorBars[] = {
    "tabErrorBars\0"
};

const QMetaObject tabErrorBars::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tabErrorBars,
      qt_meta_data_tabErrorBars, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &tabErrorBars::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *tabErrorBars::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *tabErrorBars::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tabErrorBars))
        return static_cast<void*>(const_cast< tabErrorBars*>(this));
    return QWidget::qt_metacast(_clname);
}

int tabErrorBars::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_frmSetAppearance[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      34,   17,   17,   17, 0x0a,
      41,   17,   17,   17, 0x0a,
      51,   17,   17,   17, 0x0a,
      62,   17,   17,   17, 0x0a,
      72,   17,   17,   17, 0x0a,
      90,   17,   17,   17, 0x0a,
     114,   17,   17,   17, 0x0a,
     130,   17,   17,   17, 0x0a,
     144,   17,   17,   17, 0x0a,
     162,   17,   17,   17, 0x0a,
     184,   17,   17,   17, 0x0a,
     206,   17,   17,   17, 0x0a,
     225,   17,   17,   17, 0x0a,
     246,   17,   17,   17, 0x0a,
     263,   17,   17,   17, 0x0a,
     282,  280,   17,   17, 0x0a,
     328,  304,   17,   17, 0x0a,
     358,  304,   17,   17, 0x0a,
     379,  304,   17,   17, 0x0a,
     405,  401,   17,   17, 0x0a,
     421,  401,   17,   17, 0x0a,
     442,  438,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmSetAppearance[] = {
    "frmSetAppearance\0\0CreateActions()\0"
    "init()\0doApply()\0doAccept()\0doClose()\0"
    "doHelpOnContext()\0doHelpOnSetAppearance()\0"
    "doDuplLegends()\0doColorSync()\0"
    "doSetDiffColors()\0doSetDiffLineStyles()\0"
    "doSetDiffLineWidths()\0doSetDiffSymbols()\0"
    "doSetBlackAndWhite()\0doLoadComments()\0"
    "doStripLegends()\0a\0newListSelection(int)\0"
    "graph_number,set_number\0"
    "ShowSetData_external(int,int)\0"
    "showSetData(int,int)\0writeSetData(int,int)\0"
    "val\0SyncColors(int)\0SyncColors2(int)\0"
    "dat\0setapp_data_proc(int)\0"
};

const QMetaObject frmSetAppearance::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmSetAppearance,
      qt_meta_data_frmSetAppearance, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmSetAppearance::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmSetAppearance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmSetAppearance::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmSetAppearance))
        return static_cast<void*>(const_cast< frmSetAppearance*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmSetAppearance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CreateActions(); break;
        case 1: init(); break;
        case 2: doApply(); break;
        case 3: doAccept(); break;
        case 4: doClose(); break;
        case 5: doHelpOnContext(); break;
        case 6: doHelpOnSetAppearance(); break;
        case 7: doDuplLegends(); break;
        case 8: doColorSync(); break;
        case 9: doSetDiffColors(); break;
        case 10: doSetDiffLineStyles(); break;
        case 11: doSetDiffLineWidths(); break;
        case 12: doSetDiffSymbols(); break;
        case 13: doSetBlackAndWhite(); break;
        case 14: doLoadComments(); break;
        case 15: doStripLegends(); break;
        case 16: newListSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: ShowSetData_external((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: showSetData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: writeSetData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: SyncColors((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: SyncColors2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: setapp_data_proc((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}
static const uint qt_meta_data_GrTabMain[] = {

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

static const char qt_meta_stringdata_GrTabMain[] = {
    "GrTabMain\0"
};

const QMetaObject GrTabMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GrTabMain,
      qt_meta_data_GrTabMain, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GrTabMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GrTabMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GrTabMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GrTabMain))
        return static_cast<void*>(const_cast< GrTabMain*>(this));
    return QWidget::qt_metacast(_clname);
}

int GrTabMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_GrTabTitles[] = {

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

static const char qt_meta_stringdata_GrTabTitles[] = {
    "GrTabTitles\0"
};

const QMetaObject GrTabTitles::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GrTabTitles,
      qt_meta_data_GrTabTitles, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GrTabTitles::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GrTabTitles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GrTabTitles::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GrTabTitles))
        return static_cast<void*>(const_cast< GrTabTitles*>(this));
    return QWidget::qt_metacast(_clname);
}

int GrTabTitles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_GrTabFrame[] = {

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

static const char qt_meta_stringdata_GrTabFrame[] = {
    "GrTabFrame\0"
};

const QMetaObject GrTabFrame::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GrTabFrame,
      qt_meta_data_GrTabFrame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GrTabFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GrTabFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GrTabFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GrTabFrame))
        return static_cast<void*>(const_cast< GrTabFrame*>(this));
    return QWidget::qt_metacast(_clname);
}

int GrTabFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_GrTabLegBox[] = {

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

static const char qt_meta_stringdata_GrTabLegBox[] = {
    "GrTabLegBox\0"
};

const QMetaObject GrTabLegBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GrTabLegBox,
      qt_meta_data_GrTabLegBox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GrTabLegBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GrTabLegBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GrTabLegBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GrTabLegBox))
        return static_cast<void*>(const_cast< GrTabLegBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int GrTabLegBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_GrTabLegends[] = {

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

static const char qt_meta_stringdata_GrTabLegends[] = {
    "GrTabLegends\0"
};

const QMetaObject GrTabLegends::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GrTabLegends,
      qt_meta_data_GrTabLegends, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GrTabLegends::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GrTabLegends::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GrTabLegends::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GrTabLegends))
        return static_cast<void*>(const_cast< GrTabLegends*>(this));
    return QWidget::qt_metacast(_clname);
}

int GrTabLegends::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_GrTabSpecial[] = {

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

static const char qt_meta_stringdata_GrTabSpecial[] = {
    "GrTabSpecial\0"
};

const QMetaObject GrTabSpecial::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GrTabSpecial,
      qt_meta_data_GrTabSpecial, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GrTabSpecial::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GrTabSpecial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GrTabSpecial::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GrTabSpecial))
        return static_cast<void*>(const_cast< GrTabSpecial*>(this));
    return QWidget::qt_metacast(_clname);
}

int GrTabSpecial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_frmGraphApp[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      20,   12,   12,   12, 0x0a,
      36,   12,   12,   12, 0x0a,
      47,   12,   12,   12, 0x0a,
      57,   12,   12,   12, 0x0a,
      67,   12,   12,   12, 0x0a,
      76,   12,   12,   12, 0x0a,
      85,   12,   12,   12, 0x0a,
     103,   12,   12,   12, 0x0a,
     120,   12,   12,   12, 0x0a,
     132,   12,   12,   12, 0x0a,
     141,   12,   12,   12, 0x0a,
     150,   12,   12,   12, 0x0a,
     159,   12,   12,   12, 0x0a,
     173,   12,   12,   12, 0x0a,
     183,   12,   12,   12, 0x0a,
     201,   12,  197,   12, 0x0a,
     225,  219,   12,   12, 0x0a,
     257,  255,   12,   12, 0x0a,
     284,  275,   12,   12, 0x0a,
     320,  316,   12,   12, 0x0a,
     337,  316,   12,   12, 0x0a,
     356,  316,   12,   12, 0x0a,
     416,  380,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmGraphApp[] = {
    "frmGraphApp\0\0init()\0CreateActions()\0"
    "doAccept()\0doClose()\0doApply()\0doOpen()\0"
    "doSave()\0doHelpOnContext()\0doHelpGraphApp()\0"
    "doPrepare()\0doHide()\0doShow()\0doKill()\0"
    "doDuplicate()\0doFocus()\0doCreateNew()\0"
    "int\0graphapp_aac_cb()\0n_gno\0"
    "show_graph_data_external(int)\0i\0"
    "newSelection(int)\0n,values\0"
    "update_graphapp_items(int,int*)\0gno\0"
    "update_view(int)\0updatelegends(int)\0"
    "update_frame_items(int)\0"
    "type,file,exists,writeable,readable\0"
    "IOrequested(int,QString,bool,bool,bool)\0"
};

const QMetaObject frmGraphApp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmGraphApp,
      qt_meta_data_frmGraphApp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmGraphApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmGraphApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmGraphApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmGraphApp))
        return static_cast<void*>(const_cast< frmGraphApp*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmGraphApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: CreateActions(); break;
        case 2: doAccept(); break;
        case 3: doClose(); break;
        case 4: doApply(); break;
        case 5: doOpen(); break;
        case 6: doSave(); break;
        case 7: doHelpOnContext(); break;
        case 8: doHelpGraphApp(); break;
        case 9: doPrepare(); break;
        case 10: doHide(); break;
        case 11: doShow(); break;
        case 12: doKill(); break;
        case 13: doDuplicate(); break;
        case 14: doFocus(); break;
        case 15: doCreateNew(); break;
        case 16: { int _r = graphapp_aac_cb();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 17: show_graph_data_external((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: newSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: update_graphapp_items((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2]))); break;
        case 20: update_view((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: updatelegends((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: update_frame_items((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: IOrequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}
static const uint qt_meta_data_AxisTabMain[] = {

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

static const char qt_meta_stringdata_AxisTabMain[] = {
    "AxisTabMain\0"
};

const QMetaObject AxisTabMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AxisTabMain,
      qt_meta_data_AxisTabMain, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AxisTabMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AxisTabMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AxisTabMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AxisTabMain))
        return static_cast<void*>(const_cast< AxisTabMain*>(this));
    return QWidget::qt_metacast(_clname);
}

int AxisTabMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_AxisTabLabelBars[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   18,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AxisTabLabelBars[] = {
    "AxisTabLabelBars\0\0i\0locationChanged(int)\0"
};

const QMetaObject AxisTabLabelBars::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AxisTabLabelBars,
      qt_meta_data_AxisTabLabelBars, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AxisTabLabelBars::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AxisTabLabelBars::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AxisTabLabelBars::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AxisTabLabelBars))
        return static_cast<void*>(const_cast< AxisTabLabelBars*>(this));
    return QWidget::qt_metacast(_clname);
}

int AxisTabLabelBars::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: locationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_AxisTabTickLabels[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   19,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AxisTabTickLabels[] = {
    "AxisTabTickLabels\0\0i\0locationChanged(int)\0"
};

const QMetaObject AxisTabTickLabels::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AxisTabTickLabels,
      qt_meta_data_AxisTabTickLabels, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AxisTabTickLabels::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AxisTabTickLabels::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AxisTabTickLabels::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AxisTabTickLabels))
        return static_cast<void*>(const_cast< AxisTabTickLabels*>(this));
    return QWidget::qt_metacast(_clname);
}

int AxisTabTickLabels::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: locationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_AxisTabTickMarks[] = {

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

static const char qt_meta_stringdata_AxisTabTickMarks[] = {
    "AxisTabTickMarks\0"
};

const QMetaObject AxisTabTickMarks::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AxisTabTickMarks,
      qt_meta_data_AxisTabTickMarks, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AxisTabTickMarks::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AxisTabTickMarks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AxisTabTickMarks::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AxisTabTickMarks))
        return static_cast<void*>(const_cast< AxisTabTickMarks*>(this));
    return QWidget::qt_metacast(_clname);
}

int AxisTabTickMarks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_AxisTabSpecial[] = {

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

static const char qt_meta_stringdata_AxisTabSpecial[] = {
    "AxisTabSpecial\0"
};

const QMetaObject AxisTabSpecial::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AxisTabSpecial,
      qt_meta_data_AxisTabSpecial, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AxisTabSpecial::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AxisTabSpecial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AxisTabSpecial::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AxisTabSpecial))
        return static_cast<void*>(const_cast< AxisTabSpecial*>(this));
    return QWidget::qt_metacast(_clname);
}

int AxisTabSpecial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_frmAxisProp[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x0a,
      35,   12,   12,   12, 0x0a,
      46,   12,   12,   12, 0x0a,
      56,   12,   12,   12, 0x0a,
      70,   12,   66,   12, 0x0a,
      90,   84,   12,   12, 0x0a,
     115,  109,   12,   12, 0x0a,
     136,   84,   12,   12, 0x0a,
     159,  155,   12,   12, 0x0a,
     184,  177,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmAxisProp[] = {
    "frmAxisProp\0\0i\0selEditChanged(int)\0"
    "doAccept()\0doApply()\0doClose()\0int\0"
    "axes_aac_cb()\0value\0axis_scale_cb(int)\0"
    "onoff\0set_active_proc(int)\0"
    "set_axis_proc(int)\0gno\0update_ticks(int)\0"
    "axisno\0create_axes_dialog(int)\0"
};

const QMetaObject frmAxisProp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmAxisProp,
      qt_meta_data_frmAxisProp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmAxisProp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmAxisProp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmAxisProp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmAxisProp))
        return static_cast<void*>(const_cast< frmAxisProp*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmAxisProp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: selEditChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: doAccept(); break;
        case 2: doApply(); break;
        case 3: doClose(); break;
        case 4: { int _r = axes_aac_cb();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: axis_scale_cb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: set_active_proc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: set_axis_proc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: update_ticks((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: create_axes_dialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
static const uint qt_meta_data_frmNetCDF[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      18,   10,   10,   10, 0x0a,
      35,   10,   10,   10, 0x0a,
      57,   10,   10,   10, 0x0a,
      74,   10,   10,   10, 0x0a,
      84,   10,   10,   10, 0x0a,
     109,  100,   94,   10, 0x0a,
     166,  130,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmNetCDF[] = {
    "frmNetCDF\0\0init()\0update_netcdfs()\0"
    "do_netcdfquery_proc()\0do_netcdf_proc()\0"
    "doFiles()\0doClose()\0char*\0datatype\0"
    "getcdf_type(nc_type)\0"
    "type,file,exists,writeable,readable\0"
    "IOrequested(int,QString,bool,bool,bool)\0"
};

const QMetaObject frmNetCDF::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmNetCDF,
      qt_meta_data_frmNetCDF, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmNetCDF::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmNetCDF::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmNetCDF::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmNetCDF))
        return static_cast<void*>(const_cast< frmNetCDF*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmNetCDF::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: update_netcdfs(); break;
        case 2: do_netcdfquery_proc(); break;
        case 3: do_netcdf_proc(); break;
        case 4: doFiles(); break;
        case 5: doClose(); break;
        case 6: { char* _r = getcdf_type((*reinterpret_cast< nc_type(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< char**>(_a[0]) = _r; }  break;
        case 7: IOrequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
static const uint qt_meta_data_inputLine[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   10,   11,   10, 0x0a,
      25,   10,   11,   10, 0x0a,
      35,   10,   11,   10, 0x0a,
      49,   47,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_inputLine[] = {
    "inputLine\0\0int\0getSize()\0getType()\0"
    "getTarget()\0i\0formatChanged(int)\0"
};

const QMetaObject inputLine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_inputLine,
      qt_meta_data_inputLine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &inputLine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *inputLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *inputLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_inputLine))
        return static_cast<void*>(const_cast< inputLine*>(this));
    return QWidget::qt_metacast(_clname);
}

int inputLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = getSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = getType();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = getTarget();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: formatChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_pageHeaderInfo[] = {

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
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   29,   15,   15, 0x0a,
      57,   15,   15,   15, 0x0a,
      69,   15,   15,   15, 0x0a,
      85,   15,   15,   15, 0x0a,
      95,   93,   15,   15, 0x0a,
     109,   93,   15,   15, 0x0a,
     128,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_pageHeaderInfo[] = {
    "pageHeaderInfo\0\0readHeader()\0r\0"
    "changeRepresentation(int)\0doReadIni()\0"
    "updateOffsets()\0doNew()\0i\0doDelete(int)\0"
    "offsetChanged(int)\0doTestLoad()\0"
};

const QMetaObject pageHeaderInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pageHeaderInfo,
      qt_meta_data_pageHeaderInfo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pageHeaderInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pageHeaderInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pageHeaderInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pageHeaderInfo))
        return static_cast<void*>(const_cast< pageHeaderInfo*>(this));
    return QWidget::qt_metacast(_clname);
}

int pageHeaderInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: readHeader(); break;
        case 1: changeRepresentation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: doReadIni(); break;
        case 3: updateOffsets(); break;
        case 4: doNew(); break;
        case 5: doDelete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: offsetChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: doTestLoad(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void pageHeaderInfo::readHeader()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_pageDataInfo[] = {

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
      16,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   14,   13,   13, 0x0a,
      62,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_pageDataInfo[] = {
    "pageDataInfo\0\0i\0newChannelCount(int)\0"
    "channelCountChanged(int)\0eofToggled(bool)\0"
};

const QMetaObject pageDataInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pageDataInfo,
      qt_meta_data_pageDataInfo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pageDataInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pageDataInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pageDataInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pageDataInfo))
        return static_cast<void*>(const_cast< pageDataInfo*>(this));
    return QWidget::qt_metacast(_clname);
}

int pageDataInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newChannelCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: channelCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: eofToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void pageDataInfo::newChannelCount(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_pageFileInfo[] = {

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
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   29,   13,   13, 0x0a,
      58,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_pageFileInfo[] = {
    "pageFileInfo\0\0requestInfos()\0event\0"
    "showEvent(QShowEvent*)\0ShowInfos()\0"
};

const QMetaObject pageFileInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pageFileInfo,
      qt_meta_data_pageFileInfo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pageFileInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pageFileInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pageFileInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pageFileInfo))
        return static_cast<void*>(const_cast< pageFileInfo*>(this));
    return QWidget::qt_metacast(_clname);
}

int pageFileInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: requestInfos(); break;
        case 1: showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 2: ShowInfos(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void pageFileInfo::requestInfos()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_pageImportInfo[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_pageImportInfo[] = {
    "pageImportInfo\0\0i\0newChannelCount(int)\0"
};

const QMetaObject pageImportInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pageImportInfo,
      qt_meta_data_pageImportInfo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pageImportInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pageImportInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pageImportInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pageImportInfo))
        return static_cast<void*>(const_cast< pageImportInfo*>(this));
    return QWidget::qt_metacast(_clname);
}

int pageImportInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newChannelCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_frmBinaryFormatInput[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,
      29,   21,   21,   21, 0x0a,
      44,   42,   21,   21, 0x0a,
      64,   21,   21,   21, 0x0a,
      83,   21,   21,   21, 0x0a,
     102,   21,   21,   21, 0x0a,
     119,   21,   21,   21, 0x0a,
     140,  138,   21,   21, 0x0a,
     165,  138,   21,   21, 0x0a,
     190,   21,   21,   21, 0x0a,
     197,   21,   21,   21, 0x0a,
     207,   21,   21,   21, 0x0a,
     218,   21,   21,   21, 0x0a,
     234,  138,   21,   21, 0x0a,
     264,   21,   21,   21, 0x0a,
     294,  290,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmBinaryFormatInput[] = {
    "frmBinaryFormatInput\0\0init()\0readHeader()\0"
    "t\0headerToggled(bool)\0doSaveFileFormat()\0"
    "doLoadFileFormat()\0SelectDataFile()\0"
    "SelectHeaderFile()\0i\0formatSourceChanged(int)\0"
    "HeaderFormatChanged(int)\0doOK()\0"
    "doClose()\0doAccept()\0transmitInfos()\0"
    "initSettings(importSettings&)\0"
    "convertSettingsToString()\0ifi\0"
    "doReadDataFromHeader(ifstream&)\0"
};

const QMetaObject frmBinaryFormatInput::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmBinaryFormatInput,
      qt_meta_data_frmBinaryFormatInput, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmBinaryFormatInput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmBinaryFormatInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmBinaryFormatInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmBinaryFormatInput))
        return static_cast<void*>(const_cast< frmBinaryFormatInput*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmBinaryFormatInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: readHeader(); break;
        case 2: headerToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: doSaveFileFormat(); break;
        case 4: doLoadFileFormat(); break;
        case 5: SelectDataFile(); break;
        case 6: SelectHeaderFile(); break;
        case 7: formatSourceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: HeaderFormatChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: doOK(); break;
        case 10: doClose(); break;
        case 11: doAccept(); break;
        case 12: transmitInfos(); break;
        case 13: initSettings((*reinterpret_cast< importSettings(*)>(_a[1]))); break;
        case 14: convertSettingsToString(); break;
        case 15: doReadDataFromHeader((*reinterpret_cast< ifstream(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
static const uint qt_meta_data_frmSetEditor[] = {

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
      26,   14,   13,   13, 0x0a,
      40,   13,   13,   13, 0x0a,
      51,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmSetEditor[] = {
    "frmSetEditor\0\0g_no,set_no\0init(int,int)\0"
    "doUpdate()\0doClose()\0"
};

const QMetaObject frmSetEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmSetEditor,
      qt_meta_data_frmSetEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmSetEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmSetEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmSetEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmSetEditor))
        return static_cast<void*>(const_cast< frmSetEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmSetEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: doUpdate(); break;
        case 2: doClose(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_frmUndoList[] = {

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
      13,   12,   12,   12, 0x0a,
      20,   12,   12,   12, 0x0a,
      29,   12,   12,   12, 0x0a,
      38,   12,   12,   12, 0x0a,
      54,   48,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_frmUndoList[] = {
    "frmUndoList\0\0init()\0doUndo()\0doRedo()\0"
    "doClose()\0state\0doToggleActive(int)\0"
};

const QMetaObject frmUndoList::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmUndoList,
      qt_meta_data_frmUndoList, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmUndoList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmUndoList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmUndoList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmUndoList))
        return static_cast<void*>(const_cast< frmUndoList*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmUndoList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: doUndo(); break;
        case 2: doRedo(); break;
        case 3: doClose(); break;
        case 4: doToggleActive((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
