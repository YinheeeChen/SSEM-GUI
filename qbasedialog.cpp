#include "qbasedialog.h"
#include "qlabel.h"

QBaseDialog::QBaseDialog(QWidget *parent)
    : QDialog{parent}
{

}

void QBaseDialog::keyPressEvent(QKeyEvent * event)
{
    if(Qt::Key_Escape==event->key())
    {
        return;
    }
    QDialog::keyPressEvent(event);
}
