/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:38:10 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/12 13:41:16 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AForm.hpp"

AForm::AForm(void)
	:	_name("Default_name"),
		_is_signed(false),
		_sign_req_grade(150),
		_exec_req_grade(150)
{
	std::cout << "AForm default constructor called, all grade related values set to 150 by default." << std::endl;
}

AForm::GradeTooHighException::GradeTooHighException(void) throw()
	: err_msg("[\033[31mERROR\033[0m] \033[35mAForm grade too high exception thrown\033[0m")
{
}

AForm::GradeTooLowException::GradeTooLowException(void) throw()
	: err_msg("[\033[31mERROR\033[0m] \033[35mAForm grade too low exception thrown\033[0m")
{
}

AForm::FormNotSignedException::FormNotSignedException(void) throw()
	: err_msg("[\033[31mERROR\033[0m] \033[35mAForm not signed exception thrown\033[0m")
{
}

AForm::AForm(const AForm & other)
	:	_name(other.getName()),
		_is_signed(other.getIsSigned()),
		_sign_req_grade(other.getSignReqGrade()),
		_exec_req_grade(other.getExecReqGrade())
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign_req_grade, int exec_req_grade)
	:	_name(name),
		_is_signed(false),
		_sign_req_grade(sign_req_grade),
		_exec_req_grade(exec_req_grade)
{
	if (sign_req_grade > 150 || exec_req_grade > 150)
		throw AForm::GradeTooLowException();
	else if (sign_req_grade < 1 || exec_req_grade < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm constructor called." << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

AForm::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

AForm::FormNotSignedException::~FormNotSignedException(void) throw()
{
}

std::string const &	AForm::getName(void) const
{
	return (this->_name);
}

void	AForm::setIsSigned(bool isSigned)
{
	this->_is_signed = isSigned;
}

bool 	AForm::getIsSigned(void) const
{
	return (this->_is_signed);
}

int const &	AForm::getSignReqGrade(void) const
{
	return (this->_sign_req_grade);
}

int const &	AForm::getExecReqGrade(void) const
{
	return (this->_exec_req_grade);
}

void	AForm::beSigned(Bureaucrat & other)
{
	if (this->_is_signed == true && other.getGrade() <= this->getSignReqGrade())
		std::cout << other.getName() << " could not sign " << this->getName()
		<< " because it's already signed." << std::endl;
	else if (other.getGrade() <= this->getSignReqGrade())
	{
		this->_is_signed = true;
		std::cout << other.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << "\033[35m" << other.getName() << " could not sign " << this->getName()
		<< " because grade must be at least " << this->getSignReqGrade() << "\033[0m." << std::endl;
		throw AForm::GradeTooLowException();
	}
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->_exec_req_grade && this->getIsSigned() == true)
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		this->makeAction();
	}
	else if (executor.getGrade() > this->_exec_req_grade)
	{
		std::cout << "\033[35m" << executor.getName() << " could not execute " << this->getName() << ", grade too low\033[0m" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return (this->err_msg.c_str());
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return (this->err_msg.c_str());
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
	return (this->err_msg.c_str());
}

AForm & AForm::operator=(const AForm & other)
{
	this->_is_signed = other.getIsSigned();
	std::cout << "Could not copy name and grade requirements because they are declared as const. Only is_signed was copied" << std::endl;
	std::cout << "AForm assignment operator called." << std::endl;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, const AForm & other)
{
	std::string	isSigned;

	if (other.getIsSigned() == true)
		isSigned = ". Signed";
	else
		isSigned = ". Not signed";
	os << other.getName() << isSigned << ". Grade required to sign is "
	<< other.getSignReqGrade() << ". Grade required to execute is "
	<< other.getExecReqGrade();
	return (os);
}
