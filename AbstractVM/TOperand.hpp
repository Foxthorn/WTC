/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06/19/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/08/06 06/19/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOPERAND_HPP
# define TOPERAND_HPP

#include "IOperand.hpp"

template<typename T, eOperandType S>
class TOperand : public IOperand
{
    public:
        TOperand();
        TOperand(TOperand const & src);
        TOperand(std::string const & val);
        virtual ~TOperand();

        virtual int getPrecision(void) const;
        virtual eOperandType getType(void) const;
        virtual std::string const &toString(void) const;
        T const getValue();

        virtual TOperand & operator=(TOperand<T, S> const &src);  
        virtual IOperand const * operator+(IOperand const &rhs) const;
        virtual IOperand const * operator-(IOperand const &rhs) const;
        virtual IOperand const * operator*(IOperand const &rhs) const;
        virtual IOperand const * operator/(IOperand const &rhs) const;
        virtual IOperand const * operator%(IOperand const &rhs) const;

        void validateValue(std::string const & str, eOperandType type);
    
    private:
        T           _value;
        int         _precision;
        eOperandType      _type;
        std::string _str;
};

#include "TOperand.cpp"

#endif