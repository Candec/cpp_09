/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:23:26 by jibanez-          #+#    #+#             */
/*   Updated: 2023/06/07 00:52:49 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//shuf -i 1-100000 -n 3000 | tr "\n" " "

ms::ms()
{

}

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

	std::vector<int> vector;
	vector = sort(_vector);

	printVector(vector);
}

ms::ms(ms const &src)
{
	*this = src;
}

ms& ms::operator=(ms const &src)
{
	if(this != &src)
		this->_vector = src._vector;
	return (*this);
}

ms::~ms()
{

}

//------------------------------------------------------------------------------

void ms::printVector(std::vector<int> vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (i > 10)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << vector[i] << " ";
	}
}

bool ms::isSort(std::vector<int> vector)
{
	size_t i = 1;
	while (i < vector.size() && vector[i] >= vector[i - 1])
		i++;

	return (i == vector.size() ? true : false);
}

std::vector<int> ms::sort(std::vector<int> vector)
{
	if (isSort(vector))
		return (vector);

	std::list<std::vector <int> > list;

	if (vector.size() > 1)
	{
		list = split(vector);
		list.front() = sort(list.front());
		list.back() = sort(list.back());
		vector = join(list);
	}

	return (vector);
}

std::list<std::vector<int> > ms::split(std::vector<int> vector)
{
	std::list<std::vector<int> > list;
	std::vector<int> vectorA;
	std::vector<int> vectorB;

	for (size_t i = 0; i < vector.size(); i++)
	{
		if (i < vector.size() / 2)
			vectorA.push_back(vector[i]);
		else
			vectorB.push_back(vector[i]);
	}

	list.push_back(vectorA);
	list.push_back(vectorB);

	return (list);
}

std::vector<int> ms::join(std::list<std::vector<int> > list)
{
	if (list.size() != 2)
		std::cout << "Error: list size incorrect" << std::endl;

	std::vector<int> vector;
	std::vector<int> vectorA = list.front();
	std::vector<int> vectorB = list.back();

	if (vectorA.empty())
		return (vectorB);

	if (vectorB.empty())
		return (vectorA);

	size_t a = 0;
	size_t b = 0;

	while (vector.size() < vectorA.size() + vectorB.size())
	{
		if (vectorB[b] == 0 && vectorA[a] > 0)
		{
			vector.push_back(vectorA[a]);
			a++;
		}
		else if (vectorA[a] == 0 && vectorB[b] > 0)
		{
			vector.push_back(vectorB[b]);
			b++;
		}
		else if (vectorA[a] < vectorB[b] && a < vectorA.size())
		{
			vector.push_back(vectorA[a]);
			a++;
		}
		else if (vectorB[b] <= vectorA[a] && b < vectorB.size())
		{
			vector.push_back(vectorB[b]);
			b++;
		}
	}

	return (vector);
}
