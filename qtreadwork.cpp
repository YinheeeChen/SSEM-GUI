
#include "qtreadwork.h"
#include "Util.h"

QTreadWork::QTreadWork()
{
    m_store=new Store(STORE,REGISTER);
    m_processor=new Processor(REGISTER);
}

QTreadWork::~QTreadWork()
{
    if(NULL!=m_store)
    {
        delete m_store;
    }

    if(NULL!=m_processor)
    {
        delete m_processor;
    }
}

void QTreadWork::RunOneLine()
{
    m_processor->increaseCI();
    m_processor->setPi(m_store->getInstruction(m_processor->binToDec(m_processor->getCi()))); //Fetch
    m_processor->decodeOP(); //Decode
    if(!execute(*m_processor, *m_store))//Execute
    {
        emit Show(m_processor->getstrAcc(),m_processor->getstrCi(),m_processor->getstrPi(),m_processor->getOpcode(),m_processor->getOperand());
        return;
    }
    m_store->clearStore();
    emit Finally();
}

