/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:16:40 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 10:16:41 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon(src)
{
    *this = src;
}

PlasmaRifle::~PlasmaRifle() {};

void    PlasmaRifle::attack() const
{
    std::cout <<  "* piouuu piouuu piouuu *" << std::endl;
}