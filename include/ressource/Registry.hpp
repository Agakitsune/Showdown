
#pragma once

#include <unordered_map>
#include <string>
#include <any>
#include <type_traits>
#include <typeindex>
#include <filesystem>
#include <algorithm>

#include "RegistryKey.hpp"
#include "file.hpp"

namespace showdown {
    
    template<typename T>
    requires std::is_class_v<T>
    class Registry;

    class ARegistry {
        public:
            ARegistry() = default;
            virtual ~ARegistry() = default;

            virtual std::vector<RegistryKey> keys() const = 0;

            virtual void file(const RegistryKey &key, const std::string &path) = 0;
            virtual bool isFileRegistry() const = 0;

            void parse(const std::string &path) {
                if (!std::filesystem::exists(path))
                    throw std::runtime_error("Path '" + path + "' does not exist");
                if (!std::filesystem::is_directory(path))
                    throw std::runtime_error("Path '" + path + "' is not a directory");

                std::ranges::for_each(
                    std::filesystem::recursive_directory_iterator(path),
                    [this, &path](const std::filesystem::directory_entry &entry) {
                        if (entry.is_regular_file()) {
                            file(RegistryKey(std::filesystem::relative(entry.path(), std::filesystem::path(path)).replace_extension().string()), entry.path().string());
                        }
                    }
                );
            }

            void parse(const std::filesystem::path &path) {
                if (!std::filesystem::exists(path))
                    throw std::runtime_error("Path '" + path.string() + "' does not exist");
                if (!std::filesystem::is_directory(path))
                    throw std::runtime_error("Path '" + path.string() + "' is not a directory");

                std::ranges::for_each(
                    std::filesystem::recursive_directory_iterator(path),
                    [this, &path](const std::filesystem::directory_entry &entry) {
                        if (entry.is_regular_file()) {
                            file(RegistryKey(std::filesystem::relative(entry.path(), path).replace_extension().string()), entry.path().string());
                        }
                    }
                );
            }

            void parse(const std::filesystem::directory_entry &entry) {
                if (!entry.is_directory())
                    throw std::runtime_error("Path '" + entry.path().string() + "' is not a directory");

                std::ranges::for_each(
                    std::filesystem::recursive_directory_iterator(entry.path()),
                    [this, &entry](const std::filesystem::directory_entry &e) {
                        if (e.is_regular_file()) {
                            file(RegistryKey(std::filesystem::relative(e.path(), entry.path()).replace_extension().string()), e.path().string());
                        }
                    }
                );
            }

            void parse(const std::string &ns, const std::string &path) {
                if (!std::filesystem::exists(path))
                    throw std::runtime_error("Path '" + path + "' does not exist");
                if (!std::filesystem::is_directory(path))
                    throw std::runtime_error("Path '" + path + "' is not a directory");

                std::ranges::for_each(
                    std::filesystem::recursive_directory_iterator(path),
                    [this, &path, &ns](const std::filesystem::directory_entry &entry) {
                        if (entry.is_regular_file()) {
                            auto key = RegistryKey(ns, std::filesystem::relative(entry.path(), std::filesystem::path(path)).replace_extension().string());
                            std::cout << "Registering " << key << std::endl;
                            file(key, entry.path().string());
                        }
                    }
                );
            }

            void parse(const std::string &ns, const std::filesystem::path &path) {
                if (!std::filesystem::exists(path))
                    throw std::runtime_error("Path '" + path.string() + "' does not exist");
                if (!std::filesystem::is_directory(path))
                    throw std::runtime_error("Path '" + path.string() + "' is not a directory");

                std::ranges::for_each(
                    std::filesystem::recursive_directory_iterator(path),
                    [this, &path, &ns](const std::filesystem::directory_entry &entry) {
                        if (entry.is_regular_file()) {
                            auto key = RegistryKey(ns, std::filesystem::relative(entry.path(), path).replace_extension().string());
                            std::cout << "Registering " << key << std::endl;
                            file(key, entry.path().string());
                        }
                    }
                );
            }

            void parse(const std::string &ns, const std::filesystem::directory_entry &entry) {
                if (!entry.is_directory())
                    throw std::runtime_error("Path '" + entry.path().string() + "' is not a directory");

                std::ranges::for_each(
                    std::filesystem::recursive_directory_iterator(entry.path()),
                    [this, &entry, &ns](const std::filesystem::directory_entry &e) {
                        if (e.is_regular_file()) {
                            auto key = RegistryKey(ns, std::filesystem::relative(e.path(), entry.path()).replace_extension().string());
                            std::cout << "Registering " << key << std::endl;
                            file(key, e.path().string());
                        }
                    }
                );
            }

            template<typename T>
            requires std::is_base_of_v<ARegistry, T>
            T &as() {
                return dynamic_cast<T&>(*this);
            }
    };

    template<typename T>
    requires std::is_class_v<T>
    class Registry : public ARegistry {
        std::unordered_map<RegistryKey, std::unique_ptr<T>> _values;

        public:
            Registry() = default;
            virtual ~Registry() override = default;

            virtual std::vector<RegistryKey> keys() const override {
                std::vector<RegistryKey> keys;
                for (const auto &[key, value] : _values) {
                    keys.push_back(key);
                }
                return keys;
            }

            T &get(const RegistryKey &key) {
                try {
                    return *_values.at(key);
                } catch (const std::out_of_range &e) {
                    throw std::runtime_error("Key '" + key.string() + "' not found");
                }
            }

