#include <iostream>
#include <string>
#include "PersonalPizza.h"
using namespace std;

double Subtotal, tax, price;

Pizza::Pizza()
{
	basePizzaPrice = 7.99;
	singleTopPrice = 0.98;
	numTops = 0;
	taxRate = 0.075;
	customerName = "No Name";
}
Pizza::Pizza(double ebaseprice, double etax, double eTops)
{
	basePizzaPrice = ebaseprice;
	singleTopPrice = eTops;
	numTops = 0;
	taxRate = etax;
	customerName = "No Name";

	if (ebaseprice < 0)
	{
		basePizzaPrice = 7.99;
	}

	else if (eTops < 0)
	{
		singleTopPrice = 0.98;
	}

	else if (etax < 0 || etax > 1)
	{
		taxRate = 0.075;
	}


}



void Pizza::setbasePizzaPrice(double uBasePrice)
{
	if (uBasePrice >= 0)
	{
		basePizzaPrice = uBasePrice;
	}
}
void Pizza::setsingleTopPrice(double uTopPrice)
{
	if (uTopPrice >= 0)
	{
		singleTopPrice = uTopPrice;
	}
}
void Pizza::setnumTops(int uTops)
{
	if (uTops >= 0 || uTops <= 7)
	{
		numTops = uTops;
	}
}
void Pizza::settaxRate(double uTaxRate)
{
	if (uTaxRate >= 0 || uTaxRate <= 1)
	{
		taxRate = uTaxRate;
	}
}
void Pizza::setcustomerName(string uCustomer)
{
	if (uCustomer.length() > 2)
	{
		customerName = uCustomer;
	}

	else
	{
		customerName = "No Name";
	}
}



double Pizza::getbasePizzaPrice()
{
	return basePizzaPrice;
}
double Pizza::getsingleTopPrice()
{
	return singleTopPrice;
}
double Pizza::getnumTops()
{
	return numTops;
}
double Pizza::gettaxRate()
{
	return taxRate;
}
string Pizza::getName()
{
	return customerName;
}

double Pizza::calcSubtotal(double baseprice, int topping, double topprice)
{
	Subtotal = baseprice + (topping * topprice);
	return Subtotal;
}
double Pizza::calcTax(double Subtotal, double taxRate)
{
	tax = Subtotal * taxRate;
	return tax;
}
double Pizza::calcTotal(double Subtotal, double tax)
{
	price = Subtotal + tax;
	return price;
}




