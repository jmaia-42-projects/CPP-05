/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:28:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/30 16:59:13 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class	Bureaucrat;

#include "Form.hpp"

class	Bureaucrat
{
	private:
		std::string const	name;
		unsigned int		grade;

		Bureaucrat(void);

		void	throwExceptionIfGradeInvalid(unsigned int grade);
	public:
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &vogon);
		~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const &vogon);

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		void	incrementGrade(unsigned int amount);
		void	decrementGrade(unsigned int amount);
		void	signForm(Form &form);
		
		class	GradeTooHighException
		{
			private:
				unsigned int	grade;
			public:
				GradeTooHighException(unsigned int grade);

				void	printException(void);
		};
		class	GradeTooLowException 
		{
			private:
				unsigned int	grade;
			public:
				GradeTooLowException(unsigned int grade);

				void	printException(void);
		};
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &vogon);

#endif
