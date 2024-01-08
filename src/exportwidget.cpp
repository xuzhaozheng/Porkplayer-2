#include "exportwidget.h"
#include <QDebug>
#include <QFileDialog>
#include <QVector>
#include <QFileinfo>
#include <QProcess>
#include <qmessagebox.h>

QMap<QString, int> ExportWidget::opModeMap = ExportWidget::init_opModeMap();
QMap<QString, QString> ExportWidget::targetFormatMap = ExportWidget::init_targetFormatMap();
QMap<QString, QString> ExportWidget::targetBitrateMap = ExportWidget::init_targetBitrateMap();
QMap<QString, QList<int>> ExportWidget::targetResMap =  ExportWidget::init_targetResMap();
QMap<QString, QString> ExportWidget::targetVCodecMap =  ExportWidget::init_targetVCodecMap();
QMap<QString, QString> ExportWidget::targetACodecMap =  ExportWidget::init_targetACodecMap();
QMap<QString, QString> ExportWidget::targetFpsMap =  ExportWidget::init_targetFpsMap();


ExportWidget::ExportWidget(QString source_file_path,QWidget* parent ,QString ori_fps, QList<int> ori_res)
{
	ui.setupUi(this);

	init_ui();
	init_signal_slot();

	sourceFile.setFile(source_file_path);
	originalRes = ori_res;

	originalFps = ori_fps;
	
	sourceFilePath = sourceFile.absoluteFilePath();
	outputPath = sourceFile.absolutePath();

	ffmpegPath = "";

	opModeSwitch("Transcode");
	targetFormat = getTargetFormat();
	targetBitrate = getTargetBitrate();

	setTargetRes("Original");
	setTargetFps("Original");

	aCodec = getAudioCodec();
	vCodec = getVideoCodec();

}

ExportWidget::~ExportWidget() {}

void ExportWidget::init_signal_slot()
{
	connect(ui.e_selectOutBtn, SIGNAL(clicked()), SLOT(selectDestintation()));
	connect(ui.e_startBtn, SIGNAL(clicked()), SLOT(startExport()));
	connect(ui.e_opModeBox, SIGNAL(currentTextChanged(QString)), this, SLOT(opModeSwitch(QString)));
	connect(ui.e_vCodecBox, SIGNAL(currentTextChanged(QString)), this, SLOT(vCodecSwitch(QString)));
	connect(ui.e_aCodecBox, SIGNAL(currentTextChanged(QString)), this, SLOT(aCodecSwitch(QString)));
	connect(ui.e_formatBox, SIGNAL(currentTextChanged(QString)), this, SLOT(targetFormatSwitch(QString)));
	connect(ui.e_bitRateBox, SIGNAL(currentTextChanged(QString)), this, SLOT(targetBitrateSwitch(QString)));
	connect(ui.e_fpsBox, SIGNAL(currentTextChanged(QString)), this, SLOT(targetFpsSwitch(QString)));
	connect(ui.e_resBox, SIGNAL(currentTextChanged(QString)), this, SLOT(targetResSwitch(QString)));
}

QMap<QString, int> ExportWidget::init_opModeMap()
{
	QMap<QString, int> map;
	map["Transcode"] = 0;
	map["Rewrap"] = 1;
	return map;
}

QMap<QString, QString> ExportWidget::init_targetFormatMap()
{
	QMap<QString, QString> map;
	map["MOV"] = ".mov";
	map["MP4"] = ".mp4";
	return map;
}

QMap<QString, QString> ExportWidget::init_targetBitrateMap()
{
	QMap<QString, QString> map;
	map["100"] = "100M";
	map["60"] = "60M";
	map["40"] = "40M";
	map["10"] = "10M";
	map["6"] = "6M";
	return map;
}

QMap<QString, QList<int>> ExportWidget::init_targetResMap()
{
	QMap<QString, QList<int>> map;

	map["UHD 2160p"] = { 3840,2160 };
	map["HD 1080p"] = { 1920,1080 };
	map["HD 720p"] = { 1280,720 };
	map["DCI 4K Flat"] = { 3996,2160 };
	map["DCI 4K Scope"] = { 4096,1716 };
	map["DCI 2K Flat"] = { 1998,1080 };
	map["DCI 2K Scope"] = { 2048,858 };

	return map;
}

QMap<QString, QString> ExportWidget::init_targetVCodecMap()
{
	QMap<QString, QString> map;
	map["H.264"] = "libx264";
	map["H.265"] = "libx265";
	return map;
}

QMap<QString, QString> ExportWidget::init_targetACodecMap()
{
	QMap<QString, QString> map;
	map["AAC"] = "aac";
	map["PCM 16bit"] = "pcm_u16le";
	map["PCM 24bit"] = "pcm_u32le";
	return map;
}

