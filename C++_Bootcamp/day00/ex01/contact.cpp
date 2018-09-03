/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 06:50:23 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 06:50:24 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <string>
#include <iomanip>

Contact::Contact() : created(0) {}

Contact::~Contact() {}

int Contact::CreateContact( void )
{
    if (created == 1)
        return 0;
    created = 1;
    std::cout << "Enter firstname: ";
    std::getline (std::cin, firstname);
    std::cout << "Enter lastname: ";
    std::getline (std::cin, lastname);
    std::cout << "Enter nickname: ";
    std::getline (std::cin, nickname);
    std::cout << "Enter login: ";
    std::getline (std::cin, login);
    std::cout << "Enter postal address: ";
    std::getline (std::cin, postal);
    std::cout << "Enter email address: ";
    std::getline (std::cin, email);
    std::cout << "Enter phone number: ";
    std::getline (std::cin, phone);
    std::cout << "Enter birthday date: ";
    std::getline (std::cin, birthday);
    std::cout << "Enter favorite meal: ";
    std::getline (std::cin, meal);
    std::cout << "Enter underwear color: ";
    std::getline (std::cin, underwear);
    std::cout << "Enter darkest secret: ";
    std::getline (std::cin, secret);
    return 1;
}

void Contact::SearchDisplay( int number )
{
    if (created == 0)
    {
        std::cout << std::setfill(' ') << std::setw(11);
        std::cout << "|";
        std::cout << std::setfill(' ') << std::setw(11);
        std::cout << "|";
        std::cout << std::setfill(' ') << std::setw(11);
        std::cout << "|";
        std::cout << std::setfill(' ') << std::setw(11);
        std::cout << "|";          
        std::cout << std::endl;        
    }
    else
    {
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << number << "|";
        Shorten(firstname);
        std::cout << "|";
        Shorten(lastname);
        std::cout << "|";
        Shorten(nickname);
        std::cout << "|";
        std::cout << std::endl;
    }
}

void Contact::Shorten(std::string str)
{
    char buffer[11];
    
    std::cout << std::setfill(' ') << std::setw(10);
    if (str.size() > 10)
    {
        str.copy(buffer, 9, 0);
        buffer[9] = '.';
        buffer[10] = '\0';
        std::cout << buffer;
    }
    else
        std::cout << str;
}

void Contact::DisplayInfo( void )
{
    std::cout << "Firstname: ";
    std::cout << firstname << std::endl;
    std::cout << "Lastname: ";
    std::cout << lastname << std::endl;
    std::cout << "Nickname: ";
    std::cout << nickname << std::endl;
    std::cout << "Login: ";
    std::cout << login << std::endl;
    std::cout << "Postal Address: ";
    std::cout << postal << std::endl;
    std::cout << "Email Address: ";
    std::cout << email << std::endl;
    std::cout << "Phone Number: ";
    std::cout << phone << std::endl;
    std::cout << "Birthday: ";
    std::cout << birthday << std::endl;
    std::cout << "Underwear: ";
    std::cout << underwear << std::endl;
    std::cout << "Favorite Meal: ";
    std::cout << meal << std::endl;
    std::cout << "Darkest Secret: ";
    std::cout << secret << std::endl;
}