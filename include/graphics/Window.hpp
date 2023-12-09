
#pragma once

#include <memory>

#include "glfw/Window.hpp"
#include "graphics/Pipeline.hpp"
#include "graphics/Drawable.hpp"
#include "graphics/Projector.hpp"
#include "graphics/Color.hpp"

// #include "ressource/Manager.hpp"

namespace showdown {

    class RegistryKey;

}

namespace showdown::graphics {

    class Window {
        glfw::Window _handle;
        mutable const Pipeline *_lastPipeline = nullptr;
        std::unique_ptr<Projector> _projector = nullptr;

        public:
            Window(int width, int height, const std::string &title);
            Window(int width, int height, std::string &&title);
            Window(int width, int height, const char *title);

            Window(const Window &other) = delete;
            Window(Window &&other) noexcept;

            ~Window();
            
            Window &operator=(const Window &other) = delete;
            Window &operator=(Window &&other) noexcept;

            bool isOpen() const;
            void close() const;

            void pollEvents() const;

            void usePipeline(const Pipeline &pipeline);
            void usePipeline(const RegistryKey &pipeline);

            template<typename T>
            requires std::is_base_of_v<Projector, T>
            void useProjector(const T &projector) {
                _projector = std::make_unique<T>(projector);
            }

            void draw(const Drawable &drawable) const;
            void draw(const Drawable &drawable, const float z) const;
            void draw(const Drawable &drawable, const Pipeline &pipeline) const;
            void draw(const Drawable &drawable, const float z, const Pipeline &pipeline) const;
            void drawPrimitive(const showdown::gl::DrawMode mode, int first, int count) const;

            void clear(const color &color = black) const;

            void display() const;
    };

}
