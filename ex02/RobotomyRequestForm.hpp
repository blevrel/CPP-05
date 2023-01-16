/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:18:45 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/12 10:10:48 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{

public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm & other);
	~RobotomyRequestForm(void);
	const std::string	getTarget(void) const;
	void				makeAction(void) const;
	RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
	
private:

	const std::string	_target;

};

#endif
