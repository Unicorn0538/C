#include <iostream>
#include <cstring>
using namespace std;

template<class elemtype>
class priorityqueue
{
    private:
    int cur;
    elemtype *Array;
    int maxsize;

    void doublespace();
    void buildheap();
    void percolateDown(int hole);

    public:
    priorityqueue(int capacity=100);
    priorityqueue(const elemtype data[],int Size);
    ~priorityqueue() {delete [] Array;}
    bool isempty()const {return cur == 0;}
    void enqueue(const elemtype &x);
    int  Find(elemtype x);
    void dicrease(int i,elemtype x);
    elemtype gethead()const {return Array[1];}
};

template<class elemtype>
void priorityqueue<elemtype>::doublespace()
{
    elemtype *tmp=Array;
    Array = new elemtype[maxsize*2];
    for(int i = 0; i < cur; ++ i)
        Array[i] = tmp[i];
    delete [] tmp;
    maxsize *= 2;
}

template <class elemtype>
void priorityqueue<elemtype>::buildheap()
{
    for(int i = cur/2; i > 0; i --)
       percolateDown(i);
}

template <class elemtype>
void priorityqueue<elemtype>::percolateDown(int hole)
{
    int child;
    elemtype tmp =  Array[hole];

    for(; hole*2 <= cur; hole = child)
    {
        child = hole *2;
        if(child < cur && Array[child+1] < Array[child])
           child ++;
        if(Array[child] < tmp)Array[hole] = Array[child];
        else break;
    }
    Array[hole] = tmp;
}

template <class elemtype>
priorityqueue<elemtype>::priorityqueue(int capacity)
{
    Array = new elemtype[capacity];
    maxsize = capacity;
    cur = 0;
}

template <class elemtype>
priorityqueue<elemtype>::priorityqueue(const elemtype data[], int Size)
{
    maxsize = Size + 10;
    cur = Size;
    Array = new elemtype [maxsize];

    for(int i = 0; i < Size ; i++)
        Array[i+1] = data[i];
    buildheap();
}

template <class elemtype>
void priorityqueue<elemtype>::enqueue(const elemtype &x)
{
    if(maxsize-1 == cur) doublespace();

    int hole = ++cur;
    for(; hole > 1 && x < Array[hole/2]; hole /= 2)
         Array[hole] = Array[hole/2];
    Array[hole] = x;
}

template <class elemtype>
int priorityqueue<elemtype>::Find(elemtype x)
{
   int Min=0;
    for(int i=1;i<cur+1;i++)
     {
        if(Array[i]>x&&(Min==0||Array[i]<Array[Min]))
        {
           Min=i;
        }
     }
    if(Min==0)return -1;
    else return Min;
}

template<class elemtype>
void priorityqueue<elemtype>::dicrease(int i,elemtype x)
{
    Array[i]-=x;
    buildheap();
}

int main()
{
    ios::sync_with_stdio(false);

    priorityqueue<int > p;
    int N,tmp1,tmp2;
    char *ch;
    ch = new char[10];

    cin>>N;
    while(N--)
    {
       cin>>ch;
       cin>>tmp1;
       if(strcmp("insert",ch)==0)p.enqueue(tmp1);
       if(strcmp("find",ch)==0){ int a=p.Find(tmp1);cout<<a<<endl;}
       if(strcmp("decrease",ch)==0){cin>>tmp2;p.dicrease(tmp1,tmp2);}
    }
    return 0;
}
