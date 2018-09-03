/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pdecr.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/07/06 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/07/06 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pdecr.hpp"

Pdecr::Pdecr() {}

Pdecr::Pdecr(Pdecr const & src) {
	*this = src;	
}

Pdecr::~Pdecr() {}

Pdecr & Pdecr::operator=(Pdecr const & src) {}

void	execute(Brainfuck * b)
{
	b->res--;
}