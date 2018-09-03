/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:37:53 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/12 11:37:57 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

int ConvertToInt(std::string str)
{
    std::stringstream s(str);
    int x = 0;
    s >> x;
    return x;
}

bool ContainsString(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (toupper(str[i]) >= 'A' && toupper(str[i]) <= 'Z')
            return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    int a = 0;
    if (argc != 2)
    {
        return 0;
    }
    if (ContainsString(argv[1]))
    {
           
    }
    else
    {
        a = ConvertToInt(argv[1]);
    }
    std::cout << a << std::endl;
    
}
