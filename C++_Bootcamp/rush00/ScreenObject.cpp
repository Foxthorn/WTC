/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScreenObject.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:31:21 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/09 16:31:22 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScreenObject.hpp"

ScreenObject::ScreenObject(std::string symbol, int width, int height) 
{
    _width = width;
    _height = height;
    _active = true;
    _symbol = symbol;
}

ScreenObject::~ScreenObject() {}

WINDOW *ScreenObject::create_spaceship(int startx, int starty)
{
    WINDOW *local_win;
    const char* str = this->_symbol.c_str();
	local_win = newwin(this->_height, this->_width, startx, starty);
    mvaddstr(starty, startx, str);
	wrefresh(local_win);
    
	return local_win;
}

bool ScreenObject::active()
{
    return this->_active;
}

int ScreenObject::X() const
{
    return this->_x;
}

int ScreenObject::Y() const
{
    return this->_y;
}

void ScreenObject::setStart(int x, int y)
{
    this->_x = x;
    this->_y = y;
    this->_max_x = x + this->_width;
}

void ScreenObject::setX(int x)
{
    this->_x = x;
}

void ScreenObject::setY(int y)
{
    this->_y = y;
}