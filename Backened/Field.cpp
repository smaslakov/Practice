#include "Field.h"

int Field::calculateFieldStrength() const {
    int fieldStrength = 0;
    for(int i = 0; i < 2; i++){
        for (const Card& card : field[i]) {
            fieldStrength += card.getStrength();
        }
    }
    return fieldStrength;
}
