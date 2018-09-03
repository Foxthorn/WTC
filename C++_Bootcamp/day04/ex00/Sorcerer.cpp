/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 08:29:09 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 08:29:10 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include <iostream>

Sorcerer::Sorcerer(std::string name, std::string title)
{
    setName(name);
    setTitle(title);
    std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
    *this = src;
    std::cout << this->getName() << ", " << this->getTitle() << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer() 
{
    std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
}

void    Sorcerer::polymorph(Victim const & src) const
{
    src.getPolymorphed();
}

void    Sorcerer::setName(std::string name)
{
    this->_name = name;
}

void    Sorcerer::setTitle(std::string title)
{
    this->_title = title;
}

std::string Sorcerer::getName() const
{
    return this->_name;
}

std::string Sorcerer::getTitle() const
{
    return this->_title;
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs)
{
    o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
    return o;
}