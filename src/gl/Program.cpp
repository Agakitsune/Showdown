
#include "gl/Program.hpp"

namespace showdown::gl {
    
    Program::Program() {
        handle = glCreateProgram();
        refCount = new size_t(1);
    }

    Program::Program(const Program& other) {
        handle = other.handle;
        refCount = other.refCount;
        (*refCount)++;
    }

    Program::Program(Program&& other) noexcept {
        handle = other.handle;
        refCount = other.refCount;
        other.handle = 0;
        other.refCount = nullptr;
    }

    Program::~Program() {
        if (handle != 0 && (!refCount || --(*refCount) == 0)) {
            glDeleteProgram(handle);
        }
    }

    Program& Program::operator=(const Program& other) {
        handle = other.handle;
        refCount = other.refCount;
        (*refCount)++;
        return *this;
    }

    Program& Program::operator=(Program&& other) noexcept {
        handle = other.handle;
        refCount = other.refCount;
        other.handle = 0;
        other.refCount = nullptr;
        return *this;
    }

    void Program::attach(const Shader& shader) const {
        glAttachShader(handle, shader.getHandle());
    }

    void Program::detach(const Shader& shader) const {
        glDetachShader(handle, shader.getHandle());
    }

    void Program::link() const {
        glLinkProgram(handle);
    }

    std::string Program::getInfoLog() const {
        GLint length;
        glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &length);
        char* log = new char[length];
        glGetProgramInfoLog(handle, length, nullptr, log);
        std::string result(log);
        delete[] log;
        return result;
    }

    void Program::use() const {
        glUseProgram(handle);
    }

    Uniform Program::getUniform(const std::string& name) const {
        return Uniform(glGetUniformLocation(handle, name.c_str()));
    }

} // namespace showdown::gl
