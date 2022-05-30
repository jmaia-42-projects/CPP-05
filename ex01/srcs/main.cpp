/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:51:16 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/30 17:09:49 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int	main(void)
{
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

	/* *** EX01 *** */
	
	{
		Form	formA("Chicken liberation", 3, 5);
		Form	formB("Chicken liberation 2", 1, 150);
		try
		{
			Form	formC("Chicken liberation 3", 0, 150); // This should throw an exception
		}
		catch (Form::GradeTooHighException &e)
		{
			e.printException();
		}
		try
		{
			Form	formC("Chicken liberation 4", 1, 151); // This should throw an exception
		}
		catch (Form::GradeTooLowException &e)
		{
			e.printException();
		}
		try
		{
			Form	formC("Chicken liberation 5", 0, 151); // This should throw an exception
		}
		catch (Form::GradeTooHighException &e)
		{
			e.printException();
		}

		Bureaucrat	alice("alice", 2);
		Bureaucrat	bob("bob", 3);
		Bureaucrat	carol("carol", 4);

		carol.signForm(formA); // This should throw an exception
		bob.signForm(formA);
		alice.signForm(formA); // This should throw an exception
	}
}
