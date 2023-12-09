
#pragma once

#include "gl/VertexArray.hpp"
#include "gl/Buffer.hpp"

#include "graphics/Transformable.hpp"
#include "graphics/Drawable.hpp"
#include "graphics/Color.hpp"

namespace showdown::graphics {

    class Shape : public Transformable, public Drawable {
        protected:
            gl::VertexArray _array;
            gl::Buffer _buffer;
            color _color = white;

            virtual void setupBuffer() = 0;
            virtual void drawShape(const Window &window, const Pipeline &pipeline) const = 0;

        public:
            Shape() = default;
            Shape(const Shape &other);
            Shape(Shape &&other) noexcept;

            ~Shape() = default;

            Shape &operator=(const Shape &other);
            Shape &operator=(Shape &&other) noexcept;

            void setPosition(const float x, const float y);
            void setPosition(const math::vec2f &position);
            void move(const float x, const float y);

            void setRotation(const float angle);
            void rotate(const float angle);

            void setScale(const float x, const float y);
            void setScale(const math::vec2f &scale);
            void scale(const float x, const float y);

            void setOrigin(const float x, const float y);
            void setOrigin(const math::vec2f &origin);

            math::vec2f getPosition() const;
            math::vec2f getScale() const;
            math::vec2f getOrigin() const;
            float getRotation() const;

            virtual void draw(const Window &window) const override;
            virtual void draw(const Window &window, const float z) const override;
            virtual void draw(const Window &window, const Pipeline &pipeline) const override;
            virtual void draw(const Window &window, const float z, const Pipeline &pipeline) const override;
            virtual void setup(const Pipeline &pipeline) const override;
    };

}
