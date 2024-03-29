#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <iostream>

using namespace std;

class outofbound{};

class errorsize{};

template<class elemtype>
class linklist
{
private:
    struct node
    {
        elemtype data;
        node *next;
        node(const elemtype&x , node*p=NULL)
        {
            data=x;
            next=p;
        }
        node():next(NULL){};
    };
    node *head;
    int Size;

protected:
    node *get(int i)const  //获取第i个节点
    {
        if(i<0) return head;
        node*p=head->next;
        for(int j=0;j<i;j++)
        {
            p=p->next;
        }
        return p;
    }

public:
    linklist():Size(0){head=new node;}
    ~linklist(){Clear();delete head;}

    int length()
    {
        return Size;
    }

    int Search(const elemtype &x)const
    {
        node *p=head->next;
        for(int i=0;p;++i)
        {
            if(x==p->data)return i;
            p=p->next;
        }
        return -1;
    }

    elemtype visit(int i)const
    {
        return get(i)->data;
    }

    void Insert(int i,const elemtype&x)
    {
        node *p=get(i-1);
        p->next=new node (x,p->next);
        ++Size;
    }

    void Remove(int i)
    {
        node *p=get(i-1);
        node *q=p->next;
        p->next=q->next;
        delete q;
        -- Size;
    }

    void Clear ()
    {
        while (length()>0)
            Remove(0);
    }

    void traverse()const
    {
        node *p=head->next;
        while (p)
        {
            cout<<p->data<<'\t';
            p=p->next;
        }
    }

    //void Reverse()
};

#endif // LINKLIST_H_INCLUDED
