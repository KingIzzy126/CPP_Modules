/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:43:45 by ialashqa          #+#    #+#             */
/*   Updated: 2026/04/20 17:06:37 by ialashqa         ###   ########.fr       */
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
        span();
        span(unsigned int n);
        span(const span &copy);
        span &operator=(const span &copy);
        ~span();

        // Member functions
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        
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
