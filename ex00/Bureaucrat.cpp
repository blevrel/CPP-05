/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:26:04 by blevrel           #+#    #+#             */
/*   Updated: 2022/12/12 12:24:26 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Default_name")
{
	this->grade = 150;
	std::cout << "Bureaucrat default constructor called, grade automatically set to 150" << std::endl;
}


Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	if (_grade > 151)
		throw _grade("Grade too high. Grade ranges from 1 to 150");
	else if (_grade < 0)
		throw _grade("Grade too low. Grade ranges from 1 to 150");
	this->grade = _grade;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string const	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	this->grade++;
}

Bureaucrat::GradeTooHighException
{
	
}

Bureaucrat::GradeTooLowException
{
	
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (os);
}
