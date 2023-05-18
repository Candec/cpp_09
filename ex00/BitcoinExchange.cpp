/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:27:34 by jibanez-          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:57 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(BE data)
{
	_data = data;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{

}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange &src)
{

}

bool BitcoinExchange::_ReadLine(std::string line)
{
	if (line.size() < 13)
		return (false);
	
	if (std::isdigit(line[4]) || std::isdigit(line[7]))
		return (false);
		
	if (line[4] != '-' || line[7] != '-')
		return (false);

	if (line[10] != ' ' || line[12] != ' ')
		return (false);

	if (line[11] != '|')
		return (false);

	return (true);
}

bool BitcoinExchange::_ReadDate(std::string date)
{

}

bool BitcoinExchange::_ReadValue(std::string value)
{

}

void BitcoinExchange::RateCalc(std::string line)
{

}
