
#pragma once

#include "graphics/Pipeline.hpp"
#include "utils/VertexArray.hpp"

namespace showdown::graphics {

    class TexturePipeline : public Pipeline {
        public:
            using Pipeline::Pipeline;
            virtual ~TexturePipeline() override = default;

            virtual void setup() const override;
    };

}
