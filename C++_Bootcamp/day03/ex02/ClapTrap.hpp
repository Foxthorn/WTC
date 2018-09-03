/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:32:17 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 11:32:18 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
            ClapTrap();
            ClapTrap(std::string name);
            ClapTrap(ClapTrap const & src);
            ~ClapTrap();

            ClapTrap &  operator=(ClapTrap const & src);

            void        takeDamage(unsigned int amount);            
            void        beRepaired(unsigned int amount);       
            void        vault_hunter_dot_exe(std::string const & target);   

            std::string getName();
            void        setName(std::string);  

    protected:
            unsigned int         _hit_points;
            unsigned int         _max_hit_points;
            unsigned int         _energy;
            unsigned int         _max_energy;
            unsigned int         _level;
            std::string          _name;
            unsigned int         _melee_damage;
            unsigned int         _ranged_damage;
            unsigned int         _armor_reduction;
};

#endif
