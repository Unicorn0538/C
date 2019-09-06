#include <iostream>
#define MaxN 10001
using namespace std;
 
int n;
int connect[MaxN][500]={0}; 
int length[MaxN]={0};
int seg[MaxN][500]={0};   
int count;
void init()
{
    cin>>n;
    
    for (int i = 0; i < n-1; ++i)
    {
        int x,y;
        cin>>x>>y;
        connect[x][length[x]++] = y;
        connect[y][length[y]++] = x;
    }
}
 
int getComponent(int s, int x,int tmp)//找出s的x开头的分支的数目
{
    //函数错误写不出来了
    if(tmp==x&&connect[x][0]==s)return 0;
    count++;
    for(int i=0;i<length[x];i++)
    {
        if(connect[x][i]==s)continue;
        else {tmp=s;count+=getComponent(x,connect[x][i],tmp);}
        
    }
    //int Tm = count;
    //cout<<Tm<<endl;
    return count;
} 
 
void Build()
{
    for (int i = 1; i <= n; ++i) 
        for (int j = 0; j < length[i]; ++j){
            count=0;
            seg[i][j] = getComponent(i,connect[i][j],0);
        }
}
 
void Output()
{

    for (int i = 1; i <= n; ++i)
    {
       for (int j =0;j<length[i];j++)
       cout<<connect[i][j]<<"的个数是"<<seg[i][j]<<"  ";
       cout<<endl;      
    }
    
}
 
int main()
{
    init(); 
    Build();
    Output(); 
 
    return 0;
}