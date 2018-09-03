/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bropen.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/07/47 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/07/47 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bropen.hpp"

Bropen::Bropen() {}

Bropen::Bropen(Bropen const & src) {
	*this = src;	
}

Bropen::~Bropen() {}

Bropen & Bropen::operator=(Bropen const & src) {}

void	execute(Brainfuck * b)
{
	int bal = 1;
	if (b->*res == '\0')
	{
		do {
			b->p++;
			if (*p == '[')
				bal++;
			else if (*p == ']')
				bal--;
		} while (bal != 0)
	}
}