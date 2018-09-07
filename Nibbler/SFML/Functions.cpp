/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12/53/02 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/06 12/53/02 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Functions::Functions() 
{
	std::cout << "SFML CONSTRUCTED" << std::endl;
}

Functions::Functions(Functions const & src) {
	*this = src;	
}

Functions::~Functions() 
{
	std::cout << "SFML DECONSTRUCTED" << std::endl;
	this->_window->close();
	delete this->_window;
}

Functions & Functions::operator=(Functions const & src) {
	if (this != &src)
    {
		this->_window = src._window;
		this->_width = src._width;
		this->_height = src._height;
		this->_event = src._event;
		this->_columns = src._columns;
		this->_rows = src._rows;
    }
	return (*this);
}

void	Functions::Initialise(int width, int height)
{
	this->_width = width;
	this->_height = height;
	this->_columns = width / BLOCK_SIZE;
	this->_rows = height / BLOCK_SIZE;

	sf::String s;
	s = "Nibbler SFML";
	this->_window = new sf::RenderWindow(sf::VideoMode(width, height), s, sf::Style::None);
	if (this->_window == NULL)
	{
		throw Error::CreateWindowException();
	}

	this->_window->setActive(false);
}

void	Functions::Render(std::vector<std::vector<int>> & map)
{
	sf::Color color;
	color.r = 83;
	color.g = 101;
	color.b = 188;
	this->_window->clear(color);
	sf::RectangleShape block(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
	
	for(int col = 0; col < this->_columns; col++)
	{
		for(int row = 0; row < this->_rows; row++)
		{
			bool drawn = false;
			if (map[row][col] == SNAKE_BODY)
			{
				color.r = 255;
				color.g = 255;
				color.b = 0;
				drawn = true;
			}
			else if (map[row][col] == SNAKE_HEAD)
			{
				color.r = 0;
				color.g = 255;
				color.b = 255;
				drawn = true;
			}
			else if (map[row][col] == FOOD)
			{
				color.r = 0;
				color.g = 0;
				color.b = 0;
				drawn = true;
			}
			if (drawn)
			{
				block.setPosition(static_cast<float>(col * BLOCK_SIZE), static_cast<float>(row * BLOCK_SIZE));
				block.setFillColor(color);
				this->_window->draw(block);
			}
		}
	}
	this->_window->display();
}

void	Functions::Sleep(int sleep)
{
	sf::Time delay = sf::milliseconds(sleep);
	sf::sleep(delay);
}

Keys	Functions::Key()
{
	if (this->_event.type == sf::Event::KeyPressed)
	{
		if (this->_event.key.code == sf::Keyboard::Up)
		{
			return Keys::UP_KEY;
		}
		else if (this->_event.key.code == sf::Keyboard::Down)
		{
			return Keys::DOWN_KEY;
		}
		else if (this->_event.key.code == sf::Keyboard::Right)
		{
			return Keys::RIGHT_KEY;
		} 
		else if (this->_event.key.code == sf::Keyboard::Left)
		{
			return Keys::LEFT_KEY;
		} 
		else if (this->_event.key.code == sf::Keyboard::Escape)
		{
			return Keys::ESC_KEY;
		} 
		else if (this->_event.key.code == sf::Keyboard::Num1)
		{
			return Keys::KEY_1;
		} 
		else if (this->_event.key.code == sf::Keyboard::Num2)
		{
			return Keys::KEY_2;
		} 
		else if (this->_event.key.code == sf::Keyboard::Num3)
		{
			return Keys::KEY_3;
		}
	}
	return Keys::NO_KEY;
}

bool	Functions::Event()
{
	return (this->_window->pollEvent(this->_event));
}

bool	Functions::Close()
{
	if(this->_event.type == sf::Event::Closed)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Functions * createFunctions()
{
	return new Functions();
}

void	deleteFunctions(Functions * func)
{
	delete func;
}