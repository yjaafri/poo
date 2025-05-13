#include "Case.h"

Case::Case() : herbe(true), sels(0), animal(nullptr) {}
bool Case::aHerbe() const { return herbe; }
int Case::getSels() const { return sels; }
Animal* Case::getAnimal() const { return animal; }
void Case::pousserHerbe() { if (!herbe && sels > 0) { herbe = true; sels = 0; } }
void Case::consommerHerbe() { herbe = false; }
void Case::ajouterSels(int qte) { sels += qte; }
void Case::setAnimal(Animal* a) { animal = a; }
void Case::retirerAnimal() { animal = nullptr; }