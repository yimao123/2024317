/****************************************************************************
** Meta object code from reading C++ file 'scrollzoomer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scrollzoomer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scrollzoomer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScrollZoomer_t {
    QByteArrayData data[7];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScrollZoomer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScrollZoomer_t qt_meta_stringdata_ScrollZoomer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ScrollZoomer"
QT_MOC_LITERAL(1, 13, 14), // "scrollBarMoved"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "Qt::Orientation"
QT_MOC_LITERAL(4, 45, 1), // "o"
QT_MOC_LITERAL(5, 47, 3), // "min"
QT_MOC_LITERAL(6, 51, 3) // "max"

    },
    "ScrollZoomer\0scrollBarMoved\0\0"
    "Qt::Orientation\0o\0min\0max"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScrollZoomer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double, QMetaType::Double,    4,    5,    6,

       0        // eod
};

void ScrollZoomer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScrollZoomer *_t = static_cast<ScrollZoomer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scrollBarMoved((*reinterpret_cast< Qt::Orientation(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject ScrollZoomer::staticMetaObject = {
    { &QwtPlotZoomer::staticMetaObject, qt_meta_stringdata_ScrollZoomer.data,
      qt_meta_data_ScrollZoomer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ScrollZoomer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScrollZoomer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ScrollZoomer.stringdata0))
        return static_cast<void*>(const_cast< ScrollZoomer*>(this));
    return QwtPlotZoomer::qt_metacast(_clname);
}

int ScrollZoomer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlotZoomer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
