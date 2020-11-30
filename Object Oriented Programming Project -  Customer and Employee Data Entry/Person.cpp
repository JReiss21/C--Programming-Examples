/*
Implementation file for Person.h file for Customer/Employee Data Entry program assignment
Written by Joseph Reiss U76703774
*/

//include directives
#include "Person.h"
#include <string>

//namespace
using namespace std;

//constructor for person class
Person::Person(std::string first_name, std::string last_name, std::string email_address)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->email_address = email_address;
}

/*
set first name from person class
precondition: first name to set for object
postcondition: sets the first name to the passed string
*/
void Person::set_first_name(string first_name)
{
	this->first_name = first_name;
}

/*
set last name from person class
precondition: passed last name to set for the person object
postcondition: sets the last name to the passed string
*/
void Person::set_last_name(string last_name)
{
	this->last_name = last_name;
}

/*
set email address from person class
precondition: passed email address to set for the person object
postcondition: sets the last name to the passed string
*/
void Person::set_email_address(string email_address)
{
	this->email_address = email_address;
}

