/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:04:14 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/12 14:47:04 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INTERN_HPP
#define	INTERN_HPP
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	AForm;
class	Intern
{

public:

	Intern(void);
	~Intern(void);
	Intern(const Intern & other);
	AForm		*makeForm(std::string name, std::string target);
	Intern &	operator=(const Intern & other);

private:

	AForm	*(Intern::*f[3])(std::string target);
	AForm	*makeShrubbery(std::string target);
	AForm	*makeRobotomy(std::string target);
	AForm	*makePresidential(std::string target);

};

#endif
