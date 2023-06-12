/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:59:16 by jibanez-          #+#    #+#             */
/*   Updated: 2023/06/12 15:19:13 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}

	if (argc == 2)
		ms ms(argv[1]);
	else
	{
		int i = 1;
		std::stringstream ss;
		while (i++ < argc)
		{
			if (i == 1)
				ss << argv[i];
			else
				ss << " " << argv[i];
		}
		ms ms(ss.str().c_str());
	}

	return (0);
}
