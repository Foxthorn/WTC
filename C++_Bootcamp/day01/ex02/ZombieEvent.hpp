/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:42:46 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 09:42:47 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <string>

class ZombieEvent
{
    public:
            ZombieEvent();
            ~ZombieEvent();

            std::string zombieType;

            void    setZombieType(std::string type);
            Zombie* newZombie(std::string name);
            Zombie* randomChump(void);
};

#endif
