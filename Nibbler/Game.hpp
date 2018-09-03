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

class Game {
	public:
		Game();
		Game(Game const & src);
		Game(int width, int height);
		~Game();
		Game & operator=(Game const & src);

		void	InitMap();
		void	PlaceFood();
		void	PlaceSnake();

	private:
		int								_width;
		int								_height;
		ScreenObject					_food;
		std::vector<ScreenObject>		_snake;
		std::vector<std::vector<int>> 	_map;

};

#endif
