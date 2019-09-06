#include "linklist.h"

template<class elemtype>
linklist<elemtype>::linklist()
{
    head = new node ;
}

template<class elemtype>
int linklist<elemtype>::length()
{
    node*p;
    int length=0;
    p=head->next;
    while(p)
    {
        length++;
        p=p->next;
    }
    return length;
}

template<class elemtype>
int linklist<elemtype>::Search(const elemtype &x)const
{
    int num=0;
    node*p;
    p=head->next;
    while(p)
    {
        num++;
        if(p->data==x)return num;
        p=p->next;
    }
    return -1;
}

template <class elemtype>
elemtype linklist<elemtype>::visit(int i)const
{
    if(i<0) throw outofbound();
    node*p;
    p=head->next;
    for(int j=0;j<i-1;j++)
    {
        if(!p) throw errorsize();
        p=p->next;
    }
    if(!p) throw errorsize();
    return p->data;
}

template<class elemtype>
void linklist<elemtype>::Insert(int i,const elemtype &x)
{
    if(i<0)throw outofbound();
    node *p;
    p=head;
    for(int j=0;j<i-1;j++)
    {
        if(!p)throw errorsize();
        p=p->next;
    }
    node*tmp;
    tmp->data=x;
    tmp->next=p->next;
    p->next=tmp;
}

template <class elemtype>
void linklist<elemtype>::Remove(int i)
{
    if(i<0)throw outofbound();
    node*p;
    p=head;
    for(int j=0;j<i-1;j++)
    {
        if(!p)throw outofbound();
        p=p->next;
    }
    node*tmp;
    tmp=p->next;
    if(tmp->next==NULL)p->next=NULL;
    else p->next=tmp->next;
    delete tmp;
}

template<class elemtype>
void linklist<elemtype>::Clear()
{
    node *p,*q;
    p=head->next;
    head->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        delete q;
    }
}

template<class elemtype>
void linklist<elemtype>::traverse()const
{
    node*p;
    p=head->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

template<class elemtype>
void linklist<elemtype>::Reverse()
{
    if(head->next)throw outofbound();
    node *q,*p;
    p=head->next;
    head->next=NULL;

    while(p)
    {
        q=p;
        p=p->next;
        q->next=head->next;
        head->next=q;
    }


}
