/*
Header file for the customer class for Customer/Employee Data Entry program assignment
Written by Joseph Reiss U76703774
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

//include directives
#include "Person.h"
#include <string>

//customer class
class Customer : public Person {
private:	//private data members

	std::string customer_number;

public:
	//constructor
	Customer(std::string first_name = "", std::string last_name = "", std::string email_address = "", std::string customer_number = "");

	//member functions
	void set_customer_number(std::string);
	std::string get_customer_number() const { return customer_number; }

	void display_customer_data() const;
};
#endif CUSTOMER_H