#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED

class ERROR{};

template<class elemtype>
class seqqueue
{
private:
    elemtype *elem;
    int Front,Rear;
    int maxsize;
    void doublespace();
public:
    seqqueue(int inisize=10);
    ~seqqueue(){delete elem;}
    bool isempty()const;
    void enqueue(const elemtype &x);
    elemtype dequeue();
    elemtype gethead()const;

};

template<class elemtype>
seqqueue<elemtype>::seqqueue(int inisize)
{
    elem=new elemtype[inisize];
    Front=0;
    Rear=0;
    maxsize=inisize;
}

template<class elemtype>
bool seqqueue<elemtype>::isempty()const
{
    return Front==Rear;
}

template<class elemtype>
void seqqueue<elemtype>::enqueue(const elemtype &x)
{
    if((Rear+1)%maxsize==Front)doublespace();
    Rear=(Rear+1)%maxsize;
    elem[Rear]=x;
}

template <class elemtype>
elemtype seqqueue<elemtype>::dequeue()
{
    if(isempty())throw ERROR();
    Front=(Front+1)%maxsize;
    return elem[Front];
}

template<class elemtype>
elemtype seqqueue<elemtype>::gethead()const
{
    if(isempty())throw ERROR();
    return elem[Front];
}

template<class elemtype>
void seqqueue<elemtype>::doublespace()
{
    elemtype *tmp;
    tmp=elem;
    elem=new elemtype[maxsize*2];

    for(int i=0;i<maxsize;i++)
        elem[i]=tmp[(Front+i)%maxsize];
    Front=0;Rear=maxsize-1;
    maxsize=maxsize*2;
    delete tmp;
}

#endif // SEQQUEUE_H_INCLUDED
