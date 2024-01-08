/********************************************************************************
** Form generated from reading UI file 'exportwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTWIDGET_H
#define UI_EXPORTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exportWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *vl_1;
    QHBoxLayout *hb_1;
    QLabel *e_outPath_Label;
    QLineEdit *e_outPathEdit;
    QPushButton *e_selectOutBtn;
    QHBoxLayout *hb_2;
    QGridLayout *control_layout;
    QVBoxLayout *vCodec_vLayout;
    QLabel *e_vCodecLabel;
    QComboBox *e_vCodecBox;
    QVBoxLayout *format_vLayout;
    QLabel *e_formatLabel;
    QComboBox *e_formatBox;
    QSpacerItem *space_2;
    QPushButton *e_startBtn;
    QPushButton *e_cancelBtn;
    QVBoxLayout *bitRate_vLayput;
    QLabel *e_bitRateText;
    QHBoxLayout *mbps_hLayout;
    QComboBox *e_bitRateBox;
    QLabel *e_mbpsText;
    QSpacerItem *space_1;
    QSpacerItem *space_3;
    QLabel *e_opModeLabel;
    QComboBox *e_opModeBox;
    QVBoxLayout *res_vLayout;
    QLabel *e_resLabel;
    QComboBox *e_resBox;
    QVBoxLayout *fps_vLayout;
    QLabel *e_fpsLabel;
    QComboBox *e_fpsBox;
    QVBoxLayout *aCodec_vLayout;
    QLabel *e_aCodecLabel;
    QComboBox *e_aCodecBox;
    QTextBrowser *e_log_text;

    void setupUi(QWidget *exportWidget)
    {
        if (exportWidget->objectName().isEmpty())
            exportWidget->setObjectName(QStringLiteral("exportWidget"));
        exportWidget->setWindowModality(Qt::ApplicationModal);
        exportWidget->setEnabled(true);
        exportWidget->resize(961, 414);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exportWidget->sizePolicy().hasHeightForWidth());
        exportWidget->setSizePolicy(sizePolicy);
        exportWidget->setMinimumSize(QSize(0, 0));
        exportWidget->setMaximumSize(QSize(16777215, 16777215));
        exportWidget->setBaseSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(exportWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        vl_1 = new QVBoxLayout();
        vl_1->setObjectName(QStringLiteral("vl_1"));
        hb_1 = new QHBoxLayout();
        hb_1->setObjectName(QStringLiteral("hb_1"));
        e_outPath_Label = new QLabel(exportWidget);
        e_outPath_Label->setObjectName(QStringLiteral("e_outPath_Label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(e_outPath_Label->sizePolicy().hasHeightForWidth());
        e_outPath_Label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Bahnschrift Light"));
        font.setPointSize(10);
        e_outPath_Label->setFont(font);

        hb_1->addWidget(e_outPath_Label);

        e_outPathEdit = new QLineEdit(exportWidget);
        e_outPathEdit->setObjectName(QStringLiteral("e_outPathEdit"));
        e_outPathEdit->setFont(font);
        e_outPathEdit->setCursor(QCursor(Qt::IBeamCursor));
        e_outPathEdit->setReadOnly(true);

        hb_1->addWidget(e_outPathEdit);

        e_selectOutBtn = new QPushButton(exportWidget);
        e_selectOutBtn->setObjectName(QStringLiteral("e_selectOutBtn"));
        sizePolicy1.setHeightForWidth(e_selectOutBtn->sizePolicy().hasHeightForWidth());
        e_selectOutBtn->setSizePolicy(sizePolicy1);
        e_selectOutBtn->setMinimumSize(QSize(0, 0));
        e_selectOutBtn->setMaximumSize(QSize(16777215, 16777215));
        e_selectOutBtn->setFont(font);

        hb_1->addWidget(e_selectOutBtn);


        vl_1->addLayout(hb_1);

        hb_2 = new QHBoxLayout();
        hb_2->setObjectName(QStringLiteral("hb_2"));
        control_layout = new QGridLayout();
        control_layout->setObjectName(QStringLiteral("control_layout"));
        vCodec_vLayout = new QVBoxLayout();
        vCodec_vLayout->setObjectName(QStringLiteral("vCodec_vLayout"));
        e_vCodecLabel = new QLabel(exportWidget);
        e_vCodecLabel->setObjectName(QStringLiteral("e_vCodecLabel"));
        sizePolicy1.setHeightForWidth(e_vCodecLabel->sizePolicy().hasHeightForWidth());
        e_vCodecLabel->setSizePolicy(sizePolicy1);
        e_vCodecLabel->setFont(font);

        vCodec_vLayout->addWidget(e_vCodecLabel);

        e_vCodecBox = new QComboBox(exportWidget);
        e_vCodecBox->setObjectName(QStringLiteral("e_vCodecBox"));
        e_vCodecBox->setFont(font);

        vCodec_vLayout->addWidget(e_vCodecBox);


        control_layout->addLayout(vCodec_vLayout, 2, 1, 1, 1);

        format_vLayout = new QVBoxLayout();
        format_vLayout->setObjectName(QStringLiteral("format_vLayout"));
        e_formatLabel = new QLabel(exportWidget);
        e_formatLabel->setObjectName(QStringLiteral("e_formatLabel"));
        sizePolicy1.setHeightForWidth(e_formatLabel->sizePolicy().hasHeightForWidth());
        e_formatLabel->setSizePolicy(sizePolicy1);
        e_formatLabel->setFont(font);

        format_vLayout->addWidget(e_formatLabel);

        e_formatBox = new QComboBox(exportWidget);
        e_formatBox->setObjectName(QStringLiteral("e_formatBox"));
        sizePolicy1.setHeightForWidth(e_formatBox->sizePolicy().hasHeightForWidth());
        e_formatBox->setSizePolicy(sizePolicy1);
        e_formatBox->setFont(font);

        format_vLayout->addWidget(e_formatBox);


        control_layout->addLayout(format_vLayout, 2, 0, 1, 1);

        space_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        control_layout->addItem(space_2, 6, 2, 1, 1);

        e_startBtn = new QPushButton(exportWidget);
        e_startBtn->setObjectName(QStringLiteral("e_startBtn"));
        e_startBtn->setFont(font);

        control_layout->addWidget(e_startBtn, 7, 1, 1, 1);

        e_cancelBtn = new QPushButton(exportWidget);
        e_cancelBtn->setObjectName(QStringLiteral("e_cancelBtn"));
        e_cancelBtn->setFont(font);

        control_layout->addWidget(e_cancelBtn, 7, 2, 1, 1);

        bitRate_vLayput = new QVBoxLayout();
        bitRate_vLayput->setObjectName(QStringLiteral("bitRate_vLayput"));
        e_bitRateText = new QLabel(exportWidget);
        e_bitRateText->setObjectName(QStringLiteral("e_bitRateText"));
        sizePolicy1.setHeightForWidth(e_bitRateText->sizePolicy().hasHeightForWidth());
        e_bitRateText->setSizePolicy(sizePolicy1);
        e_bitRateText->setFont(font);

        bitRate_vLayput->addWidget(e_bitRateText);

        mbps_hLayout = new QHBoxLayout();
        mbps_hLayout->setObjectName(QStringLiteral("mbps_hLayout"));
        e_bitRateBox = new QComboBox(exportWidget);
        e_bitRateBox->setObjectName(QStringLiteral("e_bitRateBox"));
        e_bitRateBox->setFont(font);
        e_bitRateBox->setEditable(false);

        mbps_hLayout->addWidget(e_bitRateBox);

        e_mbpsText = new QLabel(exportWidget);
        e_mbpsText->setObjectName(QStringLiteral("e_mbpsText"));
        e_mbpsText->setFont(font);

        mbps_hLayout->addWidget(e_mbpsText);


        bitRate_vLayput->addLayout(mbps_hLayout);


        control_layout->addLayout(bitRate_vLayput, 2, 2, 1, 1);

        space_1 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        control_layout->addItem(space_1, 6, 0, 1, 1);

        space_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        control_layout->addItem(space_3, 6, 1, 1, 1);

        e_opModeLabel = new QLabel(exportWidget);
        e_opModeLabel->setObjectName(QStringLiteral("e_opModeLabel"));
        e_opModeLabel->setFont(font);

        control_layout->addWidget(e_opModeLabel, 1, 0, 1, 1);

        e_opModeBox = new QComboBox(exportWidget);
        e_opModeBox->setObjectName(QStringLiteral("e_opModeBox"));
        e_opModeBox->setFont(font);

        control_layout->addWidget(e_opModeBox, 1, 1, 1, 1);

        res_vLayout = new QVBoxLayout();
        res_vLayout->setObjectName(QStringLiteral("res_vLayout"));
        e_resLabel = new QLabel(exportWidget);
        e_resLabel->setObjectName(QStringLiteral("e_resLabel"));
        sizePolicy1.setHeightForWidth(e_resLabel->sizePolicy().hasHeightForWidth());
        e_resLabel->setSizePolicy(sizePolicy1);
        e_resLabel->setFont(font);

        res_vLayout->addWidget(e_resLabel);

        e_resBox = new QComboBox(exportWidget);
        e_resBox->setObjectName(QStringLiteral("e_resBox"));
        e_resBox->setFont(font);

        res_vLayout->addWidget(e_resBox);


        control_layout->addLayout(res_vLayout, 4, 0, 1, 1);

        fps_vLayout = new QVBoxLayout();
        fps_vLayout->setObjectName(QStringLiteral("fps_vLayout"));
        e_fpsLabel = new QLabel(exportWidget);
        e_fpsLabel->setObjectName(QStringLiteral("e_fpsLabel"));
        sizePolicy1.setHeightForWidth(e_fpsLabel->sizePolicy().hasHeightForWidth());
        e_fpsLabel->setSizePolicy(sizePolicy1);
        e_fpsLabel->setFont(font);

        fps_vLayout->addWidget(e_fpsLabel);

        e_fpsBox = new QComboBox(exportWidget);
        e_fpsBox->setObjectName(QStringLiteral("e_fpsBox"));
        e_fpsBox->setFont(font);

        fps_vLayout->addWidget(e_fpsBox);


        control_layout->addLayout(fps_vLayout, 4, 1, 1, 1);

        aCodec_vLayout = new QVBoxLayout();
        aCodec_vLayout->setObjectName(QStringLiteral("aCodec_vLayout"));
        e_aCodecLabel = new QLabel(exportWidget);
        e_aCodecLabel->setObjectName(QStringLiteral("e_aCodecLabel"));
        sizePolicy1.setHeightForWidth(e_aCodecLabel->sizePolicy().hasHeightForWidth());
        e_aCodecLabel->setSizePolicy(sizePolicy1);
        e_aCodecLabel->setFont(font);

        aCodec_vLayout->addWidget(e_aCodecLabel);

        e_aCodecBox = new QComboBox(exportWidget);
        e_aCodecBox->setObjectName(QStringLiteral("e_aCodecBox"));
        e_aCodecBox->setFont(font);

        aCodec_vLayout->addWidget(e_aCodecBox);


        control_layout->addLayout(aCodec_vLayout, 4, 2, 1, 1);

        control_layout->setColumnStretch(0, 3);
        control_layout->setColumnStretch(1, 3);
        control_layout->setColumnStretch(2, 3);

        hb_2->addLayout(control_layout);

        e_log_text = new QTextBrowser(exportWidget);
        e_log_text->setObjectName(QStringLiteral("e_log_text"));
        sizePolicy.setHeightForWidth(e_log_text->sizePolicy().hasHeightForWidth());
        e_log_text->setSizePolicy(sizePolicy);
        e_log_text->setMinimumSize(QSize(600, 0));
        e_log_text->setFocusPolicy(Qt::NoFocus);

        hb_2->addWidget(e_log_text);

        hb_2->setStretch(1, 3);

        vl_1->addLayout(hb_2);

        vl_1->setStretch(0, 1);
        vl_1->setStretch(1, 8);

        horizontalLayout->addLayout(vl_1);


        retranslateUi(exportWidget);

        QMetaObject::connectSlotsByName(exportWidget);
    } // setupUi

    void retranslateUi(QWidget *exportWidget)
    {
        exportWidget->setWindowTitle(QApplication::translate("exportWidget", "Export Media", Q_NULLPTR));
        e_outPath_Label->setText(QApplication::translate("exportWidget", "Output path:", Q_NULLPTR));
        e_outPathEdit->setText(QString());
        e_selectOutBtn->setText(QApplication::translate("exportWidget", "Select Destination", Q_NULLPTR));
        e_vCodecLabel->setText(QApplication::translate("exportWidget", "Video Codec:", Q_NULLPTR));
        e_formatLabel->setText(QApplication::translate("exportWidget", "Target Format:", Q_NULLPTR));
        e_startBtn->setText(QApplication::translate("exportWidget", "Start", Q_NULLPTR));
        e_cancelBtn->setText(QApplication::translate("exportWidget", "Cancel", Q_NULLPTR));
        e_bitRateText->setText(QApplication::translate("exportWidget", "Bit Rate:", Q_NULLPTR));
        e_mbpsText->setText(QApplication::translate("exportWidget", "Mbps", Q_NULLPTR));
        e_opModeLabel->setText(QApplication::translate("exportWidget", "Operation Mode:", Q_NULLPTR));
        e_opModeBox->clear();
        e_opModeBox->insertItems(0, QStringList()
         << QApplication::translate("exportWidget", "Transcode", Q_NULLPTR)
         << QApplication::translate("exportWidget", "Rewrap", Q_NULLPTR)
        );
        e_resLabel->setText(QApplication::translate("exportWidget", "Resolution:", Q_NULLPTR));
        e_fpsLabel->setText(QApplication::translate("exportWidget", "FPS:", Q_NULLPTR));
        e_aCodecLabel->setText(QApplication::translate("exportWidget", "Audio Codec:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class exportWidget: public Ui_exportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTWIDGET_H
