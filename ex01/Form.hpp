/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:30:22 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/11 09:36:03 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;
class	Form
{

public:

	Form(void);
	~Form(void);
	Form(std::string name, int sign_req_grade, int exec_req_grade);
	Form(const Form & other);
	std::string	const &	getName(void) const;
	bool			  	getIsSigned(void) const;
	int const&			getSignReqGrade(void) const;
	int const&			getExecReqGrade(void) const;
	void				beSigned(Bureaucrat & other);
	Form &				operator=(const Form & other);

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
	bool				_is_signed;
	int const			_sign_req_grade;
	int const			_exec_req_grade;

};

std::ostream & operator<<(std::ostream & os, const Form & other);

#endif
