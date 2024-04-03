#ifndef FIELD_H
#define FIELD_H
#pragma once
#include <vector>
#include "Card.h"
class Field {
public:
    std::vector<Card> field[2];
    int calculateFieldStrength() const;
    int fieldStrength = 0;
private:

};

#endif // FIELD_H