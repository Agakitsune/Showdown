
#pragma once

#include "math/math.hpp"

#include "graphics/Shape.hpp"

namespace showdown::graphics {

    class Rectangle : public Shape {
        math::vec2us _size = math::vec2us(0, 0);

        protected:
            virtual void setupBuffer() override;
            virtual void drawShape(const Window &window, const Pipeline &pipeline) const override;

        public:
            Rectangle(const math::vec2us &size);
            Rectangle(const math::vec2us &size, const color &color);
            Rectangle(const unsigned short width, const unsigned short height);
            Rectangle(const unsigned short width, const unsigned short height, const color &color);
            Rectangle(const Rectangle &other);
            Rectangle(Rectangle &&other) noexcept;

            ~Rectangle() = default;

            void setSize(const math::vec2us &size);
            void setSize(const unsigned short width, const unsigned short height);
            void setColor(const color &color);

            const math::vec2us &getSize() const;
            const color &getColor() const;

            Rectangle &operator=(const Rectangle &other);
            Rectangle &operator=(Rectangle &&other) noexcept;
    };

}