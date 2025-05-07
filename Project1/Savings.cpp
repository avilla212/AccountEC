#include "Savings.h"

void Savings::deposit(double amount, string user) {
	try {
		ifstream inFile("LoggedIn.txt");
		if (!inFile.is_open()) {
			throw runtime_error("Error opening LoggedIn.txt.");
		}

		ofstream tempFile("Temp.txt");
		if (!tempFile.is_open()) {
			throw runtime_error("Error opening Temp.txt.");
		}

		string fileUser;
		double fileBalance;
		bool userFound = false;

		// while loop to read from the file
		// and write to the temp file
		// new file should be user 100 100
		// <user> <savingsBalance> <checkingsBalance>
		while (inFile >> fileUser >> fileBalance) {
			if (fileUser == user) {
				fileBalance += amount;
				savingsBalance = fileBalance;
				userFound = true;
			}
			tempFile << fileUser << " " << fileBalance << endl;

		}

		inFile.close();
		tempFile.close();

		if (!userFound) {
			cout << "User not found." << endl;
			remove("Temp.txt");
			return;
		}

		// Replace old file with updated file
		remove("LoggedIn.txt");
		rename("Temp.txt", "LoggedIn.txt");
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	catch (...) {
		cout << "Unknown error..." << endl;
	}
}

void Savings::withdraw(double total) {
	if (total > savingsBalance) {
		cout << "You cannot withdraw that much. Try again." << endl;
	}
	else {
		savingsBalance -= total;
	}
}
void Savings::display() {
	cout << "Savings balance: $" << savingsBalance << endl;
}