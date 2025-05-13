#include "Univers.h"
#include <iostream>
#include <algorithm> // pour std::shuffle
#include <random>    // pour std::default_random_engine

std::vector<std::pair<int, int>> Univers::casesAdjacentesLibres(int x, int y) const {
    std::vector<std::pair<int, int>> positions;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // pas la case actuelle
            int nx = x + dx;
            int ny = y + dy;
            if (estValide(nx, ny) && grille[nx][ny].getAnimal() == nullptr) {
                positions.push_back({nx, ny});
            }
        }
    }

    // mélanger les positions pour du hasard
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(positions.begin(), positions.end(), g);

    return positions;
}


Univers::Univers(int l, int c, int nbMoutons, int nbLoups)
    : lignes(l), colonnes(c), grille(l, std::vector<Case>(c)) {
    srand(time(0));

    // Placement des moutons
    for (int i = 0; i < nbMoutons; ++i) {
        int x, y;
        do {
            x = rand() % lignes;
            y = rand() % colonnes;
        } while (grille[x][y].getAnimal() != nullptr);

        char sexe = (rand() % 2 == 0) ? 'M' : 'F';
        Mouton* mouton = new Mouton(x, y, sexe, this);
        grille[x][y].setAnimal(mouton);
        animaux.push_back(mouton);
    }

    // Placement des loups
    for (int i = 0; i < nbLoups; ++i) {
        int x, y;
        do {
            x = rand() % lignes;
            y = rand() % colonnes;
        } while (grille[x][y].getAnimal() != nullptr);

        char sexe = (rand() % 2 == 0) ? 'M' : 'F';
        Loup* loup = new Loup(x, y, sexe, this);
        grille[x][y].setAnimal(loup);
        animaux.push_back(loup);
    }
}

Univers::~Univers() {
    for (auto a : animaux) delete a;
}

void Univers::afficher() const {
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            Animal* a = grille[i][j].getAnimal();
            if (a) std::cout << a->getType();
            else if (grille[i][j].aHerbe()) std::cout << "H";
            else std::cout << ".";
        }
        std::cout << std::endl;
    }
}

void Univers::tourDeJeu() {
    for (Animal* a : animaux) {
        if (a->estVivant()) {
            a->deplacer();
            a->manger();
            a->reproduire();
            a->vieillir();
        }
    }

    retirerAnimalMort();
}

Case& Univers::getCase(int x, int y) {
    return grille[x][y];
}

bool Univers::estValide(int x, int y) const {
    return x >= 0 && x < lignes && y >= 0 && y < colonnes;
}

void Univers::ajouterAnimal(Animal* a) {
    animaux.push_back(a);
    grille[a->getX()][a->getY()].setAnimal(a);
}

void Univers::retirerAnimalMort() {
    for (auto it = animaux.begin(); it != animaux.end(); ) {
        if (!(*it)->estVivant()) {
            grille[(*it)->getX()][(*it)->getY()].ajouterSels(1);
            grille[(*it)->getX()][(*it)->getY()].retirerAnimal();
            delete *it;
            it = animaux.erase(it);
        } else {
            ++it;
        }
    }
}
