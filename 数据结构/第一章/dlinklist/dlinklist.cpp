#include "dlinklist.h"

template<class elemtype>
dlinklist<elemtype>::dlinklist()
{
    head=new node;
    head->next=tail=new node;
    tail->prev=head;
    currentsize=0;
}

template <class elemtype>
void dlinklist<elemtype>::Clear()
{

}

template<class elemtype>//插入从零开始计数，可插入第零个节点；
void dlinklist<elemtype>::Insert(int i,const elemtype &x )
{

}

template <class elemtype>
void dlinklist<elemtype>::Remove(int i)
{
    if(i<0||i>currentsize)throw errorsize();
    node *p=head->next;
    for(int j=0;j<i;j++)
    {
        if(p->next!=NULL)throw outofbounds();
        p=p->next;
    }
    node *tmp;
    tmp=p;
    p->prev->next=p->next;
    p->next->prev=p->prev;
    delete tmp;
}

template <class elemtype>
int dlinklist<elemtype>::Search(const elemtype&x)
{
    node *p=head->next;
   for(int i=0;i<currentsize;i++)
   {
       if(p->data==x)return i+1;
       else p=p->next;
   }
   return 0;
}

template<class elemtype>
elemtype dlinklist<elemtype>::visit(int i)const
{
    if(i>currentsize||i<1)throw errorsize();
    node*p=head->next;
    for(int j=0;j<i;i++)
    {
        p=p->next;
    }
    return p->data;
}

template<class elemtype>
void dlinklist<elemtype>::traverse()const
{
    node *p=head->next;
    for(int i=0;i<currentsize;i++)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
