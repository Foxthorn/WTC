/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:20:29 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/15 11:20:30 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "Brainfuck.hpp"

std::string openfile(char* filename)
{
    std::istream    file;
    file.open(filename);
    std::string code;
    std::string line;
    if (file.is_open())
    {
        while ( getline(file, line))
        {
            code += line;
        }
    }
    file.close();
    return code;
}

int main(int argc, char** argv)
{
    if (argc != 2)
        return 0;
    char* code = openfile(argv[1]);
    Brainfuck brainfuck(code);
}
