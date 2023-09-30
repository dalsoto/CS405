// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

// Clean up code by not having to call "std::"
using namespace std;

int main()
{
	cout << "Buffer Overflow Example" << endl;

	// TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
	//  even though it is a constant and the compiler buffer overflow checks are on.
	//  You need to modify this method to prevent buffer overflow without changing the account_order
	//  varaible, and its position in the declaration. It must always be directly before the variable used for input.

	// Defines the buffer limit
	const int MAX_SIZE = 21; // Account for 1 null element in array

	const string account_number = "CharlieBrown42";
	char* user_input = new char[MAX_SIZE]; // 1 NULL CHARACTER - will only take 20 chars
	cout << "Enter a value: ";
	cin.getline(user_input, MAX_SIZE); // Only read 20 characters

	// OVERFLOW
	// !cin = iput from user is longer than 20 chars
	// cin.bad() = IO Error
	// cin.eof() = EOF has been reached
	if (!cin || cin.bad() || cin.eof()) {
		// Clear buffer
		cin.clear();
		cout << "You entered: " << user_input << endl;
		cout << "Buffer Overflow Detected - Please Try Again" << endl; // Print overflow has been detected
	}
	else { // NO OVERFLOW - account number is only shown when no overflow 
		cout << "You entered: " << user_input << endl;
		cout << "Account Number = " << account_number << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
