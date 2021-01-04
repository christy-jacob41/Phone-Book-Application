//the phoneBookEntry class keeps track of one entry and can return name, number, and email and change number and email

#include <string>

#include "phoneBookEntry.h"

// implementing constructors
// default constructor
phoneBookEntry::phoneBookEntry()
{
	entryName = "";
	entryPhoneNumber = "";
	entryEmail = "";
}
// constructor with name and number
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number)
{
	entryName = name;
	entryPhoneNumber = number;
	entryEmail = "";
}
// constructor with name, number, and email
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email)
{
	entryName = name;
	entryPhoneNumber = number;
	entryEmail = email;
}
phoneBookEntry::phoneBookEntry(const phoneBookEntry &from) // copy constructor
{
	entryName = from.name();
	entryPhoneNumber = from.phoneNumber();
	entryEmail = from.email();
}

// implementing accessors
std::string phoneBookEntry::name() const
{
	return entryName;
}
std::string phoneBookEntry::phoneNumber() const
{
	return entryPhoneNumber;
}
std::string phoneBookEntry::email() const
{
	return entryEmail;
}

// implementing mutators
void phoneBookEntry::phoneNumber(const std::string &newNumber)
{
	entryPhoneNumber = newNumber;
}
void phoneBookEntry::email(const std::string &newEmail)
{
	entryEmail = newEmail;
}
