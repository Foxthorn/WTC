/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 07/13/05 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/04 07/13/05 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SNAKE_HPP
# define	SNAKE_HPP

#include "ScreenObject.hpp"
#include "eDirection.hpp"
#include <vector>

class Snake
{
	public:
		Snake();
		Snake(int x, int y, int direction);
		Snake(Snake const & src);
		~Snake();
		Snake & operator=(Snake const & src);

		std::vector<ScreenObject *>	getSnake();
		bool						MoveSnake(std::vector<std::vector<int>> & map);

	private:
		bool						ValidMove();
		std::vector<ScreenObject *> _snake;
};

#endif
