/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Puts.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/07/35 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/07/35 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Puts.hpp"

Puts::Puts() {}

Puts::Puts(Puts const & src) {
	*this = src;	
}

Puts::~Puts() {}

Puts & Puts::operator=(Puts const & src) {}

void	execute(Brainfuck * b)
{
	std::cout << *res;
}