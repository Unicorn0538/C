#include <iostream>
using namespace std;

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

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    int a[100];
    for(int i=0;i<N;i++)
       cin>>a[i];
    quicksort(a,N);
    int tmp=a[0],num=1;
    for(int i=1;i<N;i++)
        if(tmp!=a[i]){num++;tmp=a[i];}
    cout<<num;
}