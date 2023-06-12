/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:01:23 by jibanez-          #+#    #+#             */
/*   Updated: 2023/06/12 18:07:16 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <list>
# include <vector>
# include <deque>
# include <ctime>
# include <sys/time.h>
# include <unistd.h>


class ms
{
	public:
		ms();
		ms(const char *str);
		ms(ms const &src);
		ms &operator=(ms const &src);
		~ms();


	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		void printVector(std::vector<int> vector);
		void printDeque(std::deque<int> deque);
		bool isSort(std::vector<int> vector);
		bool isSort(std::deque<int> deque);
		std::vector<int> sort(std::vector<int> vector);
		std::deque<int> sort(std::deque<int> deque);
		std::list<std::vector<int> > split(std::vector<int> vector);
		std::list<std::deque<int> > split(std::deque<int> deque);
		std::vector<int> join(std::list<std::vector<int> > list);
		std::deque<int> join(std::list<std::deque<int> > list);
};

#endif
