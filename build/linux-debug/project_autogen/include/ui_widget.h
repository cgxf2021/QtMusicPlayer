/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *musicImageLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *titleImageBtn;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *minimizeBtn;
    QPushButton *closeBtn;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *playList;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *lyricsList;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *addMusicBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *leftSwitchBtn;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *playBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *rightSwitchBtn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *playModeBtn;
    QSpacerItem *horizontalSpacer_12;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QLabel *songNameLabel;
    QHBoxLayout *horizontalLayout_5;
    QSlider *playSlider;
    QLabel *timeLabel;
    QPushButton *voiceBtn;
    QSlider *voiceSlider;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1200, 800);
        Widget->setMinimumSize(QSize(1200, 800));
        Widget->setMaximumSize(QSize(1200, 800));
        musicImageLabel = new QLabel(Widget);
        musicImageLabel->setObjectName("musicImageLabel");
        musicImageLabel->setGeometry(QRect(30, 630, 135, 135));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(9, 9, 1171, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        titleImageBtn = new QPushButton(layoutWidget);
        titleImageBtn->setObjectName("titleImageBtn");

        horizontalLayout->addWidget(titleImageBtn);

        titleLabel = new QLabel(layoutWidget);
        titleLabel->setObjectName("titleLabel");

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        minimizeBtn = new QPushButton(layoutWidget);
        minimizeBtn->setObjectName("minimizeBtn");

        horizontalLayout->addWidget(minimizeBtn);

        closeBtn = new QPushButton(layoutWidget);
        closeBtn->setObjectName("closeBtn");

        horizontalLayout->addWidget(closeBtn);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 12);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 80, 991, 521));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        playList = new QListWidget(layoutWidget1);
        playList->setObjectName("playList");

        horizontalLayout_2->addWidget(playList);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lyricsList = new QListWidget(layoutWidget1);
        lyricsList->setObjectName("lyricsList");

        horizontalLayout_2->addWidget(lyricsList);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 8);
        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(221, 689, 711, 61));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        addMusicBtn = new QPushButton(layoutWidget2);
        addMusicBtn->setObjectName("addMusicBtn");

        horizontalLayout_3->addWidget(addMusicBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        leftSwitchBtn = new QPushButton(layoutWidget2);
        leftSwitchBtn->setObjectName("leftSwitchBtn");

        horizontalLayout_3->addWidget(leftSwitchBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        playBtn = new QPushButton(layoutWidget2);
        playBtn->setObjectName("playBtn");

        horizontalLayout_3->addWidget(playBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        rightSwitchBtn = new QPushButton(layoutWidget2);
        rightSwitchBtn->setObjectName("rightSwitchBtn");

        horizontalLayout_3->addWidget(rightSwitchBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        playModeBtn = new QPushButton(layoutWidget2);
        playModeBtn->setObjectName("playModeBtn");

        horizontalLayout_3->addWidget(playModeBtn);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(4, 1);
        horizontalLayout_3->setStretch(6, 1);
        horizontalLayout_3->setStretch(8, 1);
        horizontalLayout_3->setStretch(10, 1);
        layoutWidget3 = new QWidget(Widget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(222, 618, 801, 61));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        songNameLabel = new QLabel(layoutWidget3);
        songNameLabel->setObjectName("songNameLabel");

        verticalLayout->addWidget(songNameLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        playSlider = new QSlider(layoutWidget3);
        playSlider->setObjectName("playSlider");
        playSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(playSlider);

        timeLabel = new QLabel(layoutWidget3);
        timeLabel->setObjectName("timeLabel");

        horizontalLayout_5->addWidget(timeLabel);

        horizontalLayout_5->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_5);

        voiceBtn = new QPushButton(Widget);
        voiceBtn->setObjectName("voiceBtn");
        voiceBtn->setGeometry(QRect(1080, 690, 60, 60));
        voiceSlider = new QSlider(Widget);
        voiceSlider->setObjectName("voiceSlider");
        voiceSlider->setGeometry(QRect(1080, 500, 60, 180));
        voiceSlider->setOrientation(Qt::Vertical);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        musicImageLabel->setText(QCoreApplication::translate("Widget", "musicImage", nullptr));
        titleImageBtn->setText(QCoreApplication::translate("Widget", "TitleImage", nullptr));
        titleLabel->setText(QCoreApplication::translate("Widget", "Dark Music Player", nullptr));
        minimizeBtn->setText(QCoreApplication::translate("Widget", "minimize", nullptr));
        closeBtn->setText(QCoreApplication::translate("Widget", "close", nullptr));
        addMusicBtn->setText(QCoreApplication::translate("Widget", "addMusic", nullptr));
        leftSwitchBtn->setText(QCoreApplication::translate("Widget", "leftSwitch", nullptr));
        playBtn->setText(QCoreApplication::translate("Widget", "play", nullptr));
        rightSwitchBtn->setText(QCoreApplication::translate("Widget", "rightSwitch", nullptr));
        playModeBtn->setText(QCoreApplication::translate("Widget", "playMode", nullptr));
        songNameLabel->setText(QCoreApplication::translate("Widget", "Nama of Song:", nullptr));
        timeLabel->setText(QCoreApplication::translate("Widget", "00:00/00:00", nullptr));
        voiceBtn->setText(QCoreApplication::translate("Widget", "voice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
