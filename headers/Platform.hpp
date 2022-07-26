//
// Created by Dominik on 22.07.2022.
//

#ifndef NIBBLES_01_PLATFORM_HPP
#define NIBBLES_01_PLATFORM_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Platform : public Drawable {
public:
    Platform();

    sf::RectangleShape shape;
private:
    float const shapeWidth{200.0f};
    float const shapeHeight{30.0f};
    float const player_velocity{6.0f};

    Vector2f velocity{0.f, 0.f};

    void draw(RenderTarget &target, RenderStates state) const override;
};


#endif //NIBBLES_01_PLATFORM_HPP
