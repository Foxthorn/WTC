/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12:14:42 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/12 12:14:43 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate( void )
{
    int index = rand() % 3;
    if (index == 0)
    {
        Base * a = new A();
        return a;
    }
    else if (index == 1)
    {
        Base * b = new B();
        return b;
    } 
    else if (index == 2)
    {
        Base * c = new C();
        return c;
    }
    return NULL;
}

void    identify_from_pointer( Base * pointer)
{
    if (dynamic_cast<A *>(pointer) != NULL)
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(pointer) != NULL)
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(pointer) != NULL)
    {
        std::cout << "C" << std::endl;
    }
}

void    identify_from_reference( Base & p )
{
    if (dynamic_cast<A *>(&p) != NULL)
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(&p) != NULL)
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(&p) != NULL)
    {
        std::cout << "C" << std::endl;
    }
}

int main ()
{
    srand(time(NULL));
    Base * base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    return 0;
}
