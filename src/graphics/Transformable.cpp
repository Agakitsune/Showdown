
#include "graphics/Transformable.hpp"

namespace showdown::graphics {

    void Transformable::translate(const float x, const float y, const float z) {
        _translation = _translation + math::vec3f(x, y, z);
    }

    void Transformable::translate(const math::vec3f &v) {
        _translation = _translation + v;
    }

    void Transformable::translate(const math::vec2f &v) {
        _translation = _translation + math::vec3f(v, 0.0f);
    }

    void Transformable::scale(const float x, const float y, const float z) {
        _scale = _scale * math::vec3f(x, y, z);
    }

    void Transformable::scale(const math::vec3f &v) {
        _scale = _scale * v;
    }

    void Transformable::scale(const math::vec2f &v) {
        _scale = _scale * math::vec3f(v, 1.0f);
    }

    void Transformable::rotate(const float x, const float y, const float z) {
        _rotation = _rotation + math::vec3f(x, y, z);
    }

    void Transformable::rotate(const math::vec3f &v) {
        _rotation = _rotation + v;
    }

    void Transformable::rotate(const float angle) {
        _rotation = _rotation + math::vec3f(0.0f, 0.0f, angle);
    }

    void Transformable::setTranslation(const float x, const float y, const float z) {
        _translation = math::vec3f(x, y, z);
    }

    void Transformable::setTranslation(const math::vec3f &v) {
        _translation = v;
    }

    void Transformable::setTranslation(const math::vec2f &v) {
        _translation = math::vec3f(v, 0.0f);
    }

    void Transformable::setScale(const float x, const float y, const float z) {
        _scale = math::vec3f(x, y, z);
    }

    void Transformable::setScale(const math::vec3f &v) {
        _scale = v;
    }

    void Transformable::setScale(const math::vec2f &v) {
        _scale = math::vec3f(v, 1.0f);
    }

    void Transformable::setRotation(const float x, const float y, const float z) {
        _rotation = math::vec3f(x, y, z);
    }

    void Transformable::setRotation(const math::vec3f &v) {
        _rotation = v;
    }

    void Transformable::setRotation(const float angle) {
        _rotation = math::vec3f(0.0f, 0.0f, angle);
    }

    void Transformable::setOrigin(const float x, const float y, const float z) {
        _origin = math::vec3f(x, y, z);
    }

    void Transformable::setOrigin(const math::vec3f &v) {
        _origin = v;
    }

    void Transformable::setOrigin(const math::vec2f &v) {
        _origin = math::vec3f(v, 0.0f);
    }

    const math::vec3f &Transformable::getTranslation() const {
        return _translation;
    }

    const math::vec3f &Transformable::getScale() const {
        return _scale;
    }

    const math::vec3f &Transformable::getRotation() const {
        return _rotation;
    }

    const math::vec3f &Transformable::getOrigin() const {
        return _origin;
    }

    math::matrix<4, 4, float> Transformable::getModel() const {
        math::matrix<4, 4, float> model(1.0f);

        model = math::translate(model, -(_origin * _scale));
        model = math::rotation(model, _rotation);
        model = math::translate(model, _translation);
        model = math::scale(model, _scale);

        return model;
    }

}
