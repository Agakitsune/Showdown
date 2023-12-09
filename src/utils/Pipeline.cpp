
#include "utils/Pipeline.hpp"
#include "ressource/Manager.hpp"

namespace showdown::utils {

    std::unique_ptr<graphics::Pipeline> fromJson(const std::string &path) {
        std::fstream file(path);
        if (!file.is_open())
            throw std::runtime_error("Cannot open file " + path);
        nlohmann::json json;
        file >> json;

        auto pipeline = graphics::PipelineBuilder::buildPipeline(json["type"]);
        if (!pipeline)
            throw std::runtime_error("Cannot build pipeline from type " + json["type"].get<std::string>());

        if (json.contains("vertex") && json["vertex"].is_array()) {
            for (const auto &vertexKey : json["vertex"]) {
                pipeline->addShader(Manager::getRegistry<FileRegistry>("shader").get(RegistryKey::of(vertexKey)), gl::ShaderType::Vertex);
            }
        }

        if (json.contains("geometry") && json["geometry"].is_array()) {
            for (const auto &geometryKey : json["geometry"]) {
                pipeline->addShader(Manager::getRegistry<FileRegistry>("shader").get(RegistryKey::of(geometryKey)), gl::ShaderType::Geometry);
            }
        }

        if (json.contains("fragment") && json["fragment"].is_array()) {
            for (const auto &fragmentKey : json["fragment"]) {
                pipeline->addShader(Manager::getRegistry<FileRegistry>("shader").get(RegistryKey::of(fragmentKey)), gl::ShaderType::Fragment);
            }
        }

        pipeline->link();
        return pipeline;
    }

}
