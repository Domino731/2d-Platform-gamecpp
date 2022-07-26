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

    void resetJump();

    RectangleShape player;
    Vector2f velocity{5.f, 5.f};
    const float movementSpeed = 2.f;
    const float jumpSpeed = 6.f;

    bool isJumping = false;
    bool isFalling = false;
    bool isFalling2 = false;
    int const jumpHeight = 200;
    int jumpEndY = 0;


    float gravityValue = 1.5f;
    float ground = 550.f;
private:

    void draw(RenderTarget &target, RenderStates state) const override;
};

#endif //NIBBLES_01_PLAYER_HPP
