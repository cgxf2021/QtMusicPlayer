#include "../header/work.hpp"

#include <QFile>
#include <QFileInfo>
#include <QMap>
#include <QRegularExpression>
#include <QTextStream>

#include "../header/database_manager.hpp"
#include "../header/message_queue.hpp"

Worker::Worker(QObject *parent) : QObject(parent) {}

Worker::~Worker() {}

// 解析歌曲
void Worker::parseSong(const QUrl &url) {
  QFileInfo songInfo = QFileInfo(url.toString());
  if (!songInfo.isFile()) {
    return;
  }
  QString songTitle = songInfo.baseName();
  QStringList songInfoList = songTitle.split('-');
  // 创建歌曲对象
  Song *song = new Song(url, "", "", "");
  // 设置歌名/歌手/专辑
  switch (songInfoList.size()) {
    case 1:
      song->setName(songInfoList.at(0));
      break;
    case 2:
      song->setName(songInfoList.at(0));
      song->setAuthor(songInfoList.at(1));
      break;
    default:
      song->setName(songInfoList.at(0));
      song->setAuthor(songInfoList.at(1));
      song->setAlbum(songInfoList.at(2));
  }
  // 解析歌词并设置歌词
  parseLyrics(song);
  // 入队
  MessageQueue::getInstance()->push(song);
  emit parseFinished();
}

// 解析歌词
void Worker::parseLyrics(Song *song) {
  // 歌曲不存在
  if (!song || song->getUrl().isEmpty()) {
    return;
  }
  QString lyricsUrlString = song->getUrl().toString().replace(
      QRegularExpression("\\.(mp3|m4a)"), ".lrc");
  // LOG << lyricsUrlString;
  // 判断歌词文件是否存在
  if (!QFileInfo(lyricsUrlString).isFile()) {
    return;
  }
  // 打开歌词文件
  QFile lyricsFile(lyricsUrlString);
  if (!lyricsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return;
  }
  // 按行读取
  QTextStream textStream(&lyricsFile);
  QRegularExpression pattern("\\[(\\d+):(\\d+(?:\\.\\d+)?)\\](.*)");
  QMap<qint64, QString> lyrics;
  while (!textStream.atEnd()) {
    QString line = textStream.readLine();
    QRegularExpressionMatch match = pattern.match(line);
    // LOG << match.captured(1);
    // LOG << match.captured(2);
    // LOG << match.captured(3);
    // 说明不是时间+歌词
    if (match.captured(1).isEmpty()) {
      continue;
    }
    int minutes = match.captured(1).toInt();
    double seconds = match.captured(2).toFloat();
    QString content = match.captured(3);
    lyrics.insert((minutes * 60 + seconds) * 1000, content);
  }
  // 关闭文件
  lyricsFile.close();
  // 设置歌词
  song->setLyrics(lyrics);
}

// 保存歌曲数据库
void Worker::saveSongToDatabase(Song *song) {
  if (song) {
    DatabaseManager::getInstance()->insertSong(*song);
  }
}

// 从数据库读取歌曲
void Worker::loadSongFromDatabase() {
  QList<Song *> songList;
  bool ret = DatabaseManager::getInstance()->selectSongs(songList);
  if (ret) {
    // 将歌曲添加到消息队列
    for (auto song : songList) {
      // 解析歌词并设置歌词
      parseLyrics(song);
      // 入队
      MessageQueue::getInstance()->push(song);
    }
    emit parseFinished(true);
  }
}
