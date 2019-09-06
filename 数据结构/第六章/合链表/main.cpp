#include <iostream>
#include <cstring>
using namespace std;

template <class elemtype>
class seqlist
{
friend  seqlist<elemtype>operator+(const seqlist<elemtype> &a1,const seqlist<elemtype>&a2)
  {
      seqlist tmp(a1.currentsize+a2.currentsize);int j;
      for(j=0;j<a1.currentsize;j++)
        tmp.Insert(a1.data[j]);
      for(j=0;j<a2.currentsize;j++ )
        tmp.Insert(a2.data[j]);

      cout<<endl;
      for(j=0;j<tmp.currentsize;j++)
      {
          cout<<tmp.data[j]<<" ";
      }
      return tmp;
  }
private:
    elemtype *data;
    int maxsize;
    int currentsize;

    void doublespace();

public:
    seqlist(int S=10);
    ~seqlist(){delete []data;}
    void Insert(const elemtype &x);

};

template<class elemtype>
void seqlist<elemtype>::doublespace()
{
    elemtype *tmp=new elemtype[maxsize*2];
    if(!tmp)return;
    for(int j=0;j<currentsize;j++)
        tmp[j]=data[j];
    delete []data;
    data=tmp;
    maxsize=maxsize*2;
}
template<class elemtype>
seqlist<elemtype>::seqlist(int s)
{
    data=new elemtype[s];
    maxsize=s;
    currentsize=0;
}

template<class elemtype>
void seqlist<elemtype>::Insert(const elemtype &x)
{
    if(currentsize>=maxsize)doublespace();
    data[currentsize]=x;
    currentsize++;
}


int main()
{
    seqlist<int> a,b;
    int i = 0,lenga = 0,lengb = 0;
    cout<<"请输入第一个顺序表的长度";
    cin>> lenga ;

    while(lenga--)
    {
        cin>>i;
        a.Insert(i);
    }
    cout<<"请输入第二个顺序表的长度";
    cin>>lengb;
    while(lengb--)
    {
        cin>>i;
        b.Insert(i);
    }
    a+b;

    return 0;

}

