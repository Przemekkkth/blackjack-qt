#include "gamescene.h"
#include "utils.h"
#include "pixmapmanager.h"
#include "fontmanager.h"
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsLineItem>
#include <QDebug>
#include <QDir>
#include <QPainter>
#include <QRandomGenerator>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene(parent)
{
    onUserCreate();
}

GameScene::~GameScene()
{

}

void GameScene::loop()
{
    m_deltaTime = m_elapsedTimer.elapsed();
    m_elapsedTimer.restart();

    m_loopTime += m_deltaTime;
    while(m_loopTime > m_loopSpeed)
    {
        m_loopTime -= m_loopSpeed;
        handlePlayerInput();


        if (m_roundOver) {
            if (m_deck.getTotal(m_playerHand) <= 21
                && (m_deck.getTotal(m_dealerHand) > 21
                    || m_deck.getTotal(m_playerHand) > m_deck.getTotal(m_dealerHand) )) {
                m_result = ":   Player wins";
            }
            else if (m_deck.getTotal(m_dealerHand) <= 21
                && (m_deck.getTotal(m_playerHand) > 21
                    || m_deck.getTotal(m_dealerHand) > m_deck.getTotal(m_playerHand) )) {
                m_result = ":   Dealer wins";
            }
            else {
                m_result = ":   Draw";
            }
        }

        clear();
        drawCards();
        drawScore();
        drawButtons();
        resetStatus();
    }
}

void GameScene::initPlayerHand()
{
    m_playerHand.clear();
    int idx = QRandomGenerator::global()->generate() % m_deck.cardCount();
    m_playerHand.push_back( m_deck.removeCard(idx) );

    idx = QRandomGenerator::global()->generate() % m_deck.cardCount();
    m_playerHand.push_back( m_deck.removeCard(idx) );
}

void GameScene::initDealerHand()
{
    m_dealerHand.clear();

    int idx = QRandomGenerator::global()->generate() % m_deck.cardCount();
    m_dealerHand.push_back( m_deck.removeCard(idx) );

    idx = QRandomGenerator::global()->generate() % m_deck.cardCount();
    m_dealerHand.push_back( m_deck.removeCard(idx) );
}

void GameScene::resetGame()
{
    m_deck.fill();

    m_playerHand.clear();
    m_deck.takeCard(m_playerHand);
    m_deck.takeCard(m_playerHand);

    m_dealerHand.clear();
    m_deck.takeCard(m_dealerHand);
    m_deck.takeCard(m_dealerHand);

    m_result = "";

    m_roundOver = false;
}

void GameScene::drawCard(int x, int y, Card card)
{
    QGraphicsPixmapItem* pItem = new QGraphicsPixmapItem();
    pItem->setPixmap(PixmapManager::Instance()->getPixmap(card.suit, card.rank));
    pItem->setPos(x, y);
    addItem(pItem);
}

void GameScene::drawBack(int x, int y)
{
    QGraphicsPixmapItem* pItem = new QGraphicsPixmapItem();
    pItem->setPixmap(PixmapManager::Instance()->getPixmap(PixmapManager::TextureID::back));
    pItem->setPos(x, y);
    addItem(pItem);

}

void GameScene::drawCards()
{
    const int x_margin = 25;
    const int cardWidth = 192 + 10;
    const int y_playerHand = 300;
    const int y_dealerHand = 25;
    for (int i = 0; i < m_dealerHand.size(); ++i) {
        drawCard(x_margin + i * cardWidth, y_dealerHand, m_dealerHand.at(i));
        if (i == 0 && !m_roundOver) {
            drawBack(x_margin + i * cardWidth, y_dealerHand);
        }
    }

    for (int i = 0; i < m_playerHand.size(); ++i) {
        drawCard(x_margin + i * cardWidth, y_playerHand, m_playerHand.at(i));
    }
}

void GameScene::drawScore()
{
    QGraphicsSimpleTextItem *tItem = new QGraphicsSimpleTextItem();
    tItem->setBrush(Qt::white);
    tItem->setPen(QPen(Qt::green));
    tItem->setPos(25, 600);
    tItem->setFont(m_font);
    tItem->setText(QString("Player: ") + QString::number(m_deck.getTotal(m_playerHand))
                   + QString(" vs Dealer ") + (m_roundOver ? ( QString::number(m_deck.getTotal(m_dealerHand)) + m_result ) : QString(" ? ")));
    addItem(tItem);
}

void GameScene::drawButtons()
{
    if (!m_roundOver) {
        Button* hitBtn = new Button(QStringLiteral("Hit!"));
        hitBtn->setPos(175, 700);
        addItem(hitBtn);

        Button* standBtn = new Button(QStringLiteral("Stand"));
        standBtn->setPos(500, 700);
        addItem(standBtn);
    }
    else {
        Button* playAgainBtn = new Button(QStringLiteral("Play again"));
        playAgainBtn->setPos(175, 700);
        addItem(playAgainBtn);
    }

}

