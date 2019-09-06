#include <iostream>

using namespace std;

template<class type>
class hftree
{
private:
    struct node
    {
        type data;
        int weight;
        int left,right,parent;
    };

    node *elem;
    int length;

public:
    struct hfcode
    {
        type data;
        string code;
    };

    hftree( type*v, int *w,int Size)
    {
        const int max_int = 32767;
        int min1,min2;//��С������С����Ȩֵ
        int x,y;  //��С��������С�����±�

        //�ó�ֵ
        length=2*Size;
        elem=new node [length];
        for (int i=Size;i<length;++i)
        {
            elem[i].weight=w[i-Size];
            elem[i].data=v[i-Size];
            elem[i].parent=elem[i].left=elem[i].right=0;
        }

        //�鲢ɭ���е���
        for(int i=Size-1;i>0;--i)
        {
            min1=min2=max_int;
            x=y=0;
            for(int j=i+1;j<length;++j)
            {
                if(elem[j].parent==0)
                   {
                    if(elem[j].weight<min1)
                    {
                       min2=min1;
                       min1=elem[j].weight;
                       x=y;
                       y=j;
                    }
                    else if(elem[j].weight<min2)
                    {
                        min2=elem[j].weight;
                        x=j;
                    }
                   }
            }

            elem[i].weight=min1+min2;
            elem[i].left=x;
            elem[i].right=y;
            elem[i].parent=0;
            elem[x].parent=i;
            elem[y].parent=i;
        }
    }

    void getcode(hfcode result[])//�ӹ����������ɹ���������
    {
        int Size=length*2;
        int p,s;
        //s��׷�ݹ��������ڴ���Ľڵ㣬p��s�ĸ��ڵ��±�

        for(int i=Size;i<length;++i)
        {//��ÿ��������ķ���
            result[i-Size].data=elem[i].data;
            result[i-Size].code=" ";
            p=elem[i].parent;
            s=i;

            while(p)//���׷��
            {
                if(elem[p].left==s)
                    result[i-Size].code='0'+result[i-Size].code;
                else result [i-Size].code='1'+result[i-Size].code;
                s=p;
                p=elem[p].parent;
            }
        }
    }

    ~hftree(){delete [] elem;}
};


int main()
{
    char ch[]={"aeistdn"};
    int w[]={10,15,12,3,4,13,1};
    hftree<char>tree(ch,w,7);
    hftree<char>::hfcode result[7];
    tree.getcode(result);

    for(int j=0;j<7;j++)
    {
        cout<<result[j].data<<' '<<result[j].code<<endl;
    }
    return 0;
}
