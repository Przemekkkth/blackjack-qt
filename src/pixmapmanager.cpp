#include "pixmapmanager.h"

PixmapManager* PixmapManager::ptr = nullptr;

PixmapManager *PixmapManager::Instance()
{
    if(!ptr)
    {
        ptr = new PixmapManager();
    }
    return ptr;
}

QPixmap& PixmapManager::getPixmap(TextureID id)
{
    return m_textures.get(id);
}

QPixmap &PixmapManager::getPixmap(QString suit, int rank)
{
    if (suit == QStringLiteral("spade") ) {
        if (rank == 1) {
            return m_textures.get(TextureID::ace_spade);
        }
        else if (rank == 2) {
            return m_textures.get(TextureID::_2_spade);
        }
        else if (rank == 3) {
            return m_textures.get(TextureID::_3_spade);
        }
        else if (rank == 4) {
            return m_textures.get(TextureID::_4_spade);
        }
        else if (rank == 5) {
            return m_textures.get(TextureID::_5_spade);
        }
        else if (rank == 6) {
            return m_textures.get(TextureID::_6_spade);
        }
        else if (rank == 7) {
            return m_textures.get(TextureID::_7_spade);
        }
        else if (rank == 8) {
            return m_textures.get(TextureID::_8_spade);
        }
        else if (rank == 9) {
            return m_textures.get(TextureID::_9_spade);
        }
        else if (rank == 10) {
            return m_textures.get(TextureID::_10_spade);
        }
        else if (rank == 11) {
            return m_textures.get(TextureID::jack_spade);
        }
        else if (rank == 12) {
            return m_textures.get(TextureID::queen_spade);
        }
        else if (rank == 13) {
            return m_textures.get(TextureID::king_spade);
        }
    }
    else if (suit == QStringLiteral("heart")) {
        if (rank == 1) {
            return m_textures.get(TextureID::ace_heart);
        }
        else if (rank == 2) {
            return m_textures.get(TextureID::_2_heart);
        }
        else if (rank == 3) {
            return m_textures.get(TextureID::_3_heart);
        }
        else if (rank == 4) {
            return m_textures.get(TextureID::_4_heart);
        }
        else if (rank == 5) {
            return m_textures.get(TextureID::_5_heart);
        }
        else if (rank == 6) {
            return m_textures.get(TextureID::_6_heart);
        }
        else if (rank == 7) {
            return m_textures.get(TextureID::_7_heart);
        }
        else if (rank == 8) {
            return m_textures.get(TextureID::_8_heart);
        }
        else if (rank == 9) {
            return m_textures.get(TextureID::_9_heart);
        }
        else if (rank == 10) {
            return m_textures.get(TextureID::_10_heart);
        }
        else if (rank == 11) {
            return m_textures.get(TextureID::jack_heart);
        }
        else if (rank == 12) {
            return m_textures.get(TextureID::queen_heart);
        }
        else if (rank == 13) {
            return m_textures.get(TextureID::king_heart);
        }
    }
    else if (suit == QStringLiteral("diamond")) {
        if (rank == 1) {
            return m_textures.get(TextureID::ace_diamond);
        }
        else if (rank == 2) {
            return m_textures.get(TextureID::_2_diamond);
        }
        else if (rank == 3) {
            return m_textures.get(TextureID::_3_diamond);
        }
        else if (rank == 4) {
            return m_textures.get(TextureID::_4_diamond);
        }
        else if (rank == 5) {
            return m_textures.get(TextureID::_5_diamond);
        }
        else if (rank == 6) {
            return m_textures.get(TextureID::_6_diamond);
        }
        else if (rank == 7) {
            return m_textures.get(TextureID::_7_diamond);
        }
        else if (rank == 8) {
            return m_textures.get(TextureID::_8_diamond);
        }
        else if (rank == 9) {
            return m_textures.get(TextureID::_9_diamond);
        }
        else if (rank == 10) {
            return m_textures.get(TextureID::_10_diamond);
        }
        else if (rank == 11) {
            return m_textures.get(TextureID::jack_diamond);
        }
        else if (rank == 12) {
            return m_textures.get(TextureID::queen_diamond);
        }
        else if (rank == 13) {
            return m_textures.get(TextureID::king_diamond);
        }
    }
    else if (suit == QStringLiteral("club")) {
        if (rank == 1) {
            return m_textures.get(TextureID::ace_club);
        }
        else if (rank == 2) {
            return m_textures.get(TextureID::_2_club);
        }
        else if (rank == 3) {
            return m_textures.get(TextureID::_3_club);
        }
        else if (rank == 4) {
            return m_textures.get(TextureID::_4_club);
        }
        else if (rank == 5) {
            return m_textures.get(TextureID::_5_club);
        }
        else if (rank == 6) {
            return m_textures.get(TextureID::_6_club);
        }
        else if (rank == 7) {
            return m_textures.get(TextureID::_7_club);
        }
        else if (rank == 8) {
            return m_textures.get(TextureID::_8_club);
        }
        else if (rank == 9) {
            return m_textures.get(TextureID::_9_club);
        }
        else if (rank == 10) {
            return m_textures.get(TextureID::_10_club);
        }
        else if (rank == 11) {
            return m_textures.get(TextureID::jack_club);
        }
        else if (rank == 12) {
            return m_textures.get(TextureID::queen_club);
        }
        else if (rank == 13) {
            return m_textures.get(TextureID::king_club);
        }
    }
}

