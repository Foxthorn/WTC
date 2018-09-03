/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 06:30:00 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 06:30:04 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace::std;

char ToUpperCase(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

int main (int ac, char **av)
{
    if (ac == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < ac; i++)
        {
            for (int j = 0; av[i][j]; j++)
            {
                cout << ToUpperCase(av[i][j]);
            }
        }
        cout << std::endl;
    }
    return 0;
}
