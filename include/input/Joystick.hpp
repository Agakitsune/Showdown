
#pragma once

#include "gl/Utils.hpp"

namespace showdown::input {

    enum Joystick {
        Joystick1 = GLFW_JOYSTICK_1,
        Joystick2 = GLFW_JOYSTICK_2,
        Joystick3 = GLFW_JOYSTICK_3,
        Joystick4 = GLFW_JOYSTICK_4,
        Joystick5 = GLFW_JOYSTICK_5,
        Joystick6 = GLFW_JOYSTICK_6,
        Joystick7 = GLFW_JOYSTICK_7,
        Joystick8 = GLFW_JOYSTICK_8,
        Joystick9 = GLFW_JOYSTICK_9,
        Joystick10 = GLFW_JOYSTICK_10,
        Joystick11 = GLFW_JOYSTICK_11,
        Joystick12 = GLFW_JOYSTICK_12,
        Joystick13 = GLFW_JOYSTICK_13,
        Joystick14 = GLFW_JOYSTICK_14,
        Joystick15 = GLFW_JOYSTICK_15,
        Joystick16 = GLFW_JOYSTICK_16,
        JoystickCount
    };

    enum class JoystickAxis {
        LeftX,
        LeftY,
        RightX,
        RightY,
        LeftTrigger,
        RightTrigger
    };

    enum class JoystickFullAxis {
        Left,
        Right,
        Trigger
    };

    struct JoystickDeadZone {
        float leftZone = 0.1f;
        float rightZone = 0.1f;
        float triggerZone = 0.0f;
    };

    enum class JoystickButton {
        A = GLFW_GAMEPAD_BUTTON_A,
        B = GLFW_GAMEPAD_BUTTON_B,
        X = GLFW_GAMEPAD_BUTTON_X,
        Y = GLFW_GAMEPAD_BUTTON_Y,
        LeftBumper = GLFW_GAMEPAD_BUTTON_LEFT_BUMPER,
        RightBumper = GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER,
        Back = GLFW_GAMEPAD_BUTTON_BACK,
        Start = GLFW_GAMEPAD_BUTTON_START,
        Guide = GLFW_GAMEPAD_BUTTON_GUIDE,
        LeftThumb = GLFW_GAMEPAD_BUTTON_LEFT_THUMB,
        RightThumb = GLFW_GAMEPAD_BUTTON_RIGHT_THUMB,
        DpadUp = GLFW_GAMEPAD_BUTTON_DPAD_UP,
        DpadRight = GLFW_GAMEPAD_BUTTON_DPAD_RIGHT,
        DpadDown = GLFW_GAMEPAD_BUTTON_DPAD_DOWN,
        DpadLeft = GLFW_GAMEPAD_BUTTON_DPAD_LEFT,
        // PS4 compatibility
        Cross = GLFW_GAMEPAD_BUTTON_CROSS,
        Circle = GLFW_GAMEPAD_BUTTON_CIRCLE,
        Square = GLFW_GAMEPAD_BUTTON_SQUARE,
        Triangle = GLFW_GAMEPAD_BUTTON_TRIANGLE,
        // Switch compatibility
        NintendoB = A,
        NintendoA = B,
        NintendoY = X,
        NintendoX = Y,
    };

} // namespace showdown::input
