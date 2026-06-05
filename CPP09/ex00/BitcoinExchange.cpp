/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:21:53 by ialashqa          #+#    #+#             */
/*   Updated: 2026/06/05 19:44:29 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source) : _db(source._db)
{
    
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& source)
{
    if(this != &source)
    {
        _db = source._db;
    }
}

BitcoinExchange::~BitcoinExchange()
{
    
}

void BitcoinExchange::readDatabase()
{
    std::ifstream   file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database.\n";
        return;
    }
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        std::string date    = line.substr(0, comma);
        std::string rateStr = line.substr(comma + 1);
        float       rate    = static_cast<float>(std::strtod(rateStr.c_str(), NULL));
        _db[date] = rate;
    }
    file.close();
}

bool BitcoinExchange::isValidDate(std::string date, int month, int day)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);
    for (int i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if(!std::isdigit(date[i]))
            return (false);
    }
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    
    return (true);
}

bool BitcoinExchange::isValidValue(std::string rateStr, float rate, std::string line)
{
    char* end;
    std::strtod(rateStr.c_str(), &end);
    
    if(end == rateStr.c_str() || *end != '\0')
    {
        std::cerr << "Error: bad input => " << line << "\n";
        return (false);
    }
    if (rate < 0)
    {
        std::cerr << "Error: not a positive number.\n";
        return (false);
    }
    if (rate > 1000)
    {
        std::cerr << "Error: too large number.\n";
        return (false);
    }
    return (true);
}

