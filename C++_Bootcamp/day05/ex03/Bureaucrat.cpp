/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 06:55:32 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/11 06:55:33 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("none"), _grade(150)
{}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name)
{
    if (src._grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else if (src._grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
    {
        *this = src;
    }
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
    {
        this->_grade = grade;
    }
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs)
{
    this->_grade = rhs._grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::signForm(bool able, std::string const form)
{
    if (able)
    {
        std::cout << this->getName() << " signs " << form << std::endl;
    }
    else
    {
        std::cout << this->getName() << " cannot sign " << form << " because their grade is to low" << std::endl;        
    }
}

void Bureaucrat::executeForm(Form const & form)
{
    if (this->getGrade() <= form.getReqGradeExecute())
    {
        form.execute(*this);        
        std::cout << this->getName() << " executes " << form.getName();
    }
    else
    {
        throw GradeTooLowException();
    }
}

void Bureaucrat::operator+=(int const num)
{
    if (this->_grade - num < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
    {
        this->_grade -= num;
    }
}

void Bureaucrat::operator-=(int const num)
{
    if (this->_grade + num > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        this->_grade += num;
    }
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src)
{
    o << src.getName() << ", bureaucrat grade " << src.getGrade();
    return o;
}

//GradeTooHighException

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src) 
{
    *this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &)
{
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Error : Bureaucrat grade set too high";
}

//GradeTooLowException

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src) 
{
    *this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &)
{
    return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Error : Bureaucrat grade set too low";
}