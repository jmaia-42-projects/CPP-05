/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:15:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 10:52:22 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

Form	*ShrubberyCreationForm::create(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):	Form(target, 145, 137) { }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj):	Form(obj) { }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	Form::operator=(obj);
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	file;

	this->checkCanExecute(executor);
	file.open((this->getName() + "_shrubbery").c_str());
	file << 	"       ###\n"
					"      #o###\n"
					"    #####o###\n"
					"   #o#\\#|#/###\n"
					"    ###\\|/#o#\n"
					"     # }|{  #\n"
					"       }|{" << std::endl;
	if (!file)
		throw (ShrubberyCreationForm::FileException(this->getName() + "_shrubbery"));
}

ShrubberyCreationForm::FileException::FileException(std::string fileName)
{
	this->fileName = fileName;
}

void	ShrubberyCreationForm::FileException::printException(void)
{
	std::cerr << "An error occured while writing to file " << this->fileName << std::endl;
}
