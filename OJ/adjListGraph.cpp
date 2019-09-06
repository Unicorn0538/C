#include <iostream>
#include <queue>
using namespace std;

template<class typeofver,class typeofedge>
class adjlistgraph
{
   private:
   int vers,egde;

   public:
   adjlistgraph(int vsize,const typeofver d[]);
   bool insert(int u,int v,typeofedge w);
   bool remove(int u,int v);
   bool exist(int u,int v)const;
   ~adjlistgraph();
   void dfs()const;   
   void bfs()const;

   private:
   struct edgenode
   {
       int end;
       typeofedge weight;
       edgenode *next;

       edgenode(int e,typeofedge w,edgenode *n=NULL)
       {end=e; weight=w; next=n;}
   };

   struct vernode
   {
       typeofver ver;
       edgenode *head;

       vernode(edgenode *n =NULL ){head = n;}
   };

   vernode *verlist;

   void dfs(int start,bool visited[])const;
};

template<class typeofver,class typeofedge>
adjlistgraph<typeofver,typeofedge>::adjlistgraph(int vsize, const typeofver d[])
{
    vers=vsize;egde=0;

    verlist = new vernode[vsize];
    for(int i=0;i<vsize;i++) verlist[i].ver=d[i];
}

template<class typeofver,class typeofedge>
adjlistgraph<typeofver,typeofedge>::~adjlistgraph()
{
    edgenode *p;

    for(int i=0;i<vers;i++)
        while((p=verlist[i].head)!=NULL)
        {
            verlist[i].head = p->next;
            delete p;
        }   

    delete [] verlist;
}

template<class typeofver,class typeofedge>
bool adjlistgraph<typeofver,typeofedge>::insert(int u, int v,typeofedge w)
{
    verlist[u].head = new edgenode(v, w, verlist[u].head);
    ++egde;
    return true;
}

template<class typeofver,class typeofedge>
bool adjlistgraph<typeofver,typeofedge>::remove(int u,int v)
{
    edgenode *p=verlist[u].head,*q;

    if(p==NULL)return false;
    if(p->end==v)
    {
        verlist[u].head = p->next;
        delete p;
        --egde;
        return true;
    }

    while(p->next!=NULL && p->next->end!=v) p=p->next;
    if(p->next == NULL)return false;
    q = p->next; p->next=q->next;delete q;
    --egde;
    return true;
}

template<class typeofver,class typeofedge>
bool adjlistgraph<typeofver,typeofedge>::exist(int u,int v)const
{
   edgenode *p = verlist[u].head;

   while(p!=NULL&&p->end != v)p=p->next;
   if(p==NULL)return false;else return true;    
}

template<class typeofver,class typeofedge>
void adjlistgraph<typeofver,typeofedge>::dfs()const
{
    bool *visited = new bool[vers];
    for(int i=0;i<vers;i++)visited[i] = false;

    for(int i=0;i<vers;i++)
    {
        if(visited[i])continue;
        dfs(i,visited);
        cout<<endl;
    }
}

template<class typeofver,class typeofedge>
void adjlistgraph<typeofver,typeofedge>::dfs(int start,bool visited[])const
{
    edgenode *p = verlist[start].head;

    cout << verlist[start].ver << '\t';
    visited[start] = true;
    while(p!=NULL)
    {
        if(!visited[p->end])dfs(p->end,visited);
        p=p->next;
    }
}

template<class typeofver,class typeofedge>
void adjlistgraph<typeofver,typeofedge>::bfs()const
{
    bool *visited =new bool [vers];
    int cur;
    queue<int>q;
    edgenode *p;

    for(int i=0;i<vers;++i)visited[i] = false;

    for(int i=0;i<vers;i++)
    {
        if(visited[i])continue;
        q.push(i);
        while(!q.empty())
        {
            cur = q.front();q.pop();
            if(visited[cur])continue;
            cout<<verlist[cur].ver<<'\t';
            visited[cur]=true;
            p=verlist[cur].head;
            while(p!=NULL)
            {
                if(!visited[p->end])q.push(p->end);
                p=p->next;
            }
        }
        cout<<endl;
    }
}


int main()
{
    adjlistgraph<char,int> g(10,"abcderfghuj");
    if(g.insert(0,5,9))cout<<"yes"<<endl;else cout<<"NO"<<endl;
    if(g.exist(0,5))cout<<"yes"<<endl;else cout<<"NO"<<endl;
    g.insert(0,7,3);g.insert(5,1,0);g.insert(6,9,0);g.insert(8,9,0);g.insert(6,8,0);
    g.bfs();
    g.dfs();
    if(g.remove(0,5))cout<<"yes"<<endl;else cout<<"NO"<<endl;
    if(g.exist(0,5))cout<<"yes"<<endl;else cout<<"NO"<<endl;
    return 0;
}