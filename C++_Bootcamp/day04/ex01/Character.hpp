/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:18:24 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 10:18:25 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <iostream>

class Character
{
    public:
        Character();
        Character(std::string const & name);
        Character(Character const & src);
        ~Character();

        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);
        std::string const & getName() const;
        AWeapon*            getWeapon() const;
        int                 getAP() const;

        Character &  operator=(Character const & src);

    private:
        std::string const   _name;
        int                 _ap;
        AWeapon*            _weapon;

};

std::ostream & operator<<( std::ostream & o, Character const & rhs);

#endif
