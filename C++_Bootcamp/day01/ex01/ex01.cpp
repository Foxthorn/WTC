/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:35:13 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 09:35:15 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void memoryLeak()
{
    std::string*    panthere = new std::string("String panthere");
    std::cout << *panthere << std::endl;
    delete panthere;
}

int main ( void )
{
    memoryLeak();
    return 0;
}
