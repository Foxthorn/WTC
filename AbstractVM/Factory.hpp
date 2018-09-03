/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06/19/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/08/06 06/19/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
# define FACTORY_HPP

#include <iostream>
#include "IOperand.hpp"

class Factory
{
    private:
        IOperand const * (Factory::*_functions[5])(std::string const & value);
        IOperand const * createInt8(std::string const & value);
		IOperand const * createInt16(std::string const & value);
		IOperand const * createInt32(std::string const & value);
		IOperand const * createFloat(std::string const & value);
		IOperand const * createDouble(std::string const & value);

    public:
        Factory();
        Factory(Factory const & src);
        ~Factory();
        IOperand const * createOperand(eOperandType type, std::string const & value);
        Factory & operator=(Factory const & src);

};

#endif