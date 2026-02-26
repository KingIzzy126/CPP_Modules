/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:21:27 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/15 17:21:27 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

/* ---------------------------------------------- */
/*       Orthodox Canonical Form (private)        */
/* ---------------------------------------------- */

ScalarConvert::ScalarConvert() 
{

}

ScalarConvert::ScalarConvert(const ScalarConvert& other) 
{ 
    (void)other; 
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert& other) 
{ 
    (void)other; 
    return *this; 
}

ScalarConvert::~ScalarConvert() 
{

}

/* ---------------------------------------------- */
/*                   Printing                     */
/* ---------------------------------------------- */

static void printChar(double value, bool impossible)
{
    std::cout << "char: ";
    if(impossible || value != value || value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (value < 32 || value == 127)
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(static_cast<int>(value)) << "'\n";
}

static void printInt(double value, bool impossible)
{
    std::cout << "int: ";
    if (impossible || value != value  || value < static_cast<double>(INT_MIN)
        || value > static_cast<double>(INT_MAX))
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";
}

static void printFloat(double value, bool impossible)
{
    std::cout << "float: ";
    if (impossible)
    {
        std::cout << "impossible\n";
        return;
    }
    float f = static_cast<float>(value);
    std::cout << f;
    if (f == static_cast<int>(f) && !(f != f) && f < 1000000.0f && f > -1000000.0f)
        std::cout << ".0";
    std::cout << "f\n";
}

static void printDouble(double value, bool impossible)
{
    std::cout << "double: ";
    if (impossible)
    {
        std::cout << "impossible\n";
        return;
    }
    std::cout << value;
    if (value == static_cast<int>(value) && !(value != value) && value < 1000000.0 && value > -1000000.0)
        std::cout << ".0";
    std::cout << "\n";
}

static void handlePseudo(const std::string &str)
{
    double value;

    if (str == "nanf" || str == "nan")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf")
        value = std::numeric_limits<double>::infinity();
    else
        value = -std::numeric_limits<double>::infinity();

    printChar(value, true);
    printInt(value, true);
    printFloat(value, false);
    printDouble(value, false);
}

void ScalarConvert::convert(const std::string &literal)
{
    if (isPseudoLiteral(literal))
    {
        handlePseudo(literal);
        return;
    }

    double value;
    bool impossible = false;

    if (isChar(literal))
        value = static_cast<double>(literal[0]);
    else if (isInt(literal))
    {
        long l = std::strtol(literal.c_str(), NULL, 10);
        if (l < INT_MIN || l > INT_MAX)
            impossible = true;
        value = static_cast<double>(l);
    }
    else if (isFloat(literal))
        value = static_cast<double>(std::strtod(literal.c_str(), NULL));
    else if (isDouble(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    printChar(value, impossible);
    printInt(value, impossible);
    printFloat(value, impossible);
    printDouble(value, impossible);
}