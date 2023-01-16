/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:26:04 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/11 09:31:17 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	:	_name("Default_name"),
		_grade(150)
{
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

Bureaucrat::Bureaucrat(const Bureaucrat & other)
	:	_name(other.getName()),
		_grade(other.getGrade())
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:	_name(name),
		_grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
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
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::check_grade(int	from) const
{
	if (this->_grade == 150 && from == 1)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade == 1 && from == 0)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::incrementGrade(void)
{
	this->check_grade(0);
	this->_grade--;
	std::cout << this->_name << " just got upgraded from grade "
	<< this->_grade + 1 << " to " << this->_grade << "." << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	this->check_grade(1);
	this->_grade++;
	std::cout << this->_name << " just got downgraded from grade "
	<< this->_grade - 1 << " to " << this->_grade << "." << std::endl;
}

void	Bureaucrat::signForm(AForm & other)
{
	other.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
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
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = other.getGrade();
	std::cout << "Bureaucrat assignment operator called." << std::endl;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (os);
}
