
#include "ressource/RegistryKey.hpp"

namespace showdown {

    bool RegistryKey::checkNamespace(char c) {
        if (!checkName(c) && c != '/')
            return false;
        return true;
    }

    bool RegistryKey::checkName(char c) {
        if (std::islower(c) || std::isdigit(c) || c == '_' || c == '-' || c == '.' || c == '/')
            return false;
        return true;
    }

    RegistryKey::RegistryKey(const std::string &name) {
        if (_default.empty())
            throw std::runtime_error("No default namespace set");
        if (auto it = std::find_if(name.begin(), name.end(), checkName); it != name.end())
            throw std::runtime_error("Invalid character '" + std::string(1, *it) + "' in name '" + name + "'");
        this->ns = _default;
        this->name = name;
    }

    RegistryKey::RegistryKey(const std::string &ns, const std::string &name) : ns(ns), name(name) {
        if (auto it = std::find_if(ns.begin(), ns.end(), checkNamespace); it != ns.end())
            throw std::runtime_error("Invalid character '" + std::string(1, *it) + "' in namespace '" + ns + "'");
        if (auto it = std::find_if(name.begin(), name.end(), checkName); it != name.end())
            throw std::runtime_error("Invalid character '" + std::string(1, *it) + "' in name '" + name + "'");
        this->ns = ns;
        this->name = name;
    }

    RegistryKey::RegistryKey(const RegistryKey &other) : ns(other.ns), name(other.name) {}

    RegistryKey::RegistryKey(RegistryKey &&other) : ns(std::move(other.ns)), name(std::move(other.name)) {}

    void RegistryKey::setDefaultNamespace(const std::string &ns) {
        if (auto it = std::find_if(ns.begin(), ns.end(), checkNamespace); it != ns.end())
            throw std::runtime_error("Invalid character '" + std::string(1, *it) + "' in namespace '" + ns + "'");
        if (_default.empty())
            _default = ns;
    }

    RegistryKey RegistryKey::of(const std::string &value) {
        if (value.find(':') == std::string::npos)
            return RegistryKey(_default, value);
        auto pos = value.find(':');
        return RegistryKey(value.substr(0, pos), value.substr(pos + 1));
    }

    RegistryKey &RegistryKey::operator=(const RegistryKey &other) {
        if (this != &other) {
            ns = other.ns;
            name = other.name;
        }
        return *this;
    }

    RegistryKey &RegistryKey::operator=(RegistryKey &&other) {
        if (this != &other) {
            ns = std::move(other.ns);
            name = std::move(other.name);
        }
        return *this;
    }

    bool RegistryKey::operator==(const RegistryKey &other) const {
        return ns == other.ns && name == other.name;
    }

    const std::string &RegistryKey::getNamespace() const {
        return ns;
    }

    const std::string &RegistryKey::getName() const {
        return name;
    }

    std::string RegistryKey::string() const {
        return ns + ":" + name;
    }

    std::ostream &operator<<(std::ostream &os, const RegistryKey &key) {
        return os << key.string();
    }

    std::string RegistryKey::_default = "";

}
