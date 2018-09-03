/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:12:41 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 11:12:42 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain() 
{
    IQ = 140;
}
Brain::~Brain() {}

std::string Brain::identify() const
{
    std::stringstream sptr;

    sptr << this;
    return (sptr.str());
}