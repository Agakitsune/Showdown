
#pragma once

#include "graphics/Pipeline.hpp"
#include "utils/VertexArray.hpp"

namespace showdown::graphics {

    class ShapePipeline : public Pipeline {
        public:
            using Pipeline::Pipeline;
            virtual ~ShapePipeline() override = default;

            virtual void setup() const override;
    };

}
