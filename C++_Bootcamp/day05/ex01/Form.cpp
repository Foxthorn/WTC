/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:07:30 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/11 09:07:31 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("none"), _req_grade_sign(150), _req_grade_execute(150)
{}

Form::Form(Form const & src) : _name(src._name), _req_grade_sign(src._req_grade_sign), _req_grade_execute(src._req_grade_execute)
{
    if (src._req_grade_execute > 150 || src._req_grade_sign > 150)
    {
        throw Form::GradeTooLowException();
    }
    else if (src._req_grade_execute < 1 || src._req_grade_sign < 1)
    {
        throw Form::GradeTooHighException();
    }
    else
    {
        *this = src;
    }
}

Form::Form(std::string name, int req_grade_sign, int req_grade_execute) : _name(name), _req_grade_sign(req_grade_sign), _req_grade_execute(req_grade_execute)
{
    if (req_grade_execute > 150 || req_grade_sign > 150)
    {
        throw Form::GradeTooLowException();
    }
    else if (req_grade_execute < 1 || req_grade_sign < 1)
    {
        throw Form::GradeTooHighException();
    }
}

Form::~Form() {}

std::string Form::getName() const
{
    return this->_name;
}

int         Form::getReqGradeSign() const
{
    return this->_req_grade_sign;
}

int         Form::getReqGradeExecute() const
{
    return this->_req_grade_execute;
}

bool        Form::getSigned() const
{
    return this->_signed;
}

void        Form::beSigned(Bureaucrat src)
{
    if (src.getGrade() <= this->getReqGradeSign())
    {
        this->_signed = true;        
        src.signForm(this->getSigned(), this->getName());
    }
    else
    {
        src.signForm(this->getSigned(), this->getName());
        throw Bureaucrat::GradeTooLowException();
    }
}

Form & Form::operator=(Form const & rhs)
{
    this->_signed = rhs._signed;
    return *this;
}


//GradeTooHighException

Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src) 
{
    *this = src;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException& Form::GradeTooHighException::operator=(GradeTooHighException const &)
{
    return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Error : Form grade set too high";
}

//GradeTooLowException

Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src) 
{
    *this = src;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException& Form::GradeTooLowException::operator=(GradeTooLowException const &)
{
    return *this;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Error : Form grade set too low";
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
    if (rhs.getSigned())
    {
        o << rhs.getName() << " is signed and needs a Bureaucrat with a grade of " << rhs.getReqGradeExecute() << " to execute" << std::endl;
    }
    else
    {
        o << rhs.getName() << " is not signed and needs a Bureaucrat with a grade of " << rhs.getReqGradeSign() << " to sign" << " and a grade of " << rhs.getReqGradeExecute() << " to execute" << std::endl;
    }
    return o;
}
