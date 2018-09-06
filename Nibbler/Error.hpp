/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:47:25 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/04 14:47:29 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

#include <stdexcept>

class Error
{
    public:
        class InitError : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Initialise Error";
            }
        };
        class DLError : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Error:: Dynamic Library Error";
            }
        };
        class CreateWindowException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Exception:: Occured during Window Creation";
            }
        };
        class CloseWindowException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Exception:: Occured during Window Closing";
            }
        };
        class NoDLOpenException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Exception:: Occured because no Dynamic Library was opened";
            }
        };
        class OpeningDLException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Exception:: Occured during opening of Dynamic Library";
            }
        };
        
};

#endif
