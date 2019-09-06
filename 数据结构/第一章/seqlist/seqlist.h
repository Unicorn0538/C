//线性表顺序结构的实现

#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED

#include<iostream>
using namespace std;
template <class elemType>
class list
{ public:
     virtual int length() const = 0;
     virtual int Search(const elemType &x) const = 0 ;
     virtual elemType visit(int i) const = 0;
     virtual void Insert(int i, const elemType &x) = 0;
     virtual void Remove(int i) = 0;
     virtual void Clear() = 0;
     virtual void traverse() const = 0;
     virtual ~list() {};
};


class outofbound{};
class ilegalsizze{};
template<class elemtype>
class seqlist:public list<elemtype>
{
private:
    elemtype *data;
    int currentsize,maxsize;
    void doublesize();
public:
    seqlist(int inisize=10);
    ~seqlist(){delete []data;}
    int Search(const elemtype&x)const;
    //if result>=0,result is  subscript,else is inexistence
    void Insert(int i,const elemtype&x);
    //i is subscript
    elemtype visit(int i)const;
    void Remove (int i);
    void Clear();
    void traverse()const;
    int length()const;
};


#endif // SEQLIST_H_INCLUDED
