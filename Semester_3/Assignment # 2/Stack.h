#include <iostream>
#include <exception>
#include <string>
#include <fstream>

using namespace std;

template <class T1>
//? Node Class
class Node
{
public:
    T1 Data;
    Node *Next;

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

//? Template based Stack class
class Stack
{
    Node<T> *Top, *Bottom;
    int Size;

public:
    Stack()
    {
        Top = NULL;
        Size = 0;
    }

    Node<T> *GetTop()
    {
        return this->Top;
    }

    T GetTopData()
    {
        T temp;
        if (this->Top != NULL)
            return this->Top->Data;
        else
            return temp;
    }

    bool isEmpty()
    {
        if (this->Top == NULL)
        {
            // cout << "Yes,The Stack is empty\n";
            return true;
        }
        // cout << "The Stack is not empty\n";
        return false;
    }

    bool isFull()
    {
        try
        {
            Node<T> *p = new int();
        }
        catch (bad_alloc &e)
        {
            // cout << "Yes the Stack is full\n";
            return true;
        }
        // cout << "No the Stack is not empty\n";
        return false;
    }

    void Print(Node<T> *temp)
    {
        if (temp == NULL)
            return;

        Print(temp->Next);

        cout << temp->Data << " ";

        if (temp == this->Top)
            cout << endl
                 << endl;
    }

    void Push(T n)
    {
        try
        {
            Node<T> *Temp = new Node(n);
            delete Temp;
        }
        catch (bad_alloc &e)
        {
            cout << "Stack Overflow\n";
            return;
        }

        Node<T> *Temp = new Node(n);
        if (Size == 0)
        {
            Top = Temp;
            Bottom = Temp;
            Size++;
            return;
        }

        Temp->Next = Top;
        Top = Temp;
        Size++;
        return;
    }

    T Pop()
    {
        T tempVar;
        if (this->Top == NULL)
        {
            cout << "Sorry Stack is empty\n";
            return tempVar;
        }
        Node<T> *Temp = this->Top;
        tempVar = this->Top->Data;
        Top = Top->Next;
        Temp->Next = NULL;
        delete Temp;
        return tempVar;
    }
};

class XMLData
{
    string FileName;

public:
    XMLData(string name)
    {
        this->FileName = name;
    }

    //? This will check the stack from top to bottom to find the matching tag

    void DepthChecker(Stack<string> &String_Stack, Stack<int> &Num_Stack, string to_find, int counter)
    {
        if (String_Stack.isEmpty())
        {
            cout << "Starting Tag of " << to_find << " missing at line number " << counter << endl;
            return;
        }
        if (to_find == String_Stack.GetTopData())
        {
            String_Stack.Pop();
            Num_Stack.Pop();
            return;
        }
        int Data = Num_Stack.GetTopData();
        string Data2 = String_Stack.GetTopData();
        Num_Stack.Pop();
        String_Stack.Pop();
        DepthChecker(String_Stack, Num_Stack, to_find, counter);
        Num_Stack.Push(Data);
        String_Stack.Push(Data2);
    }

    //? Main Function Open files and check all the probelms

