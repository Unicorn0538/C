#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <iostream>
using namespace std;
#include "linkqueue.h"
#include "linkstack.h"

template<class elemtype>
class binarytree
{
	friend  void printtree(const binarytree &t, elemtype flag);
private:
	struct node
	{
		node *left, *right;
		elemtype data;

		node():left(NULL),right(NULL){}
		node(elemtype x,node *r,node *l):data(x),right(r),left(l){}
		~node(){}
	};

	node *root;  //二叉树的节点

public:
	binarytree():root(NULL){}
	binarytree(elemtype x) { root = new node(x); }
	~binarytree();
	void Clear();
	bool isempty()const;
	elemtype Root(elemtype flag)const;
	elemtype lchild(elemtype x, elemtype flag)const;
	elemtype rchild(elemtype x, elemtype flag)const;
	void delleft(elemtype x);
	void delright(elemtype x);
	void preorder()const;
	void midorder()const;
	void postorder()const;
	void levelorder()const;
	void creattree()const;
	elemtype parent(elemtype x, elemtype flag)const { return flag; }

private:
	node *Find(elemtype x, node *t)const;
	void Clear(node *&t);
	void preorder(node *t)const;
	void midorder(node *t)const;
	void postorder(node *t)const;

};

template<class elemtype>
bool binarytree<elemtype>::isempty()const
{
	return root == NULL;
}

template<class elemtype>
elemtype binarytree<elemtype>::Root(elemtype flag)const
{
	if (root == NULL)return flag;
	else return root->data;
}

template<class elemtype>
void binarytree<elemtype>::Clear(binarytree<elemtype>::node *&t)
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

/*template<class elemtype>
void binarytree<elemtype>::preorder(binarytree<elemtype>::node *t)const
{
	if (root == NULL)return;
	cout << t->data << " ";
	preorder(t->left);
	preorder(t->right);

}

template<class elemtype>
void binarytree<elemtype>::preorder()const
{
	cout << "the preorder is:" << " ";
	preorder(root);
}*/

template<class elemtype>
void binarytree<elemtype>::preorder()const
{
    if(!root)return;
    linkstack<node *> s;
    node*p;

    s.push(root);
    while(!s.isempty())
    {
        p=s.top();
        cout<<p->data<<" ";
        s.pop();

        if(p->right)s.push(p->right);
        if(p->left)s.push(p->left);
    }

}

/*template<class elemtype>
void binarytree<elemtype>::midorder(binarytree<elemtype>::node*t)const
{
	if (t == NULL)return;
	midorder(t->left);
	cout << t->data << " ";
	midorder(t->right);

}

template<class elemtype>
void binarytree<elemtype>::midorder()const
{
	cout << "the midorder is:" << " ";
	midorder(root);

}*/

template<class elemtype>
void binarytree<elemtype>::midorder()const  //中序遍历
{
    if(!root)return;

    linkstack<node*> s;
    node* p=root;

    s.push(root);
    while(p->left)
    {
        s.push(left);
        p=p->next;
    }

    while(!s.isempty())
    {
        p=s.top();
        cout<<p->data<<" ";
        s.pop();

        if(p->right)
        {
            s.push(p->right);
            p=p->right;
            while(p->left)
            {
                s.push(p->left);
                p=p->left;
            }
        }
    }
}

/*template<class elemtype>
void binarytree<elemtype>::postorder(binarytree<elemtype>::node*t)const

{
	if (t = NULL)return;
	postorder(t->left);
	postorder(t->right);
	cout<<t->data<<" "；
}

template<class elemtype>
void binarytree<elemtype>::postorder()const
{
	cout << "the postorder is:  ";
	postorder(root);

}*/

template <class elemtype>
void binarytree<elemtype>::postorder()const
{
    if(!root)return;
    linkstack<node*> s1;
    linkstack<int> s2;
    node *p=root;
    int a=0;

    s1.push(root);s2.push(a);
    while(p->left)
    {
        s1.push(p->left);
        s2.push(a);
        p=p->left;
    }

    while(s1.isempty())
    {
        p=s1.top();

        if(s2.top()==0)
        {
            s2.pop();
            s2.push(1);
            if(p->right){s1.push(p->right);s2.push(0);p=s2.top();}
        }

        if(s2.top()==1)
        {
            s2.pop();
            s2.push(2);
            while(p->left)
            {
                s1.push(p->left);
                s2.push(0);
                p=p->left;
            }
        }

        if(s2.top()==2)
        {
            p=s1.top();
            cout<<p->data<<" ";
            s1.pop();
            s2.pop();
        }
    }
}

template<class elemtype>
void binarytree<elemtype>::levelorder()const
{
	linkqueue<node*> q;
	node*tmp;

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
binarytree<elemtype>::Find()




#endif // BINARYTREE_H_INCLUDED
/*struct stnode
{
    node *Node;
    int times;
    stnode(node *N=NULL):Node(N),times(0){}
};

template<class elemtype>
void binarytree<elemtype>::midorder()const
{
    linkstack<stnode> s;
    stnode p(root);
    s.push(p);

    while(!s.isempty())
    {
        p=s.pop();
        if(++p.times==2)
        {
            cout<<p->Node->data;
            if(p->Node->right)
                s.push(stnode(p.Node->right));
        }
        else{
            s.push(p);
            if(p->Node->left)
                s.push(stnode(p.Node->left));
        }
    }

}

template<class elemtype>
void binarytree<elemtype>::postorder()const
{
    linkstack<stnode> s;
    stnode p(root);

    s.push(p);

    while(!s.isempty())
    {
        p=s.pop();
        if(++p.times==3)
        {
            cout<<p->Node->data<<" ";
            continue;
        }
        s.push(p);
        if(p.times==1)
        {
            if(p->Node->left)
            s.push(stnode(p.Node->left));
        }
        else{
            if(p->Node->right)
                s.push(stnode(p.Node->right));
        }
    }
}
*/
