/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bincr.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/07/19 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/07/19 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bincr.hpp"

Bincr::Bincr() {}

Bincr::Bincr(Bincr const & src) {
	*this = src;	
}

Bincr::~Bincr() {}

Bincr & Bincr::operator=(Bincr const & src) {}

void	execute(Brainfuck * b)
{
	b->(*res)++;
}