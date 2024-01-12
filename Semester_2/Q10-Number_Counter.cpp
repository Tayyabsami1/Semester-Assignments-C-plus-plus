#include <iostream>

using namespace std;

int countDigits(int number, int tofind, int i = 1, int count = 0)
{
    if (i > number)
    {
        return count;
    }
    if (i >= 1 && i <= 99)
    {
        if (i % 10 == tofind)
        {
            count++;
        }
        if (i / 10 == tofind)
        {
            count++;
        }
    }

    if (i >= 100 && i <= 999)
    {
        if (i % 100 == tofind)
        {
            count++;
        }
        if (i % 10 == tofind)
        {
            count++;
        }
        if (i / 100 == tofind)
        {
            count++;
        }
    }

    if (i >= 1000 && i <= 9999)
    {
        if (i % 1000 == tofind)
        {
            count++;
        }
        if (i % 100 == tofind)
        {
            count++;
        }
        if (i % 10 == tofind)
        {
            count++;
        }
        if (i / 1000 == tofind)
        {
            count++;
        }
    }
    if (i >= 10000 && i <= 99999)
    {
        if (i % 1000 == tofind)
        {
            count++;
        }
        if (i % 100 == tofind)
        {
            count++;
        }
        if (i % 10 == tofind)
        {
            count++;
        }
        if (i / 10000 == tofind)
        {
            count++;
        }
    }

    i++;
    return countDigits(number, tofind, i, count);
}

int main()
{
    int n, m;

    cout << "Enter the number till you want to check " << endl;
    cin >> n;

    cout<<"Now enter the number you want to check "<<endl;
    cin>>m;

    /*
    Sample :
    Till Number 33 --Occurence of 3 is
    3,13,23,30,31,32 and two times in 33 
    
    */

    cout<< countDigits(n, m);


    return 0;
}