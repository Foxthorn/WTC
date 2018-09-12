/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:38:44 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/03 14:03:12 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Game.hpp"

void	ValidArguments(const std::string & str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			throw Error::ArgumentsException();
		}
	}
}

void	ValidResolution(const std::string & w, const std::string & h)
{
	double width = std::stof(w);
	double height = std::stof(h);

	if ((width < 200 && height < 200) || (width > 1000 && height > 800))
	{
		throw Error::ResolutionException();
	}
	if (width > height)
	{
		if (width / height >= 1.95)
			throw Error::ResolutionException();
	}
	if (width < height) 
	{
		if (height / width >= 1.95)
			throw Error::ResolutionException();
	}
	if (static_cast<int>(width) % 10 != 0 || static_cast<int>(height) % 10 != 0)
	{
		throw Error::ResolutionException();
	}
}

int		main(int ac, char** av)
{
	if (ac != 4) 
	{
		std::cout << "Usage: ./nibbler [window: width] [window: height] [Library]" << std::endl;
		std::cout << "SDL: 0, SFML: 1, OPENGL: 2" << std::endl;
		std::cout << "Height < 2 x Width" << std::endl;
		std::cout << "OR" << std::endl;
		std::cout << "Width < 2 x Height" << std::endl;
		std::cout << "Width and Height must be divisible by 10" << std::endl;
		std::cout << "MIN_WIDTH = 200" << std::endl;
		std::cout << "MIN_HEIGHT = 200" << std::endl;		
		std::cout << "MAX_WIDTH = 1000" << std::endl;
		std::cout << "MAX_HEIGHT = 800" << std::endl;
	}
	else 
	{
		try
		{
			for(int i = 1; i <= 3; i++)
			{
				ValidArguments(av[i]);
			}
			ValidResolution(av[1], av[2]);
			int library = std::atoi(av[3]);
			if (library > 2 || library < 0)
			{
				throw Error::LibraryException();
			}
			int width = std::stoi(av[1]);
			int height = std::stoi(av[2]);
			Game game(width, height, library);
			game.Loop();
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
}
