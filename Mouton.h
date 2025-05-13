#ifndef MOUTON_H
#define MOUTON_H

#include "Animal.h"

class Mouton : public Animal {
public:
    Mouton(int x, int y, char sexe, Univers* univers);
    void deplacer() override;
    void manger() override;
    void reproduire() override;
    void vieillir() override;
    char getType() const override;
};

#endif