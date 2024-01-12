#include <iostream>
#include "SortedSet.h"
using namespace std;

int main()
{
    SortedSet<int> Obj;
    SortedSet<int> Obj2;
    Obj.insert(5);
    Obj.insert(4);
    Obj.insert(3);
    // Obj.insert(4);
    // Obj.insert(10);
    // Obj.insert(50);
    // Obj.insert(60);
    // Obj.Remove(15);  // Remove from Location 7 
    
    // Inserting in List 2 
    Obj2.insert(1);
    Obj2.insert(2);
    Obj2.insert(3);

    // Prinitng Both Lists 
    Obj.print();
    Obj2.print();

    Obj.Union(Obj2);
    Obj.print();
}