//孩子兄弟链 孩子节点存放姓名，兄弟节点存放邮箱
#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
class email
{
    struct emailnode
    {
      char *elem;
      emailnode *son;
      emailnode *brother;

      emailnode(char *d,emailnode *s=NULL,emailnode *b=NULL)
      {
          elem = new char[strlen(d)+1];
          strcpy(elem,d);
          son=s;
          brother=b;
      }
    };

    emailnode *root;

    public:
    email(emailnode *t=NULL){root= t;}
    void insert(char *tmp1,char *tmp2){Insert(tmp1,tmp2,root);}
    void print(){Print(root);}

    private:

    void Insert (char *tmp1,char *tmp2,emailnode *&t) //将两个字符串插入
    {  
       if(t==NULL)//如果该节点为空
        {
           t=new emailnode(tmp2,NULL,NULL);
           t->son=new emailnode(tmp1);
           return;
        }
        
        if(strcmp(t->elem,tmp2)==0)//如果邮箱相同
        {
            insertson(tmp1,t->son);//把姓名插入最下面的儿子节点
            return;
        }
        Insert(tmp1,tmp2,t->brother);//查找下一个兄弟节点
    }

    void Print(emailnode *t)//输出
    {
        if(t==NULL)return;
    
        emailnode *tmp=t->son;
        while(tmp)
        {
            printf("%s ",tmp->elem);
            tmp=tmp->son;
        }
        printf("\n");
        Print(t->brother);
    }

    void insertson(char *tmp1,emailnode *&t)
    {
        if(t==NULL){t=new emailnode(tmp1,NULL,NULL);return;}
        insertson(tmp1,t->son);
    }

};

int main()
{
    
    int N;
    scanf("%d",&N);
    email e;
    char *tmp1,*tmp2;
    tmp1=new char[100];tmp2=new char[100];
    while(N--)
    {
        scanf("%s",tmp1);
        scanf("%s",tmp2);
        e.insert(tmp1,tmp2);
        
    }e.print();
    
    return 0;

}