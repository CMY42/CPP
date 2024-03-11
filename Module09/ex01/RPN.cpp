#include "RPN.hpp"

RPN::RPN() : stack() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : stack(other.stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		stack = other.stack;
	return *this;
}

void RPN::performOperation(const std::string& operation)
{
	if(stack.size() < 2) throw std::runtime_error("Not enough elements for operation");
	double second = stack.top(); stack.pop(); // Récupère le deuxième nombre de la pile et le retire
	double first = stack.top(); stack.pop(); // Récupère le premier nombre de la pile et le retire

	// Effectue l'opération
	if (operation == "+") stack.push(first + second); // Ajoute le résultat à la pile, additionne les deux nombres
	else if (operation == "-") stack.push(first - second); // Soustrait le deuxième nombre du premier et ajoute le résultat à la pile
	else if (operation == "*") stack.push(first * second); // Multiplie les deux nombres et ajoute le résultat à la pile
	else if (operation == "/") stack.push(first / second); // Divise le premier nombre par le deuxième et ajoute le résultat à la pile
	else throw std::runtime_error("Invalid operation");
}

double RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;
	while (iss >> token)
	{
		// Vérifie si le token est un nombre valide
		if (token.find_first_not_of("0123456789+-*/") != std::string::npos) // Si le token contient autre chose que des chiffres ou des opérateurs
			throw std::runtime_error("Error");

		if (isdigit(token[0]) || (token.length() == 1 && token.find_first_of("+-*/") != std::string::npos))// Si le token est un nombre ou un opérateur
		{
			// C'est un nombre, l'ajoute à la pile
			if (isdigit(token[0]))
				stack.push(std::stod(token));
			// C'est une opération, la performe
			else
				performOperation(token);
		}
		// Token invalidE
		else
			throw std::runtime_error("Error");
	}
	if (stack.size() != 1) throw std::runtime_error("Error"); // Si la pile contient plus d'un élément
	return stack.top();
}
