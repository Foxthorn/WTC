/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:11:24 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 13:11:25 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& ref) : name(name), weapon(ref)
{
}
HumanA::~HumanA() {}

void HumanA::attack()
{
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}
