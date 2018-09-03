/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 08:29:31 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 08:29:31 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
    public:
        Victim();
        Victim(Victim const & src);
        Victim(std::string name);
        virtual ~Victim();

        virtual void    getPolymorphed() const;

        std::string     getName() const;
        void            setName(std::string name);

    protected:
        std::string _name;
};

std::ostream & operator<<( std::ostream & o, Victim const & rhs);

#endif
