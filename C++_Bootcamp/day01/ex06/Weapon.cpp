/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:06:57 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 13:06:58 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type)
{
    this->type = type;
}
Weapon::~Weapon() {}

std::string const&  Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}
