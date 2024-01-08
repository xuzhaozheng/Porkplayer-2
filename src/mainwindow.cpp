#include "mainwindow.h"
#include "mpvwidget.h"
#include "timecode.h"

#include "exportwidget.h"
#include "metadatawidget.h"
#include "settingwindow.h"

#include <QPushButton>
#include <QSlider>
#include <QLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QMap>
#include <QFileDialog>
#include <sstream>
#include <string>
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>

#include "ui/ui_mainwindow.h"

using std::string;
using std::to_string;

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{   
    // 在Qt中，父类销毁时会自动delete子类，只需要new而无需单独delete。
    m_mpv = new MpvWidget(this);
    m_setting = new SettingWindow(this);
    sourceFile = new QFileInfo();

    ui.mpv = m_mpv;
    ui.setupUi(this);
    init_signal_slot();
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    
}

void MainWindow::init_signal_slot()
{
    qRegisterMetaType<QStringList>("QStringList");
    connect(ui.m_slider, SIGNAL(sliderMoved(int)), SLOT(seek(int)));
    // 按钮的信号与槽连接
    connect(ui.m_openBtn, SIGNAL(clicked()), SLOT(openMedia()));
    connect(ui.m_playBtn, SIGNAL(clicked()), SLOT(pauseResume()));
    connect(ui.m_playReverseBtn, SIGNAL(clicked()), SLOT(playRev()));
    connect(ui.m_prev5sBtn, SIGNAL(clicked()), SLOT(prev5s()));
    connect(ui.m_next5sBtn, SIGNAL(clicked()), SLOT(next5s()));
    connect(ui.m_prevFrameBtn, SIGNAL(clicked()), SLOT(prevFrame()));
    connect(ui.m_nextFrameBtn, SIGNAL(clicked()), SLOT(nextFrame()));
    connect(ui.m_screenshotBtn, SIGNAL(clicked()), SLOT(screenshot()));
    connect(ui.m_exportBtn, SIGNAL(clicked()), SLOT(exportMedia()));
    connect(ui.m_metadataBtn, SIGNAL(clicked()), SLOT(getMetadata()));
    connect(ui.m_settingBtn, SIGNAL(clicked()), SLOT(openSetting()));

    connect(m_setting, SIGNAL(targetDisplayChanged(QStringList)), this, SLOT(setTargetDisplay(QStringList)));



    // 刷新滑动条位置
    connect(m_mpv, SIGNAL(positionChanged(double)), this, SLOT(setSliderValue(double)));
    // 刷新时间文本
    connect(m_mpv, SIGNAL(positionChanged(double)), this, SLOT(refreshTimeText(double)));
    // 刷新滑动条范围
    connect(m_mpv, SIGNAL(durationChanged(int)), this, SLOT(setSliderRange(int)));
    // 刷新播放速度文本
    connect(m_mpv, SIGNAL(speedChanged(double)), this, SLOT(refreshSpeedText(double)));
    connect(m_mpv, SIGNAL(newFileLoaded(QList<int>)), this, SLOT(resizeVideoWindow(QList<int>)));
}

void MainWindow::setSourceFile(QString filepath)
{
    sourceFile->setFile(filepath);
}

void MainWindow::openMedia()
{
    QString file = QFileDialog::getOpenFileName(0, "Open a video");
    if (file.isEmpty())
        return;// 对未选择文件的情况进行处理，防止退出
    m_mpv->command(QStringList() << "loadfile" << file);
    setSourceFile(file);
    ui.m_filenameText->setText(sourceFile->fileName());
}

void MainWindow::resizeVideoWindow(QList<int> size)
{
    // 调整视频窗口大小至与原视频比例相符
    if (size[0] > 2048)
    {
        QSize window;
        float newWidth = 1920;
        float newHeight = 1920 * size[1] / size[0];
        if (newHeight / 2 != 0) {
            newHeight++;
            m_mpv->setMinimumSize(QSize(newWidth, newHeight));
            m_mpv->resize(QSize(newWidth, newHeight));
        }
    }
    else {
        m_mpv->setMinimumSize(QSize(size[0], size[1]));
    }
}

