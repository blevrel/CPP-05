/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:38:10 by blevrel           #+#    #+#             */
/*   Updated: 2022/12/13 18:29:46 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"

Form::Form(void)
	: name("Default_name"), sign_req_grade(150), exec_req_grade(150)
{
	this->is_signed = false;
	std::cout << "Form default constructor called, all grade related values set to 150 by default." << std::endl;
}

Form::GradeTooHighException::GradeTooHighException(void) throw()
	: err_msg("[\033[31mERROR\033[0m] \033[35mForm grade too high exception thrown\033[0m")
{
}

Form::GradeTooLowException::GradeTooLowException(void) throw()
	: err_msg("[\033[31mERROR\033[0m] \033[35mForm grade too low exception thrown\033[0m")
{
}

Form::Form(const Form & other)
	: name(other.getName()),
	is_signed(other.getIsSigned()),
	sign_req_grade(other.getSignReqGrade()),
	exec_req_grade(other.getExecReqGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string _name, unsigned int _sign_req_grade, unsigned int _exec_req_grade)
	: name(_name),
	is_signed(false),
	sign_req_grade(_sign_req_grade),
	exec_req_grade(_exec_req_grade)
{
	if (_sign_req_grade > 150 || _exec_req_grade > 150)
		throw Form::GradeTooLowException();
	else if (_sign_req_grade < 1 || _exec_req_grade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form constructor called." << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

std::string const &	Form::getName(void) const
{
	return (this->name);
}

bool 	Form::getIsSigned(void) const
{
	return (this->is_signed);
}

unsigned int const &	Form::getSignReqGrade(void) const
{
	return (this->sign_req_grade);
}

unsigned int const &	Form::getExecReqGrade(void) const
{
	return (this->exec_req_grade);
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return (this->err_msg.c_str());
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return (this->err_msg.c_str());
}

Form & Form::operator=(const Form & other)
{
	this->is_signed = other.getIsSigned();
	std::cout << "Could not copy name and grade requirements because they are declared as const. Only IsSigned was copied" << std::endl;
	std::cout << "Form assignment operator called." << std::endl;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, const Form & other)
{
	std::string	isSigned;

	if (other.getIsSigned() == true)
		isSigned = "Signed";
	else
		isSigned = "Not signed";
	os << other.getName() << ". Form. " << isSigned << ". Grade required to sign is "
	<< other.getSignReqGrade() << ". Grade required to execute is "
	<< other.getExecReqGrade();
	return (os);
}
