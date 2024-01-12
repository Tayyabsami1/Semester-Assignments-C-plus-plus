#pragma once
#include <iostream>

using namespace std;

template <class T1>

class Node
{
public:
    T1 Data;
    Node* Next;

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
class SortedSet
{
    int Size;
    Node<T>* Head;
    Node<T>* Tail;

public:
    // Default Constructor
    SortedSet()
    {
        Size = 0;
        Head = NULL;
        Tail = NULL;
    }

    T getSize()
    {
        return this->Size;
    }

    void insert(T const data)
    {
        Node<T>* NewNode = new Node<T>(data);
        if (Size == 0)
        {
            Head = NewNode;
            Tail = NewNode;
            Size++;
            return;
        }

        else
        {
            Node<T>* Temp = Head;
            Node<T>* Prev = Head;

            while (Temp != NULL)
            {
                if ((data < Temp->Data) && (Temp == Head))
                {
                    NewNode->Next = Temp;
                    Head = NewNode;
                    Size++;
                    break;
                }

                if (data < Temp->Data)
                {
                    if (data == Prev->Data)
                    {
                        cout << "Sorry " << data << " is already in the List\n";
                        break;
                    }

                    NewNode->Next = Temp;
                    Prev->Next = NewNode;
                    Size++;
                    break;
                }

                if ((Temp->Next == NULL))
                {
                    if (Temp->Data == data)
                    {
                        cout << "Sorry " << data << " is already in the List\n";
                        break;
                    }

                    Temp->Next = NewNode;
                    NewNode->Next = NULL;
                    Tail = NewNode;
                    Size++;
                    break;
                }
                Prev = Temp;
                Temp = Temp->Next;
            }
        }
    }

    void Remove(int const index)
    {
        if (index > Size || index<1)
        {
            cout << "This Index doesn't exist in the link list \n";
            return;
        }

        if (index == 1)
        {
            Node<T>* temp = Head;
            Head = Head->Next;
            temp->Next = NULL;
            delete temp;
            Size--;
        }
        else
        {
            Node<T>* Current = Head;
            Node<T>* Prev = NULL;
            int currPos = 1;

            while (currPos < index)
            {
                Prev = Current;
                Current = Current->Next;
                currPos++;
            }

            Prev->Next = Current->Next;
            Current->Next = NULL;
            delete Current;

            if (Prev->Next == NULL)
            {
                Tail = Prev;
            }
            Size--;
        }
    }

    void insertAtStart(T const Element)
    {
        Node<T>* NewNode = new Node<T>(Element);
        if (Size == 0)
        {
            Head = NewNode;
            Tail = NewNode;
            Size++;
        }
        else
        {
            NewNode->Next = Head;
            Head = NewNode;
            Size++;
        }
    }

    void InsertAtTail(T const d)
    {
        Node<T>* NewNode = new Node<T>(d);
        Tail->Next = NewNode;
        Tail = NewNode;
        Size++;
    }

    void Union(SortedSet<T> const& otherSet)
    {
        Node<T>* temp = this->Head;
        Node<T>* temp2 = otherSet.Head;
        Node<T>* LCurrent1 = this->Head;

        while (temp != NULL)
        {
            if (temp2 == NULL)
            {
                break;
            }

            if (temp->Data > temp2->Data)
            {
                if (temp == this->Head)
                {
                    this->insertAtStart(temp2->Data);
                    LCurrent1 = this->Head;
                    temp2 = temp2->Next;
                }
                else
                {
                    Node<T>* NewNode = new Node<T>(temp2->Data);
                    NewNode->Next = temp;
                    LCurrent1->Next = NewNode;
                    LCurrent1 = NewNode;
                    temp2 = temp2->Next;
                    Size++;
                }
                continue;
            }

            if (temp2 != NULL)
            {
                if (temp->Data == temp2->Data)
                {
                    temp2 = temp2->Next;
                    LCurrent1 = temp;
                    temp = temp->Next;
                }
                else
                {
                    LCurrent1 = temp;
                    temp = temp->Next;
                }
            }
        }

        while (temp2 != NULL)
        {
            if (this->Tail->Data != temp2->Data)
            {
                this->InsertAtTail(temp2->Data);
            }

            temp2 = temp2->Next;
        }
    }

    void Rotate(int K)
    {
        Node<T>* temp = Head;
        int counter = 1;
        while (K <1)
        {
            cout << "Invalid input\n Please Enter a number LESS than the Size of the List to rotate it \n";
            cin >> K;
        }

        if (K > this->Size) {
            K = K % Size;
        }

        if (K == 0)
        {
            return;
        }

        if (K == 1)
        {
            this->Head = temp->Next;
            Tail->Next = temp;
            Tail = temp;
            Tail->Next = NULL;
            return;
        }

        if (K == Size - 1)
        {
            while (counter < K)
            {
                temp = temp->Next;
                counter++;
            }

            Tail->Next = Head;
            Head = Tail;
            Tail = temp;
            Tail->Next = NULL;
            return;
        }
        else
        {
            while (counter < K)
            {
                temp = temp->Next;
                counter++;
            }
            Tail->Next = Head;
            Head = temp->Next;
            Tail = temp;
            Tail->Next = NULL;
            return;
        }
    }

    void print() const
    {
        if (this->Size == 0)
        {
            cout << "The List is eympty\n";
            return;
        }

        Node<T>* Temp = Head;

        while (Temp != NULL)
        {
            cout << Temp->Data << " ";
            Temp = Temp->Next;
        }
        cout << endl
            << Size << endl;
        cout << this->Head->Data << " " << this->Tail->Data << endl<<endl;
    }

    void reverseList()
    {
        Node<T>* Lastcurrent = NULL;
        Node<T>* Current = this->Head;
        Node<T>* CurrentNext;
        this->Tail = this->Head;
        while (Current != NULL)
        {
            CurrentNext = Current->Next;

            Current->Next = Lastcurrent;

            Lastcurrent = Current;
            Current = CurrentNext;
        }

        this->Head = Lastcurrent;
    }

    ~SortedSet()
    {
        delete Head;
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
};