#ifndef CARD_H
#define CARD_H
#pragma once
#include <string>
class Card {
public:
    Card(const std::string& name, int strength);

    const std::string& getName() const;
    int getStrength() const;

private:
    std::string m_name;
    int m_strength;
};

#endif // CARD_H