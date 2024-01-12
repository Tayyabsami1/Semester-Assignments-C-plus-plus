#include <iostream>
#include <string>

using namespace std;

int search(string s, string Search, int pos, int Length, int counter)
{
    // The Terminating condition
    if (pos + counter > Length)
    {
        return -1;
    }

    // If we found a match we return its distance from the starting position
    if (s[(pos - 1) + counter] == Search[0])
    {
        return counter - 1;
    }

    counter++;

    return search(s, Search, pos, Length, counter);
}

int SearchDigit(int N, int S, int pos)
{
    // Convering the Integer to String
    string N1 = to_string(N);
    string S1 = to_string(S);

    int L = N1.length();

    if (N1.length() > 9)
    {
        return -1;
    }

    // The Recursive Function Call
    int num = search(N1, S1, pos, L, 0);

    return num;
}

int main()
{
    // Q1
    long long int number;

    // Inputing the Number
    cout << "Enter the number " << endl;
    cin >> number;

    // Taking the number to search
    cout << "Enter the Number you want to search " << endl;
    int search;
    cin >> search;

    // Taking the Input of the Shadow
    cout << "Enter the position from where you want to find it " << endl;
    int position;
    cin >> position;

    // Calling the main function containing the Logic
    int Answer = SearchDigit(number, search, position);

    if (Answer == -1)
    {
        cout << "Please Check if your searched number is present and your digit is within 9 digits" << endl;
    }
    else
    {
        cout << "Your searched digit is " << Answer << " digits apart from your searched position" << endl;
    }
}