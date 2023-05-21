/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:27:38 by jibanez-          #+#    #+#             */
/*   Updated: 2023/05/11 20:27:39 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map <std::string, float> csv2map(const char* path)
{

	std::map <std::string, float> map;
	std::ifstream data(path);

	if (data.fail())
	{
		std::cout << "cannot open file" << std::endl;
		return (map);
	}

	std::string line;

	while (std::getline(data, line))
	{
		if (line == "date,exchange_rate")
			std::getline(data, line);

		std::string date;
		std::string valueStr;
		float value;

		date = line.substr(0, 10);
		std::istringstream(line.substr(line.find(",") + 1, line.size() - line.find(","))) >> value;

		map.insert(std::pair <std::string, float> (date, value));
	}

	return (map);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "invalid number of arguments" << std::endl;
		return (1);
	}

	std::map <std::string, float> map;

	map = csv2map("./data.csv");

	if (map.empty())
	{
		std::cout << "invalid data file" << std::endl;
		return (1);
	}

	BitcoinExchange be(map);
	std::fstream input(argv[1]);
	std::string line;

	// be.printMap();

	while (std::getline(input, line))
		be.RateCalc(line);

	return (0);
}
