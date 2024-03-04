#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // std::rand et std::srand
#include <ctime> // std::time
#include <iostream>

//Permet de generer un objet de type A, B ou C de maniere aleatoire
Base *generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return nullptr; //plus sur que return 0;
}

//Permet d'identifier le type reel d'un objet de type A, B ou C
void identify(Base *p)
{
	if (dynamic_cast<A *>(p)) //dynamic_cast permet d'identifier le type reel d'un objet, car std::type_info est interdit
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

//Permet d'identifier le type reel d'un objet de type A, B ou C
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast &e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
}

//Dynamic_cast est une operation couteuse, mais elle est necessaire pour identifier le type reel d'un objet
//Permet de determiner le type reel d'un objet pointe par un pointeur ou une reference de base a l'execution
int main()
{
	std::srand(std::time(0)); // Initialise le générateur une seule fois	Base *base = generate();
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	return 0;
}
