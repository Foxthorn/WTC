/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScreenObject.hpp                                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13/43/58 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/03 13/43/58 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCREENOBJECT_HPP
# define	SCREENOBJECT_HPP

#include "eGameObjects.hpp"

class ScreenObject {
	public:
		ScreenObject();
		ScreenObject(ScreenObject const & src);
		~ScreenObject();
		ScreenObject & operator=(ScreenObject const & src);

		void	SetX(int x);
		void	SetY(int y);
		void	SetType(int type);
		int		GetX();
		int		GetY();
		int		GetType();

	private:
		int	_x;
		int	_y;
		int	_type;

	protected:

};

#endif
