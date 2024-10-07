#ifndef PIXMAPMANAGER_H
#define PIXMAPMANAGER_H


#include "resourceholder.h"
#include <QPixmap>

class PixmapManager
{
public:
    enum TextureID
    {
        _1_spade, _2_spade, _3_spade, _4_spade, _5_spade, _6_spade, _7_spade, _8_spade, _9_spade, _10_spade,
        _1_heart, _2_heart, _3_heart, _4_heart, _5_heart, _6_heart, _7_heart, _8_heart, _9_heart, _10_heart,
        _1_club, _2_club, _3_club, _4_club, _5_club, _6_club, _7_club, _8_club, _9_club, _10_club,
        _1_diamond, _2_diamond, _3_diamond, _4_diamond, _5_diamond, _6_diamond, _7_diamond, _8_diamond, _9_diamond, _10_diamond,
        jack_spade, jack_heart, jack_club, jack_diamond,
        queen_spade, queen_heart, queen_club, queen_diamond,
        king_spade, king_heart, king_club, king_diamond,
        ace_spade, ace_heart, ace_club, ace_diamond,
        back,
        button, pressed_button
    };

    static PixmapManager* Instance();
    QPixmap& getPixmap(TextureID id);

    QPixmap& getPixmap(QString suit, int rank);
private:
    PixmapManager();
    PixmapManager(PixmapManager& other) = delete;
    void operator=(const PixmapManager &) = delete;

    ResourceHolder<QPixmap, TextureID> m_textures;
    static PixmapManager* ptr;
};

#endif // PIXMAPMANAGER_H
