#include <iostream>
using namespace std;

template<class elemtype>
class avltree
{
    struct avlnode
    {
        elemtype data;
        avlnode *left;
        avlnode *right;
        int height;

        avlnode(const elemtype d,avlnode *lt,avlnode *rt,int h=1)
         :data(d),left(lt),right(rt),height(1){}
    };

    avlnode *root;

    public:
    avltree(){root=NULL;}
    ~avltree(){makeempty(root);}
    elemtype *find(const elemtype &x)const;
    void insert(const elemtype &x){insert(x,root);}
    void remove(const elemtype &x){remove(x,root);}
    
    private:
    void insert(const elemtype &x,avlnode *&t);
    bool remove(const elemtype &x,avlnode *&t);
    void makeempty(avlnode*t);
    int height(avlnode *t)const{return t=NULL?0:t->height;}
    void LL(avlnode *&t);
    void LR(avlnode *&t){RR(t->left);LL(t);}
    void RL(avlnode *&t){LL(t->right);RR(t);}
    void RR(avlnode *&t);
    int max(int a,int b){return (a>b)?a:b;}
    bool adjust(avlnode *&t,int subtree);
};

template<class elemtype>
elemtype*avltree<elemtype>::find(const elemtype &x)const
{
   avlnode *t = root;

   while(t!=NULL&&t->data!=x)
     if(t->data > x)t=t->left;
     else t= t->right;

   if(t==NULL)return NULL;
   else return (elemtype *)t;
}

template<class elemtype>
void avltree<elemtype>::LL(avlnode * &t)
{
   avlnode *t1=t->left;
   t->left = t1->right;
   t1->right = t;
   t->height = max(height(t->left),height(t->right))+1;
   t1->height = max(height(t1->left),height(t))+1;
   t=t1;
}

template<class elemtype>
void avltree<elemtype>::RR(avlnode *&t)
{
   avlnode *t1 = t->right;
   t->right = t1->left;
   t1->left = t;
   t->height = max(height(t->left),height(t->right))+1;
   t1->height = max(height(t1->left),height(t->right))+1;
   t=t1;
}

template<class elemtype>
void avltree<elemtype>::insert(const elemtype &x,avlnode *&t)
{
    if(t==NULL) t=new avlnode (x,NULL,NULL);
    else if(x < t->data)
    {
        insert(x,t->left);
        if(height(t->left)-height(t->right)==2)
          if(x < t->left->data)LL(t);else LR(t);
    }
    else if(x > t->data)
    {
        insert(x,t->right);
        if(height(t->left)-height(t->right)==2)
          if(t->right->data < x)RR(t);else RL(t);
    }

    t->height = max(height(t->left),height(t->right))+1;
}

template<class elemtype>
bool avltree<elemtype>::remove(const elemtype &x,avlnode *&t)
{
    if(t=NULL)return true;

    if(x==t->data)
    {
        if(t->left == NULL||t->right==NULL)
        {
            avlnode *oldnode = t;
            t=(t->left!=NULL)?t->left:t->right;
            delete oldnode;
            return false;
        }
        else 
        {
            avlnode *tmp = t->right;
            while(tmp->left!=NULL)tmp = tmp->left;
            t->data = tmp->data;
            if(remove(tmp->data,t->right))return true;
            return adjust(t,1);
        }
    }

    if(x<t->data)
    {
        if(remove(x,t->left))return true;
        return adjust(t,0);
    }
    else
    {
        if(remove(x,t->right))return true;
        return adjust(t,1);
    }
}

template<class elemtype>
bool avltree<elemtype>::adjust(avlnode *&t,int subtree)
{
    if(subtree)
    {
        if(height(t->left)-height(t->right)==1)return true;
        if(height(t->right)-height(t->left)){--t->height;return false;}
        if(height(t->left->right) > height(t->left->left))
        {
            LR(t);return false;
        }
        LL(t);
        if(height(t->right)==height(t->left))return false;else return true;
    }
    else
    {
       if(height(t->right)-height(t->left)==1)return true;
       if(height(t->right)==height(t->left)){--t->height;return false;}
       if(height(t->right->left)>height(t->right->right))
       {
           RL(t);return false;
       }
       RR(t);
       if(height(t->right))==height(t->left))return false;else return true;
    }
}

template<class elemtype>
void avltree<elemtype>::makeempty(avlnode *t)
{
   if ( t == NULL ) return ;   //删完返回
   if (t->right)makeempty(t->right);  //删除右子树
   if (t->left)makeempty(t->left);    //删除左子树
   delete t;   //删除节点
}
