#include <iostream>
#include <cstring>
using namespace std;

template<class elemtype>
class priorityqueue
{
    private:
    int cur;
    elemtype *array;
    int maxsize;

    void doublespace();
    void buildheap();    //������С����
    void percolateDown(int hole);  //��hole�����ʱ��λ��

    public:
    priorityqueue(int capacity=100);
    priorityqueue(const elemtype data[],int size);
    ~priorityqueue() {delete [] array;}
    bool isempty()const {return cur == 0;}
    void enqueue(const elemtype &x);   //����
    elemtype  findmin();      //Ѱ�����ȼ�ֵ��x�����СԪ�ص��±�
    void dequeue();  //���±�Ϊi��Ԫ�ؼ�ȥx
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
        child = hole *2;
        if(child != cur &&
         array[child+1] < array[child])
           child ++;
        if(array[child] < tmp)array[hole] = array[child];
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
    for(; hole > 1 && x < array[hole/2]; hole /= 2)
         array[hole] = array[hole/2];
    array[hole] = x;
}

template <class elemtype>
elemtype priorityqueue<elemtype>::findmin()  //˳����ұ�x��С��ֵ
{
    return array[1];
}

template<class elemtype>
void priorityqueue<elemtype>::dequeue()
{
    if(cur==0)return;

    array[1]=array[cur--];
    percolateDown(1);
}

int main()
{
    ios::sync_with_stdio(false);

    priorityqueue<int > p;
    int N,tmp;
    char *ch;
    ch = new char[10];

    cin>>N;
    cin.get();
    while(N--)
    {

       cin>>ch;
       if(strcmp("insert",ch)==0) {cin>>tmp;p.enqueue(tmp);}
       if(strcmp("min",ch)==0){ int a=p.findmin();cout<<a<<endl;}
       if(strcmp("delete",ch)==0){p.dequeue();}
    }
    return 0;
}
