/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 19:55:50 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/06 19:55:50 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ---------------------------------------------- */
/*          Constructors & Destructor             */
/* ---------------------------------------------- */

AForm::AForm() : _name("King's Form"), _signed(false), _gradeSign(10), _gradeExecute(3)
{
    std::cout << "AForm: " << _name << " default constructor was created\n";
}

AForm::AForm(const std::string &name, int gradeSign, int gradeExecute)
 : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
    std::cout << "AForm parameterized constructor was created\n";
    if (_gradeSign < 1 || _gradeExecute < 1)
        throw AForm::GradeTooHighException();
    else if (_gradeSign > 150 || _gradeExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
 : _name(copy._name), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute)
{
    std::cout << "AForm copy constructor was created\n";
}

AForm &AForm::operator=(const AForm &copy)
{
    std::cout << "AForm assignment operator was created\n";
    if (this != &copy)
    {
        _signed = copy._signed;
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm: " << _name << " destructor was destroyed\n";
}

/* ---------------------------------------------- */
/*                   Getters                      */
/* ---------------------------------------------- */

const std::string &AForm::getName() const
{
    return (_name);
}

bool AForm::getSigned() const
{
    return (_signed);
}

int AForm::getGradeSign() const
{
    return (_gradeSign);
}

int AForm::getGradeExecute() const
{
    return (_gradeExecute);
}

/* ---------------------------------------------- */
/*                   Functions                    */
/* ---------------------------------------------- */

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeExecute)
        throw GradeTooLowException();
    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("grade is too high! (minimum is 1)");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return  ("grade is too low! (maximum is 150)");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("form is not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "AForm: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No")
        << ", Grade to sign: " << form.getGradeSign() << ", Grade to execute: "
        << form.getGradeExecute();
    return (out);
}