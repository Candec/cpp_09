/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 07:55:46 by jibanez-          #+#    #+#             */
/*   Updated: 2023/06/03 11:17:05 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

rpn::rpn(std::string &str)
{
	try
	{
		calculate(str);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

rpn::rpn(rpn const &src)
{
	*this = src;
}

rpn& rpn::operator = (rpn const &src)
{
	if(this != &src)
		this->stack = src.stack;
	return (*this);
}

rpn::~rpn()
{

}

void printStack(std::stack<int> s)\
{
	std::stack<int> copy = s;

	for (size_t i = 0; i < copy.size(); i++)
	{
		std::cout << copy.top() << " ";
		copy.pop();
	}
	std::cout << std::endl;
}

int rpn::calculator(int a, int b, char c)
{
	if (c == '+')
	{
		// std::cout << a << " + " << b << " = " << a + b << std::endl;
		return (b + a);
	}
	else if (c == '-')
	{
		// std::cout << b << " - " << a << " = " << b - a << std::endl;
		return (b - a);
	}
	else if (c == '*')
	{
		// std::cout << a << " * " << b << " = " << a * b << std::endl;
		return (b * a);
	}
	else if (c == '/')
	{
		if (b == 0)
			throw std::invalid_argument("Cannot divide by Zero\n");
		// std::cout << a << " / " << b << " = " << a / b << std::endl;
		return (b / a);
	}
	return (0);
}

void rpn::calculate(std::string &str)
{

	size_t n;
	size_t op;
	std::string operators = "+-*/";

	n = 0;
	op = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			n++;
			stack.push(str[i] - '0');
		}
		else if (operators.find(str[i]) != std::string::npos)
		{
			op++;
			int a = stack.top();
			stack.pop();
			stack.top() = calculator(a, stack.top(), str[i]);
		}
		else if (isspace(str[i]))
			continue;
		else
			throw std::invalid_argument("Error: invalid input\n");
	}

	if ((op + 1) != n)
		throw std::invalid_argument("Error: invalid input - Insuficiente operators or numbers\n");

	std::cout << stack.top() << std::endl;
}
