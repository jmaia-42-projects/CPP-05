/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:02:05 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/31 15:21:53 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) { };

Bureaucrat::Bureaucrat(std::string name, unsigned int grade):	name(name)
{
	throwExceptionIfGradeInvalid(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &vogon)
{
	*this = vogon;
}

Bureaucrat::~Bureaucrat(void) { }

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &vogon)
{
	this->grade = vogon.grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::throwExceptionIfGradeInvalid(unsigned int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException(grade));
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException(grade));
}

void	Bureaucrat::incrementGrade(unsigned int amount)
{
	if (amount >= this->grade)
		throw (Bureaucrat::GradeTooHighException(0));
	this->grade -= amount;
}

void	Bureaucrat::decrementGrade(unsigned int amount)
{
	if (this->grade + amount > 150)
		throw (Bureaucrat::GradeTooLowException(this->grade + amount));
	this->grade += amount;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (Form::FormAlreadySignedException &e)
	{
		std::cerr << this->name << " couldn't sign " << form.getName() << " because form is already signed." << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << this->name << " couldn't sign " << form.getName() << " because grade is too low." << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (Form::IFormException &e)
	{
		e.printException();
	}
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &vogon)
{
	return (os << vogon.getName() << ", bureaucrat grade " << vogon.getGrade() << ".");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(unsigned int grade)
{
	this->grade = grade;
}

void	Bureaucrat::GradeTooHighException::printException(void)
{
	std::cerr << "Grade " << this->grade << " is too high !" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(unsigned int grade)
{
	this->grade = grade;
}

void	Bureaucrat::GradeTooLowException::printException(void)
{
	std::cerr << "Grade " << this->grade << " is too low !" << std::endl;
}
