/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:07:08 by ialashqa          #+#    #+#             */
/*   Updated: 2026/06/13 17:12:49 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <list>

class RPN
{
    private:
        std::stack<int, std::list<int> > _stack;
        
        bool    isOperator(char c);
        int     applyOperator(char op, int a, int b);
    
    public:
        RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& copy);
        ~RPN();
        
        void    calculate(std::string expression);
};

#endif