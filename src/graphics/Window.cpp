
#include "graphics/Window.hpp"

namespace showdown::graphics {
    
    Window::Window(int width, int height, const std::string &title) : _handle(width, height, title) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
    }

    Window::Window(int width, int height, std::string &&title) : _handle(width, height, title) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
    }

    Window::Window(int width, int height, const char *title) : _handle(width, height, title) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
    }

    Window::Window(Window &&other) noexcept : _handle(std::move(other._handle)) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
    }

    Window::~Window() {}
    
    Window &Window::operator=(Window &&other) noexcept {
        _handle = std::move(other._handle);
        return *this;
    }

    bool Window::isOpen() const {
        return !_handle.shouldClose();
    }

    void Window::close() const {
        _handle.close();
    }

    void Window::pollEvents() const {
        _handle.pollEvents();
    }

    void Window::usePipeline(const Pipeline &pipeline) {
        if (_lastPipeline)
            _lastPipeline->reset();
        _lastPipeline = &pipeline;
        pipeline.setup();
    }

    void Window::draw(const Drawable &drawable, const Pipeline *pipeline) const {
        if (pipeline) {
            if (pipeline != _lastPipeline) {
                _lastPipeline->reset();
                pipeline->setup();
                _lastPipeline = pipeline;
            }
        }
        if (_projector) {
            _projector->setup(*_lastPipeline);
        }
        drawable.setup(*_lastPipeline);
        drawable.draw(*this, *_lastPipeline);
    }

    void Window::draw(const Drawable &drawable, const float z, const Pipeline *pipeline) const {
        if (pipeline) {
            if (pipeline != _lastPipeline) {
                _lastPipeline->reset();
                pipeline->setup();
                _lastPipeline = pipeline;
            }
        }
        if (_projector) {
            _projector->setup(*_lastPipeline);
        }
        drawable.setup(*_lastPipeline);
        drawable.draw(*this, z, *_lastPipeline);
    }

    void Window::drawPrimitive(const showdown::gl::DrawMode mode, int first, int count) const {
        _handle.drawArrays(mode, first, count);
    }

    void Window::clear(const color &color) const {
        glClearColor(color.r, color.g, color.b, color.a);
        _handle.clear(showdown::gl::ClearMask::ColorDepth);
    }

    void Window::display() const {
        _handle.swapBuffers();
    }

}
