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

    void gravity();

    RectangleShape player;
    Vector2f velocity{5.f, 5.f};
    const float movementSpeed = 2.f;
    const float jumpSpeed = 1.f;

    bool isJumping = false;
    bool isFalling = false;
    int const jumpHeight = 100;
    int currentJumpHeight = 0;

    int jumpStartY = 0;
    int jumpEndY = 0;
    int jumpY = 0;

    float gravityValue = 1.f;
    float ground = 550.f;
private:

    void draw(RenderTarget &target, RenderStates state) const override;
};

#endif //NIBBLES_01_PLAYER_HPP
