/****************************************************************************
** Meta object code from reading C++ file 'pomodoro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pomodoro_app/pomodoro.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pomodoro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Pomodoro_t {
    QByteArrayData data[8];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pomodoro_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pomodoro_t qt_meta_stringdata_Pomodoro = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Pomodoro"
QT_MOC_LITERAL(1, 9, 15), // "setModePomodoro"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "setModeShortBreak"
QT_MOC_LITERAL(4, 44, 16), // "setModeLongBreak"
QT_MOC_LITERAL(5, 61, 14), // "timerTriggered"
QT_MOC_LITERAL(6, 76, 17), // "displayTimeUpdate"
QT_MOC_LITERAL(7, 94, 10) // "resetTimer"

    },
    "Pomodoro\0setModePomodoro\0\0setModeShortBreak\0"
    "setModeLongBreak\0timerTriggered\0"
    "displayTimeUpdate\0resetTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pomodoro[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Pomodoro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Pomodoro *_t = static_cast<Pomodoro *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setModePomodoro(); break;
        case 1: _t->setModeShortBreak(); break;
        case 2: _t->setModeLongBreak(); break;
        case 3: _t->timerTriggered(); break;
        case 4: _t->displayTimeUpdate(); break;
        case 5: _t->resetTimer(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Pomodoro::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Pomodoro.data,
      qt_meta_data_Pomodoro,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Pomodoro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pomodoro::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Pomodoro.stringdata0))
        return static_cast<void*>(const_cast< Pomodoro*>(this));
    return QObject::qt_metacast(_clname);
}

int Pomodoro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
