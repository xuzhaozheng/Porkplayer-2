#include <QtWidgets/QWidget>
#include <QString>

#include "mediainfo/MediaInfoDLL.h"
#include "ui/ui_metadatawidget.h"



class MetadataWidget : public QWidget
{
	Q_OBJECT
public:
	MetadataWidget(QString filePath, QWidget* parent = 0);
	~MetadataWidget();

	void handle_mediainfo();
	MediaInfoDLL::String toMiString(QString in);

Q_SIGNALS:
	void processFinshed();// Mediainfo进程完成的信号

private Q_SLOTS:
	void showMetadata();

private:
	Ui::MetadataWidget ui;
	MediaInfoDLL::MediaInfo* handle;
	QString currentFilePath;
	QString currentFileMetadata;

};