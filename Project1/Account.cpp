#include "Account.h"

// =========== findUser ===========
// Will take in a username and password then check our Users.txt file 
// to see if they exist on the same line. If they do exist on the same line,
// return true. If not, return false.
//
// Input: string user, string password
//
// Output: bool
// ================================

bool Account::findUser(string user, string password) {
	try {
		// object to read our Users.txt file
		ifstream file("Users.txt");

		// if file doesnt open
		if (!file.is_open()) {
			throw runtime_error("Error opening file.");
			return false;
		}

		// line to hold the line we are reading from the file
		string line;

		// loop through file
		while (!file.eof()) {
			// read each line stopping at the space
			getline(file, line, ' ');

			// check if the username and passwords exist
			if (line == user) {
				cout << "Username found" << endl;
				getline(file, line);

				if (line == password) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				// This block causes early return even if match is further down the file
				// return false;
				getline(file, line); // consume the rest of the line
			}
		}

		// Reached end of file without finding match
		return false;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
}
// end of findUser

bool Account::userExists(string user) {
	try {
		ifstream file("Users.txt");

		if (!file.is_open()) {
			throw runtime_error("Error opening file.");
			return false;
		}

		string line;

		while (getline(file, line)) {
			istringstream iss(line);
			string fileUser, filePass;

			iss >> fileUser >> filePass;

			if (fileUser == user) {
				cout << "Duplicate username found: " << fileUser << endl;
				return true;
			}
		}

		return false;
	} catch (exception& e) {
		cout << e.what() << endl;
		return false;
	} catch (...) {
		cout << "An unknown error occurred." << endl;
		return false;
	}
}

bool Account::signup(string user, string password) {
	try {
		// check if user already exists
		if (userExists(user)) {
			cout << "Username already taken." << endl;
			return false;
		}
		else {
			// open file to write
			ofstream outFile("Users.txt", ios::app);

			// check if file opened successfully
			if (!outFile.is_open()) {
				throw runtime_error("Error opening Users.txt for writing.");
			}

			// write the username and password to the file
			outFile << user << " " << password << endl;
			outFile.close();
			onSignup(user, password); // Call onSignup to write to LoggedIn.txt

			cout << "Signup successful!" << endl;
			return true;
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
}

bool Account::onSignup(string user, string password) {
	try {
		// open file
		ofstream outFile("LoggedIn.txt", ios::app);

		// validate opening
		if (!outFile.is_open()) {
			throw runtime_error("Error opening Users.txt for writing.");
		}

		
		// writing user and balance to file
		outFile << user << " " << checkingsBalance << " " << savingsBalance << endl;
		outFile.close();

		return true;
	} catch (exception& e) {
		cout << e.what() << endl;
		return false;
	} catch (...) {
		cout << "An unknown error occurred." << endl;
		return false;
	}
}

bool Account::onLogin(string user, string password) {
	try {

		// open file to write
		ofstream outFile("LoggedIn.txt", ios::app);

		// check if file opened successfully
		if (!outFile.is_open()) {
			throw runtime_error("Error opening Users.txt for writing.");
		}

		// write the username and password to the file
		outFile << user << " " << checkingsBalance << " " << savingsBalance << endl;
		outFile.close();

		return true;

	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
	catch (...) {
		cout << "An unknown error occurred." << endl;
		return false;
	}

}


bool Account::login(string user, string password) {
	// call find user function
	if (findUser(user, password)) {
		// append user and password to LoggedIn file using the onLogin function
		onLogin(user, password);
		return true;
	}
	else {
		cout << "Login failed." << endl;
		return false;
	}
}


void Account::withdraw(double amount) {
	cout << "Pass" << endl;
}

void Account::deposit(double amount, string user) {
	cout << "Pass" << endl;
}


void Account::display() {
	cout << "Pass" << endl;
}