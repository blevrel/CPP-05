/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:30:22 by blevrel           #+#    #+#             */
/*   Updated: 2022/12/13 18:17:22 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

class	Form
{

private:

	std::string const	 name;
	bool				is_signed;
	unsigned int const	sign_req_grade;
	unsigned int const	exec_req_grade;

public:

	Form(void);
	~Form(void);
	Form(std::string name, unsigned int sign_req_grade, unsigned int exec_req_grade);
	Form(const Form & other);
	std::string	const &	getName(void) const;
	bool			  	getIsSigned(void) const;
	unsigned int const&	getSignReqGrade(void) const;
	unsigned int const&	getExecReqGrade(void) const;
	Form &	operator=(const Form & other);

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
};

std::ostream & operator<<(std::ostream & os, const Form & other);
