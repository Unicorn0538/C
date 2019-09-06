//闭散列表
#include <iostream>
using namespace std;

template<class KEY,class OTHER>
struct SET
{
    KEY key;
    OTHER other;
};

template<class KEY,class OTHER>
class closehashtable
{
   private:
   struct hashnode
   {
      SET<KEY, OTHER> data;
      int state;

      hashnode(){state = 0;}
   };

   hashnode *array;
   int size;
   int (*key)(const KEY &x);
   static int defaultkey(const int &x){return x;}

   public:
   closehashtable(int length=101,int (*f)(const KEY &x)=defaultkey)
   {size = legth;array = new hashnode[size];key = f;}
   ~closehashtable(){delete[]array;}
   SET<KEY,OTHER>*find(const KEY &x)const;
   void insert(const SET<KEY,OTHER>&x);
   void remove(const KEY &x);
};

template<class KEY,class OTHER>
void closehashtable<KEY,OTHER>::insert(const SET<KEY,OTHER>&x)
{
    int initpos,pos;

    initpos = pos = key(x.key)%size;
    do
    {
        if(array[pos].state!=1)
        {
            array[pos].data = x;
            array[pos].state = 1;
            return;
        }
        pos = (pos+1)%size;
    }while(pos!=initpos);
}

template<class KEY,class OTHER>
void closehashtable<KEY,OTHER>::remove(const KEY &x)
{
    int initpos , pos;

    initpos = pos =key(x)%size;
    do
    {
        if(array[pos].state == 0)return;
        if(array[pos].state == 1&&array[pos].data.key == x)
        {
            array[pos]=2;
            return;
        }
        pos = (pos+1)%size;
    } while (pos!=inipos);
}

template<class KEY,class OTHER>
SET<KEY,OTHER>*closehashtable<KEY,OTHER>::find(const KEY &x)const
{
    int initpos,pos;
    inipos = pos = key(x)&size;

    do
    {
        if(array[pos].state==0)return NULL;
        if(array[pos].state==1&&array[pos].data.key==x)
           return (SET<KEY,OTHER>*)&array[pos];
        pos = (pos+1)%size;
    } while (pos != initpos);    
}
