/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 06:55:41 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/11 06:55:42 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat  c("Mike", 150);
    Bureaucrat  d("Bob", 1);

    //BUREAUCRAT
    std::cout << std::endl;
    std::cout << "----BUREAUCRAT----" << std::endl;
    std::cout << std::endl;  

    try
    {
        std::cout << "Creating James with grade 151" << std::endl;
        Bureaucrat a("James", 151);
        std::cout << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;        
    }

    try
    {
        std::cout << "Creating John with grade 0" << std::endl;        
        Bureaucrat b("John", 0);
        std::cout << std::endl;        
    }
    catch (Bureaucrat::GradeTooHighException e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;        
    }

    try
    {
        std::cout << c << std::endl;
        std::cout << "Decreasing Mikes grade by one" << std::endl;  
        c -= 1;      
        std::cout << c << std::endl;    
    }
    catch (Bureaucrat::GradeTooLowException e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;        
    }

    try
    {
        std::cout << d << std::endl;
        std::cout << "Increasing Bobs grade by one" << std::endl;  
        d += 1;      
        std::cout << d << std::endl;    
    }
    catch (Bureaucrat::GradeTooHighException e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;        
    }

    std::cout << std::endl;
    std::cout << "----FORMS----" << std::endl;
    std::cout << std::endl;    
    //FORM

   try
    {
        std::cout << "Creating PresidentialPardonForm C67 with sign grade 25" << std::endl;
        PresidentialPardonForm p = PresidentialPardonForm("Obama");
        std::cout << "Creating Mike with grade 150" << std::endl;   
        Bureaucrat mike("Mike", 150);     
        mike.executeForm(p);
        std::cout << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;        
    }

    try
    {
        std::cout << "Creating RobotomyRequestForm C68 with execute grade 45" << std::endl;
        RobotomyRequestForm r = RobotomyRequestForm("That Guy");
        std::cout << "Creating bob with grade 45" << std::endl;   
        Bureaucrat bob("bob", 45);     
        bob.executeForm(r);
        std::cout << std::endl;
    }
    catch (Form::FormNotSignedException e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;        
    }

    Intern intern;
    Form* rrf;
    Form* unknown;

    rrf = intern.makeForm("robotomy request", "Bender");
    unknown = intern.makeForm("dunno", "that Guy");
}
