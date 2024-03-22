#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : priceDatabase(other.priceDatabase) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		priceDatabase = other.priceDatabase;
	return *this;
}

void BitcoinExchange::loadPriceDatabase(const std::string& dbPath)
{
	std::ifstream file(dbPath);
	std::string line;
	while (getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		double price;
		if (getline(iss, date, ',') && iss >> price)
			priceDatabase[date] = price;
	}
}

double BitcoinExchange::findPriceForDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = priceDatabase.lower_bound(date);
	if (it != priceDatabase.begin() && (it == priceDatabase.end() || it->first != date))
		--it; // Utilise l'élément précédent si la date n'est pas trouvée
	return it->second;
}


void BitcoinExchange::processInputFile(const std::string& inputPath)
{
	std::ifstream file(inputPath);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file " + inputPath);
	std::string line, date, valueStr;
	getline(file, line); // Ignorer l'en-tête du fichier.

	while (getline(file, line))
	{
		std::istringstream stream(line);
		if (!(getline(stream, date, '|') >> std::ws && getline(stream, valueStr)))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date.erase(remove_if(date.begin(), date.end(), isspace), date.end()); // Nettoyage des espaces
		valueStr.erase(remove_if(valueStr.begin(), valueStr.end(), isspace), valueStr.end()); // Nettoyage des espaces

		// Vérifier si la date est au bon format (AAAA-MM-JJ)
		std::regex dateRegex("\\d{4}-\\d{2}-\\d{2}");
		if (!std::regex_match(date, dateRegex))
		{
			std::cerr << "Error: bad date format => " << date << std::endl;
			continue;
		}

		// Vérifier si la date est valide
		std::istringstream dateStream(date);
		int year, month, day;
		char dash;
		dateStream >> year >> dash >> month >> dash >> day;

		if (!dateStream || (month < 1 || month > 12) || (day < 1 || day > 31))
		{
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue;
		}

		try
		{
			float value = std::stof(valueStr);
			if (value < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			double price = findPriceForDate(date);
			std::cout << date << " => " << value << " = " << value * price << std::endl;
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Error: too large a number." << std::endl;
		}
	}
}

