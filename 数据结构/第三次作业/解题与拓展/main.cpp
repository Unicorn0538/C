#include <iostream>

using namespace std;

/*template<class T>
//不带头节点的循环单链表，包含一个迭代器类
//迭代器本身可以被赋值，可以判断相等
//通过迭代器访问他指向的元素
class CycleList
{
private:
    struct node
    {
        T data;
        node *next;

        node():next(NULL){}
        node(const T&x,node *p=NULL):data(x),next(p){}
    };

    node *head;

public:
    CycleList():head(NULL){}

    ~CycleList()
    {
        if(head!=NULL)
        {
            node *beg=head,*tmp;
            do{
                tmp=head->next;
                delete head;
                head=tmp;
            }while(head=tmp);
        }
    }

    class myltr
    {
        friend CycleList;
    private:
        node *cur;

    public:
        myltr(node *p=NULL):cur(p){}

        myltr operator++(int )
        {
            node *tmp=cur;
            cur=cur->next;
            return tmp;
        }

        myltr operator++()
        {
            return cur=cur->next;
        }

        bool &operator==(const myltr&a)
        {
            return cur==a.cur;
        }

        T &operator*()
        {
            return cur->data;
        }
        bool operator!=(const myltr&a)
        {
            return cur!=a.cur;
        }
        bool isNULL()
        {
            return cur==NULL;
        }
    };

    myltr Begin()const
    {
        return head;
    }

    void Insert(myltr &p,const T&a)
    {
        if(p.cur==NULL)
        {
            head=p.cur=new node(a);
            head->next=head;
        }
        else p.cur=p.cur->next=new node(a,p.cur->next);
    }

    void Erase(myltr &p)
    {
        if(p.cur==NULL)return;
        if(p.cur->next==p.cur)
        {
            delete p.cur;
            head=p.cur=NULL;
        }
        else {
            node *q;
            q=p.cur->next;
            p.cur->next=q->next;
            if(q==head)head=q->next;
            delete q;
        }
    }

    myltr Search(const T&a)
    {
        myltr p=Begin(),q=p;
        for(++p;p!=q;++p)
            if(a==*p)return p;
        return NULL;
    }
};
*/

//Ackerman函数的实现
/*int A(int m,int n)
{
    seqstack<int > a;
    a.push(m);
    a.push(n);

    while (true)
    {
        n=a.pop();
        if(a.isempty())return n;

        m=a.pop();

        if(m!=0&&n!=0)
        {
            a.push(m-1);
            a.push(m);
            a.push(n-1);
        }
        else if(m!=0&&n==0)
        {
            a.push(m-1);
            a.push(1);
        }
        else push(n+1);
    }
}
*/


