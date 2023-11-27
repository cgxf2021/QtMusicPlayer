#include "../header/music_player.hpp"

// 初始化静态变量
int MusicPlayer::m_currentListPos = 0;

MusicPlayer::MusicPlayer(QObject *parent) : QObject(parent) {
  // 设置播放器
  m_mediaPlayer = new QMediaPlayer(this);
  // 创建音频
  m_audioOutput = new QAudioOutput();
  // 设置音频输出
  m_mediaPlayer->setAudioOutput(m_audioOutput);
  // 设置音量
  m_mediaPlayer->audioOutput()->setVolume(0.5);
  // 设置播放模式
  m_mode = PlaybackMode::ListLoop;

  /* =====  connect  ===== */

  // 媒体播放器 --> mediaPlayerStateChanged
  QObject::connect(m_mediaPlayer, &QMediaPlayer::mediaStatusChanged, this,
                   &MusicPlayer::mediaPlayerSourceChanged);
}

MusicPlayer::~MusicPlayer() { delete m_mediaPlayer; }

// 获取实例
MusicPlayer *MusicPlayer::getInstance() {
  static MusicPlayer musicPlayer;
  return &musicPlayer;
}

// 获取当前播放位置
int MusicPlayer::getCurrentPos() { return m_currentListPos; }

// 为播放器初始化源
void MusicPlayer::initializeSource() {
  if (!m_songUrlList.isEmpty()) {
    m_mediaPlayer->setSource(m_songUrlList.first());
    emit songSourceChangedSignal();
  }
}

// 设置播放列表URL
void MusicPlayer::setSongUrlList(const QStringList &songUrlList) {
  for (auto songUrl : songUrlList) {
    m_songUrlList.push_back(QUrl(songUrl));
  }
}

// 添加播放列表URL
void MusicPlayer::addSongUrl(const QUrl &url) { m_songUrlList.push_back(url); }

// 播放模式(单曲循环/列表循环/随机播放)
void MusicPlayer::setPlaybackMode(MusicPlayer::PlaybackMode mode) {
  m_mode = mode;
  emit playbackModeChanged(m_mode);
}

// 获取媒体播放器
QMediaPlayer *MusicPlayer::getMediaPlayer() const { return m_mediaPlayer; }

// 获取播放模式
MusicPlayer::PlaybackMode MusicPlayer::getPlaybackMode() const {
  return m_mode;
}

// 切换上一首
void MusicPlayer::leftSwitchSource() {
  if (!m_songUrlList.empty()) {
    m_mediaPlayer->pause();
    m_currentListPos = (m_currentListPos - 1) % m_songUrlList.size();
    if (m_currentListPos < 0) {
      m_currentListPos += m_songUrlList.size();
    }
    m_mediaPlayer->setSource(m_songUrlList.at(m_currentListPos));
    emit songSourceChangedSignal();
    m_mediaPlayer->play();
  }
}

// 切换下一首
void MusicPlayer::rightSwitchSource() {
  if (!m_songUrlList.empty()) {
    m_mediaPlayer->pause();
    m_currentListPos = (m_currentListPos + 1) % m_songUrlList.size();
    m_mediaPlayer->setSource(m_songUrlList.at(m_currentListPos));
    emit songSourceChangedSignal();
    m_mediaPlayer->play();
  }
}

/* =====  private =====  */

/* =====  private slots  ===== */

// 播放状态改变后进行的操作
void MusicPlayer::mediaPlayerSourceChanged(QMediaPlayer::MediaStatus status) {
  if (status == QMediaPlayer::MediaStatus::EndOfMedia &&
      !m_songUrlList.isEmpty()) {
    switch (m_mode) {
      case PlaybackMode::ListLoop:
        m_currentListPos = (m_currentListPos + 1) % m_songUrlList.size();
        m_mediaPlayer->setSource(m_songUrlList.at(m_currentListPos));
        // LOG << m_mediaPlayer->mediaStatus();
        break;
      case PlaybackMode::RandomPlay:
        break;
      case PlaybackMode::SingleLoop:
        // LOG << "SingleLoop";
        break;
    }
    emit songSourceChangedSignal();
    m_mediaPlayer->play();
  }
}
