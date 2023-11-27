#ifndef DATABASE_MANAGER_HPP_
#define DATABASE_MANAGER_HPP_

#include <QList>
#include <QSqlDatabase>

#include "song.hpp"

// 输出调用处的函数名
#define LOG (qDebug() << "[" << __PRETTY_FUNCTION__ << "] ")

class DatabaseManager {
 private:
  DatabaseManager();
  ~DatabaseManager();
  DatabaseManager(const DatabaseManager &) = delete;
  DatabaseManager &operator=(const DatabaseManager &) = delete;
  // 数据库连接对象
  QSqlDatabase m_connection;
  // 表名
  QString m_tableName;
  // 初始化
  bool initialize();
  // 建表
  bool createTable();

 public:
  static DatabaseManager *getInstance();
  // 打开数据库
  bool open();
  // 关闭数据库
  void close();
  // 插入歌曲
  bool insertSong(const Song &song);
  // 搜索表中所有歌曲
  bool selectSongs(QList<Song *> &songList);
};

#endif  // !DATABASE_MANAGER_HPP_
