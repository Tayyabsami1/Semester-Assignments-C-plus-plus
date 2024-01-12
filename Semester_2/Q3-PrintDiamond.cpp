/*
 * Name     : Tayyab Kamran Sami
 * Roll no  : 22i-2505
 * Assingement no 1
 */

#include <iostream>

using namespace std;

// * Recursively prints the spaces
void spaceprinter(int spaces)
{
	if (spaces == 0)
	{
		return;
	}

	cout << " ";
	spaces--;
	
	spaceprinter(spaces);
}

// * Recursively prints the stars
void starprinter(int n)
{
	if (n == 0)
	{
		return;
	}

	cout << "*";
	n--;

	starprinter(n);
}

/*
 * It call the two basic functions recursively which print stars and spaces
 */
void theupper_half_printer(int n, int spaces)
{
	if (n == 0) // ! BASE CONDITION
	{
		return;
	}

	starprinter(n);
	spaceprinter(spaces);
	starprinter(n);

	n--, spaces += 2;
	cout << endl;

	theupper_half_printer(n, spaces);
}

void thelower_half_printer(int n, int spaces)
{
	if (spaces < 0) // ! BASE CONDITION
	{
		return;
	}

	starprinter(n);
	spaceprinter(spaces);
	starprinter(n);

	n++, spaces -= 2;
	cout << endl;

	thelower_half_printer(n, spaces);
}

/*
? It calls two functions with updated vales to print the upper-half and the
? lower-half of the pattern.
*/
void printDiamond(int stars)
{
	int spaces = 0;

	theupper_half_printer(stars, spaces);

	spaces = (stars * 2) - 4;
	stars = 2;

	thelower_half_printer(stars, spaces);

	return;
}

int main()
{
	int n;

	cout << "Enter Number of star: ";
	cin >> n;

	printDiamond(n);

	return 0;
}
