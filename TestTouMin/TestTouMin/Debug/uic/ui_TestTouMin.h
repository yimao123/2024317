/********************************************************************************
** Form generated from reading UI file 'TestTouMin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTTOUMIN_H
#define UI_TESTTOUMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestTouMinClass
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *TestTouMinClass)
    {
        if (TestTouMinClass->objectName().isEmpty())
            TestTouMinClass->setObjectName(QStringLiteral("TestTouMinClass"));
        TestTouMinClass->resize(600, 400);
        TestTouMinClass->setStyleSheet(QStringLiteral("#pushButton{background-image: url(:/TestTouMin/19_big.jpg);}"));
        pushButton = new QPushButton(TestTouMinClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 60, 112, 34));
        pushButton_2 = new QPushButton(TestTouMinClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 80, 112, 34));

        retranslateUi(TestTouMinClass);

        QMetaObject::connectSlotsByName(TestTouMinClass);
    } // setupUi

    void retranslateUi(QWidget *TestTouMinClass)
    {
        TestTouMinClass->setWindowTitle(QApplication::translate("TestTouMinClass", "TestTouMin", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TestTouMinClass", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("TestTouMinClass", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestTouMinClass: public Ui_TestTouMinClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTTOUMIN_H
