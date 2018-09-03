/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 08:29:02 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 08:29:04 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
    public:
        Sorcerer();
        Sorcerer(Sorcerer const & src);
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();

        void        polymorph(Victim const &) const;

        std::string getName() const;
        std::string getTitle() const;
        void        setName(std::string name);
        void        setTitle(std::string title);

    private:
        std::string _name;
        std::string _title;
};

std::ostream & operator<<( std::ostream & o, Sorcerer const & rhs);

#endif
