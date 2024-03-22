#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5); // push() pour ajouter un élément
	mstack.push(17);

	std::cout << mstack.top() << std::endl; // top() pour accéder au dernier élément
	mstack.pop(); // pop() pour enlever le dernier élément
	std::cout << mstack.size() << std::endl; // size() pour connaître le nombre d'éléments

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin(); // itérateur sur le premier élément
	MutantStack<int>::iterator ite = mstack.end(); // itérateur sur le dernier élément

	++it; // it++ pour avancer l'itérateur
	--it; // it-- pour reculer l'itérateur
	while (it != ite)
	{
		std::cout << *it << std::endl; // *it pour accéder à la valeur de l'élément pointé par l'itérateur
		++it;
	}

	std::stack<int> s(mstack);

	/*//test de la copie et de l'assignation
	std::cout << "-----" << std::endl;
	MutantStack<int> originalStack;
	originalStack.push(1);
	MutantStack<int> copiedStack(originalStack);
	MutantStack<int> assignedStack;
	assignedStack = originalStack;

	// Modifier l'original et afficher les valeurs pour vérifier l'indépendance des copies
	// On ajoute 2 à l'original, puis on affiche les trois stacks pour vérifier que les copies sont indépendantes
	originalStack.push(2);
	std::cout << "Original stack after modification:" << std::endl;
	for (MutantStack<int>::iterator it = originalStack.begin(); it != originalStack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Copied stack should remain unchanged:" << std::endl;
	for (MutantStack<int>::iterator it = originalStack.begin(); it != originalStack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Assigned stack should also remain unchanged:" << std::endl;
	for (MutantStack<int>::iterator it = originalStack.begin(); it != originalStack.end(); ++it)
		std::cout << *it << std::endl;*/

	// test avec std::list pour comparer
	std::cout << "-----" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
			std::cout << *it << std::endl;
	}
	return 0;
}
