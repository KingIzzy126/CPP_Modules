/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:37:14 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/03 17:07:58 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static int open_fstreams(std::fstream& oldfile, std::fstream& newfile, char *fileName)
{
	std::string outputFileName = std::string(fileName) + ".replace";
    newfile.open(fileName, std::ios::in);
    oldfile.open(outputFileName, std::ios::out);

    if (!oldfile.is_open() || !newfile.is_open())
    {
        std::cout << "Error while opening a file\n";
        return (-1);
    }
    return (0);
}

static void replace(std::string line, std::string s1, std::string s2)
{
    size_t begin = line.find(s1);
    size_t len = s1.length();

    while (begin != std::string::npos)
    {
        line.replace(begin, len, s2);
        begin = line.find(s1, begin + s2.length());
    }
}
int main(int ac, char **av)
{
    std::fstream    oldfile;
    std::fstream    newfile;
    std::string     line;
    std::string     filename;
    std::string     s1;
    std::string     s2;

    if (ac != 4)
}



	if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cout << "Invalid arguments: Program takes 3 non-empty arguments!" << std::endl;
		return (-1);
	}

	fname = argv[1];
	s1 = strdup(argv[2]);
	s2 = strdup(argv[3]);

	if (open_fstreams(istream, ostream, fname))
		return (-1);
	while (getline(istream, line))
	{
		replace(line, s1, s2);
		ostream << line << std::endl;
	}
	istream.close();
	ostream.close();
}
