
#include "gl/Shader.hpp"

namespace showdown::gl {

    Shader::Shader(ShaderType type) {
        handle = glCreateShader(static_cast<GLenum>(type));
    }

    Shader::Shader(Shader&& other) noexcept {
        handle = other.handle;
        other.handle = 0;
    }

    Shader::~Shader() {
        glDeleteShader(handle);
    }

    Shader& Shader::operator=(Shader&& other) noexcept {
        handle = other.handle;
        other.handle = 0;
        return *this;
    }

    void Shader::source(const std::string& source) const {
        const char* csource = source.c_str();
        glShaderSource(handle, 1, &csource, nullptr);
    }

    void Shader::source(const char* source) const {
        glShaderSource(handle, 1, &source, nullptr);
    }

    bool Shader::compile() const {
        glCompileShader(handle);
        GLint status;
        glGetShaderiv(handle, GL_COMPILE_STATUS, &status);
        return status == GL_TRUE;
    }

    std::string Shader::getInfoLog() const {
        GLint length;
        glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &length);
        char* log = new char[length];
        glGetShaderInfoLog(handle, length, nullptr, log);
        std::string result(log);
        delete[] log;
        return result;
    }

    GLuint Shader::getHandle() const {
        return handle;
    }

} // namespace showdown::gl