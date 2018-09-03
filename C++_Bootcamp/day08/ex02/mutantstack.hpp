/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutantstack.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09/56/01 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/14 09/56/01 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MUTANTSTACK_HPP
# define	MUTANTSTACK_HPP

#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>() {}
		MutantStack(MutantStack const & src) : _base(src._base) {}
		~MutantStack() {}

		typedef typename std::list<T>::iterator iterator;

		void		push(T num) {this->_base.push_front(num);}
		void		pop() {this->_base.pop_front();}
		T			top() {return this->_base.front();}
		T			size() {return this->_base.size();}

		iterator	begin() {return this->_base.begin();}
		iterator	end() {return this->_base.end();}

	private:
		std::list<T> _base;

};

#endif
