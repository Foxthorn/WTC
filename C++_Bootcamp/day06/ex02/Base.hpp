/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12/19/13 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/12 12/19/13 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BASE_HPP
# define	BASE_HPP

class Base 
{
	public:
		Base();
		Base(Base const & src);
		virtual ~Base();
		Base & operator=(Base const & src);

};

#endif
