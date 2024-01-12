#include <iostream>

using namespace std;

class Customer
{
public:
    int Items_Number, Age;

    Customer()
    {
        this->Age = 0;
        this->Items_Number = 0;
    }
};

//? Node Class
template <typename T1>
class Node
{
public:
    Customer Data;
    Node<Customer> *Next;
    Node<Customer> *Prev;

    Node()
    {
        this->Next = NULL;
        this->Prev = NULL;
    }

    Node(T1 Data)
    {
        this->Data = Data;
        this->Next = NULL;
        this->Prev = NULL;
    }

    ~Node()
    {
        if (this->Next == NULL)
        {
            delete Next;
            delete Prev;
        }
    }
};

//? Queue Class
template <typename T>
class Queue
{
    Node<Customer> *Front;
    Node<Customer> *Rear;
    int Size;
    int No_of_Items;

public:
    //? Constructor
    Queue()
    {
        this->Rear = NULL;
        this->Front = NULL;
        Size = 0;
        this->No_of_Items = 0;
    }

    int Get_No_items()
    {
        return this->No_of_Items;
    }

    //? Destructor
    ~Queue()
    {
        Node<T> *Temp = this->Front;
        Node<T> *Temp2 = NULL;
        while (Temp != NULL)
        {
            Temp2 = Temp;
            Temp = Temp->Next;
            delete Temp2;
        }
        this->Front = NULL;
        this->Rear = NULL;
    }

    void Push(T n)
    {
        Node<T> *New_Node = new Node(n);

        //? If size is 0
        if (this->Size == 0)
        {
            this->Rear = New_Node;
            this->Front = New_Node;
            this->No_of_Items += New_Node->Data.Items_Number;
            this->Size++;
            return;
        }

        //? If person is the most senior
        if (New_Node->Data.Age > this->Front->Data.Age)
        {
            New_Node->Next = this->Front;
            New_Node->Prev = NULL;
            this->Front->Prev = New_Node;
            this->Front = New_Node;
            this->No_of_Items += New_Node->Data.Items_Number;
            this->Size++;
            return;
        }

        //? if he is equal to the most senior
        if (New_Node->Data.Age == this->Front->Data.Age)
        {
            if (this->Size == 1)
            {
                this->Rear->Next = New_Node;
                New_Node->Prev = this->Rear;
                this->Rear = New_Node;
                this->No_of_Items += New_Node->Data.Items_Number;
                this->Size++;
                return;
            }
            New_Node->Next = this->Front->Next;
            (this->Front->Next)->Prev = New_Node;
            this->Front->Next = New_Node;
            New_Node->Prev = this->Front;
            this->No_of_Items += New_Node->Data.Items_Number;
            this->Size++;
            return;
        }

        //? if he is less than or equal to the most junior
        if (New_Node->Data.Age <= this->Rear->Data.Age)
        {
            this->Rear->Next = New_Node;
            New_Node->Prev = this->Rear;
            this->Rear = New_Node;
            this->No_of_Items += New_Node->Data.Items_Number;
            this->Size++;
            return;
        }

        //? if he is in between the line
        Node<T> *temp = this->Front->Next;
        while (temp != NULL)
        {
            // ? If he has a brother in the line
            if (New_Node->Data.Age == temp->Data.Age)
            {
                New_Node->Next = temp->Next;
                temp->Next->Prev = New_Node;
                temp->Next = New_Node;
                New_Node->Prev = temp;
                this->No_of_Items += New_Node->Data.Items_Number;
                this->Size++;
                return;
            }
            //? If he is the only individual in the line
            if (New_Node->Data.Age > temp->Data.Age)
            {
                New_Node->Next = temp;
                temp->Prev->Next = New_Node;
                New_Node->Prev = temp->Prev;
                temp->Prev = New_Node;
                this->No_of_Items += New_Node->Data.Items_Number;
                this->Size++;
                return;
            }
        }
    }

