/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08/36/08 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/14 08/36/08 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <stdexcept>
#include <iostream>

Span::Span(unsigned int n) : _n(n)
{}

Span::Span(Span const & src) 
{
	*this = src;	
}

Span::~Span() 
{}

Span & Span::operator=(Span const & src) 
{
	if (this != &src)
		*this = src;
	return *this;
}

void	Span::addNumber(int num)
{
	if (this->_lst.size() == this->_n)
	{
		throw std::out_of_range("Container is full");
	}
	else
	{
		this->_lst.push_back(num);
		this->_lst.sort();
	}
}

int		Span::longestSpan()
{
	if (this->_lst.size() >= 2)
	{
		int diff = this->_lst.back() - this->_lst.front();
		return diff;
	}
	else
	{
		throw std::out_of_range("Container contains to few elements");
	}
}

int		Span::shortestSpan()
{
	int lowest = this->_lst.back() - this->_lst.front();
	std::list<int>::iterator it;
	std::list<int>::iterator temp;
	std::list<int>::iterator its;
	std::list<int>::iterator ite = this->_lst.end();
	for (it = this->_lst.begin(); it != ite; ++it)
	{
		temp = it;
		temp++;
		for (its = temp; its != ite; ++its)
		{
			if (*its - *it < lowest)
				lowest = *its - *it;
		}
	}
	return lowest;		
}

void	Span::betterAddNumber(std::list<int> numbers)
{
	if (numbers.size() > this->_n)
	{
		throw std::out_of_range("List size to big");
	}
	else
	{
		this->_lst = numbers;
		this->_lst.sort();
	}
}



