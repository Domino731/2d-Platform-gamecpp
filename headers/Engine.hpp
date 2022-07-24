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
    vector<Platform> platforms;

    // draw platforms
    void drawPlatforms(RenderWindow &window);

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    // player class
    Player player;
};


#endif //NIBBLES_01_ENGINE_HPP
