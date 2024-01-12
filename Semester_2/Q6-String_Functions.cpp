/*
*Hi,In this code I will manually implement the various functions of String
*Library. The main purpose to make this code is to get the clear idea of
*what is happening behind the scenes and also to practice the concept of passing
*character pointers into an array
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*  It finds the length of the string. I implemented the function by running a loop until I
     find the terminating character.
*/
int mystrlen(char *sentence)
{
    int count = 0;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

/*  It copies a string into a given string. I implemented the logic by allocating a new
    array equal to size of the string to be copied and then giving it the values of the
    specific string by running a Loop.
*/
char *mystrcpy(char *s1, char *s2)
{
    delete[] s1;
    s1 = NULL;

    int size = mystrlen(s2);

    s1 = new char[size];
    for (int i = 0; i < size; i++)
    {
        s1[i] = s2[i];
    }

    return s1;
}

/*  It appends two strings. I implemented the logic by getting the size of both the 
    strings and then allocating a bigger character array equal to the size of the sum of
    length of both the strings and then I used the Loop and the if conditions to append 
    them and returned the character array using a pointer 

*/
char * mystrcat(char*s1,char*s2)
{
    int size1=mystrlen(s1);
    int size2=mystrlen(s2);
    char *s3=new char[size1+size2];
   
    for(int i=0; i<size1+size2; i++ )
    {
        if(i<size1)
        {
            s3[i]=s1[i];
        }

        else
        {
           s3[i]=s2[i-size1];
        }
    }

    return s3;
}
char * mystrncat(char*s1,char*s2, int n)
{
    int size1=mystrlen(s1);
    int size2=mystrlen(s2);
    char *s3=new char[size1+size2];
   
    for(int i=0; i<size1+n; i++ )
    {
        if(i<size1)
        {
            s3[i]=s1[i];
        }

        else
        {
           s3[i]=s2[i-size1];
        }
    }

    return s3;
}

int  mystrcmp(char*c1,char*c2)
{
    int size1=mystrlen(c1);
    int size2=mystrlen(c2);

    if(size1==size2)
    {
        return 0;
    }

    if(size1<size2)
    {
        return -1;

    }

    if(size1>size2)
    {
        return 1;
    }

}

int  mystrncmp(char*c1,char*c2,int size)
{
    int size2=mystrlen(c2);

    if(size==size2)
    {
        return 0;
    }

    if(size<size2)
    {
        return -1;

    }

    if(size>size2)
    {
        return 1;
    }

}

int main()
{
    int option;

    cout << "Hi,Please Select the optiom you want to implement "
         << "\n\n";
    cout << "1.Find the Length of the string using Strlen()" << endl;
    cout << "2.Copy the string into another string using Strcpy" << endl;
    cout << "3.Append the string to another string using Strcat" << endl;
    cout << "4.Append n charactters of string to another string using Strncat"<<endl;
    cout << "5.Compare two strings using Strcmp "<<endl;
    cout << "6.Compare string 1 upto n characters with string 2"<<endl;
    cout << "7. Compare two strings and removing words using Strtok()"<<endl;
    

    cin >> option;
    cin.ignore();

    if (option == 1)
    {
        char *sentence = new char[100];

        cout << "Enter the sentence to find its length" << endl;
        cin.get(sentence, 100);

        int count = mystrlen(sentence);

        cout << "The String has " << count << " number of Characters " << endl;

        delete[] sentence;
        sentence = NULL;
    }

    if (option == 2)
    {
        char *s1 = new char[100];
        cout << "Enter the String " << endl;
        cin.get(s1, 100);
        cin.ignore();
        cout << "Enter the String you want to copy " << endl;
        char *s2 = new char[100];
        cin.get(s2, 100);
        cin.ignore();

        s1 = mystrcpy(s1, s2);

        cout << "The string after copying the string in it is ";
        puts(s1);

        delete[] s1;
        delete[] s2;
        s1 = NULL;
        s2 = NULL;
    }

    if (option == 3)
    {
        char *s1=new char[150];            // ALLOCATED 
        char *s2=new char[150];            // ALLOCATED 
        cout<<"Enter the string 1 "<<endl;
        cin.get(s1,150);
        cin.ignore();

        cout<<"Enter the string 2 you want to append "<<endl;
        cin.get(s2,150);
        puts(s2);
        cin.ignore();

       s1= mystrcat(s1,s2);

       cout<<"The string after getting appended is ";
       puts(s1);

         delete[] s1;
        delete[] s2;
        s1 = NULL;
        s2 = NULL;
    }

    if(option==4)
    {
         char *s1=new char[150];            // ALLOCATED 
        char *s2=new char[150];            // ALLOCATED 

        cout<<"Enter the string 1 "<<endl;
        cin.get(s1,150);
        cin.ignore();

        cout<<"Enter the string 2 you want to append "<<endl;
        cin.get(s2,150);
        cin.ignore();

        cout<<"Enter the number of characters you want to append "<<endl;
        int n;
        cin >> n;

       s1= mystrncat(s1,s2,n);

       cout<<"The string after getting appended is \n";
       puts(s1);
      

        delete[] s1;
        delete[] s2;
        s1 = NULL;
        s2 = NULL;

    }

    if(option==5)
    {
          char *s1=new char[150];            // ALLOCATED 
        char *s2=new char[150];            // ALLOCATED 

        cout<<"Enter the  first string  "<<endl;
        cin.get(s1,150);
        cin.ignore();

        cout<<"Enter the string 2 you want to compare "<<endl;
        cin.get(s2,150);
        puts(s2);
        cin.ignore();
      

      int value= mystrcmp(s1,s2);

      if(value==0)
      {
        cout<<"Both the strings are equal as the value returned is equal to 0 "<<endl;
      }

      if(value==-1)
      {
        cout<<"String  is smaller than string 2 as the value returned is less than 0 "<<endl;
      }

      if(value==1)
      {
        cout<<"String 1 is greater than string 2 as the value returned is greater than 0 "<<endl;
      }
     

        delete[] s1;
        delete[] s2;
        s1 = NULL;
        s2 = NULL;

    }

    if(option==6)
    {
        char *s1=new char[150];            // ALLOCATED 
        char *s2=new char[150];            // ALLOCATED 

        cout<<"Enter the  first string  "<<endl;
        cin.get(s1,150);
        cin.ignore();

        cout<<"Enter the number of characters you want to compare "<<endl;
        int size;
        cin>>size;
        if(size>mystrlen(s1))
        {
            cout<<"The string that not have this many characters "<<endl;
            exit(0);
        }

        cin.ignore();
        cout<<"Enter the string 2 you want to compare "<<endl;
        cin.get(s2,150);


      int value= mystrncmp(s1,s2,size);

      if(value==0)
      {
        cout<<"The string till n characters is equal to string 2 as the value returned is equal to 0 "<<endl;
      }

      if(value==-1)
      {
        cout<<"The string till n characters is smaller than string 2 as the value returned is less than 0 "<<endl;
      }

      if(value==1)
      {
        cout<<"The string till n characters is larger than string 2 as the value returned is greater than 0 "<<endl;
      }
     

        delete[] s1;
        delete[] s2;
        s1 = NULL;
        s2 = NULL;

    }

    return 0;
}
