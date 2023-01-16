/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:38:10 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/12 13:41:18 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"

Form::Form(void)
	:	_name("Default_name"),
		_is_signed(false),
		_sign_req_grade(150),
		_exec_req_grade(150)
{
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
	:	_name(other.getName()),
		_is_signed(other.getIsSigned()),
		_sign_req_grade(other.getSignReqGrade()),
		_exec_req_grade(other.getExecReqGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string name, int sign_req_grade, int exec_req_grade)
	:	_name(name),
		_is_signed(false),
		_sign_req_grade(sign_req_grade),
		_exec_req_grade(exec_req_grade)
{
	if (sign_req_grade > 150 || exec_req_grade > 150)
		throw Form::GradeTooLowException();
	else if (sign_req_grade < 1 || exec_req_grade < 1)
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
	return (this->_name);
}

bool 	Form::getIsSigned(void) const
{
	return (this->_is_signed);
}

int const &	Form::getSignReqGrade(void) const
{
	return (this->_sign_req_grade);
}

int const &	Form::getExecReqGrade(void) const
{
	return (this->_exec_req_grade);
}

void	Form::beSigned(Bureaucrat & other)
{
	if (this->_is_signed == true && other.getGrade() <= this->getSignReqGrade())
		std::cout << other.getName() << " could not sign " << this->getName()
		<< " because it's already signed." << std::endl;
	else if (other.getGrade() <= this->getSignReqGrade())
	{
		this->_is_signed = true;
		std::cout << other.getName() << " signed " << this->_name << "." << std::endl;
	}
	else
	{
		std::cout << "\033[35m" << other.getName() << " could not sign " << this->getName()
		<< " because grade must be at least " << this->getSignReqGrade() << "\033[0m." << std::endl;
		throw Form::GradeTooLowException();
	}
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
	this->_is_signed = other.getIsSigned();
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
