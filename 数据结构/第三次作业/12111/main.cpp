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

        int  left;
        int right;
        int parent;

        Node (int l=0,int r=0,int p=0)
        {
            left=l;
            right=r;
            parent=p;
        }
        ~Node(){}
    };

    Node Data[100001];//����½ڵ�
    int root; //��


public:
    binarytree()
    {
        int left, right, Size;
        cin >> Size;//�ڵ���

        if (Size == 0) root = 0;
        else root = 1;


        for (int i = 1; i <= Size; i++)
        {
            cin >> left;
            Data[i].left = left;
            cin >> right;
            Data[i].right = right;
            Data[left].parent = Data[right].parent = i;
        }

        while (Data[root].parent)
            root = Data[root].parent;

    }
    ~binarytree(){}
    bool isempty()const;
    bool levelorder()const; //��α����ж��Ƿ�Ϊ��ȫ������
};

template<class elemtype>
bool binarytree<elemtype>::isempty()const
{
	return root == 0;
}

template<class elemtype>
bool binarytree<elemtype>::levelorder()const
{
	if(!root)return 0;
	linkqueue<Node> q;
	Node tmp;

	q.enqueue(Data[root]);

	while (!q.isempty())
	{
		tmp=q.dequeue();
		if(tmp.right!=0&&tmp.left==0)return 0;
		//���ֻ���к��ӣ���Ϊ����ȫ������
		else if(tmp.right!=0&&tmp.left!=0)
        {
            q.enqueue(Data[tmp.left]);
            q.enqueue(Data[tmp.right]);
        }
        else if((tmp.left!=0&&tmp.right==0)||(tmp.left==0&&tmp.right==0))
        {//������Һ��Ӷ�û�л���ֻ�������ж�ʣ��Ľڵ��Ƿ�ΪҶ�ӽڵ�
            while(!q.isempty())
            {
                tmp=q.dequeue();
                if(tmp.left!=0||tmp.right!=0){return 0;}
                //����з�Ҷ�ӽڵ㣬�ز�����ȫ������
            }
        }

	}
	return 1;
}


int main()
{
    binarytree<int> bt;
    if(bt.levelorder())
        cout<<"Y"<<endl;
    else cout<<"N"<<endl;
    return 0;
}
