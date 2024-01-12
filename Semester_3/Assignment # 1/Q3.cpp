#include "SortedSet.h"

#include <iostream>

using namespace std;

int main()
{
   SortedSet<int>Object;
   Object.insert(0);
   Object.insert(1);
   Object.insert(2);
   Object.insert(3);
   Object.insert(-109);
   Object.insert(1000);
   Object.print();
   Object.reverseList();
   Object.print();
}