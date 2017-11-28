// STL Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;


int main()
{
	float balance = 0.0;

    queue<float> transactions;


	transactions.push(160);
	transactions.push(-40);
	transactions.push(600.66);
	

	while (!transactions.empty())
	{
		balance += transactions.front();
		cout << balance << "  pushed to account" << endl;
		transactions.pop();
	}

	cout << "Final balance: $" << balance << endl;
	
    return 0;
}

