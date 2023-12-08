
#pragma once

#include "math/math.hpp"
#include "graphics/Projector.hpp"
#include "utils/Clip.hpp"

namespace showdown::graphics {

    class OrthographicProjector : public Projector {
        math::matrix<4, 4, float> projection;

        public:
            OrthographicProjector(const float width, const float height);
            OrthographicProjector(const math::vec2f &size);
            OrthographicProjector(const OrthographicProjector &other) = default;
            OrthographicProjector(OrthographicProjector &&other) noexcept = default;

            virtual ~OrthographicProjector() override = default;

            OrthographicProjector &operator=(const OrthographicProjector &other) = default;
            OrthographicProjector &operator=(OrthographicProjector &&other) noexcept = default;

            virtual void setup(const Pipeline &pipeline) const override;
    };

}
