/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10/21/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/04 10/21/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

Factory::Factory()
{}

Factory::Factory(Factory const & src) {
	*this = src;	
}

Factory::Factory(int width, int height) : _width(width), _height(height)
{
	this->_currentLibrary = NONE;
}

Factory::~Factory() {}

Factory & Factory::operator=(Factory const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

void		Factory::CloseLibrary(IFunctions * graphicsInstance)
{
	if(!_dlhandle) 
	{
		throw Error::NoDLOpenException();
	}
	void (*destroy)(IFunctions *);
	destroy = (void (*)(IFunctions *))dlsym(_dlhandle, "deleteFunctions");
	if (!destroy) 
	{
		throw Error::DLError();
	}
	destroy(graphicsInstance);
	dlclose(_dlhandle);
	_dlhandle = NULL;
	_currentLibrary = NONE;
	_graphicsInstance = NULL;
}

IFunctions *Factory::CreateLibrary(int librabry)
{
	if (librabry == this->_currentLibrary)
	{
		return this->_graphicsInstance;
	}
	else if (this->_currentLibrary != NONE)
	{
		CloseLibrary(this->_graphicsInstance);
	}

	return CreateSDL();
}

IFunctions * Factory::CreateSDL()
{
	_dlhandle = dlopen("sdl/libsdl.dylib", RTLD_LAZY);
	if (!_dlhandle)
	{
		throw Error::OpeningDLException();
	}

	_currentLibrary = SDL;

	IFunctions *(*create)(void);
	create = (IFunctions *(*)())dlsym(_dlhandle, "createFunctions");
	if (!create)
	{
		throw Error::DLError();
	}

	this->_graphicsInstance = create();
	this->_graphicsInstance->Initialise(_width, _height);
	return this->_graphicsInstance;
}