/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:40:22 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 10:40:24 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>


int main( void )
{
    ZombieHorde gen(9);

    gen.announce();
    return 0;
}
