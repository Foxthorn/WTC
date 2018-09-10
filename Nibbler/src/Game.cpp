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

Game::Game(int width, int height, int library) : _width(width), _height(height)
{
	this->_columns = width / BLOCK_SIZE;
	this->_rows = height / BLOCK_SIZE;
	this->_snake = new Snake(_rows / 2, _columns / 2, RIGHT);
	this->_start_library = library;
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

Game::~Game() 
{
	for(size_t i = 0; i < _map.size(); i++)
	{
		_map[i].clear();
	}
	_map.clear();
}

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
	Factory factory(_width, _height, this->_start_library);
	IFunctions * func = factory.CreateLibrary(this->_start_library);
	func->Render(_map);
	int sleep = 80;
	int decrease = 0;
	while(_snake->MoveSnake(_map))
	{
		bool swapped = false;
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
			else if (func->Key() == KEY_1 || func->Key() == KEY_2 || func->Key() == KEY_3)
			{
				if (func->Key() == KEY_1) {
					func = factory.CreateLibrary(SDL);
				}
				if (func->Key() == KEY_2)
				{
					func = factory.CreateLibrary(SFML);
				} 
				if (func->Key() == KEY_3)
				{
					func = factory.CreateLibrary(OPENGL);
				}
				swapped = true;
			}
			else if (func->Key() == UP_KEY || func->Key() == DOWN_KEY || func->Key() == RIGHT_KEY || func->Key() == LEFT_KEY)
			{
				ChangeSnakeDirection(func->Key());
			}
			if (_snake->GetLength() <= 70)
				decrease = _snake->GetLength();
		}
		func->Render(_map);
		int time_taken = CheckFood();
		UpdateMap();
		if (time_taken == 0 && !swapped)
			func->Sleep(sleep - decrease);
	}
	while(func->Key() == Keys::NO_KEY)
	{
		func->Event();
	}
	factory.CloseLibrary(func);
	std::cout << "Score: " << this->_snake->GetLength() - 4 << std::endl;
	std::cout << "GAME OVER" << std::endl;
}

int		Game::CheckFood()
{
	auto snake = _snake->getSnake();
	if (_food.GetX() == snake[0]->GetX() && _food.GetY() == snake[0]->GetY())
	{
		_snake->EatFood();
		return PlaceFood();
	}
	return 0;
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

int		Game::PlaceFood()
{
	int start = time(NULL);
	srand(time(NULL));
	int x = rand() % _columns;
	int y = rand() % _rows;
	while(ValidFood(x, y))
	{
		srand(time(NULL));
		x = rand() % _columns;
		y = rand() % _rows;
	}
	_food.SetY(y);
	_food.SetX(x);
	_food.SetType(FOOD);

	_map[y][x] = FOOD;
	int end = time(NULL);
	return end - start;
}

bool	Game::ValidFood(int x, int y)
{
	auto snake = this->_snake->getSnake();
	if (_map[y][x] == SNAKE_BODY || _map[y][x] == SNAKE_HEAD)
		return true;
	if (x >= _columns || y >= _rows)
		return true;
	return false;
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

void	Game::UpdateMap()
{
	auto snake = this->_snake->getSnake();
	for (size_t s = 0; s < snake.size(); s++)
	{ 
		int x = snake[s]->GetX();
		int y = snake[s]->GetY();
		_map[y][x] = snake[s]->GetType();
	}
	int x = _food.GetX();
	int y = _food.GetY();
	_map[y][x] = FOOD;
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
