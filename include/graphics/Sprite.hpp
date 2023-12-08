
#pragma once

#include <filesystem>

#include "gl/VertexArray.hpp"
#include "gl/Buffer.hpp"

#include "graphics/Transformable.hpp"
#include "graphics/Texture.hpp"
#include "graphics/Drawable.hpp"

namespace showdown::graphics {

    class Sprite : public Transformable, public Drawable {
        Texture _texture;
        gl::VertexArray _array;
        gl::Buffer _buffer;

        void setupBuffer();

        public:
            Sprite(const Sprite &other);
            Sprite(Sprite &&other) noexcept;
            Sprite(const Texture &texture);
            Sprite(Texture &&texture);
            Sprite(const char *path);
            Sprite(const std::string &path);
            Sprite(const std::filesystem::path &path);

            ~Sprite();

            Sprite &operator=(const Sprite &other);
            Sprite &operator=(Sprite &&other) noexcept;

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

            void setTexture(const Texture &texture);
            void setTexture(Texture &&texture);
            void setTexture(const char *path);
            void setTexture(const std::string &path);
            void setTexture(const std::filesystem::path &path);

            math::vec2f getPosition() const;
            math::vec2f getScale() const;
            math::vec2f getOrigin() const;
            float getRotation() const;
            const Texture &getTexture() const;

            void draw(const Window &window, const Pipeline &pipeline) const override;
            void draw(const Window &window, const float z, const Pipeline &pipeline) const override;
            void setup(const Pipeline &pipeline) const override;
    };

}
