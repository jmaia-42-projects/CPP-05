/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:32:36 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/30 16:56:33 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class	Form;

# include "Bureaucrat.hpp"

class	Form
{
	private:
		std::string const	name;
		bool				isSigned;
		unsigned int const	signMinGrade;
		unsigned int const	execMinGrade;

		Form(void);
	public:
		Form(std::string const name, unsigned int const signMinGrade, unsigned int const execMinGrade);
		Form(Form const &obj);
		~Form(void);

		Form	&operator=(Form const &obj);

		std::string 	getName(void) const;
		bool			isFormSigned(void) const;
		unsigned int	getSignMinGrade(void) const;
		unsigned int	getExecMinGrade(void) const;

		void	beSigned(Bureaucrat const &vogon);

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
		class	FormAlreadySigned { };
};

std::ostream	&operator<<(std::ostream &os, Form const &obj);

#endif
