/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:11:34 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 13:11:35 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    public:
            HumanB(std::string name);
            ~HumanB();

            std::string name;
            Weapon*     weapon;

            void setWeapon(Weapon& weapon);
            void attack();
};

#endif
