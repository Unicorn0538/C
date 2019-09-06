#include "seqlist.h"

template<class elemtype>
seqlist<elemtype> :: seqlist(int inisize)
{
    if(inisize<=0)throw outofbound();
    maxsize=inisize;
    data=new elemtype[inisize];
    currentsize=0;
}

template<class elemtype>
void seqlist<elemtype>::doublesize()
{
    elemtype *tmp;
    tmp=new elemtype[maxsize*2];
    if(!tmp)throw ilegalsizze();
    for(int i=0;i<currentsize;i++)
        tmp[i]=data[i];
    delete [] data;
    data = tmp;
}



template<class elemtype>
int seqlist<elemtype>::Search(const elemtype&x)const
{
    for(int j=0;j<currentsize;j++)
    {
        if(data[j]==x)return j;
    }
    return -1;
}

template<class elemtype>
void seqlist<elemtype>::Insert(int i,const elemtype&x)
{
    if(i<0||i>currentsize)throw ilegalsizze();
    if(currentsize>=maxsize)doublesize();
    for(int j=currentsize;j>i;j--)
    {
        data[j]=data[j-1];
    }
    data[i]=x;
    currentsize++;
}

template<class elemtype>
elemtype seqlist <elemtype>::visit(int i)const
{
    if(i<0||i>currentsize)
        throw ilegalsizze();
    return data[i];
}

template<class elemtype>
void seqlist <elemtype>::Remove(int i)
{
    if(i>=currentsize||i<0)throw ilegalsizze();
    for(int j=i;j<currentsize;j++)
        data[j]=data[j+1];
    currentsize--;
}

template <class elemtype>
void seqlist<elemtype>::Clear()
{
    currentsize=0;
}

template <class elemtype>
void seqlist<elemtype>::traverse()const
{
    for(int i=0;i<currentsize;i++)
        cout<<data[i]<<" ";
}

template <class elemtype>
int seqlist <elemtype> :: length()const
{
    return currentsize;
}

