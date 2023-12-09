
#include "graphics/pipeline/ShapePipeline.hpp"

namespace showdown::graphics {

    void ShapePipeline::setup() const {
        std::cout << "ShapePipeline::setup()" << std::endl;
        // Pipeline::setup();

        showdown::utils::useVertex<showdown::math::vec2f, showdown::math::vec4f>(0);
    }

}
