#include <iostream>
using namespace std;
#define maxn 21
struct node
{
   long long int data;
   bool flag;
   int num;
   node(){num=0;flag=false;data=-1;}
};
int main()
{
    int N,t=0;
    cin>>N;
    node *a;
    a=new node [maxn];
    long long int tmp;
    while(N--)
    {
      cin>>tmp;
      
      if(t==0){a[t].data=tmp;a[t++].num++;continue;}
      
      int p=t;
      if(a[t-1].data<tmp){a[t].data=tmp;a[t++].num++;}
      else  
      while(p>0)
      {
        if(a[p-1].data==tmp){a[p-1].num++;break;}
        if(a[p-1].data>tmp){p--;continue;}
        if(a[p-1].data<tmp&&a[p].data>tmp)
        {int n=t;
            for(;n>p-1;n--)
            {
                a[n+1]=a[n];
            }
            a[p].data=tmp;
            a[p].num=1;
            t++;
            break;
        }
         
      }
      if((p==0)&&(a[0].data!=tmp))
      {
            int n=t;
            for(;n>p-1;n--)
            {
                a[n+1]=a[n];
            }
            a[p].data=tmp;
            a[p].num=1;
            t++;
      }
    }
    for(int i=0;i<t;i++)
    cout<<a[i].data<<" "<<a[i].num<<endl;
    return 0;
}