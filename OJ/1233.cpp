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
   ~adjlistgraph();
   int searchpath(int start,int M)
   {
       edgenode*p=verlist[start].head;
       int num=0;
       while(p!=NULL)
       { 
           bool *visited = new bool [vers];
           for(int i=0;i<vers;i++)visited[i]=false;
           visited[start]=true;
           circle(p->end,M,visited,num);
           p=p->next;
       }
      return num;
   }   

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

   void circle(int start,int M,bool visited[],int &num)
   {
    /*if(M==1){num++;return;}
    edgenode *p = verlist[start].head;
    visited[start] = true;M--;
    while(p!=NULL)
    {
        if(!visited[p->end])circle(p->end,M,visited,num);
        p=p->next;
        visited[start]=false;
    } */

    if(M==1){
        ++num;
        return;
    }
    edgenode *tmp=verlist[start].head;
    while(tmp!=NULL){
        if(!visited[tmp->end]){
            visited[start]=true;
            circle(tmp->end,M-1,visited,num);
            visited[start]=false;
        }
        tmp=tmp->next;
    } 
   }
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

int main()
{
    int N,m,start,M;
    cin>>N>>m>>start>>M;
    int *a = new int [N];
    for(int i=0;i<N;i++)a[i]=i;
    adjlistgraph<int,int> g(N,a);
    int tmp1,tmp2;
    while(m--)
    {
        cin>>tmp1>>tmp2;
        g.insert(tmp1-1,tmp2-1,1);
    }
    cout<< g.searchpath(start-1,M)<<endl;
    //g.dfs();
    return 0;
}