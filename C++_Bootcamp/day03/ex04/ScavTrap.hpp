/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:12:36 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 11:12:37 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
    public:
            ScavTrap();
            ScavTrap(std::string name);
            ScavTrap(ScavTrap const & src);
            ~ScavTrap();

            void    meleeAttack(std::string const & target);
            void    rangedAttack(std::string const & target);
            void    challengeNewcomer(std::string const & target);  
};

#endif

