#include "Checkings.h"

#include "Checkings.h"
void Checkings::deposit(double amount, string user) {
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

		while (inFile >> fileUser >> fileBalance) {
			if (fileUser == user) {
				fileBalance += amount;
				checkingsBalance = fileBalance;
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



void Checkings::withdraw(double total) {
	if (total > checkingsBalance) {
		cout << "Cannot withdraw that much. Try again" << endl;
	}
	else {
		checkingsBalance -= total;
	}
}
void Checkings::display() {
	cout << "Checkings balance: $" << checkingsBalance << endl;
}