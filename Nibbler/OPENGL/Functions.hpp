/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13/15/44 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/07 13/15/44 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FUNCTIONS_HPP
# define	FUNCTIONS_HPP

#include "../includes/IFunctions.hpp"
#include <GLFW/glfw3.h>

class Functions : public IFunctions
{
	public:
		Functions();
		Functions(Functions const & src);
		~Functions();
		Functions & operator=(Functions const & src);

		virtual void	Initialise(int width, int height);
		virtual bool	Event();
		virtual	Keys	Key();
		virtual	void	Sleep(int sleep);
		virtual bool	Close();
		virtual void	Render(std::vector<std::vector<int>> & map);
	private:
		void			Draw(int row, int col, float r, float g, float b);
		GLFWwindow*		_window;
		int				_columns;
		int				_rows;
		int				_width;
		int				_height;

};

extern "C" Functions * createFunctions();
extern "C" void deleteFunctions(Functions * func);

#endif
