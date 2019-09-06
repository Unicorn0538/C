#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
#include <iostream>
using namespace std;

template<class elemtype>
class linkstack
{
private:
    struct node
    {
        elemtype data;
        node *next;

        node(const elemtype&x,node*n=NULL)
        {
            data=x;
            next=n;
        }
        node():next(NULL){};
    };

    node *Top;

public:
    linkstack();
    ~linkstack();
    bool isempty();
    void push(const elemtype &x);
    elemtype top()const;
    elemtype pop();
};


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
    if(Top==NULL)return;
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



#endif // LINKSTACK_H_INCLUDED
