/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 19:44:24 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/06 19:44:24 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExecute;

    public:
        Form();
        Form(const std::string &name, int gradeSign, int gradeExecute);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        const std::string  &getName() const;
        bool                getSigned() const;
        int                 getGradeSign() const;
        int                 getGradeExecute() const;

        void    beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif