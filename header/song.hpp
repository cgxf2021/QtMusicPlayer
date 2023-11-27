#ifndef SONG_HPP_
#define SONG_HPP_

#include <QDebug>
#include <QMap>
#include <QString>
#include <QUrl>

class Song {
 public:
  Song();
  ~Song();
  Song(const QUrl &url, const QString &name, const QString &author,
       const QString &album);
  // 获取url
  const QUrl &getUrl() const;
  QUrl getUrl();
  // 获取歌名
  const QString &getName() const;
  // 获取作者
  const QString &getAuthor() const;
  // 获取专辑名
  const QString &getAlbum() const;
  // 获取歌词map
  const QMap<qint64, QString> &getLyrics() const;
  // 设置url
  void setUrl(const QUrl &url);
  // 设置歌名
  void setName(const QString &name);
  // 设置作者
  void setAuthor(const QString &author);
  // 设置专辑名
  void setAlbum(const QString &album);
  // 设置歌词map
  void setLyrics(const QMap<qint64, QString> &lyrics);
  // 重写输出<<
  friend QDebug &operator<<(QDebug &debug, const Song &song);

 private:
  QUrl m_url;
  QString m_name;
  QString m_author;
  QString m_album;
  QMap<qint64, QString> m_lyrics;
};

#endif  // !SONG_HPP_
