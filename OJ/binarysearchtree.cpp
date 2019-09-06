//二叉查找树递归算法
#include <iostream>
using namespace std;

template<class elemtype>
class binarysearchtree
{
    struct binarynode
    {
        elemtype data;
        binarynode *left;
        binarynode *right;

        binarynode( elemtype &x, binarynode *lt=NULL,binarynode  *rt=NULL)
         :data(x),left(lt),right(rt){}
        binarynode():left(NULL),right(NULL){}
    };
    
    binarynode *root;

public:
    binarysearchtree(binarynode *t = NULL){root = t;}
    ~binarysearchtree(){makeempty(root);}    
    void insert(const elemtype &x){insert(x,root);}  //插入一个节点
    void remove(const elemtype &x){remove(x,root);}  //移除与x值相等的节点
    bool search(const elemtype &x){return search(x,root);}  //寻找是否存在x

private:
    void insert(const elemtype &x,binarynode *&t);
    void remove(const elemtype &x,binarynode *&t);
    bool search(const elemtype &x,binarynode *&t);
    void makeempty(binarynode *&t);
};


template <class elemtype>
void binarysearchtree<elemtype>::insert(const elemtype &x, binarynode *&t)
{
   if(t == NULL){t = new binarynode (x); return;}    //插入根节点
   if(x > t -> data)insert(x, t->right);              //在右子树上插入
    else if(x < t -> data)insert(x, t->left);        //在左子树上插入
}

template<class elemtype>
void binarysearchtree<elemtype>::remove(const elemtype &x,binarynode *&t)
{
    if(t == NULL) return;
    
    if(x > t->data) remove(x , t->right);  //如果x大，在右子树上移除
     else if(x < t->data) remove(x , t->left) ;//如果x小，在左子树上移除
       else   //找到x
       {
          if(t->right&&t->left)    //有两个孩子
          {
              binarynode *tmp = t->left;    //找左子树上的最小值
              while(tmp->right != NULL)tmp = tmp -> right;  //找到替身
              t->data = tmp->data;   //替换
              remove(t->data ,  t->left);  //在t的左子树上删除替身
          }
          else  //有一个孩子或叶子节点
          {
              binarynode *tmp = t ;    
              t = (t->left == NULL)? t->right : t->right;  //将孩子代替该节点
              delete tmp;   //删除原节点的空间
          }
           
       }
}

template<class elemtype>
bool binarysearchtree<elemtype>::search(const elemtype &x,binarynode *&t)
{
    if(t == NULL)return false;   
    if(x == t->data) return true;  //找到返回
    if(x > t->data)search(x, t->right);  //在右子树上查找
      else if(x < t->data)Search(x, t->left);     //在左子树上查找
}

template<class elemtype>
void binarysearchtree<elemtype>::makeempty(binarynode *&t)
{
   if ( t == NULL ) return ;   //删完返回
   if (t->right)makeempty(t->right);  //删除右子树
   if (t->left)makeempty(t->left);    //删除左子树
   delete t;   //删除节点
}

int main()
{
    binarysearchtree <int> a;
}