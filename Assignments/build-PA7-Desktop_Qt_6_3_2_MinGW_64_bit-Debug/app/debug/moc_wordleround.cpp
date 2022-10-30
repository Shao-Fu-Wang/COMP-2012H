/****************************************************************************
** Meta object code from reading C++ file 'wordleround.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../PA7/app/wordleround.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wordleround.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WordleRound_t {
    uint offsetsAndSizes[20];
    char stringdata0[12];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[9];
    char stringdata5[10];
    char stringdata6[20];
    char stringdata7[4];
    char stringdata8[6];
    char stringdata9[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_WordleRound_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_WordleRound_t qt_meta_stringdata_WordleRound = {
    {
        QT_MOC_LITERAL(0, 11),  // "WordleRound"
        QT_MOC_LITERAL(12, 11),  // "invalidWord"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 15),  // "invalidHardWord"
        QT_MOC_LITERAL(41, 8),  // "roundWin"
        QT_MOC_LITERAL(50, 9),  // "roundLose"
        QT_MOC_LITERAL(60, 19),  // "updateKeyboardColor"
        QT_MOC_LITERAL(80, 3),  // "key"
        QT_MOC_LITERAL(84, 5),  // "color"
        QT_MOC_LITERAL(90, 18)   // "resetKeyboardColor"
    },
    "WordleRound",
    "invalidWord",
    "",
    "invalidHardWord",
    "roundWin",
    "roundLose",
    "updateKeyboardColor",
    "key",
    "color",
    "resetKeyboardColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WordleRound[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,
       5,    0,   53,    2, 0x06,    4 /* Public */,
       6,    2,   54,    2, 0x06,    5 /* Public */,
       9,    0,   59,    2, 0x06,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QChar, QMetaType::QColor,    7,    8,
    QMetaType::Void,

       0        // eod
};

void WordleRound::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WordleRound *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->invalidWord(); break;
        case 1: _t->invalidHardWord(); break;
        case 2: _t->roundWin(); break;
        case 3: _t->roundLose(); break;
        case 4: _t->updateKeyboardColor((*reinterpret_cast< std::add_pointer_t<QChar>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2]))); break;
        case 5: _t->resetKeyboardColor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WordleRound::*)();
            if (_t _q_method = &WordleRound::invalidWord; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WordleRound::*)();
            if (_t _q_method = &WordleRound::invalidHardWord; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WordleRound::*)();
            if (_t _q_method = &WordleRound::roundWin; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WordleRound::*)();
            if (_t _q_method = &WordleRound::roundLose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WordleRound::*)(const QChar & , const QColor & );
            if (_t _q_method = &WordleRound::updateKeyboardColor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WordleRound::*)();
            if (_t _q_method = &WordleRound::resetKeyboardColor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject WordleRound::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WordleRound.offsetsAndSizes,
    qt_meta_data_WordleRound,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_WordleRound_t
, QtPrivate::TypeAndForceComplete<WordleRound, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QChar &, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *WordleRound::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WordleRound::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WordleRound.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WordleRound::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WordleRound::invalidWord()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WordleRound::invalidHardWord()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WordleRound::roundWin()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WordleRound::roundLose()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WordleRound::updateKeyboardColor(const QChar & _t1, const QColor & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void WordleRound::resetKeyboardColor()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
