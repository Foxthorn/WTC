/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 08:29:24 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 08:29:24 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include <iostream>

Victim::Victim(std::string name)
{
    setName(name);
    std::cout << "Some random victim called "<< name <<" just popped !" << std::endl;
}

Victim::Victim(Victim const & src)
{
    *this = src;
    std::cout << "Some random victim called "<< this->getName() <<" just popped !" << std::endl;    
}

Victim::~Victim()
{
    std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
}

void    Victim::getPolymorphed() const
{
    std::cout << this->getName() <<" has been turned into a cute little sheep !" << std::endl;
}

void    Victim::setName(std::string name)
{
    this->_name = name;
}

std::string Victim::getName() const
{
    return this->_name;
}

std::ostream & operator<<( std::ostream & o, Victim const & rhs)
{
    o << "I'm "<< rhs.getName() << " and I like otters !" << std::endl;
    return o;
}