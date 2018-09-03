/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 07/30/51 by cpauwels         #+#    #+#              */
/*   Updated: 2018/06/12 07/30/51 by cpauwels        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef		INTERN_HPP
# define	INTERN_HPP

#include "Form.hpp"

class Intern 
{
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();

		Form * makeForm(std::string form, std::string target);
	
	private:

};

#endif
