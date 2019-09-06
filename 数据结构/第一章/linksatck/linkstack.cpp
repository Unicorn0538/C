#include "linkstack.h"
template<class elemtype>
linkstack<elemtype>::linkstack()
{
    Top=NULL;
}

template<class elemtype>
linkstack<elemtype>::~linkstack()
{
    node *tmp;
    while(Top)
    {
        tmp=Top;
        Top=Top->next;
        delete tmp;
    }
}

template<class elemtype>
bool linkstack<elemtype>::isempty()
{
   return Top==NULL;
}

template<class elemtype>
void linkstack<elemtype>::push(const elemtype&x)
{
    Top=new node(x,Top);
}

template<class elemtype>
elemtype linkstack<elemtype>::pop()
{
    if(Top==NULL)return -1;
    node*tmp=Top;
    Top=Top->next;
    elemtype x=tmp->data;
    delete tmp;
    return x;
}

template<class elemtype>
elemtype linkstack<elemtype>::top()const
{
    if(Top==NULL)return;
    return Top->data;
}
