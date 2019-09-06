#include <iostream>
#include "linkqueue.h"
using namespace std;

int main()
{
    linkqueue <int> s;
  for (int i=0; i<10; ++i) s.enqueue(2*i);
  while (!s.isempty())  cout << s.dequeue() << ' ';
  cout << endl;

}
