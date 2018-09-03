/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:32:10 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 11:32:11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap() : _hit_points(100), _max_hit_points(100), _level(1)
{
    std::cout << "Created a CL4P-Tp unit" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hit_points(100), _max_hit_points(100), _level(1), _name(name)
{
    std::cout << "Gave CL4P-TP a name" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "We Done" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap()
{
    std::cout << "GOODBYE CRUEL WORLD!" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
    this->_hit_points = src._hit_points;
    this->_max_hit_points =src._max_hit_points;
    this->_energy = src._energy;
    this->_max_energy = src._max_energy;
    this->_level = src._level;
    this->_name = src._name;
    this->_melee_damage = src._melee_damage;
    this->_ranged_damage = src._ranged_damage;
    this->_armor_reduction = src._armor_reduction;

    return *this;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "FR4G-TP  takes " << amount- this->_armor_reduction << " damage" << std::endl;    
    this->_hit_points -= (amount - this->_armor_reduction);
    if (this->_hit_points <= 0)
        this->_hit_points = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "FR4G-TP  repairs for " << amount << " damage" << std::endl;
    this->_hit_points += amount;
    if (this->_hit_points > this->_max_hit_points)
        this->_hit_points = this->_max_hit_points;
}

std::string ClapTrap::getName()
{
    return this->_name;
}

void ClapTrap::setName(std::string name)
{
    this->_name = name;
}
