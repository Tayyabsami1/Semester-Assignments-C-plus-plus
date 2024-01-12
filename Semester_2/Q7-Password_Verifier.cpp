#include <iostream>
#include<string>
#include<cstring>  // you can use the strlen function to find the length of string 
#include<conio.h>

using namespace std;

class mysecurepasswords
{
    char*pw=new char[56];
    
    public:

    void theinput()
    {
        cout<<"Hi enter your password and we will check it "<<endl;
        cin.get(pw,56);
    }

    void thechecker()
    {
        int length=0;
        bool condition1,condition2=true,condition3=true,condition4=true;

        for(int i=0; pw[i]!='\0'; i++)
        {
            length++;
        }

        if(length<6)    // Checking the length 
        {
            condition1=true;
        }
        else condition1=false;

        for(int i=0; i<length; i++)   // Checking for lowercase letter
        {
            if(pw[i]>=97 && pw[i]<=122)
            {
                condition2=false;
            }
        }

        for(int i=0; i<length; i++)   // checking for upper case
        {
            if(pw[i]>=65 && pw[i]<=90)
            {
                condition3=false;
            }
        }

        for(int i=0; i<length; i++)   // checking for numeric 
        {
            if(pw[i]>=48 && pw[i]<=57)
            {
                condition4=false;
            }
        }

        if(condition1)
        {
            cout<<"Your password should be atleast 6 digits long "<<endl;
        }

        if(condition2)
        {
            cout<<"Your password must have atleast one lower case alphabet  "<<endl;
        } 

         if(condition3)
        {
            cout<<"Your password must have atleast one upper case alphabet  "<<endl;
        }

         if(condition4)
        {
            cout<<"Your password must have atleast one numeric digit  "<<endl;
        } 

       if(condition1==false&& condition2==false&&condition3==false&& condition4==false)
       {
        cout<<"Your password has been saved successfully "<<endl;
       }

       delete []pw;
       pw=NULL;
    } 
};
int main()
{
  cout<<"            Hello we will check your password and check it         "<<endl<<"\n";
  mysecurepasswords mycompany;
  mycompany.theinput();
  mycompany.thechecker();
  getch();
  
  return 0;
}