#ifndef NIBBLES_01_ENGINE_HPP
#define NIBBLES_01_ENGINE_HPP

#include "Player.hpp"
#include "Platform.hpp"

using namespace std;
using namespace sf;

class Engine {
public:
    // constructor, destructor
    Engine();

    // run engine
    void run();

private:
    // config
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    // platforms
    vector<Platform> platforms;

    // player class
    Player player;

    // methods
    void checkCollision();

    // Collision
    FloatRect nextPos;
};


#endif //NIBBLES_01_ENGINE_HPP
