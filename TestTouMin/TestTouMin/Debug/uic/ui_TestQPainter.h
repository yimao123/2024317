/********************************************************************************
** Form generated from reading UI file 'TestQPainter.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQPAINTER_H
#define UI_TESTQPAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQPainter
{
public:

    void setupUi(QWidget *TestQPainter)
    {
        if (TestQPainter->objectName().isEmpty())
            TestQPainter->setObjectName(QStringLiteral("TestQPainter"));
        TestQPainter->resize(400, 300);

        retranslateUi(TestQPainter);

        QMetaObject::connectSlotsByName(TestQPainter);
    } // setupUi

    void retranslateUi(QWidget *TestQPainter)
    {
        TestQPainter->setWindowTitle(QApplication::translate("TestQPainter", "TestQPainter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQPainter: public Ui_TestQPainter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQPAINTER_H
