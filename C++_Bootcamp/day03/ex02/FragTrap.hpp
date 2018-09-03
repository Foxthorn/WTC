/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:37:25 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 07:37:26 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
        public:
                FragTrap();
                FragTrap(FragTrap const & src);
                FragTrap(std::string name);
                ~FragTrap();

                void    meleeAttack(std::string const & target);
                void    rangedAttack(std::string const & target);
                void    vault_hunter_dot_exe(std::string const & target);
};

#endif
