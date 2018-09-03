/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06/19/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/08/06 06/19/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include <limits>
#include <cstdint>
#include <cmath>

#include "TOperand.hpp"
#include "Factory.hpp"

template <typename T, eOperandType S>
TOperand<T, S>::TOperand()
{
    this->_precision = 0;
    this->_type = 0;
    this->_value = 0;
    this->_str = "0";
}

template <typename T, eOperandType S>
TOperand<T, S>::TOperand(TOperand const &src)
{
    if (this != &src)
    {
        *this = src;
    }
}

template <typename T, eOperandType S>
TOperand<T, S>::TOperand(std::string const & val) : _precision(S), _type(S)
{
    validateValue(val, S);
    std::size_t t;
    this->_value = static_cast<T>(std::stold(val, &t));
    this->_str = std::to_string(this->_value);
}

template <typename T, eOperandType S>
TOperand<T, S>::~TOperand(){}

template <typename T, eOperandType S>
void TOperand<T, S>::validateValue(std::string const & str, eOperandType type)
{
    std::size_t t;
    long double val = std::stold(str, &t);
    switch (type)
    {
        case eOperandType::TypeInt8 :
            if (val < INT8_MIN)
            {
                throw (Error::UnderFlow());
            }
            if (val > INT8_MAX)
            {
                throw (Error::OverFlow());
            }
            break;
        case eOperandType::TypeInt16 :
            if (val < INT16_MIN)
            {
                throw (Error::UnderFlow());
            }
            if (val > INT16_MAX)
            {
                throw (Error::OverFlow());
            }
            break;
        case eOperandType::TypeInt32 :
            if (val < INT32_MIN)
            {
                throw (Error::UnderFlow());
            }
            if (val > INT32_MAX)
            {
                throw (Error::OverFlow());
            }
            break;
        case eOperandType::TypeFloat :
            if (val < std::numeric_limits<float>::min())
            {
                throw (Error::UnderFlow());
            }
            if (val > std::numeric_limits<float>::max())
            {
                throw (Error::OverFlow());
            }
            break;
        case eOperandType::TypeDouble :
            if (val < std::numeric_limits<double>::min())
            {
                throw (Error::UnderFlow());
            }
            if (val > std::numeric_limits<double>::max())
            {
                throw (Error::OverFlow());
            }
            break;
    }
}

template <typename T, eOperandType S>
int TOperand<T, S>::getPrecision(void) const
{
    return (this->_precision);
}

template <typename T, eOperandType S>
eOperandType TOperand<T, S>::getType(void) const
{
    return (this->_type);
}

template <typename T, eOperandType S>
TOperand<T, S> & TOperand<T, S>::operator=(TOperand<T, S> const & src)
{
    if (this != &src)
    {
        this->_precision = src._precision;
        this->_type = src._type;
        this->_value = src._value;
    }
    return (*this);
}

template <typename T, eOperandType S>
IOperand const * TOperand<T, S>::operator+(IOperand const & rhs) const
{
    std::string ans;
    std::ostringstream convert;
    std::size_t t;
    long double temp = std::stold(rhs.toString(), &t);
    convert << (this->_value + temp);
    ans = convert.str();

    Factory factory;

    if (this->_precision < rhs.getPrecision())
    {
        return factory.createOperand(rhs.getType(), static_cast<std::string>(ans));
    }
    else
    {
        return factory.createOperand(this->_type, static_cast<std::string>(ans));
    }
}

template <typename T, eOperandType S>
IOperand const * TOperand<T, S>::operator-(IOperand const &rhs) const
{
    std::string ans;
    std::ostringstream convert;
    std::size_t t;
    long double temp = stold(rhs.toString(), &t);
    convert << (this->_value - temp);
    ans = convert.str();

    Factory factory;

    if (this->_precision < rhs.getPrecision())
    {
        return factory.createOperand(rhs.getType(), static_cast<std::string>(ans));
    }
    else
    {
        return factory.createOperand(this->_type, static_cast<std::string>(ans));
    }
}

template <typename T, eOperandType S>
IOperand const * TOperand<T, S>::operator*(IOperand const &rhs) const
{
    std::string ans;
    std::ostringstream convert;
    std::size_t t;
    long double temp = stold(rhs.toString(), &t);
    convert << (this->_value * temp);
    ans = convert.str();

    Factory factory;

    if (this->_precision < rhs.getPrecision())
    {
        return factory.createOperand(rhs.getType(), static_cast<std::string>(ans));
    }
    else
    {
        return factory.createOperand(this->_type, static_cast<std::string>(ans));
    }
}

template <typename T, eOperandType S>
IOperand const * TOperand<T, S>::operator/(IOperand const &rhs) const
{
    std::string ans;
    std::ostringstream convert;
    std::size_t t;
    long double temp = stold(rhs.toString(), &t);
    if (temp == static_cast<long double>(0)) {
        throw Error::DivBy0();
    }
    convert << (this->_value / temp);
    ans = convert.str();

    Factory factory;

    if (this->_precision < rhs.getPrecision())
    {
        return factory.createOperand(rhs.getType(), static_cast<std::string>(ans));
    }
    else
    {
        return factory.createOperand(this->_type, static_cast<std::string>(ans));
    }
}

template <typename T, eOperandType S>
IOperand const * TOperand<T, S>::operator%(IOperand const &rhs) const
{
    std::size_t t;
    long double temp = stold(rhs.toString(), &t);
    if (temp == static_cast<long double>(0)) {
        throw Error::DivBy0();
    }
    std::string ans = std::to_string(static_cast<T>(fmod(this->_value, temp)));
    Factory factory;

    if (this->_precision < rhs.getPrecision())
    {
        return factory.createOperand(rhs.getType(), static_cast<std::string>(ans));
    }
    else
    {
        return factory.createOperand(this->_type, static_cast<std::string>(ans));
    }
}

template <typename T, eOperandType S>
std::string const & TOperand<T, S>::toString(void) const
{
    return (this->_str);
}

template <typename T, eOperandType S>
T const TOperand<T, S>::getValue()
{
    return this->_value;
}
