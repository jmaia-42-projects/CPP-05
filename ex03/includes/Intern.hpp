/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:21:06 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 10:33:09 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

# include "Form.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(Intern const &obj);
		~Intern(void);

		Intern	&operator=(Intern const &obj);

		Form	*makeForm(std::string formName, std::string target);
};

#endif
