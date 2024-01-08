/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setting
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *vb_1;
    QGridLayout *gd_1;
    QComboBox *s_colorSpaceBox;
    QComboBox *s_dataLevelBox;
    QComboBox *s_eotfBox;
    QLabel *s_dataLevelText;
    QLabel *s_displaySettingText;
    QLabel *s_eotfText;
    QLabel *s_colorSpcaeText;
    QFrame *s_ffmpegPathText;
    QGridLayout *gd_2;
    QLabel *s_exportSettingText;
    QLabel *s_ffmpegPathTitle;
    QLineEdit *s_ffmpegPathEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *s_applyBtn;

    void setupUi(QWidget *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName(QString::fromUtf8("setting"));
        setting->setWindowModality(Qt::ApplicationModal);
        setting->resize(601, 400);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(setting->sizePolicy().hasHeightForWidth());
        setting->setSizePolicy(sizePolicy);
        setting->setMinimumSize(QSize(600, 400));
        QFont font;
        font.setPointSize(10);
        setting->setFont(font);
        verticalLayout_2 = new QVBoxLayout(setting);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        vb_1 = new QVBoxLayout();
        vb_1->setObjectName(QString::fromUtf8("vb_1"));
        vb_1->setSizeConstraint(QLayout::SetDefaultConstraint);
        gd_1 = new QGridLayout();
        gd_1->setObjectName(QString::fromUtf8("gd_1"));
        gd_1->setSizeConstraint(QLayout::SetDefaultConstraint);
        s_colorSpaceBox = new QComboBox(setting);
        s_colorSpaceBox->setObjectName(QString::fromUtf8("s_colorSpaceBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift Light"));
        font1.setPointSize(10);
        s_colorSpaceBox->setFont(font1);
        s_colorSpaceBox->setEditable(false);

        gd_1->addWidget(s_colorSpaceBox, 1, 1, 1, 1);

        s_dataLevelBox = new QComboBox(setting);
        s_dataLevelBox->setObjectName(QString::fromUtf8("s_dataLevelBox"));
        s_dataLevelBox->setFont(font1);

        gd_1->addWidget(s_dataLevelBox, 2, 1, 1, 1);

        s_eotfBox = new QComboBox(setting);
        s_eotfBox->setObjectName(QString::fromUtf8("s_eotfBox"));
        s_eotfBox->setFont(font1);

        gd_1->addWidget(s_eotfBox, 3, 1, 1, 1);

        s_dataLevelText = new QLabel(setting);
        s_dataLevelText->setObjectName(QString::fromUtf8("s_dataLevelText"));
        s_dataLevelText->setFont(font1);
        s_dataLevelText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gd_1->addWidget(s_dataLevelText, 2, 0, 1, 1);

        s_displaySettingText = new QLabel(setting);
        s_displaySettingText->setObjectName(QString::fromUtf8("s_displaySettingText"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(s_displaySettingText->sizePolicy().hasHeightForWidth());
        s_displaySettingText->setSizePolicy(sizePolicy1);
        s_displaySettingText->setMaximumSize(QSize(100, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bahnschrift SemiBold"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        s_displaySettingText->setFont(font2);

        gd_1->addWidget(s_displaySettingText, 0, 0, 1, 1);

        s_eotfText = new QLabel(setting);
        s_eotfText->setObjectName(QString::fromUtf8("s_eotfText"));
        s_eotfText->setFont(font1);
        s_eotfText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gd_1->addWidget(s_eotfText, 3, 0, 1, 1);

        s_colorSpcaeText = new QLabel(setting);
        s_colorSpcaeText->setObjectName(QString::fromUtf8("s_colorSpcaeText"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(s_colorSpcaeText->sizePolicy().hasHeightForWidth());
        s_colorSpcaeText->setSizePolicy(sizePolicy2);
        s_colorSpcaeText->setFont(font1);
        s_colorSpcaeText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gd_1->addWidget(s_colorSpcaeText, 1, 0, 1, 1);

        gd_1->setColumnStretch(0, 1);

        vb_1->addLayout(gd_1);

        s_ffmpegPathText = new QFrame(setting);
        s_ffmpegPathText->setObjectName(QString::fromUtf8("s_ffmpegPathText"));
        s_ffmpegPathText->setFrameShape(QFrame::HLine);
        s_ffmpegPathText->setFrameShadow(QFrame::Sunken);

        vb_1->addWidget(s_ffmpegPathText);

        gd_2 = new QGridLayout();
        gd_2->setObjectName(QString::fromUtf8("gd_2"));
        s_exportSettingText = new QLabel(setting);
        s_exportSettingText->setObjectName(QString::fromUtf8("s_exportSettingText"));
        sizePolicy1.setHeightForWidth(s_exportSettingText->sizePolicy().hasHeightForWidth());
        s_exportSettingText->setSizePolicy(sizePolicy1);
        s_exportSettingText->setMaximumSize(QSize(100, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Bahnschrift SemiBold"));
        font3.setPointSize(12);
        s_exportSettingText->setFont(font3);

        gd_2->addWidget(s_exportSettingText, 0, 0, 1, 1);

        s_ffmpegPathTitle = new QLabel(setting);
        s_ffmpegPathTitle->setObjectName(QString::fromUtf8("s_ffmpegPathTitle"));
        s_ffmpegPathTitle->setFont(font1);
        s_ffmpegPathTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gd_2->addWidget(s_ffmpegPathTitle, 1, 0, 1, 1);

        s_ffmpegPathEdit = new QLineEdit(setting);
        s_ffmpegPathEdit->setObjectName(QString::fromUtf8("s_ffmpegPathEdit"));
        s_ffmpegPathEdit->setFont(font1);

        gd_2->addWidget(s_ffmpegPathEdit, 1, 1, 1, 1);

        gd_2->setColumnStretch(0, 1);

        vb_1->addLayout(gd_2);


        verticalLayout_2->addLayout(vb_1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        s_applyBtn = new QPushButton(setting);
        s_applyBtn->setObjectName(QString::fromUtf8("s_applyBtn"));
        s_applyBtn->setFont(font1);

        horizontalLayout->addWidget(s_applyBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(setting);

        s_colorSpaceBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(setting);
    } // setupUi

    void retranslateUi(QWidget *setting)
    {
        setting->setWindowTitle(QCoreApplication::translate("setting", "Porkplayer Setting", nullptr));
        s_colorSpaceBox->setCurrentText(QString());
        s_dataLevelText->setText(QCoreApplication::translate("setting", "Data Level :", nullptr));
        s_displaySettingText->setText(QCoreApplication::translate("setting", "Target Display", nullptr));
        s_eotfText->setText(QCoreApplication::translate("setting", "EOTF :", nullptr));
        s_colorSpcaeText->setText(QCoreApplication::translate("setting", "Color Space :", nullptr));
        s_exportSettingText->setText(QCoreApplication::translate("setting", "Export", nullptr));
        s_ffmpegPathTitle->setText(QCoreApplication::translate("setting", "FFmpeg Path :", nullptr));
        s_applyBtn->setText(QCoreApplication::translate("setting", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
