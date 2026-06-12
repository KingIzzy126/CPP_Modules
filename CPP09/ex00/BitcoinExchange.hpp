/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:21:56 by ialashqa          #+#    #+#             */
/*   Updated: 2026/06/12 19:51:50 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <iomanip>
# include <cstdlib>
# include <sstream>
# include <cctype>
# include <map>
# include <stdexcept>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _db;
        
		bool	isValidDate(std::string date, int month, int day);
		bool	isValidValue(std::string rateStr, float rate, std::string line);
		float	getRate(std::string date);
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& source);
        BitcoinExchange& operator=(const BitcoinExchange& source);
        ~BitcoinExchange();

        void	readDatabase();
		void	readInput(std::string file);
		void	printOutput(std::string date, float value, float rate);
};

#endif