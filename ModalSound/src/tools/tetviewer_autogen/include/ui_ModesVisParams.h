/********************************************************************************
** Form generated from reading UI file 'ModesVisParams.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODESVISPARAMS_H
#define UI_MODESVISPARAMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModesVisParamsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *boxModeScale_;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *boxModeId_;

    void setupUi(QDialog *ModesVisParamsDialog)
    {
        if (ModesVisParamsDialog->objectName().isEmpty())
            ModesVisParamsDialog->setObjectName(QStringLiteral("ModesVisParamsDialog"));
        ModesVisParamsDialog->resize(200, 120);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModesVisParamsDialog->sizePolicy().hasHeightForWidth());
        ModesVisParamsDialog->setSizePolicy(sizePolicy);
        ModesVisParamsDialog->setMinimumSize(QSize(200, 120));
        ModesVisParamsDialog->setMaximumSize(QSize(200, 120));
        verticalLayout_2 = new QVBoxLayout(ModesVisParamsDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(ModesVisParamsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        boxModeScale_ = new QLineEdit(groupBox);
        boxModeScale_->setObjectName(QStringLiteral("boxModeScale_"));
        boxModeScale_->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(boxModeScale_);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        boxModeId_ = new QSpinBox(groupBox);
        boxModeId_->setObjectName(QStringLiteral("boxModeId_"));
        boxModeId_->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(boxModeId_);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(ModesVisParamsDialog);

        QMetaObject::connectSlotsByName(ModesVisParamsDialog);
    } // setupUi

    void retranslateUi(QDialog *ModesVisParamsDialog)
    {
        ModesVisParamsDialog->setWindowTitle(QApplication::translate("ModesVisParamsDialog", "Parameters", 0));
        groupBox->setTitle(QApplication::translate("ModesVisParamsDialog", "Mode Shapes", 0));
        label->setText(QApplication::translate("ModesVisParamsDialog", "Mode Amp:     ", 0));
        boxModeScale_->setText(QApplication::translate("ModesVisParamsDialog", "0.0001", 0));
        label_3->setText(QApplication::translate("ModesVisParamsDialog", "Mode ID: ", 0));
    } // retranslateUi

};

namespace Ui {
    class ModesVisParamsDialog: public Ui_ModesVisParamsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODESVISPARAMS_H
