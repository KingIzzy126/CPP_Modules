/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:21:53 by ialashqa          #+#    #+#             */
/*   Updated: 2026/06/08 13:00:36 by ialashqa         ###   ########.fr       */
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
    return *this;
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
    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if(!std::isdigit(date[i]))
            return (false);
    }
    if (month < 1 || month > 12)
        return (false);
	// Leap year handle Feb 28/29
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// Calculate year for leap year
    int	year = std::atoi(date.substr(0, 4).c_str());
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
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

float BitcoinExchange::getRate(std::string date)
{
    if (_db.empty())
    {
        std::cerr << "Error: database is empty.\n";
        return -1;
    }
    std::map<std::string, float>::iterator it = _db.lower_bound(date);
    if (it == _db.end() || it->first != date)
    {
        if (it == _db.begin())
        {
            std::cerr << "Error: date out of range => " << date << "\n";
            return -1;
        }
        --it;
    }

    return it->second;
}

void BitcoinExchange::readInput(std::string file)
{
    std::ifstream input(file.c_str());
    if (!input.is_open())
    {
        std::cerr << "Error: could not open file.\n";
        return;
    }
    std::string line;
    while (std::getline(input, line))
    {
        if (line.empty())
            continue;
        if (line == "date | value")
            continue;
        size_t split = line.find(" | ");
        if (split == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }
        std::string date    = line.substr(0, split);
        std::string rateStr = line.substr(split + 3);
        float       rate    = static_cast<float>(std::strtod(rateStr.c_str(), NULL));
        int         month   = std::atoi(date.substr(5, 2).c_str());
        int         day     = std::atoi(date.substr(8, 2).c_str());

        if (!isValidDate(date, month, day))
        {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }
        if (!isValidValue(rateStr, rate, line))
            continue;
        float dbRate = getRate(date);
        if (dbRate < 0)
            continue;
        printOutput(date, rate, dbRate);
    }
    input.close();
}

void	BitcoinExchange::printOutput(std::string date, float value, float rate)
{
	std::cout << date << " => " << value << " = " << (value * rate) << "\n";
}