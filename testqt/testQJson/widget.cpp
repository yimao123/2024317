#include "widget.h"
#include "ui_widget.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QJsonObject sOne, sTwo, language, languages;
    sOne.insert("grade", 10);
    sOne.insert("language", "汉语");
    sTwo.insert("grade", 6);
    sTwo.insert("language", "英语");
    language.insert("serialone", sOne);
    language.insert("serialtwo", sTwo);
    languages.insert("languages", language);

    QJsonDocument json_document;
    json_document.setObject(languages);
    QByteArray byte_array = json_document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);
    qDebug()<<json_str;

    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(json_str.toUtf8(), &jsonError);
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull()) {
        qDebug() << "Json格式错误" << jsonError.error;
        return;

    }//封包数据正确性判断


    QJsonObject parse = doc.object();

    QJsonValue value = parse.value("languages");

    if(value.type() == QJsonValue::Object){

        QJsonObject _parse = value.toObject();

        QJsonValue _value = _parse.value("serialone");

        if(_value.type() == QJsonValue::Object){

            QJsonObject __parse = _value.toObject();

            QJsonValue grade = __parse.value("grade");

            int var = grade.toInt();

            qDebug()<<"grade:"<<var;

            QJsonValue language = __parse.value("language");

            QString str = language.toString();

            qDebug()<<"language:"<<str;

        }

        QJsonValue __value = _parse.value("serialtwo");

        if(__value.type() == QJsonValue::Object){

            QJsonObject __parse = __value.toObject();

            QJsonValue grade = __parse.value("grade");

            int var = grade.toInt();

            qDebug()<<"grade:"<<var;

            QJsonValue language = __parse.value("language");

            QString str = language.toString();

            qDebug()<<"language:"<<str;
        }
    }

}

Widget::~Widget()
{
    delete ui;
}
