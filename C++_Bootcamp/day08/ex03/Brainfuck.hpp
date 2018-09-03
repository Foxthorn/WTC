/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brainfuck.hpp                                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11/01/54 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11/01/54 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BRAINFUCK_HPP
# define	BRAINFUCK_HPP

#include <vector>

class Brainfuck {
	public:
		Brainfuck();
		Brainfuck(std:string const str);
		Brainfuck(Brainfuck const & src);
		~Brainfuck();
		Brainfuck & operator=(Brainfuck const & src);

		char * res;
		std::vector<char> data;
		const char *code;
};

#endif
