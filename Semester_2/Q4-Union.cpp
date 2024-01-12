/*
 * Name     : Tayyab Kamran Sami
 * Roll no  : 22i-2505
 * Assingement no 1
 */

#include <iostream>

using namespace std;

struct arrayUnion
{
	int arr1[10];
	int arr2[5];
	int *ResultUnionArr;
	int size;

	void input()
	{
		// Taking Input for Array 1
		for (int i = 0; i < 10; i++)
		{
			cout << "Enter the number " << i + 1 << " for Array 1 " << endl;
			cin >> arr1[i];
		}

		//  Taking input for Array 2
		for (int i = 0; i < 5; i++)
		{
			cout << "Enter the number " << i + 1 << " for Array 2 " << endl;
			cin >> arr2[i];
		}

		// Printing Array 1 
		cout<<"Array 1 is  : ";
		cout<<"{ ";
		for(int i=0; i<10; i++)
		{
			cout<<arr1[i];
			if(i<9)
			cout<<",";
		}
		cout<<"}\n";

		// Printing Array 2 
		cout<<"Array 2 is  : ";
		cout<<"{ ";
		for(int i=0; i<5; i++)
		{
			cout<<arr2[i];
			if(i<4)
			cout<<",";
		}
		cout<<"}\n";
	}
	void find_union()
	{
		int num1 = -8889;
		
		// ? Checking for repetetion in Array 1
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i != j)
				{
					if (arr1[i] == arr1[j])
					{
						arr1[j] = num1;
					}
				}
			}
		}

		// ? Checking for repetetion in array 2
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i != j)
				{
					if (arr2[i] == arr2[j])
					{
						arr2[j] = num1;
					}
				}
			}
		}

		// ? Checking for Similarities in Array 1 and Array 2
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr1[i] == arr2[j])
				{
					arr2[j] = num1;
				}
			}
		}

		// * Checking how many Elements are left in Array 1 after removing repetetion
		int counter1 = 0;

		for (int i = 0; i < 10; i++)
		{
			if (arr1[i] != num1)
			{
				counter1++;
			}
		}

		// * Checking how many elements are left in Array 2 after rremoving similarities with
		// * Array 1 and repetetion from within
		int counter2 = 0;

		for (int i = 0; i < 5; i++)
		{
			if (arr2[i] != num1)
			{
				counter2++;
			}
		}

// ! Allocating an Array of the required size 
		size=counter1+counter2;
		ResultUnionArr = new int[size];

		int theinputter = 0;

// * Filling the Array with the Elements
		for (int i = 0; i < 10; i++)
		{
			if (arr1[i] != num1)
			{
				ResultUnionArr[theinputter] = arr1[i];
				theinputter++;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (arr2[i] != num1)
			{
				ResultUnionArr[theinputter] = arr2[i];
				theinputter++;
			}
		}

// * Sorting the Array in ascending order 
		for(int i=0; i<size-1; i++)
		{
			for(int j=i+1; j<size; j++)
			{
				if(ResultUnionArr[i]>ResultUnionArr[j])
				{
					int temp=ResultUnionArr[i];
					ResultUnionArr[i]=ResultUnionArr[j];
					ResultUnionArr[j]=temp;
				}
			}
		}
	}

	void printresult()
	{
		cout<<"Their union is  : ";
		cout<<"{ ";
		for(int i=0; i<size; i++)
		{
			cout<<ResultUnionArr[i];
			if(i<size-1)
			cout<<",";

		}
		cout<<"}\n";

// ! DEALOCATING THE ARRAY AFTER USING 
		delete[]ResultUnionArr;
		ResultUnionArr=NULL;
	}
};

int main()
{
	arrayUnion u;
	u.input();
	u.find_union();
	u.printresult();
}
