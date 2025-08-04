/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:37:14 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/04 12:47:15 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static int open_fstreams(std::fstream& oldfile, std::fstream& newfile, const std::string& fileName)
{
	std::string outputFileName = fileName + ".replace";
    
    oldfile.open(fileName, std::ios::in);
    newfile.open(outputFileName, std::ios::out);

    if (!oldfile.is_open() || !newfile.is_open())
    {
        std::cout << "Error while opening a file\n";
        return (-1);
    }
    return (0);
}

static void replace(std::string& line, const std::string& s1, const std::string& s2)
{
    size_t begin = line.find(s1);

    while (begin != std::string::npos)
    {
        line.replace(begin, s1.length(), s2);
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
    { 
        if (av[1][0] == '\0' || av[2][0] == '\0' || av[3][0] == '\0')
        {
            std::cout << "Invalid arguments: Program only takes 3 arguments\n";
            return (-1);
        }
    }
    filename = av[1];
    s1 = av[2];
    s2 = av[3];
    if (open_fstreams(oldfile, newfile, filename) == -1)
        return (-1);
    while (getline(oldfile, line))
    {
        replace(line, s1, s2);
        newfile << line;
    }
    oldfile.close();
    newfile.close();
    return (0);
}
