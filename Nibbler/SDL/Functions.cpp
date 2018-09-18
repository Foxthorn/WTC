/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09/33/56 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/04 09/33/56 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Functions::Functions()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		throw Error::InitError();
	}
}

Functions::Functions(Functions const & src) {
	*this = src;	
}

Functions::~Functions()
{
	SDL_DestroyRenderer(this->_renderer);
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
}

Functions & Functions::operator=(Functions const & src) {
	if (this != &src)
    {
		this->_window = src._window;
		this->_renderer = src._renderer;
		this->_event = src._event;
		this->_width = src._width;
		this->_height = src._height;
		this->_columns = src._columns;
		this->_rows = src._rows;
    }
	return (*this);
}

void		Functions::Render(std::vector<std::vector<int>> & map)
{
	SDL_Rect block;
	SDL_SetRenderDrawColor(this->_renderer, 128, 128, 128, 0);
	SDL_RenderClear(this->_renderer);
	block.h = BLOCK_SIZE;
	block.w = BLOCK_SIZE;
	for(int col = 0; col < this->_columns; col++)
	{
		for(int row = 0; row < this->_rows; row++)
		{
			bool drawn = false;
			if (map[row][col] == SNAKE_BODY)
			{
				SDL_SetRenderDrawColor(this->_renderer, 0, 255, 0, 0);
				drawn = true;
			}
			else if (map[row][col] == SNAKE_HEAD)
			{
				SDL_SetRenderDrawColor(this->_renderer, 255, 0, 0, 0);
				drawn = true;
			}
			else if (map[row][col] == FOOD)
			{
				SDL_SetRenderDrawColor(this->_renderer, 0, 255, 255, 0);
				drawn = true;
			}
			else if (map[row][col] == SPECIAL_FOOD)
			{
				SDL_SetRenderDrawColor(this->_renderer, 255, 223, 0, 0);
				drawn = true;
			}
			if (drawn)
			{
				block.x = col * BLOCK_SIZE;
				block.y = row * BLOCK_SIZE;
				SDL_RenderFillRect(this->_renderer, &block);
			}
		}
	}
	SDL_RenderPresent(this->_renderer);
}

void	Functions::Initialise(int width, int height)
{	
	if (SDL_CreateWindowAndRenderer(width, height, 0, &this->_window, &this->_renderer) == -1) 
	{
		throw Error::CreateWindowException();
	}	

	SDL_SetWindowTitle(this->_window, "Nibbler SDL");
	SDL_SetWindowPosition(this->_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	this->_width = width;
	this->_height = height;
	this->_columns = width / BLOCK_SIZE;
	this->_rows = height / BLOCK_SIZE;
}

bool	Functions::Event()
{
	if (SDL_PollEvent(&this->_event) == 1) 
	{
		return true;
	}
	return false;
}

Keys	Functions::Key()
{
	if (this->_event.type == SDL_KEYDOWN) 
	{
		switch(this->_event.key.keysym.sym)
		{
			case SDLK_UP:
				return Keys::UP_KEY;
			case SDLK_DOWN:
				return Keys::DOWN_KEY;
			case SDLK_RIGHT:
				return Keys::RIGHT_KEY;
			case SDLK_LEFT:
				return Keys::LEFT_KEY;
			case SDLK_ESCAPE:
				return Keys::ESC_KEY;
			case SDLK_1:
				return Keys::KEY_1;
			case SDLK_2:
				return Keys::KEY_2;		
			case SDLK_3:
				return Keys::KEY_3;		
		}
	}
	return Keys::NO_KEY;
}

void	Functions::Sleep(int sleep)
{
	SDL_Delay(sleep);
}

bool	Functions::Close()
{
	if (this->_event.type == SDL_QUIT)
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

void deleteFunctions(Functions * func)
{
	delete func;
}