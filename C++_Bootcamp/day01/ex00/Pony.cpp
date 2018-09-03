/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:05:08 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 09:05:11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>
#include <string>

Pony::Pony()
{
    std::cout << "Created a Pony" << std::endl;
}

Pony::~Pony()
{
    std::cout << "Killed Pony " << std::endl;
}
