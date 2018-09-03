/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:53:29 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/09 14:53:30 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "ScreenObject.hpp"
#include <iostream>
#include <ncurses.h>

class Enemy : public ScreenObject
{
    public:
        Enemy();
        Enemy(int x, int y);
        ~Enemy();

        int Y();
        int X();
        bool active();
        void setActive();
        void setStart(int startx, int starty);
        WINDOW *create_enemy();

    private:
        int _direction;
        bool _active;
        int _x;
        int _y;
        std::string _symbol;
};

#endif
