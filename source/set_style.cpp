#include "../header/set_style.hpp"

#include <QPainter>
#include <QPainterPath>

StyleSet::StyleSet() {}

StyleSet::~StyleSet() {}

void StyleSet::setPushButton(QPushButton *button, const QString &tips,
                             const QString &path, int width, int height) {
  button->setIcon(QIcon(path));
  button->setText("");
  button->setFixedSize(width, height);
  button->setIconSize(button->size());
  button->setToolTip(tips);
  // 设置qss
  m_buttonStyle = QString(
      "QPushButton {"
      "  border: none;"
      "  background-color: transparent;"
      "  padding: 0px;"
      "}");
  button->setStyleSheet(m_buttonStyle);
}

void StyleSet::setListWidget(QListWidget *listWidget, int itemHeight) {
  m_listWidgetStyle = QString(
                          "QListWidget {"
                          "  background-color: rgba(255, 255, 255, 0.3);"
                          "  border-radius: 5px;"
                          "}"
                          "QListWidget::Item {"
                          "  color: #FFFFFF;"
                          "  height: %1px;"
                          "  border-radius: 5px;"
                          "}"
                          "QListWidget::Item:selected {"
                          "  background-color: rgba(212, 35, 122, 0.5);"
                          "}"
                          "QListWidget::Item:hover {"
                          "  background-color: rgba(135, 206, 250, 0.5);"
                          "}")
                          .arg(itemHeight);
  listWidget->setStyleSheet(m_listWidgetStyle);
  listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void StyleSet::setLabel(QLabel *label, int fontSize, bool isBord,
                        bool isItalics, const QColor &color,
                        const QString &text) {
  // 设置字体
  QFont font = label->font();
  font.setPointSize(fontSize);
  font.setFamily("AR PL UKai CN");
  font.setBold(isBord);
  font.setItalic(isItalics);
  label->setFont(font);
  // 设置字体内容
  label->setText(text);
  // 设置颜色
  QPalette palette = label->palette();
  palette.setColor(QPalette::WindowText, color);
  label->setPalette(palette);
  m_labelStyle = QString(
      "QLabel {"
      "border: none;"
      "background-color: transparent;"
      "padding: 0px;"
      "}");
  label->setStyleSheet(m_labelStyle);
}

QPixmap StyleSet::setRoundRectImage(QPixmap &drawImage, const QSize &size,
                                    int radius) {
  // 缩放图片
  drawImage =
      drawImage.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  // 创建空白图片
  QPixmap blankImage(drawImage.size());
  // 设置空白图片透明
  blankImage.fill(Qt::transparent);
  // 创建画笔
  QPainter painter(&blankImage);
  // 抗锯齿
  painter.setRenderHint(QPainter::Antialiasing);
  // 平滑
  painter.setRenderHint(QPainter::SmoothPixmapTransform);
  // 将图片裁剪圆角
  QPainterPath path;
  path.addRoundedRect(blankImage.rect(), radius, radius);
  painter.setClipPath(path);
  painter.drawPixmap(blankImage.rect(), drawImage);

  return blankImage;
}

void StyleSet::setSlider(QSlider *slider, bool isHorizontal) {
  if (isHorizontal) {
    m_hSliderStyle = QString(
        "QSlider::groove:horizontal {"
        "  background-color: #CCCCCC;"
        "  height: 6px;"
        "  border-radius: 3px;"
        "}"
        "QSlider::sub-page:horizontal {"
        "  background-color: #87CEFA;"
        "  height: 6px;"
        "  border-radius: 3px;"
        "}"
        "QSlider::handle:horizontal {"
        "  background-color: #FFFFFF;"
        "  width: 12px;"
        "  margin: -6px 0;"
        "  border-radius: 6px;"
        "}");
    slider->setStyleSheet(m_hSliderStyle);
  } else {
    m_vSliderStyle = QString(
        "QSlider::groove:vertical {"
        "  background-color: #87CEFA;"
        "  width: 6px;"
        "  border-radius: 3px;"
        "}"
        "QSlider::sub-page:vertical {"
        "  background-color: #CCCCCC;"
        "  width: 6px;"
        "  border-radius: 3px;"
        "}"
        "QSlider::handle:vertical {"
        "  background-color: #FFFFFF;"
        "  height: 12px;"
        "  margin: 0 -6px;"
        "  border-radius: 6px;"
        "}");
    slider->setStyleSheet(m_vSliderStyle);
  }
}
