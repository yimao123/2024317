/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qwt_dial.h"
#include "qwt_knob.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QwtKnob *Knob;
    QwtDial *Dial;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        Knob = new QwtKnob(Widget);
        Knob->setObjectName(QStringLiteral("Knob"));
        Knob->setGeometry(QRect(40, 80, 150, 150));
        Dial = new QwtDial(Widget);
        Dial->setObjectName(QStringLiteral("Dial"));
        Dial->setGeometry(QRect(210, 40, 200, 200));
        Dial->setLineWidth(4);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
