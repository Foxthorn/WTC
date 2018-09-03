/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScreenObject.cpp                                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13/43/58 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/03 13/43/58 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScreenObject.hpp"

ScreenObject::ScreenObject() {}

ScreenObject::ScreenObject(ScreenObject const & src) {
	*this = src;	
}

ScreenObject::~ScreenObject() {}

ScreenObject & ScreenObject::operator=(ScreenObject const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

void	ScreenObject::SetX(int x) {
	this->_x = x;
}

void	ScreenObject::SetY(int y) {
	this->_y = y;
}

void	ScreenObject::SetType(int type) {
	this->_type = type;
}
