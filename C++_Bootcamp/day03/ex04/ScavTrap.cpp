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
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap() : ClapTrap()
{
    _energy = 50;
    _max_energy = 50;
    _melee_damage = 20;
    _ranged_damage = 15;
    _armor_reduction = 3;
    std::cout << "I LIIIIVE !!!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _energy = 50;
    _max_energy = 50;
    _melee_damage = 20;
    _ranged_damage = 15;
    _armor_reduction = 3;
    setName(name);
    std::cout << "Wait a minute -- i'm not dead!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
    std::cout << "PROTECT ME SQUIRE" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap()
{
    std::cout << "STAIRS NOOOOOOOOO!" << std::endl;
}

void ScavTrap::challengeNewcomer(std::string const & target)
{
    std::string attacks[] = {"Defeat Ug-Thak, Lord of Skags", "Dance, dance, baby", "Give me a High Five", "Collect 139377 brown rocks", "Defeat the Destroyer of Worlds"};

    if (this->_energy >= 25)
    {
        srand(time(NULL));
        int i = rand() % 5;
        std::cout << "FR4G-TP " << target << " your mighty challenge is..... " << attacks[i] << std::endl;
        this->_energy -= 25;
    }
    else
    {
        std::cout << "I dont have enough energy" << std::endl;
    }
}

void ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " from point blank range, causing " << this->_melee_damage << " points of damage!" << std::endl;
}

void ScavTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " from range, causing " << this->_ranged_damage << " points of damage!" << std::endl;
}