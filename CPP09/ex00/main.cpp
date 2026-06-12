/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:30:14 by ialashqa          #+#    #+#             */
/*   Updated: 2026/06/12 15:52:00 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return 1;
	}

	BitcoinExchange	btc;

	try
	{
		btc.readDatabase();
		btc.readInput(argv[1]);
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << "\n";
	}

	return 0;
}