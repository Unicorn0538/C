#include <iostream>
using namespace std;
class african
{
    private:
    int size;
    int *parent;

    public:
    african(int s);
    ~african(){delete[]parent;}
    void Union(int root1,int root2);
    int find(int x);
    void print()
    {
        if(parent[0]<0)cout<<0-parent[0]<<endl;
        else {
            cout<<0-parent[find(0)]<<endl;
        }
    }
};

african::african(int s)
{
    size = s;
    parent = new int[size];
    for(int i=0;i<size;i++)parent[i]=-1;
}

int african::find(int x)
{
    if(parent[x]<0)return x;
    return parent[x]=find(parent[x]);
}

void african::Union(int root1,int root2)
{
    if(root1 == root2)return;
    if(parent[root1]>parent[root2])
    {
        parent[root2]+=parent[root1];
        parent[root1]=root2;
    }
    else
    {
        parent[root1]+=parent[root2];
        parent[root2]=root1;
    }
    
}

int main()
{
    int n,m,i,tmp1,tmp2;
    cin>>n>>m;
    african A(n);
    while(m--)
    {
      cin>>i>>tmp1;
      i--;
      while(i--)
      {
          cin>>tmp2;
          A.Union(A.find(tmp1),A.find(tmp2));
      }
    }
    A.print();
    return 0;
}