            const T &get(const RegistryKey &key) const {
                try {
                    return *_values.at(key);
                } catch (const std::out_of_range &e) {
                    throw std::runtime_error("Key '" + key.string() + "' not found");
                }
            }

            template<typename U>
            requires std::derived_from<U, T>
            void set(const RegistryKey &key, const U &value) {
                _values[key] = std::make_unique<U>(value);
            }

            template<typename U>
            requires std::derived_from<U, T>
            void set(const RegistryKey &key, U &&value) {
                _values[key] = std::make_unique<U>(std::move(value));
            }

            virtual void file(const RegistryKey &key, const std::string &path) override {
                if constexpr (is_file_constructible<T>) {
                    _values[key] = showdown::file<T>{}(path);
                }
            }

            virtual bool isFileRegistry() const override {
                return showdown::is_file_constructible<T>;
            }

            template<typename... Args>
            requires std::is_constructible_v<T, Args...>
            T &emplace(const RegistryKey &key, Args &&... args) {
                return _values.emplace(key, std::make_unique<T>(std::forward<Args>(args)...)).first->second;
            }

            template<typename... Args>
            requires std::is_constructible_v<T, Args...>
            T &emplace(RegistryKey &&key, Args &&... args) {
                return _values.emplace(std::move(key), std::make_unique<T>(std::forward<Args>(args)...)).first->second;
            }

            T &operator[](const RegistryKey &key) {
                return *_values[key];
            }

            T &operator[](RegistryKey &&key) {
                return *_values[std::move(key)];
            }

            bool contains(const RegistryKey &key) const {
                return _values.contains(key);
            }

            bool contains(RegistryKey &&key) const {
                return _values.contains(std::move(key));
            }

            T *find_if(const std::function<bool(const RegistryKey &, const T &)> &predicate) {
                for (auto &[key, value] : _values) {
                    if (predicate(key, *value))
                        return value.get();
                }
                return nullptr;
            }

            void erase(const RegistryKey &key) {
                _values.erase(key);
            }

            void erase(RegistryKey &&key) {
                _values.erase(std::move(key));
            }

            void clear() {
                _values.clear();
            }

            size_t size() const {
                return _values.size();
            }

            bool empty() const {
                return _values.empty();
            }

            typename std::unordered_map<RegistryKey, std::unique_ptr<T>>::iterator begin() {
                return _values.begin();
            }

            typename std::unordered_map<RegistryKey, std::unique_ptr<T>>::iterator end() {
                return _values.end();
            }

            typename std::unordered_map<RegistryKey, std::unique_ptr<T>>::const_iterator begin() const {
                return _values.begin();
            }

            typename std::unordered_map<RegistryKey, std::unique_ptr<T>>::const_iterator end() const {
                return _values.end();
            }

            typename std::unordered_map<RegistryKey, std::unique_ptr<T>>::const_iterator cbegin() const {
                return _values.cbegin();
            }

            typename std::unordered_map<RegistryKey, std::unique_ptr<T>>::const_iterator cend() const {
                return _values.cend();
            }
    };

    class FileRegistry : public ARegistry {
        std::unordered_map<RegistryKey, std::filesystem::path> _values;

        public:
            FileRegistry() = default;
            virtual ~FileRegistry() override = default;

            virtual std::vector<RegistryKey> keys() const override;

            std::filesystem::path &get(const RegistryKey &key);
            const std::filesystem::path &get(const RegistryKey &key) const;

            void set(const RegistryKey &key, const std::filesystem::path &value);
            void set(const RegistryKey &key, std::filesystem::path &&value);

            virtual void file(const RegistryKey &key, const std::string &path) override;
            virtual bool isFileRegistry() const override;

            template<typename... Args>
            requires std::is_constructible_v<std::filesystem::path, Args...>
            std::filesystem::path &emplace(const RegistryKey &key, Args &&... args) {
                return _values.emplace(key, std::filesystem::path(std::forward<Args>(args)...)).first->second;
            }

            template<typename... Args>
            requires std::is_constructible_v<std::filesystem::path, Args...>
            std::filesystem::path &emplace(RegistryKey &&key, Args &&... args) {
                return _values.emplace(std::move(key), std::filesystem::path(std::forward<Args>(args)...)).first->second;
            }

            std::filesystem::path &operator[](const RegistryKey &key);
            std::filesystem::path &operator[](RegistryKey &&key);

            bool contains(const RegistryKey &key) const;
            bool contains(RegistryKey &&key) const;

            std::filesystem::path *find_if(const std::function<bool(const RegistryKey &, const std::filesystem::path &)> &predicate);

            void erase(const RegistryKey &key);
            void erase(RegistryKey &&key);

            void clear();

            size_t size() const;

            bool empty() const;

            typename std::unordered_map<RegistryKey, std::filesystem::path>::iterator begin();
            typename std::unordered_map<RegistryKey, std::filesystem::path>::iterator end();
            typename std::unordered_map<RegistryKey, std::filesystem::path>::const_iterator begin() const;
            typename std::unordered_map<RegistryKey, std::filesystem::path>::const_iterator end() const;
            typename std::unordered_map<RegistryKey, std::filesystem::path>::const_iterator cbegin() const;
            typename std::unordered_map<RegistryKey, std::filesystem::path>::const_iterator cend() const;
    };

} // namespace showdown
