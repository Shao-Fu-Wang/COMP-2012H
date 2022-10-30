/****************************************************************************
** Meta object code from reading C++ file 'tst_testbonustask5.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../PA7/tests/testbonustask5/tst_testbonustask5.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_testbonustask5.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestBonusTask5_t {
    uint offsetsAndSizes[8];
    char stringdata0[15];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TestBonusTask5_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_TestBonusTask5_t qt_meta_stringdata_TestBonusTask5 = {
    {
        QT_MOC_LITERAL(0, 14),  // "TestBonusTask5"
        QT_MOC_LITERAL(15, 23),  // "testReadAnswerFile_data"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 18)   // "testReadAnswerFile"
    },
    "TestBonusTask5",
    "testReadAnswerFile_data",
    "",
    "testReadAnswerFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestBonusTask5[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x08,    1 /* Private */,
       3,    0,   27,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestBonusTask5::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestBonusTask5 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->testReadAnswerFile_data(); break;
        case 1: _t->testReadAnswerFile(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TestBonusTask5::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestBonusTask5.offsetsAndSizes,
    qt_meta_data_TestBonusTask5,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TestBonusTask5_t
, QtPrivate::TypeAndForceComplete<TestBonusTask5, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TestBonusTask5::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestBonusTask5::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestBonusTask5.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestBonusTask5::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
