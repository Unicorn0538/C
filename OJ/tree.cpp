#include <iostream>
using namespace std;

//交换二叉树的左右子树
/*template <class elemtype>
void tree<elemtype>::swaplr()
{
    swaplr(root);
}

template <class elemtype>
void tree<elemtype>::swaplr(node *n)
{
    node *p;
    if(n->left)swaplr(n->left);
    if(n->right)swaplr(n->right);

    //交换根节点的左右子树
    p=n->left;
    n->left = n->right;
    n->right = p;
}*/


//统计度数为二的节点数
/*template<class elemtype>
int tree<elemtype>::countdegreetwo()
{
    return countdegreetwo(root);
}

template<class elemtype>
int tree<elemtype>::coutdegreetwo(node *n)
{
    if(n==NULL)return 0;
    if(n->left&&n->right)
       return 1+coutdegreetwo(n->left)+coutdegreetwo(n->right);
    else
    return coutdegreetwo(n->left)+countdegreetwo(t->right);
    
}*/


//判断两颗二叉树是否对称
/*template<class elemtype>
bool checknode(binarynode<elemtype>::node *t1,binarynode<elemtype>::node *t2)
{
    if(t1 == nullptr && t2 == nullptr)return true;
    if(t1 ==nullptr||t2==nullptr)return false;
    if(t1->data != t2->data)return false;
    return checknode(t1->left,t2->right)&&checknode(t1->right&&t2->left);
}
*/

//假设树以儿子兄弟链的方式存储，求高度和规模
/*
template<class elemtype>
int tree<elemtype>::hight(node*t)
{
    node *tmp = t->son;
    int max = 0;
    int cur;

    while(tmp !=NULL)
    {
        cur = height(tmp);
        if(cur > max)max = cur;
        tmp = tmp->brother;
    }
    return max+1;
}

template <class elemtype>
int tree<elemtype>::size(node *t)
{
    node *tmp = t->son;
    int sz = 0;

    while(tmp != NULL)
    {
        sz += size(tmp);
        tmp = tmp->brother;
    }
    return sz+1;
}
*/