/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bdecr.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/07/27 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/07/27 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bdecr.hpp"

Bdecr::Bdecr() {}

Bdecr::Bdecr(Bdecr const & src) {
	*this = src;	
}

Bdecr::~Bdecr() {}

Bdecr & Bdecr::operator=(Bdecr const & src) {}

void	execute(Brainfuck * b)
{
	b->(*res)--;
}