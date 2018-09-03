/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:41:52 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/14 07:41:54 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>

int main()
{
    std::list<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    try
    {
        std::cout << easyfind(lst, 4) << std::endl;
        std::cout << std::endl;        
    }
    catch (std::logic_error e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {
        std::cout << easyfind(lst, 6) << std::endl;
        std::cout << std::endl;        
    }
    catch (std::logic_error e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }
}