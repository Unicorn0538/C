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
    linkstack(){ Top=NULL;}

    ~linkstack()
    {
      node *tmp;
      while(Top)
       {
        tmp=Top;
        Top=Top->next;
        delete tmp;
       }
    }

    bool isempty()
    {
         return Top==NULL;
    }

    void push(const elemtype &x)
    {
        Top=new node(x,Top);
    }

    elemtype top()const
    {
    if(Top==NULL)return;
    return Top->data;
    }

    elemtype pop()
    {
     if(Top==NULL)return -1;
    node*tmp=Top;
    Top=Top->next;
    elemtype x=tmp->data;
    delete tmp;
    return x;
    }
};


#endif // LINKSTACK_H_INCLUDED
