/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:17:22 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 10:17:23 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(int hp, std::string const & type) : _type(type)
{
    this->_hp = hp;
}

Enemy::Enemy(Enemy const & src)
{
    *this = src;
}

Enemy::~Enemy() {};

std::string const & Enemy::getType() const
{
    return this->_type;
}

int Enemy::getHP() const
{
    return this->_hp;
}

Enemy &  Enemy::operator=(Enemy const & src)
{
    this->_hp = src._hp;
    return *this;
}

void Enemy::takeDamage(int damage)
{
    if (damage > 0)
    {
        this->_hp = this->_hp - damage;
        if (this->getHP() < 0)
            this->_hp = 0;
    }
} 
