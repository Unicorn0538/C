#include <iostream>
using namespace std;

template<class KEY,class OTHER>
struct SET
{
   KEY key;
   OTHER other;
};

template<class KEY,class OTHER>
class openhashtable
{
   struct hashnode
   {
      SET<KEY,OTHER>data;
      node *next;

      node (const SET<KEY,OTHER>&d,node *n = NULL){data = d;next = n;}
      node(){next = NULL;}
   };

   hashnode **array;
   int size;
   int (*key)(const KEY &x);
   static int defaultkey(const int &x){return x;}

   public:
   openhashtable(int length=101,int (*f)(const KEY &x)=defaultkey)
   {size = legth;array = new hashnode*[size];key = f;for(int i=0;i<size;++i)array[i]=NULL;}
   ~openhashtable();
   SET<KEY,OTHER>*find(const KEY &x)const;
   void insert(const SET<KEY,OTHER>&x);
   void remove(const KEY &x);
};

template<class KEY,class OTHER>
openhashtable<KEY,OTHER>::~openhashtable()
{
    hashnode *p,*q;
    for(int i=0;i<size;i++)
    {
        p=array[i];
        while(p!=NULL){q = p->next;delete p;p=q;}
    }
    delete []array;
}

template<class KEY,class OTHER>
void openhashtable<KEY,OTHER>::insert(const SET<KEY,OTHER>&x)
{
    int pos;  hashnode *p;

    pos = key(x.key)%size;
    array[pos] = new hashnode (x,array[pos]);
}

template<class KEY,class OTHER>
void openhashtable<KEY,OTHER>::remove(const KEY &x)
{
    int pos;
    node *p,*q;
    pos = key(x)%size;
    if(array[pos]==NULL)return;
    p = array[pos];
    if(array[pos]->data.key==x)
    {
        array[pos]=p->next;
        delete p;
        return;
    }

    while(p->next!=NULL&&!(p->next->data.key==x))p=p->next;
    if(p->next!=NULL)
    {
        q = p->next;
        p->next = q->next;
        delete p;
    }
}

template<class KEY,class OTHER>
SET<KEY,OTHER>*openhashtable<KEY,OTHER>::find(const KEY &x)const
{
   int pos;
   hashnode *p;

   pos = key(x)%size;
   p=array[pos];
   while(p!=NULL&&!(p->data.key==X))p=p->next;
   if(p==NULL)return NULL;
   else return (SET<KEY,OTHER>*)p;
}

int main()
{
    openhashtable ;
}