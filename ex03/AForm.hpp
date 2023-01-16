/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:30:22 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/12 16:22:42 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm
{

public:

	AForm(void);
	virtual	~AForm(void);
	AForm(std::string name, int sign_req_grade, int exec_req_grade);
	AForm(const AForm & other);
	std::string	const &	getName(void) const;
	bool			  	getIsSigned(void) const;
	void			  	setIsSigned(bool isSigned);
	int const&			getSignReqGrade(void) const;
	int const&			getExecReqGrade(void) const;
	void				beSigned(Bureaucrat & other);
	void				execute(Bureaucrat const & executor) const;
	virtual void		makeAction(void) const = 0;
	AForm &				operator=(const AForm & other);

	class	GradeTooHighException : public std::exception
	{
		
	private:

		std::string	err_msg;

	public:

	const char	*what(void) const throw();
	GradeTooHighException(void) throw();
	~GradeTooHighException(void) throw();

	};

	class	FormNotSignedException : public std::exception
	{
		
	private:

		std::string	err_msg;

	public:

	const char	*what(void) const throw();
	FormNotSignedException(void) throw();
	~FormNotSignedException(void) throw();

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

std::ostream & operator<<(std::ostream & os, const AForm & other);

#endif
