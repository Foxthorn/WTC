/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brclose.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/07/50 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/07/50 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brclose.hpp"

Brclose::Brclose() {}

Brclose::Brclose(Brclose const & src) {
	*this = src;	
}

Brclose::~Brclose() {}

Brclose & Brclose::operator=(Brclose const & src) {}

void	execute(Brainfuck * b)
{
	int bal = 0;
	do {
		if (b->*p == '[') 
			bal++;
		else if (b->*p == ']')
			bal--;
		b->p--;
	} while (b != 0)
}