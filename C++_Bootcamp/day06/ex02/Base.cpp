/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12/19/13 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/12 12/19/13 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base() {}

Base::Base(Base const & src) {
	*this = src;	
}

Base::~Base() {}

Base & Base::operator=(Base const & src) 
{
	if (this != &src)
		*this = src;
	return *this;
}

