/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 06:55:26 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/11 06:55:28 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat const & src);
        Bureaucrat(std::string const name, int grade);
        ~Bureaucrat();

        std::string getName() const;
        int         getGrade() const;
        void        signForm(bool able, std::string const form);
        void        executeForm(Form const & form);

        void        operator+=(int const num);
        void        operator-=(int const num);
        Bureaucrat& operator=(Bureaucrat const & rhs);

        class GradeTooHighException
        {
            public:
                GradeTooHighException();
                GradeTooHighException(GradeTooHighException const & src);
                ~GradeTooHighException() throw();
                virtual const char * what () const throw ();
                GradeTooHighException& operator=(GradeTooHighException const &);
        };

        class GradeTooLowException
        {
            public:
                GradeTooLowException();
                GradeTooLowException(GradeTooLowException const & src);
                ~GradeTooLowException() throw();
                virtual const char * what() const throw();
                GradeTooLowException& operator=(GradeTooLowException const &);            
        };

    private:
        std::string const   _name;
        int                 _grade;

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src); 

#endif
