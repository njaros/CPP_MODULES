/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:39:58 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 17:14:53 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>

int	Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account( void ) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts += 1;
	if (this->_nbAccounts - 1)
		std::cout << std::endl;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created";
}

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts += 1;
	this->_totalAmount += this->_amount;
	if (this->_nbAccounts - 1)
		std::cout << std::endl;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created";
}

Account::~Account( void )
{
	static int	trickSolve = 0;	//Ce tricks est nécessaire car l'exo a été conçu pour Linux et non pour Mac,
								//En effet, Mac détruit les éléments dans le sens inverse de Linux, ce qui rend
								//l'exercice infaisable.
								//trickSolve me permet d'inverser toutes les valeurs des éléments avant les destructions.
	int			i;
	int			tot;
	int			temp;
	i = -1;
	if (!trickSolve)
	{
		trickSolve = 1;
		if (this->_accountIndex)
		{
			tot = this->_nbAccounts - 1;
			while (++i < this->_nbAccounts / 2)
			{
				(this - i)->_accountIndex = i;
				(this - (tot - i))->_accountIndex = tot - i;
				temp = (this - i)->_amount;
				(this - i)->_amount = (this - (tot - i))->_amount;
				(this - (tot - i))->_amount = temp;
			}
		}
	}
	std::cout << std::endl;
	this->_displayTimestamp();
	this->_nbAccounts -= 1;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed";
}

void	Account::makeDeposit( int deposit )
{
	std::cout << std::endl;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	this->_totalNbDeposits += 1;
	this->_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	std::cout << std::endl;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused";
		return (0);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		this->_totalNbWithdrawals += 1;
		this->_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals;
		return (1);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	std::cout << std::endl;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals;
}

void	Account::_displayTimestamp( void )
{
	time_t		rawtime;
	struct tm	*timeinfo;
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);	
	std::cout << "[" << timeinfo->tm_year + 1900;
	std::cout.fill ('0');
	std::cout.width(2); 
	std::cout << timeinfo->tm_mon + 1;
	std::cout.fill ('0');
	std::cout.width(2);
	std::cout << timeinfo->tm_mday;
	std::cout << "_";
	std::cout.fill ('0');
	std::cout.width(2);
	std::cout << timeinfo->tm_hour;
	std::cout.fill ('0');
	std::cout.width(2);
	std::cout << timeinfo->tm_min;
	std::cout.fill ('0');
	std::cout.width(2);
	std::cout << timeinfo->tm_sec;
	std::cout << "] ";
	//std::cout << "[19920104_091532] ";
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	std::cout << std::endl;
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
}
