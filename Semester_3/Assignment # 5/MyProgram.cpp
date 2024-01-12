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
    int Height;

    MyKeyWordNode()
    {
        Key = "";
        Left_Child = NULL;
        Right_Child = NULL;
        Height = 1;
    }

    MyKeyWordNode(string Key)
    {
        this->Key = Key;
        Left_Child = NULL;
        Right_Child = NULL;
        Height = 1;
    }

    int Get_Height()
    {
        if (this == NULL)
            return 0;
        return this->Height;
    }
};

int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int GetBalanceFactor(MyKeyWordNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int bal=node->Left_Child->Get_Height() - node->Right_Child->Height;

    return bal;
}

MyKeyWordNode *Right_Rotate(MyKeyWordNode *Y)
{
    MyKeyWordNode *X = Y->Left_Child;
    MyKeyWordNode *T2 = X->Right_Child;

    X->Right_Child = Y;
    Y->Left_Child = T2;
    Y->Height = max(Y->Left_Child->Get_Height(), Y->Right_Child->Get_Height()) + 1;
    X->Height = max(X->Left_Child->Get_Height(), X->Right_Child->Get_Height()) + 1;

    return X;
}

MyKeyWordNode *Left_Rotate(MyKeyWordNode *X)
{
    MyKeyWordNode *Y = X->Right_Child;
    MyKeyWordNode *T2 = Y->Left_Child;

    X->Right_Child = T2;
    Y->Left_Child = X;
    Y->Height = max(Y->Left_Child->Get_Height(), Y->Right_Child->Get_Height()) + 1;
    X->Height = max(X->Left_Child->Get_Height(), X->Right_Child->Get_Height()) + 1;

    return Y;
}

class MyTree
{
    MyKeyWordNode *Root;

public:
    // * For Inserting the Keywords along with their Urls
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

        else if (value == node->Key)
        {
            if (node->ListofUrl.back() != url)
            {
                node->ListofUrl.push_back(url);
            }
            return node;
        }

        if (node->Left_Child != NULL && node->Right_Child != NULL)
            node->Height = Max(node->Left_Child->Get_Height(), node->Right_Child->Get_Height()) + 1;
        else if (node->Left_Child != NULL && node->Right_Child == NULL)
            node->Height = node->Left_Child->Get_Height() + 1;
        else if (node->Left_Child == NULL && node->Right_Child != NULL)
            node->Height = node->Right_Child->Get_Height() + 1;

        int Balance = GetBalanceFactor(node);
        // LL Case
        if (node->Left_Child != NULL)
        {
            if (Balance > 1 && value < node->Left_Child->Key)
            {
                node = Right_Rotate(node);
            }
            // LR Case
            else if (Balance > 1 && value > node->Left_Child->Key)
            {
                node->Left_Child = Left_Rotate(node->Left_Child);
                node = Right_Rotate(node);
            }
        }
        // RR Case
        if (node->Right_Child != NULL)
        {
            if (Balance < -1 && value > node->Right_Child->Key)
            {
                node = Left_Rotate(node);
            }
            // RL Case
            else if (Balance < -1 && value < node->Right_Child->Key)
            {
                node->Right_Child = Right_Rotate(node->Right_Child);
                node = Left_Rotate(node);
            }
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
        cout << "3. Exit\n";
        cin >> Option;
        if (Option == 3)
        {
            cout << "Exited successfully\n";
            exit(0);
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
            cout << Word << " inserted successfully\n";
        }
    }
    return;
}

int main()
{
    string FileName, Word;
    MyTree MyMainTree;
    cout << "Enter the name of the file : \n";
    //! Make this a cin statement
    FileName = "Assignment_data.txt";
    MyMainTree = Interface(FileName);
    Menue_Maker(FileName, MyMainTree);
}