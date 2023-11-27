#include "widget.h"

#include <QDebug>
#include <QFileDialog>
#include <QIcon>
#include <QPainter>
#include <QPainterPath>
#include <QPalette>
#include <QPixmap>
#include <QStyleOption>
#include <iterator>

#include "./header/song.hpp"
#include "./header/work.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  // 初始化界面样式
  initializeWidget();
  // 初始化媒体播放器
  initializeMedia();
  // 初始化工作类对象
  initializeWorker();
  // 发送恢复歌曲列表函数
  emit loadSongListFromDatabaseSignal();

  /* =====  connect ===== */

  // close button
  QObject::connect(ui->closeBtn, &QPushButton::clicked, this,
                   [this]() -> void { this->close(); });
  // minimize button
  QObject::connect(ui->minimizeBtn, &QPushButton::clicked, this,
                   [this]() -> void { this->showMinimized(); });
  // voice button
  QObject::connect(ui->voiceBtn, &QPushButton::clicked, this, [this]() -> void {
    if (ui->voiceSlider->isHidden()) {
      ui->voiceSlider->show();
    } else {
      ui->voiceSlider->hide();
    }
  });
  // 点击添加按钮 --> addMusicBtnClicked
  QObject::connect(ui->addMusicBtn, &QPushButton::clicked, this,
                   &Widget::addMusicBtnClicked);
  // 点击播放按钮 --> playBtnClicked
  QObject::connect(ui->playBtn, &QPushButton::clicked, this,
                   &Widget::playBtnClicked);
  // 点击上一首按钮 --> leftSwitchBtnClicked
  QObject::connect(ui->leftSwitchBtn, &QPushButton::clicked, this,
                   &Widget::leftSwitchBtnClicked);
  // 点击下一首按钮 --> rightSwitchBtnClicked
  QObject::connect(ui->rightSwitchBtn, &QPushButton::clicked, this,
                   &Widget::rightSwitchBtnClicked);
  // 媒体播放状态变化 --> 播放按钮状态变化
  QObject::connect(m_musicPlayer->getMediaPlayer(),
                   &QMediaPlayer::playbackStateChanged, this,
                   &Widget::handlePlayBackStateChanged);
  // 媒体播放器换源 --> 播放器界面变化
  QObject::connect(m_musicPlayer, &MusicPlayer::songSourceChangedSignal, this,
                   &Widget::handleMusicSourceChanged);
  // 点击播放模式按钮 --> playModeBtnClicked
  QObject::connect(ui->playModeBtn, &QPushButton::clicked, this,
                   &Widget::playModeBtnClicked);
  // 修改播放模式 --> 修改播放模式图标
  QObject::connect(m_musicPlayer, &MusicPlayer::playbackModeChanged, this,
                   &Widget::handlePlaybackModeChanged);
  // 媒体播放进度变化 --> 播放滑动条和时间标签变化
  QObject::connect(m_musicPlayer->getMediaPlayer(),
                   &QMediaPlayer::positionChanged, this,
                   &Widget::handlePlayPositionChanged);
  // 媒体播放进度变化 --> 歌词滚动变化
  QObject::connect(m_musicPlayer->getMediaPlayer(),
                   &QMediaPlayer::positionChanged, this,
                   &Widget::highlightCurrentLyric);
  // 播放滑动条释放 --> 媒体播放进度变化
  QObject::connect(ui->playSlider, &QSlider::sliderReleased, this,
                   &Widget::playSliderReleased);
  QObject::connect(ui->playSlider, &QSlider::sliderMoved, this,
                   &Widget::playSliderMoved);
  QObject::connect(ui->playSlider, &QSlider::sliderPressed, this,
                   &Widget::playSliderPressed);
  // 音量改变 --> 音量条改变
  QObject::connect(m_musicPlayer->getMediaPlayer()->audioOutput(),
                   &QAudioOutput::volumeChanged, this,
                   &Widget::handleVoiceChanged);
  // 音量条改变 --> 音量改变
  QObject::connect(ui->voiceSlider, &QSlider::sliderReleased, this,
                   &Widget::voiceSliderReleased);
  // 主界面销毁 --> 线程释放资源
  QObject::connect(this, &Widget::destroyed, m_thread, [this]() -> void {
    m_thread->quit();
    m_thread->wait();
    m_thread->deleteLater();
  });
}

Widget::~Widget() { delete ui; }

/* =====  测试  ===== */

