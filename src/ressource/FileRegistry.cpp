
#include "ressource/Registry.hpp"

namespace showdown {

    std::vector<RegistryKey> FileRegistry::keys() const {
        std::vector<RegistryKey> keys;
        for (const auto &[key, value] : _values) {
            keys.push_back(key);
        }
        return keys;
    }

    std::filesystem::path &FileRegistry::get(const RegistryKey &key) {
        return _values.at(key);
    }

    const std::filesystem::path &FileRegistry::get(const RegistryKey &key) const {
        return _values.at(key);
    }

    void FileRegistry::set(const RegistryKey &key, const std::filesystem::path &value) {
        _values[key] = value;
    }

    void FileRegistry::set(const RegistryKey &key, std::filesystem::path &&value) {
        _values[key] = std::move(value);
    }

    void FileRegistry::file(const RegistryKey &key, const std::string &path) {
        _values[key] = path;
    }

    bool FileRegistry::isFileRegistry() const {
        return true;
    }

    std::filesystem::path &FileRegistry::operator[](const RegistryKey &key) {
        return _values[key];
    }

    std::filesystem::path &FileRegistry::operator[](RegistryKey &&key) {
        return _values[std::move(key)];
    }

    bool FileRegistry::contains(const RegistryKey &key) const {
        return _values.contains(key);
    }

    bool FileRegistry::contains(RegistryKey &&key) const {
        return _values.contains(std::move(key));
    }

    std::filesystem::path *FileRegistry::find_if(const std::function<bool(const RegistryKey &, const std::filesystem::path &)> &predicate) {
        for (auto &[key, value] : _values) {
            if (predicate(key, value))
                return &value;
        }
        return nullptr;
    }

    void FileRegistry::erase(const RegistryKey &key) {
        _values.erase(key);
    }

    void FileRegistry::erase(RegistryKey &&key) {
        _values.erase(std::move(key));
    }

    void FileRegistry::clear() {
        _values.clear();
    }

    size_t FileRegistry::size() const {
        return _values.size();
    }

    bool FileRegistry::empty() const {
        return _values.empty();
    }

    typename std::unordered_map<RegistryKey, std::filesystem::path>::iterator FileRegistry::begin() {
        return _values.begin();
    }

    typename std::unordered_map<RegistryKey, std::filesystem::path>::iterator FileRegistry::end() {
        return _values.end();
    }

    typename std::unordered_map<RegistryKey, std::filesystem::path>::const_iterator FileRegistry::begin() const {
        return _values.begin();
    }

    typename std::unordered_map<RegistryKey, std::filesystem::path>::const_iterator FileRegistry::end() const {
        return _values.end();
    }

    typename std::unordered_map<RegistryKey, std::filesystem::path>::const_iterator FileRegistry::cbegin() const {
        return _values.cbegin();
    }

    typename std::unordered_map<RegistryKey, std::filesystem::path>::const_iterator FileRegistry::cend() const {
        return _values.cend();
    }

}
