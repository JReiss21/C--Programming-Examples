/*
Header file for employee class for Customer/Employee Data Entry program assignment
Written by Joseph Reiss U76703774
*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

//include directives
#include "Person.h"
#include <string>

//employee class
class Employee : public Person {
private:	//private data members

	std::string social_security_number;

public:
	//constructor
	Employee(std::string first_name = "", std::string last_name = "", std::string email_address = "", std::string social_security_number = "");

	//member functions
	void set_social_security_number(std::string);
	std::string get_social_security_number() const { return social_security_number; }

	void display_employee_data() const;
};

#endif EMPLOYEE_H