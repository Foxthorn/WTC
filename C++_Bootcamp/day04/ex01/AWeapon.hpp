/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:16:00 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 10:16:05 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
    public:
        AWeapon();
        AWeapon(std::string const & name, int apcost, int damage);
        AWeapon(AWeapon const & src);
        virtual ~AWeapon();

        virtual void attack() const = 0;

        std::string const & getName() const;
        int                 getAPCost() const;
        int                 getDamage() const;

        AWeapon &  operator=(AWeapon const & src);

    protected:
        std::string _name;
        int         _damage;
        int         _ap;
};

#endif