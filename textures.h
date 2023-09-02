#ifndef TEXTURES_H
#define TEXTURES_H

#include <QString>

enum class Suit;
enum class Rank;

class Textures
{
public:
    Textures();

    void setPathToTexturePack(const QString &path);
    void setPathToBackCardsTextures(const QString &path);

    QString getCardTexture(int suit, int rank);
    QString getBackCardTexture() const;

private:
    QString m_pathToTexturePack;
    QString m_backCardsTextures;
    std::unordered_map<int, QString> cardName;

    int getCardId(int suit, int rank);
    void initializeCardMappings();
};

#endif // TEXTURES_H