/* =====  初始化  ===== */

// 初始化界面组件
void Widget::initializeWidget() {
  // 设置widget
  this->setFixedSize(1200, 800);
  // 设置无边框
  this->setWindowFlags(Qt::FramelessWindowHint);
  // 设置透明
  this->setAttribute(Qt::WA_TranslucentBackground);
  // 样式设置对象
  m_widgetStyle = new StyleSet();
  // 设置按钮样式
  m_widgetStyle->setPushButton(ui->addMusicBtn, "添加",
                               ":/icon/images/toolIcon/addMusic_red.png", 50,
                               50);
  m_widgetStyle->setPushButton(ui->leftSwitchBtn, "上一首",
                               ":/icon/images/toolIcon/left_music_2.png", 50,
                               50);
  m_widgetStyle->setPushButton(ui->playBtn, "播放",
                               ":/icon/images/toolIcon/play.png", 50, 50);
  m_widgetStyle->setPushButton(ui->rightSwitchBtn, "下一首",
                               ":/icon/images/toolIcon/right_music_2.png", 50,
                               50);
  m_widgetStyle->setPushButton(ui->playModeBtn, "列表循环",
                               ":/icon/images/toolIcon/listCycle.png", 50, 50);
  m_widgetStyle->setPushButton(ui->voiceBtn, "音量",
                               ":/icon/images/toolIcon/voice_2.png", 60, 60);
  m_widgetStyle->setPushButton(ui->closeBtn, "关闭",
                               ":/icon/images/toolIcon/close.png", 30, 30);
  m_widgetStyle->setPushButton(ui->minimizeBtn, "最小化",
                               ":/icon/images/toolIcon/minimize.png", 30, 30);
  m_widgetStyle->setPushButton(ui->titleImageBtn, "关于",
                               ":/icon/images/toolIcon/logo.png", 170, 50);
  // 设置列表样式
  m_widgetStyle->setListWidget(ui->playList);
  m_widgetStyle->setListWidget(ui->lyricsList, 40);
  // 设置标签样式
  m_widgetStyle->setLabel(ui->titleLabel, 18, false, false, Qt::white,
                          "Dolphin|Music");
  m_widgetStyle->setLabel(ui->timeLabel, 12, false, false, Qt::white,
                          "00:00/00:00");
  m_widgetStyle->setLabel(ui->songNameLabel, 14, false, true, Qt::white,
                          "Name of the Song");
  // 设置左下角图片
  m_widgetStyle->setLabel(ui->musicImageLabel);
  QPixmap musicImage = QPixmap(":/background/images/background/music_bg.jpg");
  musicImage = m_widgetStyle->setRoundRectImage(
      musicImage, ui->musicImageLabel->size(), 10);
  ui->musicImageLabel->setPixmap(musicImage);
  // 设置滑块样式
  m_widgetStyle->setSlider(ui->playSlider);
  m_widgetStyle->setSlider(ui->voiceSlider, false);
  // 音量滑块不显示
  ui->voiceSlider->hide();
  ui->voiceSlider->setValue(50);
  // 设置鼠标悬浮在按钮的样式
  ui->addMusicBtn->setCursor(Qt::PointingHandCursor);
  ui->leftSwitchBtn->setCursor(Qt::PointingHandCursor);
  ui->playBtn->setCursor(Qt::PointingHandCursor);
  ui->rightSwitchBtn->setCursor(Qt::PointingHandCursor);
  ui->playModeBtn->setCursor(Qt::PointingHandCursor);
  ui->voiceBtn->setCursor(Qt::PointingHandCursor);
  ui->titleImageBtn->setCursor(Qt::PointingHandCursor);
  // 释放
  delete m_widgetStyle;
}

// 初始化多媒体
void Widget::initializeMedia() {
  // 初始化媒体
  m_musicPlayer = MusicPlayer::getInstance();
  // 初始化歌曲管理
  m_songManager = SongManager::getInstance();
}

