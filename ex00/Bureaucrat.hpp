/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:25:16 by blevrel           #+#    #+#             */
/*   Updated: 2022/12/12 12:24:08 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

class	Bureaucrat
{

private:

	std::string const	name;
	int					grade;

public:

	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(std::string _name, int _grade);
	std::string const	getName(void) const;
	int					getGrade(void) const;
	void				incrementGrade(void);
	void				decrementGrade(void);

};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & other);
