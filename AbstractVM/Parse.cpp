/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06/19/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/08/06 06/19/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"
#include "Error.hpp"
#include <iostream>
#include <string>
#include <fstream>

Parse::Parse() {
    this->_exception = false;
}

Parse::Parse(Parse const & src)
{
	*this = src;	
}

Parse::~Parse() {}

Parse & Parse::operator=(Parse const & src)
{
	if (this != &src) {
		*this = src;
    }
	return (*this);
}

void    Parse::CheckFileExtension(std::string filename) 
{
    int pos = 0;
    for(int i = filename.length() - 1; i > 0; i--) {
        if (filename[i] == '.') {
            pos = i;
            break;
        }
    }
    std::string extension = "";
    for(int i = pos; i < (int)filename.length(); i++) {
        extension += filename[i];
    }
    if (extension != ".avm") {
        throw Error::LexicalError();
    }
}

void    Parse::ReadFile(std::string const &str)
{
    std::string command;
    CheckFileExtension(str);
    std::ifstream file(str);
    if (!file.good()) {
        throw Error::LexicalError();
    }
    while(std::getline(file, command))
    {
        if (command == "exit") {
            break;
        }
        else {
            CallAction(command);
        }
    }
}

void    Parse::ReadInput() 
{
    std::string command;
    while(true) {
        std::getline(std::cin, command);
        this->_commands.push_back(command);
        if (command == ";;") {
            break;
        }
        command.clear();
    }
    for(int i = 0; i < (int)this->_commands.size(); i++) {
        CallAction(this->_commands[i]);
    }
}

void Parse::StrToUpper(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++) {
		str[i] = std::toupper(str[i]);
	}
}

void Parse::CallAction(std::string command)
{
    try {
        StrToUpper(command);
        this->_command = trim(command);
        std::string operation = GetOperation();
        if (operation == "") {
            return;
        }
        int pos = SearchCommands(operation);
        eOperandType type;
        std::string value = "";
        if (pos == 0 || pos == 8) {
            ParseCommand(type, value);
        }
        if (this->_exception == true) {
            return;
        }
        switch(pos) {
            case 0:
                this->_a.Push(type, value);
                break;
            case 1:
                this->_a.Pop();
                break;
            case 2:
                this->_a.Add();
                break;
            case 3:
                this->_a.Sub();
                break;
            case 4:
                this->_a.Mul();
                break;
            case 5:
                this->_a.Div();
                break;
            case 6:
                this->_a.Mod();
                break;
            case 7:
                this->_a.Dump();
                break;
            case 8:
                this->_a.Assert(type, value);
                break;
            case 9:
                this->_a.Print();
                break;
            case 10:
                return;
        }
    }
    catch(std::exception &e) {
        this->_exception = true;
        std::cout << std::endl << command << " : " << e.what() << std::endl << std::endl;
    }
}

int     Parse::SearchCommands(std::string operation)
{
    std::string str[] = {"PUSH", "POP", "ADD", "SUB", "MUL", "DIV", "MOD", "DUMP", "ASSERT", "PRINT", ";;", "EXIT"};
    for (int i = 0; i < 12; i++) {
        if (operation == str[i]) {
            return i;
        }
    }
    throw (Error::Unknown());
}

std::string Parse::GetOperation()
{
    std::string operation = "";
    StrToUpper(this->_command);
    for(size_t i = 0; i < this->_command.length(); i++) {
        if (this->_command[i] == ' ' || this->_command[i] == ';') {
             break;
        }
        operation = operation + this->_command[i];
    }
    return operation;
}

std::string Parse::GetValue(int pos) 
{
    std::string value = "";
    for(size_t j = pos + 1; j < this->_command.length(); j++) {
        if (this->_command[j] == ')') {
            break;
        }
        else {
            value += this->_command[j];
        }
    }
    CheckValidValue(value);
    return value;
}

void        Parse::CheckValidValue(std::string value) 
{
    bool decimal = false;
    for(int i = 0; i < (int)value.length(); i++) {
        if (value[i] == '.') {
            if (decimal == true) {
                throw Error::LexicalError();
            }
            decimal = true;
        }
        else if (value[i] == '-') {
            if (i != 0) {
                throw Error::LexicalError();
            }
        }
        else if (!std::isdigit(static_cast<unsigned char>(value[i]))) {
            throw Error::LexicalError();
        }
    }
}

std::string Parse::GetDataType(int pos, std::string & value) 
{
    std::string dataType = "";
    for(size_t j = pos; j < this->_command.length(); j++) {
        if (j < this->_command.length() - 1 && this->_command[j + 1] == ' ') {
            throw Error::SyntaxError();
        }
        if (this->_command[j] == '(') {
            pos = j;
            break;
        }
        else {
            dataType += this->_command[j];
        }
    }
    value = GetValue(pos);
    return dataType;
}

int         Parse::index_of(std::string type, int maxLength)
{
    std::string types[] = {"INT8", "INT16", "INT32", "FLOAT", "DOUBLE"};
    for(size_t i = 0; i < (size_t)maxLength; i++) {
        if (type == types[i]) {
            return i;
        }
    }
    throw Error::InvalidType();
}

void        Parse::SetType(int i, eOperandType & type)
{
    if (i == 0) {
        type = eOperandType::TypeInt8;
    }
    else if (i == 1) {
        type = eOperandType::TypeInt16;
    }
    else if (i == 2) {
        type = eOperandType::TypeInt32;
    }
    else if (i == 3) {
        type = eOperandType::TypeFloat;
    }
    else if (i == 4) {
        type = eOperandType::TypeDouble;
    }
    else {
        throw Error::UnknownType();
    }
}

void        Parse::ParseCommand(eOperandType & type, std::string & value)
{
    CheckValid();
    for(size_t i = 0; i < this->_command.length(); i++) {
        if (this->_command[i] == ';') {
            value = "";
            return;
        }
        else if (this->_command[i] == ' ') {
            std::string dataType = GetDataType(i + 1, value);
            int num = index_of(dataType, 5);
            SetType(num, type);
            break;
        }
    }
    return;
}

std::string& Parse::ltrim(std::string& str, const std::string& chars)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
std::string& Parse::rtrim(std::string& str, const std::string& chars)
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
std::string& Parse::trim(std::string& str, const std::string& chars)
{
    return ltrim(rtrim(str, chars), chars);
}

void        Parse::CheckValid() {
    bool opening = false;
    bool closing = false;
    for(int i = 0; i < (int)this->_command.length(); i++) {
        if (this->_command[i] == '(') {
            opening = true;
        }
        if (this->_command[i] == ')') {
            closing = true;
        }
    }
    if (!closing || !opening) {
        throw Error::SyntaxError();
    }
}