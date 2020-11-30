/*
Implementation file for customer.h file for Customer/Employee Data Entry program assignment
Written by Joseph Reiss U76703774
*/

//include directives
#include "Customer.h"
#include <iostream>
#include <string>

//namespace
using namespace std;

//constructor for customer class
Customer::Customer(std::string first_name, std::string last_name, std::string email_address, std::string customer_number) : Person(first_name, last_name, email_address) {
	this->customer_number = customer_number;
}

/*
set customer number from customer class
precondition: a string to set the customer number value to
postcondition: sets the passed string to the customer number value for the object
*/
void Customer::set_customer_number(std::string customer_number)
{
	this->customer_number = customer_number;
}

/*
display employee data from employee class
precondition: none
postcondition: displays all of the employee objects data to the console
*/
void Customer::display_customer_data() const
{
	cout << endl << "CUSTOMER DATA" << endl;
	cout << "Name: " << get_full_name() << endl;
	cout << "Email: " << get_email_address() << endl;
	cout << "Customer Number: " << get_customer_number() << endl;
}