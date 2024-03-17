/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication12.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION12_H
#define UI_QTWIDGETSAPPLICATION12_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication12Class
{
public:
    QPushButton *DoBtn;

    void setupUi(QWidget *QtWidgetsApplication12Class)
    {
        if (QtWidgetsApplication12Class->objectName().isEmpty())
            QtWidgetsApplication12Class->setObjectName(QStringLiteral("QtWidgetsApplication12Class"));
        QtWidgetsApplication12Class->resize(600, 400);
        DoBtn = new QPushButton(QtWidgetsApplication12Class);
        DoBtn->setObjectName(QStringLiteral("DoBtn"));
        DoBtn->setGeometry(QRect(140, 80, 112, 34));

        retranslateUi(QtWidgetsApplication12Class);

        QMetaObject::connectSlotsByName(QtWidgetsApplication12Class);
    } // setupUi

    void retranslateUi(QWidget *QtWidgetsApplication12Class)
    {
        QtWidgetsApplication12Class->setWindowTitle(QApplication::translate("QtWidgetsApplication12Class", "QtWidgetsApplication12", Q_NULLPTR));
        DoBtn->setText(QApplication::translate("QtWidgetsApplication12Class", "DoBtn", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication12Class: public Ui_QtWidgetsApplication12Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION12_H
