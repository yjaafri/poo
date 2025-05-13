#include "Loup.h"
#include "Univers.h"
Loup::Loup(int x, int y, char sexe, Univers* univers)
    : Animal(x, y, sexe, univers) {}
void Loup::manger() {}
void Loup::reproduire() {}
void Loup::vieillir() { ++age; ++faim; if (age >= 60 || faim >= 11) mourir(); }
char Loup::getType() const { return 'L'; }
void Loup::deplacer() {
    auto casesLibres = univers->casesAdjacentesLibres(x, y);
    if (!casesLibres.empty()) {
        int nx = casesLibres[0].first;
        int ny = casesLibres[0].second;

        univers->getCase(x, y).retirerAnimal();
        setPosition(nx, ny);
        univers->getCase(nx, ny).setAnimal(this);
    }
}
