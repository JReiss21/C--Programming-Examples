/*
This program is the solution to the Customer/Employee Data Entry program assignment
Written by Joseph Reiss U76703774
*/

//include directives
#include "Person.h"
#include "Employee.h"
#include "Customer.h"
#include <string>
#include <iostream>
#include <limits>

//namespace
using namespace std;

//main function
int main()
{
	//beginning message
	cout << endl << "Customer/Employee Data Entry Program" << endl << endl;

	//main loop to execute program until user enters end condition
	while (true)
	{
		char user_continue = ' ';
		char cust_or_empl = ' ';
		cout << endl << "Would you like to enter data for a customer or employee? (c/e): ";		//getting user input for customer or employee data entry
		cin >> cust_or_empl;
		if (!cin.good())	//handling input
		{
			cout << "Invalid input, not a character." << endl;
			while (true)
			{
				cout << endl << "Continue? (y/n): ";		//getting user input to continue program or not
				cin >> user_continue;
				if (!cin.good())
				{
					cout << "Invalid input, not a character. Try again." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
				
				//processing the users choice to continue program or not
				if (tolower(user_continue) == 'y')
				{
					break;
				}
				else if (tolower(user_continue) == 'n')
				{
					//ending message
					cout << endl << endl << "End of program. Goodbye!" << endl;
					return 0;
				}
				else
				{
					cout << "Invalid choice. Try again." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			continue;
		}

		//variables for employee & customer that can be used for either
		string first_name;
		string last_name;
		string email_address;

		//getting data for an employee if selected
		if (tolower(cust_or_empl) == 'e')
		{
			Employee employee;
			string social_security_number;
			
			//getting data
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "DATA ENTRY" << endl;
			cout << "First name: ";
			getline(cin, first_name);
			cout << "Last name: ";
			getline(cin, last_name);
			cout << "Email Address: ";
			getline(cin, email_address);
			cout << "SSN: ";
			getline(cin, social_security_number);

			//setting the objects variables to the data entered
			employee.set_first_name(first_name);
			employee.set_last_name(last_name);
			employee.set_email_address(email_address);
			employee.set_social_security_number(social_security_number);

			//displaying the object
			cout << endl;
			employee.display_employee_data();
		}
		else if (tolower(cust_or_empl) == 'c')	//getting data for customer if selected
		{
			Customer customer;
			string customer_number;

			//getting data
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "DATA ENTRY" << endl;
			cout << "First name: ";
			getline(cin, first_name);
			cout << "Last name: ";
			getline(cin, last_name);
			cout << "Email Address: ";
			getline(cin, email_address);
			cout << "Customer Number: ";
			getline(cin, customer_number);

			//setting the objects variables to the data entered
			customer.set_first_name(first_name);
			customer.set_last_name(last_name);
			customer.set_email_address(email_address);
			customer.set_customer_number(customer_number);

			//displaying the object
			cout << endl;
			customer.display_customer_data();
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (true)
		{
			cout << endl << "Continue? (y/n): ";		//getting user input to continue program or not
			cin >> user_continue;
			if (!cin.good())
			{
				cout << "Invalid input, not a character. Try again." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			//processing the users choice to continue program or not
			if (tolower(user_continue) == 'y')
			{
				break;
			}
			else if (tolower(user_continue) == 'n')
			{
				//ending message
				cout << endl << endl << "End of program. Goodbye!" << endl;
				return 0;
			}
			else
			{
				cout << "Invalid choice. Try again." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		continue;
	}
}