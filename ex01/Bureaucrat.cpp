/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:26:04 by blevrel           #+#    #+#             */
/*   Updated: 2022/12/13 17:31:26 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Default_name")
{
	this->grade = 150;
	std::cout << "Bureaucrat default constructor called, grade automatically set to 150." << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw()
	: err_msg("[\033[31mERROR\033[0m] \033[35mGrade too high exception thrown\033[0m")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw()
	: err_msg("[\033[31mERROR\033[0m] \033[35mGrade too low exception thrown\033[0m")
{
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) : name(other.getName())
{
	this->grade = other.getGrade();
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = _grade;
	std::cout << "Bureaucrat constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}


Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::check_grade(int	from) const
{
	if (this->grade == 150 && from == 1)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade == 1 && from == 0)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::incrementGrade(void)
{
	this->check_grade(0);
	this->grade--;
	std::cout << this->name << " just got upgraded from grade "
	<< this->grade + 1 << " to " << this->grade << "." << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	this->check_grade(1);
	this->grade++;
	std::cout << this->name << " just got downgraded from grade "
	<< this->grade - 1 << " to " << this->grade << "." << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (this->err_msg.c_str());
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (this->err_msg.c_str());
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
	std::cout << "Impossible to copy name because it is declared as const." << std::endl;
	this->grade = other.getGrade();
	std::cout << "Bureaucrat assignment operator called." << std::endl;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (os);
}
