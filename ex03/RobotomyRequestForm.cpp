/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:21:14 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/12 11:46:28 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	:	AForm("RobotomyRequestForm", 72, 45),
		_target("Default_target")
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:	AForm("RobotomyRequestForm", 72, 45),
		_target(target)

{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
	:	AForm("RobotomyRequestForm", 72, 45),
		_target(other.getTarget())
{
	this->setIsSigned(other.getIsSigned());
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}


RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
	this->setIsSigned(other.getIsSigned());
	std::cout << "Impossible to copy name, target and grade requirements because they are declared as consts" << std::endl;
	std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
	return (*this);
}

const std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::makeAction(void) const
{
	int	rand;

	std::srand(std::time(NULL));
	rand = std::rand() % 2;
	
	if (rand == 1)
			std::cout << "* drilling noises * " << this->getTarget() << " has been Robotomized successfully !" << std::endl;
		else
			std::cout << "Robotomy has failed." << std::endl;

}
