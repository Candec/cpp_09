/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 07:55:46 by jibanez-          #+#    #+#             */
/*   Updated: 2023/05/22 00:50:00 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

rpn::rpn(std::string &str)
{
	std::stringstream ss(str);
	std::string tk;

	while (std::getline(ss, tk, ' '))
	{
		if (rpnValidator(tk))
			queue.push(tk);
		else
		{
			queue.empty();
			std::cout << "Error: invalid input: " << tk << std::endl;
			break;
		}
	}
}

rpn::rpn(rpn const &src)
{
	*this = src;
}

rpn& rpn::operator = (rpn const &src)
{
	if(this != &src)
		this->queue = src.queue;
	return (*this);
}

rpn::~rpn()
{

}

void rpn::printQueue()
{
	std::queue <std::string> copy;
	copy = queue;

	while (!copy.empty())
	{
		std::cout << copy.front() << std::endl;
		copy.pop();
	}
}

bool rpn::rpnValidator(std::string s)
{
	if (isOperator(s))
		return (true);

	int n = string2int(s);
	std::istringstream(s) >> n;
	if (n >= 0 && n  <= 10)
		return (true);

	return (false);
}

bool rpn::isOperator(std::string s)
{
	if (s == "x" || s == "/" || s == "+" || s == "-")
		return (true);
	return (false);
}

int rpn::string2int(std::string s)
{
	int n;

	std::istringstream(s) >> n;

	if (n <= 0 && n >= 10)
		return (n);
	else
		return (-1);
}

void calculate()
{

}
