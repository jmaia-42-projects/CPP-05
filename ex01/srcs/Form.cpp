/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:41:07 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/30 17:07:46 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

Form::Form(void): signMinGrade(0), execMinGrade(0) { };

Form::Form(std::string const name, unsigned int const signMinGrade, unsigned int const execMinGrade): name(name), signMinGrade(signMinGrade), execMinGrade(execMinGrade)
{
	if (signMinGrade < 1 || execMinGrade < 1)
		throw (GradeTooHighException(signMinGrade < 1 ? signMinGrade : execMinGrade));
	if (signMinGrade < 1 || execMinGrade < 1)
		throw (GradeTooHighException(execMinGrade < 1 ? execMinGrade : execMinGrade));
}

Form::Form(Form const &obj):	name(obj.name), signMinGrade(obj.signMinGrade), execMinGrade(obj.execMinGrade) { }

Form::~Form(void) { }

Form	&Form::operator=(Form const &obj)
{
	(void) obj;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->name);
}

bool	Form::isFormSigned(void) const
{
	return (this->isSigned);
}

unsigned int	Form::getSignMinGrade(void) const
{
	return (this->signMinGrade);
}

unsigned int	Form::getExecMinGrade(void) const
{
	return (this->execMinGrade);
}

void	Form::beSigned(Bureaucrat const &vogon)
{
	if (this->isSigned)
		throw (Form::FormAlreadySigned());
	if (vogon.getGrade() > this->signMinGrade)
		throw (Form::GradeTooLowException(vogon.getGrade()));
	this->isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(unsigned int grade)
{
	this->grade = grade;
}

void	Form::GradeTooHighException::printException(void)
{
	std::cerr << "Grade " << this->grade << " is too high !" << std::endl;
}

Form::GradeTooLowException::GradeTooLowException(unsigned int grade)
{
	this->grade = grade;
}

void	Form::GradeTooLowException::printException(void)
{
	std::cerr << "Grade " << this->grade << " is too low !" << std::endl;
}
