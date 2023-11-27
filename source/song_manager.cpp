#include "../header/song_manager.hpp"

SongManager::~SongManager() { clearSongMap(); }

// 实例化对象
SongManager *SongManager::getInstance() {
  static SongManager songManager;
  return &songManager;
}

// 返回歌曲对象列表的接口
QMap<QUrl, Song *> &SongManager::getSongMap() { return m_songMap; }

// 歌曲对象接口大小
int SongManager::getSongMapSize() const { return m_songMap.size(); }

// 清空歌曲对象接口
void SongManager::clearSongMap() {
  for (auto song : m_songMap) {
    delete song;
  }
}

// 是否包含某首歌的接口
bool SongManager::isContains(const QUrl &url) {
  return m_songMap.contains(url);
}

// 根据url返回某首歌的接口
Song *SongManager::getSong(const QUrl &url) { return m_songMap[url]; }

// 添加歌曲接口
void SongManager::addSong(Song *song) {
  if (song) {
    m_songMap.insert(song->getUrl(), song);
  }
}
