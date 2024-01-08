#pragma once
#include <QtWidgets/QWidget>
#include <QMetaType>
#include <QStringList>
#include "ui/ui_settingwindow.h"

class SettingWindow : public QWidget
{
	Q_OBJECT
public:
	SettingWindow(QWidget* parent=0);
	~SettingWindow();
	QString ffmpegPath;
Q_SIGNALS:
	void targetDisplayChanged(QStringList s);

private Q_SLOTS:
	void eotfSwitch(QString target);
	void colorSpaceSwitch(QString target);
	void dataLevelSwitch(QString target);
	void setffmpegPath();
private:
	Ui::setting ui;
};

