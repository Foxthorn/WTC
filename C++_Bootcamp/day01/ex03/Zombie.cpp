/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:42:31 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 09:42:32 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie()
{
    std::cout << "Created a Zombie" << std::endl;
}

Zombie::~Zombie() 
{
    std::cout << "Killed a zombie " << std::endl;
}

void Zombie::announce()
{
    std::cout << "< " << name << " (" << type << ") >"
     << " ugggggh Braiiiinss....." << std::endl;
}