PixmapManager::PixmapManager()
{
    m_textures.load(TextureID::_2_spade, QStringLiteral(":/assets/2_spade.png"));
    m_textures.load(TextureID::_3_spade, QStringLiteral(":/assets/3_spade.png"));
    m_textures.load(TextureID::_4_spade, QStringLiteral(":/assets/4_spade.png"));
    m_textures.load(TextureID::_5_spade, QStringLiteral(":/assets/5_spade.png"));
    m_textures.load(TextureID::_6_spade, QStringLiteral(":/assets/6_spade.png"));
    m_textures.load(TextureID::_7_spade, QStringLiteral(":/assets/7_spade.png"));
    m_textures.load(TextureID::_8_spade, QStringLiteral(":/assets/8_spade.png"));
    m_textures.load(TextureID::_9_spade, QStringLiteral(":/assets/9_spade.png"));
    m_textures.load(TextureID::_10_spade, QStringLiteral(":/assets/10_spade.png"));

    m_textures.load(TextureID::_2_heart, QStringLiteral(":/assets/2_heart.png"));
    m_textures.load(TextureID::_3_heart, QStringLiteral(":/assets/3_heart.png"));
    m_textures.load(TextureID::_4_heart, QStringLiteral(":/assets/4_heart.png"));
    m_textures.load(TextureID::_5_heart, QStringLiteral(":/assets/5_heart.png"));
    m_textures.load(TextureID::_6_heart, QStringLiteral(":/assets/6_heart.png"));
    m_textures.load(TextureID::_7_heart, QStringLiteral(":/assets/7_heart.png"));
    m_textures.load(TextureID::_8_heart, QStringLiteral(":/assets/8_heart.png"));
    m_textures.load(TextureID::_9_heart, QStringLiteral(":/assets/9_heart.png"));
    m_textures.load(TextureID::_10_heart, QStringLiteral(":/assets/10_heart.png"));

    m_textures.load(TextureID::_2_club, QStringLiteral(":/assets/2_club.png"));
    m_textures.load(TextureID::_3_club, QStringLiteral(":/assets/3_club.png"));
    m_textures.load(TextureID::_4_club, QStringLiteral(":/assets/4_club.png"));
    m_textures.load(TextureID::_5_club, QStringLiteral(":/assets/5_club.png"));
    m_textures.load(TextureID::_6_club, QStringLiteral(":/assets/6_club.png"));
    m_textures.load(TextureID::_7_club, QStringLiteral(":/assets/7_club.png"));
    m_textures.load(TextureID::_8_club, QStringLiteral(":/assets/8_club.png"));
    m_textures.load(TextureID::_9_club, QStringLiteral(":/assets/9_club.png"));
    m_textures.load(TextureID::_10_club, QStringLiteral(":/assets/10_club.png"));

    m_textures.load(TextureID::_2_diamond, QStringLiteral(":/assets/2_diamond.png"));
    m_textures.load(TextureID::_3_diamond, QStringLiteral(":/assets/3_diamond.png"));
    m_textures.load(TextureID::_4_diamond, QStringLiteral(":/assets/4_diamond.png"));
    m_textures.load(TextureID::_5_diamond, QStringLiteral(":/assets/5_diamond.png"));
    m_textures.load(TextureID::_6_diamond, QStringLiteral(":/assets/6_diamond.png"));
    m_textures.load(TextureID::_7_diamond, QStringLiteral(":/assets/7_diamond.png"));
    m_textures.load(TextureID::_8_diamond, QStringLiteral(":/assets/8_diamond.png"));
    m_textures.load(TextureID::_9_diamond, QStringLiteral(":/assets/9_diamond.png"));
    m_textures.load(TextureID::_10_diamond, QStringLiteral(":/assets/10_diamond.png"));

    m_textures.load(TextureID::jack_spade, QStringLiteral(":/assets/jack_spade.png"));
    m_textures.load(TextureID::jack_heart, QStringLiteral(":/assets/jack_heart.png"));
    m_textures.load(TextureID::jack_club, QStringLiteral(":/assets/jack_club.png"));
    m_textures.load(TextureID::jack_diamond, QStringLiteral(":/assets/jack_diamond.png"));

    m_textures.load(TextureID::queen_spade, QStringLiteral(":/assets/queen_spade.png"));
    m_textures.load(TextureID::queen_heart, QStringLiteral(":/assets/queen_heart.png"));
    m_textures.load(TextureID::queen_club, QStringLiteral(":/assets/queen_club.png"));
    m_textures.load(TextureID::queen_diamond, QStringLiteral(":/assets/queen_diamond.png"));

    m_textures.load(TextureID::king_spade, QStringLiteral(":/assets/king_spade.png"));
    m_textures.load(TextureID::king_heart, QStringLiteral(":/assets/king_heart.png"));
    m_textures.load(TextureID::king_club, QStringLiteral(":/assets/king_club.png"));
    m_textures.load(TextureID::king_diamond, QStringLiteral(":/assets/king_diamond.png"));

    m_textures.load(TextureID::ace_spade, QStringLiteral(":/assets/ace_spade.png"));
    m_textures.load(TextureID::ace_heart, QStringLiteral(":/assets/ace_heart.png"));
    m_textures.load(TextureID::ace_club, QStringLiteral(":/assets/ace_club.png"));
    m_textures.load(TextureID::ace_diamond, QStringLiteral(":/assets/ace_diamond.png"));

    m_textures.load(TextureID::back, QStringLiteral(":/assets/back.png"));
    m_textures.load(TextureID::button, QStringLiteral(":/assets/unpressButton.png"));
    m_textures.load(TextureID::pressed_button, QStringLiteral(":/assets/pressButton.png"));
}
