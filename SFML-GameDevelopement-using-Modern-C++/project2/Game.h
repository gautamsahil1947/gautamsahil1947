#pragma once

#include "Entity.h"
#include "EntityManager.h"

#include <SFML/Graphics.hpp>


typedef struct PlayerConfig {int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S;}PlayerConfig;
typedef struct EnemyConfig {int SR, CR, OR, OB, OG, OT, VMAX, VMIN, L, SI; float SMIN, SMAX;}EnemyConfig;
typedef struct BulletConfig {int SR, CR, FR, FG, FB, OR, OG, OB, V, L; float S;}BulletConfig;


class Game {
    sf::RenderWindow        m_window;
    EntityManager           m_entities;
    sf::Font                m_font;
    sf::Text                m_text;
    PlayerConfig            m_playerconfig;
    EnemyConfig             m_enemyconfig;
    BulletConfig            m_bulletconfig;
    int                     m_score = 0;
    int m_currentFrame = 0;
    int m_lastEnemySpawnTime = 0;
    bool m_paused = false;
    bool m_running = true;

    std::shared_ptr<Entity> m_player;
    void init(const std::string& config);
    void setPaused(bool paused);
    
    void sMovement();
    void sUserInput();
    void sRender();
    void sLifespan();
    void sEnemySpawner();
    void sCollision();

    void spawnPlayer();
    void spawnEnemy();
    void spawnSmallEnemies(std::shared_ptr<Entity> entity);
    void spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos);
    void spawnSpedialWeapon(std::shared_ptr<Entity> entity);

public:
    Game(const std::string& config);

    void run();

};

