#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Platform.hpp"

using namespace std;
using namespace sf;

#include "Engine.hpp"
#include "Platform.hpp"

Engine::Engine() {
    platforms.emplace_back();
};

void Engine::run() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    window.setFramerateLimit(120);

    Event e;
    while (true) {
        window.pollEvent(e);
        window.clear();

//        if (e.type == sf::Event::Closed)
//            window.close();

        player.changeVelocity();
        player.movePlayer();

        window.draw(player);
        for (auto &platform: platforms) {
            window.draw(platform);
        }

        window.display();
    }
}
