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
#include <dlfcn.h>

Factory::Factory(Factory const & src) {
	*this = src;	
}

Factory::Factory(int width, int height) : _width(width), _height(height)
{
	this->_currentLibrary = SDL;
	CreateSDL();
}

Factory::~Factory()
{
	if (_currentLibrary)
		CloseLibrary(_graphicsInstance);
}

IFunctions *Factory::CreateLibrary(int library)
{
	if (library == _currentLibrary)
	{
		return (_graphicsInstance);
	}
	else
	{
		CloseLibrary(_graphicsInstance);
	}

	switch(library)
	{
		case SDL:
			return CreateSDL();
		case SFML:
			return CreateSFML();
		default:
			return NULL;
	}
}

Factory & Factory::operator=(Factory const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

void		Factory::CloseLibrary(IFunctions * graphicsInstance)
{
	if (!_dlHandle) throw Error::NoDLOpenException();

	void  (*destroy)(IFunctions *);
	destroy = (void(*)(IFunctions *))dlsym(_dlHandle, "deleteFunctions");
	if (!destroy) throw Error::DLError();

	destroy(graphicsInstance);
	dlclose(_dlHandle);
	_dlHandle = NULL;
	_currentLibrary = 0;
	_graphicsInstance = NULL;
}

IFunctions * Factory::CreateSDL()
{
	_dlHandle = dlopen("sdl/libsdl.dylib", RTLD_LAZY);
	if (!_dlHandle)
	{
		throw Error::OpeningDLException();
	}

	_currentLibrary = SDL;

	IFunctions *(*create)(void);
	create = (IFunctions *(*)())dlsym(_dlHandle, "createFunctions");
	if (!create)
	{
		throw Error::DLError();
	}

	this->_graphicsInstance = create();
	this->_graphicsInstance->Initialise(_width, _height);
	return this->_graphicsInstance;
}

IFunctions * Factory::CreateSFML()
{
	_dlHandle = dlopen("sfml/libsfml.dylib", RTLD_LAZY);
	if (!_dlHandle)
	{
		throw Error::OpeningDLException();
	}

	_currentLibrary = SFML;

	IFunctions *(*create)(void);
	create = (IFunctions *(*)())dlsym(_dlHandle, "createFunctions");
	if (!create)
	{
		throw Error::DLError();
	}

	this->_graphicsInstance = create();
	this->_graphicsInstance->Initialise(_width, _height);
	return this->_graphicsInstance;
}