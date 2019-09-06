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
    char ch[8];
    int size1,size2;
    cin.getline(ch,8);
    cin>>size1>>size2;
    if(strcmp(ch,"int")==0)
    {
       seqlist<int> list1(size1);
       seqlist<int> list2(size2);
        int tmp;
        for(int j=0;j<size1;j++)
        {
            cin>>tmp;
            list1.Insert(tmp);
        }
        for(int j=0;j<size2;j++)
        {
            cin>>tmp;
            list2.Insert(tmp);
        }
        list1+list2;
    }

        else if(strcmp(ch,"double")==0)
        {
            seqlist<double> list1(size1);
            seqlist<double> list2(size2);
            double tmp;
            for(int j=0;j<size1;j++)
            {
               cin>>tmp;
               list1.Insert(tmp);
            }
            for(int j=0;j<size2;j++)
            {
                cin>>tmp;
               list2.Insert(tmp);
            }
            list1+list2;
        }

        else if(strcmp(ch,"char")==0)
        {
            seqlist<char> list1(size1);
            seqlist<char> list2(size2);
            char tmp;
            for(int j=0;j<size1;j++)
            {
               cin>>tmp;
               list1.Insert(tmp);
            }
            for (int j=0;j<size2;j++)
            {
                cin>>tmp;
                list2.Insert(tmp);
            }
            list1+list2;
            }
        else return 0;
        return 0;
}


