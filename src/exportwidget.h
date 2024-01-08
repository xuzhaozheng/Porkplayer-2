#include <QtWidgets/QWidget>
#include <QString>
#include <QMap>
#include <QVector>
#include <QFileInfo>
#include <QTextCodec>

#include <QProcess>

#include "ui/ui_exportwidget.h"

class ExportWidget : public QWidget
{
	Q_OBJECT
public:
	ExportWidget(QString source_file_path,QWidget* parent = 0, QString ori_fps = "25", QList<int> ori_res = {1920,1080});
	~ExportWidget();

	
	QString originalFps;
	QList<int> originalRes;

	void setFFmpegPath(QString path);
	void setOutputPath(QString path);
	void setOperationMode(QString mode);
	void setAudioCodec(QString codec);
	void setVideoCodec(QString codec);
	void setTargetFormat(QString codec);
	void setTargetFps(QString fps);
	void setTargetFps(double fps);
	void setTargetRes(QString res);
	void setTargetBitrate(QString rate);

	QString getAudioCodec();
	QString getVideoCodec();
	QString getTargetFormat();
	QString getTargetFps();
	QList<int> getTargetRes();
	QString getTargetBitrate();

	void selectDestintation(QString path);

	static QMap<QString, int> opModeMap;
	static QMap<QString, int> init_opModeMap();

	static QMap<QString, QString> targetFormatMap;
	static QMap<QString, QString> init_targetFormatMap();

	static QMap<QString, QString> targetBitrateMap;
	static QMap<QString, QString> init_targetBitrateMap();

	static QMap<QString, QList<int>> targetResMap;
	static QMap<QString, QList<int>> init_targetResMap();

	static QMap<QString, QString> targetVCodecMap;
	static QMap<QString, QString> init_targetVCodecMap();

	static QMap<QString, QString> targetACodecMap;
	static QMap<QString, QString> init_targetACodecMap();

	static QMap<QString, QString> targetFpsMap;
	static QMap<QString, QString> init_targetFpsMap();

Q_SIGNALS:
	void opModeChanged(QString value);
private Q_SLOTS:

	void init_signal_slot();
	void selectDestintation();


	void opModeSwitch(QString mode);
	void vCodecSwitch(QString codec);
	void aCodecSwitch(QString codec);
	void targetFormatSwitch(QString format);
	void targetBitrateSwitch(QString rate);
	void targetFpsSwitch(QString fps);
	void targetResSwitch(QString res);
	void startExport();
	void cancelExport(QProcess* p);

private:

	Ui::exportWidget ui;

	void init_ui();

	QStringList handle_ffmpeg_command(QString mode);
	
	QFileInfo sourceFile;
	QFileInfo outputFile;
	QFileInfo ffmpegFile;
	
	QString vCodec;
	QString aCodec;

	QString sourceFilename;
	QString sourceFilename_noext;
	QString sourceFilePath;
	

	QString outputFilename_noext;
	
	QString sourcePath;
	QString outputPath;
	QString ffmpegPath;


	QStringList commandList;
	QString operationMode;
	QString targetFps;
	QString targetFormat;
	QString targetBitrate;
	QList<int> targetRes ;

	QProcess* ffmpegProcess;
};