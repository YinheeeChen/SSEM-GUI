#include "qnextdialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

QNextDialog::QNextDialog(QWidget *parent)
    : QBaseDialog{parent}
{
    InitDialog();
}

void QNextDialog::InitDialog()
{
    QLabel* label=new QLabel(this);
    label->setText(QStringLiteral("Done!"));

    QPushButton* btnTry=new QPushButton(this);
    btnTry->setText("Re-try");
    QPushButton* btnExit=new QPushButton(this);
    btnExit->setText("Exit");
    QVBoxLayout* vblayAll=new QVBoxLayout(this);
    vblayAll->addWidget(label);
    vblayAll->addWidget(btnTry);
    vblayAll->addWidget(btnExit);
    connect(btnTry,&QPushButton::clicked,this,[=](){
        this->accept();
    });
    connect(btnExit,&QPushButton::clicked,this,[=](){
        this->close();
    });
}