// 初始化工作对象
void Widget::initializeWorker() {
  // 初始化消息队列
  m_messageQueue = MessageQueue::getInstance();
  // 初始化子线程
  m_thread = new QThread(this);
  // 创建工作对象
  Worker *worker = new Worker();
  // 将工作类对象移动到子线程
  worker->moveToThread(m_thread);
  // 启动子线程
  m_thread->start();
  // 发出添加歌曲信号 --> 工作类对象开始解析歌曲
  QObject::connect(this, &Widget::addSongSignal, worker, &Worker::parseSong);
  // 工作类对象解析完成 --> 处理解析完成的信号
  QObject::connect(worker, &Worker::parseFinished, this,
                   &Widget::handleWorkerParseSongFinished);
  // 主线程保存歌曲到数据库 --> 处理歌曲保存数据库
  QObject::connect(this, &Widget::saveSongToDatabaseSignal, worker,
                   &Worker::saveSongToDatabase);
  // 主线程从数据库加载歌曲 --> 处理歌曲从数据库查询返回
  QObject::connect(this, &Widget::loadSongListFromDatabaseSignal, worker,
                   &Worker::loadSongFromDatabase);
  // 线程结束 --> 释放线程中资源
  QObject::connect(m_thread, &QThread::finished, m_thread,
                   &QThread::deleteLater);
}

// 显示歌词
void Widget::showLyrics() {
  Song *currentSong =
      m_songManager->getSong(m_musicPlayer->getMediaPlayer()->source());
  ui->lyricsList->clear();
  if (currentSong->getLyrics().isEmpty()) {
    QListWidgetItem *item = new QListWidgetItem("歌词不存在");
    item->setTextAlignment(Qt::AlignCenter);
    item->setFont(QFont("AR PL UKai CN", 18));
    ui->lyricsList->addItem(item);
  }
  QMap<qint64, QString> lyrics = currentSong->getLyrics();
  for (auto line : lyrics) {
    QListWidgetItem *item = new QListWidgetItem(line);
    item->setTextAlignment(Qt::AlignCenter);
    item->setFont(QFont("AR PL UKai CN", 18));
    ui->lyricsList->addItem(item);
  }
}

/* =====  槽函数  ===== */

// 添加歌曲
void Widget::addMusicBtnClicked() {
  QStringList songStringList = QFileDialog::getOpenFileNames(
      this, "Add Music", QDir::currentPath(), "Music File (*.m4a *.mp3)");
  for (auto songString : songStringList) {
    // m_musicPlayer->addSongUrl(QUrl(songString));
    emit addSongSignal(QUrl(songString));
  }
}

// 播放歌曲
void Widget::playBtnClicked() {
  if (m_musicPlayer->getMediaPlayer()->playbackState() ==
      QMediaPlayer::PlaybackState::PlayingState) {
    m_musicPlayer->getMediaPlayer()->pause();
  } else {
    m_musicPlayer->getMediaPlayer()->play();
  }
}

// 上一首
void Widget::leftSwitchBtnClicked() { m_musicPlayer->leftSwitchSource(); }

// 下一首
void Widget::rightSwitchBtnClicked() { m_musicPlayer->rightSwitchSource(); }

// 歌曲模式
void Widget::playModeBtnClicked() {
  MusicPlayer::PlaybackMode mode = m_musicPlayer->getPlaybackMode();
  MusicPlayer::PlaybackMode newMode =
      (MusicPlayer::PlaybackMode)((mode + 1) % 3);
  m_musicPlayer->setPlaybackMode(newMode);
}

// 处理播放状态改变
void Widget::handlePlayBackStateChanged(QMediaPlayer::PlaybackState newState) {
  if (newState == QMediaPlayer::PlaybackState::PlayingState) {
    ui->playBtn->setIcon(QIcon(":/icon/images/toolIcon/pause.png"));
    ui->playBtn->setToolTip("暂停");
  } else {
    ui->playBtn->setIcon(QIcon(":/icon/images/toolIcon/play.png"));
    ui->playBtn->setToolTip("播放");
  }
}

// 处理音乐源改变
void Widget::handleMusicSourceChanged() {
  Song *song =
      m_songManager->getSong(m_musicPlayer->getMediaPlayer()->source());
  // 切换文本
  ui->songNameLabel->setText(song->getName() + '-' + song->getAuthor());
  // 歌曲列表高亮
  ui->playList->setCurrentRow(MusicPlayer::getCurrentPos());
  // 歌词显示
  this->showLyrics();
  // 播放
  // m_musicPlayer->getMediaPlayer()->play();
}

