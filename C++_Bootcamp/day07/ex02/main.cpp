/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 09:38:03 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/13 09:38:04 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Array.hpp"

int main()
{
    unsigned int num = 5;
    Array<int> a = Array<int>(num);

    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;

    std::cout << std::endl;
    std::cout << "a[0] : " << a[0] << std::endl;
    std::cout << "a[1] : " << a[1] << std::endl;
    std::cout << "a[2] : " << a[2] << std::endl;
    std::cout << "a[3] : " << a[3] << std::endl;
    std::cout << "a[4] : " << a[4] << std::endl;

    try
    {
        a[9] = 5;
    }
    catch (std::range_error e)
    {
        std::cout << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << std::endl;        
    }
}
