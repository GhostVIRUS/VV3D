/****************************************************************************
** Meta object code from reading C++ file 'VNewDiagramDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VNewDiagramDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VNewDiagramDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VNewDiagramDialog_t {
    QByteArrayData data[9];
    char stringdata[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VNewDiagramDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VNewDiagramDialog_t qt_meta_stringdata_VNewDiagramDialog = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 14),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 4),
QT_MOC_LITERAL(4, 39, 4),
QT_MOC_LITERAL(5, 44, 6),
QT_MOC_LITERAL(6, 51, 1),
QT_MOC_LITERAL(7, 53, 1),
QT_MOC_LITERAL(8, 55, 6)
    },
    "VNewDiagramDialog\0valuesAccepted\0\0"
    "name\0type\0VPoint\0a\0b\0accept"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VNewDiagramDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5,    3,    4,    6,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void VNewDiagramDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VNewDiagramDialog *_t = static_cast<VNewDiagramDialog *>(_o);
        switch (_id) {
        case 0: _t->valuesAccepted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< VPoint(*)>(_a[3])),(*reinterpret_cast< VPoint(*)>(_a[4]))); break;
        case 1: _t->accept(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VNewDiagramDialog::*_t)(QString , int , VPoint , VPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VNewDiagramDialog::valuesAccepted)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject VNewDiagramDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VNewDiagramDialog.data,
      qt_meta_data_VNewDiagramDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *VNewDiagramDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VNewDiagramDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VNewDiagramDialog.stringdata))
        return static_cast<void*>(const_cast< VNewDiagramDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int VNewDiagramDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void VNewDiagramDialog::valuesAccepted(QString _t1, int _t2, VPoint _t3, VPoint _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
