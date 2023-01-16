/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:08:54 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/12 14:45:22 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Intern.hpp"

Intern::Intern(void)
{
	this->f[0] = (&Intern::makeShrubbery);
	this->f[1] = (&Intern::makeRobotomy);
	this->f[2] = (&Intern::makePresidential);
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern & other)
{
	(void)other;
	this->f[0] = (&Intern::makeShrubbery);
	this->f[1] = (&Intern::makeRobotomy);
	this->f[2] = (&Intern::makePresidential);
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	arr[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (name.compare(arr[i]) == 0)
		{
			std::cout << "Intern creates " << name << "." << std::endl;
			return ((this->*f[i])(target));
		}
	}
	std::cout << "Intern could not create " << name << " this type of form doesn't exist." << std::endl;
	return (NULL);
}

AForm	*Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Intern & Intern::operator=(const Intern & other)
{
	(void)other;
	this->f[0] = (&Intern::makeShrubbery);
	this->f[1] = (&Intern::makeRobotomy);
	this->f[2] = (&Intern::makePresidential);
	return (*this);
}
