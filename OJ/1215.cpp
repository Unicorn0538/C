#include <iostream>
using namespace std;

template <class elemtype>
class bernoulli
{
    private:
    struct node  //定义树的节点
    {
        elemtype data;
        node *brother;
        node *son;
        node(const elemtype&x , node*b=NULL,node *s=NULL)
        {
            data=x;
            brother=p;
            son=s;
        }
        node():next(NULL){};
    };

    node **rootarray;  //存放树的根root
    int Maxsize;
    int Cur;

    void clear(node *r)
    {
        if(r==NULL)return;   
        clear(r->brother);
        clear(r->son);
        delete r;
        r=NULL;
    }
    node *merge(node *t1,node *t2)
    {
        node *p;
        if(t1->data)
    }

    public:
    bernoulli(int maxroot=100);  
    ~bernoulli();
    void insert(elemtype x);
    void remove();
    void searchmin();
    void merge(bernoulli &other);
    
};

template <class elemtype>
bernoulli<elemtype>::bernoulli(int maxroot)  
{
    Rootarray = new node *[maxroot];
    Maxsize=maxrooot;
    Cur=0;
}

template <class elemtype>
bernoulli<elemtype>::~bernoulli()
{
   for(int i=0;i<Maxsize;i++)
      clear(rootarray[i]);
   delete [] rootarray; 
}

template <class elemtype>
void bernoulli<elemtype>::insert(elemtype x)
//插入一个节点
{
      
}

template <class elemtype>
void bernoulli<elemtype>::remove()
//删除最小值
{
   
}

template <class elemtype>
void bernoulli<elemtype>::searchmin()
//找最小值
{
   
}

template <class elemtype>
void bernoulli<elemtype>::merge(bernoulli &other)
//归并当前Bernoulli堆和other Bernoulli堆
{
    
}
