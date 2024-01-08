/********************************************************************************
** Form generated from reading UI file 'metadatawidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METADATAWIDGET_H
#define UI_METADATAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MetadataWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *MetadataWidget)
    {
        if (MetadataWidget->objectName().isEmpty())
            MetadataWidget->setObjectName(QStringLiteral("MetadataWidget"));
        MetadataWidget->setWindowModality(Qt::ApplicationModal);
        MetadataWidget->resize(1500, 900);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MetadataWidget->sizePolicy().hasHeightForWidth());
        MetadataWidget->setSizePolicy(sizePolicy);
        MetadataWidget->setMinimumSize(QSize(1500, 900));
        verticalLayout_2 = new QVBoxLayout(MetadataWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(MetadataWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(9);
        textBrowser->setFont(font);

        verticalLayout->addWidget(textBrowser);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MetadataWidget);

        QMetaObject::connectSlotsByName(MetadataWidget);
    } // setupUi

    void retranslateUi(QWidget *MetadataWidget)
    {
        MetadataWidget->setWindowTitle(QApplication::translate("MetadataWidget", "Metadata", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MetadataWidget: public Ui_MetadataWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METADATAWIDGET_H
