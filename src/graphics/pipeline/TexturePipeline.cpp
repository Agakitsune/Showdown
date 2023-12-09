
#include "graphics/pipeline/TexturePipeline.hpp"

namespace showdown::graphics {

    void TexturePipeline::setup() const {
        std::cout << "TexturePipeline::setup()" << std::endl;
        // Pipeline::setup();

        showdown::utils::useVertex<showdown::math::vec2f, showdown::math::vec4f, showdown::math::vec2f>(0);
    }

}
