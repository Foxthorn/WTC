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
#include <iostream>
#include <ctime>

Snake::Snake() {}

Snake::Snake(int y, int x, int direction)
{
	_snake.push_back(new ScreenObject(x, y, SNAKE_HEAD, direction));
	for(size_t i = 1; i <= 4; i++)
	{
		_snake.push_back(new ScreenObject(x - i, y, SNAKE_BODY, direction));
	}
	_length = static_cast<int>(this->_snake.size());
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
	for(int i = 0; i < _length; i++)
	{
		int x = this->_snake[i]->GetX();
		int y = this->_snake[i]->GetY();
		map[y][x] = NOTHING;
		switch(this->_snake[i]->GetDirection())
		{
			case UP:
				y -= 1;
				break;
			case DOWN:
				y += 1;
				break;
			case RIGHT:
				x += 1;
				break;
			case LEFT:
				x -= 1;
				break;
		}
		this->_snake[i]->SetY(y);
		this->_snake[i]->SetX(x);
	}
	return CheckMovement(map);
}

bool	Snake::CheckMovement(std::vector<std::vector<int>> & map)
{
	if (_snake[0]->GetX() >= static_cast<int>(map[0].size()) - 1 || _snake[0]->GetX() < 0)
		return false;
	if (_snake[0]->GetY() >= static_cast<int>(map.size()) - 1 || _snake[0]->GetY() < 0)
		return false;
	for(int j = 1; j < _length; j++)
	{
		if (_snake[0]->GetX() == _snake[j]->GetX() && _snake[0]->GetY() == _snake[j]->GetY())
			return false;
	}
	for(int i = 0; i < _length; i++)
	{
		map[_snake[i]->GetY()][_snake[i]->GetX()] = _snake[i]->GetType();
	}
	for(int i = _length - 1; i > 0; i--)
	{
		if (i == 0) continue;
		if (_snake[i]->GetDirection() != _snake[i - 1]->GetDirection())
			_snake[i]->SetDirection(_snake[i - 1]->GetDirection());
	}
	return true;
}

void	Snake::EatFood()
{
	int x = _snake[_length - 1]->GetX();
	int y = _snake[_length - 1]->GetY();
	int direction = _snake[_length - 1]->GetDirection();
	if (direction == UP) y += 1;
	if (direction == DOWN) y -= 1;
	if (direction == RIGHT) x -= 1;
	if (direction == LEFT) x += 1;
	this->_snake.push_back(new ScreenObject(x, y, SNAKE_BODY, direction));
	_length = static_cast<int>(this->_snake.size());
}