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
	}
	else 
	{
		if (std::atoi(av[1]) >= 100 && std::atoi(av[2]) >= 100) {
			Game game(std::atoi(av[1]), std::atoi(av[2]));
			game.Loop();
		}
	}
}
