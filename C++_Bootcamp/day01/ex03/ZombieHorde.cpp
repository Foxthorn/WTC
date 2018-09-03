/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:42:48 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 10:42:49 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <iostream>

ZombieHorde::ZombieHorde(int n)
{
    horde = new Zombie[n];
    std::string names[5] = {"Bro", "Guy", "Friend", "Mate", "Dude"};
    number = n;
    for (int i = 0; i < n; i++)
    {
        int index = rand() % 5;
        horde[i].name = names[index]; 
    }
}

ZombieHorde::~ZombieHorde()
{
    for (int i = 0; i < number; i++)
    {
        horde[i].~Zombie();
    }
}

void ZombieHorde::announce()
{
    for (int i = 0; i < number; i++)
    {
        horde[i].announce();
    }
}

