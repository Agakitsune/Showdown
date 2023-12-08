
#include "graphics/Sprite.hpp"
#include "graphics/Pipeline.hpp"
#include "graphics/Window.hpp"

namespace showdown::graphics {
    
    void Sprite::setupBuffer() {
        _array.bind();
        _buffer.bind(gl::BufferTarget::ArrayBuffer);

        math::vec2u textureSize = _texture.size();

        float vertices[] = {
            0.0f, 0.0f,                                                               1.0f, 1.0f, 1.0f,       0.0f, 0.0f,
            static_cast<float>(textureSize.x), 0.0f,                                  1.0f, 1.0f, 1.0f,       1.0f, 0.0f,
            0.0f, static_cast<float>(textureSize.y),                                  1.0f, 1.0f, 1.0f,       0.0f, 1.0f,
            static_cast<float>(textureSize.x), static_cast<float>(textureSize.y),     1.0f, 1.0f, 1.0f,       1.0f, 1.0f,
        };//Position                                                                        Color                   UV

        _buffer.data(vertices, gl::BufferUsage::StaticDraw);
    }

    Sprite::Sprite(const Sprite &other) : _texture(other._texture) {
        _buffer.bind(gl::BufferTarget::ArrayBuffer);
        _buffer.data(other._buffer.getData().data(), other._buffer.size(), gl::BufferUsage::StaticDraw);
    }

    Sprite::Sprite(Sprite &&other) noexcept : _texture(std::move(other._texture)) {}

    Sprite::Sprite(const Texture &texture) : _texture(texture) {
        setupBuffer();
    }

    Sprite::Sprite(Texture &&texture) : _texture(std::move(texture)) {
        setupBuffer();
    }

    Sprite::Sprite(const char *path) {
        _texture = Texture(path);
        setupBuffer();
    }

    Sprite::Sprite(const std::string &path) {
        _texture = Texture(path);
        setupBuffer();
    }

    Sprite::Sprite(const std::filesystem::path &path) {
        _texture = Texture(path);
        setupBuffer();
    }

    Sprite::~Sprite() {}

    Sprite &Sprite::operator=(const Sprite &other) {
        _texture = other._texture;
        setupBuffer();
        setPosition(other.getPosition());
        setRotation(other.getRotation());
        setScale(other.getScale());
        setOrigin(other.getOrigin());
        return *this;
    }

    Sprite &Sprite::operator=(Sprite &&other) noexcept {
        _texture = std::move(other._texture);
        _buffer = std::move(other._buffer);
        setPosition(other.getPosition());
        setRotation(other.getRotation());
        setScale(other.getScale());
        setOrigin(other.getOrigin());
        return *this;
    }

    void Sprite::setPosition(const float x, const float y) {
        Transformable::setTranslation(x, y);
    }

    void Sprite::setPosition(const math::vec2f &position) {
        Transformable::setTranslation(position);
    }

    void Sprite::move(const float x, const float y) {
        Transformable::translate(x, y);
    }

    void Sprite::setRotation(const float angle) {
        Transformable::setRotation(angle);
    }

    void Sprite::rotate(const float angle) {
        Transformable::rotate(angle);
    }

    void Sprite::setScale(const float x, const float y) {
        Transformable::setScale(x, y);
    }

    void Sprite::setScale(const math::vec2f &scale) {
        Transformable::setScale(scale);
    }

    void Sprite::scale(const float x, const float y) {
        Transformable::scale(x, y);
    }

    void Sprite::setOrigin(const float x, const float y) {
        Transformable::setOrigin(x, y);
    }

    void Sprite::setOrigin(const math::vec2f &origin) {
        Transformable::setOrigin(origin);
    }

    void Sprite::setTexture(const Texture &texture) {
        _texture = texture;
    }

    void Sprite::setTexture(Texture &&texture) {
        _texture = std::move(texture);
    }

    void Sprite::setTexture(const char *path) {
        _texture = Texture(path);
    }

    void Sprite::setTexture(const std::string &path) {
        _texture = Texture(path);
    }

    void Sprite::setTexture(const std::filesystem::path &path) {
        _texture = Texture(path);
    }

    math::vec2f Sprite::getPosition() const {
        return math::swizzle<math::arg::X, math::arg::Y>(Transformable::getTranslation());
    }

    math::vec2f Sprite::getScale() const {
        return math::swizzle<math::arg::X, math::arg::Y>(Transformable::getScale());
    }

    math::vec2f Sprite::getOrigin() const {
        return math::swizzle<math::arg::X, math::arg::Y>(Transformable::getOrigin());
    }

    float Sprite::getRotation() const {
        return Transformable::getRotation().z;
    }

    const Texture &Sprite::getTexture() const {
        return _texture;
    }

    void Sprite::draw(const Window &window, const Pipeline &pipeline) const {
        pipeline.set("Z", 0);
        window.drawPrimitive(gl::DrawMode::TriangleStrip, 0, 4);
    }

    void Sprite::draw(const Window &window, const float z, const Pipeline &pipeline) const {
        pipeline.set("Z", z);
        window.drawPrimitive(gl::DrawMode::TriangleStrip, 0, 4);
    }

    void Sprite::setup(const Pipeline &pipeline) const {
        auto model = getModel();
        _texture.slot(0);
        
        pipeline.set4x4("model", 1, true, &model[0][0]);
        pipeline.set("Texture", 0);

        _array.bind();
    }

} // namespace showdown::graphics
