//最大化堆
#include<iostream>
using namespace std;

template<class elemtype>
class priorityqueue
{
    private:
    int cur;
    elemtype *array;
    int maxsize;

    void doublespace();
    void buildheap(); //由无序数列构建一个堆
    void percolateDown(int hole);  //将第hole个节点的数放到合适的位置

    public:
    priorityqueue(int capacity=100);
    priorityqueue(const elemtype data[],int size);
    ~priorityqueue() {delete [] array;}
    bool isempty()const {return cur == 0;}
    void enqueue(const elemtype &x);
    elemtype dequeue();
    elemtype gethead()const {return array[1];}
};

template<class elemtype>
void priorityqueue<elemtype>::doublespace()
{
    elemtype *tmp=array;
    array = new elemtype[maxsize*2];
    for(int i = 0; i < cur; ++ i)
        array[i] = tmp[i];
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
    elemtype tmp =  array[hole];
      
    for(; hole*2 <= cur; hole = child)
    {
        child = hole*2;
        if(child!=cur&&array[child+1]>array[child])
             child++;
        if(tmp<array[child])
             array[hole]=array[child];
        else break;
    }
    array[hole] = tmp;
}

template <class elemtype>
priorityqueue<elemtype>::priorityqueue(int capacity)
{
    array = new elemtype[capacity];
    maxsize = capacity;
    cur = 0;
}

template <class elemtype>
priorityqueue<elemtype>::priorityqueue(const elemtype data[], int size)
{
    maxsize = size + 10;
    cur = size;
    array = new elemtype [maxsize];

    for(int i = 0; i < size ; i++)
        array[i+1] = data[i];
    buildheap();     
}

template <class elemtype>
void priorityqueue<elemtype>::enqueue(const elemtype &x)
{
    if(maxsize-1 == cur) doublespace();

    int hole = ++cur;
    for(; hole > 1 && x > array[hole/2]; hole /= 2)
         array[hole] = array[hole/2];
    array[hole] = x;
}

template <class elemtype>
elemtype priorityqueue<elemtype>::dequeue()
{
    elemtype tmp = array[1];
    array[1] = array[cur];
    cur--;
    percolateDown(1);
    return tmp;
}



int main()
{
    priorityqueue<int> p;
    for(int i=0;i<10;i++)
        p.enqueue(i*2);
    p.enqueue(5);
    p.enqueue(7);
    p.enqueue(18);
    p.enqueue(21);
    for(int i= 0;i<14;i++)
        cout<<p.dequeue()<<" ";
    return 0;    
}