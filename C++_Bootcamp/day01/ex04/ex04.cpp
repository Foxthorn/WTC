/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:07:00 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 11:07:02 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main ( void )
{
    std::string str = "HI THIS IS BRAIN";

    std::string* strPtr = &str;
    std::cout << *strPtr << std::endl;

    std::string& strRef = str;
    std::cout << strRef << std::endl;
}
