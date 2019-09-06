#include <iostream>
#include <cstring>
using namespace std;

struct node
{
   char data[32];
};

void merge(node a[],int left,int mid,int right)
{
    node *tmp = new node[right-left+1];
    int i = left,j=mid,k=0;

    while(i<mid&&j<=right)
    {
        if(strcmp(a[i].data,a[j].data)>0)tmp[k++]=a[i++];
        else tmp[k++]=a[j++];
    }

    while(i<mid)tmp[k++]=a[i++];
    while(j<=right)tmp[k++]=a[j++];

    for(i=0,k=left;k<=right;)a[k++]=tmp[i++];
    delete[]tmp;
}


void mergesort(node a[],int left,int right)
{
    int mid = (left+right)/2;
    if(left == right)return;
    mergesort(a,left,mid);
    mergesort(a,mid+1,right);
    merge(a,left,mid+1,right);
}

char *fun(char *str,char ch)
{
   char *tmp;
   int i,k=0;
   tmp = new char [35];
   for(i=0;i<35&&str[i]!='\0';i++)
   if(str[i]!=ch)tmp[k++]=str[i];
   tmp[k]='\0';
   return tmp;
}
int main()
{
    char ch,*tmp,*tmp1;
    tmp = new char[35];
    tmp1 = new char [35];
    node *str;
    str = new node [35];
    cin>>ch;
    int k=0;
    while(true)
    {
        cin.getline(tmp,33);
        if(strcmp(tmp,"@")==0)break;
        tmp1=fun(tmp,ch);
        
        strcpy(str[k++].data,tmp1);
    }    
    mergesort(str,0,k);
    for(int i=0;i<k-1;i++)
    {
       cout<<str[i].data<<endl;
    }
    return 0;
}