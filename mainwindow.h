#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtimer.h"
#include "qtreadwork.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_btnStart_clicked();

    void on_btnNext_clicked();

    void on_btnAuto_clicked();

    void on_btnStop_clicked();

private:
    Ui::MainWindow *ui;
private:
    QString m_strCurrentPath;
    QVector<QString> m_vecFilePaths;

    uint32_t nCurrentIndex;
    QTreadWork* m_threadWork;
    QThread* m_thread;
    QTimer* m_timer;
private:
    void InitConfig();
private slots:
    void Show(QString strAcc, QString strCi, QString strPi, int iOpcode, int iOperand);
    void ShowDialog();
};
#endif // MAINWINDOW_H
