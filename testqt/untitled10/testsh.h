#ifndef TESTSH_H
#define TESTSH_H

#include <QWidget>

namespace Ui {
class TestSh;
}

class TestSh : public QWidget
{
    Q_OBJECT

public:
    explicit TestSh(QWidget *parent = 0);
    ~TestSh();

private:
    Ui::TestSh *ui;
};

#endif // TESTSH_H
