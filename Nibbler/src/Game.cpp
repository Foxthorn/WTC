/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14/22/25 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/03 14/22/25 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game() {}

Game::Game(Game const & src) 
{
	*this = src;	
}

Game::Game(int width, int height) : _width(width), _height(height)
{
	this->_columns = width / BLOCK_SIZE;
	this->_rows = height / BLOCK_SIZE;
	this->_snake = new Snake(_rows / 2, _columns / 2, RIGHT);
	std::vector<int> temp;
	for(int i = 0; i <= this->_columns; i++) 
	{
		temp.push_back(NOTHING);
	}
	for(int i = 0; i <= this->_rows; i++) 
	{
		this->_map.push_back(temp);
	}
	PlaceSnake();
	PlaceFood();
}

Game::~Game() {}

Game & Game::operator=(Game const & src) 
{
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

void	Game::Loop()
{
	Factory factory(_width, _height);
	IFunctions *func = factory.CreateLibrary(SFML);
	while(_snake->MoveSnake(_map))
	{
		if (func->Event())
		{
			if (func->Close())
			{
				break;
			}
			else if (func->Key() == ESC_KEY)
			{
				break;
			}
			else if (func->Key() == KEY_1 || func->Key() == KEY_2)
			{
				if (func->Key() == KEY_1) func = factory.CreateLibrary(SDL);
				else if (func->Key() == KEY_2) func = factory.CreateLibrary(SFML);
			}
			else if (func->Key() == UP_KEY || func->Key() == DOWN_KEY || func->Key() == RIGHT_KEY || func->Key() == LEFT_KEY)
			{
				ChangeSnakeDirection(func->Key());
			}
		}
		func->Render(_map);
		func->Sleep(100);
		CheckFood();
	}
	factory.CloseLibrary(func);
	
}

void	Game::CheckFood()
{
	auto snake = _snake->getSnake();
	if (_food.GetX() == snake[0]->GetX() && _food.GetY() == snake[0]->GetY())
	{
		_snake->EatFood();
		PlaceFood();
	}
}

void	Game::PrintMap()
{
	for(size_t i = 0; i < this->_map.size(); i++) 
	{
		for(size_t j = 0; j < this->_map[i].size(); j++)
		{
			std::cout << this->_map[i][j];
		}
		std::cout << std::endl;
	}
}

void	Game::PlaceFood()
{
	srand(time(NULL));
	int x = rand() % _columns;
	int y = rand() % _rows;
	while(_map[y][x] != NOTHING)
	{
		srand(time(NULL));
		x = rand() % _columns;
		y = rand() % _rows;
	}

	_food.SetY(y);
	_food.SetX(x);
	_food.SetType(FOOD);

	_map[y][x] = FOOD;
}

void	Game::PlaceSnake()
{
	std::vector<ScreenObject *> display_snake = _snake->getSnake();
	for(size_t i = 0; i < display_snake.size(); i++)
	{
		int x = display_snake[i]->GetX();
		int y = display_snake[i]->GetY();
		_map[y][x] = display_snake[i]->GetType();
	}
}

void	Game::ChangeSnakeDirection(int direction)
{
	std::vector<ScreenObject *> display_snake = _snake->getSnake();
	if (display_snake[0]->GetDirection() == UP && direction == DOWN) return;
	if (display_snake[0]->GetDirection() == DOWN && direction == UP) return;
	if (display_snake[0]->GetDirection() == LEFT && direction == RIGHT) return;
	if (display_snake[0]->GetDirection() == RIGHT && direction == LEFT) return;
	if (display_snake[0]->GetType() == SNAKE_HEAD)
		display_snake[0]->SetDirection(direction);
}
