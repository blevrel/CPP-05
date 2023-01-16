/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:25:16 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/11 09:32:08 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "AForm.hpp"

class	AForm;
class	Bureaucrat
{

public:

	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(const Bureaucrat & other);
	std::string			getName(void) const;
	int					getGrade(void) const;
	void				check_grade(int from) const;
	void				incrementGrade(void);
	void				decrementGrade(void);
	void				signForm(AForm & other);
	void				executeForm(AForm const & form) const;
	Bureaucrat & 		operator=(const Bureaucrat & other);

	class	GradeTooHighException : public std::exception 
	{

	private:

		std::string	err_msg;
		
	public:
	
		const char	*what(void) const throw();
		GradeTooHighException(void) throw();
		 ~GradeTooHighException(void) throw();

	};

	class	GradeTooLowException : public std::exception 
	{

	private:

		std::string	err_msg;

	public:
	
		const char	*what(void) const throw();
		GradeTooLowException(void) throw();
		~GradeTooLowException(void) throw();

	};

private:

	std::string const	_name;
	int					_grade;

};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & other);

#endif
