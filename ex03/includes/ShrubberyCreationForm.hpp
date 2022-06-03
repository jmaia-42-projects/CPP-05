/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:42:40 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 10:50:47 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <string>

# include "Form.hpp"

class	ShrubberyCreationForm:	public Form
{
	private:
		ShrubberyCreationForm(void);
	public:
		static Form	*create(std::string target);

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &obj);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &obj);

		void	execute(Bureaucrat const &executor) const;

		class	FileException:	public IFormException
		{
			private:
				std::string	fileName;
			public:
				FileException(std::string fileName);
				void	printException(void);
		};
};

#endif
