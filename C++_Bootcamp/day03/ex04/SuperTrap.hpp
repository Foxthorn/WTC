/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:49:39 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 12:49:40 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

class SuperTrap : public FragTrap, public NinjaTrap
{
    public:
            SuperTrap();
            SuperTrap(std::string name);
            SuperTrap(SuperTrap const & src);
            ~SuperTrap();

            void    meleeAttack(std::string const & target);
            void    rangedAttack(std::string const & target);
};

#endif