#include "mainwindow.h"
#include "qapplication.h"
#include "qnextdialog.h"
#include "qstartdialog.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include<QFileDialog>
#include <QMessageBox>
#include <QThread>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    while (true) {
        QStartDialog* dlg = new QStartDialog(this);
        if (QDialog::Accepted != dlg->exec()) {
            QTimer::singleShot(0, qApp, SLOT(quit()));
            return;
        }

        m_strCurrentPath = QFileDialog::getOpenFileName(this, "打开文件", "C:\\");

        if (!m_strCurrentPath.isEmpty()) {
            ui->editFile->append(m_strCurrentPath);
            break;
        }
    }

    m_threadWork=new QTreadWork();
    m_thread=new QThread;
    m_threadWork->moveToThread(m_thread);
    m_thread->start();

    // close the main window
    connect(this,&MainWindow::destroy,this,[=](){
        m_thread->quit();
        m_thread->wait();
        m_thread->deleteLater();
        if(NULL!=m_threadWork)
        {
            delete m_threadWork;
        }
    });

    //Load file from user into store
    m_timer=new QTimer(this);
    InitConfig();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitConfig()
{
    // execute the programe
    connect(m_threadWork,&QTreadWork::Show,this,&MainWindow::Show);
    connect(m_threadWork,&QTreadWork::Finally,this,&MainWindow::ShowDialog);
    connect(m_timer,&QTimer::timeout,this,[&](){
        m_threadWork->RunOneLine();
        ui->editStore->clear();
        vector<QString> vcetor;
        m_threadWork->m_store->getStore(vcetor);
        for (int var = 0; var < vcetor.size(); ++var) {
            ui->editStore->append(vcetor.at(var));
        }
    });
}

void MainWindow::Show(QString strAcc,QString strCi,QString strPi,int iOpcode,int iOperand)
{
    ui->editAcc->setText(strAcc);
    ui->editCI->setText(strCi);
    ui->EDITpi->setText(strPi);
    ui->editOpcode->setText(QString("%1").arg(iOpcode));
    ui->editOperand->setText(QString("%1").arg(iOperand));
}

void MainWindow::ShowDialog()
{

    m_timer->stop();
    while (true) {
        QNextDialog dlg;
        if (QDialog::Accepted != dlg.exec()) {
            this->close();
            return;
        }

        m_strCurrentPath = QFileDialog::getOpenFileName(this, "打开文件", "C:\\");
        qDebug()<<m_strCurrentPath;

        if (m_strCurrentPath.isEmpty()) {
            continue;
        }

        ui->editFile->append(m_strCurrentPath);
        break;
    }
    // clear the display and store
    ui->editStore->clear();
    m_threadWork->m_store->clearStore();
    m_threadWork->m_processor->clearProcessor();
    ui->editAcc->setText(m_threadWork->m_processor->getstrAcc());
    ui->editCI->setText(m_threadWork->m_processor->getstrCi());
    ui->EDITpi->setText(m_threadWork->m_processor->getstrPi());
    ui->editOpcode->setText(QString("%1").arg(m_threadWork->m_processor->getOpcode()));
    ui->editOperand->setText(QString("%1").arg(m_threadWork->m_processor->getOperand()));
}


void MainWindow::on_btnStart_clicked()
{
    ui->editStore->clear();
    // start loading
    if (!m_threadWork->m_store->LoadFileIntoStore(m_strCurrentPath.toStdString()))
    {
        QMessageBox dlgMsg(QMessageBox::Critical, QStringLiteral("错误"), QString("Error reading file:%1").arg(m_strCurrentPath));
        dlgMsg.setWindowFlags(dlgMsg.windowFlags() | Qt::WindowStaysOnTopHint);
        dlgMsg.exec();
        return ;
    }
    // display new content
    vector<QString> vcetor;
    m_threadWork->m_store->getStore(vcetor);
    for (int var = 0; var < vcetor.size(); ++var) {
        ui->editStore->append(vcetor.at(var));
    }
}


void MainWindow::on_btnNext_clicked()
{
    m_threadWork->RunOneLine();
    ui->editStore->clear();
    vector<QString> vcetor;
    m_threadWork->m_store->getStore(vcetor);
    for (int var = 0; var < vcetor.size(); ++var) {
        ui->editStore->append(vcetor.at(var));
    }
}


void MainWindow::on_btnAuto_clicked()
{
    m_timer->start(1000);
}


void MainWindow::on_btnStop_clicked()
{
    m_timer->stop();
}

