#include <iostream>
#include <stdio.h>
#define Maxn 10005
using namespace std;

int N;
int seg[Maxn][500];
int legth[Maxn];
struct trnode
{
	int no, size;
	trnode* next;
	trnode() :no(0), size(1), next(NULL) {}
	trnode(int nno) :no(nno), size(1), next(NULL) {}
};
trnode *trarr;
bool *visited;

void getSizeAround(trnode *cur)
{
	visited[cur->no]=1;
	if (cur->size >1) return;
	trnode *tmp =trarr[cur->no].next;
	while (tmp)
	{
		if (!visited[tmp->no])
		{
			getSizeAround(tmp);
			cur->size+=tmp->size;
		}
		tmp=tmp->next;
	}
	return;
}

int main()
{

	scanf("%d", &N);

	trarr=new trnode[N + 1];
	visited=new bool[N + 1];
	int u, v;
	for (int i=0;i<N-1;i++)
	{
		scanf("%d%d", &u, &v);
		trnode *tmpu=new trnode(u), *tmpv=new trnode(v);
		tmpv->next=trarr[u].next;
		trarr[u].next=tmpv;
		tmpu->next=trarr[v].next;
		trarr[v].next=tmpu;
	}

	for (int i=1;i<=N;i++)
	{
		for (int j=0;j<=N;j++) visited[j] = 0;
		visited[i]=1;

		trnode* cur=trarr[i].next;
		while(cur)
		{
            getSizeAround(cur);
 			seg[i][legth[i]++]=cur->size;
			cur = cur->next;
		}
	}
	
    int p=1,Min=10000,Max;
	for(int i=1;i<=N;i++)
    {      Max=seg[i][0];
         for(int j=0;j<legth[i];j++)
          if(Max<seg[i][j])Max=seg[i][j];
          if(Min>Max){Min=Max;p=i;}
    }
     printf("%d",p);
     printf(" ");
     printf("%d",Min);
	return 0;
}
