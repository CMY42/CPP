/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedReplace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:29:45 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:29:45 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDREPLACE_HPP
#define SEDREPLACE_HPP

#include <string>

class SedReplace
{
public:
	static std::string replaceString(const std::string& str, const std::string& from, const std::string& to);
};

#endif
