/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:27:06 by jibanez-          #+#    #+#             */
/*   Updated: 2023/05/18 14:52:54 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <sstream>

// I will use map as it is a great type for big amounts of data which are going
// to remain unaltered, such as in the case of the historic price of a currency

class BitcoinExchange
{
	typedef std::map<std::string, float> BE;

	public:

		BitcoinExchange();
		BitcoinExchange(BE data);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator = (BitcoinExchange const &src);
		~BitcoinExchange();

		float RateCalc(std::string line);
		void printMap();

	private:

		BE _data;

		bool _ReadLine(std::string line);
		bool _ReadDate(std::string date);
		bool _ReadValue(std::string value);

};

#endif