// 处理模式改变
void Widget::handlePlaybackModeChanged(MusicPlayer::PlaybackMode mode) {
  switch (mode) {
    case MusicPlayer::PlaybackMode::ListLoop:
      ui->playModeBtn->setIcon(QIcon(":/icon/images/toolIcon/listCycle.png"));
      ui->playModeBtn->setToolTip("列表循环");
      break;
    case MusicPlayer::PlaybackMode::RandomPlay:
      ui->playModeBtn->setIcon(QIcon(":/icon/images/toolIcon/listRandom.png"));
      ui->playModeBtn->setToolTip("随机播放");
      break;
    case MusicPlayer::PlaybackMode::SingleLoop:
      ui->playModeBtn->setIcon(QIcon(":/icon/images/toolIcon/singleCycle.png"));
      ui->playModeBtn->setToolTip("单曲循环");
      break;
  }
}

// 处理播放进度条改变
void Widget::handlePlayPositionChanged(qint64 position) {
  // 获取当前音乐秒数
  qint64 musicCurrentSeconds = position / 1000;
  // 获取音乐时长
  qint64 musicDurationSeconds =
      m_musicPlayer->getMediaPlayer()->duration() / 1000;
  // 获取进度条最大值
  int maxPlaySliderValue = ui->playSlider->maximum();
  // 设置进度条数值
  ui->playSlider->setValue((int)((double)musicCurrentSeconds /
                                 musicDurationSeconds * maxPlaySliderValue));
  // 设置时间标签
  QString timeLabelText =
      QString("%1:%2/%3:%4")
          .arg(musicCurrentSeconds / 60, 2, 10, QChar('0'))
          .arg(musicCurrentSeconds % 60, 2, 10, QChar('0'))
          .arg(musicDurationSeconds / 60, 2, 10, QChar('0'))
          .arg(musicDurationSeconds % 60, 2, 10, QChar('0'));
  ui->timeLabel->setText(timeLabelText);
}

// 释放滑动条改变播放进度
void Widget::playSliderReleased() {
  int maxPlaySliderValue = ui->playSlider->maximum();
  int currentPlaySliderValue = ui->playSlider->value();
  m_musicPlayer->getMediaPlayer()->setPosition(
      (qint64)((double)currentPlaySliderValue / maxPlaySliderValue *
               m_musicPlayer->getMediaPlayer()->duration()));
  // 重新连接
  QObject::connect(m_musicPlayer->getMediaPlayer(),
                   &QMediaPlayer::positionChanged, this,
                   &Widget::handlePlayPositionChanged);
}

// 移动滑动条
void Widget::playSliderMoved() {
  // 关闭媒体播放进度变化 --> 播放滑动条和时间标签变化
  QObject::disconnect(m_musicPlayer->getMediaPlayer(),
                      &QMediaPlayer::positionChanged, this,
                      &Widget::handlePlayPositionChanged);
}
// 点击滑动条
void Widget::playSliderPressed() {
  // 关闭媒体播放进度变化 --> 播放滑动条和时间标签变化
  QObject::disconnect(m_musicPlayer->getMediaPlayer(),
                      &QMediaPlayer::positionChanged, this,
                      &Widget::handlePlayPositionChanged);
}

// 处理工作对象解析结束
void Widget::handleWorkerParseSongFinished(bool isFromDatabase) {
  LOG << "message size: " << m_messageQueue->size();
  Song *song = nullptr;
  while (!m_messageQueue->isEmpty()) {
    song = m_messageQueue->pop();
    if (song) {
      m_songManager->addSong(song);
      m_musicPlayer->addSongUrl(song->getUrl());
      if (!isFromDatabase) {
        // 发送将song存入数据库
        emit saveSongToDatabaseSignal(song);
      }
      QListWidgetItem *item =
          new QListWidgetItem(song->getName() + '-' + song->getAuthor());
      // 为音乐设置图片
      item->setIcon(QIcon(":/icon/images/toolIcon/music.png"));
      item->setFont(QFont("AR PL UKai CN", 15));
      ui->playList->addItem(item);
    }
  }
  // 如果播放器当前没有歌曲播放
  if (m_musicPlayer->getMediaPlayer()->playbackState() ==
      QMediaPlayer::PlaybackState::StoppedState) {
    m_musicPlayer->initializeSource();
    ui->songNameLabel->setText(
        QFileInfo(m_musicPlayer->getMediaPlayer()->source().toString())
            .baseName());
  }
}

