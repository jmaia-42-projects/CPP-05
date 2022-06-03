/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:40:58 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 10:42:11 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) { }

Intern::Intern(Intern const &obj)
{
	(void) obj;
}

Intern::~Intern(void) { }

Intern	&Intern::operator=(Intern const &obj)
{
	(void) obj;
	return (*this);
}

Form	*Intern::makeForm(std::string formName, std::string target)
{
	std::string	names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form		*(*forms[3])(std::string target) = {
		RobotomyRequestForm::create,
		PresidentialPardonForm::create,
		ShrubberyCreationForm::create
	};
	Form		*form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
			form = forms[i](target);
	}
	if (!form)
	{
		std::cerr << "Requested form " << formName << " does not exist !" << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << formName << std::endl;
	return (form);
}
