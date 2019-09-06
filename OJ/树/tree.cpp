//二叉树的递归实现
#include <iostream>
using namespace std;

class ERROR{};

template<class elemtype>
class linkqueue
{
private:
    struct node
    {
     elemtype data;
        node *next;
        node(const elemtype&x,node *ne=NULL)
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

    void enqueue(const elemtype&x)
    {
        if(isempty())Rear=Front=new node(x);
        else
        {
           Rear->next=new node(x);
           Rear=Rear->next;
        }
    }

 elemtype dequeue()
    {
       if(isempty())return 0;
       node *tmp=Front;
     elemtype Tmp=Front->data;
       Front=Front->next;
       if(Front==NULL)Rear=NULL;
       delete tmp;
       return Tmp;
    }

 elemtype gethead()const
    {
        if(isempty())return 0;
        return Front->data;
    }
};

template<class elemtype>
class binarytree
{
    friend void printtree(const binarytree &t,elemtype flag);
    private:
	struct binarynode
	{
		binarynode *left, *right;
		elemtype data;

		binarynode():left(NULL),right(NULL){}
		binarynode(elemtype x,binarynode *r=NULL,binarynode *l=NULL):data(x),right(r),left(l){}
		~binarynode(){}
	};

	binarynode *root;  //二叉树的节点

public:
	binarytree():root(NULL){}
	binarytree(const elemtype &x) { root = new binarynode(x); }
	~binarytree(){clear(root);}
	void Clear(){clear(root);}//删除树中的所有节点
	bool isempty()const{return root==NULL;}//判断是否位空树
	elemtype Root(elemtype flag)const//找根节点
    {if(root==NULL)return flag;else return root->data;}
	elemtype lchild(elemtype x, elemtype flag)const;//找x的左孩子
	elemtype rchild(elemtype x, elemtype flag)const;//找x的右孩子
	void delleft(elemtype x);//删除x的左子树
	void delright(elemtype x);
	void preorder()const{preorder(root);}  //前序遍历
	void midorder()const{midorder(root);}  //中序遍历
	void postorder()const{postorder(root);}//后序遍历
	void levelorder()const; //层次遍历
	void createtree(elemtype flag);  //创建二叉树
	elemtype parent(elemtype x, elemtype flag)const { return flag; }
    void maketree(const elemtype&x,binarytree&lt,binarytree&rt)
    {
        root = new binarynode(x,lt,rt);
        lt.root=NULL;
        rt.root=NULL;
    }

private:
	binarynode *Find(elemtype x, binarynode *t)const
    {
        binarynode *tmp;
        if(root==NULL)return NULL;
        if(t->data==NULL)return t;
        if(tmp=Find(x,t->left))return tmp;
        else return Find(x,t->right);
    }
	void clear(binarynode *&t);
	void preorder(binarynode *t)const;
	void midorder(binarynode *t)const;
	void postorder(binarynode *t)const;

};

template<class elemtype>
void binarytree<elemtype>::clear(binarytree<elemtype>::binarynode *&t)
{
	if (root == NULL)return;
	clear(t->right);
	clear(t->left);
	delete t;
	t = NULL;
}

template<class elemtype>
void binarytree<elemtype>::preorder(binarytree<elemtype>::binarynode *t)const
{
	if (root == NULL)return;
	cout << t->data << " ";
	preorder(t->left);
	preorder(t->right);

}

template<class elemtype>
void binarytree<elemtype>::midorder(binarytree<elemtype>::binarynode*t)const
{
	if (t == NULL)return;
	midorder(t->left);
	cout << t->data << " ";
	midorder(t->right);

}

template<class elemtype>
void binarytree<elemtype>::postorder(binarytree<elemtype>::binarynode*t)const

{
	if (t == NULL)return;
	postorder(t->left);
	postorder(t->right);
	cout<<t->data<<" ";
}

template<class elemtype>
void binarytree<elemtype>::levelorder()const
{
	linkqueue<binarynode*> q;
	binarynode*tmp;

	cout << "the levelorder is:  ";
	q.enqueue(root);

	while (!q.isempty())
	{
		tmp = q.dequeue();
		cout << tmp->data << " ";
		if (tmp->left)q.enqueue(tmp->left);
		if (tmp->right)q.enqueue(tmp->right);
	}
}

template<class elemtype>
void binarytree<elemtype>::delleft(elemtype x)
{
   binarynode *tmp = Find(x,root);
   if(tmp==NULL)return;
   clear(tmp->left);
}

template<class elemtype>
void binarytree<elemtype>::delright(elemtype x)
{
   binarynode *tmp = Find(x,root);
   if(tmp==NULL)return;
   clear(tmp->right);
}

template<class elemtype>
elemtype binarytree<elemtype>::lchild(elemtype x,elemtype flag)const
{
   binarynode *tmp = Find(x,root);
   if(tmp==NULL||tmp->left==NULL)return flag;
   return tmp->left->data;
}

template<class elemtype>
elemtype binarytree<elemtype>::rchild(elemtype x,elemtype flag)const
{
   binarynode *tmp = Find(x,root);
   if(tmp==NULL||tmp->right==NULL)return flag;
   return tmp->right->data;
}

template<class elemtype>
void binarytree<elemtype>::createtree(elemtype flag)
{
    linkqueue<binarynode*>que;
    binarynode *tmp;
    elemtype x,rdata,ldata;
    cout<<"\nenter root:";
    cin>>x;
    root = new binarynode(x);
    que.enqueue(root);

    while(!que.isempty())
    {
        tmp = que.dequeue();
        cout<<"\nenter sons of"<<tmp->data<<"(end of "<<flag<<"):";
        cin>>ldata>>rdata;
        if(ldata!=flag)que.enqueue(tmp->left=new binarynode(ldata));
        if(rdata!=flag)que.enqueue(tmp->right=new binarynode(rdata));
    cout<<"create completed!\n";
    }
}

template<class elemtype>
void printtree(const binarytree<elemtype>&t,elemtype flag)
{
    linkqueue<elemtype> q;
    q.enqueue(t.root->data);
    cout<<endl;
    while(!q.isempty())
    {
        char p,l,r;
        p = q.dequeue();
        l = t.lchild(p,flag);
        r = t.rchild(p,flag);
        cout<<p<<" "<<l<<" "<<r<<endl;
        if(l!='@')q.enqueue(l);
        if(r!='@')q.enqueue(r);

    }
}

int main()
{
    binarytree<char>tree;
    tree.createtree('@');
    tree.preorder();
    tree.midorder();
    tree.postorder();
    tree.levelorder();
    printtree(tree,'@');
    tree.delleft('L');
    tree.delright('C');
    tree.delleft('C');
    printtree(tree,'@');
    return 0;
}
