#ifndef SONG_MANAGER_HPP_
#define SONG_MANAGER_HPP_

#include "song.hpp"

class SongManager {
 private:
  SongManager() = default;
  ~SongManager();
  SongManager(const SongManager &) = delete;
  SongManager &operator=(const SongManager &) = delete;
  // 歌曲接口
  QMap<QUrl, Song *> m_songMap;

 public:
  static SongManager *getInstance();
  // 返回歌曲对象列表的接口
  QMap<QUrl, Song *> &getSongMap();
  // 歌曲对象接口大小
  int getSongMapSize() const;
  // 清空歌曲对象接口
  void clearSongMap();
  // 是否包含某首歌的接口
  bool isContains(const QUrl &url);
  // 根据url返回某首歌的接口
  Song *getSong(const QUrl &url);
  // 添加歌曲接口
  void addSong(Song *song);
};

#endif  // !SONG_MANAGER_HPP_
