/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 07/13/05 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/04 07/13/05 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::Snake() {}

Snake::Snake(int x, int y, int direction)
{
	_snake.push_back(new ScreenObject(x, y, SNAKE_HEAD, direction));
	for(size_t i = 1; i <= 4; i++)
	{
		_snake.push_back(new ScreenObject(x - i, y, SNAKE_BODY, direction));
	}
}

Snake::Snake(Snake const & src) {
	*this = src;	
}

Snake::~Snake() 
{
	_snake.clear();
}

Snake & Snake::operator=(Snake const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

std::vector<ScreenObject *>	Snake::getSnake()
{
	return this->_snake;
}

bool	Snake::MoveSnake(std::vector<std::vector<int>> & map)
{
	int adjustment;
	for(size_t i = 0; i < this->_snake.size(); i++)
	{
		int x = this->_snake[i]->GetX();
		int y = this->_snake[i]->GetY();
		switch(this->_snake[i]->GetDirection())
		{
			case UP:
				this->_snake[i]->SetX(x - 1);
				break;
			case DOWN:
				this->_snake[i]->SetX(x + 1);
				break;
			case RIGHT:
				this->_snake[i]->SetY(y + 1);
				break;
			case LEFT:
				this->_snake[i]->SetY(y - 1);
				break;
		}
		if (i != 0)
		{
			if (_snake[i]->GetDirection() != _snake[i - 1]->GetDirection())
			{
				_snake[i]->SetDirection(_snake[i - 1]->GetDirection());
			}
		}
	}
	return ValidMove();
}

bool	Snake::ValidMove()
{
	for(size_t i = 0; i < this->_snake.size(); i++)
	{
		for(size_t j = 0; j < this->_snake.size(); j++)
		{
			if (j == i) continue;
			if (_snake[i]->GetY() == _snake[j]->GetY())
			{
				if (_snake[i]->GetX() == _snake[j]->GetY())
				{
					return false;
				}
			}
		}
	}
	return true;
}