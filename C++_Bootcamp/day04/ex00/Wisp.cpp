/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wisp.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:06:00 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 10:06:01 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wisp.hpp"
#include "Victim.hpp"
#include <iostream>

Wisp::Wisp(std::string name) : Victim(name)
{
    std::cout << "* Sparkly noises *" << std::endl;
}

Wisp::Wisp(Wisp const & src) : Victim(src)
{
    *this = src;
    std::cout << this->getName() << " makes sparkly noises" << std::endl;
}

Wisp::~Wisp()
{
    std::cout << this->getName() << " ceases to exist" << std::endl;
}

void Wisp::getPolymorphed() const
{
    std::cout << this->getName() << " is immune to your magic!" << std::endl;
}
