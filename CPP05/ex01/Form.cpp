/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 19:55:50 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/06 19:55:50 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* ---------------------------------------------- */
/*          Constructors & Destructor             */
/* ---------------------------------------------- */

Form::Form() : _name("King's Form"), _signed(false), _gradeSign(10), _gradeExecute(3)
{
    std::cout << "Form " << _name << " default constructor was created\n";
}

Form::Form(const std::string &name, int gradeSign, int gradeExecute)
 : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
    std::cout << "Form parameterized constructor was created\n";
    if (_gradeSign < 1 || _gradeExecute < 1)
        throw Form::GradeTooHighException();
    else if (_gradeSign > 150 || _gradeExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy)
 : _name(copy._name), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute)
{
    std::cout << "Form copy constructor was created\n";
}

Form &Form::operator=(const Form &copy)
{
    std::cout << "Form assignment operator was created\n";
    if (this != &copy)
    {
        _signed = copy._signed;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form " << _name << " destructor was destroyed\n";
}

/* ---------------------------------------------- */
/*                   Getters                      */
/* ---------------------------------------------- */

const std::string &Form::getName() const
{
    return (_name);
}

bool Form::getSigned() const
{
    return (_signed);
}

int Form::getGradeSign() const
{
    return (_gradeSign);
}

int Form::getGradeExecute() const
{
    return (_gradeExecute);
}

/* ---------------------------------------------- */
/*                   Functions                    */
/* ---------------------------------------------- */

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("grade is too high! (minimum is 1)");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return  ("grade is too low! (maximum is 150)");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No")
        << ", Grade to sign: " << form.getGradeSign() << ", Grade to execute: "
        << form.getGradeExecute();
    return (out);
}