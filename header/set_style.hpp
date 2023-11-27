#ifndef SET_STYLE_HPP
#define SET_STYLE_HPP

#include <QColor>
#include <QFont>
#include <QIcon>
#include <QLabel>
#include <QListWidget>
#include <QPalette>
#include <QPixmap>
#include <QPushButton>
#include <QString>

/* 设置widget的样式 */
class StyleSet {
 private:
  QString m_buttonStyle;
  QString m_listWidgetStyle;
  QString m_labelStyle;
  QString m_hSliderStyle;
  QString m_vSliderStyle;

 public:
  StyleSet();
  ~StyleSet();
  // 设置按钮样式
  void setPushButton(QPushButton *button, const QString &tips,
                     const QString &path, int width, int height);
  // 设置列表样式
  void setListWidget(QListWidget *listWidget, int itemHeight = 30);
  // 设置标签文字样式
  void setLabel(QLabel *label, int fontSize = 1, bool isBord = false,
                bool isItalics = false, const QColor &color = Qt::white,
                const QString &text = nullptr);
  // 绘制圆角矩形图片
  QPixmap setRoundRectImage(QPixmap &drawImage, const QSize &size, int radius);
  // 设置滑动条样式
  void setSlider(QSlider *slider, bool isHorizontal = true);
};

#endif  // !SET_STYLE_HPP
