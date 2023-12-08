
#pragma once

#include "gl/Program.hpp"

namespace showdown::utils {

    gl::Program loadProgram(const std::string &vertexPath, const std::string &fragmentPath);
    gl::Program loadProgram(const std::string &vertexPath, const std::string &fragmentPath, const std::string &geometryPath);

}