QMap<QString, QString> ExportWidget::init_targetFpsMap()
{
	QMap<QString, QString> map;
	map["24"] = "24";
	map["25"] = "25";
	map["30"] = "30";
	map["50"] = "50";
	map["60"] = "60";
	map["23.976"] = "24000/1001";
	map["29.97"] = "30000/1001";
	map["59.94"] = "60000/1001";
	return map;
}

void ExportWidget::init_ui()
{

	ui.e_formatBox->addItem("MOV");
	ui.e_formatBox->addItem("MP4");

	ui.e_vCodecBox->addItem("H.264");
	ui.e_vCodecBox->addItem("H.265");
	
	ui.e_aCodecBox->addItem("AAC");
	ui.e_aCodecBox->addItem("PCM 16bit");
	ui.e_aCodecBox->addItem("PCM 24bit");

	ui.e_fpsBox->addItem("Original");
	ui.e_fpsBox->addItem("24");
	ui.e_fpsBox->addItem("25");
	ui.e_fpsBox->addItem("30");
	ui.e_fpsBox->addItem("50");
	ui.e_fpsBox->addItem("60");
	ui.e_fpsBox->addItem("23.976");
	ui.e_fpsBox->addItem("29.97");
	ui.e_fpsBox->addItem("59.94");

	ui.e_bitRateBox->addItem("100");
	ui.e_bitRateBox->addItem("60");
	ui.e_bitRateBox->addItem("40");
	ui.e_bitRateBox->addItem("10");
	ui.e_bitRateBox->addItem("6");

	ui.e_resBox->addItem("Original");
	ui.e_resBox->addItem("UHD 2160p");
	ui.e_resBox->addItem("HD 1080p");
	ui.e_resBox->addItem("HD 720p");
	ui.e_resBox->addItem("DCI 4K Flat");
	ui.e_resBox->addItem("DCI 4K Scope");
	ui.e_resBox->addItem("DCI 2K Flat");
	ui.e_resBox->addItem("DCI 2K Scope");

}


// setter and getter


void ExportWidget::setFFmpegPath(QString path)
{
	ffmpegFile.setFile(path);
	ffmpegPath = ffmpegFile.absoluteFilePath();
}

void ExportWidget::setOutputPath(QString path)
{
	if (QFileInfo::exists(path))
	{
		outputPath = path;
	}
}

void ExportWidget::setOperationMode(QString mode)
{
	if (opModeMap.contains(mode)) {
		operationMode = mode;
	}
	else {
		//unsupported
	}
}

void ExportWidget::setTargetFormat(QString format)
{
	if (targetFormatMap.contains(format)) {
		targetFormat = targetFormatMap.value(format);
	}
	else {
		//unsupported
	}

}

QString ExportWidget::getTargetFormat()
{
	if (targetFormat == "") {
		QString displayFormat;
		displayFormat = ui.e_formatBox->currentText(); ;
		return targetFormatMap.value(displayFormat);
	}
	else {
		return targetFormat;
	}
}

void ExportWidget::setVideoCodec(QString codec)
{

	if (targetVCodecMap.contains(codec)) {
		vCodec = targetVCodecMap.value(codec);
	}
	else {
		//unsupported
	}
}

void ExportWidget::setAudioCodec(QString codec)
{
	if (targetACodecMap.contains(codec)) {
		aCodec = targetACodecMap.value(codec);
	}
	else {
		//unsupported
	}
}

QString ExportWidget::getAudioCodec()
{
	if (aCodec == "") {
		QString displayCodec;
		displayCodec = ui.e_aCodecBox->currentText(); ;
		return targetACodecMap.value(displayCodec);
	}
	else {
		return aCodec;
	}
}

QString ExportWidget::getVideoCodec()
{
	if (vCodec == "") {
		QString displayCodec;
		displayCodec = ui.e_vCodecBox->currentText();
		return targetVCodecMap.value(displayCodec);
	}
	else {
		return vCodec;
	}
}

void ExportWidget::setTargetFps(QString fps)
{
	if (targetFpsMap.contains(fps)) {
		targetFps = targetFpsMap.value(fps);
	}
	else if(fps=="Original") {
		targetFps = originalFps;
	}
	else {
		//unsupported
	}

}

void ExportWidget::setTargetFps(double fps)
{
	QString stringfps = QString::number(fps);
	if (targetFpsMap.contains(stringfps)) {
		targetFps = targetFpsMap.value(stringfps);
	}
	else if (stringfps == "Original") {
		targetFps = originalFps;
	}
	else {
		//unsupported
	}

}

QString ExportWidget::getTargetFps()
{
	if (targetFps == "") {
		QString displayFps;
		displayFps = ui.e_fpsBox->currentText();
		return targetFps = targetFpsMap.value(displayFps);
	}
	else {
		return targetFps;
	}
}

void ExportWidget::setTargetRes(QString res)
{
	if(targetResMap.contains(res))
	{
		targetRes = targetResMap.value(res);
	}
	else if (res == "Original") {
		targetRes = { originalRes[0], originalRes[1]};
	}
	else {
		// unsuported
	}
}

