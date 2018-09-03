/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:12:30 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 11:12:31 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap() : _hit_points(100), _max_hit_points(100), _energy_points(50),
                    _max_energy_points(50), _level(1), _melee_damage(20),
                    _ranged_damage(15), _armor_reduction(3) 
{
    std::cout << "I LIIIIVE !!!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _hit_points(100), _max_hit_points(100),
                                 _energy_points(50), _max_energy_points(50), _level(1),
                                 _name(name), _melee_damage(20), _ranged_damage(15), _armor_reduction(3) 
{
    std::cout << "Wait a minute -- i'm not dead!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
    std::cout << "PROTECT ME SQUIRE" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap()
{
    std::cout << "STAIRS NOOOOOOOOO!" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
    this->_hit_points = src._hit_points;
    this->_max_hit_points =src._max_hit_points;
    this->_energy_points = src._energy_points;
    this->_max_energy_points = src._max_energy_points;
    this->_level = src._level;
    this->_name = src._name;
    this->_melee_damage = src._melee_damage;
    this->_ranged_damage = src._ranged_damage;
    this->_armor_reduction = src._armor_reduction;

    return *this;
}

void ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " from point blank range, causing " << this->_melee_damage << " points of damage!" << std::endl;
}

void ScavTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " from range, causing " << this->_ranged_damage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    std::cout << "FR4G-TP " << this->_name << " takes " << amount- this->_armor_reduction << " damage" << std::endl;    
    this->_hit_points -= (amount - this->_armor_reduction);
    if (this->_hit_points <= 0)
        this->_hit_points = 0;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    std::cout << "FR4G-TP " << this->_name << " repairs for " << amount << " damage" << std::endl;
    this->_hit_points += amount;
    if (this->_hit_points > this->_max_hit_points)
        this->_hit_points = this->_max_hit_points;
}

void ScavTrap::challengeNewcomer(std::string const & target)
{
    std::string attacks[] = {"Defeat Ug-Thak, Lord of Skags", "Dance, dance, baby", "Give me a High Five", "Collect 139377 brown rocks", "Defeat the Destroyer of Worlds"};

    if (this->_energy_points >= 25)
    {
        srand(time(NULL));
        int i = rand() % 5;
        std::cout << "FR4G-TP " << target << " your mighty challenge is..... " << attacks[i] << std::endl;
        this->_energy_points -= 25;
    }
    else
    {
        std::cout << "I dont have enough energy" << std::endl;
    }
}

std::string ScavTrap::getName()
{
    return this->_name;
}

void ScavTrap::setName(std::string name)
{
    this->_name = name;
}
