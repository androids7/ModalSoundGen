/****************************************************************************
** Meta object code from reading C++ file 'TetViewerFrame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TetViewerFrame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TetViewerFrame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TetViewerFrame_t {
    QByteArrayData data[13];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TetViewerFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TetViewerFrame_t qt_meta_stringdata_TetViewerFrame = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TetViewerFrame"
QT_MOC_LITERAL(1, 15, 4), // "open"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "export_bin_tet"
QT_MOC_LITERAL(4, 36, 17), // "export_abaqus_tet"
QT_MOC_LITERAL(5, 54, 17), // "check_useless_vtx"
QT_MOC_LITERAL(6, 72, 10), // "load_modes"
QT_MOC_LITERAL(7, 83, 12), // "modes_params"
QT_MOC_LITERAL(8, 96, 12), // "set_mode_sel"
QT_MOC_LITERAL(9, 109, 3), // "mId"
QT_MOC_LITERAL(10, 113, 18), // "mode_scale_changed"
QT_MOC_LITERAL(11, 132, 1), // "s"
QT_MOC_LITERAL(12, 134, 17) // "mode_vis_finished"

    },
    "TetViewerFrame\0open\0\0export_bin_tet\0"
    "export_abaqus_tet\0check_useless_vtx\0"
    "load_modes\0modes_params\0set_mode_sel\0"
    "mId\0mode_scale_changed\0s\0mode_vis_finished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TetViewerFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    1,   65,    2, 0x0a /* Public */,
      10,    1,   68,    2, 0x0a /* Public */,
      12,    1,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void TetViewerFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TetViewerFrame *_t = static_cast<TetViewerFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open(); break;
        case 1: _t->export_bin_tet(); break;
        case 2: _t->export_abaqus_tet(); break;
        case 3: _t->check_useless_vtx(); break;
        case 4: _t->load_modes(); break;
        case 5: _t->modes_params(); break;
        case 6: _t->set_mode_sel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->mode_scale_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->mode_vis_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TetViewerFrame::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TetViewerFrame.data,
      qt_meta_data_TetViewerFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TetViewerFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TetViewerFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TetViewerFrame.stringdata0))
        return static_cast<void*>(const_cast< TetViewerFrame*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TetViewerFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
