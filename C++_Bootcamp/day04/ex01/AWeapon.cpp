/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:16:25 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 10:16:26 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include <iostream>

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name)
{
    this->_damage = damage;
    this->_ap = apcost;
}

AWeapon::AWeapon(AWeapon const & src) 
{
    *this = src;
}

AWeapon::~AWeapon() {}

std::string const & AWeapon::getName() const
{
    return this->_name;
}

int AWeapon::getAPCost() const
{
    return this->_ap;
}

int AWeapon::getDamage() const
{
    return this->_damage;
}

AWeapon &  AWeapon::operator=(AWeapon const & src)
{
    _name = src._name;
    _ap = src._ap;
    _damage = src._damage;
    return *this;
}
