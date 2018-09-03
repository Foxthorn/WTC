/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 08:08:15 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/13 08:08:17 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T>
void    iterate(T* array, unsigned int length, void (*f)(T))
{
    for (unsigned int i = 0; i < length; i++)
    {
        f(array[i]);
    }
}

template< typename T>
void printArg( T var)
{
    std::cout << var << std::endl;
}

int main( void )
{
    int nums[] = {1, 2, 3, 4, 5};

    ::iterate(nums, 5, ::printArg);

    return 0;
}
