#ifndef UNIVERS_H
#define UNIVERS_H

#include <vector>
#include <utility>
#include "Case.h"
#include "Mouton.h"
#include "Loup.h"

class Univers {
private:
    int lignes, colonnes;
    std::vector<std::vector<Case>> grille;
    std::vector<Animal*> animaux;

public:
    Univers(int l, int c, int nbMoutons, int nbLoups);
    ~Univers();

    void afficher() const;
    void tourDeJeu();

    Case& getCase(int x, int y);
    bool estValide(int x, int y) const;
    void ajouterAnimal(Animal* a);
    void retirerAnimalMort();

    // 🔽 C'est cette ligne qui manque chez toi !
    std::vector<std::pair<int, int>> casesAdjacentesLibres(int x, int y) const;
};

#endif
