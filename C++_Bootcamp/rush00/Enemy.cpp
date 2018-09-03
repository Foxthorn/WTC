/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:53:34 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/09 14:53:35 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "ScreenObject.hpp"

Enemy::Enemy() : ScreenObject("(\\!/)", 5,2)
{
    _active = true;
    _direction = -1;
    _symbol = "(\\!/)";    
}

Enemy::Enemy(int x, int y) : ScreenObject("(\\!/)", 5,2)
{
    _direction = -1;
    _active = true;
    _x = x;
    _y = y;
    _symbol = "(\\!/)";
}

Enemy::~Enemy() {}

WINDOW *Enemy::create_enemy()
{
    this->_x += this->_direction;
    if (this->_x <= 10)
    {
        this->_direction = 1;
        this->_y += 1;
    }
    if (this->_x >= COLS - 10)
    {
        this->_direction = -1;    
        this->_y += 1;
    }
    if (this->_y >= LINES)
        this->_active = false;
	return ScreenObject::create_spaceship(this->_x, this->_y);
}

int Enemy::X()
{
    return this->_x;
}

int Enemy::Y()
{
    return this->_y;
}

bool Enemy::active()
{
    return this->_active;
}

void Enemy::setStart(int startx, int starty)
{
    this->_x = startx;
    this->_y = starty;
}
