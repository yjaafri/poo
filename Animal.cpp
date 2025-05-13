#include "Animal.h"

Animal::Animal(int x, int y, char sexe, Univers* univers)
    : x(x), y(y), age(0), faim(0), sexe(sexe), vivant(true), univers(univers) {}

bool Animal::estVivant() const { return vivant; }
int Animal::getX() const { return x; }
int Animal::getY() const { return y; }
char Animal::getSexe() const { return sexe; }
void Animal::setPosition(int newX, int newY) { x = newX; y = newY; }
void Animal::mourir() { vivant = false; }