/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:34:44 by ialashqa          #+#    #+#             */
/*   Updated: 2026/06/10 14:52:05 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int>    _vec;
        std::deque<int>     _deq;
        
        // Ford Johnson vector
        void    mergeInsertVec(std::vector<int>& vec);
        void    insertPendingVec(std::vector<int>& chain, std::vector<int>& pending);
        void    binaryInsertVec(std::vector<int>& chain, int value, int bound);
        
        // Ford Johnson deque
        void    mergeInsertDeq(std::deque<int>& deq);
        void    insertPendingDeq(std::deque<int>& chain, std::deque<int>& pending);
        void    binaryInsertDeq(std::deque<int>& chain, int value, int bound);

        // Jacobs sequencer
        int     jacobsthal(int n);
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& source);
        PmergeMe& operator=(const PmergeMe& source);
        ~PmergeMe();
        
        void parseInput(int ac, char **av);
        void run();
};

#endif