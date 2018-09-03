/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 07:20:06 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/06 07:20:09 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) 
{
    std::cout << "Defualt constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& src )
{
    this->_value = src._value;
    std::cout << "Copy Constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;

    return _value;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    
    this->_value = raw;
}

Fixed& Fixed::operator=( const Fixed &rhs )
{
    std::cout << "Assignation operator called" << std::endl;

    this->_value = rhs.getRawBits();

    return *this;
}
