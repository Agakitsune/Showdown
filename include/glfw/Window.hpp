
#pragma once

#include <string>
#include <cmath>
#include <algorithm>

#include "gl/Utils.hpp"
#include "gl/Type.hpp"

#include "input/Keyboard.hpp"
#include "input/Mouse.hpp"
// #include "input/Joystick.hpp"

#include "math/math.hpp"

namespace showdown::glfw {
    
    enum class WindowAttribute {
        Focused = GLFW_FOCUSED,
        Iconified = GLFW_ICONIFIED,
        Resizable = GLFW_RESIZABLE,
        Visible = GLFW_VISIBLE,
        Decorated = GLFW_DECORATED,
        AutoIconify = GLFW_AUTO_ICONIFY,
        Floating = GLFW_FLOATING,
        Maximized = GLFW_MAXIMIZED,
        CenterCursor = GLFW_CENTER_CURSOR,
        TransparentFramebuffer = GLFW_TRANSPARENT_FRAMEBUFFER,
        Hovered = GLFW_HOVERED,
        FocusOnShow = GLFW_FOCUS_ON_SHOW,
        RedBits = GLFW_RED_BITS,
        GreenBits = GLFW_GREEN_BITS,
        BlueBits = GLFW_BLUE_BITS,
        AlphaBits = GLFW_ALPHA_BITS,
        DepthBits = GLFW_DEPTH_BITS,
        StencilBits = GLFW_STENCIL_BITS,
        AccumRedBits = GLFW_ACCUM_RED_BITS,
        AccumGreenBits = GLFW_ACCUM_GREEN_BITS,
        AccumBlueBits = GLFW_ACCUM_BLUE_BITS,
        AccumAlphaBits = GLFW_ACCUM_ALPHA_BITS,
        AuxBuffers = GLFW_AUX_BUFFERS,
        Stereo = GLFW_STEREO,
        Samples = GLFW_SAMPLES,
        SRGBCapable = GLFW_SRGB_CAPABLE,
        RefreshRate = GLFW_REFRESH_RATE,
        DoubleBuffer = GLFW_DOUBLEBUFFER,
        ClientAPI = GLFW_CLIENT_API,
        ContextVersionMajor = GLFW_CONTEXT_VERSION_MAJOR,
        ContextVersionMinor = GLFW_CONTEXT_VERSION_MINOR,
        ContextRevision = GLFW_CONTEXT_REVISION,
        ContextRobustness = GLFW_CONTEXT_ROBUSTNESS,
        OpenGLForwardCompat = GLFW_OPENGL_FORWARD_COMPAT,
        OpenGLDebugContext = GLFW_OPENGL_DEBUG_CONTEXT,
        OpenGLProfile = GLFW_OPENGL_PROFILE,
        ContextReleaseBehavior = GLFW_CONTEXT_RELEASE_BEHAVIOR,
        ContextNoError = GLFW_CONTEXT_NO_ERROR,
        ContextCreationAPI = GLFW_CONTEXT_CREATION_API,
        ScaleToMonitor = GLFW_SCALE_TO_MONITOR,
        CocoaRetinaFramebuffer = GLFW_COCOA_RETINA_FRAMEBUFFER,
        CocoaFrameName = GLFW_COCOA_FRAME_NAME,
        CocoaGraphicsSwitching = GLFW_COCOA_GRAPHICS_SWITCHING,
        X11ClassName = GLFW_X11_CLASS_NAME,
        X11InstanceName = GLFW_X11_INSTANCE_NAME,
    };

    class Window {
        GLFWwindow *handle;

        double xoffset = 0;
        double yoffset = 0;

        static Window *current;

        static bool _init;
        static bool _glewInit;
        static bool defaultHints;

        static void init();
        static void glewInit();

        static void resizeCallback(GLFWwindow *window, int width, int height);
        static void scrollCallback(GLFWwindow *window, double xoffset, double yoffset);

        public:
            static void terminate();

            Window(int width, int height, const std::string &title);
            Window(int width, int height, std::string &&title);
            Window(int width, int height, const char *title);

            Window(const Window &other) = delete;
            Window(Window &&other) noexcept;

            ~Window();

            Window &operator=(const Window &other) = delete;
            Window &operator=(Window &&other) noexcept;

            bool shouldClose() const;
            void close() const;
            
            void setTitle(const std::string &title);
            void setTitle(std::string &&title);
            void setTitle(const char *title);

            math::vec2i getPos() const;
            math::vec2i getSize() const;
            math::vec2i getFramebufferSize() const;

            void setPos(int x, int y);
            void setPos(const math::vec2i &pos);

            void setSize(int width, int height);
            void setSize(const math::vec2i &size);

            int getAttribute(WindowAttribute attrib) const;
            void setAttribute(WindowAttribute attrib, int value);

            void pollEvents() const;
            void waitEvents() const;
            void waitEvents(double timeout) const;
            
            void swapBuffers() const;

            void drawArrays(gl::DrawMode mode, GLint first, GLsizei count) const;

            void clear(gl::ClearMask mask) const;

            bool isKeyPressed(const input::Key key) const;
            bool isKeyReleased(const input::Key key) const;

            bool isMouseButtonPressed(const input::MouseButton button) const;
            bool isMouseButtonReleased(const input::MouseButton button) const;

            showdown::math::vec2d getMousePos() const;
            void setMousePos(double x, double y) const;
            void setMousePos(const showdown::math::vec2d &pos) const;
            
            showdown::math::vec2d getMouseScroll() const;

            void showCursor() const;
            void hideCursor() const;
            void lockCursor() const;
            void unlockCursor() const;

            static void setHint(WindowAttribute attrib, int value);
            static void setHint(WindowAttribute attrib, const std::string &value);
            static void setHint(WindowAttribute attrib, std::string &&value);
            static void setHint(WindowAttribute attrib, const char *value);

    };

} // namespace showdown::glfw
