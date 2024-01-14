#ifndef QSTARTDIALOG_H
#define QSTARTDIALOG_H

#include "qbasedialog.h"
#include <QWidget>

class QStartDialog : public QBaseDialog
{
    Q_OBJECT
public:
    explicit QStartDialog(QWidget *parent = nullptr);
private:
private:
    void InitDialog();


signals:

};

#endif // QSTARTDIALOG_H
