#include "Platform.hpp"

Platform::Platform(float pX, float pY) {
    shape.setFillColor(Color::Red);
    shape.setSize(Vector2f(200.f, 30.f));
    shape.setPosition(pX, pY);
}

void Platform::draw(RenderTarget &target, RenderStates state) const {
    target.draw(this->shape, state);
}
