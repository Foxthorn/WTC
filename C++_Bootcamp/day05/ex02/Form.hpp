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

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(Form const & src);
        Form(std::string name, int req_grade_sign, int req_grade_execute);        
        virtual ~Form();

        Form& operator=(Form const & rhs);

        void        setTarget(std::string target);
        std::string getTarget() const;
        std::string getName() const;
        int         getReqGradeSign() const;
        int         getReqGradeExecute() const;
        bool        getSigned() const;

        void        beSigned(Bureaucrat src);
        virtual void execute(Bureaucrat const & src) const = 0;

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

        class FormNotSignedException
        {
            public:
                FormNotSignedException();
                FormNotSignedException(FormNotSignedException const & src);
                ~FormNotSignedException() throw();
                virtual const char * what() const throw();
                FormNotSignedException& operator=(FormNotSignedException const &);
        };

    private:
        std::string const _name;
        std::string       _target;
        int const         _req_grade_sign;
        int const         _req_grade_execute;
        bool              _signed;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif

