#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#include "Engine.hpp"

Engine::Engine() {
    platforms.emplace_back(100, 100);
    platforms.emplace_back(100, 400);
    platforms.emplace_back(200, 500);
    platforms.emplace_back(300, 300);
    platforms.emplace_back(400, 200);
    platforms.emplace_back(500, 600);
    platforms.emplace_back(600, 400);
};

void Engine::run() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    window.setFramerateLimit(120);

    Event e;
    while (true) {
        window.pollEvent(e);
        window.clear();

        if (e.type == sf::Event::Closed)
            window.close();

        player.changeVelocity();

        checkCollision();

        player.movePlayer();
        player.gravity();

        window.draw(player);
        for (auto &platform: platforms) {
            window.draw(platform);
        }

        window.display();
    }
}

void Engine::checkCollision() {

    bool isIntersecting = true;

    for (auto &platform: platforms) {
        FloatRect playerBounds = player.player.getGlobalBounds();
        FloatRect wallBounds = platform.shape.getGlobalBounds();

        nextPos = playerBounds;
        nextPos.left += player.velocity.x;
        nextPos.top += player.velocity.y;


        if (wallBounds.intersects(nextPos)) {
            //Bottom collision
            if (playerBounds.top < wallBounds.top
                && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left
                    ) {
                player.velocity.y = 0.f;
                player.player.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                player.resetJump();
            }

                //Top collision
            else if (playerBounds.top > wallBounds.top
                     && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                     && playerBounds.left < wallBounds.left + wallBounds.width
                     && playerBounds.left + playerBounds.width > wallBounds.left
                    ) {
                player.velocity.y = 0.f;
                player.player.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
                player.resetJump();
                player.isJumping = false;
            }

            //Right collision
            if (playerBounds.left < wallBounds.left
                && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top
                    ) {
                player.velocity.x = 0.f;
                player.player.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
            }

                //Left collision
            else if (playerBounds.left > wallBounds.left
                     && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
                     && playerBounds.top < wallBounds.top + wallBounds.height
                     && playerBounds.top + playerBounds.height > wallBounds.top
                    ) {
                player.velocity.x = 0.f;
                player.player.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
            }
        }
    }
}
