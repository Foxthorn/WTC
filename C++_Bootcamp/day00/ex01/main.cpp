/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 06:40:30 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 06:40:34 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "contact.hpp"
#include <string>

int createContact(Contact *items)
{
    if (items[7].created == 1)
    {
        std::cout << "Phonebook is already full" << std::endl;
        return 1;
    }
    for (int i = 0; items[i].CreateContact() == 0; i++);
    return 0;
}

int search(Contact *items)
{
    std::string number;
    int         index;
    bool        correctInput;

    correctInput = false;
    std::cout << "Index     |FirstName | Last Name| Nickname |" << std::endl;
    for (int i = 0; i < 8; i++)
        items[i].SearchDisplay(i);
    
    while (!correctInput)
    {
        std::cout << "Enter an index: " << std::endl;
        std::getline (std::cin, number);
        if (number.size() == 1 && number[0] >= 48 && number[0] <= 57)
        {
            index = number[0] - 48;
            correctInput = true;
            items[index].DisplayInfo();
        }
        else
        {
            std::cout << "Invalid index" << std::endl;
        }
    }
    return 0;
}

int main() 
{
    Contact         items[8];
    std::string     line;

    while (line != "EXIT")
    {
        std::cout << "Enter a Command:" << std::endl;
        std::getline (std::cin, line);
        if (line == "ADD")
            createContact(items);
        if (line == "SEARCH")
            search(items);
        else
        {
            std::cout << "Invalid Command" << std::endl;
            std::cout << "Please use 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
            std::cout << std::endl;
        }
    }
    return 0;
}
