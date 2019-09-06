#include <iostream>
using namespace std;



template<class type>
class openhashtable
{
   struct hashnode
   {
      type data;
      node *next;

      node (const type&d,node *n = NULL){data = d;next = n;}
      node(){next = NULL;}
   };

   hashnode **array;
   int size;
   int (*key)(const type &x);
   static int defaultkey(const int &x){return x;}

   public:
   openhashtable(int length=101,int (*f)(const type &x)=defaultkey)
   {size = legth;array = new hashnode*[size];key = f;for(int i=0;i<size;++i)array[i]=new hashnode;}
   ~openhashtable();
   bool find(const type &x)const;
   void insert(const type&x);
   void remove(const type &x);
};

template<class type>
openhashtable<type>::~openhashtable()
{
    hashnode *p,*q;
    for(int i=0;i<size;i++)
    {
        p=array[i];
        while(p!=NULL){q = p->next;delete p;p=q;}
    }
    delete []array;
}

template<class type>
void openhashtable<type>::insert(const type&x)
{
    int pos;  hashnode *p;

    pos = key(x)%size;
    p = array[pos] -> next;
    while(p!=NULL&&p->data!=x)p=p->next;
    if(p==NULL)
    {
        p=new hashnode(x);
        p->next = array[pos]->next;
        array[pos]->next=p;
    }
}

template<class type>
void openhashtable<type>::remove(const type &x)
{
    int pos;
    node *p,*q;
    pos = key(x)%size;
    if(array[pos]==NULL)return;
    p = array[pos];
    if(array[pos]->data==x)
    {
        array[pos]=p->next;
        delete p;
        return;
    }

    while(p->next!=NULL&&!(p->next->data==x))p=p->next;
    if(p->next!=NULL)
    {
        q = p->next;
        p->next = q->next;
        delete p;
    }
}

template<class type>
bool openhashtable<type>::find(const type &x)const
{
   int pos;
   hashnode *p;

   pos = key(x)%size;
   p=array[pos];
   while(p->next!=NULL&&!(p->next->data==X))p=p->next;
   if(p->next==NULL)return true;
   else return false;
}

int main()
{
    
}