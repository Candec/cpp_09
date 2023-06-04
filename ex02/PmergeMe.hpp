/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:01:23 by jibanez-          #+#    #+#             */
/*   Updated: 2023/06/04 01:03:42 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <list>
# include <vector>

class ms
{
	public:
		ms();
		ms(char *str);
		ms(ms const &src);
		ms &operator=(ms const &src);
		~ms();


	private:
		std::vector<int> _vector;

		void printVector(std::vector<int> vector);
		bool isSort(std::vector<int> vector);
		std::vector<int> sort(std::vector<int> vector);
		std::list<std::vector<int> > split(std::vector<int> vector);
		std::vector<int> join(std::list<std::vector<int> > list);
};

#endif
