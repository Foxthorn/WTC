/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 07:20:06 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/07 07:32:07 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : _value(0)
{
    //std::cout << "Defualt constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& src )
{
    this->_value = src._value;
    //std::cout << "Copy Constructor called" << std::endl;
}

Fixed::Fixed( int const value )
{
    //std::cout << "Int constructor called" << std::endl;
    setRawBits(value * (1 << _bits));
}

Fixed::Fixed( float const value )
{
    int n;
    //std::cout << "Float constructor called" << std::endl;
    n = roundf(value * (1 << _bits));
    setRawBits(n);
}

Fixed::~Fixed( void ) {
    //std::cout << "Destructor called" << std::endl;
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
    //std::cout << "Assignation operator called" << std::endl;

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
    float val = getRawBits();
    return (val / (1 << this->_bits));
}

int Fixed::toInt( void ) const
{
    int val = getRawBits();
    return (val / (1 << this->_bits));
}

bool Fixed::operator>( Fixed const & rhs )
{
    if (this->_value > rhs.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator<( Fixed const & rhs )
{
    if (this->_value < rhs.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator>=( Fixed const & rhs )
{
    if (this->_value >= rhs.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator<=( Fixed const & rhs )
{
    if (this->_value <= rhs.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator==( Fixed const & rhs )
{
    if (this->_value == rhs.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator!=( Fixed const & rhs )
{
    if (this->_value != rhs.getRawBits())
        return true;
    else
        return false;
}

Fixed Fixed::operator+( Fixed const & rhs ) const
{
    Fixed res;

    res.setRawBits(this->_value + rhs._value);
    return res;
}

Fixed Fixed::operator-( Fixed const & rhs ) const
{
    Fixed res;

    res.setRawBits(this->_value - rhs._value);
    return res;
}

Fixed Fixed::operator*( Fixed const & rhs ) const
{
    Fixed res;

    res.setRawBits((this->_value * rhs._value) / (1 << this->_bits));
    return res;
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
    Fixed res;

    res.setRawBits((this->_value / rhs._value) / (1 << this->_bits));
    return res;
}

Fixed& Fixed::min( Fixed& lhs, Fixed& rhs )
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed& Fixed::max( Fixed& lhs, Fixed& rhs )
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed const & Fixed::min( Fixed const& lhs, Fixed const& rhs )
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed const & Fixed::max( Fixed const& lhs, Fixed const& rhs )
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed& Fixed::operator++( void )
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed res;

    res = *this;
    this->_value++;
    return res;
}

Fixed& Fixed::operator--( void )
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--( int )
{
    Fixed res;

    res = *this;
    this->_value--;
    return res;
}
