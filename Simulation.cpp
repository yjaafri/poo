#include "Univers.h"
#include <iostream>

int main() {
    Univers univers(7, 7, 4, 2);
    for (int tour = 0; tour < 1000; ++tour) {
        std::cout << "\nTour " << tour << ":\n";
        univers.afficher();
        univers.tourDeJeu();
        std::cin.get();
    }
    return 0;
}