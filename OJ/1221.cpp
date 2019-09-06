//二叉查找树递归算法
#include <iostream>
#include <cstring>
using namespace std;

template<class elemtype>
class binarysearchtree
{
    struct binarynode
    {
        elemtype data;
        binarynode *left;
        binarynode *right;

        binarynode(const elemtype &x,binarynode *lt=NULL,binarynode *rt=NULL)
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
    void remove_min(const elemtype &x){remove_min(x,root);}  //移除比x小的所有值
    void remove_max(const elemtype &x){remove_max(x,root);}  //移除比x大的所有值
    void remove_interval(const elemtype &x,const elemtype &y){if(x<=y)remove_interval(x,y,root);}  
    //移除x与y之间的所有值
    bool search_ith(int i ,elemtype &x){ return search_ith(i,x,root);} 
    //输出第i大的值

private:
    void insert(const elemtype &x,binarynode *&t);
    void remove(const elemtype &x,binarynode *&t);
    bool search(const elemtype &x,binarynode *&t);
    void makeempty(binarynode *&t);
    void remove_min(const elemtype &x,binarynode *&t);
    void remove_max(const elemtype &x,binarynode *&t);
    void remove_interval(const elemtype &x,const elemtype &y,binarynode *&t);
    bool search_ith(int i,elemtype &x,binarynode *&t);
    int size(binarynode *&t);
};


template <class elemtype>
void binarysearchtree<elemtype>::insert(const elemtype &x, binarynode *&t)
{
   if(t == NULL){t = new binarynode (x); return;}    //插入根节点
   if(x >= t -> data)insert(x, t->right);              //在右子树上插入
    else if(x < t -> data)insert(x, t->left);        //在左子树上插入
}

template<class elemtype>
void binarysearchtree<elemtype>::remove(const elemtype &x,binarynode *&t)
{
    if(t == NULL) return;
    
    if(x > t->data) remove(x , t->right);  //如果x大，在右子树上移除
     else if(x < t->data) remove(x , t->left) ;  //如果x小，在左子树上移除
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
              t = (t->left == NULL)? t->right : t->left;  //将孩子代替该节点
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
      else if(x < t->data)search(x, t->left);     //在左子树上查找
}

template<class elemtype>
void binarysearchtree<elemtype>::makeempty(binarynode *&t)
{
   if ( t == NULL ) return ;   //删完返回
   if (t->right)makeempty(t->right);  //删除右子树
   if (t->left)makeempty(t->left);    //删除左子树
   delete t;   //删除节点
}

template<class elemtype>
void binarysearchtree<elemtype>::remove_min(const elemtype &x,binarynode *&t)
{
    if(t == NULL)return;
    if(x > t->data)    //根节点与x的比较
    {
        binarynode *tmp = t;
        makeempty(t->left);  //删除左子树
        t = t->right;
        delete tmp;
        remove_min(x,t);
    }   
    else { remove_min(x,t->left);}   //在左子树上删除
}

template<class elemtype>
void binarysearchtree<elemtype>::remove_max(const elemtype &x,binarynode *&t)
{
   if(t == NULL)return;
   if(x < t->data)
   {
       binarynode *tmp=t;
       makeempty(t->right);
       t = t->left;
       delete tmp;
       remove_max(x,t);
   }
   else { remove_max(x,t->right);}
}

template<class elemtype>
void binarysearchtree<elemtype>::remove_interval(const elemtype &x,const elemtype &y,binarynode *&t)
{
   if(t == NULL)return;
   if(x >= t->data)remove_interval(x,y,t->right);
   else if(y <= t->data)remove_interval(x, y, t->left);
   else{remove(t->data,t);remove_interval(x,y,t);}
}

template<class elemtype>
bool binarysearchtree<elemtype>::search_ith(int i,elemtype &x,binarynode *&t)
{
   if(t == NULL)return false;
   int tmp = size(t->left);
   if(i-1 == tmp)
   {
       x = t->data;
       return true;
   } 
   else if(i <= tmp)search_ith(i, x, t->left);
   else search_ith(i-tmp-1,x,t->right);
  
}

template<class elemtype>
int binarysearchtree<elemtype>::size(binarynode *&t)
{
   if(t==NULL)return 0;
   return 1 + size(t->left) + size(t->right);
}

int main ()
{
    int N=0 ,tmp1,tmp2;
    binarysearchtree <int>bt; 
    char ch[25];
    cin>>N;

    while(N--)
    {
        ios::sync_with_stdio(false);
        cin>>ch;
        if(strcmp(ch,"insert")==0) { cin>>tmp1;bt.insert(tmp1);}
        if(strcmp(ch,"delete")==0) { cin>>tmp1;bt.remove(tmp1);}
        
        if(strcmp(ch,"find")==0) 
        { 
            cin>>tmp1;
            if(bt.search(tmp1))
                 cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }

        if(strcmp(ch,"find_ith")==0)
        {
            cin>>tmp1;
            if(bt.search_ith(tmp1,tmp2))
               cout<< tmp2<<endl;
            else cout<<"N"<<endl;
        }


        if(strcmp(ch,"delete_less_than")==0){cin>>tmp1;bt.remove_min(tmp1);}
        if(strcmp(ch,"delete_greater_than")==0){cin>>tmp1;bt.remove_max(tmp1);}
        if(strcmp(ch,"delete_interval")==0){cin>>tmp1>>tmp2;bt.remove_interval(tmp1,tmp2);}
        
    }
    return 0;
}