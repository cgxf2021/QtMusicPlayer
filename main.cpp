#include <QApplication>

#include "widget.h"

int main(int argc, char *argv[]) {
  qputenv("QT_QPA_PLATFORM", "xcb");
  QApplication application(argc, argv);
  QPixmap winPix(":/background/images/background/win_icon.png");
  winPix = winPix.scaled(QSize(64, 64), Qt::KeepAspectRatio, Qt::SmoothTransformation);
  application.setWindowIcon(QIcon(winPix));
  Widget widget;
  widget.move(360, 120);
  widget.show();
  return application.exec();
}
