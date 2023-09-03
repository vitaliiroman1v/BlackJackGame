#pragma once

#include <memory>
#include <vector>

#include "card.hpp"

class Deck
{
public:
    Deck();

    void init();
    std::vector<std::unique_ptr<Card>>& getDeck();

private:
    std::vector<std::unique_ptr<Card>> m_deck;
};
