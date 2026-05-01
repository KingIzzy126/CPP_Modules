/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:04:07 by ialashqa          #+#    #+#             */
/*   Updated: 2026/05/01 17:10:29 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout <<mstack.top() << std::endl; // 17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // 1
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << "\n=== Comparison with std::list ===\n";
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        lst.pop_back();
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        
        std::cout << "Iterating through list:\n";
        std::list<int>::iterator it = lst.begin(); 
        while (it != lst.end())
        {
            std::cout << *it << "\n";
            ++it;
        }
    }

    std::cout << "\n=== Reverse Iterator ===\n";
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        
        MutantStack<int>::reverse_iterator it = mstack.rbegin(); 
        while(it != mstack.rend())
        {
            std::cout << *it << "\n";
            ++it;
        }
    }


    return 0;
}