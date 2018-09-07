/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09/33/56 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/04 09/33/56 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FUNCTIONS_HPP
# define	FUNCTIONS_HPP

#include "../includes/IFunctions.hpp"
#include <iostream>
#include <SDL.h>

class Functions : public IFunctions 
{
	public:
		Functions();
		Functions(Functions const & src);
		virtual	~Functions();
		Functions & operator=(Functions const & src);

		virtual void	Initialise(int width, int height);
		virtual bool	Event();
		virtual Keys	Key();
		virtual	void	Sleep(int sleep);
		virtual bool	Close();
		virtual void	Render(std::vector<std::vector<int>> & map);

	private:
		SDL_Window 		* _window;
		SDL_Renderer 	* _renderer;
		SDL_Event		_event;
		bool			_keyPressed;
		int				_columns;
		int				_rows;
		int				_width;
		int				_height;
};

extern "C" Functions * createFunctions();
extern "C" void deleteFunctions(Functions * func);

#endif
