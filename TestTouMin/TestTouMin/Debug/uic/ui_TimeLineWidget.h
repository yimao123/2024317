/********************************************************************************
** Form generated from reading UI file 'TimeLineWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMELINEWIDGET_H
#define UI_TIMELINEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeLineWidget
{
public:

    void setupUi(QWidget *TimeLineWidget)
    {
        if (TimeLineWidget->objectName().isEmpty())
            TimeLineWidget->setObjectName(QStringLiteral("TimeLineWidget"));
        TimeLineWidget->resize(400, 300);

        retranslateUi(TimeLineWidget);

        QMetaObject::connectSlotsByName(TimeLineWidget);
    } // setupUi

    void retranslateUi(QWidget *TimeLineWidget)
    {
        TimeLineWidget->setWindowTitle(QApplication::translate("TimeLineWidget", "TimeLineWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TimeLineWidget: public Ui_TimeLineWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMELINEWIDGET_H
