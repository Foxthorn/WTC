/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:12:55 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 11:12:56 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"
#include <iostream>

class Human
{
    public:
            Human();
            ~Human();

            Brain const &getBrain(void);
            std::string identify() const;

            Brain const mind;
};

#endif