/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IFunctions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09/37/43 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/04 09/37/43 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		IFUNCTIONS_HPP
# define	IFUNCTIONS_HPP

#include <vector>
#include "Error.hpp"
#include "eKeys.hpp"
#include "eGameObjects.hpp"

#define BLOCK_SIZE 10
#define MAX_HEIGHT 800
#define MAX_WIDTH 1000

class IFunctions {
	public:
		virtual void	Initialise(int width, int height) = 0;
		virtual bool	Event() = 0;
		virtual	Keys	Key() = 0;
		virtual	void	Sleep(int sleep) = 0;
		virtual bool	Close() = 0;
		virtual void	Render(std::vector<std::vector<int>> & map) = 0;
	private:
};

#endif
