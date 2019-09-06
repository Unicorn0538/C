#include <iostream>

using namespace std;
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

    Node **Data;//存放新节点
    Node *root; //根

    void Clear(binarytree<elemtype>::Node *&t);
public:
    binarytree(const elemtype &x){root=new Node(x);Data=new Node*[100000];}
    binarytree():root(NULL){Data=new Node*[100000];}
    ~binarytree();
    void creattree(int N);
    void Clear();
    bool isempty()const;
    bool levelorder()const; //层次遍历判断是否为完全二叉树
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
bool binarytree<elemtype>::levelorder()const
{
	if(!root)return 0;
	linkqueue<Node*> q;
	Node*tmp;

	q.enqueue(root);

	while (!q.isempty())
	{
		tmp = q.dequeue();
		if(tmp->right!=NULL&&tmp->left==NULL)return 0;
		//如果只有有孩子，必为非完全二叉树
		else if(tmp->right!=NULL&&tmp->left!=NULL)
        {
            q.enqueue(tmp->left);
            q.enqueue(tmp->right);
        }
        else if((tmp->left!=NULL&&tmp->right==NULL)||(tmp->left==NULL&&tmp->right==NULL))
        {//如果左右孩子都没有或者只有左孩子判断剩余的节点是否为叶子节点
            while(!q.isempty())
            {
                tmp=q.dequeue();
                if(tmp->left!=NULL||tmp->right!=NULL)return 0;
                //如果有非叶子节点，必不是完全二叉树
            }
        }

	}
	return 1;
}

template <class elemtype>
void  binarytree<elemtype>::creattree(int N)
{
    int pi,qi;
    root=Data[0];//临时根
    for(int i=0;i<N;i++)
    {
        cin>>pi>>qi;
        //判断是否有左右孩子，将新节点存进数组
        if(pi==0&&qi==0)Data[i]=new Node();
            else if(pi==0&&qi!=0)Data[i]=new Node(i,NULL,Data[qi-1]);
              else if(pi!=0&&qi!=0)Data[i]=new Node(i,Data[pi-1],Data[qi-1]);
                else Data[i]=new Node(i,Data[pi-1]);

         if(Data[i]->left==root||Data[i]->right==root)root=Data[i];
         //如果该节点的孩子指向临时根，那这个节点赋为临时根
    }

}



int main()
{
    int N;
    binarytree<int> bt(0);
    cin>>N;
    bt.creattree(N);
    if(bt.levelorder())
        cout<<"Y"<<endl;
    else cout<<"N"<<endl;
    return 0;
}
