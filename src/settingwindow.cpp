#include "settingwindow.h"
#include <QStringList>
#include <QMap>
#include <QFileInfo>
#include <QMessageBox>

SettingWindow::SettingWindow(QWidget* parent)
{
	ui.setupUi(this);

    qRegisterMetaType<QStringList>("QStringList");
    // 在实现文件而非ui文件中添加选项，便于业务逻辑维护
    ui.s_dataLevelBox->addItem("Full");
    ui.s_dataLevelBox->addItem("Limited");

    ui.s_colorSpaceBox->addItems(QStringList()<< "BT.709"
        << "BT.2020"
        << "DCI-P3"
        << "BT.601(PAL)"
        << "BT.601(NTSC)"
        << "Adobe RGB");

    ui.s_eotfBox->addItems(QStringList() << "Gamma 2.4"
        <<"sRGB"
        << "Gamma 2.2"
        << "Gamma 2.6"
        << "PQ"
        << "HLG"
        << "Linear");

	connect(ui.s_dataLevelBox, SIGNAL(currentTextChanged(QString)), SLOT(dataLevelSwitch(QString)));
	connect(ui.s_eotfBox, SIGNAL(currentTextChanged(QString)), SLOT(eotfSwitch(QString)));
    connect(ui.s_colorSpaceBox, SIGNAL(currentTextChanged(QString)), SLOT(colorSpaceSwitch(QString)));
    connect(ui.s_applyBtn, SIGNAL(clicked()), SLOT(setffmpegPath()));
}

SettingWindow::~SettingWindow(){}

void SettingWindow::colorSpaceSwitch(QString target)
{

    // 建立显示字符串与传递给mpv的字符串之间的map
    QMap<QString, QString> colorSpaceMap;
    colorSpaceMap.insert("BT.709", "bt.709");
    colorSpaceMap.insert("BT.2020", "bt.2020");
    colorSpaceMap.insert("DCI-P3", "dci-p3");
    colorSpaceMap.insert("BT.601(PAL)", "bt.601-625");
    colorSpaceMap.insert("BT.601(NTSC)", "bt.601-525");
    colorSpaceMap.insert("Adobe RGB", "bt.601-525");
    Q_EMIT targetDisplayChanged(QStringList() << "target-prim" << colorSpaceMap.value(target));
}

void SettingWindow::eotfSwitch(QString target)
{
    // 建立显示字符串与传递给mpv的字符串之间的map
    QMap<QString, QString> eotfMap;
    eotfMap.insert("Gamma 2.2", "gamma2.2");
    eotfMap.insert("Gamma 2.4", "gamma2.4");
    eotfMap.insert("Gamma 2.6", "gamma2.6");
    eotfMap.insert("Gamma 2.6", "gamma2.6");
    eotfMap.insert("PQ", "pq");
    eotfMap.insert("HLG", "hlg");
    eotfMap.insert("sRGB", "srgb");
    eotfMap.insert("Linear", "linear");

    Q_EMIT targetDisplayChanged(QStringList() << "target-trc" << eotfMap.value(target));

}

void SettingWindow::dataLevelSwitch(QString target)
{
    if (target == "Full") {
        Q_EMIT targetDisplayChanged(QStringList() << "video-output-levels" <<"full");


    }
    else if (target == "Limited")
    {
        Q_EMIT targetDisplayChanged(QStringList() << "video-output-levels" << "limited");

    }
}

void SettingWindow::setffmpegPath()
{
    QFileInfo ffmpeg;
    ffmpeg.setFile(ui.s_ffmpegPathEdit->text());
    // 使用QFileInfo类的方法检测是否为有效路径
    if (ffmpeg.exists()&&ffmpeg.isExecutable()) {
        ffmpegPath = ffmpeg.absoluteFilePath();
        QMessageBox::information(this, "Setting", "Succeed to load ffmpeg");

    }
    else {
        QMessageBox::critical(this, "Setting", "Not valid ffmpeg path");
    }
}