/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12/19/10 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/12 12/19/10 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		C_HPP
# define	C_HPP

#include "Base.hpp"

class C : public Base 
{
	public:
		C();
		C(C const & src);
		~C();
		C & operator=(C const & src);
	private:

	protected:

};

#endif