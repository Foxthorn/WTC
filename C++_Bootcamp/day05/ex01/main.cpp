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

int main()
{
    Bureaucrat  c("Mike", 150);
    Bureaucrat  d("Bob", 1);
    Form        e("C28", 50, 50);

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
        std::cout << "Creating form C67 with sign grade 151" << std::endl;
        Form e("C67", 151, 150);
        std::cout << std::endl;
    }
    catch (Form::GradeTooLowException e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;        
    }

    try
    {
        std::cout << "Creating form C68 with execute grade 0" << std::endl;
        Form f("C68", 150, 0);
        std::cout << std::endl;
    }
    catch (Form::GradeTooHighException e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;        
    }

    try
    {
        std::cout << "Creating form C69 with sign/execute grade 1" << std::endl;
        Form g("C69", 1, 1);
        std::cout << "Creating Paul with grade 2" << std::endl;
        Bureaucrat h("Paul", 2);
        g.beSigned(h); 
        std::cout << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;        
    }
}
