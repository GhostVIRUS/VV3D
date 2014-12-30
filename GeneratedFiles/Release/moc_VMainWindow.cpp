/****************************************************************************
** Meta object code from reading C++ file 'VMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VMainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VMainWindow_t {
    QByteArrayData data[28];
    char stringdata[299];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VMainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VMainWindow_t qt_meta_stringdata_VMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 13),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 4),
QT_MOC_LITERAL(4, 32, 4),
QT_MOC_LITERAL(5, 37, 6),
QT_MOC_LITERAL(6, 44, 1),
QT_MOC_LITERAL(7, 46, 1),
QT_MOC_LITERAL(8, 48, 7),
QT_MOC_LITERAL(9, 56, 14),
QT_MOC_LITERAL(10, 71, 3),
QT_MOC_LITERAL(11, 75, 1),
QT_MOC_LITERAL(12, 77, 1),
QT_MOC_LITERAL(13, 79, 1),
QT_MOC_LITERAL(14, 81, 14),
QT_MOC_LITERAL(15, 96, 13),
QT_MOC_LITERAL(16, 110, 15),
QT_MOC_LITERAL(17, 126, 14),
QT_MOC_LITERAL(18, 141, 9),
QT_MOC_LITERAL(19, 151, 15),
QT_MOC_LITERAL(20, 167, 2),
QT_MOC_LITERAL(21, 170, 5),
QT_MOC_LITERAL(22, 176, 20),
QT_MOC_LITERAL(23, 197, 32),
QT_MOC_LITERAL(24, 230, 20),
QT_MOC_LITERAL(25, 251, 18),
QT_MOC_LITERAL(26, 270, 12),
QT_MOC_LITERAL(27, 283, 15)
    },
    "VMainWindow\0createNewFile\0\0name\0type\0"
    "VPoint\0a\0b\0newFile\0updateParticle\0row\0"
    "x\0y\0z\0deleteParticle\0editParticles\0"
    "updateParticles\0QList<VPoint*>\0particles\0"
    "changeCellColor\0id\0color\0toggleCellVisibility\0"
    "toggleParticlesNumbersVisibility\0"
    "toggleAxesVisibility\0restoreDefaultView\0"
    "showCellInfo\0closeContentTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   79,    2, 0x0a /* Public */,
       8,    0,   88,    2, 0x0a /* Public */,
       9,    4,   89,    2, 0x0a /* Public */,
      14,    1,   98,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,
      16,    1,  102,    2, 0x0a /* Public */,
      19,    2,  105,    2, 0x0a /* Public */,
      22,    1,  110,    2, 0x0a /* Public */,
      23,    0,  113,    2, 0x0a /* Public */,
      24,    0,  114,    2, 0x0a /* Public */,
      25,    0,  115,    2, 0x0a /* Public */,
      26,    1,  116,    2, 0x0a /* Public */,
      27,    1,  119,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5,    3,    4,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::QColor,   20,   21,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,

       0        // eod
};

void VMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VMainWindow *_t = static_cast<VMainWindow *>(_o);
        switch (_id) {
        case 0: _t->createNewFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< VPoint(*)>(_a[3])),(*reinterpret_cast< VPoint(*)>(_a[4]))); break;
        case 1: _t->newFile(); break;
        case 2: _t->updateParticle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 3: _t->deleteParticle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->editParticles(); break;
        case 5: _t->updateParticles((*reinterpret_cast< QList<VPoint*>(*)>(_a[1]))); break;
        case 6: _t->changeCellColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 7: _t->toggleCellVisibility((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->toggleParticlesNumbersVisibility(); break;
        case 9: _t->toggleAxesVisibility(); break;
        case 10: _t->restoreDefaultView(); break;
        case 11: _t->showCellInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->closeContentTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject VMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VMainWindow.data,
      qt_meta_data_VMainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *VMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VMainWindow.stringdata))
        return static_cast<void*>(const_cast< VMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
