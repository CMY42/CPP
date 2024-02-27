/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:40:26 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:40:27 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl //pas de données membres
{
private :
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public :
	void complain(std::string level);
};

#endif
