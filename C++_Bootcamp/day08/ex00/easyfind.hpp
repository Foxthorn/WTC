/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:42:07 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/14 07:42:08 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <list>
#include <stdexcept>

template<typename T>
int     easyfind( T & lst, int num)
{
    typename T::iterator   it;
    typename T::iterator   ite = lst.end();

    for (it = lst.begin(); it != ite; ++it)
    {
        if (*it == num)
            return *it;
    }
    throw std::logic_error("No Instance in container");
}

#endif