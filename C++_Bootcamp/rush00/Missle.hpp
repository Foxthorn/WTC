/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:37:57 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/09 11:37:57 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSLE_HPP
# define MISSLE_HPP

#include <ncurses.h>
#include "ScreenObject.hpp"
#include <iostream>

class Missle : public ScreenObject
{
    public:
        Missle();
        Missle(int x, int y, int direction);        
        ~Missle();

        int getX() const;
        int getY() const;
        bool active();
        void setActive(bool active);
        void setStart(int startx, int starty);
        WINDOW *create_missle();
        bool collide(ScreenObject const & src);


    private:
        int _direction;
        bool _active;
        int _x;
        int _y;
        std::string _symbol;
};

#endif
