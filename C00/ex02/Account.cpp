/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:45:25 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/20 12:54:40 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0); // get time now
	std::tm *now = std::localtime(&t);
	std::cout << "[" << (now->tm_year + 1900) << (now->tm_mon < 9 ? "0" : "") << (now->tm_mon
		+ 1) << (now->tm_mday < 10 ? "0" : "") << now->tm_mday << "_"
		<< (now->tm_hour < 10 ? "0" : "") << now->tm_hour 
		<< (now->tm_min < 10 ? "0" : "") << now->tm_min << now->tm_sec << "]" << " ";
}

void Account::_print_func(const Account &obj, int mode)
{
	Account::_displayTimestamp();
	switch (mode)
	{
	case 0:
		std::cout << "index:" << obj._accountIndex << ";amount:" << obj._amount << ";created" << std::endl;
		break ;
	case 1:
		std::cout << "index:" << obj._accountIndex << ";amount:" << obj._amount << ";deposits:" << obj._nbDeposits << ";withdrawals:" << obj._nbWithdrawals << std::endl;
		break ;
	case 2:
		std::cout << "index:" << obj._accountIndex << ";p_amount:" << obj._pAmount << ";deposit:" << obj._deposit << ";amount:" << obj._amount << ";nb_deposits:" << obj._nbDeposits << std::endl;
		break ;
	case 3:
		std::cout << "index:" << obj._accountIndex << ";p_amount:" << obj._pAmount << ";withdrawal:" << obj._withdrawal << ";amount:" << obj._amount << ";nb_withdrawals:" << obj._nbWithdrawals << std::endl;
		break ;
	case 4:
		std::cout << "index:" << obj._accountIndex << ";p_amount:" << obj._pAmount << ";withdrawal:refused" << std::endl;
		break ;
	case 5:
		std::cout << "index:" << obj._accountIndex << ";amount:" << obj._amount << ";closed" << std::endl;
		break ;
	}
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) : _amount(initial_deposit),
	_accountIndex(_nbAccounts), _nbDeposits(0), _nbWithdrawals(0), _pAmount(0),
	_deposit(0), _withdrawal(0)
{
	Account::_print_func(*this, 0);
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
}

Account::~Account(void)
{
	Account::_print_func(*this, 5);
}

void Account::makeDeposit(int deposit)
{
	this->_deposit = deposit;
	this->_pAmount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_print_func(*this, 2);
}

bool Account::makeWithdrawal(int withdrawal)
{
	this->_withdrawal = withdrawal;
	this->_pAmount = this->_amount;
	if (!this->checkAmount())
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_print_func(*this, 3);
		return (true);
	}
	Account::_print_func(*this, 4);
	return (false);
}

int Account::checkAmount(void) const
{
	if (this->_amount < this->_withdrawal)
		return (1);
	return (0);
}

void Account::displayStatus(void) const
{
	Account::_print_func(*this, 1);
}

int Account::getNbAccounts(void) { return (_nbAccounts); }
int Account::getTotalAmount(void) { return (_totalAmount); }
int Account::getNbDeposits(void) { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }
