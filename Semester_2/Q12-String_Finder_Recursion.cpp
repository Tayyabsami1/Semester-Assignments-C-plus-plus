#include <iostream>
#include<cstring>

using namespace std;

bool isSubstr(char* s1, char* s2,int i=0,int j=0,int k=0)
{
  if(k==strlen(s2)-1)
  {
    return true;
  }

  if(i==strlen(s1)-1)
  {
    return false;
  }

  if(s1[j]==s1[k])
  {
    j++;
    k++;
    return isSubstr(s1,s2,i,j,k);
  }

  else
  {
    k=0;
    i++;
   return isSubstr(s1,s2,i,i,k);
  }
}

int main()
{
    cout<<"Enter the main string  "<<endl;
    char *MyStr1;
    MyStr1=new char [500];
    cin.get(MyStr1,500);
    
    cout<<"Enter the string you want to find in it "<<endl;
    char *MyStr2;
    cin.ignore();
    MyStr2=new char[500];
    cin.get(MyStr2,500);

    cout<< isSubstr( MyStr1,MyStr2);

}