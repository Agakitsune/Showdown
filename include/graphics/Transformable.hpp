
#pragma once

#include "math/matrix.hpp"
#include "math/math.hpp"

namespace showdown::graphics {
    
    class Transformable {
        math::vec3f _origin = math::vec3f(0.0f);
        math::vec3f _translation = math::vec3f(0.0f);
        math::vec3f _scale = math::vec3f(1.0f);
        math::vec3f _rotation = math::vec3f(0.0f);
        // math::matrix<4, 4, float> _model = math::matrix<4, 4, float>(1.0f); 

        public:
            Transformable() = default;
            ~Transformable() = default;

            void translate(const float x, const float y, const float z = 0.0f);
            void translate(const math::vec3f &v);
            void translate(const math::vec2f &v);

            void scale(const float x, const float y, const float z = 1.0f);
            void scale(const math::vec3f &v);
            void scale(const math::vec2f &v);

            void rotate(const float x, const float y, const float z);
            void rotate(const math::vec3f &v);
            void rotate(const float angle);

            void setTranslation(const float x, const float y, const float z = 0.0f);
            void setTranslation(const math::vec3f &v);
            void setTranslation(const math::vec2f &v);

            void setScale(const float x, const float y, const float z = 1.0f);
            void setScale(const math::vec3f &v);
            void setScale(const math::vec2f &v);

            void setRotation(const float x, const float y, const float z);
            void setRotation(const math::vec3f &v);
            void setRotation(const float angle);

            void setOrigin(const float x, const float y, const float z = 0.0f);
            void setOrigin(const math::vec3f &v);
            void setOrigin(const math::vec2f &v);

            // void apply(const math::matrix<4, 4, float> &m);
            // void apply(const Transformable &t);

            const math::vec3f &getTranslation() const;
            const math::vec3f &getScale() const;
            const math::vec3f &getRotation() const;
            const math::vec3f &getOrigin() const;
            math::matrix<4, 4, float> getModel() const;
    };

} // namespace showdown::gr
