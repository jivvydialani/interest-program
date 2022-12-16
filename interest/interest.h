#pragma once
#ifndef INTEREST_H_
#define INTEREST_H_

class Interest {
public:
	Interest(double investment, double monthlyDeposit, double rate, int years);
	virtual ~Interest();
	void reportNoMonthlyDeposit();
	void reportWithMonthlyDeposit();

private:
	double initialDeposit;
	double monthlyDeposit;
	double interestRate;
	int numYears;
};

#endif