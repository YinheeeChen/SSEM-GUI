#ifndef QBASEDIALOG_H
#define QBASEDIALOG_H

#include "qdialog.h"
#include <QKeyEvent>
class QBaseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QBaseDialog(QWidget *parent = nullptr);

signals:
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // QBASEDIALOG_H
