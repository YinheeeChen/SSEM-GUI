
#ifndef QTREADWORK_H
#define QTREADWORK_H
#include "Processor.h"
#include "Store.h"
#include <QObject>



class QTreadWork : public QObject
{
    Q_OBJECT
public:
    QTreadWork();
    ~QTreadWork();

private:

public:
    Store* m_store;
    Processor* m_processor;
private:

public:
    void LoadFile(QString strPath);
public slots:
    void RunOneLine();
signals:
    void Show(QString strAcc,QString strPi,QString strCi,int iOpcode,int iOperand);
    void Finally();
};

#endif // QTREADWORK_H
