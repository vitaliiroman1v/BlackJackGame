#include "textures.h"

#include <unordered_map>
#include "card.h"

Textures::Textures()
{
    setPathToTexturePack("/home/pypy/Downloads/Playing_Cards/PNG-cards-1.3/");
    setPathToBackCardsTextures("/home/pypy/Downloads/Playing_Cards/PNG-cards-1.3/red_joker.png");
    initializeCardMappings();
}

void Textures::setPathToTexturePack(const QString &path)
{
    m_pathToTexturePack = path;
}

void Textures::setPathToBackCardsTextures(const QString &path)
{
    m_backCardsTextures = path;
}

QString Textures::getCardTexture(int suit, int rank)
{
    if (m_pathToTexturePack.isEmpty())
        return {};
    QString result = m_pathToTexturePack +
                     (cardName[getCardId(suit,rank)]) +
                     ".png";
    return result;
}

QString Textures::getBackCardTexture() const
{
    return m_backCardsTextures;
}

int Textures::getCardId(int suit, int rank)
{
    return suit * 13 + rank;
}

void Textures::initializeCardMappings()
{
    std::vector<QString> suitString {"_of_hearts", "_of_diamonds", "_of_clubs", "_of_spades"};
    std::vector<QString> rankString {"2", "3", "4", "5", "6", "7", "8", "9", "10",
                              "jack", "queen", "king", "ace"};

    for (int suit = static_cast<int>(Suit::Hearts); suit <= static_cast<int>(Suit::Spades); ++suit)
    {
        for (int rank = static_cast<int>(Rank::Two); rank <= static_cast<int>(Rank::Ace); ++rank)
        {
            cardName[getCardId(suit, rank)] = rankString[rank] + suitString[suit];
        }
    }
}
