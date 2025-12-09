
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <iostream>
#include <Contact.hpp>

class PhoneBook
{
  private:
    int len;
  public:
    Contact Contact[8];
    int       getLen();
    void      setLen(int len);
    void      addContact();
    int       displayContact();
    int       selectContact();
    int       calculateSetw(std::string str);
};

#endif
