/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06/19/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/08/06 06/19/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"

int main(int ac, char** av)
{
    Parse p;
    if (ac == 2)
    {   
        try {
            p.ReadFile(av[1]);
        }
        catch(std::exception &e) {
            std::cout << std::endl << e.what() << std::endl << std::endl;
        }
    }
    else {
        try {
            p.ReadInput();
        }
        catch(std::exception &e) {
            std::cout << std::endl << e.what() << std::endl << std::endl;
        }
    }
}