void MainWindow::seek(int pos)
{
    m_mpv->command(QVariantList() << "seek" << pos << "absolute");
}

void MainWindow::pauseResume()
{
    const bool paused = m_mpv->getProperty("pause").toBool();
    m_mpv->setProperty("pause", !paused);
}

void MainWindow::pause()
{
    m_mpv->setProperty("pause", true);
}

void MainWindow::playRev() 
{
    qDebug() << "here";
    QVariantList status = getPlayStatus();
    shuttleLeft(status);
}
void MainWindow::screenshot()
{
    m_mpv->setProperty("screenshot-template", "%f_%n");
    m_mpv->setProperty("screenshot-directory",sourceFile->path());
    m_mpv->command(QStringList() << "screenshot");
}

void MainWindow::setSliderRange(int duration)
{
    ui.m_slider->setRange(0, duration);
}

void MainWindow::setSliderValue(double pos)
{
    int position = static_cast<int>(pos);
    ui.m_slider->setValue(position);
}

void MainWindow::refreshTimeText(double time) {

    double fps = m_mpv->getProperty("container-fps").toDouble();
    int frame = time_to_frame(time, fps);
    QString timecode = frame_to_timecode(frame, fps);


    std::stringstream frame_ss;
    frame_ss << frame;
    ui.m_frameText->setText(QString::fromStdString(frame_ss.str()));
    ui.m_frameText->setText(QString::fromStdString(frame_ss.str()));
    
    ui.m_timecodeText->setText(timecode);

}

void MainWindow::refreshSpeedText(double speed)
{
    QString c_dir = getPlayStatus()[0].toString();
    if (c_dir == "forward") {
        QString speedString = "+" + QString::number(speed)+"x";
        ui.m_speedText->setText(speedString);
    }
    else if (c_dir == "backward") {
        QString speedString = "-" + QString::number(speed)+"x";
        ui.m_speedText->setText(speedString);
    }
}

int MainWindow::time_to_frame(double& time, double& fps)
{
    int frame = 0;
    frame = round(fps * time);
    return frame;
}

QString MainWindow::frame_to_timecode(int& frame,double& fps)
{
    Timecode tc = Timecode(frame, fps, false);;
    QString timecode= QString::fromStdString(tc.to_string());
    return timecode;
}

void MainWindow::prev5s() {
    m_mpv->command(QVariantList() << "seek" << -5 << "relative+exact");
}

void MainWindow::next5s() {
    m_mpv->command(QVariantList() << "seek" << 5 << "relative+exact");
    
}

void MainWindow::prevFrame() 
{
    m_mpv->setProperty("play-dir", "+");
    m_mpv->command(QStringList() << "frame-back-step");

}

void MainWindow::nextFrame() 
{
    m_mpv->setProperty("play-dir", "+");
    m_mpv->command(QStringList() << "frame-step");
}

QVariantList MainWindow::getPlayStatus()
{
    QString currentDir = m_mpv->getProperty("play-dir").toString();
    double currentSpeed = m_mpv->getProperty("speed").toDouble();
    bool currentPause = m_mpv->getProperty("pause").toBool();
    QVariantList playStatus;
    playStatus << currentDir << currentSpeed << currentPause;

    return playStatus;
}

void MainWindow::shuttleRight(QVariantList status)
{   
    QString c_dir = status[0].toString();
    double c_speed = status[1].toDouble();
    bool c_pause = status[2].toBool();

    if ((c_pause == false) && (c_dir == "forward")) {
        m_mpv->setProperty("speed", c_speed * 2);
    }
    else if ((c_pause == true)||(c_dir == "backward")) {
        m_mpv->setProperty("play-dir", "+");
        if (c_speed == 1) { refreshSpeedText(1); }
        m_mpv->setProperty("speed", 1);
        m_mpv->setProperty("pause", false);
    }
}

