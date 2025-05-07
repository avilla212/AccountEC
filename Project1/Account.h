#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::runtime_error;
using std::exception;
using std::ios;
using std::istringstream;
using std::string;

using std::ifstream;
using std::ofstream;

class Account {
protected:
	double checkingsBalance = 0.0;
	double savingsBalance = 0.0;
public:
	Account() : checkingsBalance(100.00), savingsBalance(100.00) {}

	// deposit into account
	virtual void deposit(double, string);
	virtual void withdraw(double);
	virtual void display();

	bool findUser(string, string);
	bool userExists(string);

	bool login(string, string);
	bool onLogin(string, string);
	bool onSignup(string, string);
	bool signup(string, string);

	virtual ~Account() {}
};
#endif // ACCOUNT_H