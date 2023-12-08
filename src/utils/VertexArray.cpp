
#include "utils/VertexArray.hpp"

namespace showdown::utils {

    void disableAll() {
        for (GLuint i = 0; i < 16; i++) {
            gl::disableVertexAttribArray(i);
        }
    }

}
