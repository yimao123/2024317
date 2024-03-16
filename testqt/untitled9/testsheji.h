#ifndef TESTSHEJI_H
#define TESTSHEJI_H

#include <QWidget>

namespace Ui {
class TestSheji;
}

class TestSheji : public QWidget
{
    Q_OBJECT

public:
    explicit TestSheji(QWidget *parent = 0);
    ~TestSheji();

private:
    Ui::TestSheji *ui;
};

#endif // TESTSHEJI_H
