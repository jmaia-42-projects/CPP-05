/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:15:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 10:52:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

Form	*PresidentialPardonForm::create(std::string target)
{
	return (new PresidentialPardonForm(target));
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):	Form(target, 25, 5) { }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj):	Form(obj) { }

PresidentialPardonForm::~PresidentialPardonForm(void) { }

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	Form::operator=(obj);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkCanExecute(executor);
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
