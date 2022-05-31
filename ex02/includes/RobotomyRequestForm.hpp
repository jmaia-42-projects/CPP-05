/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:42:40 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/31 15:33:05 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>

# include "Bureaucrat.hpp"
# include "Form.hpp"

class	RobotomyRequestForm:	public Form
{
	private:
		RobotomyRequestForm(void);
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &obj);

		void	execute(Bureaucrat const &executor) const;
};

#endif
