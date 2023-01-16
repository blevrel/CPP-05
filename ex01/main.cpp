/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:18:46 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/12 13:42:04 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Form	form("Form", 200, 5);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	worker("Michel de la compta", 100);
		Bureaucrat	worker1("Michel de la compta1", 150);
		Form		form("Form 1", 100, 1);
		Bureaucrat	worker_cpy(worker);

		std::cout << worker << std::endl;
		std::cout << form << std::endl;
		std::cout << worker_cpy << std::endl;
		form.beSigned(worker);
		form.beSigned(worker1);
		worker.signForm(form);
		form.beSigned(worker_cpy);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	worker("Bob", 150);
		Form		form("Form 2", 100, 1);
		Bureaucrat	worker_assign_cpy;

		worker_assign_cpy = worker;

		std::cout << worker << std::endl;
		std::cout << form << std::endl;
		std::cout << worker_assign_cpy << std::endl;
		for (int i = 0; i < 50; i++)
			worker_assign_cpy.incrementGrade();
		form.beSigned(worker_assign_cpy);
		form.beSigned(worker);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat	worker("Sylvie", 2);
		Form		form("Form 3", 1, 1);

		std::cout << worker << std::endl;
		std::cout << form << std::endl;
		form.beSigned(worker);
		worker.incrementGrade();
		form.beSigned(worker);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
