#include <iostream>

using namespace std;

struct node
{
    int pi;
    int qi;
    node(int p=0,int q=0):pi(p),qi(q){}
};
int main()
{
    int N,i;
    cin>>N;
    node *data;
    data=new node[100000];
    for( i=0;i<N;i++)
    {
        cin>>data[i].pi>>data[i].qi;
    }
    if(data[0].pi==0&&data[0].qi==0)

    {for( i=N;i>0;i--)
    {
        if(data[i].pi==0&&data[i].qi!=0)
        {cout<<"N";break;}
        if(data[i].pi!=0&&data[i].qi==0)
        {
            for(int j=i-1;j>0;j--)
                if(data[j].pi!=0||data[j].qi!=0)
                {cout<<"N";break;}
        }
    }
    if(i==0)cout<<"Y"<<endl;}
    else
    {
        for( i=0;i<N;i++)
    {
        if(data[i].pi==0&&data[i].qi!=0)
        {cout<<"N";break;}
        if(data[i].pi!=0&&data[i].qi==0)
        {
            for(int j=i+1;j<N;j++)
                if(data[j].pi!=0||data[j].qi!=0)
                {cout<<"N";break;}
        }
    }
    if(i==N)cout<<"Y"<<endl;
    }

    return 0;
}


