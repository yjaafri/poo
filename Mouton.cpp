#include "Mouton.h"
#include "Univers.h"
Mouton::Mouton(int x, int y, char sexe, Univers* univers)
    : Animal(x, y, sexe, univers) {}
void Mouton::manger() {}
void Mouton::reproduire() {}
void Mouton::vieillir() { ++age; ++faim; if (age >= 50 || faim >= 6) mourir(); }
char Mouton::getType() const { return 'M'; }
void Mouton::deplacer() {
    auto casesLibres = univers->casesAdjacentesLibres(x, y);
    if (!casesLibres.empty()) {
        int nx = casesLibres[0].first;
        int ny = casesLibres[0].second;

        univers->getCase(x, y).retirerAnimal();
        setPosition(nx, ny);
        univers->getCase(nx, ny).setAnimal(this);
    }
}
