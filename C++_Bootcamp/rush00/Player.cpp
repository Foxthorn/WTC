/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:02:43 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/09 14:02:44 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(int x, int y) : ScreenObject("/|-|\\", 3, 2)
{
    ScreenObject::setStart(x, y);
    _active = true;
    _x = x;
    _y = y;
    _symbol = "/|-|\\";
}

Player::~Player() {}

WINDOW *Player::create_player(int num)
{
    this->_x += num;
    ScreenObject::setStart(this->_x, this->_y);
    return ScreenObject::create_spaceship(this->_x, this->_y);
}

int Player::X()
{
    return this->_x;
}

int Player::Y()
{
    return this->_y;
}

bool Player::active()
{
    return this->_active;
}