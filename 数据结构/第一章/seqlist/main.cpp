//线性表的顺序实现


#include <iostream>
#include "seqlist.h"
using namespace std;

int main()
{

    seqlist<int> a;
    a.Insert(0,3);
    a.Insert(0,4);
    a.Insert(0,5);
    a.traverse();

    cout<<endl<<a.length()<<endl;
    cout<<a.Search(4)<<endl;
    cout<<a.visit(2)<<endl;
    //cout<<a.visit(4)<<endl;
    a.Remove(1);
    a.traverse();

    a.Clear();
    a.traverse();
    return 0;
}
