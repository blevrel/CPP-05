/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:01:12 by blevrel           #+#    #+#             */
/*   Updated: 2022/12/14 18:40:52 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	AForm("ShrubberyCreationForm", 145, 137),
		target("Default_target")
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
	:	AForm("ShrubberyCreationForm", 145, 137),
		target(_target)

{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other)
	:	AForm("ShrubberyCreationForm", 145, 137),
		target(other.getTarget())
{
	this->setIsSigned(other.getIsSigned());
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}


ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
	this->setIsSigned(other.getIsSigned());
	std::cout << "Impossible to copy name, target and grade requirements because they are declared as consts" << std::endl;
	std::cout << "ShrubberyCreationForm assignment operator called." << std::endl;
	return (*this);
}

const std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void	ShrubberyCreationForm::makeAction(void) const
{
	std::string	file_target;
	std::ofstream	fd_write;

	file_target = this->getTarget();
	file_target.append("_shrubbery");
	fd_write.open(file_target.c_str(), std::fstream::out);
	if (fd_write.fail() == true)
	{
		std::cout << "Failed to open file to draw tree" << std::endl;
		return ;
	}
	fd_write
	<< "				  # #### #####			 	# #### #####		"<< std::endl
	<< "				### }/#|### |/####		      ### }/#|### |/####	"<< std::endl
	<< "			      ##}/#/ }||/##/_/##/_#		    ##}/#/ }||/##/_/##/_#	"<< std::endl
	<< "			     ###  }/###|/ }/ # ###		   ###  }/###|/ }/ # ###	"<< std::endl
	<< "		           ##_}_#}_}## | #/###_/_####		 ##_}_#}_}## | #/###_/_####	"<< std::endl
	<< "		          ## #### # } #| /  #### ##/##	        ## #### # } #| /  #### ##/##	"<< std::endl
	<< "		           __#_--###`  |{,###---###-~	         __#_--###`  |{,###---###-~	"<< std::endl
	<< "				     } }{			 	   } }{		"<< std::endl
	<< "				      }}{				    }}{		"<< std::endl
	<< "				      }}{			 	    }}{		"<< std::endl
	<< "				      {{}				    {{}		"<< std::endl
	<< "				      `}				    `}			"<< std::endl;
	fd_write.close();
}

