
#include "graphics/Window.hpp"
#include "graphics/projector/OrthographicProjector.hpp"
#include "ressource/Manager.hpp"

namespace showdown::graphics {
    
    void APIENTRY glDebugOutput(GLenum source, 
                            GLenum type, 
                            unsigned int id, 
                            GLenum severity, 
                            GLsizei length, 
                            const char *message, 
                            const void *userParam)
    {
        // ignore non-significant error/warning codes
        if(id == 131169 || id == 131185 || id == 131218 || id == 131204) return; 

        std::cout << "---------------" << std::endl;
        std::cout << "Debug message (" << id << "): " <<  message << std::endl;

        switch (source)
        {
            case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
            case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
            case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
            case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
            case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
        } std::cout << std::endl;

        switch (type)
        {
            case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break; 
            case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
            case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
            case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
            case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
            case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
            case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
        } std::cout << std::endl;
        
        switch (severity)
        {
            case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
            case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
            case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
            case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
        } std::cout << std::endl;
        std::cout << std::endl;
    }

    Window::Window(int width, int height, const std::string &title) : _handle(width, height, title) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        int flags; glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
        if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS); 
            glDebugMessageCallback(glDebugOutput, nullptr);
            glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
        }
        useProjector(OrthographicProjector(width, height));
    }

    Window::Window(int width, int height, std::string &&title) : _handle(width, height, title) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        int flags; glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
        if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS); 
            glDebugMessageCallback(glDebugOutput, nullptr);
            glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
        }
        useProjector(OrthographicProjector(width, height));
    }

    Window::Window(int width, int height, const char *title) : _handle(width, height, title) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        int flags; glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
        if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(glDebugOutput, nullptr);
            glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
        }
        useProjector(OrthographicProjector(width, height));
    }

    Window::Window(Window &&other) noexcept : _handle(std::move(other._handle)) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        _projector = std::move(other._projector);
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

    void Window::usePipeline(const RegistryKey &pipeline) {
        try {
            auto &pipe = Manager::getRegistry<Registry<graphics::Pipeline>>("pipeline").get(pipeline);
            usePipeline(pipe);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Window::draw(const Drawable &drawable) const {
        drawable.draw(*this);
    }

    void Window::draw(const Drawable &drawable, const float z) const {
        drawable.draw(*this, z);
    }

    void Window::draw(const Drawable &drawable, const Pipeline &pipeline) const {
        bool changed = false;
        if (&pipeline != _lastPipeline) {
            if (_lastPipeline)
                _lastPipeline->reset();
            pipeline.use();
            _lastPipeline = &pipeline;
            changed = true;
        }
        if (_projector) {
            _projector->setup(*_lastPipeline);
        }
        drawable.setup(*_lastPipeline);
        if (changed) {
            pipeline.setup();
        }
        drawable.draw(*this, *_lastPipeline);
    }

    void Window::draw(const Drawable &drawable, const float z, const Pipeline &pipeline) const {
        bool changed = false;
        if (&pipeline != _lastPipeline) {
            if (_lastPipeline)
                _lastPipeline->reset();
            pipeline.use();
            _lastPipeline = &pipeline;
            changed = true;
        }
        if (_projector) {
            _projector->setup(*_lastPipeline);
        }
        drawable.setup(*_lastPipeline);
        if (changed) {
            pipeline.setup();
        }
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
