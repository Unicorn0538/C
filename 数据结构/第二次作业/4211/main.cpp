#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct node
    {
        int  data;
        char *name;
        node *next;

        node(const int &x,const char na[] ,node*n=NULL)
        {
            data=x;
            name=new char [strlen(na)+1];
            strcpy(name,na);
            next=n;
        }

        node():next(NULL){}
        ~node(){}
    };

class acadein
{
private:
    node *Top;
    int cur;
public:
    acadein();
    ~acadein();
    bool isempty();
    void push(const int &x,const char *name);
    void Search();
    void pop();
};

acadein::acadein()
{
    Top=NULL;
    cur=0;
}


acadein::~acadein()
{
    node *tmp;
    while(Top)
    {
        tmp=Top;
        Top=Top->next;
        delete tmp;
    }
}


bool acadein::isempty()
{
   return Top==NULL;
}


void acadein::push(const int&x,const char *name )
{
    Top=new node(x,name,Top);
    cur++;
}


void acadein::pop()
{
    if(Top==NULL)return;
    node*tmp=Top;
    Top=Top->next;
    delete tmp;
    cur--;
}

void acadein::Search()
{
    node *p=Top->next;
    int i;
    for(i=0;i<cur-1;i++)
    {
        if(Top->data<p->data)
           {
               puts(p->name);
               break;
           }
        else p=p->next;
    }
    int j=-1;
    if(i==cur-1)cout<<j<<endl;

}
struct Node
    {
        char *Name;
        int influ;
        Node(char N[],int x=0):influ(x)
        {
            Name=new char [strlen(N)+1];
            strcpy(Name,N);

        }
        Node(){Name=new char[32];influ=0;}
        ~Node(){}
    };
int main()
{
   int N,i;
    cin>>N;
    Node *date;
    date = new Node[N+1];


    acadein tmp;
    if(!N)return 0;
    for(i=0;i<N;i++)
    {

        scanf("%d",&date[i].influ);
        cin.get();
        cin.getline(date[i].Name,31);
    }

    for(i=N-1;i>=0;i--)
    {
        tmp.push(date[i].influ,date[i].Name);
    }
    while(!tmp.isempty())
    {
        tmp.Search();
        tmp.pop();
    }
    delete []date;
    return 0;

}
