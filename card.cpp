#include "Card.h"

Card::Card(const std::string& name, int strength)
        : m_name(name), m_strength(strength) {}

const std::string& Card::getName() const {
    return m_name;
}

int Card::getStrength() const {
    return m_strength;
}