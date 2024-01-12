#include <iostream>
#include <exception>

using namespace std;
template <class T1>

//? A Node Class 
class Node
{
public:
    T1 Data;
    Node *Next;
    Node *Prev;

    Node(T1 data)
    {
        this->Data = data;
        Next = NULL;
    }

    ~Node()
    {
        if (this->Next == NULL)
        {
            delete Next;
        }
    }
};

template <class T>

//? A Stack implemented through Doubly Link list 
class UndoStack
{
    Node<T> *Top, *Bottom;
    int Size;

public:
    //? Constructor
    UndoStack()
    {
        Top = NULL;
        Bottom = NULL;
        Size = 0;
    }

    //? Return a pointer to the Top
    Node<T> *GetTop()
    {
        return this->Top;
    }

    //? Return a pointer to the Bottom
    Node<T> *GetBottom()
    {
        return this->Bottom;
    }

    //? Check if the Stack is empty
    bool isEmpty()
    {
        if (this->Top == NULL)
        {
            return true;
        }

        return false;
    }

    //? Checking if the Stack is empty
    bool isFull()
    {
        //* A Condition to Check if the Heap memory is Exhausted or not
        try
        {
            Node<T> *p = new int();
        }
        catch (bad_alloc &e)
        {
            return true;
        }
        return false;
    }

    //? A Function to pop data from the Stack
    void Push(T n)
    {
        //* Checking if the Heap memory is Exhausted or not
        try
        {
            Node<T> *Temp = new Node<T>(n);
            delete Temp;
        }
        catch (bad_alloc &e)
        {
            cout << "Stack Overflow\n";
            return;
        }

        //*  Made a New Node to Push
        Node<T> *Temp = new Node<T>(n);

        //*Checking If Size is Zero
        if (Size == 0)
        {
            Top = Temp;
            Bottom = Temp;
            Size++;
            return;
        }

        //* Condition for Size 1-100
        if (this->Size < 100)
        {
            this->Top->Next = Temp;
            Temp->Prev = this->Top;
            this->Top = Temp;
            Size++;
            return;
        }

        //* Condition for Size>100
        if (this->Size >= 100)
        {
            Node<T> *temp2 = this->Bottom->Next;
            delete this->Bottom;
            this->Bottom = temp2;
            Size--;
            this->Top->Next = Temp;
            Temp->Prev = this->Top;
            this->Top = Temp;
            Size++;
        }
        return;
    }

    //? A Function to Pop data in the Stack

    T Pop()
    {
        T tempVar = -1;
        Node<T> *Temp = NULL;

        if (this->Top == NULL)
        {
            cout << "Sorry Stack is empty\n";
            return tempVar;
        }
        //* Normal Pop when Size is less than 100
            Temp = this->Top;
            tempVar = this->Top->Data;
            this->Top = this->Top->Prev;
            this->Top->Next = NULL;
            delete Temp;
            this->Size--;
            return tempVar;
    }

    //? Printing the Stack from top to bottom
    void Print(Node<T> *temp)
    {
        //* Base Condition
        if (temp == NULL)
            return;

        //* Recursive Function Call
        Print(temp->Next);
        cout << temp->Data << " ";

        if (temp == this->Bottom)
            cout << endl
                 << endl;
    }
};

int main()
{
    UndoStack<int> Tayyab;
    for (int i = 1; i <= 100; i++)
    {
        Tayyab.Push(i);
    }

    Tayyab.Print(Tayyab.GetBottom());
    Tayyab.Push(101);
    Tayyab.Push(102);
    Tayyab.Push(103);
    Tayyab.Push(104);
    Tayyab.Print(Tayyab.GetBottom());
    Tayyab.Pop();
    Tayyab.Pop();
    Tayyab.Pop();
    Tayyab.Pop();

    Tayyab.Print(Tayyab.GetBottom());
}