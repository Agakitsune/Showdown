
#pragma once

#include <filesystem>

#include "gl/Texture.hpp"
#include "math/vector2.hpp"

namespace showdown::graphics {

    class Texture {
        gl::Texture _tex;

        public:
            Texture();
            Texture(const Texture &other);
            Texture(Texture &&other);
            Texture(const char *path);
            Texture(const std::string &path);
            Texture(const std::filesystem::path &path);

            ~Texture();

            Texture &operator=(const Texture &other);
            Texture &operator=(Texture &&other);

            static Texture create(const int width, const int height);

            void slot(size_t unit) const;

            math::vec2u size() const;
    };

} // namespace showdown
