
#include "gl/Uniform.hpp"

namespace showdown::gl {
    
    Uniform::Uniform(GLint location) : location(location) {}

    Uniform::Uniform(const Uniform& other) : location(other.location) {}

    Uniform::Uniform(Uniform&& other) noexcept : location(other.location) {
        other.location = 0;
    }

    Uniform& Uniform::operator=(const Uniform& other) {
        location = other.location;
        return *this;
    }

    Uniform& Uniform::operator=(Uniform&& other) noexcept {
        location = other.location;
        other.location = 0;
        return *this;
    }

    bool Uniform::isValid() const {
        return location != -1;
    }

    void Uniform::set(GLfloat v0) const {
        // std::cout << location << std::endl;
        // std::cout << v0 << std::endl;
        glUniform1f(location, v0);
    }

    void Uniform::set(GLfloat v0, GLfloat v1) const {
        glUniform2f(location, v0, v1);
    }

    void Uniform::set(GLfloat v0, GLfloat v1, GLfloat v2) const {
        glUniform3f(location, v0, v1, v2);
    }

    void Uniform::set(GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) const {
        glUniform4f(location, v0, v1, v2, v3);
    }
    
    void Uniform::set(GLint v0) const {
        glUniform1i(location, v0);
    }

    void Uniform::set(GLint v0, GLint v1) const {
        glUniform2i(location, v0, v1);
    }

    void Uniform::set(GLint v0, GLint v1, GLint v2) const {
        glUniform3i(location, v0, v1, v2);
    }

    void Uniform::set(GLint v0, GLint v1, GLint v2, GLint v3) const {
        glUniform4i(location, v0, v1, v2, v3);
    }
    
    void Uniform::set(GLuint v0) const {
        glUniform1ui(location, v0);
    }

    void Uniform::set(GLuint v0, GLuint v1) const {
        glUniform2ui(location, v0, v1);
    }

    void Uniform::set(GLuint v0, GLuint v1, GLuint v2) const {
        glUniform3ui(location, v0, v1, v2);
    }

    void Uniform::set(GLuint v0, GLuint v1, GLuint v2, GLuint v3) const {
        glUniform4ui(location, v0, v1, v2, v3);
    }

    void Uniform::set(GLsizei count, GLfloat *value) const {
        glUniform1fv(location, count, value);
    }

    void Uniform::set(GLsizei count, GLint *value) const {
        glUniform1iv(location, count, value);
    }

    void Uniform::set(GLsizei count, GLuint *value) const {
        glUniform1uiv(location, count, value);
    }

    void Uniform::set2x2(GLsizei count, GLboolean transpose, GLfloat *value) const {
        glUniformMatrix2fv(location, count, transpose, value);
    }

    void Uniform::set3x3(GLsizei count, GLboolean transpose, GLfloat *value) const {
        glUniformMatrix3fv(location, count, transpose, value);
    }

    void Uniform::set4x4(GLsizei count, GLboolean transpose, GLfloat *value) const {
        glUniformMatrix4fv(location, count, transpose, value);
    }

    void Uniform::set2x3(GLsizei count, GLboolean transpose, GLfloat *value) const {
        glUniformMatrix2x3fv(location, count, transpose, value);
    }

    void Uniform::set3x2(GLsizei count, GLboolean transpose, GLfloat *value) const {
        glUniformMatrix3x2fv(location, count, transpose, value);
    }

    void Uniform::set2x4(GLsizei count, GLboolean transpose, GLfloat *value) const {
        glUniformMatrix2x4fv(location, count, transpose, value);
    }

    void Uniform::set4x2(GLsizei count, GLboolean transpose, GLfloat *value) const {
        glUniformMatrix4x2fv(location, count, transpose, value);
    }

    void Uniform::set3x4(GLsizei count, GLboolean transpose, GLfloat *value) const {
        glUniformMatrix3x4fv(location, count, transpose, value);
    }

    void Uniform::set4x3(GLsizei count, GLboolean transpose, GLfloat *value) const {
        glUniformMatrix4x3fv(location, count, transpose, value);
    }

} // namespace showdown::gl
