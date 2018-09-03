/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:07:34 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/11 09:07:35 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
    public:
        Form();
        Form(Form const & src);
        Form(std::string name, int req_grade_sign, int req_grade_execute);        
        ~Form();

        Form& operator=(Form const & rhs);

        std::string getName() const;
        int         getReqGradeSign() const;
        int         getReqGradeExecute() const;
        bool        getSigned() const;

        void        beSigned(Bureaucrat src);

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
        std::string const _name;
        int const         _req_grade_sign;
        int const         _req_grade_execute;
        bool              _signed;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif

