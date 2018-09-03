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

Game::Game(int width, int height) : _height(height), _width(width)
{
	std::vector<int> temp;
	for(int i = 0; i <= width; i++) 
	{
		temp.push_back(NOTHING);
	}
	for(int i = 0; i <= height; i++) 
	{
		this->_map.push_back(temp);
	}

	PlaceFood();
	PlaceSnake();
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

void	Game::InitMap()
{
	for(int i = 0; i < this->_map.size(); i++) 
	{
		for(int j = 0; j < this->_map[i].size(); j++)
		{
			std::cout << this->_map[i][j];
		}
		std::cout << std::endl;
	}
}

void	Game::PlaceFood()
{
	srand(time(NULL));
	int x = rand() % _height;
	int y = rand() % _width;
	while(_map[y][x] != NOTHING)
	{
		srand(time(NULL));
		int x = rand() % _height;
		int y = rand() % _width;
	}

	_food.SetY(y);
	_food.SetX(x);
	_food.SetType(FOOD);

	_map[y][x] = FOOD;
}