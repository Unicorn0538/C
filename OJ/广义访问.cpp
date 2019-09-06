#include <iostream>
using namespace std;


int main()
{
    linkqueue<vernode *>q;
    bool visited[vers]={0};
    int i=0;
    edenode *t;
    versnode*p;
    while()
    {q.enqueue(verlist[0]);
        
    }
    
    while(!q.isempty())
    {
        p=q.dequeue();
        if (visited[p->verse])
    }
}

DFs(int i)
{
    visited[i]=1;
    cout<<verlist[i].data;
    p=verlist[i].adj;
    while(p)
    {
        if(visited[p->end]==0)
    }
    Dfs(p->end);
    p=p->next;
}