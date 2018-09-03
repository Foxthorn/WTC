/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bdecr.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/07/27 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/07/27 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BDECR_HPP
# define	BDECR_HPP

#include "Brainfuck.hpp"

class Bdecr {
	public:
		Bdecr();
		Bdecr(Bdecr const & src);
		~Bdecr();
		Bdecr & operator=(Bdecr const & src);
		
		void	execute(Brainfuck * b);
};

#endif
