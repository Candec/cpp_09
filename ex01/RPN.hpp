/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 07:55:54 by jibanez-          #+#    #+#             */
/*   Updated: 2023/05/25 08:52:25 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <queue>
# include <iostream>
# include <sstream>

class rpn
{

	public:

	rpn(std::string &str);
	rpn(rpn const &src);
	rpn &operator = (rpn const &src);
	~rpn();

	void printQueue();
	void calculate();

	private:

	std::queue <std::string> queue;
	bool rpnValidator(std::string s);
	bool isOperator(std::string s);
	float string2float(std::string s);
	float rpn::calculator(float a, float b, std::string c);


};

#endif
