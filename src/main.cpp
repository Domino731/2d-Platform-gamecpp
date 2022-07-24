#include<iostream>
#include<cmath>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include "Engine.hpp"

using namespace sf;

int main() {
    Engine engine;
    engine.run();
}

//int main() {
//    const int WINDOW_WIDTH = 800;
//    const int WINDOW_HEIGHT = 600;
//    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
//    window.setFramerateLimit(120);
//
//    const float gridSize = 50.f;
//
//    //Player
//    const float movementSpeed = 2.f;
//    Vector2f velocity{5.f, 5.f};
//    RectangleShape player;
//    player.setFillColor(Color::Green);
//    player.setSize(Vector2f(gridSize, gridSize));
//
//    //Walls
//    std::vector<RectangleShape> walls;
//
//    RectangleShape wall;
//    wall.setFillColor(Color::Red);
//    wall.setSize(Vector2f(200.f, 30.f));
//    wall.setPosition(gridSize * 5, gridSize * 2);
//    walls.push_back(wall);
//
//    //Collision
//    FloatRect nextPos;
//
//    sf::Event event;
//    while (window.isOpen()) {
//
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        if (Keyboard::isKeyPressed(Keyboard::W)) {
//            velocity.y = -movementSpeed;
//        }
//        if (Keyboard::isKeyPressed(Keyboard::S)) {
//            velocity.y = movementSpeed;
//        }
//        if (Keyboard::isKeyPressed(Keyboard::A)) {
//            velocity.x = -movementSpeed;
//        }
//        if (Keyboard::isKeyPressed(Keyboard::D)) {
//            velocity.x = movementSpeed;
//        }
//
//        //Collision
//        for (auto &wall: walls) {
//            FloatRect playerBounds = player.getGlobalBounds();
//            FloatRect wallBounds = wall.getGlobalBounds();
//
//            nextPos = playerBounds;
//            nextPos.left += velocity.x;
//            nextPos.top += velocity.y;
//
//            if (wallBounds.intersects(nextPos)) {
//                //Bottom collision
//                if (playerBounds.top < wallBounds.top
//                    && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
//                    && playerBounds.left < wallBounds.left + wallBounds.width
//                    && playerBounds.left + playerBounds.width > wallBounds.left
//                        ) {
//                    velocity.y = 0.f;
//                    player.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
//                }
//
//                    //Top collision
//                else if (playerBounds.top > wallBounds.top
//                         && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
//                         && playerBounds.left < wallBounds.left + wallBounds.width
//                         && playerBounds.left + playerBounds.width > wallBounds.left
//                        ) {
//                    velocity.y = 0.f;
//                    player.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
//                }
//
//                //Right collision
//                if (playerBounds.left < wallBounds.left
//                    && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
//                    && playerBounds.top < wallBounds.top + wallBounds.height
//                    && playerBounds.top + playerBounds.height > wallBounds.top
//                        ) {
//                    velocity.x = 0.f;
//                    player.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
//                }
//
//                    //Left collision
//                else if (playerBounds.left > wallBounds.left
//                         && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
//                         && playerBounds.top < wallBounds.top + wallBounds.height
//                         && playerBounds.top + playerBounds.height > wallBounds.top
//                        ) {
//                    velocity.x = 0.f;
//                    player.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
//                }
//            }
//        }
//
//        if (Keyboard::isKeyPressed(Keyboard::W)) {
//            player.move(0, velocity.y);
//        }
//        if (Keyboard::isKeyPressed(Keyboard::S)) {
//            player.move(0, velocity.y);
//        }
//        if (Keyboard::isKeyPressed(Keyboard::A)) {
//            player.move(velocity.x, 0);
//        }
//        if (Keyboard::isKeyPressed(Keyboard::D)) {
//            player.move(velocity.x, 0);
//        }
//
//
//        //Render
//        window.clear();
//        window.draw(player);
//        for (auto &i: walls) {
//            window.draw(i);
//        }
//        window.display();
//    }
//
//    return 0;
//}

