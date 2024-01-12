#include <iostream>
#include <unistd.h>

using namespace std;

template <typename T1>
//? Node CLass 
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

    //? Pusing element in the queue 
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
        this->Rear->Next = this->Front;
        this->Front->Prev = this->Rear;
        return;
    }

    //? Poping element from the rear 
    T Pop()
    {
        if (this->Front == NULL)
        {
            cout << "The Queue is empty\n";
            return 0;
        }

        T temp = this->Front->Data;
        Node<T> *temp_pointer = this->Front->Next;
        temp_pointer->Prev = NULL;
        this->Front->Next = NULL;
        this->Front->Prev = NULL;
        delete this->Front;
        this->Front = temp_pointer;
        if (this->Size > 2)
        {
            this->Front->Prev = this->Rear;
            this->Rear->Next = this->Front;
        }
        this->Size--;
        return temp;
    }

    //? Getters and Setters 
    T get_Front()
    {
        return this->Front->Data;
    }

    T get_Rear()
    {
        return this->Rear->Data;
    }

    int Get_Size()
    {
        return this->Size;
    }

    //? prininting soliders according to the Size of the queue
    void Print()
    {
        Node<T> *temp = this->Front;
        int count = 0;
        if (this->Size < 1)
        {
            cout << "The Queue is empty\n";
            return;
        }

        if (this->Size == 1)
        {
            cout << "    O   " << endl;
            cout << "   /|\\  " << endl;
            cout << "   / \\  " << endl;
            cout << "        " << endl;
            return;
        }

        while (count != 1)
        {
            cout << " O  ";
            if (temp->Next == this->Front)
            {
                count++;
                break;
            }
            temp = temp->Next;
        }

        cout << endl;

        temp = this->Front;
        count = 0;

        while (count != 1)
        {
            cout << "/|\\ ";
            if (temp->Next == this->Front)
            {
                count++;
                break;
            }
            temp = temp->Next;
        }
        cout << endl;

        temp = this->Front;
        count = 0;

        while (count != 1)
        {
            cout << "/ \\ ";
            if (temp->Next == this->Front)
            {
                count++;
                break;
            }
            temp = temp->Next;
        }

        cout << endl;
    }

    //? Deleting a required index 
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

    //? Main function to solve the probelem
    void Josephus_Problem(int n, int k, int I = 1)
    {
        if(k>1) k--;
        //* Condition to check size is greater than one 
        int index = I;
        if (this->Size < 1)
        {
            cout << "The Size should be greater that 1\n";
            return;
        }

        if (this->Size == 1)
        {
            cout << this->Front->Data << " won the game\n";
            return;
        }

        int mega = 0;
        //* Loop from starting person till one peron wins
        while (this->Size > 1)
        {
            // * Shifting the index according to the people to skip 
            index = (index + k) % (this->Size);
            if (index == 0)
            {
                index = this->Size;
            }

            //*Deleting the specified index 
            Delete_Index(index);
            this->Print();
            sleep(1);
        }

        cout << this->get_Front() << " is the winner\n";
    }
};

int main()
{
    Queue<int> Q1;
    int N, K, I;

    cout << "Enter the Number of soliders\n";
    cin >> N;
    cout << "Enter the Number of  People you want to skip\n";
    cin >> K;

    cout << "Enter the Starting Location\n";
    cin >> I;
    for (int i = 1; i <= N; i++)
    {
        Q1.Push(i);
    }

    Q1.Print();

    Q1.Josephus_Problem(N, K, I);
}