void GameScene::onUserCreate()
{
    setBackgroundBrush(COLOR_STYLE::BACKGROUND);
    for(int i = 0; i < 256; ++i)
    {
        m_keys[i] = new KeyStatus();
    }
    m_mouse = new MouseStatus();
    setSceneRect(0,0, SCREEN::PHYSICAL_SIZE.width(), SCREEN::PHYSICAL_SIZE.height());
    connect(&m_timer, &QTimer::timeout, this, &GameScene::loop);
    m_timer.start(int(1000.0f/FPS));
    m_elapsedTimer.start();

    resetGame();
    m_font = FontManager::Instance()->getFont(FontManager::FontID::BUTTON);
    m_font.setPixelSize(40);

}

void GameScene::renderScene()
{
    static int index = 0;
    QString fileName = QDir::currentPath() + QDir::separator() + "screen" + QString::number(index++) + ".png";
    QRect rect = sceneRect().toAlignedRect();
    QImage image(rect.size(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter painter(&image);
    render(&painter);
    image.save(fileName);
    qDebug() << "saved " << fileName;
}

void GameScene::handlePlayerInput()
{
    if (!m_roundOver) {
        if(m_keys[KEYBOARD::KeysMapper[Qt::Key_H]]->m_released && !m_roundOver)
        {
            m_deck.takeCard(m_playerHand);
            if (m_deck.getTotal(m_playerHand) >= 21 ) {
                m_roundOver = true;
            }

        }
        else if(m_keys[KEYBOARD::KeysMapper[Qt::Key_S]]->m_released) {
            m_roundOver = true;
        }

        if (m_mouse->m_released){
            if (m_mouse->m_x >= 175 - (300 / 2) && m_mouse->m_x <= 175 - (300 / 2) + 300 &&
                m_mouse->m_y >= 700 - (70 / 2) && m_mouse->m_y <= 700 - (70 / 2) + 70) {
                //hit
                m_deck.takeCard(m_playerHand);
                if (m_deck.getTotal(m_playerHand) >= 21 ) {
                    m_roundOver = true;
                }
            }
            if (m_mouse->m_x >= 500 - (300 / 2) && m_mouse->m_x <= 500 - (300 / 2) + 300 &&
                m_mouse->m_y >= 700 - (70 / 2) && m_mouse->m_y <= 700 - (70 / 2) + 70) {
                //stand
                m_roundOver = true;
            }
        }

        if (m_roundOver) {
            while (m_deck.getTotal(m_dealerHand) < 17) {
                m_deck.takeCard(m_dealerHand);
            }
        }
    }
    else {
        if (m_mouse->m_released){
            if (m_mouse->m_x >= 175 - (300 / 2) && m_mouse->m_x <= 175 - (300 / 2) + 300 &&
                m_mouse->m_y >= 700 - (70 / 2) && m_mouse->m_y <= 700 - (70 / 2) + 70) {
                //play again
                resetGame();
            }
        }
    }
}

void GameScene::resetStatus()
{
    for(int i = 0; i < 256; ++i)
    {
        m_keys[i]->m_released = false;
    }
    for(int i = 0; i < 256; ++i)
    {
        m_keys[i]->m_pressed = false;
    }
    m_mouse->m_released = false;
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    if(KEYBOARD::KeysMapper.contains(event->key()))
    {
        if(event->isAutoRepeat())
        {
            m_keys[KEYBOARD::KeysMapper[event->key()]]->m_held = true;
            m_keys[KEYBOARD::KeysMapper[event->key()]]->m_pressed = false;
        }
        else
        {
            m_keys[KEYBOARD::KeysMapper[event->key()]]->m_pressed = true;
            m_keys[KEYBOARD::KeysMapper[event->key()]]->m_held    = false;
        }
    }
    QGraphicsScene::keyPressEvent(event);
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    if(KEYBOARD::KeysMapper.contains(event->key()))
    {
        if(!event->isAutoRepeat())
        {
            m_keys[KEYBOARD::KeysMapper[event->key()]]->m_held = false;
            m_keys[KEYBOARD::KeysMapper[event->key()]]->m_pressed = false;
            m_keys[KEYBOARD::KeysMapper[event->key()]]->m_released = true;
        }

    }


    if (m_roundOver) {
        resetGame();
    }
    QGraphicsScene::keyReleaseEvent(event);
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_mouse->m_x = event->scenePos().x();
    m_mouse->m_y = event->scenePos().y();
    m_mouse->m_pressed = true;
    QGraphicsScene::mousePressEvent(event);
}

void GameScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    m_mouse->m_x = event->scenePos().x();
    m_mouse->m_y = event->scenePos().y();
    QGraphicsScene::mouseMoveEvent(event);
}

void GameScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_mouse->m_x = event->scenePos().x();
    m_mouse->m_y = event->scenePos().y();
    m_mouse->m_pressed = false;
    m_mouse->m_released = true;
    QGraphicsScene::mouseReleaseEvent(event);
}
