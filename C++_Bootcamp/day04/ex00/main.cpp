/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 08:30:00 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 08:30:02 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Wisp.hpp"

int main()
{
    Sorcerer robert("Robert","the Magnificent");
    
    Victim jim("Jimmy");
    Peon joe("Joe");
    Wisp wisp("Elune");
    
    std::cout << robert << jim << joe << wisp;
    
    robert.polymorph(jim);
    robert.polymorph(joe);
    robert.polymorph(wisp);
    return 0;
}