/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:32:19 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/09 09:32:20 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Missle.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include <unistd.h>

int main(void)
{	
    WINDOW *player_w;
    WINDOW *enemy_w[3];
    WINDOW *missle;
	int startx, starty, y, x;
	int ch;

	initscr();
    noecho();
	cbreak();			
    curs_set(0);
	keypad(stdscr, TRUE);		
    nodelay(stdscr, TRUE);

	starty = (LINES - 2);	
	startx = (COLS - 3) / 2;
    y = 0;
    x = (COLS - 3) / 2;
	refresh();
    Player player(startx, starty);
    Enemy *enemies = new Enemy[3];
    int j = (COLS - 3) / 2 - 5;
    for (int i = 0; i < 3; i++)
    {
        enemies[i].setStart(j, 0);
        j += 10;
    }
    
	player_w = player.create_player(0);
    Missle m(startx + 2, starty, -1);

	while(1)
	{	
        usleep(100000);
        clear();
        for (int i = 0; i < 3; i++)
        {
            if (enemies[i].active())
            {
                enemy_w[i] = enemies[i].create_enemy();
            }
            else
                delwin(enemy_w[i]);
        }
        if (player.active())
            player_w = player.create_player(0);
        if (m.active())
            missle = m.create_missle(); 
        if ((ch = getch()) == 27)
            break;           
        switch(ch)
        {
            case KEY_RIGHT:
                delwin(player_w);
                player_w = player.create_player(1);                
                break;
            case KEY_LEFT:
                delwin(player_w);          
                player_w = player.create_player(-1);                
                break;
            case 32:
                if (!m.active())
                {
                    m.setActive(true);
                    m.setStart(player.X(), player.Y());
                }
                else if (m.getY() <= 0)
                {
                    m.setActive(false);
                }
                break;
        }   
	}
    for (int i = 0; i < 3; i++)
    {
        enemies[i].~Enemy();
    }
    delwin(enemy_w[1]);
	endwin();
	return 0;
}
