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
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
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
		*this = src;
    }
	return (*this);
}

void		Functions::Render(std::vector<std::vector<int>> & map)
{
	SDL_Rect block;
	SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 0);
	SDL_RenderClear(this->_renderer);
	block.h = BLOCK_SIZE;
	block.w = BLOCK_SIZE;
	for(size_t col = 0; col < this->_columns; col++)
	{
		for(size_t row = 0; row < this->_rows; row++)
		{
			bool drawn = false;
			// std::cout << map[row][col] << std::endl;
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
	// if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_FULLSCREEN, &this->_window, &this->_renderer) == -1) 
	// {
	// 	throw Error::CreateWindowException();
	// }	
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
		return true;
	else
		return false;
}

Keys	Functions::Key()
{
	if (this->_event.type == SDL_KEYDOWN)
	{
		if (this->_event.key.keysym.sym == SDLK_UP)
		{
			return Keys::UP_KEY;
		}
		else if (this->_event.key.keysym.sym == SDLK_DOWN)
		{
			return Keys::DOWN_KEY;
		}
		else if (this->_event.key.keysym.sym == SDLK_RIGHT)
		{
			return Keys::RIGHT_KEY;
		} 
		else if (this->_event.key.keysym.sym == SDLK_LEFT)
		{
			return Keys::LEFT_KEY;
		} 
		else if (this->_event.key.keysym.sym == SDLK_ESCAPE)
		{
			return Keys::ESC_KEY;
		} 
		else if (this->_event.key.keysym.sym == SDLK_1)
		{
			return Keys::KEY_1;
		} 
		else if (this->_event.key.keysym.sym == SDLK_2)
		{
			return Keys::KEY_2;
		} 
		else if (this->_event.key.keysym.sym == SDLK_3)
		{
			return Keys::KEY_3;
		}
	}
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