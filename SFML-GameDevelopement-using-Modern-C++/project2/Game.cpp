#include "Game.h"

#include <iostream>

Game::Game(const std::string& config) {
    init(config);
}

void Game::init(const std::string& path) {
    // todo
    m_window.create(sf::VideoMode(700, 700), "Assignment 2");
    m_window.setFramerateLimit(60);
    spawnPlayer();
}

void Game::run() {
    // add pause functionality in here 
    while (m_running) {
        sEnemySpawner();
        sMovement();
        sCollision();
        sUserInput();
        sRender();

        m_currentFrame++;
    }
}

void Game::setPaused(bool paused) {
    // todo
}
