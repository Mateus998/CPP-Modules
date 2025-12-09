/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:11:42 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 12:24:24 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdio>

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
    << ";withdrawals:" << _totalNbWithdrawals
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
    _totalAmount += initial_deposit;
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
    this->_nbDeposits++;
    _totalNbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
    << ";p_amount:" << this->_amount
    << ";deposit:" << deposit;
    this->_amount += deposit;
    std::cout << ";amount:" << this->_amount
    << ";nb_deposits:" << this->_nbDeposits << '\n';
    _totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
    Account::_displayTimestamp();
    if (withdrawal > this->_amount)
    {
        std::cout << "index:" << this->_accountIndex
        << ";p_amount:" << this->_amount
        << ";withdrawal:refused" << '\n';
        return false;
    }
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "index:" << this->_accountIndex
    << ";p_amount:" << this->_amount
    << ";withdrawal:" << withdrawal;
    this->_amount -= withdrawal;
    std::cout << ";amount:" << this->_amount
    << ";nb_withdrawals:" << this->_nbWithdrawals << '\n';
    _totalAmount -= withdrawal;
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
    std::time_t t = std::time(NULL);
    std::tm *tm = std::localtime(&t);
    char time_buffer[32];
    std::strftime(time_buffer, sizeof(time_buffer), "[%Y%m%d_%H%M%S] ", tm);
    std::cout << time_buffer;
}