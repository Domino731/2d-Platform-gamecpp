//
// Created by Dominik on 19.07.2022.
//
#include <iostream>
#include "Player.hpp"

Player::Player() {
    direction = "NONE";
    collisionDirection = "NONE";
    colLeft = false;
    colRight = false;
    colTop = false;
    colBot = false;
    player.setFillColor(Color::Green);
    player.setSize(Vector2f(50.f, 50.f));
}

void Player::draw(RenderTarget &target, RenderStates state) const {
    target.draw(this->player, state);
}

void Player::changeVelocity() {
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        velocity.y = -movementSpeed;
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        velocity.y = movementSpeed;
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        velocity.x = -movementSpeed;
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        velocity.x = movementSpeed;
    }
}

void Player::movePlayer() {
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        player.move(0, velocity.y);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        player.move(0, velocity.y);
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        player.move(velocity.x, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        player.move(velocity.x, 0);
    }
}
