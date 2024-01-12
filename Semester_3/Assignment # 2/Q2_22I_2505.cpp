#include <iostream>
#include <exception>

using namespace std;

template <class T1>

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
        Prev = NULL;
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

//? A Stack implemented by a doubly Link list 
class Stack
{
    Node<T> *Top, *Bottom;
    int Size;
    //* A Direction to flip stack in O(1)
    bool Direction;

public:
    //? Constructor
    Stack()
    {
        Top = NULL;
        Bottom = NULL;
        Size = 0;
        Direction = true;
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
        if (Direction)
        {
            this->Top->Next = Temp;
            Temp->Prev = this->Top;
            this->Top = Temp;
            Size++;
            return;
        }
        else{
            Temp->Next=this->Bottom;
            this->Bottom->Prev=Temp;
            Temp->Prev=NULL;
            this->Bottom=Temp;
            Size++;
            return;
        }
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

        // Poping from top of the stack
        if(Direction)
        {
        Temp = this->Top;
        tempVar = this->Top->Data;
        this->Top = this->Top->Prev;
        this->Top->Next = NULL;
        delete Temp;
        this->Size--;
        return tempVar;
        }
        else{
            Temp=this->Bottom->Next;
            tempVar=this->Bottom->Data;
            Temp->Prev=NULL;
            this->Bottom->Next=NULL;
            delete this->Bottom;
            this->Bottom=Temp;
            return tempVar;
        }
    }

    //? Fliping a Stack in O(1)
    void Flip_Stack()
    {
        //* Just Changing the Direction
        if (Direction)
            Direction = false;
        else
            Direction = true;
    }

    //? Printing the Stack from top to bottom
    void Print(Node<T> *temp)
    {
        //* Base Condition
        if (temp == NULL)
            return;

        //* Recursive Function Call
        if (this->Direction)
        {
            Print(temp->Next);
            cout << temp->Data << " ";
        }
        else
        {
            cout << temp->Data << " ";
            Print(temp->Next);
        }

        if (temp == this->Bottom)
            cout << endl
                 << endl;
    }

};

int main()
{
    Stack<int> Tayyab;
    Tayyab.Push(1);
    Tayyab.Push(2);
    Tayyab.Push(3);
    Tayyab.Push(4);
    Tayyab.Print(Tayyab.GetBottom());
    Tayyab.Push(5);
    Tayyab.Push(6);
    Tayyab.Pop();
    Tayyab.Print(Tayyab.GetBottom());
    Tayyab.Flip_Stack();
    Tayyab.Push(0);
    Tayyab.Print(Tayyab.GetBottom());
}