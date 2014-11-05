/****************************************************************************
** Meta object code from reading C++ file 'VParticlesTableEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VParticlesTableEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VParticlesTableEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VParticlesTableEdit_t {
    QByteArrayData data[12];
    char stringdata[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VParticlesTableEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VParticlesTableEdit_t qt_meta_stringdata_VParticlesTableEdit = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 15),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 3),
QT_MOC_LITERAL(4, 41, 1),
QT_MOC_LITERAL(5, 43, 1),
QT_MOC_LITERAL(6, 45, 1),
QT_MOC_LITERAL(7, 47, 15),
QT_MOC_LITERAL(8, 63, 6),
QT_MOC_LITERAL(9, 70, 9),
QT_MOC_LITERAL(10, 80, 8),
QT_MOC_LITERAL(11, 89, 6)
    },
    "VParticlesTableEdit\0particleChanged\0"
    "\0row\0x\0y\0z\0particleDeleted\0addRow\0"
    "deleteRow\0checkRow\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VParticlesTableEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   51,    2, 0x0a /* Public */,
       9,    0,   52,    2, 0x0a /* Public */,
      10,    2,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,   11,

       0        // eod
};

void VParticlesTableEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VParticlesTableEdit *_t = static_cast<VParticlesTableEdit *>(_o);
        switch (_id) {
        case 0: _t->particleChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: _t->particleDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->addRow(); break;
        case 3: _t->deleteRow(); break;
        case 4: _t->checkRow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VParticlesTableEdit::*_t)(int , double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VParticlesTableEdit::particleChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (VParticlesTableEdit::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VParticlesTableEdit::particleDeleted)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject VParticlesTableEdit::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_VParticlesTableEdit.data,
      qt_meta_data_VParticlesTableEdit,  qt_static_metacall, 0, 0}
};


const QMetaObject *VParticlesTableEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VParticlesTableEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VParticlesTableEdit.stringdata))
        return static_cast<void*>(const_cast< VParticlesTableEdit*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int VParticlesTableEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void VParticlesTableEdit::particleChanged(int _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VParticlesTableEdit::particleDeleted(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
