/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:18:46 by blevrel           #+#    #+#             */
/*   Updated: 2022/12/13 18:31:56 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
			//empecher les negatifs ?
		Form	form("Life insurance", 150, -1);

		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
/*	try
	{
		Bureaucrat	worker("Bob", 100);

		worker.decrementGrade();
		std::cout << worker << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat	worker1("Paul", 200);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	worker2("Cynthia", 50);

		worker2.incrementGrade();
		std::cout << worker2 << std::endl;
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
	}*/
	return (0);
}
