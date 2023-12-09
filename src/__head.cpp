
#include "__head.h"

#include "glfw/Window.hpp"
#include "graphics/Pipeline.hpp"
#include "graphics/pipeline/ShapePipeline.hpp"
#include "graphics/pipeline/TexturePipeline.hpp"


void construct() {}

void destruct() {
    showdown::glfw::Window::terminate();
}
