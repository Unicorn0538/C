#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int N,tmp,i,j,count=0;
    cin>>N;
    int *a;
    a=new int [N];
    for( i=0;i<N;i++)
    {
       cin>>tmp;
       for(j=i-1;j>-1;j--)
        {
          if(a[j]>tmp)
          {
              count++;
              a[j+1]=a[j];
          }
          else break;
        }
        a[j+1]=tmp;
    }
    cout<<count<<endl;

}