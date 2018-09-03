/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScreenObject.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:31:29 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/09 16:31:30 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREENOBJECT_HPP
# define SCREENOBJECT_HPP

#include <iostream>
#include <ncurses.h>

class ScreenObject
{
    public:
        ScreenObject(std::string symbol, int width, int _height);
        ~ScreenObject();

        int Y() const;
        int X() const;
        void setY(int x);
        void setX(int y);
        void setStart(int x, int y);
        bool active();
        WINDOW *create_spaceship(int startx, int starty);

    private:
        int _x;
        int _max_x;
        int _y;
        int _height;
        int _width;
        bool _active;
        std::string _symbol;
};

#endif
