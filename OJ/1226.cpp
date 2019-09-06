#include <iostream>
#include <stdio.h>
using namespace std;
/*int devide(int a[],int low,int high)
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
*/

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


template<class elemtype>
void mergesort(elemtype a[],int left,int right)
{
    int mid = (left+right)/2;
    if(left == right)return;
    mergesort(a,left,mid);
    mergesort(a,mid+1,right);
    merge(a,left,mid+1,right);
}


int main()
{
    int N;
    scanf("%d",&N);
    int *a;
    a=new int[N+1];
    
    for(int i=0;i<N;i++)
      scanf("%d",&a[i]);
    mergesort(a,0,N-1);
    for(int i=0;i<N;i++)
      {printf("%d",a[i]);printf(" ");}
}