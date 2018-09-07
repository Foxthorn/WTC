/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10/21/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/04 10/21/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FACTORY_HPP
# define	FACTORY_HPP

#include <iostream>
#include "eLibraries.hpp"
#include "IFunctions.hpp"
#include "Error.hpp"

class Factory {
	public:
		Factory();
		Factory(int width, int height);
		Factory(Factory const & src);
		~Factory();
		Factory & operator=(Factory const & src);

		IFunctions	* CreateLibrary(int library);
		void		CloseLibrary(IFunctions * graphicsInterface);

	private:
		IFunctions	* CreateSDL();
		IFunctions	* CreateOpenGL();	
		IFunctions	* CreateSFML();
		int			_currentLibrary;
		void		* _dlhandle;
		IFunctions	* _graphicsInstance;
		int			_width;
		int			_height;
};

#endif
