
#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "stdlib.h"

PhoneBook::PhoneBook()
{
  len = 0;
  oldest = 0;
}

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
  {
    if (oldest == 8)
      oldest = 0;
    Contact[oldest++].setContact();
  }
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
    std::cout << "|" <<std::right<< std::setw(10) << i + 1;
    std::cout << "|" << std::right <<std::setw(10) << Contact::truncString(Contact[i].getFname());
    std::cout << "|" << std::right <<std::setw(10) << Contact::truncString(Contact[i].getLname());
    std::cout << "|" << std::right<< std::setw(10) << Contact::truncString(Contact[i].getSecret())  << "|"  << std::endl;
  }
  std::cout << "|-------------------------------------------|" << std::endl;
  if (len > 0)
    if (selectContact())
      return (1);
  return (0);
}

int  PhoneBook::selectContact()
{
  std::string str;
  int index;

  std::cout << "Enter valid index of the contact: ";

  while (getline(std::cin, str))
  {
    index = std::atoi((char *) str.c_str());
    
    if (str.length() == 1 && index > 0 && index <= len)
    {
      std::cout << "|-------------------------------------------|" << std::endl;
      std::cout << "First Name: " <<Contact[index - 1].getFname() << std::endl;
      std::cout << "Last Name: "<<Contact[index - 1].getLname() << std::endl;
      std::cout << "Nickname: "<<Contact[index - 1].getNickname() << std::endl;
      std::cout << "Number: "<<Contact[index - 1].getNumber() << std::endl;
      std::cout << "Secret: "<<Contact[index - 1].getSecret() << std::endl;
      std::cout << "|-------------------------------------------|" << std::endl;
    }
    else
      selectContact();
    return (0);
  }
  return (1);
}


