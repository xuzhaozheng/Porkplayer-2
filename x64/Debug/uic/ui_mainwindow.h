/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mpvwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *vb_1;
    QGridLayout *gl_1;
    QVBoxLayout *verticalLayout_4;
    QLabel *m_speedTitle;
    QLabel *m_speedText;
    QPushButton *m_metadataBtn;
    QPushButton *m_exportBtn;
    QVBoxLayout *verticalLayout_7;
    QLabel *m_filenameTitle;
    QLabel *m_filenameText;
    QVBoxLayout *verticalLayout_3;
    QLabel *m_frameTitle;
    QLabel *m_frameText;
    QSpacerItem *hSpace_1;
    QSpacerItem *hSpace_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *m_timecodeTitle;
    QLabel *m_timecodeText;
    QSpacerItem *hSpace_2;
    QPushButton *m_settingBtn;
    QSpacerItem *hSpace_0;
    QSpacerItem *hSpace_3;
    MpvWidget *m_mpv;
    QSlider *m_slider;
    QGridLayout *gl_2;
    QSpacerItem *hSpace_7;
    QHBoxLayout *hb_1;
    QPushButton *m_openBtn;
    QPushButton *m_playReverseBtn;
    QPushButton *m_playBtn;
    QSpacerItem *hSpace_5;
    QSpacerItem *hSpace_6;
    QSpacerItem *hSpace_8;
    QHBoxLayout *hb_3;
    QPushButton *m_screenshotBtn;
    QHBoxLayout *hb_2;
    QPushButton *m_prev5sBtn;
    QPushButton *m_next5sBtn;
    QPushButton *m_prevFrameBtn;
    QPushButton *m_nextFrameBtn;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1956, 1310);
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        vb_1 = new QVBoxLayout();
        vb_1->setSpacing(6);
        vb_1->setObjectName(QString::fromUtf8("vb_1"));
        vb_1->setContentsMargins(12, 12, 12, 12);
        gl_1 = new QGridLayout();
        gl_1->setObjectName(QString::fromUtf8("gl_1"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        m_speedTitle = new QLabel(MainWindow);
        m_speedTitle->setObjectName(QString::fromUtf8("m_speedTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_speedTitle->sizePolicy().hasHeightForWidth());
        m_speedTitle->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift Light"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        m_speedTitle->setFont(font);
        m_speedTitle->setFrameShape(QFrame::NoFrame);

        verticalLayout_4->addWidget(m_speedTitle);

        m_speedText = new QLabel(MainWindow);
        m_speedText->setObjectName(QString::fromUtf8("m_speedText"));
        sizePolicy.setHeightForWidth(m_speedText->sizePolicy().hasHeightForWidth());
        m_speedText->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift Light"));
        font1.setPointSize(11);
        m_speedText->setFont(font1);
        m_speedText->setFrameShape(QFrame::NoFrame);

        verticalLayout_4->addWidget(m_speedText);


        gl_1->addLayout(verticalLayout_4, 0, 7, 1, 1);

        m_metadataBtn = new QPushButton(MainWindow);
        m_metadataBtn->setObjectName(QString::fromUtf8("m_metadataBtn"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bahnschrift Light"));
        font2.setPointSize(10);
        m_metadataBtn->setFont(font2);
        m_metadataBtn->setFocusPolicy(Qt::NoFocus);

        gl_1->addWidget(m_metadataBtn, 0, 11, 1, 1);

        m_exportBtn = new QPushButton(MainWindow);
        m_exportBtn->setObjectName(QString::fromUtf8("m_exportBtn"));
        m_exportBtn->setFont(font2);
        m_exportBtn->setFocusPolicy(Qt::NoFocus);

        gl_1->addWidget(m_exportBtn, 0, 12, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        m_filenameTitle = new QLabel(MainWindow);
        m_filenameTitle->setObjectName(QString::fromUtf8("m_filenameTitle"));
        sizePolicy.setHeightForWidth(m_filenameTitle->sizePolicy().hasHeightForWidth());
        m_filenameTitle->setSizePolicy(sizePolicy);
        m_filenameTitle->setFont(font);
        m_filenameTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_7->addWidget(m_filenameTitle);

        m_filenameText = new QLabel(MainWindow);
        m_filenameText->setObjectName(QString::fromUtf8("m_filenameText"));
        sizePolicy.setHeightForWidth(m_filenameText->sizePolicy().hasHeightForWidth());
        m_filenameText->setSizePolicy(sizePolicy);
        m_filenameText->setFont(font1);
        m_filenameText->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(m_filenameText);


        gl_1->addLayout(verticalLayout_7, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        m_frameTitle = new QLabel(MainWindow);
        m_frameTitle->setObjectName(QString::fromUtf8("m_frameTitle"));
        sizePolicy.setHeightForWidth(m_frameTitle->sizePolicy().hasHeightForWidth());
        m_frameTitle->setSizePolicy(sizePolicy);
        m_frameTitle->setFont(font);

        verticalLayout_3->addWidget(m_frameTitle);

        m_frameText = new QLabel(MainWindow);
        m_frameText->setObjectName(QString::fromUtf8("m_frameText"));
        sizePolicy.setHeightForWidth(m_frameText->sizePolicy().hasHeightForWidth());
        m_frameText->setSizePolicy(sizePolicy);
        m_frameText->setFont(font1);

        verticalLayout_3->addWidget(m_frameText);


        gl_1->addLayout(verticalLayout_3, 0, 5, 1, 1);

        hSpace_1 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gl_1->addItem(hSpace_1, 0, 4, 1, 1);

        hSpace_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gl_1->addItem(hSpace_4, 0, 10, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_timecodeTitle = new QLabel(MainWindow);
        m_timecodeTitle->setObjectName(QString::fromUtf8("m_timecodeTitle"));
        sizePolicy.setHeightForWidth(m_timecodeTitle->sizePolicy().hasHeightForWidth());
        m_timecodeTitle->setSizePolicy(sizePolicy);
        m_timecodeTitle->setFont(font);
        m_timecodeTitle->setTextFormat(Qt::AutoText);

        verticalLayout_2->addWidget(m_timecodeTitle);

        m_timecodeText = new QLabel(MainWindow);
        m_timecodeText->setObjectName(QString::fromUtf8("m_timecodeText"));
        sizePolicy.setHeightForWidth(m_timecodeText->sizePolicy().hasHeightForWidth());
        m_timecodeText->setSizePolicy(sizePolicy);
        m_timecodeText->setFont(font1);

        verticalLayout_2->addWidget(m_timecodeText);


        gl_1->addLayout(verticalLayout_2, 0, 3, 1, 1);

        hSpace_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gl_1->addItem(hSpace_2, 0, 6, 1, 1);

        m_settingBtn = new QPushButton(MainWindow);
        m_settingBtn->setObjectName(QString::fromUtf8("m_settingBtn"));
        m_settingBtn->setFont(font2);
        m_settingBtn->setFocusPolicy(Qt::NoFocus);
        m_settingBtn->setFlat(false);

        gl_1->addWidget(m_settingBtn, 0, 13, 1, 1);

        hSpace_0 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gl_1->addItem(hSpace_0, 0, 1, 1, 1);

        hSpace_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gl_1->addItem(hSpace_3, 0, 8, 1, 1);


        vb_1->addLayout(gl_1);

        m_mpv = new MpvWidget(MainWindow);
        m_mpv->setObjectName(QString::fromUtf8("m_mpv"));
        m_mpv->setMinimumSize(QSize(1920, 1180));

        vb_1->addWidget(m_mpv);

        m_slider = new QSlider(MainWindow);
        m_slider->setObjectName(QString::fromUtf8("m_slider"));
        m_slider->setFocusPolicy(Qt::NoFocus);
        m_slider->setOrientation(Qt::Horizontal);

        vb_1->addWidget(m_slider);

        gl_2 = new QGridLayout();
        gl_2->setObjectName(QString::fromUtf8("gl_2"));
        hSpace_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gl_2->addItem(hSpace_7, 0, 17, 1, 1);

        hb_1 = new QHBoxLayout();
        hb_1->setObjectName(QString::fromUtf8("hb_1"));
        m_openBtn = new QPushButton(MainWindow);
        m_openBtn->setObjectName(QString::fromUtf8("m_openBtn"));
        m_openBtn->setFont(font2);
        m_openBtn->setFocusPolicy(Qt::NoFocus);

        hb_1->addWidget(m_openBtn);

        m_playReverseBtn = new QPushButton(MainWindow);
        m_playReverseBtn->setObjectName(QString::fromUtf8("m_playReverseBtn"));
        m_playReverseBtn->setFont(font2);
        m_playReverseBtn->setFocusPolicy(Qt::NoFocus);

        hb_1->addWidget(m_playReverseBtn);

        m_playBtn = new QPushButton(MainWindow);
        m_playBtn->setObjectName(QString::fromUtf8("m_playBtn"));
        m_playBtn->setFont(font2);
        m_playBtn->setFocusPolicy(Qt::NoFocus);

        hb_1->addWidget(m_playBtn);


        gl_2->addLayout(hb_1, 0, 6, 1, 1);

        hSpace_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gl_2->addItem(hSpace_5, 0, 0, 1, 1);

        hSpace_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gl_2->addItem(hSpace_6, 0, 11, 1, 1);

        hSpace_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gl_2->addItem(hSpace_8, 0, 20, 1, 1);

        hb_3 = new QHBoxLayout();
        hb_3->setObjectName(QString::fromUtf8("hb_3"));
        m_screenshotBtn = new QPushButton(MainWindow);
        m_screenshotBtn->setObjectName(QString::fromUtf8("m_screenshotBtn"));
        m_screenshotBtn->setFont(font2);
        m_screenshotBtn->setFocusPolicy(Qt::NoFocus);

        hb_3->addWidget(m_screenshotBtn);


        gl_2->addLayout(hb_3, 0, 18, 1, 1);

        hb_2 = new QHBoxLayout();
        hb_2->setObjectName(QString::fromUtf8("hb_2"));
        m_prev5sBtn = new QPushButton(MainWindow);
        m_prev5sBtn->setObjectName(QString::fromUtf8("m_prev5sBtn"));
        m_prev5sBtn->setFont(font2);
        m_prev5sBtn->setFocusPolicy(Qt::NoFocus);

        hb_2->addWidget(m_prev5sBtn);

        m_next5sBtn = new QPushButton(MainWindow);
        m_next5sBtn->setObjectName(QString::fromUtf8("m_next5sBtn"));
        m_next5sBtn->setFont(font2);
        m_next5sBtn->setFocusPolicy(Qt::NoFocus);

        hb_2->addWidget(m_next5sBtn);

        m_prevFrameBtn = new QPushButton(MainWindow);
        m_prevFrameBtn->setObjectName(QString::fromUtf8("m_prevFrameBtn"));
        m_prevFrameBtn->setFont(font2);
        m_prevFrameBtn->setFocusPolicy(Qt::NoFocus);

        hb_2->addWidget(m_prevFrameBtn);

        m_nextFrameBtn = new QPushButton(MainWindow);
        m_nextFrameBtn->setObjectName(QString::fromUtf8("m_nextFrameBtn"));
        m_nextFrameBtn->setFont(font2);
        m_nextFrameBtn->setFocusPolicy(Qt::NoFocus);

        hb_2->addWidget(m_nextFrameBtn);


        gl_2->addLayout(hb_2, 0, 13, 1, 1);


        vb_1->addLayout(gl_2);

        vb_1->setStretch(0, 1);
        vb_1->setStretch(1, 10);
        vb_1->setStretch(2, 1);
        vb_1->setStretch(3, 1);

        verticalLayout->addLayout(vb_1);


        retranslateUi(MainWindow);

        m_settingBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Porkplayer", nullptr));
        m_speedTitle->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        m_speedText->setText(QCoreApplication::translate("MainWindow", "1x", nullptr));
        m_metadataBtn->setText(QCoreApplication::translate("MainWindow", "Metadata", nullptr));
        m_exportBtn->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        m_filenameTitle->setText(QCoreApplication::translate("MainWindow", "Filename", nullptr));
        m_filenameText->setText(QCoreApplication::translate("MainWindow", "Select File to Play", nullptr));
        m_frameTitle->setText(QCoreApplication::translate("MainWindow", "Frame", nullptr));
        m_frameText->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_timecodeTitle->setText(QCoreApplication::translate("MainWindow", "Timecode", nullptr));
        m_timecodeText->setText(QCoreApplication::translate("MainWindow", "00:00:00:00", nullptr));
        m_settingBtn->setText(QCoreApplication::translate("MainWindow", "Setting", nullptr));
        m_openBtn->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        m_playReverseBtn->setText(QCoreApplication::translate("MainWindow", "Play Reverse", nullptr));
        m_playBtn->setText(QCoreApplication::translate("MainWindow", "Play/Pause", nullptr));
        m_screenshotBtn->setText(QCoreApplication::translate("MainWindow", "Screenshot", nullptr));
        m_prev5sBtn->setText(QCoreApplication::translate("MainWindow", "-5s", nullptr));
        m_next5sBtn->setText(QCoreApplication::translate("MainWindow", "+5s", nullptr));
        m_prevFrameBtn->setText(QCoreApplication::translate("MainWindow", "-1f", nullptr));
        m_nextFrameBtn->setText(QCoreApplication::translate("MainWindow", "+1f", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
