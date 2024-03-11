#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream> // pour std::ifstream, permet d'ouvrir et de lire un fichier csv
#include <map> // pour std::map<std::string, double>, permet de stocker la date et le prix CONTAINER
#include <algorithm>
#include <sstream> // pour std::stringstream permet de parser les lignes du fichier csv
#include <stdexcept> // pour std::invalid_argument

//La std::map est un container qui stocke des éléments sous forme de paires clé-valeur.
//Permet d'associer directement une date spécifique (la clé, sous forme de std::string) à un prix du Bitcoin (la valeur, sous forme de double).
//Implente comme un arbre binaire de recherche, ce qui permet de stocker les éléments dans un ordre spécifique.
//La std::map est donc un container qui permet de stocker des éléments de manière ordonnée, et qui permet de rechercher des éléments de manière efficace.

class BitcoinExchange
{
public:
	BitcoinExchange();
	virtual ~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void loadPriceDatabase(const std::string &dbPath = "data.csv");
	double findPriceForDate(const std::string &date) const;
	void processInputFile(const std::string &inputPath);

private:
	std::map<std::string, double> priceDatabase; // date, prix, double car on manipule des prix
};

#endif
