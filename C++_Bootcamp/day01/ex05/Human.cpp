/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:12:59 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 11:13:00 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include "Brain.hpp"
#include <iostream>
#include <sstream>

Human::Human() {};
Human::~Human() {};

Brain const & Human::getBrain(void)
{
    return mind;
}


std::string Human::identify() const
{
    std::stringstream sptr;

    sptr << this;
    return (sptr.str());
}
