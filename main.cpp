
#include "ressource/Manager.hpp"

#include "graphics/Window.hpp"
#include "graphics/Sprite.hpp"
#include "graphics/shape/Rectangle.hpp"

#include "graphics/pipeline/ShapePipeline.hpp"
#include "graphics/pipeline/TexturePipeline.hpp"

int main(int ac, char **av) {

    showdown::graphics::PipelineBuilder::registerPipeline("shape", []() {
        return std::make_unique<showdown::graphics::ShapePipeline>();
    });

    showdown::graphics::PipelineBuilder::registerPipeline("texture", []() {
        return std::make_unique<showdown::graphics::TexturePipeline>();
    });

    showdown::graphics::Window window(800, 600, "WindowTest");

    showdown::Manager::instance().setProject("showdown", "../assets");
    showdown::Manager::instance().load<showdown::Registry<showdown::graphics::Texture>>("showdown", "textures");
    showdown::Manager::instance().load<showdown::FileRegistry>("showdown", "shader");
    showdown::Manager::instance().load<showdown::Registry<showdown::graphics::Pipeline>>("showdown", "pipeline");

    showdown::graphics::Sprite sprite(showdown::RegistryKey::of("showdown:poyo"));
    showdown::graphics::Rectangle rectangle(40, 40);
    rectangle.setPosition(100, 100);
    // rectangle.scale(2, 2);

    // window.usePipeline(showdown::RegistryKey::of("showdown:texture"));

    sprite.scale(4, 4);

    while (window.isOpen()) {
        window.clear();

        window.draw(sprite);
        window.draw(rectangle);

        window.display();
        window.pollEvents();
    }

}
