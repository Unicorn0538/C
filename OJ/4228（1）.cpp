//定义一个二叉树查找树和一个二维数组
//二叉查找树的节点里保存邮箱和二维数组中存放姓名的位置
//二维数组里保存姓名
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

struct mailnode
{

   int num;
   char *mail;
   mailnode *left;
   mailnode *right;

   mailnode (char *m,int n,mailnode *l=NULL,mailnode *r=NULL):num(n),left(l),right(r)
   {mail=new char[50];strcpy(mail,m);}
   mailnode (mailnode *l=NULL,mailnode *r=NULL):left(l),right(r){}
   ~mailnode(){delete[]mail;}
};

struct namenode
{
    char *name;
    namenode(){name = new char[2000];}
};

class mail
{
    mailnode *root;

    public:
    mail(mailnode*t=NULL)
    {
        root = t;
    }
    ~mail(){delete root;}
    void insert(char *name,char *mail,namenode Name[]){insert(name,mail,root,Name);}
    void traverse();
    private:
    void insert(char *name, char *mail,mailnode *&t,namenode Name[]);
};

int n=0;
void mail::insert(char *name,char*mail,mailnode *&t,namenode Name[])
{
   if(t==NULL)
   {
       t=new mailnode(mail,n,NULL,NULL);
       strcpy(Name[n++].name,name);

   }
   else if(strcmp(t->mail, mail)>0)insert(name,mail,t->left,Name);
   else if(strcmp(t->mail, mail)<0)insert(name,mail,t->right,Name);
   else if(strcmp(t->mail, mail)==0)
    {strcat(Name[t->num].name," ");strcat(Name[t->num].name,name);}
}

int main()
{

    int N;
    scanf("%d",&N);
    mail m;
    struct namenode Name[N+1];
    char *tmp1,*tmp2;
    tmp1=new char[50];tmp2=new char[50];
    while(N--)
    {
        scanf("%s",tmp1);
        scanf("%s",tmp2);
        m.insert(tmp1,tmp2,Name);

    }
     for(int i=0;i<n;i++)
      {printf("%s",Name[i].name);printf("\n");}
    return 0;

}
