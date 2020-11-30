/*
Implementation file for Employee.h file for Customer/Employee Data Entry program assignment
Written by Joseph Reiss U76703774
*/

//include directives
#include "Employee.h"
#include <string>
#include <iostream>

//namespace
using namespace std;

//constructor for the employee class
Employee::Employee(std::string first_name, std::string last_name, std::string email_address, std::string social_security_number) : Person(first_name, last_name, email_address) {
	this->social_security_number = social_security_number;
}

/*
set social security number from employee class
precondition: string value to set ssn for object
postcondition: sets the passed string value as ssn for the object
*/
void Employee::set_social_security_number(std::string social_security_number)
{
	this->social_security_number = social_security_number;
}

/*
display employee data from employee class
precondition: none
postcondition: displays all of the employee objects data to the console
*/
void Employee::display_employee_data() const
{
	cout << endl << "EMPLOYEE DATA" << endl;
	cout << "Name: " << get_full_name() << endl;
	cout << "Email: " << get_email_address() << endl;
	cout << "SSN: " << get_social_security_number() << endl;
}