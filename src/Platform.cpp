#include "Platform.hpp"

Platform::Platform() {
    shape.setFillColor(Color::Red);
    shape.setSize(Vector2f(200.f, 30.f));
    shape.setPosition(200, 500);
}

void Platform::draw(RenderTarget &target, RenderStates state) const {
    target.draw(this->shape, state);
}
