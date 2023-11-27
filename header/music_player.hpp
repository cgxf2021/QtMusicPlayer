#ifndef MUSIC_PLAYER_HPP_
#define MUSIC_PLAYER_HPP_

#include <QAudioOutput>
#include <QList>
#include <QMediaPlayer>
#include <QUrl>

// 输出调用处的函数名
#define LOG (qDebug() << "[" << __PRETTY_FUNCTION__ << "] ")

class MusicPlayer : public QObject {
  Q_OBJECT

 public:
  // 获取实例
  static MusicPlayer *getInstance();
  // 获取当前播放位置
  static int getCurrentPos();
  // 播放模式(单曲循环/列表循环/随机播放)
  enum PlaybackMode { ListLoop, RandomPlay, SingleLoop };
  // 初始化播放资源
  void initializeSource();
  // 设置播放列表URL
  void setSongUrlList(const QStringList &songUrlList);
  // 添加播放列表URL
  void addSongUrl(const QUrl &url);
  // 设置播放模式
  void setPlaybackMode(MusicPlayer::PlaybackMode mode);
  // 获取媒体播放器
  QMediaPlayer *getMediaPlayer() const;
  // 获取播放模式
  MusicPlayer::PlaybackMode getPlaybackMode() const;
  // 切换上一首
  void leftSwitchSource();
  // 切换下一首
  void rightSwitchSource();

 signals:
  void songSourceChangedSignal();
  void playbackModeChanged(MusicPlayer::PlaybackMode mode);

 private:
  MusicPlayer(QObject *parent = nullptr);
  MusicPlayer(const MusicPlayer &) = delete;
  MusicPlayer &operator=(const MusicPlayer &) = delete;
  ~MusicPlayer();
  // 当前播放源位置
  static int m_currentListPos;
  // 播放器
  QMediaPlayer *m_mediaPlayer;
  // 音频
  QAudioOutput *m_audioOutput;
  // 播放模式
  MusicPlayer::PlaybackMode m_mode;
  // 播放列表
  QList<QUrl> m_songUrlList;

 private slots:
  // 播放状态改变后进行的操作
  void mediaPlayerSourceChanged(QMediaPlayer::MediaStatus status);
};

#endif  // !MUSIC_PLAYER_HPP_
