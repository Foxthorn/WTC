/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 07:20:12 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/06 07:20:13 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
            Fixed( void );
            Fixed( Fixed const& src );
            Fixed( int const value );
            Fixed( float const value );
            ~Fixed( void );

            Fixed&  operator=( Fixed const &rhs );

            int         getRawBits( void ) const;
            void        setRawBits( int const raw );
            float       toFloat( void ) const;
            int         toInt( void ) const;

    private:
            int                 _value;
            static int const    _bits = 8;

};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif
