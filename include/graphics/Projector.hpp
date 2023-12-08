
#pragma once

namespace showdown::graphics {

    class Pipeline;

    class Projector {
        public:
            Projector() = default;
            virtual ~Projector() = default;

            virtual void setup(const Pipeline &pipeline) const = 0;
    };

}
