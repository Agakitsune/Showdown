
#pragma once

#include <filesystem>
#include <fstream>

#include "json.hpp"
#include "graphics/Pipeline.hpp"

namespace showdown::utils {

    std::unique_ptr<graphics::Pipeline> fromJson(const std::string &path);

}
