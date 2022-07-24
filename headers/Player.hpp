//
// Created by Dominik on 19.07.2022.
//
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#ifndef NIBBLES_01_PLAYER_HPP
#define NIBBLES_01_PLAYER_HPP


class Player : public Drawable {
public:
    Player();

    ~Player() = default;

    bool colLeft;
    bool colRight;
    bool colTop;
    bool colBot;
    string direction;
    string collisionDirection;

    void changeVelocity();

    void movePlayer();

private:
    const float movementSpeed = 2.f;
    Vector2f velocity{5.f, 5.f};
    RectangleShape player;

    void draw(RenderTarget &target, RenderStates state) const override;
};

#endif //NIBBLES_01_PLAYER_HPP
