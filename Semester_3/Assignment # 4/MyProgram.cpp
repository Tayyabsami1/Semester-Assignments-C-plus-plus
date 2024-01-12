#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class MyKeyWord
{
public:
    int id;
    string Url;
    string KeyWords;

    MyKeyWord()
    {
        id = 0;
        Url = "";
        KeyWords = "";
    }

    MyKeyWord(int id, string url, string MyKeyWord)
    {
        this->id = id;
        this->Url = url;
        this->KeyWords = MyKeyWord;
    }
};

class MyKeyWordNode
{
public:
    string Key;
    vector<string> ListofUrl;
    MyKeyWordNode *Left_Child;
    MyKeyWordNode *Right_Child;

    MyKeyWordNode()
    {
        Key = "";
        Left_Child = NULL;
        Right_Child = NULL;
    }

    MyKeyWordNode(string Key)
    {
        this->Key = Key;
        Left_Child = NULL;
        Right_Child = NULL;
    }
};

class MyTree
{
    MyKeyWordNode *Root;

public:
    // ! For Inserting the Keywords along with their Urls
    MyKeyWordNode *insert(MyKeyWordNode *node, string &value, string &url)
    {
        if (node == NULL)
        {
            node = new MyKeyWordNode(value);
            node->ListofUrl.push_back(url);
            return node;
        }

        if (value < node->Key)
        {
            node->Left_Child = insert(node->Left_Child, value, url);
        }
        else if (value > node->Key)
        {
            node->Right_Child = insert(node->Right_Child, value, url);
        }
        if (value == node->Key)
        {
            if (node->ListofUrl.back() != url)
            {
                node->ListofUrl.push_back(url);
            }
            return node;
        }

        return node;
    }

    // * To print all the keywords
    void PrintAll(MyKeyWordNode *TempRoot)
    {
        if (TempRoot == NULL)
        {
            return;
        }
        PrintAll(TempRoot->Left_Child);
        cout << TempRoot->Key << " \n";

        for (string myUrl : TempRoot->ListofUrl)
        {
            cout << myUrl << "\n";
        }
        PrintAll(TempRoot->Right_Child);
        return;
    }

    MyKeyWordNode *GetRoot()
    {
        return this->Root;
    }

    void SetRoot(MyKeyWordNode *tempRoot)
    {
        this->Root = tempRoot;
    }

    // * For Searching a Keyword
    void Search(MyKeyWordNode *node, string &key)
    {
        if (node == NULL)
        {
            cout << "Sorry your URL is broken\n";
            return;
        }

        else if (key < node->Key)
        {
            Search(node->Left_Child, key);
        }

        else if (key > node->Key)
        {
            Search(node->Right_Child, key);
        }
        else if (key == node->Key)
        {
            cout << node->ListofUrl.size() << " result(s) found \n";
            int i = 1;
            for (string temp : node->ListofUrl)
            {
                cout << i << ". " << temp << endl;
                i++;
            }
            return;
        }
    }

    //* Find the Inorder successor 
    MyKeyWordNode *inOrderSuccessor(MyKeyWordNode *Temper)
    {
        while (Temper && Temper->Left_Child != NULL)
        {
            Temper = Temper->Left_Child;
        }

        return Temper;
    }

    // ! For Deleting a Node
    MyKeyWordNode *MakeDeletion(string KeyWord, MyKeyWordNode *Temp)
    {
        MyKeyWordNode *MyTemp2;

        if (Temp == NULL)
        {
            return NULL;
        }

        if (Temp->Key > KeyWord)
        {
            Temp->Left_Child = MakeDeletion(KeyWord, Temp->Left_Child);
        }

        else if (Temp->Key < KeyWord)
        {
            Temp->Right_Child = MakeDeletion(KeyWord, Temp->Right_Child);
        }
        else
        {
            if (Temp->Left_Child == NULL)
            {
                MyTemp2 = Temp->Right_Child;
                delete Temp;
                return MyTemp2;
            }
            else if (Temp->Right_Child == NULL)
            {
                MyTemp2 = Temp->Left_Child;
                delete Temp;
                return MyTemp2;
            }
            //! Final Case
            MyTemp2 = inOrderSuccessor(Temp->Right_Child);
            Temp->Key = MyTemp2->Key;
            Temp->Right_Child = MakeDeletion(MyTemp2->Key, Temp->Right_Child);
        }

        return Temp;
    }
    
};

