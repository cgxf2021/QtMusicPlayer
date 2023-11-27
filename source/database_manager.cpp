#include "../header/database_manager.hpp"

#include <QSqlQuery>
#include <QString>

DatabaseManager::DatabaseManager() { initialize(); }

DatabaseManager::~DatabaseManager() {
  close();
  QSqlDatabase::removeDatabase(m_connection.connectionName());
}

DatabaseManager *DatabaseManager::getInstance() {
  static DatabaseManager databaseManager;
  return &databaseManager;
}

// 初始化
bool DatabaseManager::initialize() {
  QString databaseType = "QSQLITE";
  QString connectionName = "player_connection";
  QString databaseName = "music.db";
  m_connection = QSqlDatabase::addDatabase(databaseType, connectionName);
  m_tableName = "song";
  if (!m_connection.isValid()) {
    LOG << "connection is not valid";
    return false;
  }
  m_connection.setDatabaseName(databaseName);
  if (!open()) {
    LOG << "connection is not open";
    return false;
  }
  return createTable();
}

// 建表
bool DatabaseManager::createTable() {
  if (!m_connection.isOpen()) {
    return false;
  }
  QString sql = "CREATE TABLE IF NOT EXISTS " + m_tableName +
                "\n(\n"
                "  id INTEGER PRIMARY KEY AUTOINCREMENT,\n"
                "  url TEXT UNIQUE NOT NULL,\n"
                "  name TEXT,\n"
                "  author TEXT,\n"
                "  album TEXT\n"
                ");";
  QSqlQuery query(m_connection);
  return query.exec(sql);
}

// 打开数据库
bool DatabaseManager::open() {
  m_connection.open();
  return m_connection.isOpen();
}

// 关闭数据库
void DatabaseManager::close() { m_connection.close(); }

// 插入
bool DatabaseManager::insertSong(const Song &song) {
  if (!m_connection.isOpen()) {
    return false;
  }
  QString sql = "INSERT INTO " + m_tableName +
                "(url, name, author, album)\n"
                "VALUES('" +
                song.getUrl().toString() + "', '" + song.getName() + "', '" +
                song.getAuthor() + "', '" + song.getAlbum() + "');";
  QSqlQuery query(m_connection);
  return query.exec(sql);
}

// 搜索表中所有歌曲
bool DatabaseManager::selectSongs(QList<Song *> &songList) {
  if (!m_connection.isOpen()) {
    return false;
  }
  QString sql = "SELECT * FROM " + m_tableName + ";";
  QSqlQuery query(m_connection);
  bool ret = query.exec(sql);
  if (!ret) {
    return false;
  }
  while (query.next()) {
    Song *song = new Song(
        QUrl(query.value("url").toString()), query.value("name").toString(),
        query.value("author").toString(), query.value("album").toString());
    songList.push_back(song);
  }
  return true;
}
