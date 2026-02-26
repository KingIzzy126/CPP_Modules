/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:19:13 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/15 17:19:13 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <limits>

class ScalarConvert 
{
    private:
        ScalarConvert();
        ScalarConvert(const ScalarConvert& other);
        ScalarConvert& operator=(const ScalarConvert& other);
        ~ScalarConvert();
    public:
        static void convert(const std::string& input);
};

// Detection Functions
bool isPseudoLiteral(const std::string& str);
bool isChar(const std::string& str);
bool isInt(const std::string& str);
bool isFloat(const std::string& str);
bool isDouble(const std::string& str);

#endif