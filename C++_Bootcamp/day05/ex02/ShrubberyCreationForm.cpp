/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:53:54 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/11 11:53:58 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src)
{
	*this = src;	
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() && executor.getGrade() <= this->getReqGradeExecute())
	{
		std::string name = this->getTarget() + "_shurbbery";
		const char *filename = name.c_str();
		std::ofstream ofs(filename);
		if (ofs)
		{
			ofs << "    O    " << std::endl << "   OOO   " << std::endl << "  OOOOO  " << std::endl << " OOOOOOO " << std::endl << "OOOOOOOOO" << std::endl << "    |    " << std::endl << " XXXXXXX " << std::endl;
		}
		ofs.close();
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

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) 
{
	if (this != &rhs)
		return *this;
	return *this;
}
