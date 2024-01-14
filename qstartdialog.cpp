#include "qstartdialog.h"
#include "qlabel.h"
#include <QVBoxLayout>
#include<QPushButton>
QStartDialog::QStartDialog(QWidget *parent)
    : QBaseDialog{parent}
{
    InitDialog();
}

void QStartDialog::InitDialog()
{
    QLabel* labelTitle=new QLabel(this);
    labelTitle->setText("Manchester Baby");
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setObjectName("Title");
    labelTitle->setMinimumSize(400,200);
    labelTitle->setStyleSheet("font-size: 30px;");


    QPushButton* btnStart=new QPushButton(this);
    btnStart->setText("Start");

    QPushButton* btnExit=new QPushButton(this);
    btnExit->setText("Exit");

    QVBoxLayout* vlayBtn=new QVBoxLayout();
    vlayBtn->addWidget(btnStart);
    vlayBtn->addWidget(btnExit);
    vlayBtn->setContentsMargins(80,10,80,10);

    QVBoxLayout* vlayAll=new QVBoxLayout(this);
    vlayAll->addWidget(labelTitle);
    vlayAll->addLayout(vlayBtn);
    connect(btnStart,&QPushButton::clicked,this,[&](){
        this->accept();
    });
    connect(btnExit,&QPushButton::clicked,this,[&](){
        this->close();
    });

}