    //? Poping an element from the rear of the queue
    void Pop()
    {
        if (this->Front == NULL)
        {
            cout << "The Queue is empty\n";
            return;
        }

        if (this->Size == 1)
        {
            this->Front->Next = NULL;
            delete this->Front;
            this->Size--;
            return;
        }

        T temp = this->Front->Data;
        Node<T> *temp_pointer = this->Front->Next;
        temp_pointer->Prev = NULL;
        this->Front->Next = NULL;
        this->Front->Prev = NULL;
        delete this->Front;
        this->Front = temp_pointer;
        this->Size--;
        return;
    }

    //? Get the element that is at the front
    T get_Front_Data()
    {
        return this->Front->Data;
    }

    //? Get the element that is at the back
    T get_Rear_Data()
    {
        return this->Rear->Data;
    }

    //? Returns the size of the queue
    int Get_Size()
    {
        return this->Size;
    }

    //? Printing the Queue from front to bottom
    void Print(int num)
    {
        Node<T> *temp = this->Front;
        cout << endl;
        if (temp == NULL)
        {
            return;
        }
        cout << "The Queue " << num << " is as follows : ";
        while (temp != NULL)
        {
            cout << "(" << temp->Data.Items_Number << "," << temp->Data.Age << ") ";
            temp = temp->Next;
        }
        cout << endl;
    }

    //? Checking if queue is empty or not
    bool is_Empty()
    {
        if (this->Front == NULL)
        {
            return true;
        }
        return false;
    }
};

void My_Printer(Queue<Customer> &Q1, Queue<Customer> &Q2, Queue<Customer> &Q3, Queue<Customer> &Q4)
{
    Q1.Print(1);
    Q2.Print(2);
    Q3.Print(3);
    Q4.Print(4);
}

int Find_Min(Queue<Customer> &Q1, Queue<Customer> &Q2, Queue<Customer> &Q3, Queue<Customer> &Q4)
{
    int min = 1, min_items = Q1.Get_No_items();

    if (min_items > Q2.Get_No_items())
    {
        min = 2;
        min_items = Q2.Get_No_items();
    }

     if (min_items > Q3.Get_No_items())
    {
        min = 3;
        min_items = Q3.Get_No_items();
    }

     if (min_items > Q4.Get_No_items())
    {
        min = 4;
        min_items = Q4.Get_No_items();
    }

    return min;
}

void Grocery_Store()
{
    char c;
    int mymin;
    Queue<Customer> Q1, Q2, Q3, Q4;
    Customer C1;
    do
    {
        cout << "Do you want to pay your bills\n";
        cin >> c;

        if(c=='N')
        {
            cout<<"Program exited successfully\n";
            exit(0);
        }

        if (c == 'Y')
        {
            cout << "Enter how many items do you want to purchase : ";
            cin >> C1.Items_Number;
            cout << "Enter your age : ";
            cin >> C1.Age;
            while(C1.Age<=0)
            {
                cout<<"Please input correct age : ";
                cin>>C1.Age;
            }

            if (Q1.is_Empty())
            {
                Q1.Push(C1);
                My_Printer(Q1, Q2, Q3, Q4);
                continue;
            }

            if (Q2.is_Empty())
            {
                Q2.Push(C1);
                My_Printer(Q1, Q2, Q3, Q4);
                continue;
            }

            if (Q3.is_Empty())
            {
                Q3.Push(C1);
                My_Printer(Q1, Q2, Q3, Q4);
                continue;
            }

            if (Q4.is_Empty())
            {
                Q4.Push(C1);
                My_Printer(Q1, Q2, Q3, Q4);
                continue;
            }

            mymin = Find_Min(Q1, Q2, Q3, Q4);
            if (mymin == 1)
            {
                Q1.Push(C1);
                My_Printer(Q1, Q2, Q3, Q4);
                continue;
            }

            if (mymin == 2)
            {
                Q2.Push(C1);
                My_Printer(Q1, Q2, Q3, Q4);
                continue;
            }

            if (mymin == 3)
            {
                Q3.Push(C1);
                My_Printer(Q1, Q2, Q3, Q4);
                continue;
            }

            if (mymin == 4)
            {
                Q4.Push(C1);
                My_Printer(Q1, Q2, Q3, Q4);
                continue;
            }
        }
    } while (c != 'N');
}

int main()
{
    Grocery_Store();
    return 0;
}