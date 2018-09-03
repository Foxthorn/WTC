/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wisp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:06:04 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/08 10:06:05 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WISP_HPP
# define WISP_HPP

#include "Victim.hpp"
#include <iostream>

class Wisp : public Victim
{
    public:
        Wisp();
        Wisp(Wisp const & src);
        Wisp(std::string name);
        virtual ~Wisp();

        virtual void getPolymorphed() const;
};

#endif
