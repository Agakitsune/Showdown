
#pragma once

#include "math/matrix.hpp"
#include "math/vector3.hpp"

namespace showdown::utils {

    /**
     * @brief Returns an orthographic projection matrix.
     * 
     * @param left The coordinate for the left vertical clipping plane.
     * @param right The coordinate for the right vertical clipping plane.
     * @param bottom The coordinate for the bottom horizontal clipping plane.
     * @param top The coordinate for the top horizontal clipping plane.
     * @param near The distance to the near clipping plane.
     * @param far The distance to the far clipping plane.
     * @return math::matrix<4, 4, float> The orthographic projection matrix.
     */
    math::matrix<4, 4, float> ortho(float left, float top, float right, float bottom, float near, float far);

    /**
     * @brief Returns a perspective projection matrix.
     * 
     * @param fov The field of view angle in degrees.
     * @param aspect The aspect ratio of the projection.
     * @param near The distance to the near clipping plane.
     * @param far The distance to the far clipping plane.
     * @return math::matrix<4, 4, float> The perspective projection matrix.
     */
    math::matrix<4, 4, float> perspective(float fov, float aspect, float near, float far);

    /**
     * @brief Returns a view matrix.
     * 
     * @param eye The position of the camera.
     * @param center The position of the object the camera is looking at.
     * @param up The up vector of the camera.
     * @return math::matrix<4, 4, float> The view matrix.
     */
    math::matrix<4, 4, float> lookAt(math::vector<3, float> eye, math::vector<3, float> center, math::vector<3, float> up);

} // namespace showdown::util
