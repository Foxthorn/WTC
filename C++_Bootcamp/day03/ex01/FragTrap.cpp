/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:37:17 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 07:37:18 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() : _hit_points(100), _max_hit_points(100), _energy_points(100),
                    _max_energy_points(100), _level(1), _melee_damage(30),
                    _ranged_damage(20), _armor_reduction(5) 
{
    std::cout << "Start bootup sequence" << std::endl;
}

FragTrap::FragTrap(std::string name) : _hit_points(100), _max_hit_points(100),
                                 _energy_points(100), _max_energy_points(100), _level(1),
                                 _name(name), _melee_damage(30), _ranged_damage(20), _armor_reduction(5) 
{
    std::cout << "Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
    std::cout << "Booting sequence complete" << std::endl;
    *this = src;
}

FragTrap::~FragTrap()
{
    std::cout << "I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
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

void FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " from point blank range, causing " << this->_melee_damage << " points of damage!" << std::endl;
}

void FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " from range, causing " << this->_ranged_damage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    std::cout << "FR4G-TP  takes " << amount- this->_armor_reduction << " damage" << std::endl;    
    this->_hit_points -= (amount - this->_armor_reduction);
    if (this->_hit_points <= 0)
        this->_hit_points = 0;
}

void FragTrap::beRepaired(unsigned int amount)
{
    std::cout << "FR4G-TP  repairs for " << amount << " damage" << std::endl;
    this->_hit_points += amount;
    if (this->_hit_points > this->_max_hit_points)
        this->_hit_points = this->_max_hit_points;
}

void FragTrap::vault_hunter_dot_exe(std::string const & target)
{
    std::string attacks[] = {"Laser Inferno", "Hadouken", "High Five", "Drone Strike", "Dragon Fist"};

    if (this->_energy_points >= 25)
    {
        srand(time(NULL));
        int i = rand() % 5;
        std::cout << "FR4G-TP" << this->_name << " uses the almighty " << attacks[i] << " attack on " << target << std::endl;
        this->_energy_points -= 25;
    }
    else
    {
        std::cout << "I dont have enough energy" << std::endl;
    }
}

std::string FragTrap::getName()
{
    return this->_name;
}

void FragTrap::setName(std::string name)
{
    this->_name = name;
}