/*
Header file for person class for Customer/Employee Data Entry program assignment
Written by Joseph Reiss U76703774
*/

#ifndef PERSON_H
#define PERSON_H

//include directives
#include <string>

//person class
class Person {
private:	//private data members

	std::string first_name;
	std::string last_name;
	std::string email_address;

public:
	//constructor
	Person(std::string first_name = "", std::string last_name = "", std::string email_address = "");

	//member functions
	void set_first_name(std::string);
	std::string get_first_name() const { return first_name; }

	void set_last_name(std::string);
	std::string get_last_name() const { return last_name; }

	void set_email_address(std::string);
	std::string get_email_address() const { return email_address; }

	std::string get_full_name() const { return first_name + " " + last_name; };
};

#endif PERSON_H
