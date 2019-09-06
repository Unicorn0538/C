#include <iostream>
#include <cstring>
using namespace std;

class turing
{
private:
    struct node
    {
        int year;

        node *next;
         char *name;
        node( int y,const char n[],node*ne=NULL)
        {
            year=y;
            name=new char[strlen(n)+1];
            strcpy(name,n);
            next=ne;
        }
        node():next(NULL){}
        ~node(){}
    };

    node *head;
    int currentsize;
public :
    turing();
    ~turing(){Clear();delete head;}


    void Insert(int y,const char n[]);
    void Delete (int i);
    void List (int i)const;
    void Clear();

};

turing::turing()
{
    head=new node;
    currentsize=0;
}

void turing ::Insert( int y,const char n[])
{
    node *p;
    p=head;
    while(p->next!=NULL)
    {
        if(y>p->next->year)
            {p=p->next;}
        else if(y==p->next->year)
        {
            int w=strcmp(n,p->next->name);

             if(w>0)p=p->next;
                else break;
        }
         else break;

    }

    p->next=new node(y,n,p->next);
    currentsize++;
}

void turing::Delete(int i)
{
    if(i>currentsize)return ;
    node *p,*q;
    p=head;
    for(int j=0;j<i-1;j++)
        p=p->next;
    q=p->next;
    p->next=q->next;
    delete q;
    currentsize--;
}

void turing::List(int i)const
{
    if(i>currentsize)return;
    node *p;
    p=head;
    for(int j=0;j<i;j++)
        p=p->next;
    cout<<p->year<<" "<<p->name<<endl;
}

void turing::Clear()
{
    node *p,*q;
    p=head->next;
    head->next=NULL;
    while(p!=NULL)
    {
        q=p->next;
        delete p;
        p=q;
    }
    currentsize=0;
}


int main()
{
    int N;
    cin>>N;
    turing tmp;
    if(!N)return 0;
    while(N--)
    {
        char name[31];
        int year;
        char order[10];
        cin>>order;
        if(strcmp(order,"insert")==0)
        {
            cin>>year;
            cin.get();
            cin.getline(name,31);
            tmp.Insert(year,name);
        }


        else if(strcmp(order,"list")==0)
            {
                int i;
                cin>>i;
                tmp.List(i);
            }
        else if(strcmp(order,"delete")==0)
            {
                int i;
                cin>>i;
                tmp.Delete(i);
            }
    }

    return 0;
}
