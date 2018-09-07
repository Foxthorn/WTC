/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12/53/02 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/06 12/53/02 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FUNCTIONS_HPP
# define	FUNCTIONS_HPP

#include "../includes/IFunctions.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Functions : public IFunctions
{
	public:
		Functions();
		Functions(Functions const & src);
		virtual ~Functions();
		Functions & operator=(Functions const & src);

		virtual void	Initialise(int width, int height);
		virtual bool	Event();
		virtual Keys	Key();
		virtual	void	Sleep(int sleep);
		virtual bool	Close();
		virtual void	Render(std::vector<std::vector<int>> & map);

	private:
		sf::RenderWindow	* _window;
		sf::Event			_event;
		int					_width;
		int					_height;
		int					_rows;
		int					_columns;
};

extern "C" Functions * createFunctions();
extern "C" void	deleteFunctions(Functions * func);

#endif
