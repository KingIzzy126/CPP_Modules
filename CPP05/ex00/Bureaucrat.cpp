/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:18:08 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/04 20:18:08 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ---------------------------------------------- */
/*          Constructors & Destructor             */
/* ---------------------------------------------- */

Bureaucrat::Bureaucrat() : _name("Izzy"), _grade(67)
{
    std::cout << "Bureaucrat " << _name << " default constructor was created\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat parameterized was created\n";
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "Bureaucrat copy constructor was created\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Bureaucrat assignment operator was created\n";
    if (this != &copy)
    {
        _grade = copy._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destructor was destroyed\n";
}

/* ---------------------------------------------- */
/*                   Getters                      */
/* ---------------------------------------------- */

const std::string &Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

/* ---------------------------------------------- */
/*               + and - Grade                    */
/* ---------------------------------------------- */

void Bureaucrat::incrementGrade()
{
    std::cout << "Incrementing " << _name << "'s grade...\n";
    if(_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    std::cout << "Decrementing " << _name << "'s grade...\n";
    if(_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

/* ---------------------------------------------- */
/*             Exception Messages                 */
/* ---------------------------------------------- */

// provide custom what() messages for error msgs when an exception is thrown
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high! (minimum is 1)");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low! (maximum is 150)");
}

/* ---------------------------------------------- */
/*               Operator Overload                */
/* ---------------------------------------------- */

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return (out);
}