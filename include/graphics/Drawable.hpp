
#pragma once

namespace showdown::graphics {

    class Window;
    class Pipeline;

    class Drawable {
        public:
            Drawable() = default;
            virtual ~Drawable() = default;

            virtual void draw(const Window &window, const Pipeline &pipeline) const = 0;
            virtual void draw(const Window &window, const float z, const Pipeline &pipeline) const = 0;
            virtual void setup(const Pipeline &pipeline) const = 0;
    };

}