/****************************************************************************
** Meta object code from reading C++ file 'tst_testbonustask1.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../PA7/tests/testbonustask1/tst_testbonustask1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_testbonustask1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestBonusTask1_t {
    uint offsetsAndSizes[10];
    char stringdata0[15];
    char stringdata1[29];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TestBonusTask1_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_TestBonusTask1_t qt_meta_stringdata_TestBonusTask1 = {
    {
        QT_MOC_LITERAL(0, 14),  // "TestBonusTask1"
        QT_MOC_LITERAL(15, 28),  // "testAlterAnswerFunction_data"
        QT_MOC_LITERAL(44, 0),  // ""
        QT_MOC_LITERAL(45, 23),  // "testAlterAnswerFunction"
        QT_MOC_LITERAL(69, 21)   // "testAbsurdRoundWindow"
    },
    "TestBonusTask1",
    "testAlterAnswerFunction_data",
    "",
    "testAlterAnswerFunction",
    "testAbsurdRoundWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestBonusTask1[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    0,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestBonusTask1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestBonusTask1 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->testAlterAnswerFunction_data(); break;
        case 1: _t->testAlterAnswerFunction(); break;
        case 2: _t->testAbsurdRoundWindow(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TestBonusTask1::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestBonusTask1.offsetsAndSizes,
    qt_meta_data_TestBonusTask1,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TestBonusTask1_t
, QtPrivate::TypeAndForceComplete<TestBonusTask1, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TestBonusTask1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestBonusTask1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestBonusTask1.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestBonusTask1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
