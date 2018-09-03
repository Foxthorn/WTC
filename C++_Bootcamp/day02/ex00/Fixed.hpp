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

class Fixed
{
    public:
            Fixed( void );
            Fixed( Fixed const& src );
            ~Fixed( void );

            Fixed&  operator=( Fixed const &rhs );

            int     getRawBits( void ) const;
            void    setRawBits( int const raw );

    private:
            int                 _value;
            static int const    _bits = 8;

};

#endif
