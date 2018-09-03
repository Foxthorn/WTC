/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12/18/59 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/12 12/18/59 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		B_HPP
# define	B_HPP

#include "Base.hpp"

class B : public Base 
{
	public:
		B();
		B(B const & src);
		~B();
		B & operator=(B const & src);
	private:

	protected:

};

#endif
