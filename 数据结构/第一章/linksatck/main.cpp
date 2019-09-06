#include <iostream>
#include "linkstack.h"
using namespace std;

int main()
{
    linkstack<int > a;
    for(int i=0;i<10;i++)
    {
        a.push(i);
    }
    for (int i=0;i<10;i++)
       cout<< a.pop()<<" ";
    return 0;
}
