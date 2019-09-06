#include <iostream>
using namespace std;
struct data
{
    int tmp2;
    int tmp1;
    data(){tmp1=0;tmp2=0;}
};
int main()
{
    int N;
    cin>>N
    data *A;
    A=new data[N+1];
    int x1,x2;
    for(int i=1;i<=N;i++)
    {
        cin>>data[i].tmp1>>data[i]tmp2;
    }
    int cur=0;int a[100];
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<N;j++)
            if(data[j].tmp1==i||data[j].tmp2==i)
    }

    return 0;
}
