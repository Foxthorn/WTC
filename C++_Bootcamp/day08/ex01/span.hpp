/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08/36/08 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/14 08/36/08 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SPAN_HPP
# define	SPAN_HPP

#include <list>

class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(Span const & src);
		~Span();

		Span & operator=(Span const & src);

		void	addNumber(int num);
		int		shortestSpan();
		int		longestSpan();
		void	betterAddNumber(std::list<int> numebrs);

	private:
		unsigned int	_n;
		std::list<int>		_lst;
};

#endif