// 高亮当前歌词
void Widget::highlightCurrentLyric(qint64 position) {
  // 当前歌曲
  Song *currentSong =
      m_songManager->getSong(m_musicPlayer->getMediaPlayer()->source());
  // 歌词为空
  if (currentSong->getLyrics().isEmpty()) {
    return;
  }
  QMap<qint64, QString> lyrics = currentSong->getLyrics();
  int currentLinePos = 0;
  for (auto it = lyrics.begin(); it != lyrics.end(); it++) {
    if (std::next(it) == lyrics.end()) {
      break;
    }
    if (position > it.key() && position < std::next(it).key()) {
      break;
    }
    currentLinePos++;
  }
  ui->lyricsList->setCurrentRow(currentLinePos);
  QListWidgetItem *item = ui->lyricsList->item(currentLinePos);
  // 列表滚动到该行, 并垂直居中
  ui->lyricsList->scrollToItem(item, QAbstractItemView::PositionAtCenter);
}

// 处理音量变化
void Widget::handleVoiceChanged(float volume) {
  // 获取进度条最大值
  // int maxPlaySliderValue = ui->playSlider->maximum();
  // ui->voiceSlider->setValue((int)(maxPlaySliderValue * volume));
  if (volume == 0) {
    ui->voiceBtn->setIcon(QIcon(":/icon/images/toolIcon/voice_0.png"));
  } else if (volume > 0 && volume <= 0.25) {
    ui->voiceBtn->setIcon(QIcon(":/icon/images/toolIcon/voice_1.png"));
  } else if (volume > 0.25 && volume <= 0.5) {
    ui->voiceBtn->setIcon(QIcon(":/icon/images/toolIcon/voice_2.png"));
  } else {
    ui->voiceBtn->setIcon(QIcon(":/icon/images/toolIcon/voice_3.png"));
  }
}

// 音量条改变音量
void Widget::voiceSliderReleased() {
  // 获取进度条最大值
  int maxVoiceSliderValue = ui->voiceSlider->maximum();
  int currentVoiceSliderValue = ui->voiceSlider->value();
  m_musicPlayer->getMediaPlayer()->audioOutput()->setVolume(
      (float)currentVoiceSliderValue / maxVoiceSliderValue);
}

/* =====  重写事件  ===== */

// 绘制主窗口背景图片
void Widget::paintEvent(QPaintEvent *event) {
  // 设置背景图片
  QPixmap backgroundImage(":/background/images/background/bg_1.jpg");
  backgroundImage =
      m_widgetStyle->setRoundRectImage(backgroundImage, this->size(), 15);
  QPainter painter(this);
  painter.drawPixmap(this->rect(), backgroundImage);
}

// 鼠标单击事件
void Widget::mousePressEvent(QMouseEvent *event) {
  // 点击某点隐藏音量
  int mouseX = event->pos().x();
  int mouseY = event->pos().y();
  if ((mouseX < ui->voiceSlider->x()) ||
      (mouseX > ui->voiceSlider->x() + ui->voiceSlider->width()) ||
      (mouseY < ui->voiceSlider->y()) ||
      (mouseY > ui->voiceSlider->y() + ui->voiceSlider->height())) {
    ui->voiceSlider->hide();
  }
  // 点击某点让列表显示当前行
  if ((mouseX < ui->playList->x()) ||
      (mouseX > ui->playList->x() + ui->playList->width()) ||
      (mouseY < ui->playList->y()) ||
      (mouseY > ui->playList->y() + ui->playList->height())) {
    ui->playList->setCurrentRow(MusicPlayer::getCurrentPos());
  }
  // 记录窗口移动的初始位置
  if (event->button() == Qt::LeftButton) {
    m_offset = event->globalPosition().toPoint() - this->pos();
    event->accept();
  }
}

// 鼠标移动事件
void Widget::mouseMoveEvent(QMouseEvent *event) {
  int mouseX = event->pos().x();
  int mouseY = event->pos().y();
  // 移动窗口, 判断鼠标是否在可移动窗口区域内
  if ((mouseX > ui->titleLabel->x()) && (mouseX < ui->minimizeBtn->x()) &&
      (mouseY > 0) && (mouseY < ui->titleLabel->height())) {
    // 注意是buttons, 通过按位与判断左键是否被按下
    if (event->buttons() & Qt::LeftButton) {
      move(event->globalPosition().toPoint() - m_offset);
      event->accept();
      setCursor(Qt::ClosedHandCursor);
    }
  }
}

// 鼠标释放事件
void Widget::mouseReleaseEvent(QMouseEvent *event) {
  m_offset = QPoint();
  event->accept();
  setCursor(Qt::ArrowCursor);
}
