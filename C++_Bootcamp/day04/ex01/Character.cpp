/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:18:20 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 10:18:21 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <iostream>

Character::Character(std::string const & name) : _name(name) , _ap(40), _weapon(NULL)
{
}

Character::Character() : _name("") , _ap(40), _weapon(NULL) {}

Character::Character(Character const & src) : _name(src._name), _ap(src._ap), _weapon(src._weapon)
{
}

Character::~Character() {}

void Character::recoverAP()
{
    this->_ap += 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

void Character::equip(AWeapon* weapon)
{
    _weapon = weapon;  
}

void Character::attack(Enemy* enemy)
{
    if (_ap >= _weapon->getAPCost())
    {
        _ap -= _weapon->getAPCost();
        enemy->takeDamage(_weapon->getDamage());
        std::cout << _name <<" attacks "<< enemy->getType() <<" with a "<< _weapon->getName() << std::endl;
        _weapon->attack();
        if (enemy->getHP() == 0)
            delete enemy;
    }
}

Character &  Character::operator=(Character const & src)
{
    this->_ap = src._ap;
    this->_weapon = src._weapon;
    return *this;
}

std::ostream & operator<<( std::ostream & o, Character const & rhs)
{
    if (rhs.getWeapon())
        o << rhs.getName() << " has " << rhs.getAP() << " and wields " << rhs.getWeapon()->getName() << std::endl;
    else
        o << rhs.getName() << " has " << rhs.getAP() << " and is unarmed"<< std::endl;  
    return o;
}

AWeapon* Character::getWeapon() const
{
    return _weapon;
}

int Character::getAP() const
{
    return this->_ap;
}

std::string const & Character::getName() const
{
    return this->_name;
}

