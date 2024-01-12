/*
 * Name     : Tayyab Kamran Sami
 * Roll no  : 22i-2505
 * Assingement no 1
 */

#include <iostream>

using namespace std;

/* // ! EXPLAINATION
? In this recursive function I find the length of the given string through
? recursion. I implemented the logic by incrementing the length through calling the
? function again and again until it finds the terminating character in the string
*/

int find_Length(string s, int counter)
{
	if (s[counter] == '\0') // ! BASE CONDITION
	{
		return counter;
	}

	counter++; // * Incrementing the Length

	return find_Length(s, counter); // * Making a Recursive call for the same function
}

void thepremiumvalidator(string s)
{
	int count = find_Length(s, 0);
	if (count == 0)
	{
		cout << "String Cannot be eympty " << endl;
		exit(0);
	}
}

struct String_Manipulation
{

	// ! LENGTH OF THE STRING
	int Calculate_length(string s)
	{
		int length;

		length = find_Length(s, 0); // Calling the Recursive Function

		return length;
	}

	/* // ! EXPLANATION
	? In this function we check if a substring exists in a progrm or not
	? I applied the logic by applying two nested loops the outer loop
	? iterates equal to the sum of lengths of both the strings and the
	? inner loop iterates equal to length of the sub-string.The inner loop
	? breaks as soon as it founds a mismatch and then the loop again starts
	? checking the string from its next index with the first index of the substring.
	? If it doesnot found a mismatch and the number of characters found same is equal
	? to the length of sub-string. It returns true else false.
	*/

	bool substring(string main, string str)
	{
		bool status;
		int checker2 = 0, thekeeper = 0;

		int length1 = Calculate_length(main);

		int length2 = Calculate_length(str);

		for (int i = 0; i <= length1 + length2; i++)
		{
			int k = 0, checker2 = 0;
			for (int j = i; k < length2; j++, k++)
			{
				if (main[j] != str[k])
				{
					break;
				}

				checker2++;

				if (checker2 == length2)
				{
					thekeeper = checker2;
				}
			}
		}

		if (thekeeper == length2)
		{
			status = true;
		}
		else
			status = false;

		return status;
	}
	/* // ! EXPLANATION
	? In this function I used the same logic as used in the above function
	? I just added an additional feature that when the sub string is detected
	? it saves the index in the main string substract the length of the substring
	? from it to make it accurate.

	*/
	int substring_position(string main, string str)
	{
		int index = -1, checker3 = 0;

		int length1 = Calculate_length(main);

		int length2 = Calculate_length(str);

		for (int i = 0; i <= length1 + length2; i++)
		{
			int k = 0, checker3 = 0;
			for (int j = i; k < length2; j++, k++)
			{
				if (main[j] != str[k])
				{
					break;
				}

				checker3++;

				if (checker3 == length2)
				{
					index = j - length2 + 1;
				}
			}
		}
		return index;
	}
};

int main()
{
	String_Manipulation themanipulator; // Made an Instance of the structure

	string mystring="Tayyab is a great programmer ";
	cout << "\n\n";

	// * MAKING A OPTION LIST TO SELECT WHICH FUNCTION
	// * THE USER WANT TO PERFORM

	cout << "Hello,what you want to do today " << endl;
	cout << "1. Find the Length of the String" << endl;
	cout << "2. Check if a string exist in the main string " << endl;
	cout << "3. Find the position of the substring in a string" << endl;

	int opt;
	cin >> opt;

	if (opt < 1 || opt > 3)
	{
		cout << "Enter a Number between 1 and 3" << endl;
		exit(0);
	}

	if (opt == 1)
	{
		cout << "Enter the string you want to find the length " << endl;
		
		thepremiumvalidator(mystring); // Validating it

		int len = themanipulator.Calculate_length(mystring); // Calling the function

		cout << "The Length of the provided string is " << len << ".\n";
	}

	if (opt == 2)
	{
		String_Manipulation thedestroyer;

		cout << "Enter the main string " << endl;
		string mystring2="Hi i am taking an oop class";
		
		thepremiumvalidator(mystring2); // Validating it

		cout << "Enter the string you want to find in it " << endl;
		string substr=" am taking ";
		
		thepremiumvalidator(substr); // Validating it

		// * CALLING THE FUNCTION CONTAINING THE MAIN LOGIC

		bool answer2 = thedestroyer.substring(mystring2, substr);

		if (answer2)
		{
			cout << "Yes it contains the following string " << endl;
		}
		if (!answer2)
		{
			cout << "Sorry it doesnot contain the requested string " << endl;
		}
	}

	if (opt == 3)
	{
		String_Manipulation thedetecter;

		cout << "Enter the main string " << endl;

		string mystring2="Hi i am taking an oop class";

		thepremiumvalidator(mystring2); // Validating it

		cout << "Enter the string you want to find the starting index " << endl;
		string substr="taking ";
	
		thepremiumvalidator(substr); // Validating it

		// * CALLING THE FUNCTION CONTAINING THE MAIN LOGIC

		int answer3 = thedetecter.substring_position(mystring2, substr);

		if (answer3 != -1)
		{
			cout << "The following sub string exists at the Location " << answer3 << " in the main string" << endl;
		}
		if (answer3 == -1)
		{
			cout << "The following Substring doesnot exist in the main string" << endl;
		}
	}
}