    bool FileChecker()
    {
        //* An Object to read our file
        fstream myfile;

        //* Two Stacks one to Maintain Characters and other to maintain Strings
        Stack<char> CharString;
        Stack<string> String_Stack;
        Stack<int> Number_Stack;

        myfile.open(FileName, ios::in);

        //* Successful file opening message
        if (myfile.is_open())
        {
            cout << "File open successfully\n";
        }

        int counter = 0;
        string line;
        bool Condition = false, condition1 = false, condition3 = true, condition4 = true;

        //* This Loop run till the End of File
        while (getline(myfile, line))
        {
            //* To know the line number
            counter++;

            //* This Loop will run each line of file seperatly
            for (int i = 0; i < line.length(); i++)
            {

                //* Pushing opening tags and header ?
                if (CharString.isEmpty() && line[i] != '>')
                {
                    if (line[i] == '<' || line[i] == '?')
                        CharString.Push(line[i]);
                    continue;
                }

                //* Checking if xml header is present and written quickly
                if (line[i - 2] == '<' && line[i - 1] == '?')
                {
                    condition3 = false;
                    string temp = "";
                    while (line[i] != 32)
                    {
                        temp += line[i];
                        i++;
                    }

                    if (temp != "xml")
                    {
                        cout << "Xml Header is not correctly written\n";
                        condition1 = true;
                        condition3 = false;
                    }
                    else
                    {
                        condition1 = false;
                        condition3 = false;
                    }
                    i--;
                    continue;
                }

                //* Detecting > and finding its match
                if (CharString.GetTopData() == '<' && line[i] == '>')
                {
                    CharString.Pop();
                    continue;
                }

                //* Checking Syntax of comments
                if (line[i] == '!' && line[i - 1] == '<' && (line[i + 1] != '-' || line[i + 2] != '-'))
                {
                    cout << "Wrong Syntax for comment at line number " << counter << endl;
                    condition4 = false;
                }

                //* If match of > not found
                if (line[i] == '>' && CharString.GetTopData() != '<')
                {
                    if (CharString.GetTopData() == '"' || CharString.GetTopData() == '\'')
                    {
                        cout << "Missing closing quotation of " << CharString.GetTopData() << " at line number " << counter << endl;
                        continue;
                    }
                    cout << "Missing Opening tag of > at line number " << counter << endl;
                    continue;
                }

                //* Detecting if <> are both present
                else if ((CharString.GetTopData() != '<' && line[i] == '>'))
                {
                    if (CharString.GetTopData() == '"' || CharString.GetTopData() == '\'')
                        cout << "Missing ending quote of " << CharString.GetTopData() << " at line number " << counter << endl;
                    continue;
                    cout << "Missing < at line number " << counter << endl;
                    continue;
                }

                //* If ? Not found
                if (CharString.GetTopData() != '?' && line[i] == '?' && line[i + 1] == '>')
                {
                    cout << "Opening ? Not found of xml header at line number " << counter << endl;
                    continue;
                }

                //* Detecting ? and poping it
                if (CharString.GetTopData() == '?' && line[i] == '?')
                {
                    CharString.Pop();
                    continue;
                }

                //* Detecting end of double quotes
                if (CharString.GetTopData() == '"' && line[i] == '"' && line[i - 1] != '=')
                {
                    CharString.Pop();
                    if (CharString.GetTopData() == '=')
                    {
                        CharString.Pop();
                        continue;
                    }
                    else
                    {
                        CharString.Push('"');
                    }
                    continue;
                }

                //* Detecting ending of single quotes
                if (CharString.GetTopData() == '\'' && line[i] == '\'')
                {
                    CharString.Pop();
                    if (CharString.GetTopData() == '=')
                    {
                        CharString.Pop();
                        continue;
                    }
                    else
                    {
                        CharString.Push('\'');
                    }
                    continue;
                }

                //* Detecting ending of comments
                if (CharString.GetTopData() == '-' && line[i + 2] == '>' && line[i] == '-')
                {
                    CharString.Pop();
                    CharString.Pop();
                    i++;
                    continue;
                }

                //* Checking for opening brackets n ?
                if (line[i] == '<' || line[i] == '?')
                {
                    CharString.Push(line[i]);
                    continue;
                }

                //* Checking opening quotes
                if ((line[i] == '"' || line[i] == '\''))
                {
                    if (line[i - 1] == '=')
                    {
                        CharString.Push(line[i - 1]);
                    }
                    CharString.Push(line[i]);
                    continue;
                }

                //* Checking openings of Comments
                if (line[i] == '!' && line[i - 1] == '<' && line[i + 1] == '-' && line[i + 2] == '-')
                {
                    CharString.Push(line[i + 1]);
                    CharString.Push(line[i + 2]);
                }

                //* Cheking opening tags
                if ((line[i - 1] == '<') && line[i] != '/' && line[i] != '!')
                {
                    string temp = "";
                    while (line[i] != '>')
                    {
                        if (line[i] == 32)
                        {
                            Condition = true;
                            break;
                        }

                        temp += line[i];
                        i++;
                    }
                    if (Condition)
                    {
                        if (temp != "xml")
                        {
                            String_Stack.Push(temp);
                            Number_Stack.Push(counter);
                        }
                        Condition = false;
                        continue;
                    }

                    if (temp != "xml")
                    {
                        String_Stack.Push(temp);
                        Number_Stack.Push(counter);
                    }
                    i--;
                    continue;
                }

                //* Checking closing tags
                if ((line[i - 1] == '<') && line[i] == '/')
                {
                    string temp = "";
                    int j = i + 1;
                    while (line[j] != '>')
                    {
                        if (line[j] != 32)
                            temp += line[j];
                        j++;
                    }

                    if (String_Stack.GetTopData() == temp)
                    {
                        String_Stack.Pop();
                        Number_Stack.Pop();
                    }
                    else
                    {
                        this->DepthChecker(String_Stack, Number_Stack, temp, counter);
                    }
                    i = j - 1;
                    continue;
                }
            }
        }

        myfile.close();

        ///* Cheking if xml header is not present
        if (condition3 && !condition1)
        {
            cout << "xml header is not present\n";
        }

        //* If All conditions are met and file is Ok
        if ((CharString.isEmpty() && String_Stack.isEmpty()) && !condition1 && !condition3 && condition4)
        {
            cout << "Tags and quotes are properly matched\n";
            return true;
        }

        //* If All conditions are not met and file is not Ok
        else
        {
            // cout << "Tags or Quotes are not properly matched\n";
            while (!String_Stack.isEmpty())
            {
                cout << "Missing ending  tag of " << String_Stack.GetTopData() << " at line number " << Number_Stack.GetTopData() << endl;
                String_Stack.Pop();
                Number_Stack.Pop();
            }
            return false;
        }
    }
};
