#include <iomanip>
#include <iostream>
#include "interest.h"
using namespace std;

//Parameterized constructor
Interest::Interest(double investment, double monthlyDeposit, double rate, int years) {
	initialDeposit = investment;
	this->monthlyDeposit = monthlyDeposit;
	interestRate = rate;
	numYears = years;
}

//Destructor
Interest::~Interest() {
}

void Interest::reportNoMonthlyDeposit() {
	cout << "\n     Balance and Interest Without Additional Monthly Deposits\n";
	cout << setfill('=') << setw(68) << "" << endl;
	cout << setfill(' ') << setw(10) << "Year" << "";
	cout << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest" << "" << endl;
	cout << setfill('-') << setw(68) << "" << endl;
	int currentYear = 1;
	double yearEndBalance = this->initialDeposit;
	while (currentYear <= this->numYears) {
		double interestEarned = yearEndBalance * this->interestRate / 100;
		yearEndBalance += interestEarned;
		cout << right << setfill(' ') << setw(10) << currentYear << fixed << setprecision(2)
			<< setw(20) << yearEndBalance << setw(35) << interestEarned << endl;
		currentYear++;
	}
}

void Interest::reportWithMonthlyDeposit() {
	cout << "\n     Balance and Interest With Additional Monthly Deposits\n";
	cout << setfill('=') << setw(68) << "" << endl;
	cout << setfill(' ') << setw(10) << "Year" << "";
	cout << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest" << "" << endl;
	cout << setfill('-') << setw(68) << "" << endl;
	int currentYear = 1;
	double yearEndBalance = this->initialDeposit;
	while (currentYear <= this->numYears) {
		int month = 1;
		double interestEarned = 0.0;
		double monthEndBalance = yearEndBalance;
		while (month <= 12) {
			monthEndBalance += this->monthlyDeposit;
			double monthlyInterest = monthEndBalance * this->interestRate / (100 * 12);
			interestEarned += monthlyInterest;
			monthEndBalance += monthlyInterest;
			month++;
		}
		yearEndBalance = monthEndBalance;
		cout << right << setfill(' ') << setw(10) << currentYear << fixed << setprecision(2)
			<< setw(20) << yearEndBalance << setw(35) << interestEarned << endl;
		currentYear++;
	}
}