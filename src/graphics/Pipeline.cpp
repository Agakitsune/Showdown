
#include "graphics/Pipeline.hpp"

namespace showdown::graphics {

    Pipeline::Pipeline(const std::string &vertexPath, const std::string &fragmentPath) {
        _program = utils::loadProgram(vertexPath, fragmentPath);
    }

    Pipeline::Pipeline(const std::string &vertexPath, const std::string &geometryPath, const std::string &fragmentPath) {
        _program = utils::loadProgram(vertexPath, geometryPath, fragmentPath);
    }

    Pipeline::Pipeline(const gl::Program &program) : _program(program) {}

    Pipeline::Pipeline(gl::Program &&program) : _program(std::move(program)) {}

    void Pipeline::addShader(const std::string &path, const gl::ShaderType type) const {
        try {
            _program.attach(utils::loadShader(path, type));
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Pipeline::link() const {
        _program.link();
    }

    void Pipeline::use() const {
        _program.use();
    }

    // void Pipeline::setup() const;

    void Pipeline::reset() const {
        showdown::utils::disableAll();
    }

    void Pipeline::set(const std::string &uniform, GLfloat v0) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0);
    }

    void Pipeline::set(const std::string &uniform, GLfloat v0, GLfloat v1) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0, v1);
    }

    void Pipeline::set(const std::string &uniform, GLfloat v0, GLfloat v1, GLfloat v2) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0, v1, v2);
    }

    void Pipeline::set(const std::string &uniform, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0, v1, v2, v3);
    }

    void Pipeline::set(const std::string &uniform, GLint v0) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0);
    }

    void Pipeline::set(const std::string &uniform, GLint v0, GLint v1) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0, v1);
    }

    void Pipeline::set(const std::string &uniform, GLint v0, GLint v1, GLint v2) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0, v1, v2);
    }

    void Pipeline::set(const std::string &uniform, GLint v0, GLint v1, GLint v2, GLint v3) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0, v1, v2, v3);
    }

    void Pipeline::set(const std::string &uniform, GLuint v0) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0);
    }

    void Pipeline::set(const std::string &uniform, GLuint v0, GLuint v1) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0, v1);
    }

    void Pipeline::set(const std::string &uniform, GLuint v0, GLuint v1, GLuint v2) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0, v1, v2);
    }

    void Pipeline::set(const std::string &uniform, GLuint v0, GLuint v1, GLuint v2, GLuint v3) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(v0, v1, v2, v3);
    }

    void Pipeline::set(const std::string &uniform, GLsizei count, GLfloat *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(count, value);
    }

    void Pipeline::set(const std::string &uniform, GLsizei count, GLint *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(count, value);
    }

    void Pipeline::set(const std::string &uniform, GLsizei count, GLuint *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set(count, value);
    }

    void Pipeline::set2x2(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set2x2(count, transpose, value);
    }

    void Pipeline::set3x3(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set3x3(count, transpose, value);
    }

    void Pipeline::set4x4(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set4x4(count, transpose, value);
    }

    void Pipeline::set2x3(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set2x3(count, transpose, value);
    }

    void Pipeline::set3x2(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set3x2(count, transpose, value);
    }

    void Pipeline::set2x4(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set2x4(count, transpose, value);
    }

    void Pipeline::set4x2(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set4x2(count, transpose, value);
    }

    void Pipeline::set3x4(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set3x4(count, transpose, value);
    }

    void Pipeline::set4x3(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const {
        gl::Uniform u = _program.getUniform(uniform);
        if (!u.isValid())
            return;
        u.set4x3(count, transpose, value);
    }

    std::unordered_map<std::string, std::function<std::unique_ptr<Pipeline>()>> PipelineBuilder::_builders;

    void PipelineBuilder::registerPipeline(const std::string &name, const std::function<std::unique_ptr<Pipeline>()> &builder) {
        _builders[name] = builder;
    }

    std::unique_ptr<Pipeline> PipelineBuilder::buildPipeline(const std::string &name) {
        try {
            return _builders.at(name)();
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            return nullptr;
        }
    }

}
