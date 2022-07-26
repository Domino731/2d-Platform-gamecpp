//
// Created by Dominik on 19.07.2022.
//
#include <iostream>
#include "Player.hpp"
#include <math.h>

using namespace std;

Player::Player() {
    direction = "NONE";
    collisionDirection = "NONE";
    colLeft = false;
    colRight = false;
    colTop = false;
    colBot = false;
    player.setFillColor(Color::Green);
    player.setSize(Vector2f(50.f, 50.f));
    player.setPosition(0, 550.f);
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

//    if (isFalling && ground != player.getPosition().y) {
//        player.move(0, gravityValue);
//        cout << "ground" << ground << endl;
//    } else if (isFalling && ground == player.getPosition().y) {
//        resetJump();
//    }
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
