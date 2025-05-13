#ifndef LOUP_H
#define LOUP_H

#include "Animal.h"

class Loup : public Animal {
public:
    Loup(int x, int y, char sexe, Univers* univers);
    void deplacer() override;
    void manger() override;
    void reproduire() override;
    void vieillir() override;
    char getType() const override;
};

#endif