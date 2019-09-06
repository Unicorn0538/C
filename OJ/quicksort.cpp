#include <iostream>
using namespace std;
template<class key,class other>
struct SET
{
    key k;
    other ot; 
};

template<class key,class other>
void quicksort(SET<key,other>a[],int size)
{
    quicksort(a,0,size-1);
}

template<class key,class other>
void quicksort(SET<key,other>a[],int min,int max)
{
   int mid;
   if( min >= max)return;
   mid = devide(a,min,max);
   quicksort(a,min,mid-1);
   quicksort(a,mid+1,max);
}

template<class key,class other>
int devide(SET<key,other>a[],int min, int  max )
{
    SET<key,other> k = a[min];
    int i=min,j=max;
    while(i!=j)
    {
        while(i<j&&a[i].k<=k.k)i++;
        if(i<j)
        {
            a[j]=a[i];
            --j;
        }
        while(i<j&&a[j].k>k.k)j--;
        if(i<j)
        {
            a[i]=a[j];
            ++i;
        }
    }
    a[i]=k;
    return i;
}

int main()
{
    SET<int,int> a[10];
    for(int i=0;i<10;i++)
    cin>>a[i].k;
    quicksort(a,9);
    for(int j=0;j<10;j++)
    cout<<a[j].k;
    return 0;
}