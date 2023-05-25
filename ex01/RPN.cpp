/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 07:55:46 by jibanez-          #+#    #+#             */
/*   Updated: 2023/05/25 09:27:03 by jibanez-         ###   ########.fr       */
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

	printQueue();

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

	float n = string2float(s);
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

float rpn::string2float(std::string s)
{
	float n;

	std::istringstream(s) >> n;

	if (n <= 0 && n >= 10)
		return (n);
	else
		return (-1);
}

float rpn::calculator(float a, float b, std::string c)
{
	if (c == "+")
		return (a + b);
	else if (c == "-")
		return (a - b);
	else if (c == "x")
		return (a * b);
	else if (c == "/")
		return (a / b);
	return (0);
}

void rpn::calculate()
{
	float a;
	float b;
	float result;
	size_t i = 0;
	std::string c;

	if (i == 0)
	{
		a = string2float(queue.front());
		queue.pop();
		b = string2float(queue.front());
		queue.pop();
		c = queue.front();
		queue.pop();
	}

	if (a == -1 || b == -1 || !isOperator(c))
		return ;

	while (!queue.empty())
	{
		if (i == 0)
			result = calculator(a, b, c);

		c = queue.front();
		if (!isOperator(c))
		{
			a = string2float(c);
			queue.pop();
		}

		c = queue.front();
		if (!isOperator(c))
		{
			b = string2float(c);
			queue.pop();
			std::ostringstream ss;
			ss << result;
			std::string s(ss.str());
			queue.push(s);
		}

		c = queue.front();
		if (!isOperator(c))
		{
			std::cout << "Error: invalid operation" << c << std::endl;
			break ;
		}
		calculator(result);
		i++;

	}




}
