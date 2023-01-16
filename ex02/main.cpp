/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:18:46 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/12 14:35:18 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat				worker("Sylvie", 1);
		Bureaucrat				worker_cpy;
		RobotomyRequestForm		form("Polo");

		worker_cpy = worker;
		std::cout << worker << std::endl;
		std::cout << worker_cpy << std::endl;
		std::cout << form << std::endl;

		form.beSigned(worker_cpy);
		worker.executeForm(form);

		std::cout << worker << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat				worker("Bob", 25);
		PresidentialPardonForm	form("Oscar");

		std::cout << worker << std::endl;
		std::cout << form << std::endl;

		form.beSigned(worker);
		form.execute(worker);

		std::cout << worker << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat				worker("John", 15);
		Bureaucrat				worker_cpy(worker);
		ShrubberyCreationForm	form("home");

		std::cout << worker << std::endl;
		std::cout << form << std::endl;

		form.beSigned(worker_cpy);
		worker.executeForm(form);

		std::cout << worker << std::endl;
		std::cout << form << std::endl;

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat				worker("Roberta", 150);
		ShrubberyCreationForm	form("home");

		std::cout << worker << std::endl;
		std::cout << form << std::endl;

		form.beSigned(worker);
		form.execute(worker);

		std::cout << worker << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() <<std::endl;
	}

	try
	{
		Bureaucrat				worker_sign("Roberto", 25);
		Bureaucrat				worker_exec("Mael", 5);
		PresidentialPardonForm	form("Travis");

		std::cout << worker_sign << std::endl;
		std::cout << worker_exec << std::endl;
		std::cout << form << std::endl;

		form.beSigned(worker_sign);
		form.execute(worker_exec);

		std::cout << worker_sign << std::endl;
		std::cout << worker_exec << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() <<std::endl;
	}


	return (0);
}
