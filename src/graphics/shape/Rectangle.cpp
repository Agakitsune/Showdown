
#include "graphics/shape/Rectangle.hpp"
#include "graphics/Pipeline.hpp"
#include "graphics/Window.hpp"

namespace showdown::graphics {

    void Rectangle::setupBuffer() {
        _array.bind();
        _buffer.target(gl::BufferTarget::ArrayBuffer);
        _buffer.bind(gl::BufferTarget::ArrayBuffer);

        float r = static_cast<float>(_color.r) / 255.0f;
        float g = static_cast<float>(_color.g) / 255.0f;
        float b = static_cast<float>(_color.b) / 255.0f;
        float a = static_cast<float>(_color.a) / 255.0f;

        float vertices[] = {
            0.0f, 0.0f,                                                                 r, g, b, a,
            static_cast<float>(_size.x), 0.0f,                                          r, g, b, a,
            0.0f, static_cast<float>(_size.y),                                          r, g, b, a,
            static_cast<float>(_size.x), static_cast<float>(_size.y),                   r, g, b, a,
        };//Position                                                                        Color

        _buffer.data(vertices, gl::BufferUsage::DynamicDraw);
    }

    void Rectangle::drawShape(const Window &window, const Pipeline &pipeline) const {
        window.drawPrimitive(gl::DrawMode::TriangleStrip, 0, 4);
    }

    Rectangle::Rectangle(const math::vec2us &size) : _size(size) {
        setupBuffer();
    }

    Rectangle::Rectangle(const math::vec2us &size, const color &color) : _size(size) {
        _color = color;
        setupBuffer();
    }

    Rectangle::Rectangle(const unsigned short width, const unsigned short height) : _size(width, height) {
        setupBuffer();
    }

    Rectangle::Rectangle(const unsigned short width, const unsigned short height, const color &color) : _size(width, height) {
        _color = color;
        setupBuffer();
    }

    Rectangle::Rectangle(const Rectangle &other) : _size(other._size) {
        _color = other._color;
        setupBuffer();
    }

    Rectangle::Rectangle(Rectangle &&other) noexcept : _size(other._size) {
        _color = std::move(other._color);
        setupBuffer();
    }

    Rectangle &Rectangle::operator=(const Rectangle &other) {
        _size = other._size;
        _color = other._color;
        setupBuffer();
        return *this;
    }

    Rectangle &Rectangle::operator=(Rectangle &&other) noexcept {
        _size = other._size;
        _color = std::move(other._color);
        setupBuffer();
        return *this;
    }

    void Rectangle::setSize(const math::vec2us &size) {
        _size = size;
        setupBuffer();
    }

    void Rectangle::setSize(const unsigned short width, const unsigned short height) {
        _size = math::vec2us(width, height);
        setupBuffer();
    }

    void Rectangle::setColor(const color &color) {
        _color = color;
    }

    const math::vec2us &Rectangle::getSize() const {
        return _size;
    }

    const color &Rectangle::getColor() const {
        return _color;
    }

}