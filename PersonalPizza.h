#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string>
using namespace std;

class Pizza {
private:
	double basePizzaPrice, singleTopPrice, taxRate;
	int numTops;
	string customerName;

public:
	Pizza();
	Pizza(double, double, double);

	void setbasePizzaPrice(double uBasePrice);
	void setsingleTopPrice(double uTopPrice);
	void setnumTops(int uTops);
	void settaxRate(double uTaxRate);
	void setcustomerName(string uCustomer);

	double getbasePizzaPrice();
	double getsingleTopPrice();
	double getnumTops();
	double gettaxRate();
	string getName();

	double calcSubtotal(double basePizzaPrice, int numTops, double singleTopPrice);
	double calcTax(double Subtotal, double taxRate);
	double calcTotal(double Subtotal, double tax);

};

#endif