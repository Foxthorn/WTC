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
	InitSpecialFood();
	Factory factory(_width, _height, this->_start_library);
	IFunctions * func = factory.CreateLibrary(this->_start_library);
	func->Render(_map);
	int sleep = 80;
	int decrease = 0;
	while(func->Key() == Keys::NO_KEY)
	{
		func->Event();
	}
	while(_snake->MoveSnake(_map))
	{
		bool swapped = false;
		if (func->Event())
		{
			if (func->Close())
			{
				break;
			}
			switch (func->Key())
			{
				case ESC_KEY:
					factory.CloseLibrary(func);
					DisplayScore();
					return;
				case KEY_1:
					func = factory.CreateLibrary(SDL);
					swapped = true;
					break;
				case KEY_2:
					func = factory.CreateLibrary(SFML);
					swapped = true;
					break;
				case KEY_3:
					func = factory.CreateLibrary(OPENGL);
					swapped = true;
					break;
				case UP_KEY:
					ChangeSnakeDirection(func->Key());
					break;
				case DOWN_KEY:
					ChangeSnakeDirection(func->Key());
					break;
				case RIGHT_KEY:
					ChangeSnakeDirection(func->Key());
					break;
				case LEFT_KEY:
					ChangeSnakeDirection(func->Key());
					break;
				case NO_KEY:
					break;
			}
			if (_snake->GetLength() <= 70)
				decrease = _snake->GetLength();
		}
		func->Render(_map);
		CheckSpecialFood();
		int time_taken = CheckFood();
		UpdateMap();
		if (time_taken == 0 && !swapped)
			func->Sleep(sleep - decrease);
	}
	factory.CloseLibrary(func);
	DisplayScore();
}

void	Game::DisplayScore()
{
	std::cout << "Food:		" << this->_snake->GetLength() - _num_special_food - 4 << std::endl;
	std::cout << "Special Food :	" << _num_special_food << " * 10" << std::endl;
	std::cout << "		_________ +" << std::endl;
	std::cout << "Final Score :	" << (this->_snake->GetLength() - _num_special_food - 4) + (_num_special_food  * 10) << std::endl;
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
	if (_special_food.food.GetX() == snake[0]->GetX() && _special_food.food.GetY() == snake[0]->GetY())
	{
		_special_food.active = false;
		_snake->EatFood();
		_num_special_food += 1;
		return 0;
	}
	return 0;
}

void	Game::InitSpecialFood()
{
	_special_food.active = false;
	_special_food.time_left = 0;
	_num_special_food = 0;
}

void	Game::CheckSpecialFood()
{
	if (_special_food.active == true)
	{
		_special_food.time_left -= 1;
		if (_special_food.time_left == 0)
		{
			_special_food.active = false;
		}
	}
	else
	{
		int rng = rand() % 100;
		if (rng >= 98)
		{
			_special_food.active = true;
			if (_height > _width) 
				_special_food.time_left = _height / 10;
			else
				_special_food.time_left = _width / 10;
			PlaceSpecialFood();
		}
	}
}

void	Game::PlaceSpecialFood()
{
	std::vector<s_point> points;
	for(size_t y = 0; y < _map.size(); y++)
	{
		for(size_t x = 0; x < _map[y].size(); x++)
		{
			s_point point;
			if (ValidFood(x, y))
			{
				point.x = x;
				point.y = y;
				points.push_back(point);
			}
		}
	}
	if (points.size() > 0) 
	{
		int i = rand() % points.size();
		int x = static_cast<int>(points[i].x);
		int y = static_cast<int>(points[i].y);
		_special_food.food.SetY(y);
		_special_food.food.SetX(x);
		_special_food.food.SetType(SPECIAL_FOOD);

		_map[y][x] = SPECIAL_FOOD;
	}
	else 
	{
		DisplayScore();
		throw Error::GAMEOVER();
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

int		Game::PlaceFood()
{
	srand(time(NULL));
	int start = time(NULL);
	std::vector<s_point> points;
	for(size_t y = 0; y < _map.size(); y++)
	{
		for(size_t x = 0; x < _map[y].size(); x++)
		{
			s_point point;
			if (_map[y][x] == NOTHING && ValidFood(x, y))
			{
				point.x = x;
				point.y = y;
				points.push_back(point);
			}
		}
	}
	if (points.size() > 0)
	{
		int i = rand() % points.size();
		int x = static_cast<int>(points[i].x);
		int y = static_cast<int>(points[i].y);
		_food.SetY(y);
		_food.SetX(x);
		_food.SetType(FOOD);

		_map[y][x] = FOOD;
		int end = time(NULL);
		return end - start;
	}
	else
	{
		DisplayScore();
		throw Error::GAMEOVER();
	}
}

bool	Game::ValidFood(int x, int y)
{
	auto snake = this->_snake->getSnake();
	if (_map[y][x] == SNAKE_BODY || _map[y][x] == SNAKE_HEAD || _map[y][x] == SPECIAL_FOOD || _map[y][x] == FOOD)
		return false;
	if (x >= _columns || y >= _rows)
		return false;
	return true;
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
	int x = snake[snake.size() - 1]->GetX();
	int y = snake[snake.size() - 1]->GetY();
	for(int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (static_cast<size_t>(j) < _map.size() && static_cast<size_t>(i) < _map[j].size())
			{
				if (_map[j][i] != NOTHING)
				{
					_map[j][i] = NOTHING;
				}
			}
		}
	}
	x = _food.GetX();
	y = _food.GetY();
	_map[y][x] = FOOD;
	if (_special_food.active == true && _special_food.time_left != 0)
	{
		_map[_special_food.food.GetY()][_special_food.food.GetX()] = SPECIAL_FOOD;
	}
	else 
	{
		_map[_special_food.food.GetY()][_special_food.food.GetX()] = NOTHING;
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
