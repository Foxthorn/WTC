/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 09:09:12 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/13 09:09:13 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

template< typename T>
class Array
{
    public:
        Array<T>() : _array(NULL), _size(0) {};

        Array<T>(unsigned int n) : _size(n)
        {
            if (_size == 0)
            {
                _array = NULL;
            }
            else
            {
                _array = new T[n];
            }
        }

        Array<T>(Array<T> const & src) : _array(NULL), _size(0)
        {
            if (this != &src)
                *this = src;
        }

        ~Array<T>() {};

        Array<T> & operator=(Array<T> const & rhs)
        {
            if (this != &rhs)
            {
                this->_size = rhs._size;
                this->_array = new T[rhs._size];
                for (unsigned int i = 0; i < this->_size; i++)
                {
                    this->_array[i] = rhs._array[i];
                }
            }
            return *this;
        }

        unsigned int    size()
        {
            return this->_size;
        }

        T & operator[](unsigned int num)
        {
            if (num < this->_size && num >= 0)
            {
                return this->_array[num];
            }
            else
            {
                throw std::range_error("Index out of range");
            }
        }

    private:
        T*              _array;
        unsigned int    _size;
};