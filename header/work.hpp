#ifndef WORK_HPP_
#define WORK_HPP_

#include <QObject>

#include "song.hpp"

// 输出调用处的函数名
#define LOG (qDebug() << "[" << __PRETTY_FUNCTION__ << "] ")

class Worker : public QObject {
  Q_OBJECT
 public:
  explicit Worker(QObject *parent = nullptr);
  ~Worker();
 public slots:
  // 解析歌曲
  void parseSong(const QUrl &url);
  // 解析歌词
  void parseLyrics(Song *song);
  // 保存歌曲数据库
  void saveSongToDatabase(Song *song);
  // 从数据库读取歌曲
  void loadSongFromDatabase();
 signals:
  // 解析完成信号
  void parseFinished(bool isFromDatabase = false);
};

#endif  // !WORK_HPP_
