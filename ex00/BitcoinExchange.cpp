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
		*this = src;
}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange &src)
{
	if(this != &src)
		this->_data = src._data;
	return (*this);
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
	if (date.empty())
		return (false);

	int year, month, day;

	std::istringstream(date.substr(0, 4)) >> year;
	std::istringstream(date.substr(5, 7)) >> month;
	std::istringstream(date.substr(9, 11)) >> day;

	if (year == 0 || month == 0 || day == 0)
		return (false);

	if (year < 2009 || year > 2023)
		return (false);

	if (month < 1 || month > 12)
		return (false);

	if (day < 1 || day > 31)
		return (false);

	if (month == 2 && day > 29)
		return (false);

	if (month == 2 && day == 29 && year % 4 != 0)
		return (false);

	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (false);

	return (true);
}

bool BitcoinExchange::_ReadValue(std::string value)
{
	if (value.empty())
		return (false);

	int dot = 0;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '-')
		{
			std::cout << "Error: not a positive number: " << value << std::endl;
			return (false);
		}

		if (!std::isdigit(value[i]) && value[i] != '.')
		{
			std::cout << "Error: bad value: " << value << std::endl;
			return (false);
		}

		if (value[i] == '.')
			dot++;

		if (dot > 1)
			return (false);
	}
	return (true);
}

float BitcoinExchange::RateCalc(std::string line)
{
	if (line ==  "date | value")
		return (-1);

	if (!_ReadLine(line))
	{
		std::cout << "Error: bad input: " << line << std::endl;
		return (-1);
	}

	std::string date = line.substr(0, 10);

	if (!_ReadDate(date))
	{
		std::cout << "Error: bad input: " << line.substr(0, 10) << std::endl;
		return (-1);
	}

	std::string strValue = line.substr(13, line.size() - 13);

	if (!_ReadValue(strValue))
	{
		return (-1);
	}

	float value;
	std::istringstream(strValue) >> value;

	if (value > 1000)
	{
		std::cout << "Error: too large a number: " << value << std::endl;
		return (-1);
	}

	BE::iterator rate;
	rate = _data.upper_bound(date);

	if (rate != _data.begin())
		rate--;

	std::cout << date << " => " << value << " = " << rate->second * value << std::endl;
	return (rate->second * value);
}

void BitcoinExchange::printMap()
{
	std::map<std::string, float>::iterator it;

	std::cout << "Map contains:" << std::endl;

	for (it = _data.begin(); it != _data.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}
