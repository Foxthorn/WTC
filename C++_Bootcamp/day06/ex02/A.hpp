/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12/19/13 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/12 12/19/13 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		A_HPP
# define	A_HPP

#include "Base.hpp"

class A : public Base 
{
	public:
		A();
		A(A const & src);
		~A();
		A & operator=(A const & src);
	private:

	protected:

};

#endif
