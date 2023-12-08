
#include "graphics/projector/OrthographicProjector.hpp"
#include "graphics/Pipeline.hpp"

namespace showdown::graphics {

    OrthographicProjector::OrthographicProjector(const float width, const float height) {
        projection = utils::ortho(0.0f, 0.0f, width, height, std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
    }

    OrthographicProjector::OrthographicProjector(const math::vec2f &size) {
        projection = utils::ortho(0.0f, 0.0f, size.x, size.y, std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
    }

    void OrthographicProjector::setup(const Pipeline &pipeline) const {
        pipeline.set4x4("projection", 1, true, const_cast<GLfloat*>(&projection[0][0]));
    }

}