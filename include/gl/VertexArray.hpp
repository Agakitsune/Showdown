
#pragma once

#include "Utils.hpp"
#include "Type.hpp"

namespace showdown::gl {
    
    class VertexArray {
        GLuint handle;

        public:
            VertexArray();
            VertexArray(const VertexArray&) = delete;
            VertexArray(VertexArray&&) noexcept;

            ~VertexArray();

            VertexArray& operator=(const VertexArray&) = delete;
            VertexArray& operator=(VertexArray&&) noexcept;

            void bind() const;
    };

    void vertexAttribPointer(GLuint index, GLint n, VertexAttributeType type, bool normal, GLsizei stride, GLint offset);
    void disableVertexAttribArray(GLuint index);
    
} // namespace dunes
