#include <iostream>

using namespace std;

class outofbound{};
template <class elemtype>
class seqstack
{
private:
    int Top;
    elemtype *elem;
    int maxsize;

    void doublespace();

public:
    seqstack (int inisize=10);
    ~seqstack(){delete elem;}
    elemtype top()const;
    void push(const elemtype&x);
    void pop();
    bool isempty()const;
};

template<class elemtype>
seqstack<elemtype>::seqstack(int inisize)
{
    maxsize=inisize;
    elem=new elemtype[inisize];
    Top=-1;
}

template <class elemtype>
void seqstack<elemtype>::doublespace()
{
    elemtype *tmp=elem;

    elem=new elemtype[maxsize*2];

    for(int i=0;i<maxsize;i++)
    {
        elem[i]=tmp[i];
    }
    delete tmp;
}

template <class elemtype>
void seqstack<elemtype>::push(const elemtype &x)
{
     if(Top==maxsize)doublespace();
     elem[++Top]=x;
}

template <class elemtype>
void seqstack<elemtype>::pop()
{
    if(isempty())throw outofbound();
    Top--;
}

template<class elemtype>
elemtype seqstack<elemtype>::top()const
{
    if(isempty())throw outofbound();
    return elem[Top];
}

template <class elemtype>
bool seqstack<elemtype>::isempty()const
{
    return Top==-1;
}

class ERROR {};

template<class elemtype>
class linkqueue
{
private:
	struct node
	{
		elemtype data;
		node *next;
		node(const elemtype&x, node *ne = NULL)
		{
			data = x;
			next = ne;
		}
		node() :next(NULL) {}
		~node() {}

	};

	node *Front, *Rear;

public:
	linkqueue();
	~linkqueue();
	bool isempty()const;
	void enqueue(const elemtype&x);
	elemtype dequeue();
	elemtype gethead()const;
};

template <class elemtype>
linkqueue<elemtype>::linkqueue()
{
	Front = Rear = NULL;
}

template<class elemtype>
linkqueue<elemtype>::~linkqueue()
{
	node *tmp;
	while (Front)
	{
		tmp = Front;
		Front = Front->next;
		delete tmp;
	}
}

template<class elemtype>
bool linkqueue<elemtype>::isempty()const
{
	return Front == NULL;
}

template <class elemtype>
void linkqueue<elemtype>::enqueue(const elemtype &x)
{
	if (isempty())Rear = Front = new node(x);
	else
	{
		Rear->next = new node(x);
		Rear = Rear->next;
	}
}

template<class elemtype>
elemtype linkqueue<elemtype>::dequeue()
{
	if (isempty())throw ERROR();
	node *tmp = Front;
	elemtype Tmp = Front->data;
	Front = Front->next;
	if (Front == NULL)Rear = NULL;
	delete tmp;
	return Tmp;
}

template <class elemtype>
elemtype linkqueue<elemtype>::gethead()const
{
	if (isempty())throw ERROR();
	return Front->data;
}

template<class elemtype>
class binarytree
{
private:
    struct Node
    {
        elemtype data;
        Node *left;
        Node *right;

        Node (const elemtype &x,Node *l=NULL,Node*r=NULL)
        {
            data=x;
            left=l;
            right=r;
        }
        Node():left(NULL),right(NULL){}
        ~Node(){}
    };
    Node *root;

    Node **Data;//存放新节点


    void Clear(binarytree<elemtype>::Node *&t);
public:
    binarytree(const elemtype &x){root=new Node(x);Data=new Node*[100000];}
    binarytree():root(NULL){Data=new Node*[100000];}
    ~binarytree();
    void creattree(int N);
    void Clear();
    bool isempty()const;
    void levelorder()const;
    void preorder() const;
    void postorder() const;
};

template<class elemtype>
bool binarytree<elemtype>::isempty()const
{
	return root == NULL;
}

template<class elemtype>
void binarytree<elemtype>::Clear(binarytree<elemtype>::Node *&t)
{
	if (root == NULL)return;
	Clear(t->right);
	Clear(t->left);
	delete t;
	t = NULL;
}

template<class elemtype>
void binarytree<elemtype>::Clear()
{
	Clear(root);
}

template<class elemtype>
binarytree<elemtype>::~binarytree()
{
	Clear(root);

}

template<class elemtype>
void  binarytree<elemtype>::levelorder()const
{
	if(!root)return ;
	linkqueue<Node*> q;
	seqstack<Node*>s;
	Node*tmp;
    s.push(root);

	while (!s.isempty())
	{
		tmp=s.top();
		s.pop();
		cout<<tmp->data<<" ";
		if(tmp->left)q.enqueue(tmp->left);
		//如果有儿子，将儿子存进队列
		if(tmp->right)s.push(tmp->right);
		//如果有兄弟将兄弟放进栈
		else s.push(q.dequeue());
		//如果没有兄弟了，将对列里保存的儿子输入栈
	}
}

template <class elemtype>
void  binarytree<elemtype>::creattree(int N)
{
    int pi,qi,vi;
    root=Data[0];

    for(int i=0;i<N;i++)
    {
        cin>>pi>>qi>>vi;
        //判断是否有左右孩子将新节点存入栈
        if(pi==0&&qi==0)Data[i]=new Node(vi,NULL,NULL);
            else if(pi==0&&qi!=0)Data[i]=new Node(vi,NULL,Data[qi-1]);
              else if(pi!=0&&qi!=0)Data[i]=new Node(vi,Data[pi-1],Data[qi-1]);
                else Data[i]=new Node(vi,Data[pi-1],NULL);

        if(Data[i]->left==root||Data[i]->right==root)root=Data[i];
        //找根
    }
}


template<class elemtype>
void binarytree<elemtype>::preorder()const
{
    if(!root)return;
    seqstack<Node*> s;
    Node*p;
    s.push(root);

    cout<<endl;
    while(!s.isempty())
    {
        p=s.top();s.pop();
        cout<<p->data<<" ";
        if(p->right)s.push(p->right);
        //如果有兄弟将兄弟存入栈
        if(p->left)s.push(p->left);
        //如果有孩子将孩子存入栈
    }
}

template<class elemtype>
void binarytree<elemtype>::postorder()const
{
    if(!root)return ;
    seqstack<Node*> s1;seqstack<int> s2;
    Node *p;int a;
    s1.push(root);s2.push(0);

    while(!s1.isempty())
    {
        p=s1.top();a=s2.top();
        s1.pop();s2.pop();
        if(++a==2)//第二次出栈才能被访问
        {
            cout<<p->data<<" ";
            if(p->right)//访问之后如果有兄弟输入兄弟
            {
                s1.push(p->right);
                s2.push(0);
            }
            continue;
        }
        s1.push(p);s2.push(a);//再次入栈
        if(s2.top()==1)
        {
            if(p->left)//如果有儿子输入儿子。
            {
                s1.push(p->left);
                s2.push(0);
            }
        }
    }
}

int main()
{
    int N;
    binarytree<int> bt;
    cin>>N;
    bt.creattree(N);
    cout<<endl;
    bt.preorder();
    cout<<endl;
    bt.postorder();
    cout<<endl;
    bt.levelorder();

    return 0;
}
