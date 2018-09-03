/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:59:08 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/11 11:59:10 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form(src)
{
	*this = src;	
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() && executor.getGrade() <= this->getReqGradeExecute())
	{
		std::cout << "* DRILLING NOISE *" << std::endl;
		srand(time(NULL));
		int i = rand() % 1;
		if (i == 0)
		{
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;;
		}
		else
		{
			std::cout << this->getTarget() << " robotomization failed" << std::endl;;			
		}
	}
	else
	{
		if (!this->getSigned())
		{
			throw FormNotSignedException();
		}
		else
		{
			throw Bureaucrat::GradeTooLowException();
		}
	}
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) 
{
	if (this != &rhs)
		return *this;
	return *this;
}
