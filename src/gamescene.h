#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QTimer>
#include <QImage>
#include <QGraphicsSimpleTextItem>
#include "deck.h"
#include "button.h"

struct KeyStatus
{
    bool m_pressed = false;
    bool m_held = false;
    bool m_released = false;
};

struct MouseStatus
{
    float m_x = 0.0f;
    float m_y = 0.0f;
    bool m_released = false;
    bool m_pressed = false;
};

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);
    ~GameScene();
private slots:
    void loop();

private:
    Deck m_deck;
    QVector<Card> m_playerHand;
    QVector<Card> m_dealerHand;
    bool m_roundOver;
    QString m_result;
    QFont m_font;

    void initPlayerHand();
    void initDealerHand();
    void resetGame();
    void drawCard(int x, int y, Card card);
    void drawBack(int x, int y);
    void drawCards();
    void drawScore();
    void drawButtons();

    void onUserCreate();
    void renderScene();
    void handlePlayerInput();
    void resetStatus();
    KeyStatus* m_keys[256];
    MouseStatus* m_mouse;
    const int FPS = 60;
    QTimer m_timer;
    QElapsedTimer m_elapsedTimer;
    float m_deltaTime = 0.0f, m_loopTime = 0.0f;
    const float m_loopSpeed = int(1000.0f/FPS);
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};


#endif // GAMESCENE_H
