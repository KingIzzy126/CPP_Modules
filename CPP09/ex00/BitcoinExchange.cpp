/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:21:53 by ialashqa          #+#    #+#             */
/*   Updated: 2026/06/04 18:25:36 by ialashqa         ###   ########.fr       */
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