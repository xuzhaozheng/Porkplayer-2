#include "metadatawidget.h"
#include "ui/ui_metadatawidget.h"
#include <mediainfo/MediaInfoDLL.h>

using namespace MediaInfoDLL;

MetadataWidget::MetadataWidget(QString filePath,QWidget* parent)
{
	// 只需要向Mediainfo提供目标文件的绝对路径，由其负责文件的打开与释放
	handle = new MediaInfo();
	ui.setupUi(this);
	currentFilePath = filePath;
	connect(this, SIGNAL(processFinshed()), SLOT(showMetadata()));
}

MetadataWidget::~MetadataWidget(){}

String MetadataWidget::toMiString(QString in)
{
	// Mediainfo接受和返回的数据类型是StdWString，需要转换
	String out = in.toStdWString();
	return out;
}

void MetadataWidget::handle_mediainfo()
{
	String mi_filePath = toMiString(currentFilePath);
	handle->Open(mi_filePath);

	// 调用Inform函数得到元数据列表
	String mi_outMetadata = handle->Inform();

	currentFileMetadata = QString::fromWCharArray(mi_outMetadata.c_str());// 唯一匹配的输出类型是c_str
	handle->Close();
	Q_EMIT processFinshed();
}

void MetadataWidget::showMetadata()
{
	// 将Mediainfo返回的元数据列表显示在文本浏览器中
	ui.textBrowser->setText(currentFileMetadata);
}