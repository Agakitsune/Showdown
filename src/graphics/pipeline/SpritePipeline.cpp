
#include "graphics/pipeline/SpritePipeline.hpp"

namespace showdown::graphics {

    void SpritePipeline::setup() const {
        Pipeline::setup();

        showdown::utils::useVertex<showdown::math::vec2f, showdown::math::vec3f, showdown::math::vec2f>(0);
    }

    void SpritePipeline::reset() const {
        showdown::utils::disableAll();
    }

}
