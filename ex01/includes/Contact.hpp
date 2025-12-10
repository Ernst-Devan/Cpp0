
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
  private:
    std::string fname;
    std::string lname;
    std::string nickname;
    std::string number;
    std::string secret;

  public:
  int         setContact();
  int         setFname();
  std::string getFname();
  int         setLname();
  std::string getLname();
  int         setNickname();
  std::string getNickname();
  int         setNumber();
  std::string getNumber();
  int         setSecret();
  std::string getSecret();
  static std::string truncString(std::string str);
};

#endif
