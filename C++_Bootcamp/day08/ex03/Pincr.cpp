/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pincr.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/07/01 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/07/01 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pincr.hpp"

Pincr::Pincr() {}

Pincr::Pincr(Pincr const & src) {
	*this = src;	
}

Pincr::~Pincr() {}

Pincr & Pincr::operator=(Pincr const & src) {}

void	execute(Brainfuck * b)
{
	b->res++;
}