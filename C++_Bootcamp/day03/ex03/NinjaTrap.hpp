/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:49:39 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 12:49:40 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class NinjaTrap : public ClapTrap
{
    public:
            NinjaTrap();
            NinjaTrap(std::string name);
            NinjaTrap(NinjaTrap const & src);
            ~NinjaTrap();

            void    meleeAttack(std::string const & target);
            void    rangedAttack(std::string const & target);
            void    ninjaShoebox(ScavTrap const & target);
            void    ninjaShoebox(ClapTrap const & target);
            void    ninjaShoebox(FragTrap const & target);
};

#endif