/********************************************************************************
** Form generated from reading UI file 'testsheji.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSHEJI_H
#define UI_TESTSHEJI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestSheji
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *TestSheji)
    {
        if (TestSheji->objectName().isEmpty())
            TestSheji->setObjectName(QStringLiteral("TestSheji"));
        TestSheji->resize(400, 300);
        pushButton = new QPushButton(TestSheji);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 80, 15));
        lineEdit = new QLineEdit(TestSheji);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 60, 113, 20));

        retranslateUi(TestSheji);

        QMetaObject::connectSlotsByName(TestSheji);
    } // setupUi

    void retranslateUi(QWidget *TestSheji)
    {
        TestSheji->setWindowTitle(QApplication::translate("TestSheji", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TestSheji", "\346\265\213\350\257\225\346\217\220\345\215\207\346\214\211\351\222\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestSheji: public Ui_TestSheji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSHEJI_H
