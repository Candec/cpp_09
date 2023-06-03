/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:23:26 by jibanez-          #+#    #+#             */
/*   Updated: 2023/06/03 22:43:17 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//shuf -i 1-100000 -n 3000 | tr "\n" " "

ms::ms(char *str)
{
	std::stringstream ss(str);
	std::string n;

	while (std::getline(ss, n, ' '))
	{
		int nb;
		std::istringstream(n) >> nb;
		_vector.push_back(nb);
	}
}

ms::ms(ms const &src)
{

}

ms& ms::operator=(ms const &src)
{

}

ms::~ms()
{

}

//------------------------------------------------------------------------------

void ms::printVector(std::vector<int> vector)
{
	std::cout << "vector before: " << "[ ";

	for (size_t i = 0; i < vector.size(); i++)
	{
		if (i > 10)
			break;
		std::cout << vector[i] << " ";
	}

	std::cout << " ]" << std::endl;
}

bool ms::isSort(std::vector<int> vector)
{

}

std::list<std::vector<int>> ms::sort(std::list<std::vector<int>>)
{

}

std::list<std::vector<int>> ms::split(std::vector<int> vector)
{

}

std::vector<int> ms::join(std::list<std::vector<int>> list)
{

}
