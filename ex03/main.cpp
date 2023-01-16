/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:18:46 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/12 16:39:41 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	AForm		*form;

	try
	{
		Bureaucrat	worker("Sylvie", 1);
		Bureaucrat	worker_cpy;
		Intern		intern;

		form = intern.makeForm("RobotomyRequestForm", "Polo");
		worker_cpy = worker;
		std::cout << worker << std::endl;
		std::cout << worker_cpy << std::endl;
		std::cout << *form << std::endl;

		form->beSigned(worker_cpy);
		worker.executeForm(*form);

		std::cout << worker << std::endl;
		std::cout << *form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	delete form;

	try
	{
		Bureaucrat	worker("Bob", 25);
		Intern		intern;

		form = intern.makeForm("PresidentialPardonForm", "Oscar");
		std::cout << worker << std::endl;
		std::cout << *form << std::endl;

		form->beSigned(worker);
		form->execute(worker);

		std::cout << worker << std::endl;
		std::cout << *form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	delete form;

	try
	{
		Bureaucrat				worker("John", 15);
		Intern		intern;
		Intern		intern_cpy(intern);

		form = intern_cpy.makeForm("ShrubberyCreationForm", "home");
		std::cout << worker << std::endl;
		std::cout << *form << std::endl;

		form->beSigned(worker);
		worker.executeForm(*form);

		std::cout << worker << std::endl;
		std::cout << *form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	delete form;

	try
	{
		Bureaucrat	worker("Roberta", 150);
		Intern		intern;
		Intern		intern_cpy;

		intern_cpy = intern;
		form = intern_cpy.makeForm("ShrubberyCreationForm", "home");
		std::cout << worker << std::endl;
		std::cout << *form << std::endl;

		form->beSigned(worker);
		form->execute(worker);

		std::cout << worker << std::endl;
		std::cout << *form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() <<std::endl;
	}

	delete form;

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
		std::cout << e.what() << std::endl;
	}

	try
	{
		Intern	intern;
		
		form = intern.makeForm("FormDoesntExist", "Test");
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
