/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Detect.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:27:02 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/15 17:27:02 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

// Utils Libft Functions (helper)
static int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

static int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}


bool isPseudoLiteral(const std::string& str)
{
    if (str == "nan" || str == "nanf" ||
        str == "+inf" || str == "-inf" ||
        str == "+inff" || str == "-inff" ||
        str == "inf" || str == "inff")
        return true;
    return false;
}

bool isChar(const std::string& str)
{
    const char* s = str.c_str();
    int len = ft_strlen(s);

    if (len == 1 && ft_isdigit(s[0]) == 0)
        return true;
    return false;
}

bool isInt(const std::string& str)
{
    const char *s = str.c_str();
    int i = 0;
    int len = ft_strlen(s);

    if (len == 0)
        return false;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (s[i] == '\0')
        return false;
    while (s[i])
    {
        if (ft_isdigit(s[i]) == 0)
            return false;
        i++;
    }
    return true;
}

bool isFloat(const std::string& str)
{
    const char *s = str.c_str();
    int i = 0;
    int len = ft_strlen(s);
    bool hasDecimal= false;

    // Have atleast 3 chars and end with "f"
    if (len < 2 || s[len - 1] != 'f')
        return false;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (s[i] == '\0' || s[i] == 'f')
        return false;
    
    while (s[i] && s[i] != 'f')
    {
        if (s[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (ft_isdigit(s[i]) == 0)
            return false;
        i++;
    }
    return hasDecimal;
}

bool isDouble(const std::string& str)
{
    const char *s = str.c_str();
    int i = 0;
    int len = ft_strlen(s);
    bool hasDecimal = false;

    if (len == 0)
        return false;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (s[i] == '\0')
        return false;

    while (s[i])
    {
        if (s[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!ft_isdigit(s[i]))
            return false;
        i++;
    }
    return hasDecimal;
}