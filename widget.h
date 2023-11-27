#ifndef WIDGET_H
#define WIDGET_H

#include <QAudioOutput>
#include <QMediaCaptureSession>
#include <QMediaPlayer>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QThread>
#include <QWheelEvent>
#include <QWidget>

#include "./header/message_queue.hpp"
#include "./header/music_player.hpp"
#include "./header/set_style.hpp"
#include "./header/song_manager.hpp"

// 输出调用处的函数名
#define LOG (qDebug() << "[" << __PRETTY_FUNCTION__ << "] ")

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  ~Widget();
  // 测试
  void test();

 signals:
  // 添加歌曲的信号
  void addSongSignal(const QUrl &url);
  // 添加歌曲到数据库信号
  void saveSongToDatabaseSignal(Song *song);
  // 从数据库中加载歌曲列表
  void loadSongListFromDatabaseSignal();

 protected:
  // 窗口拖动时记录的起始点
  QPoint m_offset;
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;

 private:
  Ui::Widget *ui;
  // 样式设置
  StyleSet *m_widgetStyle;
  // 媒体播放器
  MusicPlayer *m_musicPlayer;
  // 歌曲管理者对象
  SongManager *m_songManager;
  // 消息队列对象
  MessageQueue *m_messageQueue;
  // 子线程
  QThread *m_thread;

  // 初始化界面组件
  void initializeWidget();
  // 初始化多媒体
  void initializeMedia();
  // 初始化工作对象
  void initializeWorker();
  // 显示歌词
  void showLyrics();

 private slots:
  // 添加歌曲
  void addMusicBtnClicked();
  // 播放歌曲
  void playBtnClicked();
  // 上一首
  void leftSwitchBtnClicked();
  // 下一首
  void rightSwitchBtnClicked();
  // 歌曲模式
  void playModeBtnClicked();
  // 处理播放状态改变
  void handlePlayBackStateChanged(QMediaPlayer::PlaybackState newState);
  // 播放进度改变滑动条
  void handlePlayPositionChanged(qint64 position);
  // 释放滑动条改变播放进度
  void playSliderReleased();
  // 移动滑动条
  void playSliderMoved();
  // 点击滑动条
  void playSliderPressed();
  // 处理音乐源改变
  void handleMusicSourceChanged();
  // 处理模式改变
  void handlePlaybackModeChanged(MusicPlayer::PlaybackMode mode);
  // 处理工作对象解析结束
  void handleWorkerParseSongFinished(bool isFromDatabase = false);
  // 高亮当前歌词
  void highlightCurrentLyric(qint64 position);
  // 处理音量变化
  void handleVoiceChanged(float volume);
  // 音量条改变音量
  void voiceSliderReleased();
};

#endif  // WIDGET_H
