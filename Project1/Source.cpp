#include <iostream>
#include <fstream>

#include "Account.h"
#include "Savings.h"
#include "Checkings.h"

using namespace std;


void onLogin(string, string);
void loginAndSignup();
void showMenu();

int main() {
	// variables to be used in the program
	int choice;
	double amount;
	string username;
	string password;

	// create an instance of the Account class
	Account* account = new Account();

	do {
		loginAndSignup();
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "***********LOGIN***********\n";
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;

			if (account->login(username, password)) {
				cout << "Login successful!" << endl;

				int menuChoice;

				// create instances of Checkings and Savings accounts
				Checkings* checking = new Checkings();
				Savings* savings = new Savings();

				// display the menu and perform operations
				do {
					showMenu();

					// prompt user for choice
					cout << "Enter choice: ";
					cin >> menuChoice;

					// perform operations based on user choice
					switch (menuChoice) {
					case 1:
						cout << "Enter amount to deposit into savings: ";
						cin >> amount;
						savings->deposit(amount,username);
						break;
					case 2:
						cout << "Enter amount to deposit into checkings: ";
						cin >> amount;
						checking->deposit(amount,username);
						break;
					case 3:
						cout << "Enter amount to withdraw from savings: ";
						cin >> amount;
						savings->withdraw(amount);
						break;
					case 4:
						cout << "Enter amount to withdraw from checkings: ";
						cin >> amount;
						checking->withdraw(amount);
						break;
					case 5:
						checking->display();
						savings->display();
						break;
					case 6:
						cout << "Exiting..." << endl;
						// clean up
						delete checking;
						delete savings;
						break;
					default:
						cout << "Invalid choice. Please try again." << endl;
					}
				} while (menuChoice != 6);
			}
			// if login failed
			else {
				cout << "Login failed. Please try again." << endl;
			}
			break;
		}
		// signup case
		case 2: {
			cout << "***********SIGNUP***********\n";
			
			// prompt user for username and password
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;

			// call signup function
			if (account->signup(username, password)) {
				cout << "Signup successful!" << endl;

				// create instances of Checkings and Savings accounts
				int menuChoice;
				
				Checkings* checking = new Checkings();
				Savings* savings = new Savings();

				// display the menu and perform operations
				do {
					showMenu();
					cout << "Enter choice: ";
					cin >> menuChoice;

					switch (menuChoice) {
					case 1:
						cout << "Enter amount to deposit into savings: ";
						cin >> amount;
						savings->deposit(amount,username);
						break;
					case 2:
						cout << "Enter amount to deposit into checkings: ";
						cin >> amount;
						checking->deposit(amount,username);
						break;
					case 3:
						cout << "Enter amount to withdraw from savings: ";
						cin >> amount;
						savings->withdraw(amount);
						break;
					case 4:
						cout << "Enter amount to withdraw from checkings: ";
						cin >> amount;
						checking->withdraw(amount);
						break;
					case 5:
						checking->display();
						savings->display();
						break;
					case 6:
						cout << "Exiting..." << endl;
						// clean up
						delete checking;
						delete savings;
						break;
					default:
						cout << "Invalid choice. Please try again." << endl;
					}

				} while (menuChoice != 6);
			}
			// if signup failed
			else {
				cout << "Signup failed. Please try again." << endl;
			}
			break;
		}

		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 6);
	// clean up
	delete account;
	
	return 0;
}

void loginAndSignup() {
	cout << "***********BANK ACCOUNT MENU***********\n";
	cout << "1. Login\n";
	cout << "2. Signup\n";
}

void showMenu() {
	cout << "\n***********BANK ACCOUNT MENU***********\n";
	cout << "1. Deposit to Savings Account\n";
	cout << "2. Deposit to Checkings Account\n";
	cout << "3. Withdraw from Savings Account\n";
	cout << "4. Withdraw from Checkings Account\n";
	cout << "5. Display Account Balances\n";
	cout << "6. Exit\n";
	cout << "\n********************************\n";
}

// Function to write the logged-in user to a file
// write user password balance

