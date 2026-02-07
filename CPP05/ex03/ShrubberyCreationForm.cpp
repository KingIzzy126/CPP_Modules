/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:25:20 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/07 12:25:20 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation form", 145, 137), _target("Home")
{
    std::cout << "ShrubberyCreationForm default constructor was created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm parameterized constructor was created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm copy constructor was created\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "ShrubberyCreationForm assignment operator was created\n";
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor was created\n";
}

const std::string &ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file)
    {
        std::cout << "Error: Could not create file " << _target + "_shrubbery" << "\n";
        return;
    }
    file << "         v" << "\n";
    file << "        >X<" << "\n";
    file << "         A" << "\n";
    file << "        d$b" << "\n";
    file << "      .d\\$$b." << "\n";
    file << "    .d$i$$\\$$b." << "\n";
    file << "       d$$@b" << "\n";
    file << "      d\\$$$ib" << "\n";
    file << "    .d$$$\\$$$b" << "\n";
    file << "  .d$$@$$$$\\$$ib." << "\n";
    file << "      d$$i$$b" << "\n";
    file << "     d\\$$$$@$b" << "\n";
    file << "  .d$@$$\\$$$$$@b." << "\n";
    file << ".d$$$$i$$$\\$$$$$$b." << "\n";
    file << "        ###" << "\n";
    file << "        ###" << "\n";
    file << "        ###" << "\n";
    file << "\n";
    file << "    SHRUBBERY!" << "\n";
    file.close();
}