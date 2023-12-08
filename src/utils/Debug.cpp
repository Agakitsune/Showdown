
#include "utils/Debug.hpp"

namespace showdown {

    std::ostream &debug(const std::string &context) {
        return std::cout << "[DEBUG <" << context << ">] ";
    }

}
