/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:15:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/31 15:33:43 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target):	Form(target, 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj):	Form(obj) { }

RobotomyRequestForm::~RobotomyRequestForm(void) { }

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	Form::operator=(obj);
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkCanExecute(executor);
	if (rand() % 2)
		std::cout << this->getName() << " has been robotomized" << std::endl;
	else
		std::cerr << "Robotomization failed" << std::endl;
}