void MainWindow::slow_shuttleRight(QVariantList status)
{
    QString c_dir = status[0].toString();
    double c_speed = status[1].toDouble();
    bool c_pause = status[2].toBool();

    if ((c_pause == false) && (c_dir == "forward")) {
        m_mpv->setProperty("speed", c_speed * 0.5);
    }
    else if ((c_pause == true) || (c_dir == "backward")) {
        m_mpv->setProperty("play-dir", "+");
        m_mpv->setProperty("speed", 0.5);
        m_mpv->setProperty("pause", false);
    }
}

void MainWindow::shuttleLeft(QVariantList status)
{
    QString c_dir = status[0].toString();
    double c_speed = status[1].toDouble();
    bool c_pause = status[2].toBool();

    if ((c_pause == false) && (c_dir == "backward")) {
        m_mpv->setProperty("speed", c_speed * 2);
    }
    else if ((c_pause == true) || (c_dir == "forward")) {
        m_mpv->setProperty("play-dir", "-");
        if (c_speed == 1) { refreshSpeedText(1); }
        m_mpv->setProperty("speed", 1);
        m_mpv->setProperty("pause", false);
    }
}

void MainWindow::slow_shuttleLeft(QVariantList status)
{
    QString c_dir = status[0].toString();
    double c_speed = status[1].toDouble();
    bool c_pause = status[2].toBool();

    if ((c_pause == false) && (c_dir == "backward")) {
        m_mpv->setProperty("speed", c_speed * 0.5);
    }
    else if ((c_pause == true) || (c_dir == "forward")) {
        m_mpv->setProperty("play-dir", "-");
        m_mpv->setProperty("speed", 0.5);
        m_mpv->setProperty("pause", false);
    }
}

void MainWindow::getMetadata()
{
    
    if (sourceFile->absoluteFilePath().isEmpty()) {
        QMessageBox::information(this, "Metadata", "Open Media to get metadata");

    }
    else
    {
        MetadataWidget* m_mi = new MetadataWidget(sourceFile->absoluteFilePath(), this);
        m_mi->setAttribute(Qt::WA_DeleteOnClose);
        m_mi->handle_mediainfo();
        m_mi->show();
    }
    
}

void MainWindow::exportMedia()
{

    if (sourceFile->absoluteFilePath().isEmpty()) {
        QMessageBox::information(this, "Metadata", "Open Media to export"); // 打开视频文件后方能查看元数据

    }
    else {
        pause();
        double mpv_fps = m_mpv->getProperty("container-fps").toInt();

        QString fps = QString::number(mpv_fps, 'f', 2);
        
        QList<int>resolution;
        resolution.append(m_mpv->getProperty("width").toInt());
        resolution.append(m_mpv->getProperty("height").toInt());


        ExportWidget* m_export = new ExportWidget(sourceFile->absoluteFilePath(), this, fps, resolution);

        m_export->setFFmpegPath(m_setting->ffmpegPath);
        m_export->setAttribute(Qt::WA_DeleteOnClose);
        m_export->selectDestintation(sourceFile->absolutePath());
        m_export->show();
    }
}

void MainWindow::setTargetDisplay(QStringList property)
{

    m_mpv->setProperty(property[0], property[1]);
}

void MainWindow::openSetting()
{
    m_setting->show();
}

void MainWindow::keyPressEvent(QKeyEvent* enter)
{
    // 快捷键设计思路与Avid MC相似
    switch (enter->key()) {
    case Qt::Key_O:openMedia(); break;
    case Qt::Key_A:prev5s(); break;
    case Qt::Key_D:next5s(); break;
    case Qt::Key_N:prevFrame(); break;
    case Qt::Key_M:nextFrame(); break;
    case Qt::Key_K:pause(); break;
    case Qt::Key_Space:pauseResume(); break;
    case Qt::Key_L:shuttleRight(getPlayStatus()); break;
    case Qt::Key_U:slow_shuttleRight(getPlayStatus()); break;
    case Qt::Key_Y:slow_shuttleLeft(getPlayStatus()); break;
    case Qt::Key_J:shuttleLeft(getPlayStatus()); break;
    case Qt::Key_E:exportMedia(); break;
    }
}

