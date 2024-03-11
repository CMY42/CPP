#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack> // pour std::stack<double>, permet de stocker les opérandes CONTAINER
#include <vector>
#include <sstream> // pour std::istringstream
#include <stdexcept> // pour std::runtime_error

// Reverse Polish Notation
// structure de std::stack<double> correspond à une pile de nombres, correspond donc naturellemtn a la notation polonaise inversée
// std::stack<double> stack est un conteneur de type LIFO (Last In First Out) qui permet de stocker les opérandes
// Les deux derniers nombres à avoir été ajoutés à la pile sont ceux sur lesquels l'opération doit être appliquée en premier.
// Les opérateurs sont appliqués aux deux derniers nombres ajoutés à la pile.
// Lorsqu'une opération est effectuée, les deux nombres utilisés sont retirés de la pile et le résultat est ajouté à la pile.
// Si une erreur survient, une exception de type std::runtime_error est lancée.

class RPN
{
public:
	RPN();
	virtual ~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	double evaluate(const std::string &expression);

private:
	void performOperation(const std::string &operation);
	std::stack<double> stack;
};

#endif
