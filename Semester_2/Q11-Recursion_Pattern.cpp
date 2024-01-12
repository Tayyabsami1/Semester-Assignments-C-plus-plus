#include <iostream>

using namespace std;

void thePatternPrinter(int St, int End, char Ec1, char Oc2)
{
    // Base Case containing Recursion
    if (St > End)
    {
        St--;
        return;
    }

    cout << St;

    // Print Character when Digit is Even
    if (St % 2 == 0)
    {
        string temp(St, Ec1);
        cout << temp;
    }

    // Print Character when Digit is Odd
    if (St % 2 != 0)
    {
        string temp(St, Oc2);
        cout << temp;
    }

    St++;

    // Recursively calling the function
    thePatternPrinter(St, End, Ec1, Oc2);

    // The BackTrack Logic
    St--;
    if (St != End)
    {
        cout << St;

        if (St % 2 == 0)
        {
            string temp(St, Ec1);
            cout << temp;
        }

        if (St % 2 != 0)
        {
            string temp(St, Oc2);
            cout << temp;
        }
    }
    St--;
}

int main()
{
  int St,End;

  cout<<"Enter the Starting Number "<<endl;
  cin>>St;

  cout<<"Enter the Ending Number "<<endl;
  cin>>End;

  char Ec1,Oc2;

  cout<<"Enter the first Character "<<endl;
  cin>>Ec1;

  cout<<"Enter the second Character "<<endl;
  cin>>Oc2;

  thePatternPrinter(St,End,Ec1,Oc2);
}


