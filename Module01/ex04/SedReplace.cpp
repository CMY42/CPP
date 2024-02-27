/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedReplace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:29:42 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:29:42 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedReplace.hpp"

std::string SedReplace::replaceString(const std::string& str, const std::string& from, const std::string& to)
{
	std::string result = str;
	size_t start_pos = 0;
	while((start_pos = result.find(from, start_pos)) != std::string::npos) // Tant qu'on trouve from dans result
	{
		result.erase(start_pos, from.length()); // On supprime from
		result.insert(start_pos, to); // On insère to à la place de from
		start_pos += to.length(); // On avance le curseur pour éviter les boucles infinies si from et to sont identiques
	}
	return result;
}
