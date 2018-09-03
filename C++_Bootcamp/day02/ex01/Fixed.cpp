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
#include <cmath>

Fixed::Fixed( void ) 
{
    std::cout << "Defualt constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& src )
{
    this->_value = src._value;
    std::cout << "Copy Constructor called" << std::endl;
}

Fixed::Fixed( int const value )
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(value * (1 << _bits));
}

Fixed::Fixed( float const value )
{
    int n;
    std::cout << "Float constructor called" << std::endl;
    n = roundf(value * (1 << _bits));
    setRawBits(n);
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return this->_value;
}

void Fixed::setRawBits( int const raw )
{
     this->_value = raw;
}

Fixed& Fixed::operator=( const Fixed &rhs )
{
    std::cout << "Assignation operator called" << std::endl;

    this->_value = rhs.getRawBits();

    return *this;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs )
{
    o << rhs.toFloat();
    return o;
}

float Fixed::toFloat( void ) const
{
    float val;

    val = getRawBits();
    return (val / (1 << this->_bits));
}

int Fixed::toInt( void ) const
{
    int val = getRawBits() >> this->_bits;
    return val;
}