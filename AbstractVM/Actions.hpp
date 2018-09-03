/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06/19/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/08/06 06/19/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_HPP
# define ACTIONS_HPP

#include <vector>
#include "IOperand.hpp"
#include "Factory.hpp"

class Actions
{
    public:
        Actions();
        Actions(Actions const & src);
        ~Actions();
        void Push(eOperandType type, std::string value);
        void Pop();
        void Add();
        void Sub();
        void Mul();
        void Div();
        void Mod();
        void Print();
        void Assert(eOperandType type, std::string const & value);
        void Dump();

    private:
        Factory                         _factory;
        std::vector<IOperand const *>   _stack;
        void    Delete(IOperand const *lhs, IOperand const *rhs, IOperand const *ans);
        void    CheckEmptyStack();
        void    CheckSingleElement();
};

#endif