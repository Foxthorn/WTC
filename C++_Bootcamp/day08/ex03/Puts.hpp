/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Puts.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/07/35 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/07/35 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PUTS_HPP
# define	PUTS_HPP

#include "Brainfuck.hpp"

class Puts {
	public:
		Puts();
		Puts(Puts const & src);
		~Puts();
		Puts & operator=(Puts const & src);

		void	execute(Brainfuck * b);

};

#endif
