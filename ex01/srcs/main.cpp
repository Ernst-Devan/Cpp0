#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

void print_error() { std::cout << "Unknow command" << std::endl; }

int main(void) {
  std::string choice;
  PhoneBook phone;

  phone.setLen(0);
  std::cout << "Command: ";
  while (getline(std::cin, choice)) 
  {
    if (choice == "EXIT")
      return (0);
    else if (choice == "ADD")
      phone.addContact(); 
    else if (choice == "SEARCH")
    {
      if (phone.displayContact())
        return (1);
    } 
    std::cout << "Command: ";
  }
  return (1);
}
