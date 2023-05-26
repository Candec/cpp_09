/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 07:55:54 by jibanez-          #+#    #+#             */
/*   Updated: 2023/05/26 09:21:01 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <vector>
# include <stack>
# include <iostream>
# include <sstream>

class rpn
{

	public:

	rpn(std::string &str);
	rpn(rpn const &src);
	rpn &operator = (rpn const &src);
	~rpn();

	void calculate(std::string &input);
	int calculator(int a, int b, char c);

	private:

	std::stack <int> stack;


};

#endif
