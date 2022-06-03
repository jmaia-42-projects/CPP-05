/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:32:36 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 10:50:34 by jmaia            ###   ########.fr       */
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
		virtual ~Form(void);

		Form	&operator=(Form const &obj);

		std::string 	getName(void) const;
		bool			isFormSigned(void) const;
		unsigned int	getSignMinGrade(void) const;
		unsigned int	getExecMinGrade(void) const;

		void	beSigned(Bureaucrat const &vogon);

		void			checkCanExecute(Bureaucrat const &executor) const;
		virtual void	execute(Bureaucrat const &executor) const = 0;

		class	IFormException
		{
			public:
				virtual void	printException(void) = 0;
		};
		class	GradeTooHighException:	public IFormException
		{
			private:
				unsigned int	grade;
			public:
				GradeTooHighException(unsigned int grade);

				void	printException(void);
		};
		class	GradeTooLowException:	public IFormException
		{
			private:
				unsigned int	grade;
			public:
				GradeTooLowException(unsigned int grade);

				void	printException(void);
		};
		class	FormAlreadySignedException:	public IFormException
		{
			private:
			public:
				FormAlreadySignedException(void);
				void	printException(void);
		};
		class	FormNotSignedException:	public IFormException
		{
			private:
			public:
				FormNotSignedException(void);
				void	printException(void);
		};
};

std::ostream	&operator<<(std::ostream &os, Form const &obj);

#endif
