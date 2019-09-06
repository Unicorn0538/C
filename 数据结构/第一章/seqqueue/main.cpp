#include <iostream>
#include "seqqueue.h"
using namespace std;

int main()
{
   seqqueue <int> s;
  for (int i=0; i<10; ++i) s.enqueue(2*i);
  while (!s.isempty()) cout << s.dequeue() << ' ';
  cout << endl;

}
