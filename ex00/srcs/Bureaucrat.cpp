/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:02:05 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/30 13:26:45 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) { };

Bureaucrat::Bureaucrat(std::string name, unsigned int grade):	name(name)
{
	throwExceptionIfGradeInvalid(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
{
	*this = obj;
}

Bureaucrat::~Bureaucrat(void) { }

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &obj)
{
	this->grade = obj.grade;
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

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &obj)
{
	return (os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".");
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
