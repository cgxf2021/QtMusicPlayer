/****************************************************************************
** Meta object code from reading C++ file 'work.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../header/work.hpp"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'work.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSWorkerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWorkerENDCLASS = QtMocHelpers::stringData(
    "Worker",
    "parseFinished",
    "",
    "isFromDatabase",
    "parseSong",
    "url",
    "parseLyrics",
    "Song*",
    "song",
    "saveSongToDatabase",
    "loadSongFromDatabase"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWorkerENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[7];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[10];
    char stringdata5[4];
    char stringdata6[12];
    char stringdata7[6];
    char stringdata8[5];
    char stringdata9[19];
    char stringdata10[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWorkerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWorkerENDCLASS_t qt_meta_stringdata_CLASSWorkerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Worker"
        QT_MOC_LITERAL(7, 13),  // "parseFinished"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 14),  // "isFromDatabase"
        QT_MOC_LITERAL(37, 9),  // "parseSong"
        QT_MOC_LITERAL(47, 3),  // "url"
        QT_MOC_LITERAL(51, 11),  // "parseLyrics"
        QT_MOC_LITERAL(63, 5),  // "Song*"
        QT_MOC_LITERAL(69, 4),  // "song"
        QT_MOC_LITERAL(74, 18),  // "saveSongToDatabase"
        QT_MOC_LITERAL(93, 20)   // "loadSongFromDatabase"
    },
    "Worker",
    "parseFinished",
    "",
    "isFromDatabase",
    "parseSong",
    "url",
    "parseLyrics",
    "Song*",
    "song",
    "saveSongToDatabase",
    "loadSongFromDatabase"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWorkerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       1,    0,   53,    2, 0x26,    3 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   54,    2, 0x0a,    4 /* Public */,
       6,    1,   57,    2, 0x0a,    6 /* Public */,
       9,    1,   60,    2, 0x0a,    8 /* Public */,
      10,    0,   63,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QUrl,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Worker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSWorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Worker, std::true_type>,
        // method 'parseFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'parseFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'parseSong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        // method 'parseLyrics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Song *, std::false_type>,
        // method 'saveSongToDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Song *, std::false_type>,
        // method 'loadSongFromDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Worker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->parseFinished((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->parseFinished(); break;
        case 2: _t->parseSong((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 3: _t->parseLyrics((*reinterpret_cast< std::add_pointer_t<Song*>>(_a[1]))); break;
        case 4: _t->saveSongToDatabase((*reinterpret_cast< std::add_pointer_t<Song*>>(_a[1]))); break;
        case 5: _t->loadSongFromDatabase(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Worker::*)(bool );
            if (_t _q_method = &Worker::parseFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Worker::parseFinished(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
