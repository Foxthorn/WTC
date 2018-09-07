/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13/15/44 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/07 13/15/44 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Functions::Functions() {}

Functions::Functions(Functions const & src) {
	*this = src;	
}

Functions::~Functions() {}

Functions & Functions::operator=(Functions const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

void	Functions::Initialise(int width, int height)
{

}


