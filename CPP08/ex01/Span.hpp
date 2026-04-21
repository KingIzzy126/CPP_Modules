/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:43:45 by ialashqa          #+#    #+#             */
/*   Updated: 2026/04/21 16:49:35 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>
# include <iostream>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();

        // Member functions
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        
        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end)
        {
            if (_numbers.size() + std::distance(begin, end) > _n)
                throw FullContainer();
            _numbers.insert(_numbers.end(), begin, end);
        }
        
        class FullContainer : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Container Span is Full");
                }
        };

        class NotEnoughNumbers : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Not enough numbers in container span.");
                }
        };
};

#endif
