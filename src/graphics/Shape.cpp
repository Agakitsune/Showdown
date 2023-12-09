
#include "graphics/Shape.hpp"
#include "graphics/Pipeline.hpp"
#include "graphics/Window.hpp"

#include "ressource/Manager.hpp"

namespace showdown::graphics {
    
    // void Shape::setupBuffer() {
    //     _array.bind();
    //     _buffer.bind(gl::BufferTarget::ArrayBuffer);

    //     // math::vec2u textureSize = _texture.size();

    //     // float vertices[] = {
    //     //     0.0f, 0.0f,                                                               1.0f, 1.0f, 1.0f,       0.0f, 0.0f,
    //     //     static_cast<float>(textureSize.x), 0.0f,                                  1.0f, 1.0f, 1.0f,       1.0f, 0.0f,
    //     //     0.0f, static_cast<float>(textureSize.y),                                  1.0f, 1.0f, 1.0f,       0.0f, 1.0f,
    //     //     static_cast<float>(textureSize.x), static_cast<float>(textureSize.y),     1.0f, 1.0f, 1.0f,       1.0f, 1.0f,
    //     // };//Position                                                                        Color                   UV

    //     // _buffer.data(vertices, gl::BufferUsage::StaticDraw);
    // }

    Shape::Shape(const Shape &other) {
        _buffer.target(gl::BufferTarget::ArrayBuffer);
        _buffer.bind(gl::BufferTarget::ArrayBuffer);
        _buffer.data(other._buffer.getData().data(), other._buffer.size(), gl::BufferUsage::DynamicDraw);
    }

    Shape::Shape(Shape &&other) noexcept {
        _buffer = std::move(other._buffer);
        _color = other._color;
    }

    Shape &Shape::operator=(const Shape &other) {
        setupBuffer();
        setPosition(other.getPosition());
        setRotation(other.getRotation());
        setScale(other.getScale());
        setOrigin(other.getOrigin());
        return *this;
    }

    Shape &Shape::operator=(Shape &&other) noexcept {
        _buffer = std::move(other._buffer);
        setPosition(other.getPosition());
        setRotation(other.getRotation());
        setScale(other.getScale());
        setOrigin(other.getOrigin());
        return *this;
    }

    void Shape::setPosition(const float x, const float y) {
        Transformable::setTranslation(x, y);
    }

    void Shape::setPosition(const math::vec2f &position) {
        Transformable::setTranslation(position);
    }

    void Shape::move(const float x, const float y) {
        Transformable::translate(x, y);
    }

    void Shape::setRotation(const float angle) {
        Transformable::setRotation(angle);
    }

    void Shape::rotate(const float angle) {
        Transformable::rotate(angle);
    }

    void Shape::setScale(const float x, const float y) {
        Transformable::setScale(x, y);
    }

    void Shape::setScale(const math::vec2f &scale) {
        Transformable::setScale(scale);
    }

    void Shape::scale(const float x, const float y) {
        Transformable::scale(x, y);
    }

    void Shape::setOrigin(const float x, const float y) {
        Transformable::setOrigin(x, y);
    }

    void Shape::setOrigin(const math::vec2f &origin) {
        Transformable::setOrigin(origin);
    }

    math::vec2f Shape::getPosition() const {
        return math::swizzle<math::arg::X, math::arg::Y>(Transformable::getTranslation());
    }

    math::vec2f Shape::getScale() const {
        return math::swizzle<math::arg::X, math::arg::Y>(Transformable::getScale());
    }

    math::vec2f Shape::getOrigin() const {
        return math::swizzle<math::arg::X, math::arg::Y>(Transformable::getOrigin());
    }

    float Shape::getRotation() const {
        return Transformable::getRotation().z;
    }

    void Shape::draw(const Window &window) const {
        window.draw(*this,
            Manager::getRegistry<Registry<Pipeline>>(RegistryKey::of("showdown:pipeline"))
            .get(RegistryKey::of("showdown:shape")));
    }

    void Shape::draw(const Window &window, const float z) const {
        window.draw(*this, z,
            Manager::getRegistry<Registry<Pipeline>>(RegistryKey::of("showdown:pipeline"))
            .get(RegistryKey::of("showdown:texture")));
    }

    void Shape::draw(const Window &window, const Pipeline &pipeline) const {
        pipeline.set("Z", 0.0f);
        drawShape(window, pipeline);
    }

    void Shape::draw(const Window &window, const float z, const Pipeline &pipeline) const {
        pipeline.set("Z", z);
        drawShape(window, pipeline);
    }

    void Shape::setup(const Pipeline &pipeline) const {
        auto model = getModel();
        // _texture.slot(0);
        
        pipeline.set4x4("model", 1, true, &model[0][0]);
        // pipeline.set("Texture", 0);

        _array.bind();
        _buffer.bind(gl::BufferTarget::ArrayBuffer);
    }

} // namespace showdown::graphics
