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
    void buildheap();    //构造最小化堆
    void percolateDown(int hole);  //将hole放入何时的位置

    public:
    priorityqueue(int capacity=100);
    priorityqueue(const elemtype data[],int size);
    ~priorityqueue() {delete [] array;}
    bool isempty()const {return cur == 0;}
    void enqueue(const elemtype &x);   //进队
    int  find(elemtype x);      //寻找优先级值比x大的最小元素的下标
    void dicrease(int i,elemtype x);   //将下标为i的元素减去x
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
        if(child != cur && array[child+1] < array[child])
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
int priorityqueue<elemtype>::find(elemtype x)  //顺序查找比x最小的值
{
    int min=0;
    for(int i=1;i<cur+1;i++)
     {
        if(array[i]>x)
        {min=i;
         for(;i<cur+1;i++)
         if(array[i]>x&&array[i]<array[min])
             min=i;
        }
     }
    if(min==0)return -1;
    else return min;
}

template<class elemtype>
void priorityqueue<elemtype>::dicrease(int i,elemtype x)
{
    array[i]-=x;
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
       cin.get();
       cin.getline(ch,10,' ');
       cin>>tmp1;
       if(strcmp("insert",ch)==0)p.enqueue(tmp1);
       if(strcmp("find",ch)==0){ int a=p.find(tmp1);cout<<a<<endl;}
       if(strcmp("dicrease",ch)==0){cin>>tmp2;p.dicrease(tmp1,tmp2);}
    }
    return 0;
}

//解题与拓展上找出最大元素和将堆中第i个节点的值减小value的函数
/*template <class elemtype>
int priorityqueue<elemtype>::find(elemtype x)
{
    elemtype Min;
    int ID = -1;

    for(int i=1; i<=cur;++i)
      if(array[i]>=X&&((Min == -1)||array[i]<Min))
      {
          Min = array[i];
          ID = i;
      }
    return ID;
}

template <class elemtype>
void priorityqueue<elemtype>::dicrease(int i,elemtype value)
{
   elemtype x;
   int hole;

   array[hole = i] -= value;
   for(x = array[i];hole>1&&x<array[hole/2];hole/2)
      array[hole] = array[hole/2];
   array[hole] = x;
}*/

//最小背包问题
/*int main()
{
    int n,num=0;
    double *ar;
    priorityqueue<double> myqueue;

    //初始化
    cout<<"请输入一共多少项：/n";
    cin>>n;
    ar = new double [n];
    cout<<"请输入每项的数量：/n";

    for(int i=0; i<n;i++)
    {
        cin>>ar[i];
        myqueue.enqueue(1.0);
    }

    for(int i=0;i<n;i++)
    {
        myqueue.dicrease(myqueue.find(ar[i]),ar[i]);
        while(!myqueue.isempty())
        if(myqueue.gethead==0){++num;myqueue.dequeue();}
    }
    while(!myqueue.isempty())
    if(myqueue.dequeue()<1.0)++num;

    cout<<num;
    delete []ar;
}
*/
