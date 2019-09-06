#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED


#include <iostream>

using namespace std;

class outofbound{};
template <class elemtype>
class seqstack
{
private:
    int Top;
    elemtype *elem;
    int maxsize;

    void doublespace();

public:
    seqstack (int inisize=10);
    ~seqstack(){delete elem;}
    elemtype top()const;
    void push(const elemtype&x);
    elemtype pop();
    bool isempty()const;
};

#include "seqstack.h"

template<class elemtype>
seqstack<elemtype>::seqstack(int inisize)
{
    maxsize=inisize;
    elem=new elemtype[inisize];
    Top=-1;
}

template <class elemtype>
void seqstack<elemtype>::doublespace()
{
    elemtype *tmp=elem;

    elem=new elemtype[maxsize*2];

    for(int i=0;i<maxsize;i++)
    {
        elem[i]=tmp[i];
    }
    delete tmp;
}

template <class elemtype>
void seqstack<elemtype>::push(const elemtype &x)
{
     if(Top==maxsize)doublespace();
     elem[++Top]=x;
}

template <class elemtype>
elemtype seqstack<elemtype>::pop()
{
    if(isempty())throw outofbound();
    elemtype d;
    d=elem[Top];
    Top--;
    return d;
}

template<class elemtype>
elemtype seqstack<elemtype>::top()const
{

    return elem[Top];
}

template <class elemtype>
bool seqstack<elemtype>::isempty()const
{
    return Top==-1;
}

#endif // SEQSTACK_H_INCLUDED
