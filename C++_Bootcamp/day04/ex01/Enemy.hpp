/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:17:26 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 10:17:27 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy
{
    public:
        Enemy(int hp, std::string const & type);
        Enemy(Enemy const & src);
        virtual ~Enemy();

        std::string const & getType() const;
        int                 getHP() const;

        Enemy &  operator=(Enemy const & src);

        virtual void takeDamage(int);

    protected:
        std::string const   _type;
        int                 _hp;
};

#endif
