//排列系统的模拟
//第七章优先级队列

#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
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
        if(child!=cur&&array[child+1]<array[child])
             child++;
        if(array[child]<tmp)
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
    for(; hole > 1 && x < array[hole/2]; hole /= 2)
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

class ERROR{};

template<class elemtype>
class linkqueue
{
private:
    struct node
    {
     elemtype data;
        node *next;
        node(const elemtype&x,node *ne=NULL)
        {
            data=x;
            next=ne;
        }
        node():next(NULL){}
        ~node(){}

    };

    node *Front,*Rear;

public:
    linkqueue()
    {
        Front=Rear=NULL;
    }

    ~linkqueue()
    {
        node *tmp;
        while(Front)
        {
          tmp=Front;
          Front=Front->next;
          delete tmp;
         }
    }

    bool isempty()const
    {
        return Front==NULL;
    }

    void enqueue(const elemtype&x)
    {
        if(isempty())Rear=Front=new node(x);
        else
        {
           Rear->next=new node(x);
           Rear=Rear->next;
        }
    }

 elemtype dequeue()
    {
       node *tmp=Front;
     elemtype Tmp=Front->data;
       Front=Front->next;
       if(Front==NULL)Rear=NULL;
       delete tmp;
       return Tmp;
    }

 elemtype gethead()const
    {
        if(isempty())return 0;
        return Front->data;
    }
};

class simulator
{
    int noofserver;      //服务台个数
    int arrivallow;     //到达间隔时间的下界
    int arrivalhigh;    //到达间隔时间的上界
    int servisetimelow;  //服务间隔时间的下界
    int servisetomehigh; //服务间隔时间的上界
    int customnum;       //模拟的顾客数

    struct evenT
    {
       int time;  //事件发生时间
       int type;  //事件类型 0为到达，1为离开
       bool operator<(const evenT&e)const {return time<e.time;}
    } ;

    public:
     simulator();
     int avgwaittime();
};

simulator::simulator()
{
    cout<<"please input the num of server:";
    cin>>noofserver;
    cout<<"please input the low and high time of arrival:";
    cin>>arrivallow>>arrivalhigh;
    cout<<"please input the low and high time of service:";
    cin>>servisetimelow>>servisetomehigh;
    cout<<"please input the num of customs";
    cin>>customnum;

    srand(time(NULL));  //随机数发生器变化
}

int simulator::avgwaittime()
{
    int serverbusy =0;
    int currenttime;
    int totalwaittime = 0;
    linkqueue<evenT>waitqueue;
    priorityqueue<evenT>eventqueue;

    evenT currentevent;

    int i;
    currentevent.time=0;
    currentevent.type=0;
    for(i=0;i<customnum;++i)
    {
        currentevent.time += arrivallow+(arrivalhigh-arrivallow+1)*rand()/(RAND_MAX+1);
        eventqueue.enqueue(currentevent);
    }

    while(!eventqueue.isempty())
    {
        currentevent =eventqueue.dequeue();
        currenttime = currentevent.time;
        switch(currentevent.type)
        {
            case 0:
            if(serverbusy!=noofserver)
            {
                ++serverbusy;
                currentevent.time += servisetimelow+(servisetomehigh-servisetimelow+1)*rand()/(RAND_MAX+1);
                currentevent.type =1;
                eventqueue.enqueue(currentevent);
            }

            else waitqueue.enqueue(currentevent);
            break;

            case 1:
            if(!waitqueue.isempty())
            {
                currentevent = waitqueue.dequeue();
                totalwaittime += currenttime-currentevent.time;
                currentevent.time = currenttime + servisetimelow+(servisetomehigh-servisetimelow+1)*rand()/(RAND_MAX+1);
                currentevent.type = 1;
                eventqueue.enqueue(currentevent);
            }
            else --serverbusy;
        }
    }
    return totalwaittime/customnum;

}

int main()
{
    simulator sim;
    cout<<"the average waiting time is:"<<sim.avgwaittime()<<endl;

    return 0;
}