QList<int> ExportWidget::getTargetRes()
{

	if (targetRes.isEmpty()) {
		QString displayRes;
		displayRes = ui.e_resBox->currentText();
		return targetResMap.value(displayRes);
	}
	else {
		return targetRes;
	}
}

void ExportWidget::setTargetBitrate(QString rate)
{
	if (targetBitrateMap.contains(rate)) {
		targetBitrate = targetBitrateMap.value(rate);
	}
	else{
		//unsupported
	}
}

QString ExportWidget::getTargetBitrate()
{
	if (targetBitrate == "") {
		QString displayBitrate;
		displayBitrate = ui.e_bitRateBox->currentText();
		return targetBitrate = targetBitrateMap.value(displayBitrate);
	}
	else {
		return targetBitrate;
	}
}

void ExportWidget::selectDestintation()
{
	QString dst_path = QFileDialog::getExistingDirectory();
	if (dst_path.isEmpty())
		return;
	ui.e_outPathEdit->setText(dst_path);
	setOutputPath(dst_path);
}

void ExportWidget::selectDestintation(QString path)
{
	ui.e_outPathEdit->setText(path);
	setOutputPath(path);
}

// ui

void ExportWidget::opModeSwitch(QString mode)
{
	setOperationMode(mode);
	if (mode == "Rewrap") {
		QList<QComboBox*> rewarpDisableList;
		rewarpDisableList << ui.e_vCodecBox
			<< ui.e_aCodecBox
			<< ui.e_fpsBox
			<< ui.e_resBox
			<< ui.e_bitRateBox;
		for (QComboBox* i : rewarpDisableList) {
			i->setEnabled(false);
		}
	}
	else if (mode == "Transcode") {
		QList<QComboBox*> transcodeEnableList;
		transcodeEnableList << ui.e_vCodecBox
			<< ui.e_aCodecBox
			<< ui.e_fpsBox
			<< ui.e_resBox
			<< ui.e_bitRateBox;
		for (QComboBox* i : transcodeEnableList) {
			i->setEnabled(true);
		}
	}
}

void ExportWidget::vCodecSwitch(QString codec)
{
	setVideoCodec(codec);
}

void ExportWidget::aCodecSwitch(QString codec)
{
	setAudioCodec(codec);
}

void ExportWidget::targetFpsSwitch(QString fps)
{
	setTargetFps(fps);
}

void ExportWidget::targetResSwitch(QString res)
{
	setTargetRes(res);	
}

void ExportWidget::targetBitrateSwitch(QString rate)
{
	setTargetBitrate(rate);
}

void ExportWidget::targetFormatSwitch(QString format)
{
	setTargetFormat(format);
}

// ffmpeg

QStringList ExportWidget::handle_ffmpeg_command(QString mode)
{
	outputFilename_noext = sourceFile.completeBaseName();
	if (mode == "Rewrap") {
		QStringList command;
		QString outputFilePath = outputPath +"/" + outputFilename_noext + "_rewrap" + targetFormat;
		command << "-i" << sourceFilePath
			<< "-c:v" << "copy" 
			<< "-c:a" << "copy"
			<< outputFilePath;
		return command;
	}
	else if (mode == "Transcode") {
		QStringList command;
		QString outputFilePath = outputPath + "/" + outputFilename_noext + "_transcode" + targetFormat;
		QString resolutionString = QString::number(targetRes[0]) + "*" + QString::number(targetRes[1]);
		command << "-i" << sourceFilePath
			<< "-c:v" << vCodec
			<< "-c:a" << aCodec
			<< "-s" << resolutionString
			<< "-r" << targetFps
			<< "-b:v" << targetBitrate
			<< outputFilePath;
		return command;
	}
}

void ExportWidget::startExport()
{
	commandList = handle_ffmpeg_command(operationMode);
	
	ffmpegProcess = new QProcess(this);

	//connect(ffmpegProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(onReadData()));

	ffmpegProcess->setReadChannel(QProcess::StandardOutput);
	ffmpegProcess->start(ffmpegPath,commandList);

	bool startResult = ffmpegProcess->waitForStarted();
	if (startResult) {
		ui.e_log_text->append("FFmpeg succeed to start!");
	}
	else {
		ui.e_log_text->append("FFmpeg failed to start!");
		QMessageBox::critical(this, "Export Widget", "FFmpeg failed to start!");
	}
	ffmpegProcess->waitForFinished();

	ui.e_log_text->append(QString::fromLocal8Bit(ffmpegProcess->readAllStandardOutput() + ffmpegProcess->readAllStandardError()));
}

void ExportWidget::cancelExport(QProcess*p)
{
	if (!p) {
		p->start("q");
		bool waitResult = p->waitForFinished();
		if (waitResult)
		{
			QMessageBox::warning(this, "Export Widget", "FFmpeg process canceled");
		}
	}
}