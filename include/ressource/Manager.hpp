
#pragma once

#include <memory>
#include <unordered_map>
#include <filesystem>
#include <algorithm>

#include "Registry.hpp"
#include "RegistryKey.hpp"

#include "graphics/Texture.hpp"
#include "graphics/Pipeline.hpp"

namespace showdown {

    template<>
    struct file<graphics::Texture> {
        std::unique_ptr<graphics::Texture> operator()(const std::string &path);
    };

    template<>
    struct file<graphics::Pipeline> {
        std::unique_ptr<graphics::Pipeline> operator()(const std::string &path);
    };

    class Manager {
        static std::unique_ptr<Manager> _instance;

        std::unordered_map<std::string, std::filesystem::path> _projects;
        std::unordered_map<RegistryKey, std::unique_ptr<ARegistry>> _values;

        ARegistry &get(const RegistryKey &key);

        public:
            static Manager &instance();

            template<typename T>
            requires std::is_base_of_v<ARegistry, T>
            void emplace(const RegistryKey &key) {
                _values[key] = std::make_unique<T>();
            }

            template<typename T>
            requires std::is_class_v<T> && std::negation_v<std::is_base_of<ARegistry, T>>
            void emplaceRegistry(const RegistryKey &key) {
                _values[key] = std::make_unique<Registry<T>>();
            }

            template<typename T>
            requires std::is_base_of_v<ARegistry, T>
            static T &getRegistry(const RegistryKey &key) {
                return instance().get(key).as<T>();
            }

            template<typename T>
            requires std::is_base_of_v<ARegistry, T>
            static T &getRegistry(const std::string &key) {
                return instance().get(RegistryKey::of(key)).as<T>();
            }

            void setProject(const std::string &name, const std::string &path);
            void addProject(const std::string &name, const std::string &path);

            template<typename T>
            requires std::is_base_of_v<ARegistry, T>
            void load(const std::string &project, const std::string &directory) {
                if (_projects.find(project) == _projects.end())
                    throw std::runtime_error("Project '" + project + "' not found");

                if (std::filesystem::exists(_projects[project] / directory)) {
                    if (_values.contains(RegistryKey(directory))) {
                        std::cout << "Registry " << directory << " already loaded" << std::endl;
                    } else {
                        _values[RegistryKey(project, directory)] = std::make_unique<T>();
                        std::cout << "Loading registry " << directory << std::endl;
                        auto &registry = _values[RegistryKey(project, directory)];
                        // if (registry->isFileRegistry())
                            registry->parse(project, _projects[project] / directory);
                        // else
                            // std::cout << "Registry " << directory << " is not a file Registry" << std::endl;
                    }
                } else {
                    std::cout << "Directory " << (_projects[project] / directory) << " doesn't exist" << std::endl;
                }
            }

            std::filesystem::path locateFile(const std::string &project, const std::string &path) const;
    };

}
