//利用二叉查找树和数组来构建
//数组结构体中存放文章引言和引用数
//节点里存放文章引言和其在数组中的位置

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;


struct Array
{
   int cite;
   int tmp;
   string name;
};
static int n=1;
class parper
{
   struct parpernode
   {
     int num;
     string data;
     parpernode *left;
     parpernode *right;
     parpernode(int n, string d,parpernode *l,parpernode *r):num(n),data(d),left(l),right(r)
     {}
     parpernode(parpernode *l=NULL,parpernode *r=NULL):left(l),right(r){}
   };

   parpernode *root;

   public:
   parper(parpernode *t=NULL){root = t;}
   void sert(string tmp,Array data[],int &tmp1){return Insert(tmp,data,root,tmp1);}

   private:
   void Insert(string tmp,Array data[],parpernode *&t,int &tmp1)
   {
       if(t==NULL)
       {
        t = new parpernode (n,tmp,NULL,NULL);
        data[n].cite=1;
        data[n++].name=tmp;
        tmp1 = n-1;

        }
    else if(tmp>t->data)Insert(tmp,data , t->right,tmp1);
    else if(tmp<t->data)Insert(tmp,data,t->left,tmp1);
    else{
    data[t->num].cite++;
    tmp1 = t->num;}
   }

};


int main()
{
    ios::sync_with_stdio(false);
    
    parper p;
    
    struct Array *data;
    data = new Array[10000];
    char ch[6];
    string tmp;
    int maxi=1,tmp1=1;
    while(true)
    {

       cin>>ch;cin.get();
       if(ch[0]=='c')
       {

           getline(cin,tmp);
           p.sert(tmp,data,tmp1);
           if(data[tmp1].cite>data[maxi].cite)maxi=tmp1;
           else if(data[tmp1].cite==data[maxi].cite&&data[tmp1].name<data[maxi].name)
               maxi=tmp1;
       }
       else if(ch[0]=='q')
       {
         cout<<data[maxi].cite<<" "<<data[maxi].name<<endl;
       }
       else break;
    }
    return 0;

}
