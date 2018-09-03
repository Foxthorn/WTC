/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:42:51 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 09:42:53 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <string>

ZombieEvent::ZombieEvent() {}
ZombieEvent::~ZombieEvent() {}

void ZombieEvent::setZombieType(std::string type)
{
    zombieType = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
    Zombie* zombo = new Zombie();
    zombo->name = name;
    zombo->type = zombieType;
    return zombo;
}

Zombie* ZombieEvent::randomChump( void )
{
    std::string names[5] = {"Bro", "Guy", "Friend", "Mate", "Dude"};
    int index = rand() % 5;

    Zombie* randomZombo;
    randomZombo = newZombie(names[index]);
    randomZombo->announce();
    return randomZombo;
}
