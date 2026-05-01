/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:03:58 by ialashqa          #+#    #+#             */
/*   Updated: 2026/05/01 16:05:36 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
    MutantStack();
    MutantStack(const MutantStack &copy);
    MutantStack &operator=(const MutantStack &copy);
    ~MutantStack();
    
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    
    iterator begin();
    iterator end();
    
    const_iterator begin() const;
    const_iterator end() const;
    
    reverse_iterator rbegin();
    reverse_iterator rend();
    
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

# include "MutantStack.tpp"

#endif