
#pragma once

#include <string>
#include <iostream>
#include <functional>

// #include "exception/RegistryException.hpp"

namespace showdown {
    
    class RegistryKey {
        std::string ns;
        std::string name;

        static std::string _default;

        static bool checkNamespace(char c);
        static bool checkName(char c);

        public:
            explicit RegistryKey(const std::string &name);
            explicit RegistryKey(const std::string &ns, const std::string &name);
            RegistryKey(const RegistryKey &other);
            RegistryKey(RegistryKey &&other);
            ~RegistryKey() = default;

            static void setDefaultNamespace(const std::string &ns);
            static RegistryKey of(const std::string &value);

            RegistryKey &operator=(const RegistryKey &other);
            RegistryKey &operator=(RegistryKey &&other);

            bool operator==(const RegistryKey &other) const;

            const std::string &getNamespace() const;
            const std::string &getName() const;

            std::string string() const;
    };

    std::ostream &operator<<(std::ostream &os, const RegistryKey &key);

} // namespace showdown

template<>
struct std::hash<showdown::RegistryKey> {
    size_t operator()(const showdown::RegistryKey &key) const {
        return std::hash<std::string>()(key.string());
    }
};
