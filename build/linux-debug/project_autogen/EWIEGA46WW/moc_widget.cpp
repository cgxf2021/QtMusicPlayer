/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../widget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWidgetENDCLASS = QtMocHelpers::stringData(
    "Widget",
    "addSongSignal",
    "",
    "url",
    "saveSongToDatabaseSignal",
    "Song*",
    "song",
    "loadSongListFromDatabaseSignal",
    "addMusicBtnClicked",
    "playBtnClicked",
    "leftSwitchBtnClicked",
    "rightSwitchBtnClicked",
    "playModeBtnClicked",
    "handlePlayBackStateChanged",
    "QMediaPlayer::PlaybackState",
    "newState",
    "handlePlayPositionChanged",
    "position",
    "playSliderReleased",
    "playSliderMoved",
    "playSliderPressed",
    "handleMusicSourceChanged",
    "handlePlaybackModeChanged",
    "MusicPlayer::PlaybackMode",
    "mode",
    "handleWorkerParseSongFinished",
    "isFromDatabase",
    "highlightCurrentLyric",
    "handleVoiceChanged",
    "volume",
    "voiceSliderReleased"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {
    uint offsetsAndSizes[62];
    char stringdata0[7];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[25];
    char stringdata5[6];
    char stringdata6[5];
    char stringdata7[31];
    char stringdata8[19];
    char stringdata9[15];
    char stringdata10[21];
    char stringdata11[22];
    char stringdata12[19];
    char stringdata13[27];
    char stringdata14[28];
    char stringdata15[9];
    char stringdata16[26];
    char stringdata17[9];
    char stringdata18[19];
    char stringdata19[16];
    char stringdata20[18];
    char stringdata21[25];
    char stringdata22[26];
    char stringdata23[26];
    char stringdata24[5];
    char stringdata25[30];
    char stringdata26[15];
    char stringdata27[22];
    char stringdata28[19];
    char stringdata29[7];
    char stringdata30[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWidgetENDCLASS_t qt_meta_stringdata_CLASSWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Widget"
        QT_MOC_LITERAL(7, 13),  // "addSongSignal"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 3),  // "url"
        QT_MOC_LITERAL(26, 24),  // "saveSongToDatabaseSignal"
        QT_MOC_LITERAL(51, 5),  // "Song*"
        QT_MOC_LITERAL(57, 4),  // "song"
        QT_MOC_LITERAL(62, 30),  // "loadSongListFromDatabaseSignal"
        QT_MOC_LITERAL(93, 18),  // "addMusicBtnClicked"
        QT_MOC_LITERAL(112, 14),  // "playBtnClicked"
        QT_MOC_LITERAL(127, 20),  // "leftSwitchBtnClicked"
        QT_MOC_LITERAL(148, 21),  // "rightSwitchBtnClicked"
        QT_MOC_LITERAL(170, 18),  // "playModeBtnClicked"
        QT_MOC_LITERAL(189, 26),  // "handlePlayBackStateChanged"
        QT_MOC_LITERAL(216, 27),  // "QMediaPlayer::PlaybackState"
        QT_MOC_LITERAL(244, 8),  // "newState"
        QT_MOC_LITERAL(253, 25),  // "handlePlayPositionChanged"
        QT_MOC_LITERAL(279, 8),  // "position"
        QT_MOC_LITERAL(288, 18),  // "playSliderReleased"
        QT_MOC_LITERAL(307, 15),  // "playSliderMoved"
        QT_MOC_LITERAL(323, 17),  // "playSliderPressed"
        QT_MOC_LITERAL(341, 24),  // "handleMusicSourceChanged"
        QT_MOC_LITERAL(366, 25),  // "handlePlaybackModeChanged"
        QT_MOC_LITERAL(392, 25),  // "MusicPlayer::PlaybackMode"
        QT_MOC_LITERAL(418, 4),  // "mode"
        QT_MOC_LITERAL(423, 29),  // "handleWorkerParseSongFinished"
        QT_MOC_LITERAL(453, 14),  // "isFromDatabase"
        QT_MOC_LITERAL(468, 21),  // "highlightCurrentLyric"
        QT_MOC_LITERAL(490, 18),  // "handleVoiceChanged"
        QT_MOC_LITERAL(509, 6),  // "volume"
        QT_MOC_LITERAL(516, 19)   // "voiceSliderReleased"
    },
    "Widget",
    "addSongSignal",
    "",
    "url",
    "saveSongToDatabaseSignal",
    "Song*",
    "song",
    "loadSongListFromDatabaseSignal",
    "addMusicBtnClicked",
    "playBtnClicked",
    "leftSwitchBtnClicked",
    "rightSwitchBtnClicked",
    "playModeBtnClicked",
    "handlePlayBackStateChanged",
    "QMediaPlayer::PlaybackState",
    "newState",
    "handlePlayPositionChanged",
    "position",
    "playSliderReleased",
    "playSliderMoved",
    "playSliderPressed",
    "handleMusicSourceChanged",
    "handlePlaybackModeChanged",
    "MusicPlayer::PlaybackMode",
    "mode",
    "handleWorkerParseSongFinished",
    "isFromDatabase",
    "highlightCurrentLyric",
    "handleVoiceChanged",
    "volume",
    "voiceSliderReleased"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  134,    2, 0x06,    1 /* Public */,
       4,    1,  137,    2, 0x06,    3 /* Public */,
       7,    0,  140,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  141,    2, 0x08,    6 /* Private */,
       9,    0,  142,    2, 0x08,    7 /* Private */,
      10,    0,  143,    2, 0x08,    8 /* Private */,
      11,    0,  144,    2, 0x08,    9 /* Private */,
      12,    0,  145,    2, 0x08,   10 /* Private */,
      13,    1,  146,    2, 0x08,   11 /* Private */,
      16,    1,  149,    2, 0x08,   13 /* Private */,
      18,    0,  152,    2, 0x08,   15 /* Private */,
      19,    0,  153,    2, 0x08,   16 /* Private */,
      20,    0,  154,    2, 0x08,   17 /* Private */,
      21,    0,  155,    2, 0x08,   18 /* Private */,
      22,    1,  156,    2, 0x08,   19 /* Private */,
      25,    1,  159,    2, 0x08,   21 /* Private */,
      25,    0,  162,    2, 0x28,   23 /* Private | MethodCloned */,
      27,    1,  163,    2, 0x08,   24 /* Private */,
      28,    1,  166,    2, 0x08,   26 /* Private */,
      30,    0,  169,    2, 0x08,   28 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QUrl,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::LongLong,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   17,
    QMetaType::Void, QMetaType::Float,   29,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget, std::true_type>,
        // method 'addSongSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        // method 'saveSongToDatabaseSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Song *, std::false_type>,
        // method 'loadSongListFromDatabaseSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addMusicBtnClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playBtnClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'leftSwitchBtnClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rightSwitchBtnClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playModeBtnClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePlayBackStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::PlaybackState, std::false_type>,
        // method 'handlePlayPositionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'playSliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playSliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playSliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleMusicSourceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePlaybackModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<MusicPlayer::PlaybackMode, std::false_type>,
        // method 'handleWorkerParseSongFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'handleWorkerParseSongFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'highlightCurrentLyric'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'handleVoiceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'voiceSliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addSongSignal((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 1: _t->saveSongToDatabaseSignal((*reinterpret_cast< std::add_pointer_t<Song*>>(_a[1]))); break;
        case 2: _t->loadSongListFromDatabaseSignal(); break;
        case 3: _t->addMusicBtnClicked(); break;
        case 4: _t->playBtnClicked(); break;
        case 5: _t->leftSwitchBtnClicked(); break;
        case 6: _t->rightSwitchBtnClicked(); break;
        case 7: _t->playModeBtnClicked(); break;
        case 8: _t->handlePlayBackStateChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::PlaybackState>>(_a[1]))); break;
        case 9: _t->handlePlayPositionChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 10: _t->playSliderReleased(); break;
        case 11: _t->playSliderMoved(); break;
        case 12: _t->playSliderPressed(); break;
        case 13: _t->handleMusicSourceChanged(); break;
        case 14: _t->handlePlaybackModeChanged((*reinterpret_cast< std::add_pointer_t<MusicPlayer::PlaybackMode>>(_a[1]))); break;
        case 15: _t->handleWorkerParseSongFinished((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->handleWorkerParseSongFinished(); break;
        case 17: _t->highlightCurrentLyric((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 18: _t->handleVoiceChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 19: _t->voiceSliderReleased(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(const QUrl & );
            if (_t _q_method = &Widget::addSongSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget::*)(Song * );
            if (_t _q_method = &Widget::saveSongToDatabaseSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Widget::*)();
            if (_t _q_method = &Widget::loadSongListFromDatabaseSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void Widget::addSongSignal(const QUrl & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::saveSongToDatabaseSignal(Song * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Widget::loadSongListFromDatabaseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
