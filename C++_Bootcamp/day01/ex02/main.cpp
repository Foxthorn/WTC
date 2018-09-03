/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:43:04 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 09:43:05 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int main( void )
{
    Zombie      zombie1;
    ZombieEvent event;

    std::cout << std::endl;
    zombie1.announce();
    std::cout << "Created one zombie on the stack" << std::endl << std::endl;

    event.setZombieType("Walker");
    Zombie* newZombo1 = event.randomChump();
    std::cout << std::endl;    
    event.setZombieType("Runner");    
    Zombie* newZombo2 = event.randomChump();
    std::cout << std::endl;    
    std::cout << "Created two zombies on the heap" << std::endl;
    std::cout << "Time to clear the heap" << std::endl;
    delete newZombo1;
    delete newZombo2;

    std::cout << "Cleared the heap" << std::endl << std::endl;
    std::cout << "Stack is cleared when main ends" << std::endl;
    return 0;
}
