/****************************************************************************
** Meta object code from reading C++ file 'keyboard.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../PA7/app/keyboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Keyboard_t {
    uint offsetsAndSizes[18];
    char stringdata0[9];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[16];
    char stringdata5[15];
    char stringdata6[4];
    char stringdata7[6];
    char stringdata8[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Keyboard_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Keyboard_t qt_meta_stringdata_Keyboard = {
    {
        QT_MOC_LITERAL(0, 8),  // "Keyboard"
        QT_MOC_LITERAL(9, 18),  // "keyOnScreenPressed"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 13),  // "delKeyPressed"
        QT_MOC_LITERAL(43, 15),  // "enterKeyPressed"
        QT_MOC_LITERAL(59, 14),  // "updateKeyColor"
        QT_MOC_LITERAL(74, 3),  // "key"
        QT_MOC_LITERAL(78, 5),  // "color"
        QT_MOC_LITERAL(84, 13)   // "resetKeyColor"
    },
    "Keyboard",
    "keyOnScreenPressed",
    "",
    "delKeyPressed",
    "enterKeyPressed",
    "updateKeyColor",
    "key",
    "color",
    "resetKeyColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Keyboard[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x10a,    1 /* Public | MethodIsConst  */,
       3,    0,   45,    2, 0x10a,    2 /* Public | MethodIsConst  */,
       4,    0,   46,    2, 0x10a,    3 /* Public | MethodIsConst  */,
       5,    2,   47,    2, 0x0a,    4 /* Public */,
       8,    0,   52,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QChar, QMetaType::QColor,    6,    7,
    QMetaType::Void,

       0        // eod
};

void Keyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Keyboard *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->keyOnScreenPressed(); break;
        case 1: _t->delKeyPressed(); break;
        case 2: _t->enterKeyPressed(); break;
        case 3: _t->updateKeyColor((*reinterpret_cast< std::add_pointer_t<QChar>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2]))); break;
        case 4: _t->resetKeyColor(); break;
        default: ;
        }
    }
}

const QMetaObject Keyboard::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Keyboard.offsetsAndSizes,
    qt_meta_data_Keyboard,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Keyboard_t
, QtPrivate::TypeAndForceComplete<Keyboard, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QChar &, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Keyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Keyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Keyboard.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Keyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
