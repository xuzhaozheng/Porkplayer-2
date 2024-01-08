#include "metadatawidget.h"
#include "ui/ui_metadatawidget.h"
#include <mediainfo/MediaInfoDLL.h>

using namespace MediaInfoDLL;

MetadataWidget::MetadataWidget(QString filePath,QWidget* parent)
{
	// ֻ��Ҫ��Mediainfo�ṩĿ���ļ��ľ���·�������为���ļ��Ĵ����ͷ�
	handle = new MediaInfo();
	ui.setupUi(this);
	currentFilePath = filePath;
	connect(this, SIGNAL(processFinshed()), SLOT(showMetadata()));
}

MetadataWidget::~MetadataWidget(){}

String MetadataWidget::toMiString(QString in)
{
	// Mediainfo���ܺͷ��ص�����������StdWString����Ҫת��
	String out = in.toStdWString();
	return out;
}

void MetadataWidget::handle_mediainfo()
{
	String mi_filePath = toMiString(currentFilePath);
	handle->Open(mi_filePath);

	// ����Inform�����õ�Ԫ�����б�
	String mi_outMetadata = handle->Inform();

	currentFileMetadata = QString::fromWCharArray(mi_outMetadata.c_str());// Ψһƥ������������c_str
	handle->Close();
	Q_EMIT processFinshed();
}

void MetadataWidget::showMetadata()
{
	// ��Mediainfo���ص�Ԫ�����б���ʾ���ı��������
	ui.textBrowser->setText(currentFileMetadata);
}