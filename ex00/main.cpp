/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:18:46 by blevrel           #+#    #+#             */
/*   Updated: 2023/01/10 17:17:17 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat	worker("Bob", 100);
		Bureaucrat	worker_cpy;

		worker_cpy = worker;
		worker.decrementGrade();
		worker_cpy.incrementGrade();
		std::cout << worker << std::endl;
		std::cout << worker_cpy << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat	worker1("Paul", 200);

		std::cout << worker1 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	worker2("Cynthia", 50);
		Bureaucrat	worker2_cpy(worker2);

		worker2.incrementGrade();
		worker2_cpy.decrementGrade();
		std::cout << worker2 << std::endl;
		std::cout << worker2_cpy << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	worker3("Sylvie", 1);

		worker3.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
