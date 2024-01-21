#include "Zombie.hpp"

int main() {
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie; // Important pour éviter les fuites de mémoire

    randomChump("StackZombie");

    return 0;
}
