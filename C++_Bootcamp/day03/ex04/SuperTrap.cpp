/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:49:33 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 12:49:35 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap() : FragTrap(), NinjaTrap()
{
    _hit_points = FragTrap::_hit_points;
    _max_hit_points = FragTrap::_max_hit_points;
    _energy = NinjaTrap::_energy;
    _max_energy = NinjaTrap::_max_energy;
    _melee_damage = NinjaTrap::_melee_damage;
    _ranged_damage = FragTrap::_ranged_damage;
    _armor_reduction = FragTrap::_armor_reduction;
    std::cout << "SuperTrap online" << std::endl;
}

SuperTrap::SuperTrap(std::string name) : FragTrap(name), NinjaTrap(name)
{
    _hit_points = FragTrap::_hit_points;
    _max_hit_points = FragTrap::_max_hit_points;
    _energy = NinjaTrap::_energy;
    _max_energy = NinjaTrap::_max_energy;
    _melee_damage = NinjaTrap::_melee_damage;
    _ranged_damage = FragTrap::_ranged_damage;
    _armor_reduction = FragTrap::_armor_reduction;
    setName(name);
    std::cout << name << " reporting for duty" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & src) : FragTrap(src), NinjaTrap(src)
{
    std::cout << "Lets burn" << std::endl;
    *this = src;
}

SuperTrap::~SuperTrap()
{
    std::cout << "I leave this world behind" << std::endl;
}

void SuperTrap::meleeAttack(std::string const & target)
{
    NinjaTrap::meleeAttack(target);
}

void SuperTrap::rangedAttack(std::string const & target)
{
    FragTrap::rangedAttack(target);
}