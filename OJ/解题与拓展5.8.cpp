#include<iostream>
using namespace std;

class ERROR{};

template<class T>
class linkqueue
{
private:
    struct node
    {
     T data;
        node *next;
        node(const T&x,node *ne=NULL)
        {
            data=x;
            next=ne;
        }
        node():next(NULL){}
        ~node(){}

    };

    node *Front,*Rear;

public:
    linkqueue()
    {
        Front=Rear=NULL;
    }

    ~linkqueue()
    {
        node *tmp;
        while(Front)
        {
          tmp=Front;
          Front=Front->next;
          delete tmp;
         }
    }

    bool isempty()const
    {
        return Front==NULL;
    }

    void enqueue(const T&x)
    {
        if(isempty())Rear=Front=new node(x);
        else
        {
           Rear->next=new node(x);
           Rear=Rear->next;
        }
    }

 T dequeue()
    {
       if(isempty())return 0;
       node *tmp=Front;
     T Tmp=Front->data;
       Front=Front->next;
       if(Front==NULL)Rear=NULL;
       delete tmp;
       return Tmp;
    }

 T gethead()const
    {
        if(isempty())return 0;
        return Front->data;
    }
};

template<class T>
class tree
{
    struct node 
    {
        T data;
        node *son,*brother;

        node (T d,node *s=NULL,node *b =NULL)
        {data=d;son=s;brother = b;}
        node *root;
    };
    
    node *root;

    public:
    tree(node *t=NULL){root = t;}
    void createtree(T flag);
    void preorder(){preorder(root);}
    void postorder(){postorder(root);}
    void levelorder();

    private:
    void preorder(node *t);
    void postorder(node *t);
};

template<class T>
void tree<T>::createtree(T flag)
{
    linkqueue<node*>que;
    node *tmp;
    T x,son;
    cout<<"\nenter root:";
    cin>>x;
    root = new node(x);
    que.enqueue(root);

    while(!que.isempty())
    {
        tmp = que.dequeue();
        cout<<"\nenter sons of"<<tmp->data<<"(end of "<<flag<<"):";
        cin>>son;
        if(son ==flag)continue;
        tmp->son=new node(son);
        tmp = tmp->son;
        que.enqueue(tmp);
        while(true)
        {
            cin>>son;
            if(son == flag)break;
            tmp->brother = new node(son);
            tmp = tmp->brother;
            que.enqueue(tmp);
        }
    }
    cout<<"create completed!\n";
}

template<class T>
void tree<T>::preorder(node *t)
{
    if(t==NULL)return;
    cout<<t->data;
    node *p=t->son;
    while(p!=NULL)
    {
        preorder(p);
        p=p->brother;
    }
}

template<class T>
void tree<T>::postorder(node *t)
{
    if(t==NULL)return;
    node *p=t->son;
    while(p!=NULL)
    {
        postorder(p);
        p=p->brother;
    }
    cout<<t->data;
}

template<class T>
void tree<T>::levelorder()
{
    linkqueue<node*>que;
    node *tmp;

    if(root == NULL)return;
    que.enqueue(root);
    while(!que.isempty())
    {
        tmp=que.dequeue();
        cout<<tmp->data;
        tmp=tmp->son;
        while(tmp!=NULL)
        {
            que.enqueue(tmp);
            tmp=tmp->brother;
        }
    }
}

int main()
{
    tree<int> t;
    t.createtree(0);
    t.levelorder();
    t.postorder();
    t.preorder();
    return 0;
}