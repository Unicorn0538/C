#include <iostream>
#include "linkqueue.h"
using namespace std;

class calc
{
    enum Type{DATA,ADD,SUB,MULTI,DIV,OPAREN,CPAREN,EOL};

    struct node
    {
        Type type;
        int data;
        node *lchild,*rchild;

        node (Type t,int d=0,node *lc=NULL,node*rc=NULL)
        {
            type=t;
            data=d;
            lchild=lc;
            rchild=rc;
        }
    };

    node *root;

    node*creat(char*&s);//从s创建一棵树
    Type getToken(char *&s,int &value);//从s获取一个语法单位
    int result(node*t);//计算以t为根的表达式树的结果

public:
    calc(char*s){root=creat(s);}
    int result()
    {
        if(root==NULL)return 0;
        return result(root);
    }

    void preorder()
    {
        linkqueue<node*>que;
        node *tmp;
        que.enqueue(root);

        while(!que.isempty())
        {
            tmp=que.dequeue();
            cout<<tmp->data<<" "<<tmp->type<<endl;
            if(tmp->lchild)que.enqueue(tmp->lchild);
            if(tmp->rchild)que.enqueue(tmp->rchild);
        }
    }
};

calc::node *calc::creat(char*&s)
{
    calc::node *p,*root=NULL;
    Type returnType;
    int value;

    while (*s)
    {
        returnType=calc::getToken(s,value);
        switch(returnType)
        {
          case DATA: case OPAREN:

              if(returnType==DATA) p=new calc::node(DATA,value);
              else p=creat(s);

              if(root!=NULL)
                   if(root->rchild==NULL)root->rchild=p;
                   else root->rchild->rchild=p;
              break;

          case CPAREN:case EOL: return root;

          case ADD: case SUB:
            if(root==NULL)root=new node(returnType,0,p);
            else root=new node(returnType,0,root);
            break;

          case MULTI:case DIV:
            if(root==NULL)root=new node(returnType,0,p);
            else if(root->type==MULTI||root->type==DIV)
                root=new node (returnType,0,root);
            else root->rchild=new node(returnType,0,root->rchild);
        }
    }
    return root;
}

calc::Type calc::getToken(char *&s,int &data)
{
    char type;
    while(*s==' ')++s;  //跳过中缀表达式中的空格

    if (*s>='0'&&*s<='9')  //遇到运算数
    {
        data=0;
        while(*s>='0'&&*s<='9')
        {
            data=data*10+*s-'0';
            ++s;
        }

        return DATA;
    }

    if(*s=='\0')return EOL;

    type=*s;++s;
    switch (type)
    {
        case '+':return ADD;
        case '-':return SUB;
        case '*':return MULTI;
        case '/':return DIV;
        case '(':return OPAREN;
        case ')':return CPAREN;
        default :return EOL;
    }
}

int calc::result(calc::node*t)
{
    int num1,num2;
    if(t->type==DATA)return t->data;

    num1=result(t->lchild);  //计算左子表达式
    num2=result(t->rchild);  //计算右子表达式

    switch(t->type)
    {
        case ADD:  t->data=num1+num2;break;
        case SUB:  t->data=num1-num2;break;
        case MULTI:t->data=num1*num2;break;
        case DIV:  t->data=num1/num2;
    }

    return t->data;
}


int main()
{
    calc exp("2*3+(1*2*3+6*6)*(2+3)/5+2/2");
    exp.preorder();
    cout<<exp.result()<<endl;
    return 0;
}
