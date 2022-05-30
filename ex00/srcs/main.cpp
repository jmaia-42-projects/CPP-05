/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:51:16 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/30 13:29:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int	main(void)
{
	Bureaucrat	alice("Alice", 5);
	Bureaucrat	bob("Bob", 1);
	Bureaucrat	carol("Carol", 150);

	try
	{
		Bureaucrat	dave("Dave", 0); // This should throw exception
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.printException();
	}
	try
	{
		Bureaucrat	bureaucrat("Frank", 151); // This should throw exception
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.printException();
	}

	std::cout << alice.getName() << " " << alice.getGrade() << std::endl;
	std::cout << alice << std::endl;

	alice.incrementGrade(1);
	std::cout << alice << std::endl;
	alice.decrementGrade(1);
	std::cout << alice << std::endl;

	try
	{
		bob.incrementGrade(1); // This should throw an exception
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.printException();
	}
	try
	{
		carol.decrementGrade(1); // This should throw an exception
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.printException();
	}
}
