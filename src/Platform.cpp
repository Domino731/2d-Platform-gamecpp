#include "Platform.hpp"

Platform::Platform() {
    shape.setFillColor(Color::Red);
    shape.setSize(Vector2f(200.f, 30.f));
    shape.setPosition(50.f * 5, 50.f * 2);
}

void Platform::draw(RenderTarget &target, RenderStates state) const {
    target.draw(this->shape, state);
}

float Platform::top() {
    return shape.getPosition().y - shape.getSize().y / 2.f;
};

float Platform::bot() {
    return shape.getPosition().y + shape.getSize().y / 2.f;
};

float Platform::left() {
    return shape.getPosition().x - shape.getSize().x / 2.f;
};

float Platform::right() {
    return shape.getPosition().x + shape.getSize().x / 2.f;
};