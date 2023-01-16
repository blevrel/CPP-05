/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:25 by blevrel           #+#    #+#             */
/*   Updated: 2022/12/14 18:41:23 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{

private:

	const std::string	target;

public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm & other);
	~PresidentialPardonForm(void);
	const std::string	getTarget(void) const;
	void				makeAction(void) const;
	PresidentialPardonForm & operator=(const PresidentialPardonForm & other);
	
};

#endif

