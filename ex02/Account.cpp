#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void){
    return _nbAccounts;
}

int Account::getTotalAmount(void){
    return _totalAmount;
}

int Account::getNbDeposits(void){
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void){
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void){
    Account::_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
    << ";total:" << _totalAmount
    << ";deposits:" << _totalNbDeposits
    << ";withdrawals:" << _totalNbDeposits
    << '\n';
}

Account::Account(void){
    this->_accountIndex = _nbAccounts;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
    << ";amount" << 0 << ";created"
    << '\n';
    _nbAccounts++;
}

Account::Account( int initial_deposit ){
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
    << ";amount:" << initial_deposit << ";created"
    << '\n';
    _nbAccounts++;
}

Account::~Account( void ){
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
    << ";amount:" << this->_amount << ";closed"
    << '\n';
    _nbAccounts--;
}

void	Account::makeDeposit( int deposit ){
    this->_amount += deposit;
    this->_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ){
    if (withdrawal > this->_amount)
        return false;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    return true;
}

int		Account::checkAmount( void ) const{
    return this->_amount;
}

void	Account::displayStatus( void ) const{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals
    << '\n';
}

void Account::_displayTimestamp(void){
    std::cout << "[Timestamp] ";
}