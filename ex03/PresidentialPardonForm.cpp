/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:47:16 by blevrel           #+#    #+#             */
/*   Updated: 2022/12/14 18:41:15 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	:	AForm("PresidentialPardonForm", 25, 5),
		target("Default_target")
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
	:	AForm("PresidentialPardonForm", 25, 5),
		target(_target)

{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other)
	:	AForm("PresidentialPardonForm", 25, 5),
		target(other.getTarget())
{
	this->setIsSigned(other.getIsSigned());
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}


PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
	this->setIsSigned(other.getIsSigned());
	std::cout << "Impossible to copy name, target and grade requirements because they are declared as consts" << std::endl;
	std::cout << "PresidentialPardonForm assignment operator called." << std::endl;
	return (*this);
}

const std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void	PresidentialPardonForm::makeAction(void) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox."
	<< std::endl;
}
