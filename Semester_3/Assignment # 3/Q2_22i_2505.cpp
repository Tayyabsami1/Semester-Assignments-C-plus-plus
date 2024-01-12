#include <iostream>

using namespace std;

template <typename T1>

//? Node Class
class Node
{
public:
    T1 Data;
    Node<T1> *Next;
    Node<T1> *Prev;

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
    Node<T> *Front;
    Node<T> *Rear;
    int Size;

public:
    //? Constructor
    Queue()
    {
        this->Rear = NULL;
        this->Front = NULL;
        Size = 0;
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

    //? Empty the Queue
    void Make_Empty()
    {
        while (this->Size > 0)
        {
            this->Pop();
        }
        this->Front = NULL;
        this->Rear = NULL;
    }

    //? Pushing elements in the front of the queue
    void Push(T n)
    {
        Node<T> *New_Node = new Node(n);

        if (this->Size == 0)
        {
            this->Rear = New_Node;
            this->Front = New_Node;
            this->Size++;
            return;
        }

        this->Rear->Next = New_Node;
        New_Node->Prev = this->Rear;
        this->Rear = New_Node;
        this->Size++;
        return;
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
    T get_Front()
    {
        return this->Front->Data;
    }

    //? Get the element that is at the back
    T get_Rear()
    {
        return this->Rear->Data;
    }

    //? Returns the size of the queue
    int Get_Size()
    {
        return this->Size;
    }

    //? Printing the Queue from front to bottom
    void Print()
    {
        Node<T> *temp = this->Front;
        cout << endl;
        if (temp == NULL)
        {
            cout << "The Queue is empty\n";
            return;
        }
        cout << "The Queue is as follows\n";
        while (temp != NULL)
        {
            cout << temp->Data << "\n";
            temp = temp->Next;
        }
        cout << endl;
    }

    //? Delete a specific index in the queue
    void Delete_Index(int My_index)
    {
        int MainC = 1;
        Node<T> *temp = this->Front;

        while (My_index != MainC)
        {
            temp = temp->Next;
            MainC++;
        }

        if (temp == this->Front)
        {
            cout << this->Front->Data << " got eliminated\n";
            this->Pop();
            MainC = 1;
            return;
        }

        if (temp == this->Rear)
        {
            cout << this->Rear->Data << " got eliminated \n";
            temp = this->Rear->Prev;
            temp->Next = NULL;
            this->Rear->Prev = NULL;
            this->Front->Prev = temp;
            temp->Next = this->Front;
            this->Rear->Next = NULL;
            delete this->Rear;
            this->Rear = temp;
            this->Size--;
            MainC = 1;
            return;
        }
        else
        {
            cout << temp->Data << " got eliminated\n";
            Node<T> *temp2 = temp->Prev;
            temp2->Next = temp->Next;
            temp->Next->Prev = temp2;
            temp->Next = NULL;
            temp->Prev = NULL;
            this->Size--;
            delete temp;
            MainC = 1;
            return;
        }
    }

    //? Get Data of a specific index
    T Get_Index_Data(int pos)
    {
        Node<T> *Temp = this->Front;
        int counter = 0;
        while (counter < pos)
        {
            Temp = Temp->Next;
            counter++;
        }
        return Temp->Data;
    }

    //? Returns the max integer in the queue
    T Max_Finder()
    {
        T Data = this->Front->Data;
        Node<T> *Temp = this->Front->Next;

        while (Temp != NULL)
        {
            if (Data < Temp->Data)
            {
                Data = Temp->Data;
            }
            Temp = Temp->Next;
        }

        return Data;
    }

    //? Setting value of an index
    void Set_Index_Data(T Value, int pos)
    {
        Node<T> *Temp = this->Front;
        int counter = 0;
        while (counter < pos)
        {
            Temp = Temp->Next;
            counter++;
        }
        Temp->Data = Value;
    }

    //? Count sort algorithm for Count Sort
    void Count_Sort(int pos)
    {
        int count[10] = {0};

        for (int i = 0; i < this->Size; i++)
        {
            count[(this->Get_Index_Data(i) / pos) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] = count[i] + count[i - 1];
        }
        T Arr[this->Size];

        for (int i = this->Size - 1; i >= 0; i--)
        {
            Arr[--count[((this->Get_Index_Data(i) / pos) % 10)]] = this->Get_Index_Data(i);
        }

        for (int i = 0; i < this->Size; i++)
        {
            this->Set_Index_Data(Arr[i], i);
        }
    }

    // ? Find the maximum length of the string
    int Max_Finder_String()
    {
        Node<T> *Temp = this->Front;
        int Len = this->Front->Data.length();

        Temp = Temp->Next;
        while (Temp != NULL)
        {
            if (Len < Temp->Data.length())
            {
                Len = Temp->Data.length();
            }
            Temp = Temp->Next;
        }
        return Len;
    }

    //? Equalizes the length of each string
    void Appender(int L)
    {
        Node<T> *Temp = this->Front;
        while (Temp != NULL)
        {
            if (Temp->Data.length() < L)
            {
                while (Temp->Data.length() < L)
                {
                    Temp->Data += '!';
                }
            }
            Temp = Temp->Next;
        }
        return;
    }

    // ? Radix sorter for the sttrings
    void Radix_Sorter_String()
    {
        Queue<int> MyQueue;
        Queue<int> Queue2;
        Queue<string> MyCharQueue;
        if (typeid(T) == typeid(string))
        {
            int Max_L = this->Max_Finder_String();
            Appender(Max_L);

            Node<T> *My_Temp = this->Front;

            int count = 0;
            int asci;
            while (count < Max_L)
            {
                while (My_Temp != NULL)
                {
                    asci = My_Temp->Data[count];

                    if (asci > 90)
                        asci -= 32;

                    MyQueue.Push(asci);
                    Queue2.Push(asci);
                    MyCharQueue.Push(My_Temp->Data);
                    My_Temp = My_Temp->Next;
                }

                MyQueue.Radix_Sorter();

                for (int i = 0; i < this->Size; i++)
                {
                    for (int j = 0; j < this->Size; j++)
                    {
                        if (MyQueue.Get_Index_Data(i) == Queue2.Get_Index_Data(j))
                        {
                            if (i == j)
                                continue;

                            if (MyQueue.Get_Index_Data(i) == 33)
                            {
                                Queue2.Set_Index_Data(0, j);
                                continue;
                            }

                            if ((count > 0) && (this->Get_Index_Data(i)[count - 1] != MyCharQueue.Get_Index_Data(j)[count - 1]))
                            {
                                Queue2.Set_Index_Data(0, j);
                                continue;
                            }

                            if ((count > 0) && (this->Get_Index_Data(i)[0] != MyCharQueue.Get_Index_Data(j)[0]))
                            {
                                Queue2.Set_Index_Data(0, j);
                                continue;
                            }

                            this->Set_Index_Data(MyCharQueue.Get_Index_Data(j), i);
                            Queue2.Set_Index_Data(0, j);
                            break;
                        }
                    }
                }

                count++;
                My_Temp = this->Front;
                Queue2.Make_Empty();
                MyQueue.Make_Empty();
                MyCharQueue.Make_Empty();
            }
        }
    }

    //? Radix sorter for the integers
    void Radix_Sorter()
    {
        T Max = this->Max_Finder();

        for (int i = 1; Max / i > 0; i *= 10)
        {
            Count_Sort(i);
        }
        return;
    }
};

int main()
{
    int n, K;
    // string num;
    int num;
    // Queue<string> Q1;
    Queue<int> Q1;
    cout << "Enter the number of keys you want to Sort\n";
    cin >> n;

    cout << "Enter the number of digits each key will contain\n";
    cin >> K;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the input for " << i + 1 << endl;
        cin >> num;
        Q1.Push(num);
    }

    // Q1.Radix_Sorter_String();
    Q1.Radix_Sorter();
    Q1.Print();

    return 0;
}
