#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) 
{
  time_t date = time(0);

  tm *local = localtime(&date);

  int year = 1900 + local->tm_year;
  int month = 1 + local->tm_mon;
  int day = local->tm_mday;
  int hour = local->tm_hour;
  int minutes = local->tm_min;
  int seconds = local->tm_sec;

  this->_accountIndex = _nbAccounts++;
  this->_amount += initial_deposit;
  _totalAmount += initial_deposit;
  std::cout << "[" << year << month << day <<"_"<< hour << minutes << seconds << "] "\
  << "index:" << this->_accountIndex \
  << ";amount:" << initial_deposit \
  << ";created" << std::endl;
}

Account::~Account(void) 
{
   time_t date = time(0);

  tm *local = localtime(&date);

  int year = 1900 + local->tm_year;
  int month = 1 + local->tm_mon;
  int day = local->tm_mday;
  int hour = local->tm_hour;
  int minutes = local->tm_min;
  int seconds = local->tm_sec;

  std::cout << "[" << year << month << day <<"_"<< hour << minutes << seconds << "] "\
  << "index:" << this->_accountIndex \
  << ";amount:" << this->_amount \
  << ";closed" << std::endl;
}


int Account::getNbAccounts(void)
{ 
  return (_nbAccounts);
}

int Account::getTotalAmount(void) 
{ 
  return (_totalAmount); 
}

int Account::getNbDeposits(void) 
{ 
  return (_totalNbDeposits); 
}

int Account::getNbWithdrawals(void) 
{
  return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) 
{
  time_t date = time(0);

  tm *local = localtime(&date);

  int year = 1900 + local->tm_year;
  int month = 1 + local->tm_mon;
  int day = local->tm_mday;
  int hour = local->tm_hour;
  int minutes = local->tm_min;
  int seconds = local->tm_sec;

  std::cout << "[" << year << month << day <<"_"<< hour << minutes << seconds << "] "\
  << "accounts:" << _nbAccounts \
  << ";total:" << _totalAmount \
  << ";deposits:" << _totalNbDeposits \
  << ";withdrawals:" << _totalNbWithdrawals \
  << std::endl;
}

void	Account::makeDeposit(int deposit)
{
  time_t date = time(0);

  tm *local = localtime(&date);

  int year = 1900 + local->tm_year;
  int month = 1 + local->tm_mon;
  int day = local->tm_mday;
  int hour = local->tm_hour;
  int minutes = local->tm_min;
  int seconds = local->tm_sec;

  _totalNbDeposits++;
  this->_nbDeposits++;
  if (deposit < 0)
    return;
  std::cout << "[" << year << month << day <<"_"<< hour << minutes << seconds << "] "\
  << "index:" << this->_accountIndex \
  << ";p_amount:" << this->_amount \
  << ";deposit:" << deposit \
  << ";amount:" << this->_amount + deposit \
  << ";nb_deposits:" << this->_nbDeposits \
  << std::endl;
  this->_amount += deposit;
  _totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
  time_t date = time(0);

  tm *local = localtime(&date);

  int year = 1900 + local->tm_year;
  int month = 1 + local->tm_mon;
  int day = local->tm_mday;
  int hour = local->tm_hour;
  int minutes = local->tm_min;
  int seconds = local->tm_sec;

  if (this->_amount < withdrawal)
  {
    std::cout << "[" << year << month << day <<"_"<< hour << minutes << seconds << "] "\
    << "index:" << this->_accountIndex \
    << ";p_amount:" << this->_amount \
    << ";withdrawal:refused" \
    <<  std::endl;
    return (true);
  }
  else
  {
    _totalNbWithdrawals++;
    this->_nbWithdrawals++;
    std::cout << "[" << year << month << day <<"_"<< hour << minutes << seconds << "] "\
    << "index:" << this->_accountIndex \
    << ";p_amount:" << this->_amount \
    << ";withdrawal:" << withdrawal \
    << ";amount:" << this->_amount - withdrawal \
    << ";nb_withdrawals:" << this->_nbWithdrawals \
    <<  std::endl;
    _totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    return (false);
  }
}

int		Account::checkAmount(void) const
{
  return (this->_amount);
}

void	Account::displayStatus(void) const
{
  time_t date = time(0);

  tm *local = localtime(&date);

  int year = 1900 + local->tm_year;
  int month = 1 + local->tm_mon;
  int day = local->tm_mday;
  int hour = local->tm_hour;
  int minutes = local->tm_min;
  int seconds = local->tm_sec;

  std::cout << "[" << year << month << day <<"_"<< hour << minutes << seconds << "] " \
  << "index:" << this->_accountIndex \
  << ";amount:" << this->_amount \
  << ";deposits:" << this->_nbDeposits \
  << ";withdrawals:" << this->_nbWithdrawals \
  << std::endl;
}