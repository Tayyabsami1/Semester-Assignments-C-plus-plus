#include "SortedSet.h"

#include <iostream>

using namespace std;

int main()
{
   SortedSet <int>ListObj;
   ListObj.insert(10);
   ListObj.insert(20);
   ListObj.insert(30);
   ListObj.insert(40);
   ListObj.insert(50);
   ListObj.insert(60);
   ListObj.Rotate(-1);
   ListObj.print();
}