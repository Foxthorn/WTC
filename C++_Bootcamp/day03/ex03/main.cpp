/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:36:33 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 07:36:34 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

int main( void )
{
    std::cout << "Create two robots" << std::endl;
    std::cout << "<------------------ CLAPTRAP ------------------>" << std::endl;    
    std::cout << std::endl;        
    ClapTrap original( "CL4P-TP" );
    std::cout << std::endl;        
    std::cout << "<------------------ CLAPTRAP ------------------>" << std::endl;
    std::cout << std::endl;    
    std::cout << "<------------------ FRAGTRAP ------------------>" << std::endl;    
    std::cout << std::endl;        
    FragTrap one( "FR4G-TP" );
    FragTrap two( one );

    two.setName("LO4D3R");
    one.rangedAttack(two.getName());
    two.takeDamage(20);
    two.meleeAttack(one.getName());
    one.takeDamage(30);
    std::cout << std::endl;
    one.vault_hunter_dot_exe(two.getName());
    two.~FragTrap();
    std::cout << std::endl;        
    std::cout << "<------------------ FRAGTRAP ------------------>" << std::endl;    
    std::cout << std::endl;

    std::cout << "<------------------ SCAVTRAP ------------------>" << std::endl;
    std::cout << std::endl;        
    ScavTrap first( "W4LL-E" );
    first.challengeNewcomer(one.getName());
    std::cout << std::endl;        
    std::cout << "<------------------ SCAVTRAP ------------------>" << std::endl;    
    std::cout << std::endl;

    std::cout << "<------------------ NINJATRAP ------------------>" << std::endl;    
    std::cout << std::endl;        
    NinjaTrap *ninja = new NinjaTrap("Zer0");
    ninja->ninjaShoebox(original);
    ninja->ninjaShoebox(one);
    ninja->ninjaShoebox(first);
    delete ninja;
    std::cout << std::endl;        
    std::cout << "<------------------ NINJATRAP ------------------>" << std::endl;        
    std::cout << std::endl;

    return 0;
}