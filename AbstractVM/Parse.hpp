/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06/19/11 by cpauwels          #+#    #+#             */
/*   Updated: 2018/08/06 06/19/11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HPP
# define    PARSE_HPP

#include <iostream>
#include "Actions.hpp"

class Parse {

    public:
        Parse();
        Parse(Parse const & src);
        ~Parse();
        Parse & operator=(Parse const & src);

        void ReadFile(std::string const &str);
        void ReadInput();
        static void StrToUpper(std::string &str);

    private:
        int             SearchCommands(std::string operation);
        void            ParseCommand(eOperandType & type, std::string & value);
        void            CheckValid();
        void            CallAction(std::string command);
        void            CheckFileExtension(std::string filename);
        void            CheckValidValue(std::string value);
        std::string     GetOperation();
        std::string     GetDataType(int pos, std::string & value);
        std::string     GetValue(int pos);
        int             index_of(std::string type, int maxLength);
        void            SetType(int pos, eOperandType & type);
        std::string &   ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
        std::string &   rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
        std::string &   trim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
        
        std::string                 _command;
        std::vector<std::string>    _commands;
        bool                        _exception;

        Actions         _a;

};

#endif