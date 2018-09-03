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

#include <iostream>

class ScavTrap
{
    public:
            ScavTrap();
            ScavTrap(std::string name);
            ScavTrap(ScavTrap const & src);
            ~ScavTrap();

            ScavTrap &  operator=(ScavTrap const & src);

            void        rangedAttack(std::string const & target);
            void        meleeAttack(std::string const & target);
            void        takeDamage(unsigned int amount);            
            void        beRepaired(unsigned int amount);       
            void        challengeNewcomer(std::string const & target);   

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

