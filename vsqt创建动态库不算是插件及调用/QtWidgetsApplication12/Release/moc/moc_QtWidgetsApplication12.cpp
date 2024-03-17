/****************************************************************************
** Meta object code from reading C++ file 'QtWidgetsApplication12.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtWidgetsApplication12.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtWidgetsApplication12.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QtWidgetsApplication12_t {
    QByteArrayData data[3];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtWidgetsApplication12_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtWidgetsApplication12_t qt_meta_stringdata_QtWidgetsApplication12 = {
    {
QT_MOC_LITERAL(0, 0, 22), // "QtWidgetsApplication12"
QT_MOC_LITERAL(1, 23, 12), // "OnClickDoBtn"
QT_MOC_LITERAL(2, 36, 0) // ""

    },
    "QtWidgetsApplication12\0OnClickDoBtn\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtWidgetsApplication12[] = {

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
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QtWidgetsApplication12::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtWidgetsApplication12 *_t = static_cast<QtWidgetsApplication12 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnClickDoBtn(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QtWidgetsApplication12::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QtWidgetsApplication12.data,
      qt_meta_data_QtWidgetsApplication12,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtWidgetsApplication12::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtWidgetsApplication12::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtWidgetsApplication12.stringdata0))
        return static_cast<void*>(const_cast< QtWidgetsApplication12*>(this));
    return QWidget::qt_metacast(_clname);
}

int QtWidgetsApplication12::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
