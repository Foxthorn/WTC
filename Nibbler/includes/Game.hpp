/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14/22/25 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/03 14/22/25 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GAME_HPP
# define	GAME_HPP

#include <vector>
#include <iostream>
#include "eGameObjects.hpp"
#include "ScreenObject.hpp"
#include "Snake.hpp"
#include "eDirection.hpp"
#include "IFunctions.hpp"
#include "Factory.hpp"

struct s_special_food {
	ScreenObject	food;
	bool			active;
	int				time_left;
};

class Game {
	public:
		Game();
		Game(Game const & src);
		Game(int width, int height, int library);
		~Game();
		Game & operator=(Game const & src);

		void	Loop();

	private:
		void							DisplayScore();
		void							PrintMap();
		int								PlaceFood();
		void							PlaceSpecialFood();
		void							CheckSpecialFood();
		void							PlaceSnake();
		bool							MoveSnake();
		int								CheckFood();
		void							ChangeSnakeDirection(int direction);
		bool							ValidFood(int x, int y);
		void							InitSpecialFood();
		void							UpdateMap();
		int								_width;
		int								_height;
		int								_columns;
		int								_rows;
		int								_start_library;
		int								_num_special_food;
		Snake							*_snake;
		ScreenObject					_food;
		s_special_food					_special_food;
		std::vector<std::vector<int>> 	_map;

};

struct s_point {
	size_t x;
	size_t y;
};

#endif
