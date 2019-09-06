#include <iostream>
#include "dlinklist.h"
using namespace std;

/*int main()
{
    dlinklist<int> a;
   for(int i=0;i<10;i++)
   {
       a.Insert(i,i*2);
   }
   a.traverse();
   a.Remove(2);
   a.traverse();
}*/
int main()
{
    int m,n,k;

    cin>>n>>m>>k;
    dlinklist<int> lt;
    for(int i=0;i<n;i++)
        {
            lt.Insert(i,i+1);
        }

        lt.Find(m,k);
      return 0;
}
