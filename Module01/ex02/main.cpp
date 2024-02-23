/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:21:02 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:26:10 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* ptr = &str; //pointeur pour pointer sur l'adresse de la variable str (contient l'adresse memoire ou est stocke str)
	std::string& ref = str; //reference liee a str. Une reference est un autre nom pour la meme variable, pas besoin de deferencement pour acceder a la valeur de la variable

	//affichage des adresses
	std::cout << "Address of the string variable: " << &str << std::endl;
	std::cout << "Address held by stringPTR: " << ptr << std::endl;
	std::cout << "Address held by stringREF: " << &ref << std::endl;

	// Affichage des valeurs
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *ptr << std::endl;
	std::cout << "Value pointed to by stringREF: " << ref << std::endl;

	return (0);
}
