/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:17:06 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 10:17:07 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(PowerFist const & src) : AWeapon(src)
{
    *this = src;
}

PowerFist::~PowerFist() {};

void    PowerFist::attack() const
{
    std::cout <<  "* pschhh... SBAM! *" << std::endl;
}