#ifndef QNEXTDIALOG_H
#define QNEXTDIALOG_H

#include "qbasedialog.h"

class QNextDialog : public QBaseDialog
{
    Q_OBJECT
public:
    explicit QNextDialog(QWidget *parent = nullptr);

private:

private:
    void InitDialog();

signals:

};

#endif // QNEXTDIALOG_H
