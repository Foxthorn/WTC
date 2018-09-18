/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13/15/44 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/07 13/15/44 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <unistd.h>

Functions::Functions() 
{
	if (!glfwInit())
		throw Error::InitError();
}

Functions::Functions(Functions const & src) {
	*this = src;	
}

Functions::~Functions() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glfwDestroyWindow(this->_window);
	glfwTerminate();
}

Functions & Functions::operator=(Functions const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

void	Functions::Initialise(int width, int height)
{
	this->_window = glfwCreateWindow(width, height, "Nibbler OPENGL", NULL, NULL);
	if (!_window) throw Error::CreateWindowException();

	glfwMakeContextCurrent(_window);

	this->_height = height;
	this->_width = width;
	this->_rows = height / BLOCK_SIZE;
	this->_columns = width / BLOCK_SIZE;
}

bool	Functions::Event()
{
	glfwPollEvents();
	if (Key() != Keys::NO_KEY || glfwWindowShouldClose(this->_window))
		return true;
	return false;
}

void	Functions::Draw(int x, int y, float r, float g, float b)
{
	glColor3f(static_cast<float>(r) / 255, static_cast<float>(g) / 255, static_cast<float>(b) / 255);
	float xf = static_cast<float>(x - static_cast<int>(this->_width >> 1)) / static_cast<float>(this->_width >> 1);
	float yf = static_cast<float>(static_cast<int>(this->_height >> 1) - y) / static_cast<float>(this->_height >> 1);
	float xf1 = static_cast<float>(x + BLOCK_SIZE - static_cast<int>(this->_width >> 1)) / static_cast<float>(this->_width >> 1);
	float yf1 = static_cast<float>(static_cast<int>(this->_height >> 1) - y - BLOCK_SIZE) / static_cast<float>(this->_height >> 1);

	glBegin(GL_QUADS);
	glVertex2f(xf1, yf);
	glVertex2f(xf, yf);
	glVertex2f(xf, yf1);
	glVertex2f(xf1, yf1);
	glEnd();
}

void	Functions::Render(std::vector<std::vector<int>> & map)
{
	int width;
	int height;
	glfwGetFramebufferSize(this->_window, &width, &height);
	glViewport(0, 0, width, height);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int col = 0; col < this->_columns; col++)
	{
		for (int row = 0; row < this->_rows; row++)
		{
			if (map[row][col] == SNAKE_BODY)
			{
				Draw(col * BLOCK_SIZE, row * BLOCK_SIZE, 255, 0, 0);
			}
			else if (map[row][col] == SNAKE_HEAD)
			{
				Draw(col * BLOCK_SIZE, row * BLOCK_SIZE, 0, 255, 0);
			}
			else if (map[row][col] == FOOD)
			{
				Draw(col * BLOCK_SIZE, row * BLOCK_SIZE, 0, 0, 255);
			}
			else if (map[row][col] == SPECIAL_FOOD)
			{
				Draw(col * BLOCK_SIZE, row * BLOCK_SIZE, 255, 223, 0);
			}
		}
	}
	glfwSwapBuffers(this->_window);
}

Keys	Functions::Key()
{
	if (glfwGetKey(this->_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(this->_window, true);
		return Keys::ESC_KEY;
	}
	else if (glfwGetKey(this->_window, GLFW_KEY_1) == GLFW_PRESS)
		return Keys::KEY_1;
	else if (glfwGetKey(this->_window, GLFW_KEY_2) == GLFW_PRESS)
		return Keys::KEY_2;
	else if (glfwGetKey(this->_window, GLFW_KEY_3) == GLFW_PRESS)
		return Keys::KEY_3;
	else if (glfwGetKey(this->_window, GLFW_KEY_UP) == GLFW_PRESS)
		return Keys::UP_KEY;
	else if (glfwGetKey(this->_window, GLFW_KEY_DOWN) == GLFW_PRESS)
		return Keys::DOWN_KEY;
	else if (glfwGetKey(this->_window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		return Keys::RIGHT_KEY;
	else if (glfwGetKey(this->_window, GLFW_KEY_LEFT) == GLFW_PRESS)
		return Keys::LEFT_KEY;
	return Keys::NO_KEY;
}

void	Functions::Sleep(int sleep)
{
	int updated = sleep * 1000;
	usleep(updated);
}

bool	Functions::Close()
{
	if (glfwWindowShouldClose(this->_window))
	{
		return true;
	}
	return false;
}

Functions * createFunctions()
{
	return new Functions();
}

void deleteFunctions(Functions * func)
{
	delete func;
}