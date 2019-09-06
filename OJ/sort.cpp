#include <iostream>
using namespace std;

//直接插入排序
//时间复杂度为O（N^2）
template <class elemtype>
void simplesort(elemtype a[],int size)
{
    int k;
    elemtype tmp;

    for(int j=1;j<size;j++)
    {
        tmp = a[j];
        for(k=j-1;tmp<a[k]&&k>=0;--k)a[k+1]=a[k];
        a[k+1]=tmp;
    }
}

//希尔排序
//时间复杂度为O（N^(3/2)）
template<class elemtype>
void shellsort(elemtype a[],int size)
{
    int step,i,j;
    elemtype tmp;

    for(step = size/2;step>0;step/=2)
       for(i = step; i<size;i++)
       {
           tmp=a[i];
           for(j=i-step;j>=0&&a[j]>tmp;j-=step)
           a[j+step]=a[j];
           a[j+step] = tmp;
       }
}

//选择排序
//算法复杂度为O（N^2）
template <class elemtype>
void simpleselectsort(elemtype a[],int size)
{
    int i,j,k;
    elemtype tmp;

    for( i=0;i<size;i++)
    {
        k = i;
        for(j=i+1;j<size;j++)
           if(a[j]<a[k])k=j;
        tmp = a[j];
        a[j] = a[k];
        a[k] = tmp;
    }
}

//堆排序
//算法复杂度O（NlogN）不稳定的排序
template <class elemtype>
void heapsort(elemtype a[],int size)
{
    int i;
    elemtype tmp;
    
    for(i=size/2-1;i>=0;i--)percolate(a,i,size);

    for(i=size-1;i>0;--i)
    {
         tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        percolate(a,0,i);
    }
}

template<class elemtype>
void percolate(elemtype a[],int hole,int size)
{
    int child ;
    elemtype tmp = a[hole];

    for( ; hole*2+1<size; hole = child)
    {
        child = hole*2+1;
        if(child!=size-1&&a[child+1]>a[child])++child;
        if(a[child]>tmp)a[hole]=a[child];
        else break;
    }
    a[hole] = tmp;
}

//冒泡排序法
//时间复杂度为O（N^2）
template<class elemtype>
void bubblesort(elemtype a[],int size)
{
    int i,j;
    elemtype tmp;
    bool flag;

    for(int i=0;i<size;++i)
    {
        flag = false;
        for(j=0;j<size-i;++j)
          if(a[j+1]<a[j])
          {
              tmp = a[j+1];
              a[j+1] = a[j];
              a[j] = tmp;
              flag = true;
          }
          if(!flag)break;
    }
    
}

//归并排序
//时间复杂度为O（NlogN）
template<class elemtype>
void mergesort(elemtype a[],int left,int right)
{
    int mid = (left+right)/2;
    if(left == right)return;
    mergesort(a,left,mid);
    mergesort(a,mid+1,right);
    merge(a,left,mid+1,right);
}

template<class elemtype>
void merge(elemtype a[],int left,int mid,int right)
{
    elemtype *tmp = new elemtype[right-left+1];
    int i = left,j=mid,k=0;

    while(i<mid&&j<=right)
    {
        if(a[i]<a[j])tmp[k++]=a[i++];
        else tmp[k++]=a[j++];
    }

    while(i<mid)tmp[k++]=a[i++];
    while(j<=right)tmp[k++]=a[j++];

    for(i=0,k=left;k<=right;)a[k++]=tmp[i++];
    delete[]tmp;
}

//口袋排序
//时间复杂度为（len×（n+10））

template<class elemtype>
struct bucksortnode
{
    elemtype data;
    bucksortnode *next;
    bucksortnode (){next=NULL;}
    bucksortnode(elemtype *d,bucksortnode*n=NULL):data(d),next(n){}
};

template <class elemtype>
void bucketsort(bucksortnode<elemtype>*&p) //p是链表头
{
    bucksortnode *bucket[10],*last[10],*tail;
    int i , j, k, base = 1; max =0; len = 0;

    for(tail  = p;tail!=NULL;tail=tail->next)
       if(tail->data > max) max = tail->data;

    if(max = 0)len=0;
    else while(max>0){++len;max/=10;}

    for(i=1;i<=len;i++)
    {
        for(j=0;j<=9;j++)bucket[j]=last[j]=NULL;
        while(p!=NULL)
        {
            k= p->data / base % 10;
            if(bucket[k]==NULL)bucket[k]=last[k]=p;
            else last[k]=last[k]->next=p;
            p=p->next;
        }
        p=NULL;
        for(j=0;j<=9;++j)
        {
            if(bucket[j]==NULL)continue;
            if(p==NULL)p=bucket[j];
            else tail->next = bucket[j];
            tail = last[j];
        }
        tail->next = NULL;
        base *= 10;
    } 
}

//快速排序
//时间复杂度为O（NlogN）
int devide(int a[],int low,int high)
{
    int k = a[low];

    int i=low,j=high;
    while(i<j)
    {
        while(i<j&&a[j]>=k)j--;
        if(i<j)
        {
            a[i++]=a[j];
        }
        while(i<j&&a[i]<=k)i++;
        if(i<j)
        {
           a[j--]=a[i];
        }
    }
    a[i]=k;
    return i;
}


void quicksort(int a[],int low,int high)
{
    if(low>=high)return;
    int mid = devide(a,low,high);
    quicksort(a,mid+1,high);
    quicksort(a,low,mid-1);
}

void quicksort(int a[],int size)
{
    quicksort(a,0,size-1);
}