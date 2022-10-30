/****************************************************************************
** Meta object code from reading C++ file 'roundwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../PA7/app/roundwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roundwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RoundWindow_t {
    uint offsetsAndSizes[22];
    char stringdata0[12];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[21];
    char stringdata5[14];
    char stringdata6[15];
    char stringdata7[19];
    char stringdata8[18];
    char stringdata9[11];
    char stringdata10[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_RoundWindow_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_RoundWindow_t qt_meta_stringdata_RoundWindow = {
    {
        QT_MOC_LITERAL(0, 11),  // "RoundWindow"
        QT_MOC_LITERAL(12, 10),  // "closeRound"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 16),  // "popupInvalidWord"
        QT_MOC_LITERAL(41, 20),  // "popupInvalidHardWord"
        QT_MOC_LITERAL(62, 13),  // "popupRoundWin"
        QT_MOC_LITERAL(76, 14),  // "popupRoundLose"
        QT_MOC_LITERAL(91, 18),  // "popupConfirmGiveUp"
        QT_MOC_LITERAL(110, 17),  // "popupConfirmReset"
        QT_MOC_LITERAL(128, 10),  // "popupCheat"
        QT_MOC_LITERAL(139, 9)   // "popupHint"
    },
    "RoundWindow",
    "closeRound",
    "",
    "popupInvalidWord",
    "popupInvalidHardWord",
    "popupRoundWin",
    "popupRoundLose",
    "popupConfirmGiveUp",
    "popupConfirmReset",
    "popupCheat",
    "popupHint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoundWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   69,    2, 0x0a,    2 /* Public */,
       4,    0,   70,    2, 0x0a,    3 /* Public */,
       5,    0,   71,    2, 0x0a,    4 /* Public */,
       6,    0,   72,    2, 0x0a,    5 /* Public */,
       7,    0,   73,    2, 0x0a,    6 /* Public */,
       8,    0,   74,    2, 0x0a,    7 /* Public */,
       9,    0,   75,    2, 0x0a,    8 /* Public */,
      10,    0,   76,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RoundWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RoundWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->closeRound(); break;
        case 1: _t->popupInvalidWord(); break;
        case 2: _t->popupInvalidHardWord(); break;
        case 3: _t->popupRoundWin(); break;
        case 4: _t->popupRoundLose(); break;
        case 5: _t->popupConfirmGiveUp(); break;
        case 6: _t->popupConfirmReset(); break;
        case 7: _t->popupCheat(); break;
        case 8: _t->popupHint(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RoundWindow::*)();
            if (_t _q_method = &RoundWindow::closeRound; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject RoundWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_RoundWindow.offsetsAndSizes,
    qt_meta_data_RoundWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RoundWindow_t
, QtPrivate::TypeAndForceComplete<RoundWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RoundWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoundWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RoundWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RoundWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void RoundWindow::closeRound()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
