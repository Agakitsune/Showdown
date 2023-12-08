
#pragma once

#include "gl/Texture.hpp"

namespace showdown::utils {

    gl::Texture loadTexture(const std::string &path);
    gl::Texture loadDefault();

    static gl::Texture defaultTexture;
    static bool defaultTextureLoaded = false;

}
