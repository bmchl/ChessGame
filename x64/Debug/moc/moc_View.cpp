/****************************************************************************
** Meta object code from reading C++ file 'View.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../View.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'View.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_view__ChessWindow_t {
    const uint offsetsAndSize[18];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_view__ChessWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_view__ChessWindow_t qt_meta_stringdata_view__ChessWindow = {
    {
QT_MOC_LITERAL(0, 17), // "view::ChessWindow"
QT_MOC_LITERAL(18, 14), // "selectedSquare"
QT_MOC_LITERAL(33, 8), // "Position"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 1), // "x"
QT_MOC_LITERAL(45, 1), // "y"
QT_MOC_LITERAL(47, 12), // "QPushButton*"
QT_MOC_LITERAL(60, 6), // "button"
QT_MOC_LITERAL(67, 13) // "pieceSelected"

    },
    "view::ChessWindow\0selectedSquare\0"
    "Position\0\0x\0y\0QPushButton*\0button\0"
    "pieceSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_view__ChessWindow[] = {

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
       1,    3,   26,    3, 0x0a,    1 /* Public */,
       8,    1,   33,    3, 0x0a,    5 /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::Int, QMetaType::Int, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void view::ChessWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChessWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { Position _r = _t->selectedSquare((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QPushButton*>>(_a[3])));
            if (_a[0]) *reinterpret_cast< Position*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->pieceSelected((*reinterpret_cast< std::add_pointer_t<QPushButton*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPushButton* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPushButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject view::ChessWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_view__ChessWindow.offsetsAndSize,
    qt_meta_data_view__ChessWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_view__ChessWindow_t
, QtPrivate::TypeAndForceComplete<ChessWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<Position, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QPushButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPushButton *, std::false_type>


>,
    nullptr
} };


const QMetaObject *view::ChessWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view::ChessWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view__ChessWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int view::ChessWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
