#include <iostream>

using namespace std;

class outofbound{};

template<class elemtype>
class singlist
{
private:
    struct node
    {
        elemtype data;
        node *next;

        node(const elemtype &x,node *n=NULL)
        {
            data=x;
            next=n;
        }
        node():next(NULL){}
        ~node(){}
    };

    node *head;
    int lenth;
    node*Move(int i)
    {
        if(i<0||i>lenth)return 0;
    node *p=head;
    for(int j=0;j<i;j++)
        p=p->next;
    return p;
    }
public:
    singlist();
    ~singlist();
    void Insert(const elemtype &x,int i);
    void traverse();
    void Delete(int i);
    void Reverse();
};

template <class elemtype>
singlist<elemtype>::singlist()
{
    head=new node();
    lenth=0;
}

template<class elemtype>
singlist<elemtype>::~singlist()
{
    node *p=head->next,*q;
    while(p)
    {
        q=p;
        p=p->next;
        delete q;
    }
}

template<class elemtype>
void singlist<elemtype>::Insert(const elemtype&x,int i)
{
    if(i<0||i>lenth)throw outofbound();
    node *p=Move(i);
    p->next=new node(x,p->next);
    lenth++;
}

template<class elemtype>
void singlist<elemtype>::Delete(int i)
{
    if(i<0||i>lenth)throw outofbound();
    node *p=Move(i-1);
    node *tmp=p->next;
    p->next=tmp->next;
    delete tmp;
    lenth--;
}
template<class elemtype>
void singlist<elemtype>::Reverse()
{
    if(head->next==NULL)return;
    node*p=head->next;
    head->next=NULL;
    node*tmp;
    while(p)
    {
        tmp=p;
        p=p->next;
        tmp->next=head->next;
        head->next=tmp;
    }
}

template<class elemtype>
void singlist<elemtype>::traverse()
{
    node*p=head->next;
    cout<<endl;
    for(int i=0;i<lenth;i++)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

}
int main()
{
    int len;
    singlist<int> s;
    cout<<"please input the size"<<endl;
    cin>>len;
    int N;
    for(int i=0;i<len;i++)
    {
        cin>>N;
        s.Insert(N,i);
    }
    s.Reverse();
    s.traverse();
    return 0;
}
