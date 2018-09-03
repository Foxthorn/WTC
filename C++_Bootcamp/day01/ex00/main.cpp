/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:05:22 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 09:05:23 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>
#include <string>

void ponyOnTheStack()
{
    Pony stack;

    std::cout << "Its on the stack" << std::endl;
}

void ponyOnTheHeap()
{
    Pony* heap = new Pony();

    std::cout << "Its on the heap" << std::endl;
    std::cout << std::endl;
    std::cout << "Kill it with force" << std::endl;
    delete heap;
}

int main( void )
{
    std::cout << std::endl;
    ponyOnTheStack();
    std::cout << std::endl;
    ponyOnTheHeap();
    return 0;
}
