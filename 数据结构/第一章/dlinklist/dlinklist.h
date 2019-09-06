#ifndef DLINKLIST_H_INCLUDED
#define DLINKLIST_H_INCLUDED

#include <iostream>

using namespace std;

//移除第i个，包括第0个；

class outofbounds{};;
class errorsize{};;
template<class elemtype>
class dlinklist
{
private:
    struct node
    {
        elemtype data;
        node *next, *prev;

        node(const elemtype&x, node*p=NULL, node*n=NULL)
        {
            data=x;
            next=n;
            prev=p;
        }

        node():next(NULL),prev(NULL){}
        ~node(){}
    };

    node *head,*tail;
    int currentsize;

    node *Move(int i)const
    {
        node *p=head->next;
        while(i--)
        {
            p=p->next;
        }
         return p;
    }

public:
    dlinklist()
    {
        head=new node;
        head->next=tail=new node;
        tail->prev=head;
        currentsize=0;
    }
    ~dlinklist(){Clear();delete head;delete tail;}

    void Clear()
    {
        node *p=head->next,*q;
        head->next=tail;
        tail->prev=head;
        while(p!=tail)
        {
          q=p;
          p=p->next;
          delete q;
         }
        currentsize=0;
    }

    int length()const{return currentsize;}

    void Insert(int i,const elemtype&x)
    {
        if(i>currentsize||i<0)throw errorsize();
         node *p=Move(i),*tmp;
         tmp=new node(x,p->prev,p);
         p->prev->next=tmp;
         p->prev=tmp;

         ++currentsize;
    }

    elemtype Remove(int i)
    {
        elemtype data;
        node *p=Move(i);
        p->prev->next=p->next;
        p->next->prev=p->prev;
   data=p->data;        delete p;

        --currentsize;
        return data;
    }

    int Search(const elemtype &x)
    {
        node *p=head->next;
        int i=0;

        while (p!=tail&&p->data!=x)
        {
            p=p->next;
            ++i;
        }
        if(p==tail)return -1;
        else return i;
    }

    void traverse()const
    {
        node *p=head->next;
        cout<<endl;
        while (p!=tail)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    void Find(int m,int k)
   {
      int data;
           for(int i=m-1;k--&&head->next!=NULL;i+=m-1)
           {
               if(i>=currentsize)
                i%=currentsize;
               data= Remove(i);
           }

       cout<<data;
       }
};


#endif // DLINKLIST_H_INCLUDED
