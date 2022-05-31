/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:51:16 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/31 16:16:32 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <cstdlib>
#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

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
	
//	{
//		Form	formA("Chicken liberation", 3, 5);
//		Form	formB("Chicken liberation 2", 1, 150);
//		try
//		{
//			Form	formC("Chicken liberation 3", 0, 150); // This should throw an exception
//		}
//		catch (Form::GradeTooHighException &e)
//		{
//			e.printException();
//		}
//		try
//		{
//			Form	formC("Chicken liberation 4", 1, 151); // This should throw an exception
//		}
//		catch (Form::GradeTooLowException &e)
//		{
//			e.printException();
//		}
//		try
//		{
//			Form	formC("Chicken liberation 5", 0, 151); // This should throw an exception
//		}
//		catch (Form::GradeTooHighException &e)
//		{
//			e.printException();
//		}
//
//		Bureaucrat	alice("alice", 2);
//		Bureaucrat	bob("bob", 3);
//		Bureaucrat	carol("carol", 4);
//
//		carol.signForm(formA); // This should print an error
//		bob.signForm(formA);
//		alice.signForm(formA); // This should print an error
//	}
	
	/* *** EX02 *** */

	{
		srand(time(NULL));
		ShrubberyCreationForm	shrubberyForm("tests/test1");
		ShrubberyCreationForm	shrubberyForm3("tests/inacessible_subfolder/file");
		ShrubberyCreationForm	shrubberyForm4("tests/folder_with_no_write_perm/file");
		ShrubberyCreationForm	shrubberyForm5("tests/");
		ShrubberyCreationForm	shrubberyForm6("tests/i_am_a_file/hello");
		ShrubberyCreationForm	shrubberyForm7("tests/i_do_not_exist/hi");

		RobotomyRequestForm		robotomyForm("voila");

		PresidentialPardonForm	presidentialForm("target");

		Bureaucrat	megaVogon("MegaVogon", 1);
		Bureaucrat	largeCanExec("LargeVogon", 4);
		Bureaucrat	limitCanExec("LimitVogon", 5);
		Bureaucrat	cannotExec("CannotVogon", 6);

		megaVogon.executeForm(shrubberyForm); // Not signed, should print an error
		
		megaVogon.signForm(shrubberyForm);
		megaVogon.signForm(shrubberyForm3);
		megaVogon.signForm(shrubberyForm4);
		megaVogon.signForm(shrubberyForm5);
		megaVogon.signForm(shrubberyForm6);
		megaVogon.signForm(shrubberyForm7);

		megaVogon.signForm(robotomyForm);

		megaVogon.signForm(presidentialForm);

		megaVogon.executeForm(shrubberyForm);
		/* *** These tests should print an error *** */
		megaVogon.executeForm(shrubberyForm3);
		megaVogon.executeForm(shrubberyForm4);
		megaVogon.executeForm(shrubberyForm5);
		megaVogon.executeForm(shrubberyForm6);
		megaVogon.executeForm(shrubberyForm7);
		/* *** These tests should print an error *** */

		largeCanExec.executeForm(presidentialForm);
		limitCanExec.executeForm(presidentialForm);
		cannotExec.executeForm(presidentialForm); // This should print an error

		megaVogon.executeForm(robotomyForm);
	}
}
