/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:29:36 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:29:37 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedReplace.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inputFile(filename); // On ouvre le fichier en lecture
	if (!inputFile)
	{
		std::cerr << "Error opening input file" << std::endl;
		return 1;
	}

	std::ostringstream ss; // On lit le fichier en entier
	ss << inputFile.rdbuf(); // On lit le fichier en entier dans un stringstream
	std::string content = ss.str(); // On récupère le contenu du stringstream dans une string
	inputFile.close(); // On ferme le fichier

	content = SedReplace::replaceString(content, s1, s2); // On remplace s1 par s2 dans content

	std::ofstream outputFile(filename + ".replace"); // On ouvre le fichier en écriture
	if (!outputFile)
	{
		std::cerr << "Error creating output file" << std::endl;
		return 1;
	}

	outputFile << content; // On écrit le contenu de content dans le fichier
	outputFile.close(); // On ferme le fichier

	return 0;
}
