
#include "ressource/Manager.hpp"

#include "utils/Pipeline.hpp"

namespace showdown {

    std::unique_ptr<graphics::Texture> file<graphics::Texture>::operator()(const std::string &path) {
        auto ptr = std::make_unique<graphics::Texture>(path);
        return ptr;
    }

    std::unique_ptr<graphics::Pipeline> file<graphics::Pipeline>::operator()(const std::string &path) {
        auto ptr = utils::fromJson(path);
        return ptr;
    }

    Manager &Manager::instance() {
        if (!_instance) {
            _instance = std::make_unique<Manager>();
        }
        return *_instance;
    }

    ARegistry &Manager::get(const RegistryKey &key) {
        if (!_values.contains(key))
            throw std::runtime_error("Registry '" + key.string() + "' not found");
        return *_values[key];
    }

    void Manager::setProject(const std::string &name, const std::string &path) {
        RegistryKey::setDefaultNamespace(name);
        
        addProject(name, path);
    }

    void Manager::addProject(const std::string &name, const std::string &path) {
        if (!std::filesystem::exists(path))
            throw std::runtime_error("Path '" + path + "' does not exist");
        if (!std::filesystem::is_directory(path))
            throw std::runtime_error("Path '" + path + "' is not a directory");

        _projects[name] = path;
    }

    std::filesystem::path Manager::locateFile(const std::string &project, const std::string &path) const {
        std::filesystem::path p(path);
        if (std::filesystem::exists(p))
            return p;
        if (_projects.find(project) == _projects.end()) {
            throw std::runtime_error("Project '" + project + "' not found");
        } else {
            p = _projects.at(project) / path;
            if (std::filesystem::exists(p))
                return p;
        }
        throw std::runtime_error("File '" + path + "' not found");
    }

    std::unique_ptr<Manager> Manager::_instance = nullptr;

}
