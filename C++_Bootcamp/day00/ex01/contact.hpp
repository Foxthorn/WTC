/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 06:44:07 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/05 06:44:56 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact 
{
    public:
            Contact( void );
            ~Contact( void );

            std::string firstname;
            std::string lastname;
            std::string nickname;
            std::string login;
            std::string postal;
            std::string email;
            std::string phone;
            std::string birthday;
            std::string meal;
            std::string underwear;
            std::string secret;
            int         created;        

            int     CreateContact();     
            void    DisplayInfo();
            void    SearchDisplay(int number);     
            void    Shorten(std::string str);                                        
};

#endif
