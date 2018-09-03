/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06/19/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/08/06 06/19/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "TOperand.hpp"

Factory::Factory() 
{
	this->_functions[eOperandType::TypeInt8] = &Factory::createInt8;
	this->_functions[eOperandType::TypeInt16] = &Factory::createInt16;
	this->_functions[eOperandType::TypeInt32] = &Factory::createInt32;
	this->_functions[eOperandType::TypeFloat] = &Factory::createFloat;
	this->_functions[eOperandType::TypeDouble] = &Factory::createDouble;
}

Factory::Factory(Factory const & src)
{
	*this = src;
}

Factory::~Factory() {}

Factory & Factory::operator=(Factory const & src)
{
	if (this != &src) {
		*this = src;
    }
	return (*this);
}

IOperand const * Factory::createOperand(eOperandType type, std::string const & value)
{
	return ((this->*_functions[type])(value));
}

IOperand const * Factory::createInt8(std::string const & value)
{
	return new TOperand<int8_t, eOperandType::TypeInt8>(value);
}

IOperand const * Factory::createInt16(std::string const & value)
{
	return new TOperand<int16_t, eOperandType::TypeInt16>(value);
}

IOperand const * Factory::createInt32(std::string const & value)
{
	return new TOperand<int32_t, eOperandType::TypeInt32>(value);
}

IOperand const * Factory::createFloat(std::string const & value)
{
	return new TOperand<float, eOperandType::TypeFloat>(value);
}

IOperand const * Factory::createDouble(std::string const & value)
{
	return new TOperand<double, eOperandType::TypeDouble>(value);
}