#include "../header/song.hpp"

Song::Song() {}

Song::~Song() {}

Song::Song(const QUrl &url, const QString &name, const QString &author,
           const QString &album)
    : m_url(url), m_name(name), m_author(author), m_album(album) {}

// 获取url
const QUrl &Song::getUrl() const { return m_url; }

QUrl Song::getUrl() { return m_url; }

// 获取歌名
const QString &Song::getName() const { return m_name; }

// 获取作者
const QString &Song::getAuthor() const { return m_author; }

// 获取专辑名
const QString &Song::getAlbum() const { return m_album; }

// 获取歌词map
const QMap<qint64, QString> &Song::getLyrics() const { return m_lyrics; }

// 设置url
void Song::setUrl(const QUrl &url) { m_url = url; }

// 设置歌名
void Song::setName(const QString &name) { m_name = name; }

// 设置作者
void Song::setAuthor(const QString &author) { m_author = author; }

// 设置专辑名
void Song::setAlbum(const QString &album) { m_album = album; }

// 设置歌词map
void Song::setLyrics(const QMap<qint64, QString> &lyrics) { m_lyrics = lyrics; }

// 重写输出<<
QDebug &operator<<(QDebug &debug, const Song &song) {
  debug << "{ "
        << "Name: " << song.m_name << " Author: " << song.m_author
        << " Album: " << song.m_album
        << " Lyrics Lines: " << song.m_lyrics.size() << " }";
  return debug;
}
