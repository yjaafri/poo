#ifndef CASE_H
#define CASE_H

#include "Animal.h"

class Case {
private:
    bool herbe;
    int sels;
    Animal* animal;

public:
    Case();
    bool aHerbe() const;
    int getSels() const;
    Animal* getAnimal() const;
    void pousserHerbe();
    void consommerHerbe();
    void ajouterSels(int qte);
    void setAnimal(Animal* a);
    void retirerAnimal();
};

#endif