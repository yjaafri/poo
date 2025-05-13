#ifndef ANIMAL_H
#define ANIMAL_H

class Univers;

class Animal {
protected:
    int x, y;
    int age;
    int faim;
    char sexe;
    bool vivant;
    Univers* univers;

public:
    Animal(int x, int y, char sexe, Univers* univers);
    virtual ~Animal() = default;

    virtual void deplacer() = 0;
    virtual void manger() = 0;
    virtual void reproduire() = 0;
    virtual void vieillir() = 0;
    virtual char getType() const = 0;

    bool estVivant() const;
    int getX() const;
    int getY() const;
    char getSexe() const;

    void setPosition(int newX, int newY);
    void mourir();
};

#endif