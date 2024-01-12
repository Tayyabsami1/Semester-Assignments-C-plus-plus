/*
 * Name     : Tayyab Kamran Sami
 * Roll no  : 22i-2505
 * Assingement no 1
 */

#include <iostream>

using namespace std;

int liftup(int, int);	// Prototype
int liftdown(int, int); // Prototype

/* // ! EXPLANATION
? In this function we first checked that if the lift is halted or not if
? it is halted then we print a message that it cannot be moved. If the lift
? is in working condition then if the requested floor is greater than the current
? floor then we print a message that the lift is going up and call a recursive function
? Liftup. Vice versa we print a message lift going down and change the floor value
? through a recursive functiom liftdown.
*/
int lift_operating_system(int requested_floor, int current_floor, char lift_status)
{
	if (lift_status == 'H')
	{
		cout << "\nThe Lift cannot move as the lift is Halted \n"
			 << endl;
		return current_floor;
	}

	if (lift_status == 'W')
	{
		if (requested_floor > current_floor)
		{
			cout << "\n\nLift is going up \n\n";
			current_floor = liftup(current_floor, requested_floor);

			return current_floor;
		}

		if (requested_floor < current_floor)
		{
			cout << "\n\nLift is going down \n\n";
			current_floor = liftdown(current_floor, requested_floor);

			return current_floor;
		}

		if (requested_floor == current_floor)
		{
			cout << "\nThe Lift is already on the requested Floor \n"
				 << endl;
			return current_floor;
		}
	}
	return 0;
}

// * Increases the floor through Recursion
int liftup(int current_floor, int requested_floor)
{
	// ! BASE CONDITION CONTAINING TERMINATING CONDITION
	if (current_floor == requested_floor)
	{
		return current_floor;
	}

	current_floor++;

	return liftup(current_floor, requested_floor);
}

// * Decreases the floor through Recursion
int liftdown(int current_floor, int requested_floor)
{
	// ! BASE CONDITION CONTAINING TERMINATING CONDITION
	if (current_floor == requested_floor)
	{
		return current_floor;
	}

	current_floor--;

	liftdown(current_floor, requested_floor);
}

// ? Change the Status of the Lift to Halted
char halt_lift(char status)
{
	if(status=='H')
	{
		cout<<"\nThe Lift is already Halted.\n\n";
		return status;
	}
	status = 'H';
	cout << "\nLift Halted Successfully\n"
				 << endl;

	return status;
}

// ? Change the status of the lift to Un-Halted
char un_halt_lift(char status)
{
	if(status=='W')
	{
		cout<<"\nThe Lift is already Un-Halted.\n\n";
		return status;
	}
	status = 'W';
	cout << "\nLift Un-Halted Successfully\n"
				 << endl;

	return status;
}

int main()
{
	int total_floors = 6;
	int current_floor = -1;
	int requested_service = 4;
	int requested_floor;
	char status = 'W';
	while (1)
	{
		cout << "Please select a function of your choice";
		cout << endl
			 << "1. Go to a specific floor";
		cout << endl
			 << "2. Halt Lift";
		cout << endl
			 << "3. Unhalt Lift";
		cout << endl
			 << "4. Exit";
		cout << endl;

		cin >> requested_service;

		// ! VALIDATING THE OPTION ENTERED BY THE USER

		if (requested_service < 1 || requested_service > 4)
		{
			cout << "\nPlease select an appropriate option \n";
			exit(0);
		}

		switch (requested_service)
		case 1:
		{
			cout << endl
				 << "Enter Floor of choice :";
			cin >> requested_floor;

			// ! VALIDATING THE FLOOR ENTERED BY THE USER
			if (requested_floor < -1 || requested_floor > 4)
			{
				cout << "\nThis Floor doesnot exist  \n";
				exit(0);
			}

			// * Calling the function which contains all the checks to move the Lift

			current_floor = lift_operating_system(requested_floor, current_floor, status);

			cout << "\n\nNow the Lift is on " << current_floor << "\n\n";

			break;

		case 2:

			status = halt_lift(status);

			break;

		case 3:

			status = un_halt_lift(status);

			break;

		case 4:

			cout << "\nProgram exited successfully \n"
				 << endl;
			exit(0);

			break;
		}
	}
	return 0;
}
