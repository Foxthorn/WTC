/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06/19/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/08/06 06/19/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Actions.hpp"

Actions::Actions() {}

Actions::Actions(Actions const & src)
{
    *this = src;
}

Actions::~Actions() {}

void Actions::Push(eOperandType type, std::string value)
{
    this->_stack.push_back(this->_factory.createOperand(type, value));
}

void Actions::Delete(IOperand const *lhs, IOperand const *rhs, IOperand const *ans)
{
    delete lhs;
    delete rhs;
    delete ans;
}

void Actions::CheckEmptyStack()
{
    if (this->_stack.size() == 0) {
        throw Error::EmptyStack();
    }
}

void Actions::CheckSingleElement()
{
    if (this->_stack.size() == 1) {
        throw Error::OneElement();
    }
}

void Actions::Pop()
{
    if (this->_stack.size() == 0) {
        throw Error::EmptyStack();
    }

    delete this->_stack[this->_stack.size() - 1];
    this->_stack.pop_back();
}

void Actions::Add()
{
    CheckEmptyStack();
    CheckSingleElement();

    IOperand const *lhs = this->_stack[this->_stack.size() - 1];
    IOperand const *rhs = this->_stack[this->_stack.size() - 2];

    IOperand const *ans = *lhs + *rhs;
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(this->_factory.createOperand(ans->getType(), ans->toString()));
    Delete(lhs, rhs, ans);
}

void Actions::Sub()
{
    CheckSingleElement();
    CheckEmptyStack();

    IOperand const *lhs = this->_stack[this->_stack.size() - 1];
    IOperand const *rhs = this->_stack[this->_stack.size() - 2];

    IOperand const *ans = *lhs - *rhs;
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(this->_factory.createOperand(ans->getType(), ans->toString()));
    Delete(lhs, rhs, ans);
}

void Actions::Mul()
{
    CheckSingleElement();
    CheckEmptyStack();

    IOperand const *lhs = this->_stack[this->_stack.size() - 2];
    IOperand const *rhs = this->_stack[this->_stack.size() - 1];

    IOperand const *ans = *lhs * *rhs;
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(this->_factory.createOperand(ans->getType(), ans->toString()));
    Delete(lhs, rhs, ans);
}

void Actions::Div()
{
    CheckSingleElement();
    CheckEmptyStack();

    IOperand const *lhs = this->_stack[this->_stack.size() - 2];
    IOperand const *rhs = this->_stack[this->_stack.size() - 1];

    IOperand const *ans = *lhs / *rhs;
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(this->_factory.createOperand(ans->getType(), ans->toString()));
    Delete(lhs, rhs, ans);
}

void Actions::Mod()
{
    CheckSingleElement();
    CheckEmptyStack();

    IOperand const *lhs = this->_stack[this->_stack.size() - 2];
    IOperand const *rhs = this->_stack[this->_stack.size() - 1];

    IOperand const *ans = *lhs % *rhs;
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(this->_factory.createOperand(ans->getType(), ans->toString()));
    Delete(lhs, rhs, ans);
}

void Actions::Assert(eOperandType type, std::string const & value)
{
    CheckEmptyStack();

    IOperand const *last_element = this->_factory.createOperand(type, value);
    if (last_element->getType() != this->_stack[this->_stack.size() - 1]->getType()) {
        delete last_element;
        throw Error::InvalidType();
    }
    else if (last_element->toString().compare(this->_stack[this->_stack.size() - 1]->toString()) != 0) {
        delete last_element;
        throw Error::AssertNotTrue();
    }
    else if (last_element->getType() == this->_stack[this->_stack.size() - 1]->getType()) {
        std::cout << "True" << std::endl;
    }
}

void Actions::Print()
{
    CheckEmptyStack();

    if (this->_stack[this->_stack.size() - 1]->getType() == eOperandType::TypeInt8)
    {
        int i = std::stoi(this->_stack[this->_stack.size() - 1]->toString());
        std::cout << static_cast<char>(i) << std::endl;
    }
    else {
        throw Error::InvalidType();
    }
}

void Actions::Dump()
{
    CheckEmptyStack();
    std::cout << "\nSTART DUMP:" << std::endl;
    for (int i = static_cast<int>(this->_stack.size() - 1); i >= 0; i--)
    {
        std::cout << "- " << this->_stack[i]->toString() << std::endl;
    }
    std::cout << "END\n" << std::endl;
}