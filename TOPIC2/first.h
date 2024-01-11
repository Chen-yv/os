#ifndef FIRST_H
#define FIRST_H
#include "QLabel"
#include "condition.h"
#include "time_slice.h"
//#include "QTime"
#include "runwindow.h"
#include "second.h"
#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class first; }
QT_END_NAMESPACE

class first : public QMainWindow
{
    Q_OBJECT

public:

    condition outui;
    runwindow runui;
    second *second_ui;
    first(QWidget *parent = nullptr);
    ~first();

private slots:
    void on_submit_clicked();

    void on_exit_clicked();

    void on_condition_clicked();

    void on_dispath_currentTextChanged();

private:
    Ui::first *ui;
};
#endif // FIRST_H
