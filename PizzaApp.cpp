//Bao Chau
//CSIS 135 - Online Class
//Exam 2

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include "PersonalPizza.h"

using namespace std;

int main()
{
	double baseprice = 6.99;
	double taxrate = 0.095;
	double ToppingPrice = 1.0'9;
	double tax, total;
	char selections;
	string Name = "Pete's Personal Pizzas";
	const int size = 7;
	int newsize = 7;
	string toppingNames[size];
	string customer, customername;
	double Subtotal;
	for (int i = 0; i < size; i++)
	{
		toppingNames[i] = "No Topping";
	}

	Pizza petes;

	Pizza(baseprice, taxrate, ToppingPrice);
	do
	{
		cout << "PERSONAL PIZZA INVOICE GENERATOR\n"
			<< "--------------------------------\n"
			<< "a) Generate an Invoice\n"
			<< "q) Quit\n"
			<< "Please make make a selections: ";
		cin >> selections;
		if (selections == 'a' || selections == 'A')
		{
			cin.ignore();
			cout << "Please Enter Your Name: ";
			getline(cin, customer);
			petes.setcustomerName(customer);
			for (int i = 0; i < size; i++)
			{
				cout << "\nWhat Type Of Toppings You Wanted For Topping #" << i + 1 << ": ";
				getline(cin, toppingNames[i]);
				petes.setnumTops(newsize);
				if (toppingNames[i] == "")
				{
					newsize = newsize - 1;
				}
			}

			customername = petes.getName();
			Subtotal = petes.calcSubtotal(baseprice, newsize, ToppingPrice);
			tax = petes.calcTax(Subtotal, taxrate);
			total = petes.calcTotal(Subtotal, tax);

			cout << "\nPERSONAL PIZZA INVOICE - " << Name
				<< "\nCustomer: " << customername
				<< "\n----------------------------------------------"
				<< "\nNUMBER TOPPINGS: " << newsize
				<< "\nToppings: ";

			if (newsize > 0)
			{
				for (int i = 0; i < newsize; i++)
				{
					if (i != 0)
					{
						cout << ",";
					}
					cout << toppingNames[i];
				}
			}
			else
			{
				cout << "No Topping";
			}

			cout << "\nSUBTOTAL: " << Subtotal
				<< "\nTAX: " << tax
				<< "\n-------"
				<< "\nTOTAL " << total
				<< "\n";

			newsize = 7;
		}
		else if (selections == 'q' || selections == 'Q')
		{
			cout << "\nThank you for using our program.\n";
		}
		
		else
		{
			cout << "\nInvalid Selection\n";
			cin.ignore();
		}
	} while (selections != 'q' && selections != 'Q');
	return 0;
}