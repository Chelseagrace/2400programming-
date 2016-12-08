//Assignment 4
//Chelsea Guindon
//Objective: To let a bank user make a transaction of either a deposit, withdrawl, or transfer.
//				The user will also beable to bring up a report which lists all the transactions made.
//Object Description:
//	This program has five classes Transaction, and its child classes Deposit, Withdrawl, and Transfer.
//  The last class is User, which is independent.
//	Transaction holds:
//		- user id
//		- amount
//		- within Transactions own function:
//			where user id, and amount are initialized to zero
//		- Report function
//			states the final user id and amount
//	Withdrawl holds:
//		- Withdrawl funtion:
//			asks the user how much they'd like to withdrawl, and takes in that data making
//			it amount. 
//		- Report function:
//			states the user id, and amount which was just entered in by the user.
//	Deposit holds:
//		-Deposit function:
//			asks user for amount they'd like to withdrawl, setting a number to amount.
//		- Report function:
//			states the user, and the amount entered to amount. 
//	Transfer holds:
//		-Transfer function:
//			-asks the user which user they want to transfer amount to
//			-asks which amount to transfer to that user
//		-Report function:
//			-states amount transferred
//			-states user which was trasferred the amount
//	User holds:
//		-id for user
//		-numTrans, to keep recoreded the number of transactions made
//		-Transaction* t[100], an array of 100 for transaction with a pointer, for max of 100
//		-User function:
//			sets id and numTrans to zero, to initialize them.
//		-AddDeposit function:
//			t[numTrans] = new Deposit - calls Deposit function from Deposit class
//			t[numTrans]->uid = id - saves a transaction to user id
//			numTrans++ - adds to amount of number of transactions
//		-AddWithdrawl function:
//			t[numTrans] = new Withdrawl - calls Withdrawl function from Withdrwal class
//			t[numTrans]->uid = id - saves a transaction to user id
//			numTrans++ - adds to amount of number of transactions
//		-AddTransfer function:
//			t[numTrans] = new Transfer - calls Transfer function from Transfer class
//			t[numTrans]->uid = id - saves a transaction to user id
//			numTrans++ - adds to amount of number of transactions
//		-Report function:
//			Prints a report of what has been done for each transaction the user made

#include <stdio.h>
#include <iostream>
using namespace std;

class Transaction
{
public:
	int uid;
	int amount;
	//int currentBal;

	Transaction()
	{
		uid = 0;
		amount = 0;
		//currentBal = 0;
	}
	virtual void Report() {
		cout << "User Id = " << uid << "\n"
			<< "Amount = " << amount << "\n";
			//<< "Current balance = " << currentBal << "\n";
	}
};

class Withdrawl : public Transaction
{
public:

	Withdrawl() {
		cout << "How much would you like to withdrawl?";
		cin >> amount;

		//currentBal = currentBal - amount;
	}
	void Report() {
		cout << "User: " << uid << "\n"
			<< "Amount withdrawn: " << amount << "\n";
			//<< "Account balance after withdrawl:" << currentBal << "\n";
	}
};

class Deposit : public Transaction
{
public:

	Deposit() {
		cout << "Enter amount to deposit: ";
		cin >> amount;

		//currentBal = currentBal + amount; 
	}
	void Report() {
		cout << "User: " << uid << "\n"
			<< "Amount deposited: " << amount << "\n";
			//<< "Account balance after deposit:" << currentBal << "\n";
	}
};

class Transfer : public Transaction
{
public:

	Transfer() {
		cout << "User to transfer to: ";
		cin >> uid; 
		cout << "Amount: ";
		cin >> amount; 
	}
	void Report() {
		cout << "Amount transferred: " << amount << "\n"
			<< "User transferred to: " << uid << "\n";
	}
};


class User
{
public:
	int id;
	int numTrans;
	Transaction* t[100];

	User()
	{
		id = 0;
		numTrans = 0;
	}
	void AddDeposit()
	{
		t[numTrans] = new Deposit();
		t[numTrans]->uid = id;
		numTrans++;
	}
	void AddWithdrawl()
	{
		t[numTrans] = new Withdrawl();
		t[numTrans]->uid = id;
		numTrans++; 
	}
	void AddTransfer() {
		t[numTrans] = new Transfer();
		t[numTrans]->uid = id;
		numTrans++;
	}
	void Report() {
		for (int i = 0; i < numTrans; i++)
			t[i]->Report(); 
	}
};

void main() {
	User users[100];
	for (int i = 0; i < 100; i++)
		users[i].id = i;

	int u;
	cout << "enter user Id: ";
	cin >> u; 

	while(true)
	{
		int action;
		cout << "Choose action: \n 1-Deposit 2-Withdrawl 3-Transfer 4-Report 5-Quit\n";
		cin >> action;

		if (action == 1)
		{
			if (users[u].numTrans < 100)
			{
				users[u].AddDeposit(); 
			}
			else
			{
				cout << "Reached maximum amount of transactions";
			}
		}
		if (action == 2)
		{
			if (users[u].numTrans < 100)
			{
				users[u].AddWithdrawl();
			}
			else
			{
				cout << "Reached maximum amount of transactions";
			}
		}
		if (action == 3)
		{
			if (users[u].numTrans < 100)
			{
				users[u].AddTransfer();
			}
			else
			{
				cout << "Reached maximum amount of transactions";
			}
		}

		if (action == 4)
		{
			users[u].Report();
		}

		if (action == 5)
		{
			exit(0);
		}
	}
}