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

FragTrap::FragTrap() : ClapTrap()
{
    _energy = 100;
    _max_energy = 100;
    _melee_damage = 30;
    _ranged_damage = 20;
    _armor_reduction = 5;
    std::cout << "Start bootup sequence" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    _energy = 100;
    _max_energy = 100;
    _melee_damage = 30;
    _ranged_damage = 20;
    _armor_reduction = 5;
    setName(name);
    std::cout << "Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
    std::cout << "Booting sequence complete" << std::endl;
    *this = src;
}

FragTrap::~FragTrap()
{
    std::cout << "I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

void FragTrap::vault_hunter_dot_exe(std::string const & target)
{
    std::string attacks[] = {"Laser Inferno", "Hadouken", "High Five", "Drone Strike", "Dragon Fist"};

    if (this->_energy >= 25)
    {
        srand(time(NULL));
        int i = rand() % 5;
        std::cout << "FR4G-TP " << this->_name << " uses the almighty " << attacks[i] << " attack on " << target << std::endl;
        this->_energy -= 25;
    }
    else
    {
        std::cout << "I dont have enough energy" << std::endl;
    }
}

void FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " tries to attacks " << target << " from point blank range, causing " << this->_melee_damage << " points of damage!" << std::endl;
}

void FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " tries to attacks " << target << " from range, causing " << this->_ranged_damage << " points of damage!" << std::endl;
}