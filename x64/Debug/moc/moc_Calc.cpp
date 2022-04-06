/****************************************************************************
** Meta object code from reading C++ file 'Calc.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Calc.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Calc.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calc_t {
    const uint offsetsAndSize[30];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Calc_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Calc_t qt_meta_stringdata_Calc = {
    {
QT_MOC_LITERAL(0, 4), // "Calc"
QT_MOC_LITERAL(5, 13), // "valeurChangee"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 6), // "valeur"
QT_MOC_LITERAL(27, 13), // "changerValeur"
QT_MOC_LITERAL(41, 7), // "effacer"
QT_MOC_LITERAL(49, 14), // "ajouterChiffre"
QT_MOC_LITERAL(64, 7), // "chiffre"
QT_MOC_LITERAL(72, 16), // "changerOperation"
QT_MOC_LITERAL(89, 22), // "function<int(int,int)>"
QT_MOC_LITERAL(112, 9), // "operation"
QT_MOC_LITERAL(122, 13), // "operationPlus"
QT_MOC_LITERAL(136, 14), // "operationMoins"
QT_MOC_LITERAL(151, 13), // "operationEgal"
QT_MOC_LITERAL(165, 18) // "effectuerOperation"

    },
    "Calc\0valeurChangee\0\0valeur\0changerValeur\0"
    "effacer\0ajouterChiffre\0chiffre\0"
    "changerOperation\0function<int(int,int)>\0"
    "operation\0operationPlus\0operationMoins\0"
    "operationEgal\0effectuerOperation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calc[] = {

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
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   71,    2, 0x0a,    3 /* Public */,
       5,    0,   74,    2, 0x0a,    5 /* Public */,
       6,    1,   75,    2, 0x0a,    6 /* Public */,
       8,    1,   78,    2, 0x0a,    8 /* Public */,
      11,    0,   81,    2, 0x0a,   10 /* Public */,
      12,    0,   82,    2, 0x0a,   11 /* Public */,
      13,    0,   83,    2, 0x0a,   12 /* Public */,
      14,    0,   84,    2, 0x0a,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Calc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Calc *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valeurChangee((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->changerValeur((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->effacer(); break;
        case 3: _t->ajouterChiffre((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->changerOperation((*reinterpret_cast< std::add_pointer_t<function<int(int,int)>>>(_a[1]))); break;
        case 5: _t->operationPlus(); break;
        case 6: _t->operationMoins(); break;
        case 7: _t->operationEgal(); break;
        case 8: _t->effectuerOperation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Calc::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calc::valeurChangee)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Calc::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Calc.offsetsAndSize,
    qt_meta_data_Calc,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Calc_t
, QtPrivate::TypeAndForceComplete<Calc, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const function<int(int,int)> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Calc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calc.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Calc::valeurChangee(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
