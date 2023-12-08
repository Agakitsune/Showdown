
#include "gl/VertexArray.hpp"

namespace showdown::gl {
    
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &handle);
    }

    VertexArray::VertexArray(VertexArray&& other) noexcept {
        handle = other.handle;
        other.handle = 0;
    }

    VertexArray::~VertexArray() {
        if (handle != 0) {
            glDeleteVertexArrays(1, &handle);
        }
    }

    VertexArray& VertexArray::operator=(VertexArray&& other) noexcept {
        if (handle != 0) {
            glDeleteVertexArrays(1, &handle);
        }
        handle = other.handle;
        other.handle = 0;
        return *this;
    }

    void VertexArray::bind() const {
        glBindVertexArray(handle);
    }

    void vertexAttribPointer(GLuint index, GLint n, VertexAttributeType type, bool normal, GLsizei stride, GLint offset) {
        glVertexAttribPointer(index, n, static_cast<GLenum>(type), normal, stride, reinterpret_cast<const void*>(offset));
        glEnableVertexAttribArray(index);
    }

    void disableVertexAttribArray(GLuint index) {
        glDisableVertexAttribArray(index);
    }

} // namespace showdown::gl
