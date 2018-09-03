/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brainfuck.cpp                                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/01/54 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/01/54 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brainfuck.hpp"

Brainfuck::Brainfuck(const char code[]) 
{
	p = prog;
}

Brainfuck::Brainfuck(Brainfuck const & src) {
	*this = src;	
}

Brainfuck::~Brainfuck() {}

Brainfuck & Brainfuck::operator=(Brainfuck const & src) {}

