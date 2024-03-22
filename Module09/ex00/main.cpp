#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	exchange.loadPriceDatabase(); // Chargement de la base de données de prix depuis le fichier CSV par défaut "data.csv"
	exchange.processInputFile(argv[1]); // Traitement du fichier d'entrée

	return 0;
}

