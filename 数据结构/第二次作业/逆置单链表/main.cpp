#include<iostream>
using namespace std;

template<class T>
class singleList
{
private:
    struct node
    {
        T value;
        node *next;

        node() : next(NULL){}
        node(const T &v,node *n=NULL):value(v),next(n){}
    };

node *head;
int  leng;

protected:
    node *get(int i) const
    {
    if( i < 0) return head;
    node *p = head -> next;
    for(int j = 0;j < i; ++j) p = p -> next;

    return p;
}

public:
    singleList():leng(0){head = new node;}

    ~singleList()
    {
        Clear();
        delete head;
    }
    T getvalue(int i) const
    {
        if( i < 0||i>leng) return -1;
        node *p = head -> next;
        for (int j = 0;j<i;++j){
            p = p -> next;

        }return p -> value;
    }
    void Clear()
    {
        while (length()>0) Remove(0);
    }

    int length()const
    {
        return leng;
    }

    void Insert(int i,const T &x)
    {
        node *p = get(i - 1);
        p -> next = new node(x,p->next);
        ++leng;
    }

    void Remove(int i)
    {
        node *p = get(i - 1);
        p -> next = p -> next -> next;
        delete p->next;
        -- leng;
    }

    int Search(const T &x) const
    {
        node *p = head -> next;
        for(int i = 0;p;++ i){
            if (x == p -> value) return i;
            else p = p -> next;
        }

        return -1;
    }

    T visit(int i) const
    {
        return get(i) -> value ;
    }

    void traverse() const
    {
        node *p = head -> next;
        while(p){
            cout<<p -> value <<" ";
            p = p -> next;
        }
    }

void Reverse()
{
    if(head -> next == NULL) return;

    node *cur = head  -> next;
    //head->next=NULL;
    node *cur_next;

    head -> next  = NULL;
    while (cur ){
        cur_next = cur -> next;
        cur->next  = head -> next;
        head -> next = cur;
        cur = cur_next;
    }
}

/*void insert(int i,const T &x)
{
    node *p =get(i-1);
    p -> next = new node(x,p->next)

}*/

//singleList begin() const{return head;}
};

/*class MyItr
{
    friend singleList;
private:
    node *cur;
public:
    MyItr(node *p = NULL)cur(p){}
    */


int main()
{   int len;
    singleList<int> alink;

    cout<<"please input size "<<endl;
    cin>>len;
     int p;
    //int *p = new int[len-1];
    for(int i = 0 ;i < len;++i)
    {
        cin>>p;
        alink.Insert(i,p);
    }

    alink.Reverse();
    for(int j = 0; j < len; ++ j){
        cout<<alink.getvalue(j)<<" ";
    }

    return 0;
}
