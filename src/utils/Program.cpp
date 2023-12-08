
#include "utils/Program.hpp"

#include "utils/Shader.hpp"

namespace showdown::utils {

    gl::Program loadProgram(const std::string &vertexPath, const std::string &fragmentPath) {
        gl::Program program;
        gl::Shader vertexShader = loadShader(vertexPath, gl::ShaderType::Vertex);
        gl::Shader fragmentShader = loadShader(fragmentPath, gl::ShaderType::Fragment);

        program.attach(vertexShader);
        program.attach(fragmentShader);
        program.link();

        return program;
    }

    gl::Program loadProgram(const std::string &vertexPath, const std::string &geometryPath, const std::string &fragmentPath) {
        gl::Program program;
        gl::Shader vertexShader = loadShader(vertexPath, gl::ShaderType::Vertex);
        gl::Shader geometryShader = loadShader(geometryPath, gl::ShaderType::Geometry);
        gl::Shader fragmentShader = loadShader(fragmentPath, gl::ShaderType::Fragment);

        program.attach(vertexShader);
        program.attach(fragmentShader);
        program.attach(geometryShader);
        program.link();

        return program;
    }

}
