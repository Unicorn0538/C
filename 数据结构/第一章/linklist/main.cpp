#include <iostream>
#include"linklist.h"
using namespace std;

int main()
{
     linklist<int> a;
     for(int i=0;i<10;i++)
        a.Insert(i,i);
     a.traverse();
     return 0;
}
