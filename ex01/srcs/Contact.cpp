#include "Contact.hpp"
#include <cctype>
#include <iostream>
#include <string>

int check_numbers(std::string str) {
  for (unsigned int i = 0; str[i]; i++) {
    if (!std::isdigit(str[i]))
      return (1);
  }
  return (0);
}

int Contact::setContact() {
  if (setFname())
    return (1);
  if (setLname())
    return (1);
  if (setNickname())
    return (1);
  if (setNumber())
    return (1);
  if (setSecret())
    return (1);
  return (0);
}

int Contact::setFname() {
  std::cout << "First name is: ";
  while (getline(std::cin, fname)) {
    if (fname.empty())
      setFname();
    return (0);
  }
  return (1);
}

std::string Contact::getFname() { return (fname); }

int Contact::setLname() {
  std::cout << "Last name is: ";
  while (getline(std::cin, lname)) {
    if (lname.length() == 0)
      setLname();
    return (0);
  }
  return (1);
}

std::string Contact::getLname() { return (lname); }

int Contact::setNickname() {
  std::cout << "Nickname is: ";
  while (getline(std::cin, nickname)) {
    if (nickname.length() == 0)
      setNickname();
    return (0);
  }
  return (1);
}

std::string Contact::getNickname() { return (nickname); }

int Contact::setNumber() {
  std::cout << "Number is: ";
  while (getline(std::cin, number)) {
    if (number.length() == 0 || check_numbers(number))
      setNumber();
    return (0);
  }
  return (1);
}

std::string Contact::getNumber() { return (number); }

int Contact::setSecret() {
  std::cout << "Secret is: :";
  while (getline(std::cin, secret)) {
    if (secret.length() == 0)
      setSecret();
    return (0);
  }
  return (1);
  secret = truncString(secret);
}

std::string Contact::getSecret() 
{ 
  return (secret); 
}

std::string Contact::truncString(std::string str) {
  if (str.length() > 9) 
  {
    str.resize(9);
    str.append(".");
  }
  return (str);
}
