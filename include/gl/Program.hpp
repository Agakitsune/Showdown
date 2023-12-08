
#pragma once

#include <string>

#include "Utils.hpp"
#include "Shader.hpp"
#include "Uniform.hpp"

namespace showdown::gl {

    class Program {
        size_t *refCount;
        GLuint handle;

        public:
            Program();
            Program(const Program&);
            Program(Program&&) noexcept;

            ~Program();

            Program& operator=(const Program&);
            Program& operator=(Program&&) noexcept;

            void attach(const Shader& shader) const;
            void detach(const Shader& shader) const;

            void link() const;

            std::string getInfoLog() const;

            void use() const;

            Uniform getUniform(const std::string& name) const;
    };

}
