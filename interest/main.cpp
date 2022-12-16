#include <iostream>
#include <iomanip>
#include "interest.h"
using namespace std;

int main() {
	double initialInvestment, monthlyDeposit, annualInterest;
	int years;

	while (1) {
		cout << setfill('*') << setw(34) << "" << endl;
		cout << setw(11) << "" << " Data Input " << setw(11) << "" << endl;
		cout << "Initial Investment Amount:" << endl;
		cout << "Monthly Deposit:" << endl;
		cout << "Annual Interest:" << endl;
		cout << "Number of Years:" << endl;
		cout << "Press Enter to Continue. . . " << endl;
		
		cout << endl;

		cout << setfill('*') << setw(34) << "" << endl;
		cout << setw(11) << "" << " Data Input " << setw(11) << "" << endl;
		cout << "Initial Investment Amount: $" << endl;
		cin >> initialInvestment;
		cout << "Monthly Deposit: $" << endl;
		cin >> monthlyDeposit;
		cout << "Annual Interest: %" << endl;
		cin >> annualInterest;
		cout << "Number of Years: " << endl;
		cin >> years;
		cout << "Press Enter to Continue. . . " << endl;

		Interest myInterest = Interest(initialInvestment, monthlyDeposit, annualInterest, years);
		cout << endl;
		myInterest.reportNoMonthlyDeposit();
		cout << endl;
		myInterest.reportWithMonthlyDeposit();
		cout << endl;

		cout << endl << "Do you want to try another? (y/n): ";
		string choice;
		cin >> choice;
		if (choice == "n") { break; }
		cout << endl;
	}

	return 0;
}