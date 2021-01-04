//the phone book class keeps track of a phone book and allows you to insert, erase, and find an entry and allows you to get the size of the phone book and allows you to print the contents of the phone book

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#include "phoneBook.h"

// defining default constructor
phoneBook::phoneBook()
{
	phoneBookEntries = {};
	entryIterator = begin();
}

// 3 Insert Functions which either update the entry if the name exists or add the entry if the name doesen't exist
// defining insert function with a phone book entry as the passed parameter
void phoneBook::insert(const phoneBookEntry &entry)
{
	// if the name is in the book, update, or else, add
	if(find(entry.name())) // uses find function to determine if name is in book
	{
		phoneBookEntries.at(entryIterator-begin()).phoneNumber(entry.phoneNumber());
		phoneBookEntries.at(entryIterator-begin()).email(entry.email());
	}
	else
	{
		phoneBookEntries.push_back(entry);
	}
}

// defining insert function with name, number, and email as parameters
void phoneBook::insert(const std::string &name, const std::string &number, const std::string &email)
{
	// if the name is in the book, update, or else, add
	if(find(name)) // uses find function to determine if name is in book
	{
		phoneBookEntries.at(entryIterator-begin()).phoneNumber(number);
		phoneBookEntries.at(entryIterator-begin()).email(email);
	}
	else
	{
		phoneBookEntry entry(name, number, email);
		phoneBookEntries.push_back(entry);
	}
}

// defining insert function with name and number as parameters
void phoneBook::insert(const std::string &name, const std::string &number)
{
	// if the name is in the book, update, or else, add
	if(find(name)) // uses find function to determine if name is in book
	{
		phoneBookEntries.at(entryIterator-begin()).phoneNumber(number);
	}
	else
	{
		phoneBookEntry entry(name, number);
		phoneBookEntries.push_back(entry);
	}
}

// function which erases the entry with the passed name if there is one and returns true only if an entry is erased
bool phoneBook::erase(std::string name)
{
	// declaring bool variable for whether entry was erased or not
	bool erased = false;

	if(find(name)) // uses find function to determine if name is in book
	{
		phoneBookEntries.erase(entryIterator);
		erased = true; // if found erased is true
	}

	// returns whether an entry was erased or not
	return erased;
}

// function that looks for a name in the phone book and returns true if found
bool phoneBook::find(std::string name)
{
	// declaring bool variable for whether name was found or not
	bool found = false;
	entryIterator = begin(); // resetting iterator to beginning so it can hold the position of the name in the phone book vector

	// using for loop to go through entries to check if the passed name is in the book
	for(int i = 0; i < static_cast<int>(size()); i++)
	{
		// if name is found, change found to true and get out of the loop
		if(name==phoneBookEntries.at(i).name())
		{
			found = true;
			break;
		}
		entryIterator++; // adds to the position of the iterator every time an iteration passes where the name isn't found
	}

	// return whether name is found or not
	return found;
}

// 2 print functions that print out the contents of the phone book using a for loop, formatted
// one prints to cout and the other to the passed by reference ostream object
void phoneBook::print() const
{
	std::cout << std::left;
	std::cout << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;
	for(int i = 0; i < static_cast<int>(size()); i++)
	{
		std::cout << std::setw(31) << phoneBookEntries.at(i).name() << std::setw(16) << phoneBookEntries.at(i).phoneNumber() << phoneBookEntries.at(i).email() << std::endl;
	}
}
void phoneBook::print(std::ostream &out) const
{
	out << std::left;
	out << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;
	for(int i = 0; i < static_cast<int>(size()); i++)
	{
		out << std::setw(31) << phoneBookEntries.at(i).name() << std::setw(16) << phoneBookEntries.at(i).phoneNumber() << phoneBookEntries.at(i).email() << std::endl;
	}
}

// debug function to help with debugging that prints the contents of the phone book vector to the passed by reference ostream object
void phoneBook::debug(std::ostream &out) const
{
	out << std::left;
	out << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;
	for(int i = 0; i < static_cast<int>(size()); i++)
	{
		out << std::setw(31) << phoneBookEntries.at(i).name() << std::setw(16) << phoneBookEntries.at(i).phoneNumber() << phoneBookEntries.at(i).email() << std::endl;
	}
}

// function returning the vector size
std::size_t phoneBook::size() const
{
	return phoneBookEntries.size();
}

// implementing begin and end functions
phoneBook::iterator phoneBook::begin()
{
	return phoneBookEntries.begin();
}
phoneBook::iterator phoneBook::end()
{
	return phoneBookEntries.end();
}