void Searcher(string FileName, MyTree &MySearchingBST)
{
    string Word;
    cout << "Please enter a word to search\n";
    cin >> Word;

    ifstream MyFile(FileName);

    if (MyFile.is_open())
    {
        cout << "File Loaded successfully\n";
    }
    else
    {
        cout << "No such file exists \n";
    }

    string line;
    MyKeyWord MyObj;
    string temp;

    while (getline(MyFile, line))
    {
        if (line.empty())
        {
            continue;
        }
        istringstream idUrlStream(line);
        idUrlStream >> MyObj.id >> MyObj.Url;

        getline(MyFile, line);
        istringstream keywordStream(line);

        while (keywordStream >> temp)
        {
            MySearchingBST.SetRoot(MySearchingBST.insert(MySearchingBST.GetRoot(), temp, MyObj.Url));
        }
    }
    MyFile.close();
    MySearchingBST.Search(MySearchingBST.GetRoot(), Word);
    return;
}

MyTree Interface(string FileName = "Assignment_data.txt")
{
    string Word;
    cout << "Please enter a word to search\n";
    cin >> Word;

    ifstream MyFile(FileName);

    if (MyFile.is_open())
    {
        cout << "File Loaded successfully\n";
    }
    else
    {
        cout << "No such file exists \n";
    }
    string line;
    MyKeyWord MyObj;
    string temp;
    MyTree MySearchingBST;

    while (getline(MyFile, line))
    {
        if (line.empty())
        {
            continue;
        }
        istringstream idUrlStream(line);
        idUrlStream >> MyObj.id >> MyObj.Url;

        getline(MyFile, line);
        istringstream keywordStream(line);

        while (keywordStream >> temp)
        {
            MySearchingBST.SetRoot(MySearchingBST.insert(MySearchingBST.GetRoot(), temp, MyObj.Url));
        }
    }
    MyFile.close();
    MySearchingBST.Search(MySearchingBST.GetRoot(), Word);
    return MySearchingBST;
}

void Menue_Maker(string FileName, MyTree &Tree)
{
    int Option;
    while (Option != 4)
    {
        cout << "What do you  want to do more \n";
        cout << "1. Search a keyword\n";
        cout << "2. Insert a Keyword\n";
        cout << "3. Delete a keyword\n";
        cout << "4. Exit\n";
        cin >> Option;
        if (Option == 4)
        {
            cout << "Exited successfully\n";
            continue;
        }
        string Word;
        if (Option == 1)
        {
            cout << "Please enter a word to search\n";
            cin >> Word;
            Tree.Search(Tree.GetRoot(), Word);
        }

        if (Option == 2)
        {
            MyKeyWord K;
            cout << "Enter the KeyWord you want to insert\n";
            cin >> Word;
            cout << "What is the Url for this keyword\n";
            cin >> K.Url;
            Tree.insert(Tree.GetRoot(), Word, K.Url);
            cout<<Word<<" inserted successfully\n";
        }

        if (Option == 3)
        {
            cout<<"Enter the Keyword you want to delete \n";
            cin>>Word;
            Tree.MakeDeletion(Word,Tree.GetRoot());
            cout<<Word<<" deleted successfully\n";
        }
    }
    return;
}

int main()
{
    string FileName, Word;
    MyTree MyMainTree;
    cout << "Enter the name of the file : \n";
    cin>>FileName;
    // FileName = "Assignment_data.txt";
    MyMainTree = Interface(FileName);
    Menue_Maker(FileName, MyMainTree);
}