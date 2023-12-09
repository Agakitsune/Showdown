
#pragma once

#include <type_traits>

namespace showdown {

    template<typename T>
    requires std::is_class_v<T>
    struct file;

    template<typename T>
    concept is_file_constructible = requires(T t) {
        { file<T>() };
    };

}
