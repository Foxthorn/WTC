/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:49:33 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 12:49:35 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap() : ClapTrap()
{
    _hit_points = 60;
    _max_hit_points = 60;
    _energy = 120;
    _max_energy = 120;
    _melee_damage = 60;
    _ranged_damage = 5;
    _armor_reduction = 0;
    std::cout << "Your eyes deceive you" << std::endl << "An illusion fools you all" << std::endl << "I move for the kill." << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
    _hit_points = 60;
    _max_hit_points = 60;
    _energy = 120;
    _max_energy = 120;
    _melee_damage = 60;
    _ranged_damage = 5;
    _armor_reduction = 0;
    setName(name);
    std::cout << this->getName() << " enters stealth, slowly stalking his prey" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src)
{
    std::cout << "The true world revealed" << std::endl << "Weaknesses now known to me" << std::endl << "Time to go to work. " << std::endl;
    *this = src;
}

NinjaTrap::~NinjaTrap()
{
    std::cout << "Good bye!" << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap const & target)
{
    std::cout << std::endl;
    std::cout << "How hilarious" << std::endl << target.getName() << " just set off my trap card" << std::endl << "Your death approaches. " << std::endl;
    std::cout << std::endl;    
}

void NinjaTrap::ninjaShoebox(ScavTrap const & target)
{
    std::cout << std::endl;   
    std::cout << "And I disappear" << std::endl << "A ghost amidst the combat" << std::endl << "Preparing to strike " << target.getName() << std::endl;
    std::cout << std::endl;    
}

void NinjaTrap::ninjaShoebox(FragTrap const & target)
{
    std::cout << std::endl;    
    std::cout <<  target.getName() << " should now be scared" << std::endl << "I don't die so easily" << std::endl << "And now I am pissed." << std::endl;
    std::cout << std::endl;    
}

void NinjaTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " swipes with his blade and hits " << target << " for " << this->_melee_damage << " points of damage!" << std::endl;
}

void NinjaTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->_name << " specialty isn't ranged and hits " << target << " for " << this->_ranged_damage << " points of damage!" << std::endl;
}
