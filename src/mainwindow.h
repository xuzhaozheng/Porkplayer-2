#ifndef MainWindow_H
#define MainWindow_H

#include <QtWidgets/QWidget>
#include "settingwindow.h"
#include "ui/ui_mainwindow.h"
#include <QStringList>
#include <QMetaType>
#include <QVariant>


class MpvWidget;
class MediaInfoWidget;
class Timecode;
class QFileInfo;
class QSlider;
class QPushButton;
class QLineEdit;
class QComboBox;
class QLabel;
class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);

    ~MainWindow();

public Q_SLOTS:
    void openMedia();
    void seek(int pos);
    void pauseResume();


    // 自定义的播放控制函数
    void prev5s();
    void next5s();
    void prevFrame();
    void nextFrame();
    void pause();
    void playRev();

    QVariantList getPlayStatus();
    // Shuttle的具体行为与当前播放状态相关
    void shuttleRight(QVariantList status);
    void slow_shuttleRight(QVariantList status);
    void shuttleLeft(QVariantList status);
    void slow_shuttleLeft(QVariantList status);


    // 增加的功能，包括元数据、设置、转码、色彩管理
    void getMetadata();
    void screenshot();
    void exportMedia();
    void openSetting();
    void setTargetDisplay(QStringList property);

private Q_SLOTS:

    void setSliderRange(int duration);
    void setSliderValue(double pos);

    void refreshTimeText(double time);
    void refreshSpeedText(double speed);

    void resizeVideoWindow(QList<int> size);


private:
    MpvWidget* m_mpv;
    SettingWindow* m_setting;
    Ui::MainWindow ui;

    QFileInfo* sourceFile;
    QString s_ffmpegPath;

    void init_signal_slot();
    void setSourceFile(QString filepath);

    int time_to_frame(double& time, double& fps);
    QString frame_to_timecode(int& frame, double& fps);
    
protected:
    void keyPressEvent(QKeyEvent* enter);
    void closeEvent(QCloseEvent* event);

};

#endif // MainWindow_H