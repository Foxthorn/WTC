/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gets.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/07/40 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/07/40 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gets.hpp"

Gets::Gets() {}

Gets::Gets(Gets const & src) {
	*this = src;	
}

Gets::~Gets() {}

Gets & Gets::operator=(Gets const & src) {}

void	execute(Brainfuck * b)
{
	std::cin >> b->*res;
}