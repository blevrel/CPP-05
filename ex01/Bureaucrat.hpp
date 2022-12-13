/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:25:16 by blevrel           #+#    #+#             */
/*   Updated: 2022/12/13 17:26:37 by blevrel          ###   ########.fr       */
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
	Bureaucrat(const Bureaucrat & other);
	std::string			getName(void) const;
	int					getGrade(void) const;
	void				check_grade(int from) const;
	void				incrementGrade(void);
	void				decrementGrade(void);
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
};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & other);
