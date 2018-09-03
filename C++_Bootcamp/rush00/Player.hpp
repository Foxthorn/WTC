/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:02:50 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/09 14:02:51 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <iostream>
#include "ScreenObject.hpp"
#include <ncurses.h>

class Player : public ScreenObject
{
    public:
        Player(int x, int y);
        ~Player();

        int Y();
        int X();
        bool active();
        WINDOW *create_player(int num);

    private:
        bool _active;
        int _x;
        int _y;
        std::string _symbol;
};

#endif
