#include "Serializer.hpp"
#include <iostream>

//la méthode serialize convertit un pointeur Data* en un entier non signé de type uintptr_t en utilisant reinterpret_cast.
//La méthode deserialize fait l'opération inverse, convertissant un uintptr_t en un pointeur Data*.
//L'utilisation de reinterpret_cast est appropriée ici pour la conversion directe entre les types pointeur et les types entiers, ce qui est nécessaire pour la sérialisation et la désérialisation des pointeurs.
//uintptr_t est un type entier capable de stocker une adresse mémoire.
//Il est utilisé ici pour stocker l'adresse mémoire d'un objet Data, car il est garanti de pouvoir stocker une adresse mémoire sans perte de données.
//La sérialisation est le processus de conversion d'une structure de données ou d'un objet en un format (souvent une suite de bits) qui peut être stocké ou transmis et ensuite reconstruit.
//La désérialisation est le processus inverse : reconstruire l'objet à partir du format sérialisé.
int main()
{
	Data myData("Test info");

	uintptr_t raw = Serializer::serialize(&myData);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Original info: " << myData.info << std::endl;
	std::cout << "Deserialized info: " << ptr->info << std::endl;

	return 0;
}
