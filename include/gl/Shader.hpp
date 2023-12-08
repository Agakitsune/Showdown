
#pragma once

#include <string>

#include "Utils.hpp"
#include "Type.hpp"

namespace showdown::gl {
    
    class Shader {
        GLuint handle;

        public:
            Shader(ShaderType type);
            Shader(const Shader&) = delete;
            Shader(Shader&&) noexcept;

            ~Shader();

            Shader& operator=(const Shader&) = delete;
            Shader& operator=(Shader&&) noexcept;

            void source(const std::string& source) const;
            void source(const char* source) const;

            bool compile() const;

            std::string getInfoLog() const;

            GLuint getHandle() const;
    };

} // namespace zephy
