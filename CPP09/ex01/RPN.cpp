/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:13:05 by ialashqa          #+#    #+#             */
/*   Updated: 2026/06/08 17:47:25 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    
}

RPN::RPN(const RPN& copy) : _stack(copy._stack)
{
    
}

RPN& RPN::operator=(const RPN& copy)
{
    if (this != &copy)
        _stack = copy._stack;
    return (*this);
}

RPN::~RPN()
{
    
}

bool    RPN::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int     RPN::applyOperator(char op, int a, int b)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

void    RPN::calculate(std::string expression)
{
    std::istringstream  stream(expression);
    std::string         token;
    
    while (stream >> token)
    {
        if (token.size() != 1)
        {
            std::cerr << "Error\n";
            return;
        }
        char c = token[0];
        if (c >= '0' && c <= '9')
        {
            _stack.push(c - '0');
            continue;
        }
        if (isOperator(c))
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error\n";
                return;
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            
            if (c == '/' && b == 0)
            {
                std::cerr << "Error: division by zero\n";
                return; 
            }
            _stack.push(applyOperator(c, a, b));
            continue;
        }
        std::cerr << "Error\n";
        return;
    }
    if(_stack.size() != 1)
    {
        std::cerr << "Error\n";
        return;
    }
    std::cout << _stack.top() << "\n";
}