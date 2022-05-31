/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:42:40 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/31 15:26:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>

# include "Form.hpp"

class	PresidentialPardonForm:	public Form
{
	private:
		PresidentialPardonForm(void);
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &obj);
		~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &obj);

		void	execute(Bureaucrat const &executor) const;
};

#endif
