#include "Player.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Player::Player() {
    direction = "NONE";
    collisionDirection = "NONE";

    colLeft = false;
    colRight = false;
    colTop = false;
    colBot = false;

    player.setSize(Vector2f(50.f, 50.f));
    player.setPosition(0, 550.f);

    texture.loadFromFile("../sprite.png");
    player.setTexture(&texture);

    textureSizeY = texture.getSize().y / 13;
    textureSizeX = texture.getSize().x / 4;

    player.setTextureRect(IntRect(1, 31, texture.getSize().x / 4, texture.getSize().y / 13));
}

void Player::draw(RenderTarget &target, RenderStates state) const {
    target.draw(this->player, state);
}

void Player::changeVelocity() {
    if (!isJumping && !isFalling) {
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            isJumping = true;
            jumpEndY = (int) player.getPosition().y - jumpHeight;
        }
    }
    // x vector change
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        velocity.x = -movementSpeed;
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        velocity.x = movementSpeed;
    }
}

void Player::movePlayer() {
    if (isJumping) {
        if (player.getPosition().y >= jumpEndY) {
            player.move(0, -jumpSpeed);
        } else {
            isJumping = false;
            isFalling = true;
        }
    }
    gravity();
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        player.move(velocity.x, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        player.move(velocity.x, 0);
    }
}

void Player::gravity() {
    if (player.getPosition().y <= 550.f)
        player.move(0, gravityValue);
    else
        isFalling = false;
}

void Player::resetJump() {
    isFalling = false;
}
