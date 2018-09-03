/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:37:53 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/09 11:37:54 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missle.hpp"
#include "ScreenObject.hpp"
#include <ncurses.h>

Missle::Missle() : ScreenObject("|", 1, 1)
{
    _symbol = "|";
    _active = false;
}

Missle::Missle(int x, int y, int direction) : ScreenObject("|", 1, 1)
{
    _direction = direction;
    _x = x;
    _y = y;
    _active = false;
}

Missle::~Missle() {}


WINDOW *Missle::create_missle()
{	
    this->_y += this->_direction;
    ScreenObject::setStart(this->_x, this->_y);
	return ScreenObject::create_spaceship(this->_x, this->_y);
}

int Missle::getX() const
{
    return this->_x;
}

int Missle::getY() const
{
    return this->_y;
}

bool Missle::active()
{
    return this->_active;
}

void Missle::setStart(int startx, int starty)
{
    this->_x = startx;
    this->_y = starty;
}

void Missle::setActive(bool active)
{
    this->_active = active;
}
