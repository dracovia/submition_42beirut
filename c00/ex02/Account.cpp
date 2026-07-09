/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 14:39:54 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/09 16:29:54 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>


// static members 
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0; 
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals= 0;

// normal variables inside const 

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";created" << std::endl;
}
Account::~Account( void )
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

// static getters 
int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
    return _totalAmount;
}
int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}
// normal setters 
void	Account::makeDeposit(int deposit)
{
	int previousAmount;

	previousAmount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << previousAmount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}
bool	Account::makeWithdrawal(int withdrawal)
{
	int previousAmount;

	previousAmount = _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << previousAmount
		<< ";withdrawal:";

	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;

	return (true);
}
int		Account::checkAmount( void ) const
{
    return _amount;
}

// other methods 
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}
void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm		*timeInfo;

	now = std::time(0);
	timeInfo = std::localtime(&now);

	std::cout << "["
		<< std::setfill('0') << std::setw(4) << timeInfo->tm_year + 1900
		<< std::setw(2) << timeInfo->tm_mon + 1
		<< std::setw(2) << timeInfo->tm_mday
		<< "_"
		<< std::setw(2) << timeInfo->tm_hour
		<< std::setw(2) << timeInfo->tm_min
		<< std::setw(2) << timeInfo->tm_sec
		<< "] "
		<< std::setfill(' ');
}