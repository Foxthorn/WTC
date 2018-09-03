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

#include <iostream>

class FragTrap
{
    public:
            FragTrap();
            FragTrap(std::string name);
            FragTrap(FragTrap const & src);
            ~FragTrap();

            FragTrap &  operator=(FragTrap const & src);

            void        rangedAttack(std::string const & target);
            void        meleeAttack(std::string const & target);
            void        takeDamage(unsigned int amount);            
            void        beRepaired(unsigned int amount);       
            void        vault_hunter_dot_exe(std::string const & target);   

            std::string getName();
            void        setName(std::string);  

    private:
            unsigned int         _hit_points;
            unsigned int         _max_hit_points;
            unsigned int         _energy_points;
            unsigned int         _max_energy_points;
            unsigned int         _level;
            std::string          _name;
            unsigned int         _melee_damage;
            unsigned int         _ranged_damage;
            unsigned int         _armor_reduction;
};

#endif
