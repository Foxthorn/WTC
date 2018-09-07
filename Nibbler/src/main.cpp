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

int	main(int ac, char** av)
{
	if (ac != 3) 
	{
		std::cout << "Usage: ./nibbler [window: width] [window: height]" << std::endl;
		std::cout << "MIN_WIDTH = 100" << std::endl;
		std::cout << "MIN_HEIGHT = 100" << std::endl;		
		std::cout << "MAX_WIDTH = 1000" << std::endl;
		std::cout << "MAX_HEIGHT = 800" << std::endl;
	}
	else 
	{
		try
		{
			int width = std::atoi(av[1]);
			int height = std::atoi(av[2]);
			if (width >= 100 && height >= 100 && width <= 1000 && height <= 800) {
				Game game(width, height);
				game.Loop();
			}
			else
			{
				throw Error::ArgumentsException();
			}
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
}
