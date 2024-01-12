#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// A Personal Function to find the lenght of the character array
int LengthFinder(char *str)
{
    // int length=0;
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

class String
{
    char *data;
    int size;

public:
    // Constructor
    String()
    {
        this->data = new char[1];
        data[0] = '\0';

        this->size = 0;
    }

    // Parameterized Constructor
    String(int length)
    {
        this->size = length;
        this->data = new char[size - 1];
        data[0] = '\0';
    }

    // 2nd Parameterized Constructor
    String(char *str)
    {
        this->size = LengthFinder(str);
        this->data = str;
    }

    // Copy Constructor
    String(const String &str)
    {
        this->size = str.size;
        if (size == 0)
        {
            this->data = new char[1];
            this->data[0] = '\0';
        }
        else
        {
            this->data = new char[str.size - 1];

            for (int i = 0; i < size - 1; i++)
            {
                this->data[i] = str.data[i];
            }
        }
    }

    char *getdata()
    {
        return this->data;
    }

    // Find and returns the string length
    int stringLength()
    {
        int L = 0;

        for (int i = 0; this->data[i] != '\0'; i++)
        {
            L = i;
        }

        return L;
    }

    // Clear the array and make the size 0
    void clear()
    {
        this->size = 0;
        this->data = new char[1];
        this->data[0] = '\0';
    }

    // Checking If the Character Array is Eympty
    bool isEmpty()
    {
        bool check = false;

        if (this->size == 0 && this->data[0] == '\0')
        {
            check = true;
        }

        return check;
    }

    // Find the Location of the Character in the Array
    int charAt(char c)
    {
        int pos = -1;
        for (int i = 0; i < this->size; i++)
        {
            if (this->data[i] == c)
            {
                return i + 1;
            }
        }
        return pos;
    }

    // Checking if the String is equal to the string provided
    bool isEqual(char *str)
    {
        int size1 = LengthFinder(this->data);
        int size2 = LengthFinder(str);
        if (size1 == size2 && this->data == str)
        {
            return true;
        }

        return false;
    }

    // Checking if the String is equal to the string provided ignoring the capital letters
    bool equalsIgnoreCase(char *str)
    {
        int size1 = LengthFinder(this->data);
        int size2 = LengthFinder(str);
        bool checker = false;
        int counter = 0;
        if (size1 == size2 && this->data == str)
        {
            counter = true;
        }

        if (size1 == size2 && this->data != str)
        {
            for (int i = 0; i < size2; i++)
            {
                if (str[i] + 32 == data[i] || str[i] - 32 == data[i] || str[i] == data[i])
                {
                    counter++;
                }
            }
        }

        if (counter == (size2)-1)
        {
            checker = true;
        }

        return counter;
    }

    // Find the Substring in the Character Array from the starting Index
    char *substring(char *substr, int startIndex)
    {
        int size1 = LengthFinder(this->data);
        int size2 = LengthFinder(substr);

        bool check = false;
        int saver = -1;

        for (int i = startIndex; i < size1; i++)
        {
            if (check == true)
            {
                break;
            }

            for (int j = i, k = 0; k < size2; j++)
            {
                if (this->data[j] != substr[k])
                {
                    break;
                }

                k++;

                if (k == (size2))
                {
                    saver = j - k;
                    saver++;
                    check = true;
                    break;
                }
            }
        }

        char *returner;

        if (check == true)
        {
            returner = new char[size1 - saver];

            for (int i = saver, k = 0; k <= (size1 - (saver)); i++)
            {
                returner[k] = this->data[i];
                k++;
            }
        }

        return returner;
    }

    // Find the Substring in the Character Array from the starting Index till the ending Index
    char *substring(char *substr, int startIndex, int endIndex)
    {
        int size1 = LengthFinder(this->data);
        int size2 = LengthFinder(substr);
        bool check = false;
        int saver = -1;

        for (int i = startIndex; i < size1; i++)
        {
            if (check == true)
            {
                break;
            }

            for (int j = i, k = 0; k < size2; j++)
            {
                if (this->data[j] != substr[k])
                {
                    break;
                }

                k++;

                if (k == (size2))
                {
                    saver = j - k;
                    saver++;
                    check = true;
                    break;
                }
            }
        }

        char *returner;

        if (check == true)
        {
            returner = new char[size1 - saver - (size1 - endIndex)];

            for (int i = saver, k = 0; k <= (size1 - (saver) - (size1 - endIndex)); i++)
            {
                returner[k] = this->data[i];
                k++;

                if (k == (size1 - (saver) - (size1 - endIndex)))
                {
                    returner[k + 1] = '\0';
                }
            }
        }

        return returner;
    }

    // Displaying the Character Array or printing NULL if it is eympty
    void print()
    {
        if (this->size == 0 && this->data[0] == '\0')
        {
            cout << "NULL " << endl;
        }
        else
        {
            cout << this->data << endl;
        }
    }

    ~String()
    {
        delete[] this->data;
    }
};

int main()
{
    // char *ptr = new char[100];
    // cin.get(ptr, 100);

    // char *ptr2 = new char[100];
    // cin.ignore();
    // cin.get(ptr2, 100);

    // String object1(ptr);

    // cout << object1.isEqual(ptr2) << " i am checker of equality\n";
    // cout << object1.equalsIgnoreCase(ptr2) << " i am checker of equality without case sen\n";
    // cout << object1.substring(ptr2, 4, 20) << " i am the occurence finder \n";

    // object1.print();

    // object1.clear();
    // object1.print();

    // String object2(object1);

    // object2.print();

    // cout << object2.isEmpty() << " i am checker of emptiness\n";

    // delete[] ptr;
    // delete[] ptr2;

    // ptr = NULL, ptr2 = NULL;

    return 0;
}