/********************************************************************************
** Form generated from reading UI file 'testThread.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTTHREAD_H
#define UI_TESTTHREAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testThreadClass
{
public:

    void setupUi(QWidget *testThreadClass)
    {
        if (testThreadClass->objectName().isEmpty())
            testThreadClass->setObjectName(QStringLiteral("testThreadClass"));
        testThreadClass->resize(600, 400);

        retranslateUi(testThreadClass);

        QMetaObject::connectSlotsByName(testThreadClass);
    } // setupUi

    void retranslateUi(QWidget *testThreadClass)
    {
        testThreadClass->setWindowTitle(QApplication::translate("testThreadClass", "testThread", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testThreadClass: public Ui_testThreadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTTHREAD_H
