
#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int PhoneBook::getLen()
{
  return (len);
}

void  PhoneBook::setLen(int new_len)
{
  len = new_len;
}

void PhoneBook::addContact()
{  if (len == 8)
    Contact[7].setContact();
  else
  {
    Contact[len].setContact();
    setLen(len + 1);
  }
}

int PhoneBook::displayContact()
{
  std::cout << "|-------------------------------------------|" << std::endl;
  std::cout << "|Index     |First Name|Last Name |Secret    |" << std::endl;
  for (int i = 0; i < getLen(); i++)
  {
    std::cout << "|"<< i + 1 << std::setw(10);
    std::cout << "|" << Contact[i].truncString(Contact[i].getFname()) << std::setw(calculateSetw(Contact[i].getFname()));
    std::cout << "|" << Contact[i].truncString(Contact[i].getLname()) << std::setw(calculateSetw(Contact[i].getLname()));
    std::cout << "|" << Contact[i].truncString(Contact[i].getSecret()) << std::setw(calculateSetw(Contact[i].getSecret())) << "|"  << std::endl;
  }
  std::cout << "|-------------------------------------------|" << std::endl;
  if (len > 0)
    if (selectContact())
      return (1);
  return (0);
}

int  PhoneBook::selectContact()
{
  int input;
  std::string str;

  std::cout << "Enter valid index of the contact: ";
  std::cin >> input;
  if (std::cin.eof() || std::cin.fail())
    return (1);
  std::cin.ignore();
  if (input > 0 && input <= len)
  {
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "First Name: " <<Contact[input - 1].getFname() << std::endl;
    std::cout << "Last Name: "<<Contact[input - 1].getLname() << std::endl;
    std::cout << "Nickname: "<<Contact[input - 1].getNickname() << std::endl;
    std::cout << "Number: "<<Contact[input - 1].getNumber() << std::endl;
    std::cout << "Secret: "<<Contact[input - 1].getSecret() << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
  }
  else
    selectContact();
  return (0);
}

int PhoneBook::calculateSetw(std::string str)
{
    return (11 - str.length());
}


