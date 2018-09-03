/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:36:14 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/14 08:36:16 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    Span sp = Span(5);
    sp.addNumber(10);
    sp.addNumber(15);
    sp.addNumber(16);
    sp.addNumber(23);
    sp.addNumber(72);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(12);
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::list<int> numbers;
    for (int i = 0; i < 10000; i++)
    {
        numbers.push_back(i);
    }
    std::cout << "List size: " << numbers.size() << std::endl;
    Span big = Span(10000);

    try
    {
    big.betterAddNumber(numbers);
    std::cout << big.shortestSpan() << std::endl;
    std::cout << big.longestSpan() << std::endl;
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
}
